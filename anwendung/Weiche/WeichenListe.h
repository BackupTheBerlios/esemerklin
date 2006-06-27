#ifndef __WEICHENLISTE_H
#define __WEICHENLISTE_H

#include "WeichenKnoten.h"
#include "Weiche.h"

/**
 * \brief Diese Klasse ist f&uuml;r die Organisation der verketteten Liste der Weichen zust&auml;ndig.
 * 
 * Diese Klasse sollte eingebunden werden und eine Instanz davon erzeugt werden. Dar&uuml;ber kann man s&auml;mtliche Weichen verwalten.
 * Am Anfang, sollte immer die Funktion FillFromFile ausgef&uuml;hrt werden.
 * Am Ende muss/sollte immer die Funktion WriteToFile ausgef&uuml;hrt werden
 * \author Daniel Pietzsch
 */
class WeichenListe {
	protected:
	WeichenKnoten* pStart;	/**< \brief der Startpunkt der Liste */
	WeichenKnoten* pCursor;	/**< \brief Zeiger zum durch die Liste gehen */
	WeichenKnoten* pGetCursor;	/**< \brief Zeiger zum durch die Liste gehen f&uuml;r die Ausgabe */
	unsigned short int anzahl;	/**< \brief Speichert die aktuelle Anzahl an Weichen */
	unsigned short int max_anzahl;	/**< \brief Gibt die maximal erlaubte Anzahl an */
	
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
	 * Baut ein Liste auf und f&uuml;llt diese mit entsprechenden Werte aus einer Datei.
	 * \param filename ist der Name und Pfad der Datei
	 */
	void FillFromFile(char* filename);
	
	/**
	 * Schreibt die aktuelle Liste komplett in eine Datei und &uuml;berschreibt dabei die bestehende Datei.
	 * Wurden w&auml;hrend der Laufzeit eine Weiche entfernt oder hinzugef&uuml;gt, wird dies hier ber&uuml;cksichtigt.
	 * \param filename ist der Name und Pfad der Datei
	 */
	void WriteToFile(char* filename);
};

#endif /*__WEICHENLISTE_H*/
