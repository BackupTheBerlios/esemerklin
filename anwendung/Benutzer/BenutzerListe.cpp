#include "BenutzerListe.h"
#include <iostream.h>
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
		
		pCursor->SetNext(pKnoten);	//den next-Pointer der letzten Elements auf das neu hinzugefügte setzen
	}	
	anzahl++;	//die Anzahl der Benutzer erhöhen
	pGetCursor = pStart;	//den pGetCursor reseten
	return true;	//alles ok
}

void BenutzerListe::DeleteBenutzer(char* nickname) {
	pCursor = pStart;	//am Anfang wird der Cursor auf die Startposition gesetzt
	BenutzerKnoten* temp;	//ein temporärer Knoten zum Zwischenspeichern einer Adresse
	
	//Wenn das erste Element gelöscht werden soll
	if (strcmp(pCursor->GetBenutzer()->GetNickname(),nickname)) {
		pStart = pStart->GetNext();	//Der Startpunkt wird ein Element weiter gesetzt
		delete pCursor;			//Der Knoten an der ersten Stelle wird gelöscht
		pGetCursor = pStart;		//pGetCursor reseten
		anzahl--;				//anzahl der Benutzer in der lIste verringern
		return;					//und zurück
	}
	
	//Objekt vor dem zu löschenden Objekt ermitteln und pCursor auf dieses Element setzen
	while(!strcmp(pCursor->GetNext()->GetBenutzer()->GetNickname(),nickname)) {
		pCursor = pCursor->GetNext();
		if (pCursor->GetNext() == 0) {	//Wenn nix gefunden wurde zurück ohne Aktion
			pGetCursor = pStart;
			return;
		}
	}
	
	temp = pCursor->GetNext()->GetNext();	//den zu löschenden überspringen
	
	delete pCursor->GetNext();	//den nachfolgenden Knoten löschen
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

bool BenutzerListe::BenutzerExistsInFile(char* filename, char* nickname) {
	ifstream file(filename);
	char zeile[80];
	char* wort = NULL;
	int nResult;
	
	if (!file) return false;	//Wenn ein Fehler auftritt, nix machen und zurück
	
	while(!file.eof()) {			//Solange nicht Ende der Datei erreicht
		file.getline(zeile, 80);	//nächste Zeile einlesen
		
		wort = strtok(zeile, ",");						//den nickname rausfiltern
		if (wort != NULL)								//wenn strtok was findet
			nResult = strcmp(wort, nickname);				//ist der nickname vorhanden und hat er die selbe Länge?
		
		if (!nResult) {
			file.close();
			return true;
		}
	}
	file.close();
	return false;
}

bool BenutzerListe::AddBenutzerToFile(char* filename, char* nickname, char* password, usertype type) {
	ofstream file(filename, std::ios::app);	//Die Daten werden angehängt
	if (!file) return false;	//Wenn ein Fehler auftritt, nix machen und zurück
	
	if (!BenutzerExistsInFile(filename, nickname)) {
		file << "\n" << nickname << "," << password << "," << type;
		file.close();
		return true;
	}
	file.close();
	return false;
}

bool BenutzerListe::LoginBenutzer(char* filename, char* nickname, char* password) {
	ifstream file(filename);	//Datei zum lesen öffnen
	char zeile[80];			//speichert die eingelesene Zeile der Datei
	char* wort = NULL;		//Speichert das einzelne Wort, welches von Kommas getrennt ist
	int nResult;				//Speichert, ob der nickname gefunden wurde und übereinstimmt
	int pResult;				//Speichert, ob das Passwort gefunden wurde und übereinstimmt
	usertype type;			//Speichert den konvertierten Usertype, der aus der Datei eingelesen wurde
	
	if (!file) return false;	//Wenn ein Fehler auftritt, nix machen und zurück

	while(!file.eof()) {			//Solange nicht Ende der Datei erreicht
		file.getline(zeile, 80);	//nächste Zeile einlesen
		
		wort = strtok(zeile, ",");						//den nickname rausfiltern
		if (wort != NULL)								//wenn strtok was findet
			nResult = strcmp(wort, nickname);				//ist der nickname vorhanden und hat er die selbe Länge?
		
		wort = strtok(NULL, ",");							//das PW rausfiltern
		if (wort != NULL)								//wenn strtok was findet
			pResult = strcmp(wort, password);//ist es vorhanden und hat es die selbe Länge?
		
		if (!nResult && !pResult) {		//nickname und passwort stimmen überein mit denen in der Datei
			wort = strtok(NULL, ",");	//den Benutzerstatus aus der Datei lesen
			type = (usertype) atoi(wort);	//Konvertierung des Status'
			Benutzer* pBenutzer = new Benutzer(nickname, password, type);	//neuen Benutzer erzeugen
			file.close();	//Datei schließen
			if (!InsertBenutzer(pBenutzer)) return false;	//Benutzer der verketteten Liste hinzufügen
			return true;
		}
	}	
	file.close();
	return false;
}
/* Funktioniert noch nicht
bool BenutzerListe::DeleteBenutzerFromFile(char* filename, char* nickname) {
	ifstream file(filename);
	char* newlines[20];
	char zeile[80];
	int stringNotEqual = true;
	char* wort;
	int count = 0;
	bool deleted = false;
	
	if (!file) return false;
	
	while(!file.eof()) {
		file.getline(zeile, 80);
		cout << zeile << " Ende\n";
		//wort = strtok(zeile, ",");						//den nickname rausfiltern
		//if (wort != NULL)								//wenn strtok was findet
		//	stringNotEqual = strcmp(wort, nickname);				//ist der nickname vorhanden und hat er die selbe Länge?
		if (stringNotEqual)	{	//wenn nix gefunden wurde
			//strcpy(newlines[count], zeile);
			newlines[count] = new char[80];
			newlines[count] = zeile;
			cout << *(newlines) << " NewEnde\n";
			//if (count > 0 )
			//	cout << newlines[count-1] << " voherriges ende\n";
			count++;
		}
		else {
			deleted = true;
		}
	}
	file.close();
	cout << newlines[1] << " NewEnde2\n";
	
	for (int i=0; i < count; i++) {
			cout << newlines[i] << " Newline einf. ende\n";
		}
	
	if (deleted) {
		ofstream fileout(filename);
		if (!fileout) return false;
	
		for (int i=0; i < count; i++) {
			cout << newlines[i] << i << " Newline einf. ende\n";
			fileout << newlines[i];
		}
		fileout.close();
	}
	return deleted;	
}
*/