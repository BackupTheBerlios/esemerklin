#include "WeichenKnoten.h"

WeichenKnoten::WeichenKnoten(Weiche* pWeiche) {
	this->pWeiche = pWeiche;
	pNext = 0;	
}

WeichenKnoten::~WeichenKnoten() {
	delete pWeiche;
}

void WeichenKnoten::SetNext(WeichenKnoten* pNext) {
	this->pNext = pNext;
}

WeichenKnoten* WeichenKnoten::GetNext() {
	return pNext;
}

Weiche* WeichenKnoten::GetWeiche() {
	return pWeiche;
}