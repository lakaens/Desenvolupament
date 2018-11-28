#ifndef _j1Element_H_
#define	_j1Element_H_


#include"j1Module.h"
#include"p2Point.h"
#include"j1Gui.h"
struct SDL_Texture;

struct ElementStruct {
	SDL_Texture* texture;
	iPoint position;
	p2SString name;
	
};
class j1Element {
public:
	j1Element(GUiType type, ElementStruct* elements);
	~j1Element();

private:
	ElementStruct elements;
};

#endif // !_j1Element_H_
