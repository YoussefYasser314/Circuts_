#include "ActionSelect.h"
#include "ApplicationManager.h"


ActionSelect::ActionSelect(ApplicationManager* pApp) :Action(pApp) {}

ActionSelect::~ActionSelect(void) {}

void ActionSelect::Execute()
{
	UI* pUI = pManager->GetUI();

	pUI->PrintMsg("Select");

	pUI->GetPointClicked(Cx, Cy);

	pUI->ClearStatusBar();

	Component** complist = ApplicationManager().getcomplist();

	GraphicsInfo* pGInfo = new GraphicsInfo(2);

	Component* comp = 0;

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
			pGInfo->PointsList[0].x = x1;
			pGInfo->PointsList[0].y = y1;
			pGInfo->PointsList[1].x = x2;
			pGInfo->PointsList[1].y = y2;
			break;
		}
	}

	if (comp != 0)
	{
		if (comp->classtype() == "Resistor")
		{
			if (comp->getactiontype() != SELECT)
			{
				comp->setactiontype(SELECT);
			}
			else
			{
				comp->setactiontype(UNSELECT);
			}
		}

		else if (comp->classtype() == "Battery")
		{
			if (comp->getactiontype() != SELECT)
			{
				comp->setactiontype(SELECT);
			}
			else
			{
				comp->setactiontype(UNSELECT);
			}
		}

		else if (comp->classtype() == "Lamp")
		{
			if (comp->getactiontype() != SELECT)
			{
				comp->setactiontype(SELECT);
			}
			else
			{
				comp->setactiontype(UNSELECT);
			}
		}

		else if (comp->classtype() == "Switch")
		{
			if (comp->getactiontype() != SELECT)
			{
				comp->setactiontype(SELECT);
			}
			else
			{
				comp->setactiontype(UNSELECT);
			}
		}

		else if (comp->classtype() == "Ground")
		{
			if (comp->getactiontype() != SELECT)
			{
				comp->setactiontype(SELECT);
			}
			else
			{
				comp->setactiontype(UNSELECT);
			}
		}

		else if (comp->classtype() == "Connection")
		{
			if (comp->getactiontype() != SELECT)
			{
				comp->setactiontype(SELECT);
			}
			else
			{
				comp->setactiontype(UNSELECT);
			}
		}
		else if (comp->classtype() == "Buzzer")
		{
			if (comp->getactiontype() != SELECT)
			{
				comp->setactiontype(SELECT);
			}
			else
			{
				comp->setactiontype(UNSELECT);
			}
		}
		else if (comp->classtype() == "Fuse")
		{
			if (comp->getactiontype() != SELECT)
			{
				comp->setactiontype(SELECT);
			}
			else
			{
				comp->setactiontype(UNSELECT);
			}
		}
	}

}

void ActionSelect::Undo()
{}

void ActionSelect::Redo()
{}
