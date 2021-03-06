/*******************************************************************************
*
* $Header: /home/xubuntu/berlios_backup/github/tmp-cvs/esemerklin/Repository/Socket_Server/SOCKET.CPP,v 1.4 2006/06/12 09:53:56 nadorwo Exp $
*
******************************************************************************/

#include "socket.h"

/**
 * F�hrt den Spcket Server bei einem Fehler runter. Dabei werden zuerst alle Subserver heruntergefahren die jeweiligen Socketverbindungen getrennt. 
 * @param lsd Der jeweilige eindeutige Socketdeskriptor
 * @param error Fehlercode
 * @return Gibt eine 0 f�r erfolgreiches runterfahren aller Sockets zur�ck
 */ 
int shutDownServer(int lsd, int error){
	server_shutdown = 1;   //set shutdown flag
   printf("\r\nTCP Echoserver shutdown\r\n");


   for(int i=0;i<MAX_SERVER;i++)// wakeup sleeping tasks 
   {
      if((EchoServer[i].sd==-1) && (EchoServer[i].taskID!=-1))
      {
        RTX_Wakeup(EchoServer[i].taskID);
      }
   }
   //wait until the subserver tasks have finished
   int result=0;
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

/**
 * Initialisiert die Felder der EchoServer
 */
void initServer(){
	for(int i=0;i<MAX_SERVER;i++)
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
}

/**
 * Erstellt und startet den dk40_task
 * @return Ein Integer Wert, 0 bedeutet dabei das der TASK l�uft. Ungleich 0 f�r Fehler 
 */
int startDK40Task(){
   	int result = RTX_Create_Task(&dk40ID , &dk40taskdefblock);
   	if(result!=0){
     	cout << "\r\nTCP EchoServer: Creating DK40_Task failed %d, exit program\r\n";
     	printf("\r\nTCP EchoServer: Creating DK40_Task failed %d, exit program\r\n",result);
     	return 0;
   		}//if(result!=0)
   	cout << "\r\nTCP EchoServer: Initialisierung des DK40_Task erfolgreich, \r\n";
   	return result;
	}//startDK40Task()


/**
 * Startet die erfoderlichen Sub Socketserver um weiter Clients zu verbinden
 * @param Horchende Socketdeskripto, erforderlich f�r shitDownServer()
 * @param Fehlercode 
 */
void initSubServerTask(int lsd, int error){
	 for(int i=0;i<MAX_SERVER;i++){
     	int result = RTX_Create_Task(&EchoServer[i].taskID , EchoServer[i].taskdefblock);
     	if(result!=0){
       		printf("\r\nTCP Echoserver Creating task %d failed, err: %d -> exit program\r\n",i,result);
       		shutDownServer(lsd,error);
     		}//if(result!=0)
   	 	}//for(int i=0;i<MAX_SERVER;i++)
	}//initSubServerTask()
	
	
/**
 * Erstellet einen Socket der horcht
 * @param Der jeweilige Socketdiskriptor 
 * @param Fehlercode
 * @return Der R�ckgabewert ist ein Integer und gibt den Socket Deskriptor an
 */ 
int openListenSocket(int lsd,int error){
	 int result = opensocket(SOCK_STREAM, &error);
   	 if(result == API_ERROR){
    	printf("\r\nTCP Echoserver, Open socket failed %d",error);
      	shutDownServer(lsd,error);
   		}//if(result == API_ERROR)
   	 return result;
	}//openListenSocket()
	





/**
 * main()
 */
int main()
{
   int lsd = -1;             //listening socketdescriptor
   int asd = -1;             //new socketdescriptor from accept
   int port  = TM_PORT_ECHO; //default port
   int error = 0;
   int result;
   //int i;

   struct sockaddr_in addr;
   struct sockaddr_in claddr;
   char ClientIP[17];
   int  taskrdy = -1;
   
   initServer();
   startDK40Task();
   initSubServerTask(lsd,error);
   RTX_Sleep_Time(100);
   lsd = openListenSocket(lsd,error);

   
   #ifdef TCPSERV_DEBUG
   printf("\r\nTCP Echoserver: �ffnen einen Socket %d",lsd);
   #endif

  /**
   * Setzt den horchenden Socket auf Wiederverwendbar ein
   * @param lsd Den Socketdeskriptor des horchenden Sockets
   * @param error Fehlercode
   * @return (0) f�r erfolgreich, ungleich (0) f�r fehler
   */
   result = setreuse(lsd,&error);
   	
   	#ifdef TCPSERV_DEBUG
   	if(result == API_ERROR){
     	printf("\r\nTCP Echoserver: Set reuse failed %d",error);
   	}
   	#endif
   	
	addr.sin_family =  PF_INET;
	addr.sin_port   =  htons(port); //Konvertierung von Little Endian zu Big Endian
	addr.sin_addr.s_addr =  0L;

   	result = bind(lsd,(struct sockaddr *)&addr,&error);
   	if(result == API_ERROR){
   		printf("\r\nTCP Echoserver, Bind socket failed %d",error);
   		shutDownServer(lsd,error);
	}//(result == API_ERROR)
   

   /*
    * Endlosschleife, horcht und baut Verbindungen auf
    */
   while(1)
   {
      /**
       * listen
       */
      result = listen(lsd, MAX_SERVER, &error);
      if(result == API_ERROR){
        printf("\r\nTCP Echoserver, listen failed %d",error);
        shutDownServer(lsd,error);
      	}//if(result == API_ERROR)

      /**
       * accept , establish a connection
       */
      claddr.sin_family      =  PF_INET;
      claddr.sin_port        =  0;    //clear
      claddr.sin_addr.s_addr =  0L;   //clear

      result = accept(lsd,(struct sockaddr *)&claddr,&error);
      if(result == API_ERROR){
		printf("\r\nTCP Echoserver, accept failed %d",error);
        shutDownServer(lsd,error);
      	}//if(result == API_ERROR)
      
      InetToAscii(&claddr.sin_addr.s_addr,ClientIP);
      
      	#ifdef TCPSERV_DEBUG
      	printf("\r\nTCP Echoserver: Connected with %s , Port %u\r\n",ClientIP,claddr.sin_port);
      	#endif
      
      
      asd = result;
      cnt_connection++;

	       #ifdef SERVER_SHUTDOWN_TEST
    		if(cnt_connection>6L){

	          result =  closesocket(asd,&error);
    	      if(result==API_ERROR){
             	printf("\r\nTCP Echoserver, socket close failed %d",error);
          		}
          	printf("\r\nTCP Echoserver: Shutdown test\r\n");
          	shutDownServer(lsd,error);
      		}//if(cnt_connection>6L)
		   #endif

      /**
       * Suche einer ruhenden Server Task 
       */
      taskrdy =  Get_Free_Server_Task();
      if(taskrdy == -1){  //no sleeping task found
         
         #ifdef TCPSERV_DEBUG
         	printf("\r\nTCPserver: busy, refusing connection with %s , Port %u\r\n",ClientIP,claddr.sin_port);
         #endif
         closesocket(asd, &error);
      }//if(taskrdy == -1)
      else{
      		//insert the socket descriptor
        	EchoServer[taskrdy].sd = asd;
         
	        //and wakeup the sleeping server task
    	    result = RTX_Wakeup(EchoServer[taskrdy].taskID);
         
        	if(result != 0){
           		printf("\r\nTCPserver: wakeup error\r\n");
	           closesocket(asd, &error);
			}//if(result != 0)
        	else{
	        //a task is waked up and serves from now on this connection
    	    }
      }//elseif(taskrdy == -1)  //no sleeping task found
   }//while(1)    //do forever
}

/*************************************************************************/
//end tcpservm.c
/*************************************************************************/
