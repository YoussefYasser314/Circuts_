#include "ActionExit.h"
#include "ApplicationManager.h"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

ActionExit::ActionExit(ApplicationManager* pApp):Action(pApp) {}

ActionExit::~ActionExit(void){}

void ActionExit::Execute()
{
	UI* pUI = pManager->GetUI();
	pUI->PrintMsg("Exiting the simulator...");
	Sleep(2000);
	pUI->ClearDrawingArea();
	Sleep(2000);
	pUI->ClearStatusBar();
	Sleep(1000);
}

void ActionExit::Undo(){}

void ActionExit::Redo(){}

