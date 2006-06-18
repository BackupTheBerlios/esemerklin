#include "Benutzer.h"
#include <String.h>


Benutzer::Benutzer(int id, char* nickname, char* password, usertype type) {
	this->id = id;
	strcpy(this->nickname, nickname);
	strcpy(this->password, password);
	this->type = type;
}

void Benutzer::SetId(int id) {
	this->id = id;
}

int Benutzer::GetId() {
	return id;
}

void Benutzer::SetNickname(char* nickname) {
	strcpy(this->nickname, nickname);
}

char* Benutzer::GetNickname() {
	return nickname;
}

void Benutzer::SetPassword(char* password) {
	strcpy(this->password, password);
}

char* Benutzer::GetPassword() {
	return password;
}

void Benutzer::SetType(usertype type) {
	this->type = type;
}
	
int Benutzer::GetType() {
	return type;
}