#include "Lamp.h"
#include "UI/UI.h"
#include "ApplicationManager.h"
#include "ActionSelect.h"
#include <string>


Lamp::Lamp(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{
	actiontype = ApplicationManager().getactiontype();
	value = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//TODO Added functions in each component



string Lamp::getname()
{
	return name;
}

double Lamp::getvalue()
{
	return value;
}

void Lamp::setlabel(string label, double v)
{
	name = label;
	value = v;
}

string Lamp::classtype() const
{
	return "Lamp";
}

ActionType Lamp::getactiontype()
{
	return actiontype;
}

GraphicsInfo* Lamp::getgraphicsinfo() const
{
	return m_pGfxInfo;
}

void Lamp::setactiontype(ActionType at)
{
	actiontype = at;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Lamp::Draw(UI* pUI)
{
	//TODO Modified 
	if (actiontype == SELECT)
	{
		pUI->DrawBulb(*m_pGfxInfo, true);
	}
	else
		pUI->DrawBulb(*m_pGfxInfo);
}

void Lamp::Operate()
{

}