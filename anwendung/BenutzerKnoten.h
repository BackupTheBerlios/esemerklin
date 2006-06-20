#ifndef __BENUTZERKNOTEN_H
#define __BENUTZERKNOTEN_H

#include "Benutzer.h"

/**
 * Die Klasse BenutzerKnoten ist Teile der verketteten Liste BenutzerListe.
 * Diese Klasse ist ein Knoten in der Liste.
 * \author Daniel Pietzsch
 */
class BenutzerKnoten {
	protected:
	Benutzer* pBenutzer;	//Ein Zeiger auf den Benutzer, die in diesem Knoten gespeichert ist.
	BenutzerKnoten* pNext;	//Ein Zeiger auf das n&auml;chste Objekt in der Liste
	
	public:
	/**
	 * Ein Konstruktor, welcher direkt ein Zeiger auf den zu speichernden Benutzer &uuml;bernimmt. Der pNext-Zeiger wird zun&auml;chst auf 0 gesetzt, da neue Elemente stets hinten angef&uuml;gt werden, und der neue Knoten immer der letzte ist.
	 * \param pBenutzer ist ein Zeiger auf eine Instanz vom Typ Benutzer
	 */
	BenutzerKnoten(Benutzer* pBenutzer);
	
	/**
	 * Der Destruktor, welcher den Speicher des Benutzers wieder freigibt
	 */
	~BenutzerKnoten();
	
	/**
	 * Legt die Adresse des n&auml;chsten Elementes fest.
	 * \param pNext ist ein Zeiger auf eine Instanz vom Typ BenutzerKnoten.
	 */
	void SetNext(BenutzerKnoten* pNext);
	
	/**
	 * Gibt die Adresse des n&auml;chsten Knotens in der Liste zur&uuml;ck.
	 * \return Zeiger auf ein BenutzerKnoten-Objekt.
	 */
	BenutzerKnoten* GetNext();
	
	/**
	 * Gibt den Benutzer dieses Knotens zur&uuml;ck bzw. deren Adresse
	 * \return Die Adresse des Benutzers in diesem Knoten
	 */
	Benutzer* GetBenutzer();
};

#endif /*__BENUTZERKNOTEN_H*/
