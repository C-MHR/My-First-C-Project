#pragma once
#include <string>
#include <fstream>
using namespace std;
	
struct customer {
	int id;
	string name;
	int bill;
	string date;
	
};

void add(customer c[], int size);
void view(customer c[], int size);
int search(customer c[], int size);
void update(customer c[], int size);
void Delete(customer c[], int size);

void Delete(customer c[], int size)
{
	int index = search(c, size);
	if (index != -1)
	{
		c[index].id = 0;
		c[index].name = '\0';
		c[index].bill = 0;
		c[index].date = '\0';
		ofstream fout;
		fout.open("customers.txt");
		for (int i = 0; i < size; i++)
		{
			if (c[i].id != 0)
			{
				fout << c[i].id << " " << c[i].name << " " << c[i].bill << " " << c[i].date << endl;
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

void update(customer c[], int size)
{
	int index = search(c, size);
	if (index != -1)
	{
		cout << "Enter new bill Amount\n";
		cin >> c[index].bill;
		ofstream fout;
		fout.open("customers.txt");
		for (int i = 0; i < size; i++)
		{
			fout << c[i].id << " " << c[i].name << " " << c[i].bill << " " << c[i].date << endl;
		}
		fout.close();
		cout << "The record has been updated!\n";
	}
	else
	{
		cout << "Record not found\n";
	}

}

int search(customer c[], int size)
{
	cout << "Enter customer ID:";
	int sid;
	cin >> sid;
	for (int i = 0; i < size; i++)
	{
		if (c[i].id == sid)
		{
			return i;
		}
	}
	return -1;
}

void view(customer c[], int size)
{
	cout << "Customer_ID\tCustomer_Name\tBill_Amount\tDate_Of_Visit\n";

	for (int i = 0; i < size; i++)
	{
		cout << c[i].id << "\t\t" << c[i].name << "\t\t" << c[i].bill << "\t\t" << c[i].date << endl;
	}
}

void add(customer c[], int size)
{	cout << "Enter Customer ID:";
	cin >> c[size].id;
	cout << "Enter Customer's name:";
	cin >> c[size].name;
	cout << "Enter bill Amount:";
	cin >> c[size].bill;
	cout << "Enter date of visit:";
	cin >> c[size].date;
	ofstream fout;
	fout.open("customers.txt");
	for (int i = 0; i < size + 1; i++)
	{
		fout << c[i].id << " " << c[i].name << " " << c[i].bill << " " << c[i].date << endl;
	}
	fout.close();
}