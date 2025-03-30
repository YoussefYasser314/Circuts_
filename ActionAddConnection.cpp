#include "ActionAddConnection.h"
#include "ApplicationManager.h"
#include <cstdlib>


ActionAddConnection::ActionAddConnection(ApplicationManager* pApp) :Action(pApp)
{
}


ActionAddConnection::~ActionAddConnection(void)
{
}


void ActionAddConnection::Execute()
{

	int nums = 0;
	for (int i = 0; i < ApplicationManager().getcompcount(); i++) {
		if (ApplicationManager().getcomplist()[i]->getactiontype() == SELECT)
			nums++;
	}
	if (nums == 2)
	{
		//Get a Pointer to the user Interfaces
		UI* pUI = pManager->GetUI();

		GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

		//A double pointer to the components' list
		Component** complist = ApplicationManager().getcomplist();
		int index, x1, x2, y1, y2;
		Component* comp1 = 0;
		Component* comp2 = 0;

		for (int i = 0; i < ApplicationManager().getcompcount(); i++) {
			if (complist[i]->getactiontype() == SELECT) {
				comp1 = complist[i];
				index = i;
				break;
			}
		}
		for (int i = 0; i < ApplicationManager().getcompcount(); i++) {
			if (index != i)
			{
				if (complist[i]->getactiontype() == SELECT) {
					comp2 = complist[i];
					break;
				}
			}
		}

		enum Cases {
			Null,
			C00_C00,
			C00_C01,
			NOT_ALLOWED,
		};
		Connection** Connlist = ApplicationManager().GetConnList();
		int ConnCount = ApplicationManager().GetConnCount();

		Cases Case = Null;
		bool test = true;
		if (ConnCount != 0)
		{
			int count = 0;
			int another_count = 0;
			for (int i = 0; i < ConnCount; i++)
			{
				if ((Connlist[i]->GetComp1() == comp1 || Connlist[i]->GetComp2() == comp1))
				{
					for (int j = 0; j < ConnCount && j != i; j++)
					{
						if (Connlist[j]->GetComp1() == comp1 || Connlist[j]->GetComp2() == comp1)
						{
							Case = NOT_ALLOWED;
							break;
						}
						else {
							another_count++;
						}
					}
					if (another_count == ConnCount - 1) {
						int another_another_count = 0;
						for (int x = 0; x < ConnCount && x != i; x++) {
							if (Connlist[x]->GetComp1() == comp2 || Connlist[x]->GetComp2() == comp2){
								int x21 = comp2->m_pGfxInfo->PointsList[0].x;
								int x22 = comp2->m_pGfxInfo->PointsList[0].x + 100;
								int o21 = Connlist[x]->Getx1();
								int o22 = Connlist[x]->Getx2();

								int o11 = Connlist[i]->Getx1();
								int o12 = Connlist[i]->Getx2();
								int x11 = comp1->m_pGfxInfo->PointsList[0].x;
								int x12 = comp1->m_pGfxInfo->PointsList[0].x + 100;

								if (x11 != o11 && x11 != o12 && x21 != o21 && x21 != o22)
								{
									x1 = x11;
									x2 = x21;
									y2 = comp2->m_pGfxInfo->PointsList[0].y + 10;
									y1 = comp1->m_pGfxInfo->PointsList[0].y + 10;
									Connection* pR = new Connection(comp1, comp2, x1, x2, y1, y2);
									pManager->AddConnection(pR);
									break;
								}
								else if (x12 != o11 && x12 != o12 && x21 != o21 && x21 != o22) {
									x1 = x12;
									x2 = x21;
									y2 = comp2->m_pGfxInfo->PointsList[0].y + 10;
									y1 = comp1->m_pGfxInfo->PointsList[0].y + 10;
									Connection* pR = new Connection(comp1, comp2, x1, x2, y1, y2);
									pManager->AddConnection(pR);
									break;
								}
								else if (x11 != o11 && x11 != o12 && x22 != o21 && x22 != o22) {
									x1 = x11;
									x2 = x22;
									y2 = comp2->m_pGfxInfo->PointsList[0].y + 10;
									y1 = comp1->m_pGfxInfo->PointsList[0].y + 10;
									Connection* pR = new Connection(comp1, comp2, x1, x2, y1, y2);
									pManager->AddConnection(pR);
									break;
								}
								else if (x12 != o11 && x12 != o12 && x22 != o21 && x22 != o22) {
									x1 = x12;
									x2 = x22;
									y2 = comp2->m_pGfxInfo->PointsList[0].y + 10;
									y1 = comp1->m_pGfxInfo->PointsList[0].y + 10;
									Connection* pR = new Connection(comp1, comp2, x1, x2, y1, y2);
									pManager->AddConnection(pR);
									break;
								}
								
							}
							else {
								another_another_count++;
							}
						}
						if (another_another_count == ConnCount - 1) {
							int xc1 = comp2->m_pGfxInfo->PointsList[0].x;
							int xc2 = comp2->m_pGfxInfo->PointsList[0].x + 100;
							int o1 = Connlist[i]->Getx1();
							int o2 = Connlist[i]->Getx2();
							int x22 = comp1->m_pGfxInfo->PointsList[0].x + 100;
							int x21 = comp1->m_pGfxInfo->PointsList[0].x;

							if (x21 != o1 && x21 != o2)
							{
								if (abs(x21 - xc1) < abs(xc2 - x21))
								{
									x1 = x21;
									x2 = xc1;
									y1 = comp2->m_pGfxInfo->PointsList[0].y + 10;
									y2 = comp1->m_pGfxInfo->PointsList[0].y + 10;
									Connection* pR = new Connection(comp1, comp2, x1, x2, y1, y2);
									pManager->AddConnection(pR);
									break;
								}
								else
								{
									x1 = xc2;
									x2 = x21;
									y1 = comp1->m_pGfxInfo->PointsList[0].y + 10;
									y2 = comp2->m_pGfxInfo->PointsList[0].y + 10;
									Connection* pR = new Connection(comp1, comp2, x1, x2, y1, y2);
									pManager->AddConnection(pR);
									break;
								}
							}
							else if (x22 != o1 && x22 != o2)
							{
								if (abs(x22 - xc1) < abs(xc2 - x22))
								{
									x1 = x22;
									x2 = xc1;
									y1 = comp2->m_pGfxInfo->PointsList[0].y + 10;
									y2 = comp1->m_pGfxInfo->PointsList[0].y + 10;
									Connection* pR = new Connection(comp1, comp2, x1, x2, y1, y2);
									pManager->AddConnection(pR);
									break;
								}
								else
								{
									x1 = xc2;
									x2 = x22;
									y1 = comp1->m_pGfxInfo->PointsList[0].y + 10;
									y2 = comp2->m_pGfxInfo->PointsList[0].y + 10;
									Connection* pR = new Connection(comp1, comp2, x1, x2, y1, y2);
									pManager->AddConnection(pR);
									break;
								}
							}
							else
							{
								Case = NOT_ALLOWED;
							}
						}
					}
				}
				else {
					count++;
				}
				if (Case == NOT_ALLOWED)
					break;
			}
			if (Case == NOT_ALLOWED)
			{
				UI* pUI = pManager->GetUI();

				//Print Action Message
				pUI->PrintMsg("Invalid, One of the components is fully connected");
			}
			else if (count == ConnCount)
			{
				count = 0;
				for (int i = 0; i < ConnCount; i++)
				{
					if (Connlist[i]->GetComp1() == comp2 || Connlist[i]->GetComp2() == comp2)
					{
						for (int j = 0; j < ConnCount && j != i; j++)
						{
							if (Connlist[j]->GetComp1() == comp2 || Connlist[j]->GetComp2() == comp2)
							{
								Case = NOT_ALLOWED;
								break;
							}
							else {
								count++;
							}
						}
					}
					/*else {
						Case = C00_C00;
						break;
					}*/

					if (Case == NOT_ALLOWED)
						break;
					else if (count == ConnCount - 1)
						break;
				}
				if (Case == NOT_ALLOWED)
				{
					UI* pUI = pManager->GetUI();

					//Print Action Message
					pUI->PrintMsg("Invalid, One of the components is fully connected");
				}
				else if (Case == C00_C00)
				{
					int Length1 = abs(comp2->m_pGfxInfo->PointsList[0].x - (comp1->m_pGfxInfo->PointsList[0].x + 100));
					int Length2 = abs((comp2->m_pGfxInfo->PointsList[0].x + 100) - comp1->m_pGfxInfo->PointsList[0].x);
					int Length3 = abs(comp2->m_pGfxInfo->PointsList[0].x - (comp1->m_pGfxInfo->PointsList[0].x));
					int Length4 = abs((comp2->m_pGfxInfo->PointsList[0].x + 100) - (comp1->m_pGfxInfo->PointsList[0].x + 100));
					int Length11 = (comp2->m_pGfxInfo->PointsList[0].x - (comp1->m_pGfxInfo->PointsList[0].x + 100));
					int Length22 = ((comp2->m_pGfxInfo->PointsList[0].x + 100) - comp1->m_pGfxInfo->PointsList[0].x);
					int Length33 = (comp2->m_pGfxInfo->PointsList[0].x - (comp1->m_pGfxInfo->PointsList[0].x));
					int Length44 = ((comp2->m_pGfxInfo->PointsList[0].x + 100) - (comp1->m_pGfxInfo->PointsList[0].x + 100));
					int list[4] = { Length1, Length2, Length3, Length4 };
					int shortest = Length1;
					for (int i = 0; i < 4; i++)
					{
						if (list[i] < shortest)
						{
							shortest = list[i];
						}
					}
					if (Length1 == shortest)
					{
						if (Length11 > 0)
						{
							x1 = comp1->m_pGfxInfo->PointsList[0].x + 100;
							x2 = comp2->m_pGfxInfo->PointsList[0].x;
							y1 = comp1->m_pGfxInfo->PointsList[0].y + 10;
							y2 = comp2->m_pGfxInfo->PointsList[0].y + 10;
							Connection* pR = new Connection(comp1, comp2, x1, x2, y1, y2);
							pManager->AddConnection(pR);
						}
						else
						{
							x2 = comp1->m_pGfxInfo->PointsList[0].x + 100;
							x1 = comp2->m_pGfxInfo->PointsList[0].x;
							y1 = comp1->m_pGfxInfo->PointsList[0].y + 10;
							y2 = comp2->m_pGfxInfo->PointsList[0].y + 10;
							Connection* pR = new Connection(comp1, comp2, x1, x2, y1, y2);
							pManager->AddConnection(pR);
						}
					}
					else if (Length2 == shortest)
					{
						if (Length22 > 0)
						{
							x1 = comp2->m_pGfxInfo->PointsList[0].x + 100;
							x2 = comp1->m_pGfxInfo->PointsList[0].x;
							y1 = comp1->m_pGfxInfo->PointsList[0].y + 10;
							y2 = comp2->m_pGfxInfo->PointsList[0].y + 10;

							Connection* pR = new Connection(comp1, comp2, x1, x2, y1, y2);
							pManager->AddConnection(pR);
						}
						else
						{
							x2 = comp2->m_pGfxInfo->PointsList[0].x + 100;
							x1 = comp1->m_pGfxInfo->PointsList[0].x;
							y1 = comp1->m_pGfxInfo->PointsList[0].y + 10;
							y2 = comp2->m_pGfxInfo->PointsList[0].y + 10;

							Connection* pR = new Connection(comp1, comp2, x1, x2, y1, y2);
							pManager->AddConnection(pR);
						}
					}
					else if (Length3 == shortest)
					{
						if (Length33 > 0)
						{
							x1 = comp1->m_pGfxInfo->PointsList[0].x;
							x2 = comp2->m_pGfxInfo->PointsList[0].x;
							y1 = comp1->m_pGfxInfo->PointsList[0].y + 10;
							y2 = comp2->m_pGfxInfo->PointsList[0].y + 10;
							Connection* pR = new Connection(comp1, comp2, x1, x2, y1, y2);
							pManager->AddConnection(pR);
						}
						else
						{
							x2 = comp1->m_pGfxInfo->PointsList[0].x;
							x1 = comp2->m_pGfxInfo->PointsList[0].x;
							y1 = comp1->m_pGfxInfo->PointsList[0].y + 10;
							y2 = comp2->m_pGfxInfo->PointsList[0].y + 10;
							Connection* pR = new Connection(comp1, comp2, x1, x2, y1, y2);
							pManager->AddConnection(pR);
						}
					}
					else if (Length4 == shortest)
					{
						if (Length44 > 0)
						{
							x1 = comp1->m_pGfxInfo->PointsList[0].x + 100;
							x2 = comp2->m_pGfxInfo->PointsList[0].x + 100;
							y1 = comp1->m_pGfxInfo->PointsList[0].y + 10;
							y2 = comp2->m_pGfxInfo->PointsList[0].y + 10;
							Connection* pR = new Connection(comp1, comp2, x1, x2, y1, y2);
							pManager->AddConnection(pR);
						}
						else
						{
							x2 = comp1->m_pGfxInfo->PointsList[0].x + 100;
							x1 = comp2->m_pGfxInfo->PointsList[0].x + 100;
							y1 = comp1->m_pGfxInfo->PointsList[0].y + 10;
							y2 = comp2->m_pGfxInfo->PointsList[0].y + 10;
							Connection* pR = new Connection(comp1, comp2, x1, x2, y1, y2);
							pManager->AddConnection(pR);
						}
					}
				}

				else if (count == ConnCount - 1)
				{
					for (int i = 0; i < ConnCount; i++)
					{
						if (Connlist[i]->GetComp1() == comp2 || Connlist[i]->GetComp2() == comp2)
						{
							int x21 = comp2->m_pGfxInfo->PointsList[0].x;
							int x22 = comp2->m_pGfxInfo->PointsList[0].x + 100;
							int o1 = Connlist[i]->Getx1();
							int o2 = Connlist[i]->Getx2();
							int xc1 = comp1->m_pGfxInfo->PointsList[0].x + 100;
							int xc2 = comp1->m_pGfxInfo->PointsList[0].x;

							if (x21 != o1 && x21 != o2)
							{
								if (abs(x21 - xc1) < abs(xc2 - x21))
								{
									x1 = x21;
									x2 = xc1;
									y1 = comp2->m_pGfxInfo->PointsList[0].y + 10;
									y2 = comp1->m_pGfxInfo->PointsList[0].y + 10;
									Connection* pR = new Connection(comp1, comp2, x1, x2, y1, y2);
									pManager->AddConnection(pR);
									break;
								}
								else
								{
									x1 = xc2;
									x2 = x21;
									y1 = comp1->m_pGfxInfo->PointsList[0].y + 10;
									y2 = comp2->m_pGfxInfo->PointsList[0].y + 10;
									Connection* pR = new Connection(comp1, comp2, x1, x2, y1, y2);
									pManager->AddConnection(pR);
									break;
								}
							}
							else if (x22 != o1 && x22 != o2)
							{
								if (abs(x22 - xc1) < abs(xc2 - x22))
								{
									x1 = x22;
									x2 = xc1;
									y1 = comp2->m_pGfxInfo->PointsList[0].y + 10;
									y2 = comp1->m_pGfxInfo->PointsList[0].y + 10;
									Connection* pR = new Connection(comp1, comp2, x1, x2, y1, y2);
									pManager->AddConnection(pR);
									break;
								}
								else
								{
									x1 = xc2;
									x2 = x22;
									y1 = comp1->m_pGfxInfo->PointsList[0].y + 10;
									y2 = comp2->m_pGfxInfo->PointsList[0].y + 10;
									Connection* pR = new Connection(comp1, comp2, x1, x2, y1, y2);
									pManager->AddConnection(pR);
									break;
								}
							}
							else
							{
								Case = NOT_ALLOWED;
							}
						}
						if (Case = NOT_ALLOWED)
						{
							UI* pUI = pManager->GetUI();

							//Print Action Message
							pUI->PrintMsg("Invalid, One of the components is fully connected");
						}

					}
				}
			}
			
		}
		else
		{
			Case = C00_C00;
		}
		if (Case == C00_C00)
			{
				int Length1 = abs(comp2->m_pGfxInfo->PointsList[0].x - (comp1->m_pGfxInfo->PointsList[0].x + 100));
				int Length2 = abs((comp2->m_pGfxInfo->PointsList[0].x + 100) - comp1->m_pGfxInfo->PointsList[0].x);
				int Length3 = abs(comp2->m_pGfxInfo->PointsList[0].x - (comp1->m_pGfxInfo->PointsList[0].x));
				int Length4 = abs((comp2->m_pGfxInfo->PointsList[0].x + 100) - (comp1->m_pGfxInfo->PointsList[0].x + 100));
				int Length11 = (comp2->m_pGfxInfo->PointsList[0].x - (comp1->m_pGfxInfo->PointsList[0].x + 100));
				int Length22 = ((comp2->m_pGfxInfo->PointsList[0].x + 100) - comp1->m_pGfxInfo->PointsList[0].x);
				int Length33 = (comp2->m_pGfxInfo->PointsList[0].x - (comp1->m_pGfxInfo->PointsList[0].x));
				int Length44 = ((comp2->m_pGfxInfo->PointsList[0].x + 100) - (comp1->m_pGfxInfo->PointsList[0].x + 100));
				int list[4] = { Length1, Length2, Length3, Length4 };
				int shortest = Length1;
				for (int i = 0; i < 4; i++)
				{
					if (list[i] < shortest)
					{
						shortest = list[i];
					}
				}
				if (Length1 == shortest )
				{
					if (Length11 > 0)
					{
						x1 = comp1->m_pGfxInfo->PointsList[0].x + 100;
						x2 = comp2->m_pGfxInfo->PointsList[0].x;
						y1 = comp1->m_pGfxInfo->PointsList[0].y + 10;
						y2 = comp2->m_pGfxInfo->PointsList[0].y + 10;
						Connection* pR = new Connection(comp1, comp2, x1, x2, y1, y2);
						pManager->AddConnection(pR);
					}
					else 
					{
						x2 = comp1->m_pGfxInfo->PointsList[0].x + 100;
						x1 = comp2->m_pGfxInfo->PointsList[0].x;
						y1 = comp1->m_pGfxInfo->PointsList[0].y + 10;
						y2 = comp2->m_pGfxInfo->PointsList[0].y + 10;
						Connection* pR = new Connection(comp1, comp2, x1, x2, y1, y2);
						pManager->AddConnection(pR);
					}
				}
				else if (Length2 == shortest )
				{
					if (Length22 > 0)
					{
						x1 = comp2->m_pGfxInfo->PointsList[0].x + 100;
						x2 = comp1->m_pGfxInfo->PointsList[0].x;
						y1 = comp1->m_pGfxInfo->PointsList[0].y + 10;
						y2 = comp2->m_pGfxInfo->PointsList[0].y + 10;

						Connection* pR = new Connection(comp1, comp2, x1, x2, y1, y2);
						pManager->AddConnection(pR);
					}
					else
					{
						x2 = comp2->m_pGfxInfo->PointsList[0].x + 100;
						x1 = comp1->m_pGfxInfo->PointsList[0].x;
						y1 = comp1->m_pGfxInfo->PointsList[0].y + 10;
						y2 = comp2->m_pGfxInfo->PointsList[0].y + 10;

						Connection* pR = new Connection(comp1, comp2, x1, x2, y1, y2);
						pManager->AddConnection(pR);
					}
				}
				else if (Length3 == shortest )
				{
					if(Length33 > 0)
					{
						x1 = comp1->m_pGfxInfo->PointsList[0].x;
						x2 = comp2->m_pGfxInfo->PointsList[0].x;
						y1 = comp1->m_pGfxInfo->PointsList[0].y + 10;
						y2 = comp2->m_pGfxInfo->PointsList[0].y + 10;
						Connection* pR = new Connection(comp1, comp2, x1, x2, y1, y2);
						pManager->AddConnection(pR);
					}
					else
					{
						x2 = comp1->m_pGfxInfo->PointsList[0].x;
						x1 = comp2->m_pGfxInfo->PointsList[0].x;
						y1 = comp1->m_pGfxInfo->PointsList[0].y + 10;
						y2 = comp2->m_pGfxInfo->PointsList[0].y + 10;
						Connection* pR = new Connection(comp1, comp2, x1, x2, y1, y2);
						pManager->AddConnection(pR);
					}
				}
				else if(Length4 == shortest)
				{
					if(Length44 > 0)
					{
						x1 = comp1->m_pGfxInfo->PointsList[0].x + 100;
						x2 = comp2->m_pGfxInfo->PointsList[0].x + 100;
						y1 = comp1->m_pGfxInfo->PointsList[0].y + 10;
						y2 = comp2->m_pGfxInfo->PointsList[0].y + 10;
						Connection* pR = new Connection(comp1, comp2, x1, x2, y1, y2);
						pManager->AddConnection(pR);
					}
					else
					{
						x2 = comp1->m_pGfxInfo->PointsList[0].x + 100;
						x1 = comp2->m_pGfxInfo->PointsList[0].x + 100;
						y1 = comp1->m_pGfxInfo->PointsList[0].y + 10;
						y2 = comp2->m_pGfxInfo->PointsList[0].y + 10;
						Connection* pR = new Connection(comp1, comp2, x1, x2, y1, y2);
						pManager->AddConnection(pR);
					}
				}
			}
	}
	else
	{
		UI* pUI = pManager->GetUI();

		//Print Action Message
		pUI->PrintMsg("Invalid, Please select only 2 Components");
		}
}


void ActionAddConnection::Undo()
{
}


void ActionAddConnection::Redo()
{
}
