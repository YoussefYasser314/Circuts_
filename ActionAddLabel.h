#pragma once
#include <iostream>
#include "Actions/Action.h"
#include "Components/Component.h"

class ActionAddLabel : public Action
{
private:
	string new_label;
	double new_value;
	int Cx, Cy;
	int x1, y1, x2, y2;
public:
	ActionAddLabel(ApplicationManager* pApp);
	virtual ~ActionAddLabel(void);
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};

