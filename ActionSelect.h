#pragma once
#include <iostream>
#include "Actions/Action.h"
#include "Components/Resistor.h"

class ActionSelect : public Action
{
private:
	int Cx, Cy;
	int x1, y1, x2, y2;
public:
	ActionSelect(ApplicationManager* pApp);
	virtual ~ActionSelect(void);
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};

