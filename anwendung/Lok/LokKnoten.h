#ifndef __LOKKNOTEN_H
#define __LOKKNOTEN_H

#include "Lok.h"

/**
 * \brief Die Klasse LokKnoten ist ein Knotenpunkt, welcher Daten zu einer Lok enth&auml;lt, der verketteten Liste LokListe.
 * \author Daniel Pietzsch
 */
class LokKnoten {
	protected:
	Lok* pLok;	/**< \brief Ein Zeiger auf die Lok, die in diesem Knoten gespeichert ist. */
	LokKnoten* pNext;	/**< \brief Ein Zeiger auf das n&auml;chste Objekt in der Liste. */
	
	public:
	/**
	 * Ein Konstruktor, welcher direkt ein Zeiger auf die zu speichernde Lok &uuml;bernimmt. Der pNext-Zeiger wird zun&auml;chst auf 0 gesetzt, da neue Elemente stets hinten angef&uuml;gt werden, und der neue Knoten immer der letzte ist.
	 * \param pLok ist ein Zeiger auf eine Instanz vom Typ Lok
	 */
	LokKnoten(Lok* pLok);
	
	/**
	 * Der Destruktor, welcher den Speicher der Lok wieder freigibt
	 */
	~LokKnoten();
	
	/**
	 * Legt die Adresse des n&auml;chsten Elementes fest.
	 * \param pNext ist ein Zeiger auf eine Instanz vom Typ LokKnoten.
	 */
	void SetNext(LokKnoten* pNext);
	
	/**
	 * Gibt die Adresse des n&auml;chsten Knotens in der Liste zur&uuml;ck.
	 * \return Zeiger auf ein LokKnoten-Objekt.
	 */
	LokKnoten* GetNext();
	
	/**
	 * Gibt die Lok dieses Knotens zur&uuml;ck bzw. deren Adresse
	 * \return Die Adresse der Lok in diesem Knoten
	 */
	Lok* GetLok();
};

#endif /*__LOKKNOTEN_H*/
