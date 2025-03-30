#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "UI\UI.h"
#include "Actions\Action.h"
#include "Components\Component.h"

class ApplicationManager
{
	enum { MaxCompCount = 200 };	
private:
	UI* pUI;
	//TODO convert the scope to static
	static int CompCount;
	static int ConnCount;
	static Component* CompList[MaxCompCount];
	static Connection* ConnList[200];
	//TODO add
	ActionType ActType;

public:
	//TODO add them
	int getcompcount();
	Component** getcomplist();
	int GetConnCount();
	Connection** GetConnList();
	void delete_component(Component*);

public:	
	ApplicationManager();

	ActionType GetUserAction();
	
	void ExecuteAction(ActionType);

	void UpdateInterface();	
	
	UI* GetUI();
	
	void AddComponent(Component* pComp);
	void AddConnection(Connection* pConn);
	//TODO add them
	ActionType getactiontype();
	void setactiontype(ActionType);

	
	~ApplicationManager();
};



#endif