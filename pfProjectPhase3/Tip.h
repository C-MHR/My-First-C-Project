#pragma once
#include <iostream>
#include <fstream>
using namespace std;
struct tip {
	int dealId;
	int customerId;
	int tipAmount;
	string employeeName;
};
void add(deal d[], int dSize, customer c[], int cSize, tip t[], int tSize);
void view(tip t[], int tSize);

void add(deal d[], int dSize, customer c[], int cSize, tip t[], int tSize)
{
	cout << "Enter Deal Id:";
	cin >> t[tSize].dealId;
	bool dFlag = false;
	for (int i = 0; i < dSize; i++)
	{
		if (d[i].id == t[tSize].dealId)
		{
			dFlag = true;
		}
	}
	if (dFlag == true)
	{
		cout << "Enter Customer Id:";
		cin >> t[tSize].customerId;
		bool cFlag = false;
		for (int j = 0; j < cSize; j++)
		{
			if (c[j].id == t[tSize].customerId)
			{
				cFlag = true;
			}
		}
		if (cFlag == true)
		{
			cout << "Enter amount of tip:";
			cin >> t[tSize].tipAmount;
			cout << "Enter name of employee to whome tio is given:";
			cin >> t[tSize].employeeName;
			ofstream fout;
			fout.open("tips.txt");
			for (int i = 0; i < tSize + 1; i++)
			{
				fout << t[i].dealId << " " << t[i].customerId << " " << t[i].tipAmount << " " << t[i].employeeName << endl;
			}
			fout.close();
		}
		else
		{
			cout << "This Id does not exist in Customer records!\n";
		}
	}
	else
	{
		cout << "This Id does not exist in deals!\n";
	}
}
void view(tip t[], int tSize)
{
	cout << "Deal_Id\tCustomer_ID\tTip_Amount\tTip_Taking_Employee\n";
	for (int i = 0; i < tSize; i++)
	{
		cout << t[i].dealId << "\t" << t[i].customerId << "\t\t" << t[i].tipAmount << "\t\t" << t[i].employeeName << endl;
	}
}


