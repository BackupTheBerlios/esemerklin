#ifndef __BENUTZERLISTE_H
#define __BENUTZERLISTE_H

#include "BenutzerKnoten.h"
#include "Benutzer.h"

/**
 * \brief Diese Klasse ist f&uuml;r die Organisation der verketteten Liste der Benutzer zust&auml;ndig.
 * 
 * Diese Klasse sollte eingebunden werden und eine Instanz davon erzeugt werden. Dar&uuml;ber kann man s&auml;mtliche Benutzer verwalten.
 * \author Daniel Pietzsch
 */
class BenutzerListe {
	protected:
	BenutzerKnoten* pStart;	/**< \brief der Startpunkt der Liste */
	BenutzerKnoten* pCursor;	/**< \brief Zeiger zum durch die Liste gehen */
	BenutzerKnoten* pGetCursor;	/**< \brief Zeiger zum durch die Liste gehen f&uuml;r die Ausgabe */
	unsigned short int anzahl;	/**< \brief Speichert die aktuelle Anzahl an Benutzer */
	unsigned short int max_anzahl;	/**< \brief Gibt die maximal erlaubte Anzahl an */
	
	public:
	/**
	 * Der Standardkonstruktor. Er setzt alle Variablen auf 0
	 */
	BenutzerListe();
	
	/**
	 * F&uuml;gt einen Benutzer der Liste hinzu, d.h. er ist somit eingeloggt. Es wird ein neuer Knoten definiert.
	 * \param pBenutzer ist ein Zeiger auf eine Instanz vom Typ Benutzer, welche vorher erzeugt werden musste.
	 * \return Liefert true, wenn der Benutzer eingef&uuml;gt wurde. Liefert false, wenn schon 10 Benutzer erfasst sind.
	 */
	bool InsertBenutzer(Benutzer* pBenutzer);
	
	/**
	 * L&ouml;scht eineb Benutzer aus der Liste und somit auch den entsprechenden Knoten. Der Benutzer ist somit ausgeloggt.
	 * \param nickname ist Benutzername, des Benutzers, der zu l&ouml;schen ist.
	 */
	void DeleteBenutzer(char* nickname);
	
	/**
	 * Liefert den n&auml;chsten Benutzer der Liste zur&uuml;ck. Sobald ein Benutzer gel&ouml;scht oder hinzugef&uuml;gt wurde, wird es wieder auf den ersten Benutzer gesetzt.
	 * \return Ein Zeiger auf ein Objekt vom Typ Benutzer.
	 */
	Benutzer* GetNextBenutzer();
	
	/**
	 * Pr&uuml;ft, ob der Benutzer bereits existiert in der Datei.
	 * \param filename ist der Name der Datei
	 * \param nickname ist der eindeutige Benutzername
	 * \return true, wenn der Benutzer existiert. false, wenn nicht.
	 */
	bool BenutzerExistsInFile(char* filename, char* nickname);
	
	/**
	 * F&uuml;gt einen Benutzer der Benutzerdatei hinzu. Allerdings nur, wenn der Benutzer noch nicht in der Datei existiert.
	 * Die Methode f&uuml;gt den Benutzer aber nicht der verketteten Liste hinzu, da das mit einem Einloggen gleichk&auml;me.
	 * \param filename ist der Name der Datei in die gespeichert werden soll
	 * \param nickname Der Benutzername
	 * \param password Das Passwort
	 * \param type ist der Benutzertyp
	 * \return liefert true, wenn der Benutzer erfolgreich in die Datei eingef&uuml;gt wurde. Ansonsten false.
	 */
	bool AddBenutzerToFile(char* filename, char* nickname, char* password, usertype type);
	
	/**
	 * Gleicht die &uuml;bergebenen Daten beim Login mit der Benutzerdatei ab, und bei einer &Uuml;bereinstimmung wird er eingeloggt = der verketteten Liste hinzugef&uuml;gt.
	 * \param filename ist der Name der Datei
	 * \param nickname Der Benutzername
	 * \param password Das Passwort
	 * \return liefert true, wenn der Benutzer erfolgreich eingeloggt wurde. Ansonsten false.
	 */
	bool LoginBenutzer(char* filename, char* nickname, char* password);
	
	/**
	 * L&ouml;scht einen Benutzer aus der Benutzerdatei.
	 * \param filename ist der Name der Datei
	 * \param tempfilename ist die Datei, in der die Daten zwischengespeichert werden. 
	 * \param nickname Der Benutzername
	 * \return Liefert true bei erfolreichem L&ouml;schvorgang. Ansonsten false.
	 */
	bool DeleteBenutzerFromFile(char* filename, char* tempfilename, char* nickname);
};

#endif /*__BENUTZERLISTE_H*/
