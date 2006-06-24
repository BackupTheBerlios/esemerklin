#include <iostream.h>
//#include <fstream.h>

#include "./Lok/Lok.h"
#include "./Weiche/Weiche.h"
#include "./Benutzer/Benutzer.h"
#include "./Lok/LokListe.h"
#include "./Weiche/WeichenListe.h"
#include "./Benutzer/BenutzerListe.h"


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
	loks.WriteToFile("./Lok/loksout.txt");
	*/
	/*
	 * Zum Testen der WeichenListe
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
	weichen.WriteToFile("./Weiche/weichenout.txt");
	*/
	BenutzerListe benutzer;
	
	//benutzer.AddBenutzerToFile("./Benutzer/user.txt", "NewUser3", "NewPW3", admin);
	benutzer.LoginBenutzer("./Benutzer/user.txt", "daniel", "danielpw");
	benutzer.LoginBenutzer("./Benutzer/user.txt", "tam", "tampw");
	benutzer.LoginBenutzer("./Benutzer/user.txt", "mohamed", "mohamedpw");
	
	benutzer.DeleteBenutzerFromFile("./Benutzer/user.txt", "NewUser");

	Benutzer* benutzertest = benutzer.GetNextBenutzer();
	while (benutzertest != 0) {
		cout << "Nickname: " << benutzertest->GetNickname() << endl;
		cout << "PW: " << benutzertest->GetPassword() << endl;
		cout << "Type: " << benutzertest->GetType() << endl;
		benutzertest = benutzer.GetNextBenutzer();
	}
	
    	return 1;
}