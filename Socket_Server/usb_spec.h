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
* Module:     usb_spec.h
* Function:   Constants and data structures from the USB specification 1.1.
*
*******************************************************************************
*
* $Header: /home/xubuntu/berlios_backup/github/tmp-cvs/esemerklin/Repository/Socket_Server/usb_spec.h,v 1.1 2006/06/05 12:36:46 nadorwo Exp $
*
******************************************************************************/



#ifndef USB_SPEC_H
#define USB_SPEC_H



/******************************************************************************
* PID Tokens
* Refer to chapter 8.3.1 of the specification.
******************************************************************************/
#define USB_SPEC_PID_OUT    0x01
#define USB_SPEC_PID_IN     0x09
#define USB_SPEC_PID_SOF    0x05
#define USB_SPEC_PID_SETUP  0x0D
#define USB_SPEC_PID_DATA0  0x03
#define USB_SPEC_PID_DATA1  0x0B
#define USB_SPEC_PID_ACK    0x02
#define USB_SPEC_PID_NAK    0x0A
#define USB_SPEC_PID_STALL  0x0E
#define USB_SPEC_PID_PRE    0x0C



/******************************************************************************
* Standard device requests
* Refer to chapter 9.4 of the specification.
******************************************************************************/
// Request type
#define USB_SPEC_DEVICE_REQUEST_TYPE_DEVICE_TO_HOST      0x80
#define USB_SPEC_DEVICE_REQUEST_TYPE_STANDARD            0x00
#define USB_SPEC_DEVICE_REQUEST_TYPE_CLASS_SPECIFIC      0x20
#define USB_SPEC_DEVICE_REQUEST_TYPE_VENDOR_SPECIFIC     0x40
#define USB_SPEC_DEVICE_REQUEST_TYPE_RECEIVER_DEVICE     0x00
#define USB_SPEC_DEVICE_REQUEST_TYPE_RECEIVER_INTERFACE  0x01
#define USB_SPEC_DEVICE_REQUEST_TYPE_RECEIVER_ENDPOINT   0x02
#define USB_SPEC_DEVICE_REQUEST_TYPE_RECEIVER_OTHER      0x03


// Device request codes
#define USB_SPEC_DEVICE_REQUEST_GET_STATUS               0x00
#define USB_SPEC_DEVICE_REQUEST_CLEAR_FEATURE            0x01
#define USB_SPEC_DEVICE_REQUEST_SET_FEATURE              0x03
#define USB_SPEC_DEVICE_REQUEST_SET_ADDRESS              0x05
#define USB_SPEC_DEVICE_REQUEST_GET_DESCRIPTOR           0x06
#define USB_SPEC_DEVICE_REQUEST_SET_DESCRIPTOR           0x07
#define USB_SPEC_DEVICE_REQUEST_GET_CONFIGURATION        0x08
#define USB_SPEC_DEVICE_REQUEST_SET_CONFIGURATION        0x09
#define USB_SPEC_DEVICE_REQUEST_GET_INTERFACE            0x0A
#define USB_SPEC_DEVICE_REQUEST_SET_INTERFACE            0x0B
#define USB_SPEC_DEVICE_REQUEST_SYNC_FRAME               0x0C



/******************************************************************************
* Constants regarding descriptors
* Refer to chapter 9.6 of the specification.
******************************************************************************/
#define USB_SPEC_DESCRIPTOR_TYPE_DEVICE     0x01
#define USB_SPEC_DESCRIPTOR_TYPE_CONFIG     0x02
#define USB_SPEC_DESCRIPTOR_TYPE_STRING     0x03
#define USB_SPEC_DESCRIPTOR_TYPE_INTERFACE  0x04
#define USB_SPEC_DESCRIPTOR_TYPE_EP         0x05

#define USB_SPEC_DESCRIPTOR_SIZE_DEVICE     18
#define USB_SPEC_DESCRIPTOR_SIZE_CONFIG     9
#define USB_SPEC_DESCRIPTOR_SIZE_STRING     2  // + the string itself
#define USB_SPEC_DESCRIPTOR_SIZE_INTERFACE  9
#define USB_SPEC_DESCRIPTOR_SIZE_EP         7

#define USB_SPEC_VERSION                    0x0110  // 1.1 (BCD)



// Strings
#define USB_SPEC_MAX_STRING_LENGTH          127  // ( 256 - 2 ) / 2
// Language descriptor for  english
#define USB_SPEC_STRING_LANGUAGE            0x0409



// Power management
#define USB_SPEC_CONFIG_POWER_BUS           0x80
#define USB_SPEC_CONFIG_POWER_SELF          0x40
#define USB_SPEC_CONFIG_POWER_REMOTE        0x20



// Transfer types
#define USB_SPEC_TRANSFER_TYPE_CONTROL      0x00
#define USB_SPEC_TRANSFER_TYPE_ISOCHRONOUS  0x01
#define USB_SPEC_TRANSFER_TYPE_BULK         0x02
#define USB_SPEC_TRANSFER_TYPE_INTERRUPT    0x03



/******************************************************************************
* Feature selectors
* Refer to chapter 9.4 of the specification.
******************************************************************************/
#define USB_SPEC_FEATURE_STALL              0x00
#define USB_SPEC_FEATURE_REMOTE_WAKEUP      0x01



/******************************************************************************
* Standard device request
* Refer to chapter 9.3 of the specification.
******************************************************************************/
typedef struct UsbSpecDeviceRequest_
{
  unsigned char requestType;
  unsigned char request;
  unsigned int value;
  unsigned int index;
  unsigned int length;
} UsbSpecDeviceRequest;



/******************************************************************************
* Device descriptor
* Refer to chapter 9.6.1 of the specification.
******************************************************************************/
typedef struct UsbSpecDeviceDesc_
{
  unsigned char length;
  unsigned char descType;
  unsigned int usbVersion;
  unsigned char deviceClass;
  unsigned char deviceSubClass;
  unsigned char deviceProtocol;
  unsigned char maxPacketSizeEp0;
  unsigned int vendorId;
  unsigned int productId;
  unsigned int deviceVersion;
  unsigned char manufacturerStringIndex;
  unsigned char productStringIndex;
  unsigned char serialNumberStringIndex;
  unsigned char nConfigurations;
} UsbSpecDeviceDesc;



/******************************************************************************
* Configuration descriptor
* Refer to chapter 9.6.2 of the specification.
******************************************************************************/
typedef struct UsbSpecConfigDesc_
{
  unsigned char length;
  unsigned char descType;
  unsigned int totalLength;
  unsigned char nInterfaces;
  unsigned char index;
  unsigned char stringIndex;
  unsigned char attributes;
  unsigned char maxPower;
} UsbSpecConfigDesc;



/******************************************************************************
* Interface descriptor
* Refer to chapter 9.6.3 of the specification.
******************************************************************************/
typedef struct UsbSpecInterfaceDesc_
{
  unsigned char length;
  unsigned char descType;
  unsigned char index;
  unsigned char alternateSetting;
  unsigned char nEp;
  unsigned char interfaceClass;
  unsigned char interfaceSubClass;
  unsigned char interfaceProtocol;
  unsigned char stringIndex;
} UsbSpecInterfaceDesc;



/******************************************************************************
* Endpoint descriptor
* Refer to chapter 9.6.4 of the specification.
******************************************************************************/
typedef struct UsbSpecEpDesc_
{
  unsigned char length;
  unsigned char descType;
  unsigned char epAddr;
  unsigned char attributes;
  unsigned int maxPacketSize;
  unsigned char interval;
} UsbSpecEpDesc;



/******************************************************************************
* Device states
* Refer to chapter 9.1 of the specification
******************************************************************************/
typedef enum
{
  // Since the USB controller does not issue an attach interrupt in device mode,
  // USB_SPEC_DEVICE_STATE_ATTACHED is not used.
  USB_SPEC_DEVICE_STATE_POWERED,
  USB_SPEC_DEVICE_STATE_DEFAULT,
  USB_SPEC_DEVICE_STATE_ADDRESS,
  USB_SPEC_DEVICE_STATE_CONFIGURED
  // USB_SPEC_DEVICE_STATE_SUSPENDED is maintained through usbDeviceStateSuspended
  // variable
} UsbSpecDeviceState;



#endif
// End of file

