#include "ActionDelete.h"
#include "ApplicationManager.h"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

ActionDelete::ActionDelete(ApplicationManager* pApp) :Action(pApp) {}

ActionDelete::~ActionDelete(void) {}

void ActionDelete::Execute()
{
	UI* pUI = pManager->GetUI();

	Component** complist = ApplicationManager().getcomplist();

	GraphicsInfo* pGInfo = new GraphicsInfo(2);

	Component* comp = 0;

	int x1, y1, x2, y2;

	
	int c = 0;
	for (int i = 0; i < ApplicationManager().getcompcount(); i++)
	{
		if (complist[i]->getactiontype() == SELECT)
		{
			c++;
		}
	}
	if (c != 0)
	{
		pUI->PrintMsg("Are you sure you want to permenantly delete all selected objects? <yes/no>");

		Sleep(2000);

		pUI->ClearStatusBar();
		string user_confirmation = UI().GetSrting();

		while ((user_confirmation != "yes") && (user_confirmation != "no"))
		{
			pUI->PrintMsg("Enter a valid answer! <yes/no>");

			Sleep(2000);

			pUI->ClearStatusBar();
			user_confirmation = UI().GetSrting();
		}

		if (user_confirmation == "yes")
		{
			int max = ApplicationManager().getcompcount();
			int i = 0;
			while(i != max)
			{
					if (complist[i]->getactiontype() == SELECT)
					{
						ApplicationManager().delete_component(complist[i]);
						i = -1;
					}
					i++;
					max = ApplicationManager().getcompcount();
			}
		}
	}
	else
	{
		pUI->PrintMsg("You need to select a component first before deleting it.");

		Sleep(2000);

		pUI->ClearStatusBar();
	}
}

void ActionDelete::Undo()
{}

void ActionDelete::Redo()
{}
