#include "LokKnoten.h"

LokKnoten::LokKnoten(Lok* pLok) {
	this->pLok = pLok;
	pNext = 0;	
}

LokKnoten::~LokKnoten() {
	delete pLok;
}

void LokKnoten::SetNext(LokKnoten* pNext) {
	this->pNext = pNext;
}

LokKnoten* LokKnoten::GetNext() {
	return pNext;
}

Lok* LokKnoten::GetLok() {
	return pLok;
}