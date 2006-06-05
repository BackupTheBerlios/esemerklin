/****************************************************************************
* (C) 1999-2005 by BECK IPC GmbH
*
*  BECK IPC GmbH
*  Germany
*  
*  http://www.beck-ipc.com
*
* ---------------------------------------------------------------------------
* Module        : FOSSIL.H
* Function      : prototypes, constants for fossil functions
* ---------------------------------------------------------------------------

$Header: /home/xubuntu/berlios_backup/github/tmp-cvs/esemerklin/Repository/Socket_Server/FOSSIL.H,v 1.1 2006/06/05 12:36:46 nadorwo Exp $

/****************************************************************************/

#ifndef __FOSSIL_H__
#define __FOSSIL_H__

/****************************************************************************/

// constants
#define FOSSIL_EXT  0
#define FOSSIL_COM  1
#define FOSSIL_SER2 2           // SC1x3 only!
#define FOSSIL_SER3 3           // SC1x3 only!

// status
#define FOSSIL_OUTPUT_BUFFER_EMPTY 0x40
#define FOSSIL_OUTPUT_NOT_FULL     0x20
#define FOSSIL_LINE_BREAK          0x10
#define FOSSIL_FRAMING_ERROR       0x08
#define FOSSIL_PARITY_ERROR        0x04
#define FOSSIL_OVERRUN_ERROR       0x02
#define FOSSIL_DATA_AVAILABLE      0x01

// RS485 mode
typedef enum {
    FOSSIL_RS485_LOWACTIVE,
    FOSSIL_RS485_HIGHACTIVE,
    FOSSIL_RS485_DISABLE
} RS485_MODE ;

// type definitions
typedef struct FossilDriverInfo
{
  unsigned       size;          // structure size
  unsigned char  version;       // (not used)
  unsigned char  level;         // (not used)
  char      far *id;            // (not used)
  unsigned       inputBuffSize; // input buffer size
  unsigned       inputAvailable; // bytes available on Input buffer
  unsigned       outputBuffSize;// output buffer size
  unsigned       ouputAvailable; // bytes available on Output buffer
  unsigned char  screenWidth;   // (not used)
  unsigned char  screenHeight;  // (not used)
  unsigned char  baudrateMask;  // (not used)
} FossilDriverInfo_t;


    //    parity
typedef enum {
    FOSSIL_PARITY_NO     = 0,
    FOSSIL_PARITY_ODD    = 1,
    FOSSIL_PARITY_EVEN   = 2,
    FOSSIL_PARITY_MARK   = 3,
    FOSSIL_PARITY_SPACE  = 4
} FOSSIL_PARITY ;

    // Flow Control
typedef enum {
    FOSSIL_FLOWCTRL_OFF           = 0x0,
        // XON/XOFF on transmit (watch for XOFF while sending)
    FOSSIL_FLOWCTRL_XONXOFF_SEND  = 0x1,
        // CTS/RTS (CTS on transmit/RTS on receive)
    FOSSIL_FLOWCTRL_RTSCTS        = 0x2,
        // XON/XOFF on receive (send XOFF when buffer near full)
    FOSSIL_FLOWCTRL_XONXOFF_RECV  = 0x8,
        // XON/XOFF used on both Tx and Rx
    FOSSIL_FLOWCTRL_XONXOFF_SEND_RECV = 0x9

} FOS_FLOW_CTRL ;


typedef enum {
    FOS_LONG_BREAK = 1,
    FOS_SHORT_BREAK = 2,
    FOS_EXTRALONG_BREAK = 3
} FOS_BREAK_SIZE ;


typedef enum {
    FOS_DISABLE = 0,
    FOS_ENABLE = 1
} FOS_TXRX_MODE ;

typedef enum {
    RTS_LOW = 0,
    RTS_HIGH = 1,
    RTS_NORMAL = 2
} FOS_RTS_MODE ;

// Type and structure definition for Fossil User CallBack function

// Possible events which has occured
#define FE_DATA_AVAIL     0x01 // New Data Received (in the data field)
#define FE_READY_FOR_SEND 0x02 // (not supported at time)
#define FE_ERROR_DETECTED 0x10 // (not supported at time)

// Possible events which the caller of the callback (the fossil interface) has to do
#define FE_IGNORE_DATA  0x01 // do not copy the reveived data in the Receive Queque
#define FE_DATA_TO_SEND 0x02 // (not supported at time)

typedef struct
{
    int size;             // size of the struct (sizeof(fossil_event_t)
    int port;             // serial port (0=EXT, 1=COM)
    int event;            // event (see above)
    void far *data;       // data pointer
    unsigned data_length; // data length
} fossil_event_t;

typedef fossil_event_t far * huge (far *FOSSIL_USER_CALLBACK)( fossil_event_t far *e );

/*************************************************************************/
//prototypes
/*************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

        // Configuration Functions
int  _cdecl fossil_setbaud (int port, 
                            long baudrate, 
                            FOSSIL_PARITY parity, 
                            int wordlen, 
                            int stopbits);

void _cdecl fossil_set_extctrl(int port, int divider, FOSSIL_PARITY parity, 
                               int wordlen, int stopbits);

void _cdecl fossil_set_flowcontrol(int port, FOS_FLOW_CTRL flowctrl) ;
void _cdecl fossil_force_rts (int port, unsigned char mode);
unsigned char _cdecl fossil_read_cts (int port);
void _cdecl fossil_deinit(int port);
void _cdecl fossil_user_callback(int port, FOSSIL_USER_CALLBACK pfFossUCB);


        // Status Functions
int _cdecl fossil_status_request(int port);
int _cdecl fossil_get_driver_info(int port, FossilDriverInfo_t far *drv_info);
int _cdecl fossil_init(int port);  
int _cdecl fossil_get_bytes_in_uart(int port);


        // RS-485 Controls
void _cdecl fossil_set_rs485(int port, RS485_MODE mode);
void _cdecl fossil_set_rs485_txenable(int port, int pin);


        // Transmitter Functions
int  _cdecl fossil_putbyte_wait(int port, int ch);
int  _cdecl fossil_putbyte(int port, int ch);
void _cdecl fossil_flush_output(int port);
void _cdecl fossil_purge_output(int port);
unsigned int _cdecl fossil_writeblock (int port, 
                                       const unsigned char far *buffer, 
                                       unsigned int count);
void _cdecl fossil_send_break(int port, FOS_BREAK_SIZE break_size );
void _cdecl fossil_enable_transmitter (int port, unsigned char mode);


        // Receiver Functions
int  _cdecl fossil_getbyte_wait(int port);
int  _cdecl fossil_getbyte (int port) ;
int  _cdecl fossil_peek_input(int port);    // ret char in buffer, -1 if none available
unsigned int _cdecl fossil_readblock (int port, 
                                      unsigned char far *buffer, 
                                      unsigned int count);
void _cdecl fossil_purge_input(int port);
void _cdecl fossil_enable_receiver (int port, unsigned char mode);


#ifdef __cplusplus
}
#endif

/*************************************************************************/
#endif /* __FOSSIL_H__ */
/****************************************************************************/
// end of file
/****************************************************************************/
