#ifndef __LOKKNOTEN_H
#define __LOKKNOTEN_H

#include "Lok.h"

/**
 * Die Klasse LokKnoten ist Teile der verketteten Liste LokListe.
 * Diese Klasse ist ein Knoten in der Liste.
 * \author Daniel Pietzsch
 */
class LokKnoten {
	protected:
	Lok* lok;	//Ein Zeiger auf die Lok, die in diesem Knoten gespeichert ist.
	LokKnoten* next;	//Ein Zeiger auf das n&auml;chste Objekt in der Liste
	
	public:
	/**
	 * Ein Konstruktor, welcher direkt ein Zeiger auf die zu speichernde Lok &uuml;bernimmt. Der next-Zeiger wird zun&auml;chst auf 0 gesetzt, da neue Elemente stets hinten angef&uuml;gt werden, und der neue Knoten immer der letzte ist.
	 * \param lok ist ein Zeiger auf eine Instanz vom Typ Lok
	 */
	LokKnoten(Lok* lok);
	
	/**
	 * Der Destruktor, welcher den Speicher der Lok wieder freigibt
	 */
	~LokKnoten();
	
	/**
	 * Legt die Adresse des n&auml;chsten Elementes fest.
	 * \param next ist ein Zeiger auf eine Instanz vom Typ LokKnoten.
	 */
	void SetNext(LokKnoten* next);
	
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
