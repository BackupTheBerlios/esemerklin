#ifndef SOCKET_H_
#define SOCKET_H_

/******************************************************************************
* Includes
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
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
//#define DKXX_USE
//test for shut down the server after 7 connections
//#define SERVER_SHUTDOWN_TEST

//#ifdef SC123
//#define IO_ADDR 0xC00
//#else
#define IO_ADDR 0x600
//#endif


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

/**
 * Erweiterung der Subserver auf 10
******************************************************************************/
static TaskDefBlock  srv1defblock =
{
  servertask,
  {'S','R','V','1'},            // a name: 4 chars
  &srv1_stack[TASK_STACKSIZE],  // top of stack
  TASK_STACKSIZE*sizeof(int),   // size of stack
  0,                            // attributes, not supported now
  SERVER_PRIO,                  // priority 20(high) ... 127(low)
  0,                            // time slice (if any), not supported now
  0,0,0,0                       // mailbox depth, not supported now
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

  			  for(int i=0;i<result; i++){
              	printf("%c",(char *)EchoServer[index].rcvbuf[i]);
               	}//for(i=0;i<outregs.x.ax;i++)
              printf("\r\n");
			
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



#endif /*SOCKET_H_*/


