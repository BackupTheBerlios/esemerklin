/****************************************************************************
* (C) 1999-2005 by BECK IPC GmbH
*
*  BECK IPC GmbH
*  Germany
*  
*  http://www.beck-ipc.com
*
* ---------------------------------------------------------------------------
* Module         : TARGET.H
* Function       : Target dependent compilation switches for
*                  Beck C-Library API functions
* ---------------------------------------------------------------------------

$Header: /home/xubuntu/berlios_backup/github/tmp-cvs/esemerklin/Repository/Socket_Server/target.h,v 1.1 2006/06/05 12:36:47 nadorwo Exp $

****************************************************************************/

#ifndef _TARGET_H_
#define _TARGET_H_


////////////////////////////////////////////////////////////////////////
//  The Paradigm Beck IPC Edition compiler will define one of the
//  following target selectors.  This selection is controlled within
//  the Paradigm IDE with the Target Expert "Controller Hardware" 
//  selection.
//
//#define  SC12 
//#define  SC11 
//#define  SC13 
//#define  SC123 
//
//  At most one of these target selectors should be defined.
////////////////////////////////////////////////////////////////////////


// Paradigm Beck IPC Edition compiler defines the __ADDR24__ symbol
// when the -Y command line option ("Extended address space") is used.
#ifdef __ADDR24__
#ifndef SC123
#define  SC123
#endif
#endif

////////////////////////////////////////////////////////////////////////
//  Library Options:
////////////////////////////////////////////////////////////////////////

#ifdef SC123

#define TCPIP_STACK_V2    // New version of TCP/IP stack
    // See TCPIP.H library header file for variant library
    //  API selected due to this compilation switch.

#define RTI_ADJUSTABLE      // [TIMER] RTI option in CHIP.INI

#endif  // SC123



#endif // _TARGET_H_

// End of file TARGET.H