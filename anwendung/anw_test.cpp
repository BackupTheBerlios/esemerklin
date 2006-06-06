#include <iostream.h>
#include <stdio.h>
#include "clib.h"

#include "sio_init.h"
#include "sio_lok.h"
#include "sio_wei.h"

/*
Die Anwendung nimmt einen Parameter an, und schreibt diesen als lok_func (Geschwindigkeit)
l.set_lok(3,args[0],1);
*/
void main(int argc, char *argv[])
{
    	char status;
    	
    	printf("l.set_lok(3,%s,1);" , argv[1]);

    //Object declaraction

    SIO_INIT io;
    SIO_LOK l;
    SIO_WEICHE w;

    // SIO configuration
    io.set_parameter();
    io.initialize();
	
    // velocity control
    //l.set_lok(3,0x1a,1);
    l.set_lok(3,(char)argv[1],1);	//hier wird der Parameter eingesetzt
    status = l.velocity();
}