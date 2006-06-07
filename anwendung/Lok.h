#ifndef __LOK_H
#define __LOK_H

/**
 * Die Klasse f&uuml;r eine Lok. Sie speichert alle relevanten Informationen zu einer Lok.
 * \author Daniel Pietzsch
 */
class Lok {
	//die gesch&uuml;tzen Attribute
	protected:
	
	int speed;
	bool xtrafunc[4];	//bis zu 4 Extrafunktionen werden unterst&uuml;tzt
	char address[1024];
	bool direction;	//F&uuml;r die Richtung der Lok. 1(true)=vorw&auml;rts, 0(false)=r&uuml;ckw&auml;rts
	
	//die &ouml;ffentlichen Methoden
	public:
	
	/**
	 * Standardkonstruktor, der die Geschwindigkeit auf 0 setzt, die Richtung auf 1 (=geradeaus) und alle Extrafunktionen auf false (=aus). Au§erdem vergibt er irgendeine Adresse
	 */
	Lok();
	
	/**
	 * Konstruktor, der s&auml;mtliche Attribute auf die &uuml;bergebenen Werte setzt
	 * \param speed erwartet einen Integerwert zwischen 0 und 15, der die Geschwindigkeit setzt.
	 * \param address erwartet einen String mit der Lokadresse
	 * \param direction erwartet true(1) f&uuml;r vorw&auml;rts oder false(0) f&uuml;r r&uuml;ckw&auml;rts
	 * \param xtrafunc erwartet einen Array von 4 Boolean Typen, welche die Extrafunktionen aktivieren (true) bzw. deaktivieren (false)
	 */
	Lok(int speed, char* address, bool direction, bool* xtrafunc);
	
	/**
	 * Setzt die aktuelle Geschwindigkeit auf den Wert, der mit speed &uuml;bergeben wurde
	 * \param speed ist ein Wert zwischen 0 und 15
	 */
	void SetSpeed(int speed);
	
	/**
	 * Liefert die aktuelle Geschwindigkeit der Lok
	 * \return Ein Integer-Wert, welcher die aktuelle Geschwindigkeit der Lok repr&auml;sentiert.
	 */
	int GetSpeed();
	
	/**
	 * Setzt die entsprechende Extrafunktion auf den anderen Wert. Funktioniert, wie ein Schalter: war die Funktion ausgeschaltet, wird sie eingeschaltet und umgekehrt.
	 * \param funcnr ist die entsprechende Nummer der Extrafunktion (Wert zwischen 0 und 3)
	 */
	void SetXtrafunc(int funcnr);	//funcnr ist nummer der Xtrafunktion (also 0-3)
	
	/**
	 * Gibt den Status der ausgew&auml;hlten Extrafunktion zur&uuml;ck
	 * \param funcnr ist die entsprechende Nummer der Extrafunktion (Wert zwischen 0 und 3)
	 */
	bool GetXtrafunc(int funcnr);
	
	/**
	 * Setzt die entsprechende Adresse f&uuml;r die Lok
	 * \param address ist die Adresse der Lok als String
	 */
	void SetAddress(char* address);
	
	/**
	 * Liefert die Adresse der Lok zur&uuml;ck.
	 * \return Die Adresse der Lok als String
	 */
	char* GetAddress();
	
	/**
	 * Switched die Richtung auf den entsprechenden Wert, d.h. war es vorher true ist es nach Aufruf der Funktion false und umgekehrt
	 */
	void SetDirection();
	
	/**
	 * Liefert die aktuelle Richtung der Lok zur&uuml;ck.
	 * \return true (1) f&uuml;r vorw&auml;rts oder false(0) f&uuml;r r&uuml;ckw&auml;rts
	 */
	bool GetDirection();
};

#endif /*__LOK_H*/
