/****************************************************************************
* (C) 1999-2005 by BECK IPC GmbH
*
*  BECK IPC GmbH
*  Germany
*  
*  http://www.beck-ipc.com
*
* ---------------------------------------------------------------------------
* Module         : HELPER.H
* Function       : prototypes, constants for helper functions
* ---------------------------------------------------------------------------

$Header: /home/xubuntu/berlios_backup/github/tmp-cvs/esemerklin/Repository/Socket_Server/HELPER.H,v 1.1 2006/06/05 12:36:46 nadorwo Exp $

*****************************************************************************/

#ifndef HELPER_H
#define HELPER_H

#include <dos.h>

/***************************************************************************/
// Prototyps
/***************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

typedef int _cdecl (far * Sprintf_Fptr)(char far * buf,
                                        const char far * fmt,
                                        void far * ap);

void         _cdecl helper_strout( const char far *s );
int          _cdecl helper_chrout( char ch, int zero );
void         _cdecl helper_dezout( unsigned int x, int zero );
void         _cdecl helper_hexdig( unsigned char dig );
void         _cdecl helper_hexout( unsigned hex );
int          _cdecl helper_printf( const char *fmt, ...);
int          _cdecl helper_sprintf( char *buffer, const char *fmt, ...);

unsigned int _cdecl helper_alloc_rtos_mem  ( unsigned long size );
int          _cdecl helper_release_rtos_mem( unsigned int seg );

unsigned int _cdecl helper_alloc_rtos_fast_mem(unsigned long size);

#ifdef __cplusplus
}
#endif


#endif // HELPER_H
