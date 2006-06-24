#include "Lok.h"


Lok::Lok() {
	address = '0';
	pLokBenutzer = 0;
}

Lok::Lok(char address) {
	this->address = address;
	pLokBenutzer = 0;	//auch hier wird die Adresse zunŠchst auf NULL gesetzt, da beim erstellen des Objektes noch nicht feststeht, welcher Benutzer die Lok steuern wird.
}

void Lok::SetAddress(char address) {
	this->address = address;
}

char Lok::GetAddress() {
	return address;
}

void Lok::SetBenutzer(Benutzer* pLokBenutzer) {
	this->pLokBenutzer = pLokBenutzer;
}

Benutzer* Lok::GetBenutzer() {
	return pLokBenutzer;
}