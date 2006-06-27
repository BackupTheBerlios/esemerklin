#ifndef __BENUTZER_H
#define __BENUTZER_H

/**
 * \enum Aufz&auml;hlung f&uuml;r den Benutzertyp. 0=beobachter bis 3=Admin
 */
enum usertype {
	beobachter,		/**< \brief =0, niedrigste Berechtigung, sieht nur das Prozessabbild */
	weichensteller,	/**< \brief =1, darf Weichen stellen */
	lokfuehrer,		/**< \brief =2, darf zusŠtzlich noch Loks steuern */
	admin			/**< \brief =3, hšchste Berechtigung, darf zusŠtzlich noch Weichen, Loks und Benutzer verwalten */
};

/**
 * \brief Die Klasse f&uuml;r einen Benutzer. Sie speichert alle relevanten Informationen zu einem Benutzer.
 * 
 * Die Klasse kann eingebunden werden, wenn man direkt in der Anwendung z.B. einen Zeiger auf einen bestimmten Benutzer haben m&ouml;chte.
 * Ansonsten kann eigentlich jeden Benutzer Ÿber die Klasse BenutzerListe ermittelt werden.
 * \author Daniel Pietzsch
 */ 
class Benutzer {
	protected:
	char nickname[20];	/**< \brief Der eindeutige Benutzername. Max. 20 Zeichen */
	char password[20];	/**< \brief Das Passwort des Benutzers. Max. 20 Zeichen */
	usertype type;		/**< \brief Der Benutzertyp. */
	
	public:
	//Benutzer();
	
	/**
	 * Der Konstruktor. Er setzt s&auml;mtliche Attribute eines Benutzers auf die &uuml;bergebenen Werte.
	 * \param nickname erwartet einen String und setzt den Benutzernamen
	 * \param password erwartet einen String und legt das Passwort fest
	 * \param type erwartet einen Integer zwischen 0 und 3 bzw. "beobachter", "weichensteller", "lokfuehrer" oder "admin".
	 */
	Benutzer(char* nickname, char* password, usertype type);
	
	/**
	 * &auml;ndert den Nickname (Benutzername).
	 * \param nickname erwartet einen String.
	 */
	void SetNickname(char* nickname);
	
	/**
	 * Gibt den Benutzernamen zur&uuml;ck.
	 * \return Es wird ein String zur&uuml;ck gegeben.
	 */
	char* GetNickname();
	
	/**
	 * &auml;ndert das Passwort des Benutzers auf den &uuml;bergebenen Wert.
	 * \param password erwartet einen String
	 */
	void SetPassword(char* password);
	
	/**
	 * Liefert das Passwort des Benutzers zur&uuml;ck.
	 * \return Es wird ein String zur&uuml;ckgegeben
	 */
	char* GetPassword();
	
	/**
	 * Setzt den Benutzertyp auf den &uuml;bergebenen Wert.
	 * \param type erwartet einen Integer zwischen 0 und 3 bzw. "beobachter", "weichensteller", "lokfuehrer" oder "admin".
	 */
	void SetType(usertype type);
	
	/**
	 * Liefert den aktuellen Benutzertypen zur&uuml;ck
	 * \return Es wird ein Integerwert zwischen 0 und 3 zur&uuml;ckgegeben, wobei 0 die niedrigste und 3 die h&ouml;chste Berechtigungsstufe ist.
	 */
	int GetType();
};

#endif /*__BENUTZER_H*/