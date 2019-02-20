#ifndef GEMINI_GRAPHICSCOMPONENT
#define GEMINI_GRAPHICSCOMPONENT

#include <iostream>

class GraphicsComponent
{
public:
	virtual ~GraphicsComponent() {};
	virtual void Render() = 0;
};


#endif // !GEMINI_GRAPHICSCOMPONENT

