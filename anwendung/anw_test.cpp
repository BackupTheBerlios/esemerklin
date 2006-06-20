#include <iostream.h>
//#include <fstream.h>

#include "Lok.h"
#include "Weiche.h"
#include "Benutzer.h"
#include "LokListe.h"
#include "WeichenListe.h"


int main(int argc, char *argv[]) {
	/*Zum Testen der LokListe
	
	LokListe loks;	//erzeugt eine neue Liste

	loks.FillFromFile();	//füllt die Liste mit Kram aus der Datei loks.txt
	
	//Testausgabe
	cout << "Loks nach dem Einlesen:\n";
	Lok* loktest = loks.GetNextLok();
	while (loktest != 0) {
		cout << "Lok-Adresse: " << loktest->GetAddress() << endl;
		loktest = loks.GetNextLok();
	}
	
	//Eine Lok löschen
	loks.DeleteLok('3');
	
	//Testausgabe
	cout << "\nLoks vor dem Schreiben in die Datei:\n";
	loktest = loks.GetNextLok();	
	while (loktest != 0) {
		cout << "Lok-Adresse: " << loktest->GetAddress() << endl;
		loktest = loks.GetNextLok();
	}
	
	//daten in die Datei schreiben
	loks.WriteToFile("./loksout.txt");
	*/
	
	WeichenListe weichen;
	
	weichen.FillFromFile();
	
	//Testausgabe
	cout << "Weichen nach dem Einlesen:\n";
	Weiche* weichentest = weichen.GetNextWeiche();
	while (weichentest != 0) {
		cout << "Weichen-Adresse: " << weichentest->GetAddress() << endl;
		weichentest = weichen.GetNextWeiche();
	}
	
	//Eine Weiche löschen
	weichen.DeleteWeiche('c');
	
	//Testausgabe
	cout << "\nWeichen vor dem Schreiben in die Datei:\n";
	weichentest = weichen.GetNextWeiche();
	while (weichentest != 0) {
		cout << "Weichen-Adresse: " << weichentest->GetAddress() << endl;
		weichentest = weichen.GetNextWeiche();
	}
	
	//daten in die Datei schreiben
	weichen.WriteToFile("./weichenout.txt");
    	return 1;
}