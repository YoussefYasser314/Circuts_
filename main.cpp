
#include <iostream>
#include <sstream>
#include <cmath>
#include "ApplicationManager.h"

int main()
{
	ActionType ActType;
	ApplicationManager AppManager;

	do
	{		
		ActType = AppManager.GetUserAction();
		//TODO Add it
		AppManager.setactiontype(ActType);

		AppManager.ExecuteAction(ActType);

		AppManager.UpdateInterface();
	
	}while(ActType != EXIT);
		
	return 0;
}
//this is a test

