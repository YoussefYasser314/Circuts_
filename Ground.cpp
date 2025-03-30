#include "Ground.h"
#include "UI/UI.h"
#include "ApplicationManager.h"
#include "ActionSelect.h"
#include <string>


Ground::Ground(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{
	actiontype = ApplicationManager().getactiontype();
	value = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//TODO Added functions in each component



string Ground::getname()
{
	return name;
}

double Ground::getvalue()
{
	return value;
}

void Ground::setlabel(string label, double v)
{
	name = label;
	value = v;
}

string Ground::classtype() const
{
	return "Ground";
}

ActionType Ground::getactiontype()
{
	return actiontype;
}

GraphicsInfo* Ground::getgraphicsinfo() const
{
	return m_pGfxInfo;
}

void Ground::setactiontype(ActionType at)
{
	actiontype = at;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Ground::Draw(UI* pUI)
{
	//TODO Modified 
	if (actiontype == SELECT)
	{
		pUI->DrawGround(*m_pGfxInfo, true);
	}
	else
		pUI->DrawGround(*m_pGfxInfo);
}

void Ground::Operate(){}