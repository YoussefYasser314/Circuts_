#include "ActionLabel.h"
#include "ActionSelect.h"
#include "ApplicationManager.h"
#include "UI/UI.h"
#include <string>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

ActionLabel::ActionLabel(ApplicationManager* pApp) :Action(pApp)
{}


ActionLabel::~ActionLabel(void)
{}

void ActionLabel::Execute()
{
	UI* pUI = pManager->GetUI();

	Component** complist = ApplicationManager().getcomplist();

	Component* comp = 0;

	pUI->PrintMsg(" Edit Label : Click on a component to edit its label. ");

	pUI->GetPointClicked(Cx, Cy);

	pUI->ClearStatusBar();

	GraphicsInfo* pGInfo = new GraphicsInfo(2);

	int x1, y1, x2, y2;

	for (int i = 0; i < ApplicationManager().getcompcount(); i++)
	{
		x1 = complist[i]->m_pGfxInfo->PointsList[0].x;
		y1 = complist[i]->m_pGfxInfo->PointsList[0].y;
		x2 = complist[i]->m_pGfxInfo->PointsList[1].x;
		y2 = complist[i]->m_pGfxInfo->PointsList[1].y;

		if (Cx >= x1 && Cx <= x2 && Cy >= y1 && Cy <= y2)
		{
			comp = complist[i];
			break;
		}
	}
	if (comp != 0)
	{
		if (comp->getactiontype() == SELECT)
		{
			if (comp->classtype() == "Resistor")
			{

				pUI->ClearStatusBar();
				new_label = pUI->GetSrting();
				pUI->ClearStatusBar();
				pUI->PrintMsg("Edit value");
				Sleep(2000);
				pUI->ClearStatusBar();
				new_value = std::stod(pUI->GetSrting());
				pUI->ClearStatusBar();
				comp->setlabel(new_label, new_value);

			}

			else if (comp->classtype() == "Battery")
			{
				pUI->ClearStatusBar();
				new_label = pUI->GetSrting();
				pUI->ClearStatusBar();
				pUI->PrintMsg("Edit value");
				Sleep(2000);
				pUI->ClearStatusBar();
				new_value = std::stod(pUI->GetSrting());
				pUI->ClearStatusBar();
				comp->setlabel(new_label, new_value);

			}

			else if (comp->classtype() == "Lamp")
			{
				pUI->ClearStatusBar();
				new_label = pUI->GetSrting();
				pUI->ClearStatusBar();
				pUI->PrintMsg("Edit value");
				Sleep(2000);
				pUI->ClearStatusBar();
				new_value = std::stod(pUI->GetSrting());
				pUI->ClearStatusBar();
				comp->setlabel(new_label, new_value);
			}

			else if (comp->classtype() == "Switch")
			{

				pUI->ClearStatusBar();
				new_label = pUI->GetSrting();
				pUI->ClearStatusBar();
				comp->setlabel(new_label, 0);

			}

			else if (comp->classtype() == "Ground")
			{
				pUI->ClearStatusBar();
				new_label = pUI->GetSrting();
				pUI->ClearStatusBar();
				comp->setlabel(new_label, 0);
			}
		}
		else
		{
			pUI->PrintMsg("Component must be selected before labeling! ");
			Sleep(2000);
			pUI->ClearStatusBar();
		}
	}
}

void ActionLabel::Undo()
{}

void ActionLabel::Redo()
{}
