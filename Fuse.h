#pragma once
#include "Components/Component.h"

class Fuse :public Component
{
	string name;
	double value;
	ActionType actiontype;
public:

	Fuse(GraphicsInfo* r_GfxInfo);
	virtual void Draw(UI*);
	virtual void Operate();	//Calculates the volt on both terminals


	virtual ActionType getactiontype();
	virtual string getname();
	virtual double getvalue();
	virtual GraphicsInfo* getgraphicsinfo() const;
	virtual void setactiontype(ActionType);
	virtual void setlabel(string, double);
	virtual string classtype() const;
};

