#include "Fuse.h"
#include "UI/UI.h"
#include "ApplicationManager.h"
#include "ActionSelect.h"
#include <string>


Fuse::Fuse(GraphicsInfo* r_GfxInfo) : Component(r_GfxInfo)
{
	actiontype = ApplicationManager().getactiontype();
	value = 0;
}


string Fuse::getname()
{
	return name;
}
                                                                                                      
double Fuse::getvalue()
{
	return value;
}

void Fuse::setlabel(string label, double v)
{
	name = label;
	value = v;
}

string Fuse::classtype() const
{
	return "Fuse";
}

ActionType Fuse::getactiontype()
{
	return actiontype;
}

GraphicsInfo* Fuse::getgraphicsinfo() const
{
	return m_pGfxInfo;
}

void Fuse::setactiontype(ActionType at)
{
	actiontype = at;
}


void Fuse::Draw(UI* pUI)
{
	//TODO Modified 
	if (actiontype == SELECT)
	{
		pUI->DrawFuse(*m_pGfxInfo, true);
	}
	else
		pUI->DrawFuse(*m_pGfxInfo);
}

void Fuse::Operate() {}
