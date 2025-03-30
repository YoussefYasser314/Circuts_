#include "ActionCheckValidation.h"
#include "ApplicationManager.h"


bool ActionCheckValidation::Check()
{
	Component** complist = ApplicationManager().getcomplist();
	int CompCount = ApplicationManager().getcompcount();
	Connection** Connlist = ApplicationManager().GetConnList();
	int ConnCount = ApplicationManager().GetConnCount();
	bool ground, connections;
	int test = 0;
	int ground_test = 0;

	if (ConnCount == CompCount)
	{
		for (int i = 0; i < ConnCount; i++) 
		{
			if (Connlist[i]->GetComp1()->classtype() == "Ground" || Connlist[i]->GetComp2()->classtype() == "Ground") 
			{
				ground_test++;
			}
		}
	}

	if (ground_test == 2) 
	{
		return true;
	}
	else
	{
		return false;
	}
}
