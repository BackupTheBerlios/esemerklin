#ifndef __WEICHENLISTE_H
#define __WEICHENLISTE_H

#include "WeichenKnoten.h"
#include "Weiche.h"

/**
 * Diese Klasse ist f&uuml;r die Organisation der verketteten Liste der Weichen zust&auml;ndig.
 */
class WeichenListe {
	protected:
	WeichenKnoten* pStart;	//der Startpunkt der Liste
	WeichenKnoten* pCursor;	//Zeiger zum durch die Liste gehen
	WeichenKnoten* pGetCursor;	//Zeiger zum durch die Liste gehen f&uuml;r die Ausgabe
	unsigned short int anzahl;	//Speichert die aktuelle Anzahl an Weichen
	static const unsigned short int max_anzahl = 20;	//Gibt die maximal erlaubte Anzahl an
	
	public:
	/**
	 * Der Standardkonstruktor. Er setzt alle Variablen auf 0
	 */
	WeichenListe();
	
	/**
	 * F&uuml;gt eine Weiche der Liste hinzu. Es wird ein neuer Knoten definiert.
	 * \param pWeiche ist ein Zeiger auf eine Instanz vom Typ Weiche, welche vorher erzeugt werden musste.
	 * \return Liefert true, wenn die Weiche eingef&uuml;gt wurde. Liefert false, wenn schon 20 Weichen erfasst sind.
	 */
	bool InsertWeiche(Weiche* pWeiche);
	
	/**
	 * L&ouml;scht eine Weiche aus der Liste und somit auch den entsprechenden Knoten.
	 * \param address ist die echte Adresse der Weiche, die zu l&ouml;schen ist.
	 */
	void DeleteWeiche(char address);
	
	/**
	 * Liefert die n&auml;chste Weiche der Liste zur&uuml;ck. Sobald eine Weiche gel&ouml;scht oder hinzugef&uuml;gt wurde, wird es wieder auf die erste Weiche gesetzt.
	 * \return Ein Zeiger auf ein Objekt vom Typ Weiche.
	 */
	Weiche* GetNextWeiche();
	
	/**
	 * Baut ein Liste auf und f&uuml;llt diese mit entsprechenden Werte aus einer Datei. Standardm&auml;§ig ist das weichen.txt
	 * \param filename ist der Name und Pfad der Datei
	 */
	void FillFromFile(char* filename = "./weichen.txt");
	
	/**
	 * Schreibt die aktuelle Liste komplett in eine Datei und &uuml;berschreibt dabei die bestehende Datei.
	 * \param filename ist der Name und Pfad der Datei
	 */
	void WriteToFile(char* filename = "./weichen.txt");
};

#endif /*__WEICHENLISTE_H*/
