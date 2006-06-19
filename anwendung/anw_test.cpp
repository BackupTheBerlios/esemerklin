#include <iostream.h>
#include <fstream.h>

#include "Lok.h"
#include "Weiche.h"
#include "Benutzer.h"
#include "LokListe.h"


int main(int argc, char *argv[])
{
	LokListe loks;	//erzeugt eine neue Liste
	/*
	Lok templok[3];
	templok[0].SetAddress('9');
	templok[1].SetAddress('b');
	templok[2].SetAddress('7');
	*/
	
	loks.FillFromFile();	//füllt die Liste mit Kram aus der Datei loks.txt
	/*
	loks.InsertLok(&templok[0]);
	loks.InsertLok(&templok[1]);
	loks.InsertLok(&templok[2]);
	*/
	
	//Testausgabe
	Lok* loktest = loks.GetNextLok();
	while (loktest != 0) {
		cout << "Lok-Adresse: " << loktest->GetAddress() << endl;
		loktest = loks.GetNextLok();
	}
	
	//Eine Lok löschen
	loks.DeleteLok('3');
	
	//Testausgabe
	loktest = loks.GetNextLok();	
	while (loktest != 0) {
		cout << "Lok-Adresse: " << loktest->GetAddress() << endl;
		loktest = loks.GetNextLok();
	}
	
	//daten in die Datei schreiben
	loks.WriteToFile("./loksout.txt");

    	return 1;
}