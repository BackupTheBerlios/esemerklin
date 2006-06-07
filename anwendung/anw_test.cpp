#include <iostream.h>
//#include <stdio.h>

#include "Lok.h"
#include "Weiche.h"


int main(int argc, char *argv[])
{
	bool func[4] = {1,0,1,0};
    	Lok lok(9, "pete", 1, func);
    	//Lok lok;
    	Weiche weiche(false, "ruma");
    	//Weiche weiche;
    	
    /*
    weiche.SetStatus();
	weiche.SetAddress("kaka");
    	*/
    	/*
    	lok.SetSpeed(-11);
    	lok.SetAddress("0234");
    	lok.SetDirection();
    	lok.SetXtrafunc(2);
    	*/
  	
  	cout << "Weichendaten:" << endl;
  	cout << "Status: " << weiche.GetStatus() << endl;
  	cout << "Address: " << weiche.GetAddress() << endl << endl;
  	
    	cout << "Lokdaten:" << endl;
    	cout << "Speed: " << lok.GetSpeed() << endl;
    	cout << "Address: " << lok.GetAddress() << endl;
    	cout << "Richtung: " << lok.GetDirection() << endl;
    	for (int i=0; i<4 ; i++)
    	    	cout << "Xtrafkt." << (i+1) << ": " << lok.GetXtrafunc(i) << endl;
    	
    	return 1;
}