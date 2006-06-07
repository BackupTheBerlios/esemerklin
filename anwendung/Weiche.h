#ifndef __WEICHE_H
#define __WEICHE_H

/**
 * Die Klasse f&uuml;r eine Weiche. Sie speichert alle relevanten Informationen zu einer Weiche.
 * \author Daniel Pietzsch
 */
class Weiche {
	//die gesch&uuml;tzen Attribute
	protected:
	bool status;	//der status der Weiche. false(0) = geradeaus, true(1) = kurve
	char address[1024];	//die Adresse der Weiche
	
	//die &ouml;ffentlichen Methoden
	public:
	
	/**
	 * Der Standardkonstruktor. Er setzt den status auf false(0), was geradeaus bedeutet und vergibt eine Adresse
	 */
	Weiche();
	
	/**
	 * Konstruktor, der s&auml;mtliche Attribute der Klasse auf die &uuml;bergebenen Werte setzt.
	 * \param status erwartet einen Boolean-Wert. false(0) steht f&uuml;r geradeaus und true(1) f&uuml;r Kurve
	 * \param address erwartet einen String, welche die Adresse der Weiche repr&auml;sentiert
	 */
	Weiche(bool status, char* address);
	
	/**
	 * Switched den Status der Weiche. War sie geradeaus gestellt, steht sie nach Aufruf der Funktion auf Kurve und umgekehrt.
	 */
	void SetStatus();
	
	/**
	 * Gibt den aktuellen Status der Weiche zur&uuml;ck
	 * \return Gibt einen Boolean-Wert zur&uuml;ck, der entweder eine Geradeausstellung (false od. 0) oder eine Kurvenstellung (true od. 1) repr&auml;sentiert
	 */
	bool GetStatus();
	
	/**
	 * Setzt die Adresse der Weiche auf den &uuml;bergebenen Wert.
	 * \param address ist ein String
	 */
	void SetAddress(char* address);
	
	/**
	 * Liefert die aktuelle Adresse der Weiche zur&uuml;ck.
	 * \return Es wird ein String zur&uuml;ckgegeben
	 */
	char* GetAddress();
};

#endif /*__WEICHE_H*/