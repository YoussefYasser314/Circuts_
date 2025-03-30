#include "Buzzer.h"
#include "UI/UI.h"
#include "ApplicationManager.h"
#include "ActionSelect.h"
#include <string>


Buzzer::Buzzer(GraphicsInfo* r_GfxInfo) : Component(r_GfxInfo)
{
	actiontype = ApplicationManager().getactiontype();
	value = 0;
}


string Buzzer::getname()
{
	return name;
}

double Buzzer::getvalue()
{
	return value;
}

void Buzzer::setlabel(string label, double v)
{
	name = label;
	value = v;
}

string Buzzer::classtype() const
{
	return "Buzzer";
}

ActionType Buzzer::getactiontype()
{
	return actiontype;
}

GraphicsInfo* Buzzer::getgraphicsinfo() const
{
	return m_pGfxInfo;
}

void Buzzer::setactiontype(ActionType at)
{
	actiontype = at;
}


void Buzzer::Draw(UI* pUI)
{
	//TODO Modified 
	if (actiontype == SELECT)
	{
		pUI->DrawBuzzer(*m_pGfxInfo, true);
	}
	else
		pUI->DrawBuzzer(*m_pGfxInfo);
}

void Buzzer::Operate() {}
