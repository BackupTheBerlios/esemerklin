#include <iostream.h>
#include <fstream.h>

#include "Lok.h"
#include "Weiche.h"
#include "Benutzer.h"
#include "LokListe.h"


int main(int argc, char *argv[])
{
	LokListe loks;
	
	Lok templok[3];
	templok[0].SetAddress('9');
	templok[1].SetAddress('b');
	templok[2].SetAddress('7');
	
	
	//loks.FillFromFile("./loks.txt");
	loks.InsertLok(&templok[0]);
	loks.InsertLok(&templok[1]);
	loks.InsertLok(&templok[2]);
	
	//cout << "Ausgabe:\n";
	/*
	Lok* loktest = loks.GetNextLok();
	
	while (loktest != 0) {
		cout << "Lok-Adresse: " << loktest->GetAddress() << endl;
		loktest = loks.GetNextLok();
	}
	*/
	loks.WriteToFile("./loksout.txt");
	/*
	ofstream fout("./test.txt");
	
	//fout.put('e');// << "Bla blub\n";
	fout << templok[0].GetAddress() << " Test";
	fout.close();
	*/
    	return 1;
}