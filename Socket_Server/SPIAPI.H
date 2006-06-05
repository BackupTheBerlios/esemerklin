/****************************************************************************
* (C) 1999-2005 by BECK IPC GmbH
*
*  BECK IPC GmbH
*  Germany
*
*  http://www.beck-ipc.com
*
* ---------------------------------------------------------------------------
* Module         : SPIAPI.H
* Function       : prototypes, constants for SPI API functions
* ---------------------------------------------------------------------------

$Header: /home/xubuntu/berlios_backup/github/tmp-cvs/esemerklin/Repository/Socket_Server/SPIAPI.H,v 1.1 2006/06/05 12:36:46 nadorwo Exp $

*****************************************************************************/

#ifndef SPIAPI_H
#define SPIAPI_H

/***************************************************************************/
// Prototyps
/***************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

void          _cdecl spi_init               (unsigned mode, char clock, char dataIn, char dataOut);
void          _cdecl spi_write              (const void far *bufferPtr, unsigned short nbytes);
void          _cdecl spi_read               (void far *bufferPtr, unsigned short nbytes);
void          _cdecl spi_read_write         (void far *rbufferPtr, const void far *wbufferPtr, unsigned short nbytes);

void          _cdecl spi_init_hw            (unsigned mode, unsigned div);
unsigned int  _cdecl spi_write_hw           (const void far *bufferPtr, unsigned short nbytes);
unsigned int  _cdecl spi_read_hw            (void far *bufferPtr, unsigned short nbytes);
unsigned int  _cdecl spi_read_write_hw      (void far *rbufferPtr, const void far *wbufferPtr, unsigned short nbytes);

void          _cdecl spi_slave_init         (unsigned mode);
void          _cdecl spi_slave_write        (unsigned char data);
unsigned char _cdecl spi_slave_read         (void);
unsigned char _cdecl spi_slave_read_write   (unsigned char data);
unsigned int  _cdecl spi_waiton_sem         (void);
unsigned int  _cdecl spi_waiton_sem_setmode (unsigned mode, unsigned div);
unsigned int  _cdecl spi_release_sem        (void);

#define SPI_MODE0          0x0000
#define SPI_MODE1          0x0001
#define SPI_MODE2          0x0002
#define SPI_MODE3          0x0003
#define SPI_OPEN_DRAIN     0x0004
#define SPI_AUTODRIVE      0x0008
#define SPI_INVERT_CS      0x0010
#define SPI_SHIFT1         0x0020
#define SPI_SHIFT2         0x0040
#define SPI_SHIFT3         0x0060
#define SPI_SHIFT4         0x0080
#define SPI_SHIFT5         0x00A0
#define SPI_SHIFT6         0x00C0
#define SPI_SHIFT7         0x00E0
#define SPI_SHIFT8         0x0000
#define SPI_ALTERNATE_IO   0x0100

#ifdef __cplusplus
}
#endif

#endif  // SPIAPI_H

