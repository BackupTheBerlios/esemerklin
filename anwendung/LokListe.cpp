#include "LokListe.h"
#include <fstream.h>

LokListe::LokListe() {
	start = 0;
	cursor = start;
	getcursor = start;
	anzahl = 0;
}

bool LokListe::InsertLok(Lok* lok) {
	if (anzahl >= max_anzahl)		//wenn schon 10 Loks in der Liste sind, mache nix.
		return false;
		
	LokKnoten* knoten = new LokKnoten(lok);	//ein neuer Knoten wird erstellt mit dem Zeiger auf die entsprechende Lok
	
	if (start == 0) {	//Startknoten festlegen beim erstellen des ersten Knotens
		start = knoten;
	}
	else {
		cursor = start;	//am Anfang wird der Cursor auf die Startposition gesetzt
	
		while(cursor->GetNext() != 0)	//bis zum letzten Element gehen.Setzt cursor auf das letzte Element.
			cursor = cursor->GetNext();
		
		cursor->SetNext(knoten);	//den next-Pointer der letzten Elements auf das neu hinzugef�gte setzen
	}	
	anzahl++;	//die Anzahl der Loks erh�hen
	getcursor = start;	//den getcursor reseten
	return true;	//alles ok
}

void LokListe::DeleteLok(char address) {
	cursor = start;	//am Anfang wird der Cursor auf die Startposition gesetzt
	LokKnoten* temp;	//ein tempor�rer Knoten zum Zwischenspeichern einer Adresse
	
	//Wenn das erste Element gel�scht werden soll
	if (cursor->GetLok()->GetAddress() == address) {
		start = start->GetNext();	//Der Startpunkt wird ein Element weiter gesetzt
		delete cursor;			//Der Knoten an der ersten Stelle wird gel�scht
		getcursor = start;		//getcursor reseten
		anzahl--;				//anzahl der Loks in der lIste verringern
		return;					//und zur�ck
	}
	
	//Objekt vor dem zu l�schenden Objekt ermitteln und cursor auf dieses Element setzen
	while(cursor->GetNext()->GetLok()->GetAddress() != address)	 {
		cursor = cursor->GetNext();
		if (cursor == 0);	//Wenn nix gefunden wurde zur�ck ohne Aktion
			return;
	}
	
	temp = cursor->GetNext()->GetNext();	//den zu l�schenden �berspringen
	
	delete cursor->GetNext();	//den nachfolgenden Knoten l�schen
	cursor->SetNext(temp);	//Dem Knoten den neuen Nachfolger mitteilen
	getcursor = start;		//getcursor reseten
	anzahl--;				//anzahl der Loks in der Liste verringen
}

Lok* LokListe::GetNextLok() {
	Lok* templok;
	if (getcursor != 0)
		templok = getcursor->GetLok();
	else
		return 0;
		
	getcursor = getcursor->GetNext();	//den cursor einen Knoten weiter setzen
	return templok;
}

void LokListe::FillFromFile(char* filename) {
	char ch;
	ifstream file(filename);	//ein Stream-Objekt anlegen
	Lok* templok;
	
	while(file.get(ch)) {		//solange was in der Datei steht
		if (ch != '\n') {	//wenns kein Zeilenumbruch ist
			templok = new Lok(ch);	//eine neue Lok erzeugen
			InsertLok(templok);		//die Lok einf�gen in die Liste
		}	//of if
	}	//of while
	
	file.close();	//Stream schlie�en
}

void LokListe::WriteToFile(char* filename) {
	ofstream file(filename);	//ein Stream-Objekt anlegen
	getcursor = start;		//getcursor reseten, damit die komplette Liste durchgegangen wird
	
	Lok* templok = GetNextLok();
	
	//solange, bis das Ende der Liste erreicht ist.
	while (templok) {
		file << templok->GetAddress() << "\n";		//Adresse in die Datei schreiben
		templok = GetNextLok();					//n�chste Lok holen
	}	//of while
	file.close();		//Stream schlie�en
}