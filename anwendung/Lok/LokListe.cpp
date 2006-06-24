#include "LokListe.h"
#include <fstream.h>

LokListe::LokListe() {
	pStart = 0;
	pCursor = pStart;
	pGetCursor = pStart;
	anzahl = 0;
}

bool LokListe::InsertLok(Lok* pLok) {
	if (anzahl >= max_anzahl)		//wenn schon 10 Loks in der Liste sind, mache nix.
		return false;
		
	LokKnoten* pKnoten = new LokKnoten(pLok);	//ein neuer Knoten wird erstellt mit dem Zeiger auf die entsprechende Lok
	
	if (pStart == 0) {	//Startknoten festlegen beim erstellen des ersten Knotens
		pStart = pKnoten;
	}
	else {
		pCursor = pStart;	//am Anfang wird der Cursor auf die Startposition gesetzt
	
		while(pCursor->GetNext() != 0)	//bis zum letzten Element gehen.Setzt pCursor auf das letzte Element.
			pCursor = pCursor->GetNext();
		
		pCursor->SetNext(pKnoten);	//den next-Pointer der letzten Elements auf das neu hinzugef�gte setzen
	}	
	anzahl++;	//die Anzahl der Loks erh�hen
	pGetCursor = pStart;	//den pGetCursor reseten
	return true;	//alles ok
}

void LokListe::DeleteLok(char address) {
	pCursor = pStart;	//am Anfang wird der Cursor auf die Startposition gesetzt
	LokKnoten* temp;	//ein tempor�rer Knoten zum Zwischenspeichern einer Adresse
	
	//Wenn das erste Element gel�scht werden soll
	if (pCursor->GetLok()->GetAddress() == address) {
		pStart = pStart->GetNext();	//Der Startpunkt wird ein Element weiter gesetzt
		delete pCursor;			//Der Knoten an der ersten Stelle wird gel�scht
		pGetCursor = pStart;		//pGetCursor reseten
		anzahl--;				//anzahl der Loks in der lIste verringern
		return;					//und zur�ck
	}
	
	//Objekt vor dem zu l�schenden Objekt ermitteln und pCursor auf dieses Element setzen
	while(pCursor->GetNext()->GetLok()->GetAddress() != address)	 {
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
	anzahl--;				//anzahl der Loks in der Liste verringen
}

Lok* LokListe::GetNextLok() {
	Lok* templok;
	if (pGetCursor != 0)
		templok = pGetCursor->GetLok();
	else
		return 0;
		
	pGetCursor = pGetCursor->GetNext();	//den pCursor einen Knoten weiter setzen
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
	pGetCursor = pStart;		//pGetCursor reseten, damit die komplette Liste durchgegangen wird
	
	Lok* templok = GetNextLok();
	
	//solange, bis das Ende der Liste erreicht ist.
	while (templok) {
		file << templok->GetAddress() << "\n";		//Adresse in die Datei schreiben
		templok = GetNextLok();					//n�chste Lok holen
	}	//of while
	file.close();		//Stream schlie�en
}