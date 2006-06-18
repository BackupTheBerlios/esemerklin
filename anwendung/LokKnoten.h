#ifndef __LOKKNOTEN_H
#define __LOKKNOTEN_H

#include "Lok.h"

class LokKnoten {
	protected:
	Lok* lok;
	LokKnoten* next;
	
	public:
	LokKnoten(Lok* lok);
	~LokKnoten();
	
	void SetNext(LokKnoten* next);
	LokKnoten* GetNext();
	
	Lok* GetLok();
};

#endif /*__LOKKNOTEN_H*/
