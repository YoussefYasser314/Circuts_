#include "ApplicationManager.h"
#include "Actions\ActionAddRes.h"
#include "ActionSelect.h"
#include "ActionLabel.h"
#include "ActionAddBattery.h"
#include"ActionAddBulb.h"
#include "ActionAddGround.h"
#include "ActionAddSwitch.h"
#include "ActionExit.h"
#include "ActionAddLabel.h"
#include "ActionAddBuzzer.h"
#include "ActionAddFuse.h"
#include "ActionDelete.h"
#include "ActionAddConnection.h"
#include "ActionCheckValidation.h"


//TODO add them
int ApplicationManager::CompCount = 0;
Component* ApplicationManager::CompList[MaxCompCount];
int ApplicationManager::ConnCount = 0;
Connection* ApplicationManager::ConnList[MaxCompCount];

////////////////////////////////////////////////////////////////////

ApplicationManager::ApplicationManager()
{
	//Creates the UI Object & Initialize the UI
	pUI = new UI;
}

////////////////////////////////////////////////////////////////////
//TODO add them from 
int ApplicationManager::getcompcount()
{
	return CompCount;
}
////////////////////////////////////////////////////////////////////

Component** ApplicationManager::getcomplist()
{
	return CompList;
}
int ApplicationManager::GetConnCount()
{
	return ConnCount;
}
Connection** ApplicationManager::GetConnList()
{
	return ConnList;
}
////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::getactiontype()
{
	return ActType;
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::setactiontype(ActionType at)
{
	ActType = at;
}

////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;		
}

////////////////////////////////////////////////////////////////////
void ApplicationManager::AddConnection(Connection* pConn)
{
	ConnList[ConnCount++] = pConn;

}

////////////////////////////////////////////////////////////////////
ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return pUI->GetUserAction(); 	
}

////////////////////////////////////////////////////////////////////
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = nullptr;
	bool x = ActionCheckValidation().Check();
	switch (ActType)
	{
		case ADD_RESISTOR:
			pAct= new ActionAddRes(this);
			break;

		case ADD_GROUND:
			pAct = new ActionAddGround(this);
			break;
		case ADD_LAMP:
			pAct = new ActionAddBulb(this);
			break;
		case ADD_BATTERY:
			pAct = new ActionAddBattery(this);
			break;
		case ADD_SWITCH:
			pAct = new ActionAddSwitch(this);
			break;

		case ADD_CONNECTION:
			pAct = new ActionAddConnection(this);
			break;

		case ADD_BUZZER:
			pAct = new ActionAddBuzzer(this);
			break;
			
		case ADD_FUSE:
			pAct = new ActionAddFuse(this);
			break;

		case ADD_Label:
			pAct = new ActionLabel(this);
			break;

		case SELECT:
			pAct = new ActionSelect(this);
			break;
		case DEL:
			pAct = new ActionDelete(this);
			break;	
		case EDIT_Label:
			pAct = new ActionLabel(this);
			break;

		case SIM_MODE:
			//pAct = new ActionCheckValidation(this);
			//ActionCheckValidation* pCheck ;
			if (x)
			{
				pUI->Switch_Mode();
					break;
			}
			else
			{
				pUI->PrintMsg("Check circiut validation first!");
				Sleep(2000);
				pUI->ClearStatusBar();
				break;
			}		
		case EXIT:
			pAct = new ActionExit(this);
			break;
	}
	if(pAct)
	{
		pAct->Execute();
		if (ActType == ADD_RESISTOR || ActType == ADD_SWITCH || ActType == ADD_BATTERY || ActType == ADD_LAMP || ActType == ADD_GROUND || ActType == ADD_BUZZER || ActType == ADD_FUSE)
		{
			pAct = new ActionAddLabel(this);
			pAct->Execute();
		}

		delete pAct;
		pAct = nullptr;
	}
}

////////////////////////////////////////////////////////////////////
void ApplicationManager::UpdateInterface()
{
	if (this->getactiontype() != EXIT)
	{
		pUI->ClearDrawingArea();
		for (int i = 0; i < CompCount; i++)
		{
			CompList[i]->Draw(pUI);
			if (CompList[i]->classtype() == "Ground")
				pUI->PrintLabel(CompList[i]->getname() + " , 0", CompList[i]->m_pGfxInfo->PointsList[0].x, CompList[i]->m_pGfxInfo->PointsList[0].y - 20);

			else if (CompList[i]->classtype() == "Switch")
			{
				pUI->PrintLabel(CompList[i]->getname(), CompList[i]->m_pGfxInfo->PointsList[0].x, CompList[i]->m_pGfxInfo->PointsList[0].y - 20);

			}
			else
				pUI->PrintLabel(CompList[i]->getname() + " , " + to_string(CompList[i]->getvalue()), CompList[i]->m_pGfxInfo->PointsList[0].x, CompList[i]->m_pGfxInfo->PointsList[0].y - 20);

		}
		for (int i = 0; i < ConnCount; i++)
			ConnList[i]->Draw(pUI);
	}
}

////////////////////////////////////////////////////////////////////
void ApplicationManager::delete_component(Component* C)
{
	for (int i = 0; i < CompCount; i++)
	{
		if (C == CompList[i])
		{
			for (int j = i; j < CompCount; j++)
			{
				CompList[j] = CompList[j + 1];

			}
			break;
		}
	}

	for (int i = 0; i < ConnCount; i++)
	{
		if (C == ConnList[i]->GetComp1() || C == ConnList[i]->GetComp2())
		{
			for (int j = i; j < ConnCount; j++)
			{
				ConnList[j] = ConnList[j + 1];
			}
			ConnCount--;
			break;
		}
		
	}
	
	for (int i = 0; i < ConnCount; i++)
	{
		if (C == ConnList[i]->GetComp1() || C == ConnList[i]->GetComp2())
		{
			for (int j = i; j < ConnCount; j++)
			{
				ConnList[j] = ConnList[j + 1];
			}
			ConnCount--;
			break;
		}
		
	}

	CompCount--;
}

////////////////////////////////////////////////////////////////////
UI* ApplicationManager::GetUI()
{
	return pUI;
}

////////////////////////////////////////////////////////////////////
ApplicationManager::~ApplicationManager()
{
	//for(int i=0; i<CompCount; i++)
	//	delete CompList[i];
	delete pUI;
	
}

