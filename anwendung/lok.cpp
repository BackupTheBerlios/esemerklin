#include "Lok.h"
#include <String.h>


Lok::Lok() {
	speed = 0;
	for (int i=0; i<4; i++)
		xtrafunc[i] = false;	
	direction = 1;
	strcpy(address,"0x01");
}

Lok::Lok(int speed, char* address, bool direction, bool* xtrafunc) {
	this->speed = speed;
	strcpy(this->address, address);
	this->direction = direction;
	for (int i=0; i<4; i++)
		this->xtrafunc[i] = xtrafunc[i];
}

void Lok::SetSpeed(int speed) {
	this->speed = speed;	
}

int Lok::GetSpeed() {
	return speed;
}

void Lok::SetXtrafunc(int funcnr) {
	if (xtrafunc[funcnr])
		xtrafunc[funcnr] = false;
	else
		xtrafunc[funcnr] = true;		
}

bool Lok::GetXtrafunc(int funcnr) {
	return xtrafunc[funcnr];
}

void Lok::SetAddress(char* address) {
	strcpy(this->address, address);
}

char* Lok::GetAddress() {
	return address;
}

void Lok::SetDirection() {
	if (direction)
		direction = false;
	else
		direction = true;
}

bool Lok::GetDirection() {
	return direction;
}