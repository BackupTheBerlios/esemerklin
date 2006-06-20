#include "WeichenListe.h"
#include <fstream.h>

WeichenListe::WeichenListe() {
	pStart = 0;
	pCursor = pStart;
	pGetCursor = pStart;
	anzahl = 0;
}

bool WeichenListe::InsertWeiche(Weiche* pWeiche) {
	if (anzahl >= max_anzahl)		//wenn schon 20 Weichen in der Liste sind, mache nix.
		return false;
		
	WeichenKnoten* pKnoten = new WeichenKnoten(pWeiche);	//ein neuer Knoten wird erstellt mit dem Zeiger auf die entsprechende Weiche
	
	if (pStart == 0) {	//Startknoten festlegen beim erstellen des ersten Knotens
		pStart = pKnoten;
	}
	else {
		pCursor = pStart;	//am Anfang wird der Cursor auf die Startposition gesetzt
	
		while(pCursor->GetNext() != 0)	//bis zum letzten Element gehen.Setzt pCursor auf das letzte Element.
			pCursor = pCursor->GetNext();
		
		pCursor->SetNext(pKnoten);	//den next-Pointer der letzten Elements auf das neu hinzugef�gte setzen
	}	
	anzahl++;	//die Anzahl der Weichen erh�hen
	pGetCursor = pStart;	//den pGetCursor reseten
	return true;	//alles ok
}

void WeichenListe::DeleteWeiche(char address) {
	pCursor = pStart;	//am Anfang wird der Cursor auf die Startposition gesetzt
	WeichenKnoten* temp;	//ein tempor�rer Knoten zum Zwischenspeichern einer Adresse
	
	//Wenn das erste Element gel�scht werden soll
	if (pCursor->GetWeiche()->GetAddress() == address) {
		pStart = pStart->GetNext();	//Der Startpunkt wird ein Element weiter gesetzt
		delete pCursor;			//Der Knoten an der ersten Stelle wird gel�scht
		pGetCursor = pStart;		//pGetCursor reseten
		anzahl--;				//anzahl der Weichen in der lIste verringern
		return;					//und zur�ck
	}
	
	//Objekt vor dem zu l�schenden Objekt ermitteln und pCursor auf dieses Element setzen
	while(pCursor->GetNext()->GetWeiche()->GetAddress() != address)	 {
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
	anzahl--;				//anzahl der Weichen in der Liste verringen
}

Weiche* WeichenListe::GetNextWeiche() {
	Weiche* tempweiche;
	if (pGetCursor != 0)
		tempweiche = pGetCursor->GetWeiche();
	else
		return 0;
		
	pGetCursor = pGetCursor->GetNext();	//den pCursor einen Knoten weiter setzen
	return tempweiche;
}

void WeichenListe::FillFromFile(char* filename) {
	char ch;
	ifstream file(filename);	//ein Stream-Objekt anlegen
	Weiche* tempweiche;
	
	while(file.get(ch)) {		//solange was in der Datei steht
		if (ch != '\n') {	//wenns kein Zeilenumbruch ist
			tempweiche = new Weiche(geradeaus, ch);	//eine neue Weiche erzeugen
			InsertWeiche(tempweiche);		//die Weiche einf�gen in die Liste
		}	//of if
	}	//of while
	
	file.close();	//Stream schlie�en
}

void WeichenListe::WriteToFile(char* filename) {
	ofstream file(filename);	//ein Stream-Objekt anlegen
	pGetCursor = pStart;		//pGetCursor reseten, damit die komplette Liste durchgegangen wird
	
	Weiche* tempweiche = GetNextWeiche();
	
	//solange, bis das Ende der Liste erreicht ist.
	while (tempweiche) {
		file << tempweiche->GetAddress() << "\n";		//Adresse in die Datei schreiben
		tempweiche = GetNextWeiche();					//n�chste Weiche holen
	}	//of while
	file.close();		//Stream schlie�en
}