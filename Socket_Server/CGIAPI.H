/****************************************************************************
* (C) 1999-2005 by BECK IPC GmbH
*
*  BECK IPC GmbH
*  Germany
*  
*  http://www.beck-ipc.com
*
* ---------------------------------------------------------------------------
* Module      : CGIAPI.H
* Function    : cgi api prototypes
* ---------------------------------------------------------------------------

$Header: /home/xubuntu/berlios_backup/github/tmp-cvs/esemerklin/Repository/Socket_Server/CGIAPI.H,v 1.1 2006/06/05 12:36:46 nadorwo Exp $

*****************************************************************************/

#ifndef _CGI_API_H__
#define _CGI_API_H__

/*************************************************************************/
#include "CGI.H"

/*************************************************************************/
// definitions
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


#ifdef __cplusplus
extern "C" {
#endif


/*************************************************************************/
//install cgi function
/*************************************************************************/
int _cdecl CGI_Install (CGI_Entry far  * cgiptr);

/*************************************************************************/
//delete cgi function
/*************************************************************************/
int _cdecl CGI_Delete (char far * PathPtr);


/*************************************************************************/
//Get formitem
/*************************************************************************/
void _cdecl CGI_GetFormItem (const char far * ArgumentBufferPtr,
                             FormItem far * formitem);

/*************************************************************************/
//Get next formitem
/*************************************************************************/
int _cdecl CGI_GetNextItem(char far * ArgumentBufferPtr, 
                           char far ** nextItemString);

/*************************************************************************/
//Get Main Page Name
/*************************************************************************/
int _cdecl CGI_SetMainPage (const char far *mainPageName);

/*************************************************************************/
//Get Root Dir
/*************************************************************************/
int _cdecl CGI_SetRootDir (const char far *rootDirName);

/*************************************************************************/
//Get Main Page Name
/*************************************************************************/
int _cdecl CGI_GetMainPage(char far **mainPageName);

/*************************************************************************/
//Get Root Dir
/*************************************************************************/
int _cdecl CGI_GetRootDir(char far **rootDirName);

/*************************************************************************/
//Install cgi function on http error
/*************************************************************************/
int _cdecl CGI_Install_Func_OnErr( unsigned int error_state,
                                   void far *CgiFuncOnErr);

/*************************************************************************/
//Install MIME table
/*************************************************************************/
int _cdecl CGI_Install_MIME_Table( unsigned int entries,
                                   CUSTOM_MIMETYPES_TABLE far *mimeTable);

/*************************************************************************/
//Remove MIME table
/*************************************************************************/
int _cdecl CGI_Remove_MIME_Table( void );


/*************************************************************************/
//SSI API
/*************************************************************************/
int _cdecl SSI_Set_File_Filter( char far * matchStr,
                                int matchType,
                                int server);
int _cdecl SSI_Register_Tag   ( const char far * tagStr,
                                SSI_Handler handler,
                                int server);
int _cdecl SSI_Set_TagLength  ( int tagLength );
int _cdecl SSI_Send_Buffer    ( unsigned long conHandle,
                                const char far *buffer,
                                int bufferlen,
                                int flag );
#ifdef __cplusplus
}
#endif

/*************************************************************************/
#endif /* _CGI_API_H__*/
/*************************************************************************/
//end cgiapi.h
