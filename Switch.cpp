#include "Switch.h"
#include "UI/UI.h"
#include "ApplicationManager.h"
#include "ActionSelect.h"
#include <string>


Switch::Switch(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{
	actiontype = ApplicationManager().getactiontype();
	value = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//TODO Added functions in each component



string Switch::getname()
{
	return name;
}

double Switch::getvalue()
{
	return value;
}

void Switch::setlabel(string label, double v )
{
	name = label;
	value = v;
}

string Switch::classtype() const
{
	return "Switch";
}

ActionType Switch::getactiontype()
{
	return actiontype;
}

GraphicsInfo* Switch::getgraphicsinfo() const
{
	return m_pGfxInfo;
}

void Switch::setactiontype(ActionType at)
{
	actiontype = at;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Switch::Draw(UI* pUI)
{
	//TODO Modified 
	if (actiontype == SELECT)
	{
		pUI->DrawSwitch(*m_pGfxInfo, true);
	}
	else
		pUI->DrawSwitch(*m_pGfxInfo);
}

void Switch::Operate()
{

}