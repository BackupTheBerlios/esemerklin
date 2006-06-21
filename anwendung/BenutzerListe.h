#ifndef __BENUTZERLISTE_H
#define __BENUTZERLISTE_H

#include "BenutzerKnoten.h"
#include "Benutzer.h"

/**
 * Diese Klasse ist f&uuml;r die Organisation der verketteten Liste der Benutzer zust&auml;ndig.
 */
class BenutzerListe {
	protected:
	BenutzerKnoten* pStart;	//der Startpunkt der Liste
	BenutzerKnoten* pCursor;	//Zeiger zum durch die Liste gehen
	BenutzerKnoten* pGetCursor;	//Zeiger zum durch die Liste gehen f&uuml;r die Ausgabe
	unsigned short int anzahl;	//Speichert die aktuelle Anzahl an Benutzer
	static const unsigned short int max_anzahl = 10;	//Gibt die maximal erlaubte Anzahl an
	
	public:
	/**
	 * Der Standardkonstruktor. Er setzt alle Variablen auf 0
	 */
	BenutzerListe();
	
	/**
	 * F&uuml;gt einen Benutzer der Liste hinzu. Es wird ein neuer Knoten definiert.
	 * \param pBenutzer ist ein Zeiger auf eine Instanz vom Typ Benutzer, welche vorher erzeugt werden musste.
	 * \return Liefert true, wenn der Benutzer eingef&uuml;gt wurde. Liefert false, wenn schon 10 Benutzer erfasst sind.
	 */
	bool InsertBenutzer(Benutzer* pBenutzer);
	
	/**
	 * L&ouml;scht eineb Benutzer aus der Liste und somit auch den entsprechenden Knoten.
	 * \param nickname ist Benutzername, des Benutzers, der zu l&ouml;schen ist.
	 */
	void DeleteBenutzer(char* nickname);
	
	/**
	 * Liefert den n&auml;chsten Benutzer der Liste zur&uuml;ck. Sobald ein Benutzer gel&ouml;scht oder hinzugef&uuml;gt wurde, wird es wieder auf den ersten Benutzer gesetzt.
	 * \return Ein Zeiger auf ein Objekt vom Typ Benutzer.
	 */
	Benutzer* GetNextBenutzer();
	
	/**
	 * F&uuml;gt einen Benutzer der Benutzerdatei hinzu. Aber nicht der verketteten Liste, da das mit einem Einloggen gleichk&auml;me.
	 * \param filename ist der Name der Datei in die gespeichert werden soll
	 * \param nickname Der Benutzername
	 * \param password Das Passwort
	 * \param type ist der Benutzertyp
	 * \return liefert true, wenn der Benutzer erfolgreich in die Datei eingef&uuml;gt wurde. Ansonsten false.
	 */
	bool AddBenutzerToFile(char* filename, char* nickname, char* password, usertype type);
	
	/**
	 * Gleicht die &uuml;bergebenen Daten beim Login mit der Benutzerdatei ab, und bei einer &Uuml;bereinstimmung wird er eingeloggt = der Liste hinzugef&uuml;gt.
	 * \param filename ist der Name der Datei
	 * \param nickname Der Benutzername
	 * \param password Das Passwort
	 * \return liefert true, wenn der Benutzer erfolgreich eingeloggt wurde. Ansonsten false.
	 */
	bool LoginBenutzer(char* filename, char* nickname, char* password);
	
	/**
	 * L&ouml;scht einen Benutzer aus der Benutzerdatei.
	 * \param filename ist der Name der Datei
	 * \param nickname Der Benutzername
	 * \return Liefert true bei erfolreichem L&ouml;schvorgang. Ansonsten false.
	 */
	bool DeleteBenutzerFromFile(char* filename, char* nickname);
};

#endif /*__BENUTZERLISTE_H*/
