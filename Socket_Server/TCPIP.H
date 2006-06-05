/****************************************************************************
* (C) 1999-2006 by BECK IPC GmbH
*
*  BECK IPC GmbH
*  Germany
*
*  http://www.beck-ipc.com
*
* ---------------------------------------------------------------------------
* Module         : TCPIP.H
* Function       : prototypes, constants for TCPIP API functions
* ---------------------------------------------------------------------------

$Header: /home/xubuntu/berlios_backup/github/tmp-cvs/esemerklin/Repository/Socket_Server/TCPIP.H,v 1.1 2006/06/05 12:36:47 nadorwo Exp $

****************************************************************************/

#ifndef __TCPIP_H__
#define __TCPIP_H__

/*************************************************************************/
#include "TCPIPAPI.H"

/*************************************************************************/

#ifdef _MSC_VER /* If Microsoft C Compiler is used, define new FP_SEG and FP_OFF Macro */
        #ifdef FP_SEG
                #undef FP_SEG
        #endif
        #define FP_SEG(ptr)    ((unsigned int)(((unsigned long)ptr)>>16))

        #ifdef FP_OFF
                #undef FP_OFF
        #endif
        #define FP_OFF(ptr)    ((unsigned int)(((unsigned long)ptr)&0xFFFF))
#endif

/*************************************************************************/
//prototypes
/*************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif


#ifdef TCPIP_STACK_V2
#define tcp_connect   tcp_connect_ipstackV2   // Select an alternate C-library function
#endif

int  _cdecl tcp_connect(const char far *DestIPStr, unsigned int ClientPort,
                        unsigned int HostPort, int *error);

int  _cdecl accept(int sd, struct sockaddr far * addressPtr, int *error);

void _cdecl api_sleep(unsigned int howlong);

int  _cdecl bind (int sd, const struct sockaddr far * addressPtr, int *error);

int  _cdecl connect (int sd, const struct sockaddr far * addressPtr, int *error);

int  _cdecl closesocket (int sd, int *error);

int  _cdecl GetWaitingBytes(int sd, int *error);

unsigned short _cdecl htons (unsigned short hostshort );

int  _cdecl listen(int sd,int backlog, int *error) ;

int  _cdecl inet_addr(const char far * IPAddressStringPtr, unsigned long far * IPAddress);

int  _cdecl InetToAscii (const unsigned long far * IPAddress,
                         char far * IPAddressStringPtr);

#ifdef TCPIP_STACK_V2
#define recvfrom   recvfrom_ipstackV2  // Select an alternate C-library function
#endif

int  _cdecl recvfrom(int sd, char far * bufptr, int bufLen, int flags,
                     unsigned long timeout,struct sockaddr far * fromPtr, int *error);


int  _cdecl recv(int sd, char far * bufptr, int bufLen, int flags, unsigned long timeout,
                 int *error);

int  _cdecl ResetConnection (int sd, int *error) ;

#ifdef TCPIP_STACK_V2
#define sendto   sendto_ipstackV2    // Select an alternate C-library function
#endif  

int  _cdecl sendto (int sd, const char far * bufptr, int bufLen, int flags,
                    const struct sockaddr far * toPtr, int *error);

int  _cdecl send(int sd, const char far * bufptr, int bufLen, int flags, int *error);

int  _cdecl setlinger(int sd, int seconds, int *error);

int  _cdecl setreuse (int sd, int *error);

int  _cdecl Set_IP_Type_Of_Service (int sd, unsigned char tos, int *error) ;

int  _cdecl opensocket(unsigned char type, int *error);

int  _cdecl setsockopt (int sd, const SetSocketOption far *sockoptptr, int *error) ;

int  _cdecl getsockopt (int sd, const GetSocketOption far *sockoptptr, int *error);

int  _cdecl Set_Blocking_Mode(int sd, unsigned char blocking_mode, int *error);

int  _cdecl RegisterCallbackFunction(int sd, void far * funcptr, int eventflagmask, int *error) ;

int  _cdecl GetRegisterCallbackFunction(int sd, void far * funcptr, int eventflagmask ,int *error);

int  _cdecl get_socketerror(int sd);

unsigned char _cdecl Get_TCP_Socket_State(unsigned int localPort,
                                          unsigned long far * remoteIP,
                                          unsigned int * remotePort);

unsigned char _cdecl Get_TCP_Socket_State_IP_All(unsigned int localPort,
                                                 struct in6_addr far * remoteIP,
                                                 unsigned int * remotePort);

int _cdecl FindAllOpenSockets(SocketInfo far * SockInfoPtr, int max);
int _cdecl FindAllOpenSockets_IP_All(SocketInfoIPv4v6 far * SockInfoPtr, int max);

int _cdecl shutdown (int sd, unsigned char dir, int * error);

//ppp client prototypes
int  _cdecl PPP_Client_Installed(void);
int  _cdecl PPP_Client_Open (PPPClient_Init far * ptr, int *error) ;
int  _cdecl PPP_Client_Open_IPv6(PPPClient_Init_IPv6 far * ptr, int *error);
int  _cdecl PPP_Client_Close (int *error) ;
int  _cdecl PPP_Client_GetStatus (int *error) ;
int  _cdecl PPP_Client_SetOptions (const PPP_Option far * ptr) ;
int  _cdecl PPP_Client_Get_DNSIP (unsigned long far * IPaddress, int primary_sec, int *error);
void _cdecl PPP_Client_GetIP (const char far *IP);
int _cdecl  PPP_Server_Get_Cfg_IPv6(PPP_IPCfg_Data_IPv6 far *ptr, int *error);


//ppp server prototypes
int  _cdecl PPP_Server_Installed (void);
int  _cdecl PPP_Server_Suspend (int timeoutsecs, int *error) ;
int  _cdecl PPP_Server_Activate (int timeoutsecs, int *error) ;
int  _cdecl PPP_Server_GetStatus (void) ;
int  _cdecl PPP_Server_Get_Cfg (PPP_IPCfg_Data far *ptr, int *error);
int  _cdecl PPP_Server_SetOptions(const PPP_Option far * ptr);
void _cdecl PPP_Server_GetIP (char far *IP);

//Get pointer to internal TCIP SNMP mib structures
int  _cdecl Get_SNMP_Data(unsigned char which , void far *  * snmp_mib_ptr);
int  _cdecl Get_SNMP_DataEx(unsigned char which , void far * * snmp_mib_ptr, int  * max);

//Login counter
int  _cdecl Get_FTP_Login_Counters(unsigned long far * * FTP_Login_Count,
                                   unsigned long far * * FTP_Login_failCount);
int  _cdecl Get_Telnet_Login_Counters(unsigned long far * * Telnet_Login_Count,
                                      unsigned long far * * Telnet_Login_failCount);

//telnet state
int  _cdecl Get_Telnet_State (int *error);

//system
void _cdecl Get_Installed_Servers ( unsigned far *first, unsigned far *second );

// Bits returned by Get_Installed_Servers:
#define GIS_ETHERNET        0x1
#define GIS_PPP_SERVER      0x2
#define GIS_PPP_CLIENT      0x4
#define GIS_WEB_SERVER      0x8
#define GIS_TELNET_SERVER   0x10
#define GIS_FTP_SERVER      0x20
#define GIS_TFTP_SERVER     0x40
#define GIS_DHCP            0x80
#define GIS_SNMP_MIB        0x10000
#define GIS_CFG_SERVER      0x20000
#define GIS_PING_CLIENT     0x40000

int  _cdecl Reconfigure_ethernet(void);
int  _cdecl DHCP_use(unsigned char dhcp_use);
void _cdecl Get_DHCP_Status(unsigned int * dhcp_use, unsigned int *dhcp_stat);
void _cdecl Get_DHCP_Status_Ext(unsigned int * dhcp_use, unsigned int *dhcp_stat,
                                UserEthDhcp_Entry far * * dhcpptr);

void _cdecl Get_IPConfig(char far *IP, char far * Mask, char far *Gateway);
void _cdecl Set_IPConfig(const char far *IP,
                         const char far * Mask,
                         const char far *Gateway);
void _cdecl Get_TCPIP_Statistics ( Packet_Count far * * pkt_cnt_ptr );
int  _cdecl Set_FTPServer_Idle_Timeout( unsigned int timeout );
int  _cdecl Set_TelnetServer_Idle_Timeout( unsigned int timeout );
unsigned int _cdecl Get_FTPServer_Idle_Timeout(void);
unsigned int _cdecl Get_TelnetServer_Idle_Timeout(void);

//ping api
int  _cdecl Ping_Open(Ping far * pingptr, int * error);
int  _cdecl Ping_Close(int sd);
int  _cdecl Ping_Statistics(Ping far * pingptr);

//memory
void _cdecl Get_TCPIP_Memory_Status(unsigned long far * total, unsigned long far * used);

//route
typedef enum  { II_ETHERNET = 0, II_PPP_SERVER = 1, II_PPP_CLIENT = 2, II_USER_DEVICE = 3
    } IP_INTERFACE ;

int  _cdecl AddDefaultGateway   (IP_INTERFACE which_interface,
                                 const unsigned long far * Gateway,
                                 int * error);
int  _cdecl AddDefaultGatewayEx (IP_INTERFACE which_interface,
                                 const unsigned long far * Gateway,
                                 const void  far * userIfaceHandle,
                                 int * error);
int  _cdecl DelDefaultGateway (const unsigned long far * Gateway, int * error);
int  _cdecl GetDefaultGateway (unsigned long far * Gateway, int * error);

int  _cdecl AddStaticRoute (IP_INTERFACE which_interface,
                            const Route_Entry far * route,
                            int * error);
int  _cdecl DelStaticRoute (IP_INTERFACE which_interface,
                            const Route_Entry far * route,
                            int * error);

//ARP cache
int  _cdecl DelArpEntryByPhys(const unsigned char far *phy, int *error);
int  _cdecl AddArpEntry(const unsigned long far *ip, const unsigned char far *phy, int *error);
int  _cdecl GetARPRouteCacheEntries(ArpRouteCacheEntry far * arpuserptr);

//interface information
int  _cdecl Get_Iface_Entries(Iface_Entry far * iface_entry, int max);
int  _cdecl Get_Iface_Entries_Ext(Iface_Entry_Ext far * iface_entry, int max);
//interface MTU
int _cdecl SetIfaceMTU(IP_INTERFACE which_interface,const void  far * userIfaceHandle,
                   unsigned int mtu, int *error);


//IGMP
int  _cdecl Add_IGMP_Membership (const unsigned long far * MulticastIP,
                                 const unsigned char far * MacAddress,
                                 int * error);
int  _cdecl Drop_IGMP_Membership (const unsigned long far * MulticastIP, int * error);
int  _cdecl IPMulticast_to_MacAddr (const unsigned long far * MulticastIP,
                                    unsigned char far * MacAddress,
                                    int * error);


int  _cdecl RegisterIPCallbackHandler(void far *funcptr);
int  _cdecl RegisterIPCallbackHandler_Snd(void far *funcptr);
void _cdecl Register_ARP_User_CB(void far * funcPtr);

//Add TCPIP device driver interface
int  Dev_Get_IP( DevUserIfaceHandle DevHandlePtr, 
                 long * ipaddr,
                 long * netmask,
                 int * errorcode) ;
int  _cdecl Dev_Open_Interface(DevUserDriver far * DriverInfo,   int * errorcode);
int  _cdecl Dev_Close_Interface(DevUserIfaceHandle DevHandlePtr, int * errorcode);
int  _cdecl Dev_Recv_Interface(DevUserIfaceHandle  DevHandlePtr, int * errorcode);
int  _cdecl Dev_Recv_Wait(DevUserIfaceHandle       DevHandlePtr, int * errorcode);
int  _cdecl Dev_Notify_ISR(DevUserIfaceHandle      DevHandlePtr, unsigned int receivedPackets,
                           unsigned int sendedPackets);
int  _cdecl Dev_Get_Buffer(DevUserBufferHandle  BufHandlePtr, char far * far* buffer,
                           unsigned int length);
int  _cdecl Dev_Send_Complete(DevUserIfaceHandle DevHandlePtr);
int  _cdecl Dev_Wait_DHCP_Complete(DevUserDriver far * DriverInfo,
                                   unsigned int time_s, int * errorcode);
int  _cdecl Dev_PPP_Register_Chap(DevUserIfaceHandle DevHandlePtr,
                                   const void far * AuthCallbackFunction,
                                   int * error);
int  _cdecl Dev_PPP_Register_Pap(DevUserIfaceHandle DevHandlePtr,
                                  const void far * AuthCallbackFunction, int * error);
int _cdecl  Dev_PPP_Set_Option(DevUserIfaceHandle DevHandlePtr,
                               const PPP_Option far * ppp_option, int * error);
int _cdecl  Dev_PPP_Get_Peer_IP(DevUserIfaceHandle DevHandlePtr,
                                long far * Address,int * error);
int _cdecl  Dev_PPP_Get_Peer_DNSIP(DevUserIfaceHandle DevHandlePtr,
                                   long far * Address,int flag,int * error);
int Dev_Get_Handle_By_Name(const char * drivername,
                           DevUserIfaceHandle far * DevHandlePtr, int *error);
int _cdecl Dev_Config_Iface(DevIpv4IfaceCfg far * devcfg, int *error);
int _cdecl Dev_Config_Iface_IPv6(DevIpv6IfaceCfg far * devcfg, int *error);
int _cdecl Dev_UnConfig_Iface(DevUserIfaceHandle DevHandlePtr, int proto, 
                              unsigned char mHomeIndex, int *error);


int _cdecl  Get_IPv6_Iface_Entries(IfaceIPv6_Entry  far * iface_ipv6_entries, int max);
int _cdecl  inet_ntop(int af, const void far * source_ptr, char far * dest_ptr, int max);
int _cdecl  inet_pton(int af, const char far * source_ptr, void far * dest_ptr);
int _cdecl  opensocket_ext(int family, unsigned char type,  int *error);

// PKI / SSL functions
int _cdecl PKI_CertificateAdd(PKI_CERT_ADD_EntryPtr addEntryPtr, int *error);
int _cdecl PKI_CertificateDel(void far * idPtr, int *error);
int _cdecl PKI_OwnKeyPairAdd(PKI_OWNKEYPAIR_ADD_EntryPtr keyEntryPtr, int *error);
int _cdecl SSL_SessionClose(int sessionID, int *error);
int _cdecl SSL_SessionNew(SSL_SESSION_NEW_EntryPtr newSessionPtr, int *error);
int _cdecl SSL_SessionProp(int sessionID, int far *proposals, int count, int *error);
int _cdecl SSL_SessionOpt(int sessionID, int option, int value, int *error);
int _cdecl SSL_AddClientCA(int sessionID, void far *caIdPtr, int *error);
int _cdecl SSL_ClientStart(int sd, char far *srvCommonName, int *error);
int _cdecl SSL_SendFlush(int sd, int *error);
int _cdecl SSL_ConnClose(int sd, int *error);

// CRYPT functions
int _cdecl Crypt_MD5_Init   (Crypt_MD5_ContextPtr md5context);
int _cdecl Crypt_MD5_Update (Crypt_MD5_ContextPtr md5context,
                             unsigned char far *inBuffer, unsigned int length);
int _cdecl Crypt_MD5_Final  (Crypt_MD5_ContextPtr md5context);

#ifdef __cplusplus
}
#endif


/*************************************************************************/
#endif /* __TCPIP_H__*/
/*************************************************************************/
//end tcpip.h
/*************************************************************************/
