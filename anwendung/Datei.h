#ifndef __DATEI_H
#define __DATEI_H
#include <fstream.h>

abstract class Datei {
	
	protected:
	char name[60];
	ofstream filewrite;
	ifstream fileread;
	
	public:
	
	abstract Datei();
	abstract ~Datei();
	
	abstract void SetName(char* name);
	abstract char* GetName();
	
	abstract void ReadFile(char* lines[]);
	abstract void WriteFile(char* lines[]);
};
#endif /*__DATEI_H*/
