#pragma once
#include"Components/Component.h"

class Ground:public Component
{
	//TODO add in all components using the same identifier
	string name;
	double value;
	ActionType actiontype;
public:

	Ground(GraphicsInfo* r_GfxInfo);
	virtual void Draw(UI*);
	virtual void Operate();	//Calculates the volt on both terminals


	//TODO add in all components using the same identifier
	virtual ActionType getactiontype();
	virtual string getname();
	virtual double getvalue();
	virtual GraphicsInfo* getgraphicsinfo() const;
	virtual void setactiontype(ActionType);
	virtual void setlabel(string, double);
	virtual string classtype() const;
};

