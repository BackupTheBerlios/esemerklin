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
* Module:     tcpserv.c
* Function:   This program demonstrates the usage of the TCP/IP-API of the IPC@Chip.
*             Its an echo-server that send all data received via TCP back to its
*             sender.
* Notes:      Use this in combination with tcpclie.
*
*******************************************************************************
*
* $Header: /home/xubuntu/berlios_backup/github/tmp-cvs/esemerklin/Repository/Socket_Server/socket.c,v 1.3 2006/06/06 22:57:45 nadorwo Exp $
*
******************************************************************************/


/******************************************************************************
* Includes
******************************************************************************/
#include <stdio.h>
#include "clib.h"

/******************************************************************************
* Constants
******************************************************************************/
#define TM_PORT_ECHO                      7    /*well known echo port*/
#define TM_TCPECHOBUF_SERVER_RECVSIZE    1024

/*
  these switches are only for debugging:
  comment these switches, if you have finished your application
  because the print routines take much time
*/
//#define TCP_ECHO_SERVER_DEBUG
#define  PRINT_DATA



/******************************************************************************
* Global variables
******************************************************************************/
static char recvbuf[TM_TCPECHOBUF_SERVER_RECVSIZE];
static char ClientIP[17];

/******************************************************************************
* main()
******************************************************************************/
int main(void)
{
   struct sockaddr_in   addr;
   struct sockaddr_in   claddr;


   int sd;
   int asd;
   int established = 0;

   #ifdef  PRINT_DATA
   int i;
   #endif
   
   int retval;
   int error;


   printf("\r\nTCPserver, listening on port %d\r\n",TM_PORT_ECHO);
   
   #ifdef TCP_ECHO_SERVER_DEBUG
   printf("\r\nOpen socket");
   #endif
   
   /**********************************************************************/
   //API call open socket START
   /**********************************************************************/   
   //Hiermit wird ein Socket geöffnet. D.h. nicht das eine Socketverbindung aufgebaut wird
   //es steht jetzt nur ein Socket zur Verfügung
   //1.Param.: SOCK_STREAM = 1 für TCP socket(Verbindungorientiert)
   //2.Param.: Fehlercode
   //Rückgabewert: -1==API_ERROR ansonsten Socket deskriptor
   retval = opensocket( SOCK_STREAM, &error );

   	if(retval == API_ERROR){
       printf("\r\nSocket open failed: %d",error);
       goto TCP_SERVER_DONE;
	   }
   	else{
       sd = retval;
   		}
   /**********************************************************************/
   //API call open socket ENDE
   /**********************************************************************/
   

   /**********************************************************************/
   //API-Call bind
   /**********************************************************************/
   //addr.sin_len    =  sizeof(struct sockaddr_in); // Ausgeklammert von Beck
   
   // Weist einem Socket eine lokale Protokoll Adresse zu   
   addr.sin_family =  PF_INET; // Protocoll Familie 
   //convert your sending port to correct byte order! SEHR WICHTIG
   retval = htons(TM_PORT_ECHO);
   addr.sin_port =  retval;
   
   // Das 'sin_addr' Attribut ist eine einfache IP Adresse in big endian byte order
   addr.sin_addr.s_addr =  0L;

   //call bind
   retval = bind( sd, (const struct sockaddr *)&addr, &error );
   if(retval == API_ERROR)
   {
       printf("\r\nTCPserver: Socket bind failed: %d",error);
       goto TCP_SERVER_DONE;
   }


   while(1)   //do forever
   {
     /**********************************************************************/
     //API-Call listen for connections
     /**********************************************************************/
     //Mit Listen versetzt man einen Socket in Lauschmodus
     printf("\r\nTCPserver: Listening for connection");

     
     // @Param1.: Der eigentliche Socket
     // @Param2.: Der Backlog, hier kann man die Länge der Warteschlange eingeben für die 
     //			  nicht vollständig verbundenen Clients. Z.b. Solche die eine Anfrage gesendet haben 
     //			  und auf einen Response warten(Thema Parallele Clients bedienen). Laut Beck API 
     //			  sind maximal 5 ausstehende Verbindung hier möglich.
     //           http://www.beck-ipc.com/files/ipc/documentation/api/scxxx/CLIB/TCPIP/tcp0E.htm
     // @Param3.: Fehlercode
     // Rückgabewert: 0 für erfolgreich ansonsten -1=API_ERROR
     retval = listen( sd, 1, &error );

     	if(retval == API_ERROR){
         printf("\r\nTCPserver: Socket listen failed: %d",error);
         goto TCP_SERVER_DONE;
	     }



     /**********************************************************************/
     //API-Call accept, establish a connection
     /**********************************************************************/
	 // Holt einen Client ab von einem lauschendem Socket
     claddr.sin_family      =  PF_INET;
     claddr.sin_port        =  0;
     claddr.sin_addr.s_addr =  0L;

	 // @Param1.: Socketdeskriptor der lauscht(MUß VORHER IN DEN LISTEN-MODUS VERSTEZT WERDEN)
	 // @Param2.: Ein Optionaler Parameter, ein Zeiger auf eine Struktur worüber man die Client IP und
	 //  		  Port ermitteln kann. Kann man auch mit 0 stehen lassen
	 // @Param3.: Fehlercode
	 // Rückgabewert: 0 für erfolgreich ansonsten -1=API_ERROR
     retval = accept( sd, (struct sockaddr *)&claddr, &error );

     	if(retval == API_ERROR){
         printf("\r\nTCPserver: Socket accept failed: %d",error);
         goto TCP_SERVER_DONE;
		}

     //save the new socketdescriptor
     asd = retval;
     established = 1;

     //get clients IP
     InetToAscii( (unsigned long *) &claddr.sin_addr.s_addr, (char *) ClientIP );

     printf("\r\nTCPserver: Connected with %s , Port %u\r\n",ClientIP, htons(claddr.sin_port));

     
     
     
     
     while(established)   //loop forever
     {

       /*******************************************************************/
       //Wait for incoming data from the client
       //To prevent a socketoverrun, we read all available data from the socket
       /*******************************************************************/
       do
       {

          //recv() wird eingesetzt um Daten von einem verbundenem Socket zu lesen
          // @Param1.: Der Socket Deskriptor des Clients
          // @Param2.: Zeigt auf einen Puffer der die aufzunehmenden Daten aufnehmen soll
          // @Param3.: Größe des Puffers(hier eine Konstante mit dem wert 1024)
          // @Param4.: Hier wird ein optionale Flag gesetzt. 
		  // 		   Auszug aus der API:
		  //          		Wait option:
	      //    					* MSG_BLOCKING - Sleep until data comes in.
		  //  						* MSG_TIMEOUT - The caller wakes up after timeout or if bufLen data is received.
    	  //						* MSG_DONTWAIT - Return immediately after collecting what ever data is ready.
    	  //     Sieh dazu API: http://www.beck-ipc.com/files/ipc/documentation/api/scxxx/CLIB/TCPIP/tcp10.htm
		  // @Param5.: Maximalla Zeit in Millisekunden wenn flag = MSG_TIMEOUT gesetzt isz
		  // @Param6.: Fehlercode, 
		  // Rückgabewert: -1=API_ERROR ansonsten Anzahl der gesendeten Bytes die in den Puffer geschrieben werden
          retval = recv( asd, (char *)recvbuf, TM_TCPECHOBUF_SERVER_RECVSIZE, MSG_TIMEOUT, 20000L, &error );

          	if(retval == API_ERROR){
             	#ifdef TCP_ECHO_SERVER_DEBUG
	            printf("\r\nTCPserver: Recverror %d",error);
    	        #endif
           	   established = 0;
           	   break;
          		}
          	else{
          		
               	if( retval > 0){//data received
                  #ifdef  PRINT_DATA
             		printf("\r\nTCPserver: Received data\r\n");
                 	for(i=0;i<retval; i++){
                   		printf("%02X ",(char)recvbuf[i]);
                 	}//for(i=0;i<outregs.x.ax;i++)
             		printf("\r\n");
             		#endif
             				             				
/*****************************Rückgabe zum Client START ******************************/

               		//send
               		retval = send( asd, (char *)recvbuf, retval, 0, &error );

               		if(retval == API_ERROR){
                   		#ifdef TCP_ECHO_SERVER_DEBUG
                   	    printf("\r\nTCPserver: Senderror %d",error);
                   		#endif
                 		established = 0;
                 		break;
               			}
			   	 }//if(retval > 0)    //data received
           	    else{
             		#ifdef TCP_ECHO_SERVER_DEBUG
             		printf("\r\nTCPserver: Nothing received %d\r\n",error);
                	#endif
           			}
          		}//elseif(retval == API_ERROR)

/*****************************Rückgabe zum Client ENDE ********************************/


          /*****************************************************************/
          //Check, if there is more data available at the socket ?
          /*****************************************************************/

          retval = GetWaitingBytes( asd, &error );

        	#ifdef TCP_ECHO_SERVER_DEBUG
          	if(retval==API_ENOERROR){
	           printf("\r\nTCPserver: Bytes waiting on the socket  %d",retval);
	         }
        	#endif
       }//while data available
       while((retval!=API_ERROR) && (retval>0));
     }//while(established)


     //close socket, given from accept
     printf("\r\nTCPserver: Closing connection");

     retval = closesocket( asd, &error );
	
	     #ifdef TCP_ECHO_SERVER_DEBUG
    	 if(retval==API_ERROR){
		      printf("\r\nTCPserver: Socket close failed: %d",error);
     		}
     	#endif

   }//while(1)

   /************************************/
   //Shutdown server, should not happen
   /************************************/

TCP_SERVER_DONE:

   printf("\r\nTCPserver: Closing listening socket");
   retval = closesocket( sd, &error );

   #ifdef TCP_ECHO_SERVER_DEBUG
   if(retval==API_ERROR)
   {
    printf("\r\nTCPserver: Socket close failed %d",error);
   }
   #endif


   return 0;

}



// End of file


