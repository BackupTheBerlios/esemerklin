/******************************************************************************
*
* (c) 2004 by BECK IPC GmbH
*
*******************************************************************************
*
* Disclaimer: This program is an example and should be used as such.
*             If you wish to use this program or parts of it in your application,
*             you must validate the code yourself. BECK IPC GmbH can not be held
*             responsible for the correct functioning or coding of this example.
*
* Module:     tcpserm.c
* Function:   Multi TCPEchoSERVER Port XX , build with the API Interface
*             This program demontrates the usage of the TCPIP and RTOS
*             interface
*             The server is able to serve three clients simultanousley,
*             echoes the received data. An extra task writes periodically
*             the DK40 output pins.
*             The listening port could be given be program parameters
*             e.g. starting the program with:   tcpservm 7
*
*             How does the TCPserver works?
*             At the main loop of our application (this is a task too)
*             we do the main following steps:
*             1. Creating the DK40 task, task procedure is the function
*             dk40_task
*
*             2. Creating three subserver tasks, the task procedure is always the
*             function server_task.
*             This works, because each created task has its individual
*             taskdata, stored in a field of the defined structure EchoServer.
* 
*             typedef struct tag_echoserver{
*                                         int taskID;  //ID
*                                         int sd;      //socket descriptor
*                                         int finish;  //finish flag
*                                         TaskDefBlock   * taskdefblock;
*                                         unsigned char rcvbuf[MAX_BUFSIZE];
*             }ECHO_SERVER;
*
*             The initialization of this field is at the start of the program.
*             This tasks goes at their start immediatley to sleep
*             with the RTOS call RTX_SLEEP_REQUEST.
*
*             3. At the main task of our program, we open a socket and
*             do a listen call (max. backlog 3).
*             If a client request comes in, accept returns a
*             valid socketdescriptor for the new connection.
*             Now the listening server searches at the field EchoServer
*             for a free subserver task (sd is marked as -1).
*             This means: Is one of the three servertask ready to
*             wakeup and able to serve this connection?
*             If this is succesful, the listening server inserts the valid
*             socketdescriptor into the right Echoserver field and
*             calls RTX_Wakeup(taskID).
*             The selected server task wakes up, take the placed
*             socket descriptor from  his server entry, and
*             starts echoing the sended data by using recv and
*             send call of the TCPIP API.
*             The main server goes again into listen for waiting
*             on the next incoming client request.
*             If the remote client closes the connection, the subserver
*             closes the socket, marks his socket entry as free (-1),
*             and goes again to sleep until a new wakeup from the
*             listening server occurs.
*             The DK40_task has a higher priority as the server tasks.
*             So this task should run without any influence of the other
*             tasks. It don't cares this task, that the other tasks
*             are sleeping.
*             If the application has some fast things to do, this
*             should be done at such a task like the dk40_task.
*
* Notes:      Use this in combination with tcpclie.
*             This is one way to implement a server, which is able to
*             server more than one clients at the same time.
*             Another more complicated way is to create subservertasks
*             dynamically after a successful accept call at the
*             main server loop.
*
*******************************************************************************
*
* $Header: /home/xubuntu/berlios_backup/github/tmp-cvs/esemerklin/Repository/Socket_Server/SOCKET.CPP,v 1.1 2006/06/11 10:55:11 nadorwo Exp $
*
******************************************************************************/

/******************************************************************************
* Includes
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "clib.h"

/******************************************************************************
* Constants
******************************************************************************/
#define TM_PORT_ECHO                        7  /*well known echo port*/
#define TASK_STACKSIZE                    1024  /*WORDS => 2048 Bytes*/
#define SERVER_PRIO                        26

#define MAX_BUFSIZE                      1024
#define MAX_SERVER                         10
#define MAX_TIMEOUT                      4000L

//debug switches
#define TCPSERV_DEBUG
#define DKXX_USE
//test for shut down the server after 7 connections
//#define SERVER_SHUTDOWN_TEST

#ifdef SC123
#define IO_ADDR 0xC00
#else
#define IO_ADDR 0x600
#endif


/******************************************************************************
* Type definitions
******************************************************************************/
// each server task has its individual data, which are in a field of this type.
typedef struct tag_echoserver{
           int taskID;                        //ID
           int sd;                            //socket descriptor
           int finish;                        //finish flag
           TaskDefBlock   * taskdefblock;     //Task definition block
           unsigned char rcvbuf[MAX_BUFSIZE]; //Receive buffer
}ECHO_SERVER;



/******************************************************************************
* Prototypes
******************************************************************************/
void huge dk40_task(void);
void huge servertask(void);

//prototypes help functions
int Get_Server_Index(int taskID);
int Get_Free_Server_Task(void);



/******************************************************************************
* Global variables
******************************************************************************/
ECHO_SERVER EchoServer[MAX_SERVER];
int server_shutdown = 0;
long cnt_connection = 0L;

//DK40 task definition block
static unsigned int dk40_stack[TASK_STACKSIZE];
static int dk40ID;

static TaskDefBlock  dk40taskdefblock =
{
  dk40_task,
  "DK40",                         // a name: 4 chars
  &dk40_stack[TASK_STACKSIZE],  // top of stack
  TASK_STACKSIZE*sizeof(int),   // size of stack
  0,                             // attributes, not supported now
  21,                            // priority 20(high) ... 127(low)
  0,                             // time slice (if any), not supported now
  0,0,0,0                        // mailbox depth, not supported now
};

//srv1-3 task definition blocks, IDs, stacks
static unsigned int srv1_stack[TASK_STACKSIZE];
static unsigned int srv2_stack[TASK_STACKSIZE];
static unsigned int srv3_stack[TASK_STACKSIZE];

static unsigned int srv4_stack[TASK_STACKSIZE];
static unsigned int srv5_stack[TASK_STACKSIZE];
static unsigned int srv6_stack[TASK_STACKSIZE];
static unsigned int srv7_stack[TASK_STACKSIZE];
static unsigned int srv8_stack[TASK_STACKSIZE];
static unsigned int srv9_stack[TASK_STACKSIZE];
static unsigned int srv10_stack[TASK_STACKSIZE];

static TaskDefBlock  srv1defblock =
{
  servertask,
  {'S','R','V','1'},            // a name: 4 chars
  &srv1_stack[TASK_STACKSIZE],  // top of stack
  TASK_STACKSIZE*sizeof(int),   // size of stack
  0,                             // attributes, not supported now
  SERVER_PRIO,                   // priority 20(high) ... 127(low)
  0,                             // time slice (if any), not supported now
  0,0,0,0                        // mailbox depth, not supported now
};

static TaskDefBlock  srv2defblock =
{
  servertask,
  {'S','R','V','2'},                         // a name: 4 chars
  &srv2_stack[TASK_STACKSIZE],  // top of stack
  TASK_STACKSIZE*sizeof(int),   // size of stack
  0,                             // attributes, not supported now
  SERVER_PRIO,                   // priority 20(high) ... 127(low)
  0,                             // time slice (if any), not supported now
  0,0,0,0                        // mailbox depth, not supported now
};

static TaskDefBlock  srv3defblock =
{
  servertask,
  {'S','R','V','3'},            // a name: 4 chars
  &srv3_stack[TASK_STACKSIZE],  // top of stack
  TASK_STACKSIZE*sizeof(int),   // size of stack
  0,                             // attributes, not supported now
  SERVER_PRIO,                   // priority 20(high) ... 127(low)
  0,                             // time slice (if any), not supported now
  0,0,0,0                        // mailbox depth, not supported now
};

/******************************************************************************
 * Erweiterung der Subserver auf 10
******************************************************************************/
static TaskDefBlock  srv4defblock =
{
  servertask,
  {'S','R','V','4'},            // a name: 4 chars
  &srv4_stack[TASK_STACKSIZE],  // top of stack
  TASK_STACKSIZE*sizeof(int),   // size of stack
  0,                             // attributes, not supported now
  SERVER_PRIO,                   // priority 20(high) ... 127(low)
  0,                             // time slice (if any), not supported now
  0,0,0,0                        // mailbox depth, not supported now
};

static TaskDefBlock  srv5defblock =
{
  servertask,
  {'S','R','V','5'},            // a name: 4 chars
  &srv5_stack[TASK_STACKSIZE],  // top of stack
  TASK_STACKSIZE*sizeof(int),   // size of stack
  0,                             // attributes, not supported now
  SERVER_PRIO,                   // priority 20(high) ... 127(low)
  0,                             // time slice (if any), not supported now
  0,0,0,0                        // mailbox depth, not supported now
};

static TaskDefBlock  srv6defblock =
{
  servertask,
  {'S','R','V','6'},            // a name: 4 chars
  &srv6_stack[TASK_STACKSIZE],  // top of stack
  TASK_STACKSIZE*sizeof(int),   // size of stack
  0,                             // attributes, not supported now
  SERVER_PRIO,                   // priority 20(high) ... 127(low)
  0,                             // time slice (if any), not supported now
  0,0,0,0                        // mailbox depth, not supported now
};

static TaskDefBlock  srv7defblock =
{
  servertask,
  {'S','R','V','7'},            // a name: 4 chars
  &srv7_stack[TASK_STACKSIZE],  // top of stack
  TASK_STACKSIZE*sizeof(int),   // size of stack
  0,                             // attributes, not supported now
  SERVER_PRIO,                   // priority 20(high) ... 127(low)
  0,                             // time slice (if any), not supported now
  0,0,0,0                        // mailbox depth, not supported now
};

static TaskDefBlock  srv8defblock =
{
  servertask,
  {'S','R','V','8'},            // a name: 4 chars
  &srv8_stack[TASK_STACKSIZE],  // top of stack
  TASK_STACKSIZE*sizeof(int),   // size of stack
  0,                             // attributes, not supported now
  SERVER_PRIO,                   // priority 20(high) ... 127(low)
  0,                             // time slice (if any), not supported now
  0,0,0,0                        // mailbox depth, not supported now
};

static TaskDefBlock  srv9defblock =
{
  servertask,
  {'S','R','V','9'},            // a name: 4 chars
  &srv9_stack[TASK_STACKSIZE],  // top of stack
  TASK_STACKSIZE*sizeof(int),   // size of stack
  0,                             // attributes, not supported now
  SERVER_PRIO,                   // priority 20(high) ... 127(low)
  0,                             // time slice (if any), not supported now
  0,0,0,0                        // mailbox depth, not supported now
};

static TaskDefBlock  srv10defblock =
{
  servertask,
  {'S','R','V','10'},            // a name: 4 chars
  &srv10_stack[TASK_STACKSIZE],  // top of stack
  TASK_STACKSIZE*sizeof(int),   // size of stack
  0,                             // attributes, not supported now
  SERVER_PRIO,                   // priority 20(high) ... 127(low)
  0,                             // time slice (if any), not supported now
  0,0,0,0                        // mailbox depth, not supported now
};
/******************************************************************************
 * Ende der Erweiterung der Subserver
******************************************************************************/


/******************************************************************************
* dk40_task()
******************************************************************************/
void huge dk40_task(void)
{
   static unsigned char cnt=0;

   while(1)
   {
       if(cnt>=127)
       {
         cnt = 0;
       }
       else
       {
         cnt++;
       }
       #ifdef DKXX_USE
       outportb(IO_ADDR,cnt);
       #endif
       RTX_Sleep_Time(100);    /*sleep*/
   }//while(1)
}

/******************************************************************************
* servertask()
******************************************************************************/
void huge servertask(void)
{
   int index;
   int result;
   int error;
   int sd;
   char *bufptr;

   do
   {
        //goto sleep
        RTX_Sleep_Request();
        //the listening server has waked us up

        //detect the given EchoServer socketdescriptor
        index = Get_Server_Index(RTX_Get_TaskID());

        if(server_shutdown == 1)
        {
          break;
        }

        sd      = EchoServer[index].sd;
        bufptr  = (char *)EchoServer[index].rcvbuf;
        if(sd==-1) //should not happen
        {
           continue;
        }

        /****************************************************************/
        //Serve the client
        /****************************************************************/
        do
        {
            result = recv(sd,bufptr, MAX_BUFSIZE, MSG_TIMEOUT,MAX_TIMEOUT,&error);
            if(result==API_ERROR)
            {
              break;
            }

            //echo received data back
            if(result>0)
            {

              RTX_Sleep_Time(20);
              result = send(sd,bufptr,result,MSG_BLOCKING,&error);
              if(result == API_ERROR)
              {
                 break;
              }
            }//if(result>0)
        }
        while(server_shutdown==0);

        if(EchoServer[index].sd!=-1)
           closesocket(EchoServer[index].sd,&error);

        #ifdef TCPSERV_DEBUG
        printf("\r\nTCP Echosubserver: Closing connection %d socket %d\r\n",index,sd);
        #endif

        EchoServer[index].sd = -1;    //mark descriptor as free

   }while(server_shutdown==0);


   //Removing ourself from the system, this should not happen

   #ifdef TCPSERV_DEBUG
   printf("\r\nTCP Echosubserver: Removing task %d  ID:%d",index,RTX_Get_TaskID());
   #endif

   if(EchoServer[index].sd!=-1)
   {
       result = closesocket(EchoServer[index].sd,&error);
       if(result == API_ERROR)
       {
          printf("\r\nTCP Echosubserver: Socket close failed %d",error);
       }
   }
   EchoServer[index].finish = 1;    // set finish flag

   RTX_Delete_Task(RTX_Get_TaskID());
}

/******************************************************************************
* Get_Free_Server_Task()
*
* return the index of the first found sleeping task at Field EchoServer
******************************************************************************/
int Get_Free_Server_Task(void)
{
  int i;
  for(i=0;i<MAX_SERVER;i++)
  {
    if(EchoServer[i].sd==-1)
    {
      return i;
    }
  }
  return -1;
}
/******************************************************************************
* Get_Server_Index()
*
* subserver function: Detect the right entry at field echoserver of the current
* task
******************************************************************************/
int Get_Server_Index(int taskID)
{
  int i;
  for(i=0;i<MAX_SERVER;i++)
  {
     if(EchoServer[i].taskID==taskID)
     {
        return i;
     }
  }
  return -1;
}

/******************************************************************************
* main()
******************************************************************************/
int main(int argc, char *argv[])
{
   int lsd = -1;             //listening socketdescriptor
   int asd = -1;             //new socketdescriptor from accept
   int port  = TM_PORT_ECHO; //default port
   int error = 0;
   int result;
   int i;


   struct sockaddr_in addr;
   struct sockaddr_in claddr;
   char ClientIP[17];
   int  taskrdy = -1;

   
   //init chip selects  with the hardware API
   #ifdef DKXX_USE
   pfe_enable_pcs( 6 );
   #endif
        

   /***************************************************/
   //Get portnumber
   /***************************************************/
   if(argc==2)
   {
     result = atoi(argv[1]);
     if(result>0)
     {
       port = result;
     }
   }
   printf("\r\nTCP Echoserver, using port %d\r\n",port);

   /***************************************************/
   //init field EchoServer
   /***************************************************/

   for(i=0;i<MAX_SERVER;i++)
   {
     EchoServer[i].taskID = -1;
     EchoServer[i].sd     = -1;
     EchoServer[i].finish =  0;
   }

   EchoServer[0].taskdefblock = &srv1defblock;
   EchoServer[1].taskdefblock = &srv2defblock;
   EchoServer[2].taskdefblock = &srv3defblock;
   EchoServer[3].taskdefblock = &srv4defblock;
   EchoServer[4].taskdefblock = &srv5defblock;
   EchoServer[5].taskdefblock = &srv6defblock;
   EchoServer[6].taskdefblock = &srv7defblock;
   EchoServer[7].taskdefblock = &srv8defblock;
   EchoServer[8].taskdefblock = &srv9defblock;
   EchoServer[9].taskdefblock = &srv10defblock;

   /***************************************************/
   //create and start dk40_task
   /***************************************************/
   result = RTX_Create_Task(&dk40ID , &dk40taskdefblock);
   if(result!=0)
   {
     printf("\r\nTCP EchoServer: Creating DK40_Task failed %d, exit program\r\n",result);
     return 0;
   }

   /***************************************************/
   //create and start all subserver tasks
   /***************************************************/
   for(i=0;i<MAX_SERVER;i++)
   {
     result = RTX_Create_Task(&EchoServer[i].taskID , EchoServer[i].taskdefblock);
     if(result!=0)
     {
       printf("\r\nTCP Echoserver Creating task %d failed, err: %d -> exit program\r\n",i,result);
       goto TCP_SERVER_DONE;
     }//if(result!=0);
   }//for(i=0;i<MAX_SERVER;i++)

   RTX_Sleep_Time(100);

   /***************************************************/
   //open listening socket
   /***************************************************/
   result = opensocket(SOCK_STREAM, &error);
   if(result == API_ERROR)
   {
      printf("\r\nTCP Echoserver, Open socket failed %d",error);
      goto TCP_SERVER_DONE;
   }

   lsd = result;
   #ifdef TCPSERV_DEBUG
   printf("\r\nTCP Echoserver: Open listening socket %d",lsd);
   #endif

   /***************************************************/
   //Set the listening socket option reuse
   /***************************************************/
   result = setreuse(lsd,&error);
   #ifdef TCPSERV_DEBUG
   if(result == API_ERROR)
   {
     printf("\r\nTCP Echoserver: Set reuse failed %d",error);
   }
   #endif

   /***************************************************/
   //bind
   /***************************************************/
   addr.sin_family =  PF_INET;
   addr.sin_port   =  htons(port);
   addr.sin_addr.s_addr =  0L;

   result = bind(lsd,(struct sockaddr *)&addr,&error);
   if(result == API_ERROR)
   {
      printf("\r\nTCP Echoserver, Bind socket failed %d",error);
      goto TCP_SERVER_DONE;
   }

   /*********************************************************/
   //Main server loop, listen and establish connections
   /*********************************************************/
   while(1)
   {
      /***************************************************/
      //listen
      /***************************************************/
      result = listen(lsd, MAX_SERVER, &error);

      if(result == API_ERROR)
      {
        printf("\r\nTCP Echoserver, listen failed %d",error);
        goto TCP_SERVER_DONE;
      }

      /***************************************************/
      //accept , establish a connection
      /***************************************************/
      claddr.sin_family      =  PF_INET;
      claddr.sin_port        =  0;    //clear
      claddr.sin_addr.s_addr =  0L;   //clear

      result = accept(lsd,(struct sockaddr *)&claddr,&error);
      if(result == API_ERROR)
      {
        printf("\r\nTCP Echoserver, accept failed %d",error);
        goto TCP_SERVER_DONE;
      }
      InetToAscii(&claddr.sin_addr.s_addr,ClientIP);
      #ifdef TCPSERV_DEBUG
      printf("\r\nTCP Echoserver: Connected with %s , Port %u\r\n",ClientIP,claddr.sin_port);
      #endif
      asd = result;
      cnt_connection++;

      #ifdef SERVER_SHUTDOWN_TEST
      if(cnt_connection>6L)
      {

          result =  closesocket(asd,&error);
          if(result==API_ERROR)
          {
             printf("\r\nTCP Echoserver, socket close failed %d",error);
          }
          printf("\r\nTCP Echoserver: Shutdown test\r\n");
          goto TCP_SERVER_DONE;
      }
      #endif

      /***************************************************/
      //find a sleeping servertask
      /***************************************************/
      taskrdy =  Get_Free_Server_Task();

      if(taskrdy == -1)  //no sleeping task found
      {
         #ifdef TCPSERV_DEBUG
         printf("\r\nTCPserver: busy, refusing connection with %s , Port %u\r\n",ClientIP,claddr.sin_port);
         #endif
         closesocket(asd, &error);
      }
      else
      {
         //insert the socket descriptor
         EchoServer[taskrdy].sd = asd;
         //and wakeup the sleeping server task
         result = RTX_Wakeup(EchoServer[taskrdy].taskID);
         if(result != 0)
         {
           printf("\r\nTCPserver: wakeup error\r\n");
           closesocket(asd, &error);
         }
         else
         {
            //a task is waked up and serves from now on this connection
         }
      }//elseif(taskrdy == -1)  //no sleeping task found
      /*****************************************/
      // the main server goes again into listen
      /*****************************************/
   }//while(1)    //do forever


/************************************/
//Shutdown server, should not happen
/************************************/
TCP_SERVER_DONE:

   server_shutdown = 1;   //set shutdown flag
   printf("\r\nTCP Echoserver shutdown\r\n");

   //wakeup sleeping tasks
   for(i=0;i<MAX_SERVER;i++)
   {
      if((EchoServer[i].sd==-1) && (EchoServer[i].taskID!=-1))
      {
        RTX_Wakeup(EchoServer[i].taskID);
      }
   }
   //wait until the subserver tasks have finished
   result=0;
   while(result<10)
   {
     RTX_Sleep_Time(1000);
     if((EchoServer[0].finish) && (EchoServer[1].finish) && (EchoServer[2].finish))
     {
       break;
     }
     result++;
   }

   //removing DK40 Task
   RTX_Delete_Task(dk40ID);
   RTX_Sleep_Time(100);

   if(lsd!=-1)
   {
     #ifdef TCPSERV_DEBUG
     printf("\r\nTCP Echoserver: Closing listening socket %d",lsd);
     #endif

     result = closesocket(lsd,&error);

     if(result == API_ERROR)
     {
        printf("\r\nTCPEchoServer: Socket close failed %d",error);
     }
   }


   printf("\r\nTCP Echoserver finished\r\n");
   return 0;
}
/*************************************************************************/
//end tcpservm.c
/*************************************************************************/

