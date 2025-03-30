#include "Battery.h"
#include "UI/UI.h"
#include "ApplicationManager.h"
#include "ActionSelect.h"
#include <string>


Battery::Battery(GraphicsInfo* r_GfxInfo): Component(r_GfxInfo)
{
	actiontype = ApplicationManager().getactiontype();
	value = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//TODO Added functions in each component


string Battery::getname()
{
	return name;
}

double Battery::getvalue()
{
	return value;
}

void Battery::setlabel(string label, double v)
{
	name = label;
	value = v;
}

string Battery::classtype() const
{
	return "Battery";
}

ActionType Battery::getactiontype()
{
	return actiontype;
}

GraphicsInfo* Battery::getgraphicsinfo() const
{
	return m_pGfxInfo;
}

void Battery::setactiontype(ActionType at)
{
	actiontype = at;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Battery::Draw(UI* pUI)
{
	//TODO Modified 
	if (actiontype == SELECT)
	{
		pUI->DrawBattery(*m_pGfxInfo, true);
	}
	else
		pUI->DrawBattery(*m_pGfxInfo);
}

void Battery::Operate(){}
