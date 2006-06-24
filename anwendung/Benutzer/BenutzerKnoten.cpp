#include "BenutzerKnoten.h"

BenutzerKnoten::BenutzerKnoten(Benutzer* pBenutzer) {
	this->pBenutzer = pBenutzer;
	pNext = 0;	
}

BenutzerKnoten::~BenutzerKnoten() {
	delete pBenutzer;
}

void BenutzerKnoten::SetNext(BenutzerKnoten* pNext) {
	this->pNext = pNext;
}

BenutzerKnoten* BenutzerKnoten::GetNext() {
	return pNext;
}

Benutzer* BenutzerKnoten::GetBenutzer() {
	return pBenutzer;
}