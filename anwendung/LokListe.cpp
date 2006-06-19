#include "LokListe.h"
#include <iostream.h>
#include <fstream.h>

LokListe::LokListe() {
	start = 0;
	cursor = start;
	getcursor = start;
}

void LokListe::InsertLok(Lok* lok) {
	LokKnoten* knoten = new LokKnoten(lok);
	
	if (start == 0) {	//Startknoten festlegen beim erstellen des ersten Knotens
		start = knoten;
	}
	else {
		cursor = start; //oder ist das schon oben definiert?
	
		while(cursor->GetNext() != 0)	//bis zum letzten Element gehen
			cursor = cursor->GetNext();
		
		cursor->SetNext(knoten);	//den next-Pointer der letzten Elements auf das neu hinzugefŸgte setzen
	}
	
	getcursor = start;
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
	ifstream file(filename);
	Lok* templok;
	
	while(file.get(ch)) {
		if (ch != '\n') {
			templok = new Lok(ch);
			InsertLok(templok);
		}	//of if
	}	//of while
	
	//delete templok;
	file.close();
}

void LokListe::WriteToFile(char* filename) {
	ofstream file(filename);
	getcursor = start;
	
	Lok* templok = GetNextLok();
	
	while (templok) {
		file << templok->GetAddress() << "\n";
		templok = GetNextLok();
	}	//of while
	file.close();	
}