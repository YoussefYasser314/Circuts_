#include "ActionAddLabel.h"
#include "ActionSelect.h"
#include "ApplicationManager.h"
#include "UI/UI.h"
#include <string>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif


ActionAddLabel::ActionAddLabel(ApplicationManager* pApp) :Action(pApp)
{}


ActionAddLabel::~ActionAddLabel(void)
{}

void ActionAddLabel::Execute()
{
	UI* pUI = pManager->GetUI();

	Component** complist = ApplicationManager().getcomplist();

	Component* comp = 0;

	for (int i = 0; i < ApplicationManager().getcompcount(); i++)
	{
		if (complist[i]->getactiontype() == ADD_RESISTOR || complist[i]->getactiontype() == ADD_SWITCH || complist[i]->getactiontype() == ADD_BATTERY || complist[i]->getactiontype() == ADD_LAMP || complist[i]->getactiontype() == ADD_GROUND || complist[i]->getactiontype() == ADD_FUSE || complist[i]->getactiontype() == ADD_BUZZER)
		{
			comp = complist[i];
			break;
		}
	}
	if (comp)
	{
		if (comp->classtype() == "Resistor")
		{
			pUI->PrintMsg("Add Label");
			Sleep(2000);
			pUI->ClearStatusBar();
			new_label = pUI->GetSrting();
			pUI->ClearStatusBar();
			pUI->PrintMsg("Add value");
			Sleep(2000);
			pUI->ClearStatusBar();
			new_value = std::stod(pUI->GetSrting());
			pUI->ClearStatusBar();
			comp->setlabel(new_label, new_value);
			comp->setactiontype(UNSELECT);

		}

		else if (comp->classtype() == "Battery")
		{
			pUI->PrintMsg("Add Label");
			Sleep(2000);
			pUI->ClearStatusBar();
			new_label = pUI->GetSrting();
			pUI->ClearStatusBar();
			pUI->PrintMsg("Add value");
			Sleep(2000);
			pUI->ClearStatusBar();
			new_value = std::stod(pUI->GetSrting());
			pUI->ClearStatusBar();
			comp->setlabel(new_label, new_value);
			comp->setactiontype(UNSELECT);

		}

		else if (comp->classtype() == "Lamp")
		{
			pUI->PrintMsg("Add Label");
			Sleep(2000);
			pUI->ClearStatusBar();
			new_label = pUI->GetSrting();
			pUI->ClearStatusBar();
			pUI->PrintMsg("Add value");
			Sleep(2000);
			pUI->ClearStatusBar();
			new_value = std::stod(pUI->GetSrting());
			pUI->ClearStatusBar();
			comp->setlabel(new_label, new_value);
			comp->setactiontype(UNSELECT);

		}

		else if (comp->classtype() == "Switch")
		{
			pUI->PrintMsg("Add Label");
			Sleep(2000);
			pUI->ClearStatusBar();
			new_label = pUI->GetSrting();
			pUI->ClearStatusBar();
			comp->setlabel(new_label, 0);
			comp->setactiontype(UNSELECT);

		}

		else if (comp->classtype() == "Ground")
		{
			pUI->PrintMsg("Add Label");
			Sleep(2000);
			pUI->ClearStatusBar();
			new_label = pUI->GetSrting();
			pUI->ClearStatusBar();
			comp->setlabel(new_label, 0);
			comp->setactiontype(UNSELECT);

		}
		else if (comp->classtype() == "Buzzer")
		{
			pUI->PrintMsg("Add Label");
			Sleep(2000);
			pUI->ClearStatusBar();
			new_label = pUI->GetSrting();
			pUI->ClearStatusBar();
			pUI->PrintMsg("Add value");
			Sleep(2000);
			pUI->ClearStatusBar();
			new_value = std::stod(pUI->GetSrting());
			pUI->ClearStatusBar();
			comp->setlabel(new_label, new_value);
			comp->setactiontype(UNSELECT);

		}
		else if (comp->classtype() == "Fuse")
		{
			pUI->PrintMsg("Add Label");
			Sleep(2000);
			pUI->ClearStatusBar();
			new_label = pUI->GetSrting();
			pUI->ClearStatusBar();
			pUI->PrintMsg("Add value");
			Sleep(2000);
			pUI->ClearStatusBar();
			new_value = std::stod(pUI->GetSrting());
			pUI->ClearStatusBar();
			comp->setlabel(new_label, new_value);
			comp->setactiontype(UNSELECT);

		}
	}	

}

void ActionAddLabel::Undo()
{}

void ActionAddLabel::Redo()
{}