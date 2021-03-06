#ifndef __LOKLISTE_H
#define __LOKLISTE_H

#include "LokKnoten.h"
#include "Lok.h"

/**
 * \brief Diese Klasse ist f&uuml;r die Organisation der verketteten Liste der Loks zust&auml;ndig.
 * 
 * Diese Klasse sollte eingebunden werden und eine Instanz davon erzeugt werden. Dar&uuml;ber kann man s&auml;mtliche Loks verwalten.
 * Am Anfang, sollte immer die Funktion FillFromFile ausgef&uuml;hrt werden.
 * Am Ende muss/sollte immer die Funktion WriteToFile ausgef&uuml;hrt werden
 * \author Daniel Pietzsch
 */
class LokListe {
	protected:
	LokKnoten* pStart;	/**< \brief der Startpunkt der Liste */
	LokKnoten* pCursor;	/**< \brief Zeiger zum durch die Liste gehen */
	LokKnoten* pGetCursor;	/**< \brief Zeiger zum durch die Liste gehen f&uuml;r die Ausgabe */
	unsigned short int anzahl;	/**< \brief Speichert die aktuelle Anzahl an Loks */
	unsigned short int max_anzahl;	/**< \brief Gibt die maximal erlaubte Anzahl an */
	
	public:
	/**
	 * Der Standardkonstruktor. Er setzt alle Variablen auf 0
	 */
	LokListe();
	
	/**
	 * F&uuml;gt eine Lok der Liste hinzu. Es wird ein neuer Knoten definiert.
	 * \param pLok ist ein Zeiger auf eine Instanz vom Typ Lok, welche vorher erzeugt werden musste.
	 * \return Liefert true, wenn die Lok eingef&uuml;gt wurde. Liefert false, wenn schon 10 Loks erfasst sind.
	 */
	bool InsertLok(Lok* pLok);
	
	/**
	 * L&ouml;scht eine Lok aus der Liste und somit auch den entsprechenden Knoten.
	 * \param address ist die echte Adresse der Lok, die zu l&ouml;schen ist.
	 */
	void DeleteLok(char address);
	
	/**
	 * Liefert die n&auml;chste Lok der Liste zur&uuml;ck. Sobald eine Lok gel&ouml;scht oder hinzugef&uuml;gt wurde, wird es wieder auf die erste Lok gesetzt.
	 * \return Ein Zeiger auf ein Objekt vom Typ Lok.
	 */
	Lok* GetNextLok();
	
	/**
	 * Baut ein Liste auf und f&uuml;llt diese mit entsprechenden Werte aus einer Datei.
	 * \param filename ist der Name und Pfad der Datei
	 */
	void FillFromFile(char* filename);
	
	/**
	 * Schreibt die aktuelle Liste komplett in eine Datei und &uuml;berschreibt dabei die bestehende Datei.
	 * Wurden w&auml;hrend der Laufzeit eine Lok entfernt oder hinzugef&uuml;gt, wird dies hier ber&uuml;cksichtigt.
	 * \param filename ist der Name und Pfad der Datei
	 */
	void WriteToFile(char* filename);
};

#endif /*__LOKLISTE_H*/
