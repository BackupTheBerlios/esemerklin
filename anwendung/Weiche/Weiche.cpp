#include "Weiche.h"
//#include <String.h>

Weiche::Weiche() {
	status = geradeaus;
	this->address = 0;
}

Weiche::Weiche(bool status, char address) {
	this->status = status;
	this->address = address;
}

void Weiche::SetStatus() {
	if (status == kurve)
		status = geradeaus;
	else
		status = kurve;
}

bool Weiche::GetStatus() {
	return status;
}

void Weiche::SetAddress(char address) {
	this->address = address;
}

char Weiche::GetAddress() {
	return address;
}