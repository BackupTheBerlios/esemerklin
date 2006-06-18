#ifndef __LOKLISTE_H
#define __LOKLISTE_H

#include "LokKnoten.h"
#include "Lok.h"

class LokListe {
	protected:
	LokKnoten* start;	//der Startpunkt der Liste
	LokKnoten* cursor;	//Zeiger zum durch die Liste gehen
	LokKnoten* getcursor;	//Zeiger für die Ausgabe
	
	public:
	LokListe();
	
	void InsertLok(Lok* lok);
	
	Lok* GetNextLok();
	
	void FillFromFile(char* filename = "./loks.txt");
	void WriteToFile(char* filename = "./loks.txt");
};

#endif /*__LOKLISTE_H*/
