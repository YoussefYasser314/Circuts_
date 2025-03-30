#pragma once
#include <iostream>
#include "Actions/Action.h"
#include "Components/Resistor.h"

class ActionDelete: public Action
{
private:
	int Cx, Cy;
	int x1, y1, x2, y2;
public:
	ActionDelete(ApplicationManager* pApp);
	virtual ~ActionDelete(void);
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};

