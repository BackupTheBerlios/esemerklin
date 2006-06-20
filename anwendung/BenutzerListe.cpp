#include "BenutzerListe.h"
#include <fstream.h>

BenutzerListe::BenutzerListe() {
	pStart = 0;
	pCursor = pStart;
	pGetCursor = pStart;
	anzahl = 0;
}

bool BenutzerListe::InsertBenutzer(Benutzer* pBenutzer) {
	if (anzahl >= max_anzahl)		//wenn schon 10 Benutzer in der Liste sind, mache nix.
		return false;
		
	BenutzerKnoten* pKnoten = new BenutzerKnoten(pBenutzer);	//ein neuer Knoten wird erstellt mit dem Zeiger auf die entsprechende Benutzer
	
	if (pStart == 0) {	//Startknoten festlegen beim erstellen des ersten Knotens
		pStart = pKnoten;
	}
	else {
		pCursor = pStart;	//am Anfang wird der Cursor auf die Startposition gesetzt
	
		while(pCursor->GetNext() != 0)	//bis zum letzten Element gehen.Setzt pCursor auf das letzte Element.
			pCursor = pCursor->GetNext();
		
		pCursor->SetNext(pKnoten);	//den next-Pointer der letzten Elements auf das neu hinzugef�gte setzen
	}	
	anzahl++;	//die Anzahl der Benutzer erh�hen
	pGetCursor = pStart;	//den pGetCursor reseten
	return true;	//alles ok
}

void BenutzerListe::DeleteBenutzer(char* nickname) {
	pCursor = pStart;	//am Anfang wird der Cursor auf die Startposition gesetzt
	BenutzerKnoten* temp;	//ein tempor�rer Knoten zum Zwischenspeichern einer Adresse
	
	//Wenn das erste Element gel�scht werden soll
	if (strcmp(pCursor->GetBenutzer()->GetNickname(),nickname)) {
		pStart = pStart->GetNext();	//Der Startpunkt wird ein Element weiter gesetzt
		delete pCursor;			//Der Knoten an der ersten Stelle wird gel�scht
		pGetCursor = pStart;		//pGetCursor reseten
		anzahl--;				//anzahl der Benutzer in der lIste verringern
		return;					//und zur�ck
	}
	
	//Objekt vor dem zu l�schenden Objekt ermitteln und pCursor auf dieses Element setzen
	while(!strcmp(pCursor->GetNext()->GetBenutzer()->GetNickname(),nickname)) {
		pCursor = pCursor->GetNext();
		if (pCursor->GetNext() == 0) {	//Wenn nix gefunden wurde zur�ck ohne Aktion
			pGetCursor = pStart;
			return;
		}
	}
	
	temp = pCursor->GetNext()->GetNext();	//den zu l�schenden �berspringen
	
	delete pCursor->GetNext();	//den nachfolgenden Knoten l�schen
	pCursor->SetNext(temp);	//Dem Knoten den neuen Nachfolger mitteilen
	pGetCursor = pStart;		//pGetCursor reseten
	anzahl--;				//anzahl der Benutzer in der Liste verringen
}

Benutzer* BenutzerListe::GetNextBenutzer() {
	Benutzer* tempbenutzer;
	if (pGetCursor != 0)
		tempbenutzer = pGetCursor->GetBenutzer();
	else
		return 0;
		
	pGetCursor = pGetCursor->GetNext();	//den pCursor einen Knoten weiter setzen
	return tempbenutzer;
}

/*
 * Ab hier m�ssen die Funktionen noch neu geschrieben werden
 * 
void BenutzerListe::FillFromFile(char* filename) {
	char ch;
	ifstream file(filename);	//ein Stream-Objekt anlegen
	Benutzer* tempbenutzer;
	
	while(file.get(ch)) {		//solange was in der Datei steht
		if (ch != '\n') {	//wenns kein Zeilenumbruch ist
			tempbenutzer = new Benutzer(ch);	//eine neue Benutzer erzeugen
			InsertBenutzer(tempbenutzer);		//die Benutzer einf�gen in die Liste
		}	//of if
	}	//of while
	
	file.close();	//Stream schlie�en
}

void BenutzerListe::WriteToFile(char* filename) {
	ofstream file(filename);	//ein Stream-Objekt anlegen
	pGetCursor = pStart;		//pGetCursor reseten, damit die komplette Liste durchgegangen wird
	
	Benutzer* tempbenutzer = GetNextBenutzer();
	
	//solange, bis das Ende der Liste erreicht ist.
	while (tempbenutzer) {
		file << tempbenutzer->GetAddress() << "\n";		//Adresse in die Datei schreiben
		tempbenutzer = GetNextBenutzer();					//n�chste Benutzer holen
	}	//of while
	file.close();		//Stream schlie�en
}
*/