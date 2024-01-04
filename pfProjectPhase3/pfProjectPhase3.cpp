
#include <iostream>
#include"Deals.h"
#include"Customer.h"
#include"Tip.h"
using namespace std;

void mainMenu();
void deals(deal d[],int D_filledIndex);
void customers(customer c[],int C_filledIndex);
void tips(deal d[], int D_filledIndex, customer c[], int C_filledIndex);

int main()
{
	mainMenu();
	
}
void mainMenu()
{
	
		const int DSIZE = 5;
		deal dealMenu[DSIZE];
		ifstream fin;
		fin.open("deals.txt");
		try {
			if (fin.fail())
			{
				throw runtime_error("File not found");
			}
		}
		catch (runtime_error & e)
		{
			cout << "Error" << e.what();
		}
		int i = 0;
		if (!fin.fail()) {
			while (!fin.eof())
			{
				fin >> dealMenu[i].id >> dealMenu[i].deal1 >> dealMenu[i].deal2 >> dealMenu[i].price;
				i++;
			}
			i = i - 1;
		}
		fin.close();

		const int CSIZE = 5;
		customer customerMenu[CSIZE];
		ifstream inputFile;
		inputFile.open("customers.txt");
		try {
			if (inputFile.fail())
			{
				throw runtime_error("File not found");
			}
		}
		catch (runtime_error & e)
		{
			cout << "Error" << e.what();
		}
		int j = 0;
		if (!inputFile.fail()) {
			while (!inputFile.eof())
			{
				inputFile >> customerMenu[j].id >> customerMenu[j].name >> customerMenu[j].bill >> customerMenu[j].date;
				j++;
			}
			j = j - 1;
		}
		inputFile.close();
	

	while (true) {
		cout << "1.Deals\n2.Customers\n3.Tips\n4.Exit\n";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			deals(dealMenu, i);
			break;
		case 2:
			customers(customerMenu, j);
			break;
		case 3:
			cout << "Calling Tips Function!\n";
			tips(dealMenu, i, customerMenu, j);
			break;
		case 4:
			cout << "Program Ends!\n";
			exit(0);
			break;
		default:
			cout << "You have entered invalid option!\n";
		}
	}
}
void deals(deal d[],int D_filledIndex)
{
	
	while (true)
	{
		cout << "Deals Management\n";
		cout << "1.Add\n2.View\n3.Search\n4.Update\n5.Delete\n6.Back to main\n";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Calling Add Function!\n";
			add(d, D_filledIndex);
			break;
		case 2:
			cout << "Calling View Function!\n";
			view(d, D_filledIndex);
			break;
		case 3:
			cout << "Calling Search Function!\n";
			{
				int id = search(d, D_filledIndex);
				if (id != -1)
				{
					cout << "ID Found!\n";
				}
				else
				{
					cout << "ID not Found!\n";
				}
			}
			break;
		case 4:
			cout << "Calling Update Function!\n";
			update(d, D_filledIndex);
			break;
		case 5:
			cout << "Calling Delete Function!\n";
			Delete(d, D_filledIndex);
			break;
		case 6:
			cout << "Going back to main menu!\n";
			mainMenu();
			break;
		default:
			cout << "You have entered invalid option!\n";

		}
	}
}
void customers(customer c[],int C_filledIndex)
{
	while (true)
	{
		cout << "Customers Management\n";
		cout << "1.Add\n2.View\n3.Search\n4.Update\n5.Delete\n6.Back to main\n";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Calling Add Function!\n";
			add(c, C_filledIndex);
			break;
		case 2:
			cout << "Calling View Function!\n";
			view(c, C_filledIndex);
			break;
		case 3:
			cout << "Calling Search Function!\n";
			{
				int id = search(c, C_filledIndex);
				if (id != -1)
				{
					cout << "ID Found!\n";
				}
				else
				{
					cout << "ID not Found!\n";
				}
			}
			break;
		case 4:
			cout << "Calling Update Function!\n";
			update(c, C_filledIndex);
			break;
		case 5:
			cout << "Calling Delete Function!\n";
			Delete(c, C_filledIndex);
			break;
		case 6:
			cout << "Going back to main menu!\n";
			mainMenu();
			break;
		default:
			cout << "You have entered invalid option!\n";
		}
	}
}
void tips(deal d[], int D_filledIndex, customer c[], int C_filledIndex)
{
	const int TSIZE = 5;
	tip tipMenu[TSIZE];
	ifstream fin;
	fin.open("tips.txt");
	try {
		if (fin.fail())
		{
			throw runtime_error("File not found\n");
		}
	}
	catch (runtime_error & e)
	{
		cout << "Error" << e.what();
	}
	int k = 0;
	if (!fin.fail())
	{
		while (!fin.eof())
		{
			fin >> tipMenu[k].dealId >> tipMenu[k].customerId >> tipMenu[k].tipAmount >> tipMenu[k].employeeName;
			k++;
		}
		k = k - 1;
	}
	while (true)
	{
		cout << "Tips Management!\n";
		cout << "1.Add\n2.View\n3.Back to main menu\n";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Calling Add Function!\n";
			add(d, D_filledIndex, c, C_filledIndex, tipMenu, k);
			break;
		case 2:
			cout << "Calling View Function!\n";
			view(tipMenu, k);
			break;
		case 3:
			cout << "Going back to main menu!\n";
			mainMenu();
			break;
		default:
			cout << "You have entered invalid option!\n";
		}
	}
}
