/****************************************************************************
* (C) 2006 by BECK IPC GmbH
*
*  BECK IPC GmbH
*  Germany
*
*  http://www.beck-ipc.com
*
* ---------------------------------------------------------------------------
* Module        : EXTDISK.H
* Function      : Defines and typedefs for EXTDISK.C
* ---------------------------------------------------------------------------

$Header: /home/xubuntu/berlios_backup/github/tmp-cvs/esemerklin/Repository/Socket_Server/EXTDISK.H,v 1.1 2006/06/05 12:36:46 nadorwo Exp $

****************************************************************************/

#ifndef __EXTDISK_H__
#define __EXTDISK_H__


/*************************************************************************/
//prototypes
/*************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

#define EXTDISK_EVENT_INSTALL   0x0001
#define EXTDISK_EVENT_REMOVE    0x0002

typedef void (far * EXTDISK_CALLBACK)(unsigned int event);

int _cdecl Extdisk_install_drive    (unsigned long totalsectors);
int _cdecl Extdisk_remove_drive     (void);

int _cdecl Extdisk_install_callback (EXTDISK_CALLBACK callback);
int _cdecl Extdisk_remove_callback  (EXTDISK_CALLBACK callback);

#ifdef __cplusplus
}
#endif

/*************************************************************************/
#endif /* __EXTDISK_H__*/

/*************************************************************************/
//end extdisk.h
/*************************************************************************/