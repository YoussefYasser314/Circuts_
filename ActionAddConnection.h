#pragma once
#include "Actions/Action.h"
#include "Components/Connection.h"

class ActionAddConnection : public Action
{

public:
	ActionAddConnection(ApplicationManager* pApp);
	virtual ~ActionAddConnection(void);
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};

