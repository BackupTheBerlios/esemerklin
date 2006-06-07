#include "Weiche.h"
#include <String.h>

Weiche::Weiche() {
	status = false;	//geradeaus
	strcpy(this->address, "0001");
}

Weiche::Weiche(bool status, char* address) {
	this->status = status;
	strcpy(this->address, address);
}

void Weiche::SetStatus() {
	if (status)
		status = false;
	else
		status = true;
}

bool Weiche::GetStatus() {
	return status;
}

void Weiche::SetAddress(char* address) {
	strcpy(this->address, address);
}

char* Weiche::GetAddress() {
	return address;
}