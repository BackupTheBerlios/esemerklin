/******************************************************************************
*
* (c) 2005 by BECK IPC GmbH
*
* BECK IPC GmbH
* Grüninger Weg 24
* 35415 Pohlheim-Garbenteich/Germany
*
* Phone: +49 6404 695-0
* Fax:   +49 6404 695-500
* WWW:   http://www.beck-ipc.com
*
*******************************************************************************
*
* Module:     usb_api.h
* Function:   See usb_api.c
*
*******************************************************************************
*
* $Header: /home/xubuntu/berlios_backup/github/tmp-cvs/esemerklin/Repository/Socket_Server/usb_api.h,v 1.1 2006/06/05 12:36:47 nadorwo Exp $
*
******************************************************************************/



#ifndef USB_API_H
#define USB_API_H



/******************************************************************************
* Type UsbBool
******************************************************************************/
#ifndef UsbBool
  #define UsbBool  unsigned char
#endif
#ifndef FALSE
  #define FALSE  0
#endif
#ifndef TRUE
  #define TRUE   ( !FALSE )
#endif



/******************************************************************************
* Error Codes
******************************************************************************/
#define USB_ERROR_NO                  0  // No error occured
#define USB_ERROR_ILLEGAL_ARGUMENT   -1  // An argument with an invalid value
                                         // was passed
#define USB_ERROR_OUT_OF_MEMORY      -2  // The USBD could not allocate enough
                                         // memory for the requested operation.
#define USB_ERROR_RESOURCE_LACK      -3  // Lack of some kind of internally managed
                                         // resource such as tasks, semaphores,
                                         // buffers, etc.
#define USB_ERROR_QUEUE_MAXIMUM      -4  // A request could not be enqueued due
                                         // to the resp. queue having reached
                                         // its maximum.
#define USB_ERROR_FEATURE_DISABLED   -5  // The requested feature is not enabled
#define USB_ERROR_OUT_OF_INTERFACES  -6  // There were not enough free interfaces/
                                         // alternative settings left
#define USB_ERROR_OUT_OF_ENDPOINTS   -7  // There were not enough free endpoints
                                         // left
#define USB_ERROR_RESET_SETUP        -8  // A reset occured or a setup token has
                                         // been received on the resp. endpoint
                                         // but the event has not yet been notified.
                                         // The requested action cannot be performed
                                         // in this situation.
#define USB_ERROR_UNKNOWN_SERVICE    -9  // The software interrupt was triggered
                                         // with an unknown service number. 



/******************************************************************************
* Service numbers
*
* These are the values that have to be written to the ah register when calling
* the software interrupt. They correspond to the C-functions below.
******************************************************************************/
#define USB_SERVICE_DYNAMIC_LINK                 0x00
#define USB_SERVICE_SEND                         0x01
#define USB_SERVICE_FREE_RECEIVE_BUFFER          0x02
#define USB_SERVICE_WAKEUP                       0x03

#define USB_SERVICE_DEVICE_INIT                  0x10
#define USB_SERVICE_DEVICE_DEINIT                0x11
#define USB_SERVICE_DEVICE_REGISTER_INTERFACE    0x12
#define USB_SERVICE_DEVICE_REGISTER_ALT_SETTING  0x13
#define USB_SERVICE_DEVICE_GET_EPS               0x14
#define USB_SERVICE_DEVICE_CONFIG_EP             0x15
#define USB_SERVICE_DEVICE_ADD_SPECIFIC_DESC     0x16
#define USB_SERVICE_DEVICE_START                 0x17
#define USB_SERVICE_DEVICE_STOP                  0x18
#define USB_SERVICE_DEVICE_STALL_EP              0x19

#define USB_SERVICE_HOST_INIT                    0x20
#define USB_SERVICE_HOST_DEINIT                  0x21
#define USB_SERVICE_HOST_ISSUE_TOKEN             0x22
#define USB_SERVICE_HOST_GET_INFO_DEVICE         0x23
#define USB_SERVICE_HOST_GET_N_INTERFACE         0x24
#define USB_SERVICE_HOST_GET_INFO_INTERFACE      0x25
#define USB_SERVICE_HOST_GET_N_ALT_SETTING       0x26
#define USB_SERVICE_HOST_GET_INFO_ALT_SETTING    0x27
#define USB_SERVICE_HOST_GET_N_EP                0x28
#define USB_SERVICE_HOST_GET_INFO_EP             0x29



/******************************************************************************
* Definition of types
******************************************************************************/
// This enum indicates the event that occured regarding callbacks
typedef enum
{
  USB_EVENT_RECEIVED,  // An RX request has been completed
                       // epNumber indicates the endpoint on which the transaction
                       // completed
                       // request holds the request that completed
  USB_EVENT_SENT,      // A TX request has been completed
                       // epNumber indicates the endpoint on which the transaction
                       // completed
                       // request holds the request that completed
  USB_EVENT_RESET,     // The device has been reset
                       // epNumber is 0
                       // request is NULL
  USB_EVENT_SETUP,     // A setup token has been received
                       // epNumber indicates on which endpoint a Setup token has
                       // been received
                       // request is NULL
  USB_EVENT_SUSPEND,   // The device has been suspended, i.e. there has been no
                       // activity on the bus for 3 ms.
                       // epNumber is 0
                       // reuqest is NULL
  USB_EVENT_RESUME,    // The device has been woken up from suspension.
                       // epNumber is 0
                       // reuqest is NULL
                       // Errors
  // If nothing else is stated epNumber is 0 and request is NULL.
  USB_EVENT_ERROR_BIT_STUFF,   // Indicates that a bit stuff error was detected
                               // in the data stream on the bus. The resp.
                               // packet was rejected. The host should repeat it.
  USB_EVENT_ERROR_DMA,         // Fatal: There was a problem regarding DMA data
                               // transport between memory and the USB controller
                               // hardware. Data may be lost.
  USB_EVENT_ERROR_TURNAROUND,  // A bus turnaround timeout occured. This means
                               // either data from the host did not arrive in time
                               // or sent data was not acknowledged in time.
  USB_EVENT_ERROR_DATA_FIELD,  // Indicates that a data field did not consist of
                               // an integral number of bytes. The resp. packet
                               // was rejected. The host should repeat it.
  USB_EVENT_ERROR_CRC16,
  USB_EVENT_ERROR_CRC5,        // Indicates a checksum error. The resp. packet
                               // was rejected. The host should repeat it.
  USB_EVENT_ERROR_PID,         // A PID check field didn't macth. This is similar
                               // to a checksum error. The resp. packet was
                               // rejected. The host should repeat it.
} UsbEventStatus;



// Callback functions will be used to notify events like resets or completed
// transactions.
typedef void huge ( far *UsbCallback )( unsigned epNumber,      // Endpoint that the
                                                                // event occured on.
                                                                // 0 if not applicable
                                        UsbEventStatus status,  // Indicates the type of
                                                                // event that happened.
                                        void far *buffer,       // If a transmission
                                        unsigned length );      // completed these
                                                                // variables hold
                                                                // the resp. data and
                                                                // its length.



// This structure is used with the software interrupt service USB_SERVICE_INIT.
// Since the service expects that much parameters and there are not enough
// registers, a variable of this structure is used to hand the parameters to the
// software interrupt.
// The fields correspond to the parameters of usbInit().
typedef struct UsbInit_
{
  UsbCallback callback;
  unsigned char classCode;
  unsigned char subClassCode;
  unsigned char protocolCode;
  unsigned vendorId;
  unsigned productId;
  unsigned versionBcd;
  char far *manufacturerString;
  char far *productString;
  char far *serialNumberString;
  char far *configString;
  UsbBool selfPowered;
  unsigned char maxPowerConsumption;
  unsigned char pioNumber;
} UsbInit;

                                                       

/******************************************************************************
* Prototypes of functions for both Device- and Host-Mode
******************************************************************************/
int far usbSend(
                 unsigned char address,
                 unsigned char epNumber,
                 void far *buffer,
                 unsigned length,
                 UsbBool less );
void far usbFreeReceiveBuffer(
                               void far *buffer );
int far usbWakeup(
                   void );



/******************************************************************************
* Prototypes of functions for Device-Mode only
******************************************************************************/
int far usbDeviceInit(
                       UsbCallback callback,
                       unsigned char classCode,
                       unsigned char subClassCode,
                       unsigned char protocolCode,
                       unsigned vendorId,
                       unsigned productId,
                       unsigned versionBcd,
                       char far *manufacturerString,
                       char far *productString,
                       char far *serialNumberString,
                       char far *configString,
                       UsbBool selfPowered,
                       unsigned char maxPowerConsumption,
                       unsigned char pioNumber );
void far usbDeviceDeinit(
                          void );
int far usbDeviceRegisterInterface(
                                    unsigned char nEp,
                                    unsigned char classCode,
                                    unsigned char subClassCode,
                                    unsigned char protocolCode,
                                    char far *interfaceString );
int far usbDeviceRegisterAltSetting(
                                     unsigned char interfaceId );
int far usbDeviceGetEps(
                         unsigned char interfaceId,
                         unsigned far *epBitmap );
int far usbDeviceConfigEp(
                           unsigned char interfaceId,
                           unsigned char altSettingId,
                           unsigned char epNumber,
                           unsigned char transferType,
                           UsbBool in,
                           unsigned maxPacketSize,
                           unsigned char interval );
int far usbDeviceAddSpecificDesc(
                                  unsigned char descriptorType,
                                  unsigned char idNumber,
                                  char far *descriptor,
                                  unsigned char descriptorLength );
void far usbDeviceStart(
                         void );
void far usbDeviceStop(
                        void );
int far usbDeviceStallEp(
                          unsigned char epNumber );



/******************************************************************************
* Prototypes of functions for Host-Mode only
******************************************************************************/
// ###



#endif
// End of file

