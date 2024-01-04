#pragma once
#include <string>
#include <fstream>
using namespace std;

struct deal {
	int id;
	string deal1;
	string deal2;
	int price;
};
void add(deal d[], int filledIndex);
void view(deal d[], int filledIndex);
int search(deal d[], int filledIndex);
void update(deal d[], int filledIndex);
void Delete(deal d[], int filledIndex);


void Delete(deal d[], int filledIndex)
{
	int index = search(d, filledIndex);
	if (index != -1)
	{
		d[index].id = 0;
		d[index].deal1 = '\0';
		d[index].deal2 = '\0';
		d[index].price = 0;
		ofstream fout;
		fout.open("deals.txt");
		for (int i = 0; i < filledIndex; i++)
		{
			if (d[i].id != 0)
			{
				fout << d[i].id << " " << d[i].deal1 << " " << d[i].deal2 << " " << d[i].price << endl;
			}
		}
		fout.close();
		cout << "The record has been deleted!\n";
	}
	else
	{
		cout << "ID not found!\n";
	}	
}

void update(deal d[], int filledIndex)
{
	int index = search(d, filledIndex);
	if (index != -1)
	{
		cout << "Enter new price\n";
		cin >> d[index].price;
		ofstream fout;
		fout.open("deals.txt");
		for (int i = 0; i < filledIndex; i++)
		{
			fout << d[i].id << " " << d[i].deal1 << " " << d[i].deal2 << " " << d[i].price << endl;
		}
		fout.close();
		cout << "The price has been updated!\n";
	}
	else
	{
		cout << "ID not found\n";
	}

}

int search(deal d[], int filledIndex)
{
	cout << "Enter deal ID:";
	int sid;
	cin >> sid;
	for (int i = 0; i < filledIndex; i++)
	{
		if (d[i].id == sid)
		{
			return i;
		}
	}
	return -1;
}

void view(deal d[], int filledIndex)
{
	cout << "Deal_ID\t\t1st_Item\t2nd_Item\tPrice\n";
	
	for (int i = 0; i < filledIndex; i++)
	{
		cout << d[i].id << "\t\t" << d[i].deal1 << "\t\t" << d[i].deal2 << "\t\t" << d[i].price << endl;
	}
}

void add(deal d[], int filledIndex)
{
	cout << "Enter Deal ID:";
	cin >> d[filledIndex].id;
	cout << "Enter Deal's 1st Item:";
	cin >> d[filledIndex].deal1;
	cout << "Enter Deal's 2nd Item:";
	cin >> d[filledIndex].deal2;
	cout << "Enter Deals Price:";
	cin >> d[filledIndex].price;
	ofstream fout;
	fout.open("deals.txt");
	for (int i = 0; i < filledIndex + 1; i++) 
	{
		fout << d[i].id << " " << d[i].deal1 << " " << d[i].deal2 << " " << d[i].price << endl;
	}
	fout.close();
}