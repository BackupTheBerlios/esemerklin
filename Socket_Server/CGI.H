/****************************************************************************
* (C) 1999-2005 by BECK IPC GmbH
*
*  BECK IPC GmbH
*  Germany
*  
*  http://www.beck-ipc.com
*
* ---------------------------------------------------------------------------
* Module        : CGI.H
* Function      : types and definitions for access to webservers cgi
* ---------------------------------------------------------------------------

$Header: /home/xubuntu/berlios_backup/github/tmp-cvs/esemerklin/Repository/Socket_Server/CGI.H,v 1.1 2006/06/05 12:36:46 nadorwo Exp $

*****************************************************************************/

#ifndef _CGI_H__
#define _CGI_H__

/*****************************************************************************/
//CGI defines
/*****************************************************************************/

//Cgi HTTP requests
#define CgiHttpGet                    1  /*  Cgi request is HTTP GET  */
#define CgiHttpHead                   2  /*  Cgi request is HTTP HEAD */
#define CgiHttpPost                   3  /*  Cgi request is HTTP POST */


//Cgi HTTP responses
#define    CgiHttpOk                  0  /*  Cgi returns HTTP 200 Ok                 */
#define    CgiHttpOkStatic            1  /*  Cgi returns HTTP 200 Ok - Static Object */
#define    CgiHttpRedirect            2  /*  Cgi returns HTTP 302 Moved Temp         */
#define    CgiHttpNotModified         3  /*  Cgi returns HTTP 304 Not Modified       */
#define    CgiHttpUnauthorized        4  /*  Cgi returns HTTP 401 Unauthorized       */
#define    CgiHttpNotFound            5  /*  Cgi returns HTTP 404 Not Found          */
#define    CgiHttpOKNoDoc             6  /*  Cgi returns HTTP 204 No document follows*/


//CGI constants for content types ,fDatatype

#define  CGIDataTypeHtml              0  /* CGI returns  text/html */
#define  CGIDataTypeImageGif          1  /* image/gif */
#define  CGIDataTypeApplet            2  /* application/octet-stream */
#define  CGIDataTypeText              3  /* text/plain */
#define  CGIDataTypeImageJpeg         4  /* image/jpeg */
#define  CGIDataTypeImagePict         5  /* image/pict */
#define  CGIDataTypeImageTiff         6  /* image/tiff */
#define  CGIDataTypeImagePng          7  /* image/png  */
#define  CGIDataTypeForm              8  /* application/x-www-form-urlencoded */
#define  CGIDataTypeIpp               9  /* application/ipp */
#define  CGIDataTypeCss              10  /* text/css */
#define  CGIDataTypeXml              11  /* text/xml */
#define  CGIDataTypeWav              12  /* audio/wav */
#define  CGIDataTypePdf              13  /* application/pdf */
#define  CGIDataTypeJavaArchive      14  /* application/java-archive */
#define  CGIDataTypeOctet            15  /* application/octet-stream */
#define  CGIDataTypeVndWapWml        16  /* text/vnd.wap.wml */
#define  CGIDataTypeVndWapWbmp       17  /* image/vnd.wap.wbmp  */
#define  CGIDataTypeVndWapWmlc       18  /* application/vnd.wap.wmlc */
#define  CGIDataTypeVndWapWmlscript  19  /* text/vnd.wap.wmlscript   */
#define  CGIDataTypeVndWapWmlscriptc 20  /* text/vnd.wap.wmlscriptc  */
#define  CGIDataTypeScaleVectGraph   21  /* image/svg+xml */

/*****************************************************************************/
//CGI API calls
/*****************************************************************************/
#define CGI_INSTALL                0x01  /* Install a cgi function */
#define CGI_REMOVE                 0x02  /* Delete a cgi function  */
#define CGI_SETMAIN                0x03  /* Set new main page name  */
#define CGI_SETROOTDIR             0x04  /* Set webservers root directory */
#define CGI_GETROOTDIR             0x05  /* Get webservers root directory */
#define CGI_GETMAIN                0x06  /* Get name of main page*/
#define CGI_GETFORMITEM            0x07  /* Split argumentbuf into form item's name and value*/
#define CGI_FINDNEXTITEM           0x08  /* Find next formitem, if one */
#define CGI_INSTALL_PAS            0x09  /* Install a Turbo Pascal cgi procedure */
#define CGI_ERR_FUNC               0x0A  /* Install cgi function on http errors (e.g. 404) */
#define CGI_MIME_INSTALL           0x0B  /* Install a custom MIME table */
#define CGI_MIME_REMOVE            0x0C  /* Remove the custom MIME table */

/*****************************************************************************/
//SSI API calls
/*****************************************************************************/
#define SSI_SET_FILE_FILTER        0x81  /* Set SSI file filter */
#define SSI_REGISTER_TAG           0x82  /* Register SSI tag */
#define SSI_SET_TAG_LEN            0x83  /* Set the maximum SSI tag length */
#define SSI_SEND_BUFFER            0x84  /* Transmit a user buffer to HTTP client */

/*****************************************************************************/
//CGI API general Errorcodes
/*****************************************************************************/
#define CGI_NOT_SUPPORTED            -2
#define CGI_ERROR                    -1
#define CGI_ENOERROR                  0

/*****************************************************************************/
//CGI API special Errorcodes, returned at the ax-register
/*****************************************************************************/
#define CGI_INVALID_METHOD           -1
#define CGI_INVALID_NAME             -2
#define CGI_INVALID_DIR              -3
#define CGI_NO_FREE_ENTRY            -4
#define CGI_NOT_FOUND                -5

/*****************************************************************************/
//SSI API match types
/*****************************************************************************/
#define SSI_MATCH_FILE_NAME   0x01
#define SSI_MATCH_FILE_EXT    0x02
#define SSI_MATCH_FILE_PATH   0x03
#define SSI_MATCH_DIR_NAME    0x04
#define SSI_MATCH_DIR_PATH    0x05
/*****************************************************************************/
//SSI API callback return values
/*****************************************************************************/
#define SSI_OUTPUT_ENABLE     0x00
#define SSI_OUTPUT_DISABLE    0x01
#define SSI_ABORT_PAGE        0x02

/*****************************************************************************/
//types
/*****************************************************************************/
typedef struct tag_cgi_table{

     char far *   PathPtr;      // name of the page
     int          method;       // httpmethod: get or post
     void far *   CgiFuncPtr;   // ptr to callback function of this page

} CGI_Entry;



/*
   this type is needed, if the function CGI_GETFORMITEM will be used,
   the user must set the pointers of the structure
   to his own buffers look at example submit.c.
*/

typedef struct tag_form_item{

     char far * NamePtr;
     char far * ValuePtr;

} FormItem;


/*
   the called cgi function gets as a parmeter
   a pointer of the following structure, which contains
   the needed http-request data and response data
*/

typedef struct {

    //Request fields, read only!!!!

    unsigned char       fConnectionId;         //  internal use only
    int                 fHttpRequest;          //  internal use only
    char far *          fPathPtr;              //  URL
    char far *          fHostPtr;              //  Host:
    char far *          fRefererPtr;           //  (at time not supported)
    char far *          fAgentPtr;             //  (at time not supported)
    char far *          fLanguagePtr;          //  (at time not supported)
    unsigned long       fBrowserDate;          //  Date:   (internal)
    char far *          fArgumentBufferPtr;    //  Pointer at argument buffer
    long                fArgumentBufferLength; //  length of argument buffer, -1 buffer empty
    char far *          fUserNamePtr;          //  Username from Authorization
    char far *          fPasswordPtr;          //  Password from Authorization


    long far *          fRemoteIPPtr;          //  Pointer to RemoteIP in wrong byte order
                                               //  , do not modify

    //Response fields,

    int                 fResponseState;          // internal, do not modify
    int                 fHttpResponse;           // response msg mostly CgiHttpOK
    int                 fDataType;               // content type mostly text/html
    char far *          fResponseBufferPtr;      // pointer to created dynamic html page
    long                fResponseBufferLength;   // length of the created page
    unsigned long       fObjectDate;             // internal, do not modify
    unsigned int        fHostIndex;              // internal, do not modify

} rpCgi, far *rpCgiPtr;

// SSI callback handler
typedef int huge (far *SSI_Handler) (unsigned long conhandle, const char far * tagPtr);

// User custom MIME table
typedef struct
{
  unsigned int mimeId;    // must be greater than internal numbers
  char far*    mimeExt;   // file extension, e.g. "gif"
  char far*    mimeType;  // mime type, e.g. "image/gif"
} CUSTOM_MIMETYPES_TABLE;

/*****************************************************************************/
#endif /*_CGI_H__*/
