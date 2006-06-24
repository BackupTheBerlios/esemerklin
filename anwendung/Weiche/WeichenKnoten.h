#ifndef __WEICHENKNOTEN_H
#define __WEICHENKNOTEN_H

#include "Weiche.h"

/**
 * \brief Die Klasse WeichenKnoten ist ein Knoten, welcher Daten einer Weiche enth&auml;lt, der verketteten Liste WeichenListe.
 * \author Daniel Pietzsch
 */
class WeichenKnoten {
	protected:
	Weiche* pWeiche;	//Ein Zeiger auf die Weiche, die in diesem Knoten gespeichert ist.
	WeichenKnoten* pNext;	//Ein Zeiger auf das n&auml;chste Objekt in der Liste
	
	public:
	/**
	 * Ein Konstruktor, welcher direkt ein Zeiger auf die zu speichernde Weiche &uuml;bernimmt. Der pNext-Zeiger wird zun&auml;chst auf 0 gesetzt, da neue Elemente stets hinten angef&uuml;gt werden, und der neue Knoten immer der letzte ist.
	 * \param pWeiche ist ein Zeiger auf eine Instanz vom Typ Weiche
	 */
	WeichenKnoten(Weiche* pWeiche);
	
	/**
	 * Der Destruktor, welcher den Speicher der Weiche wieder freigibt
	 */
	~WeichenKnoten();
	
	/**
	 * Legt die Adresse des n&auml;chsten Elementes fest.
	 * \param pNext ist ein Zeiger auf eine Instanz vom Typ WeichenKnoten.
	 */
	void SetNext(WeichenKnoten* pNext);
	
	/**
	 * Gibt die Adresse des n&auml;chsten Knotens in der Liste zur&uuml;ck.
	 * \return Zeiger auf ein WeichenKnoten-Objekt.
	 */
	WeichenKnoten* GetNext();
	
	/**
	 * Gibt die Weiche dieses Knotens zur&uuml;ck bzw. deren Adresse (->Pointer)
	 * \return Einen Pointer auf die Weiche in diesem Knoten
	 */
	Weiche* GetWeiche();
};

#endif /*__WEICHENKNOTEN_H*/
