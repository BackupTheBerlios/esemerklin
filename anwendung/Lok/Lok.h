#ifndef __LOK_H
#define __LOK_H
#include "../Benutzer/Benutzer.h"

/**
 * \brief Die Klasse f&uuml;r eine Lok. Sie speichert alle relevanten Informationen zu einer Lok.
 * Da f&uuml;r eine Lok kein Prozessabbild ben&ouml;tigt wird, wird hier nur die Adresse und der zugreifende Benutzer (sofern vorhanden) gespeichert.
 * \author Daniel Pietzsch
 */
class Lok {
	protected:
	
	char address;	//Speichert die Adresse der Lok
	Benutzer* pLokBenutzer;	//ein Zeiger auf den Benutzer, der diese Lok steuert
	
	public:
	
	/**
	 * Standardkonstruktor, der die Geschwindigkeit auf 0 setzt, die Richtung auf 1 (=geradeaus) und alle Extrafunktionen auf false (=aus). Au§erdem vergibt er irgendeine Adresse
	 */
	Lok();
	
	/**
	 * Konstruktor, der s&auml;mtliche Attribute auf die &uuml;bergebenen Werte setzt
	 * \param address erwartet einen char und setzt die Adresse der Lok
	 */
	Lok(char address);
	
	/**
	 * Setzt die entsprechende Adresse f&uuml;r die Lok
	 * \param address ist die Adresse der Lok als String
	 */
	void SetAddress(char address);
	
	/**
	 * Liefert die Adresse der Lok zur&uuml;ck.
	 * \return Die Adresse der Lok als Zeichen
	 */
	char GetAddress();
	
	/**
	 * Legt den Benutzer fest, der diese Lok steuert. Wichtig, um den exklusiven Zugriff zu realisieren.
	 * \param pLokBenutzer ist ein Zeiger auf eine Instanz vom Typ Benutzer
	 */
	void SetBenutzer(Benutzer* pLokBenutzer);
	
	/**
	 * Gibt die Adresse des Benutzers zur&uuml;ck, der diese Lok steuert
	 * \return Zeiger auf einen Benutzer
	 */
	Benutzer* GetBenutzer();
};

#endif /*__LOK_H*/
