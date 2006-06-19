#include "LokKnoten.h"

LokKnoten::LokKnoten(Lok* lok) {
	this->lok = lok;
	next = 0;	
}

LokKnoten::~LokKnoten() {
	delete lok;
}

void LokKnoten::SetNext(LokKnoten* next) {
	this->next = next;
}

LokKnoten* LokKnoten::GetNext() {
	return next;
}

Lok* LokKnoten::GetLok() {
	return lok;
}