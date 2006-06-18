#ifndef __LOK_H
#define __LOK_H
#include "Benutzer.h"

/**
 * Die Klasse f&uuml;r eine Lok. Sie speichert alle relevanten Informationen zu einer Lok.
 * Da für eine Lok kein Prozessabbild benötigt wird, wird hier nur die Adresse und der zugreifende Benutzer (sofern vorhanden) gespeichert.
 * \author Daniel Pietzsch
 */
class Lok {
	//die gesch&uuml;tzen Attribute
	protected:
	
	char address;
	Benutzer* pLokBenutzer;	//ein Zeiger auf den Benutzer, der diese Lok steuert
	
	//die &ouml;ffentlichen Methoden
	public:
	
	/**
	 * Standardkonstruktor, der die Geschwindigkeit auf 0 setzt, die Richtung auf 1 (=geradeaus) und alle Extrafunktionen auf false (=aus). Außerdem vergibt er irgendeine Adresse
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
	
	void SetBenutzer(Benutzer* pLokBenutzer);
	
	Benutzer* GetBenutzer();
};

#endif /*__LOK_H*/
