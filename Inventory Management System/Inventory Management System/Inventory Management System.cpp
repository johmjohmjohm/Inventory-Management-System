#include<iostream>
#include<string>
#include<fstream>

using namespace std;

const int maxrow = 100;




string ProductName[maxrow] = {};
string StockID[maxrow] = {};
string ProductQuantity[maxrow]{};


void AddRecord()
{
	char name[50];
	char stockno[10];
	char stockquant[50];

	cin.ignore();
	cout << "Stock ID >> ";
	cin.getline(stockno, 10);
	cout << "Product Name >> ";
	cin.getline(name, 50);
	cout << "Stock Quantity >> ";
	cin.getline(stockquant, 50);

	for (int x = 0; x < maxrow; x++)
	{
		if (StockID[x] == "\0")
		{
			StockID[x] = stockno;
			ProductName[x] = name;
			ProductQuantity[x] = stockquant;
			break;
		}
	}

}

void ListRecord()
{
	system("CLS");
	cout << "Current Record(s):" << endl;
	cout << "==================================" << endl;

	int counter = 0;
	for (int x = 0; x < maxrow; x++)
	{
		if (StockID[x] != "\0")
		{
			counter++;
			cout << " (" << counter << ".)" << endl << " Stock ID: " << StockID[x] << endl << " Product: " << ProductName[x] << endl << " Quantity: " << ProductQuantity[x] << endl << endl;
		}
	}

	if (counter == 0)
	{
		cout << "No Record Found!" << endl;
	}

	cout << "==================================" << endl;
}

void SearchRecord(string search)
{
	system("CLS");
	cout << "Current Record(s)" << endl;
	cout << "===================================" << endl;

	for (int x = 0; x < maxrow; x++)
	{
		int counter = 0;
		if (StockID[x] == search)
		{
			counter++;
			cout << " " << endl << " Stock ID: " << StockID[x] << endl << " Product: " << ProductName[x] << endl << " Quantity: " << ProductQuantity[x] << endl << endl;
		}
	}
}

void UpdateRecord(string search)
{
	char name[50];
	char stockno[10];
	char stockquant[50];

	int counter = 0;

	for (int x = 0; x < maxrow; x++)
	{
		if (StockID[x] == search)
		{
			counter++;

			cout << "*New* Stock ID >> ";
			cin.getline(stockno, 10);
			cout << "*New* Product Name >> ";
			cin.getline(name, 50);
			cout << "*New* Stock Quantity >> ";
			cin.getline(stockquant, 50);

			StockID[x] = stockno;
			ProductName[x] = name;
			ProductQuantity[x] = stockquant;

			cout << "Update Successful!" << endl;
			break;
		}
	}

	if (counter == 0)
	{
		cout << "It Does not exist!";
	}
}

void DeleteRecord(string search)
{
	int counter = 0;

	for (int x = 0; x < maxrow; x++)
	{
		if (StockID[x] == search)
		{
			counter++;
			ProductName[x] = "";
			StockID[x] = "";
			ProductQuantity[x] = "";

			cout << "Sucessfully Deleted!" << endl;
			break;
		}
	}

	if (counter == 0)
	{
		cout << "It Does not exist!";
	}

}

int main()
{
	std::cout << "MENU\n";
	int option;
	string stockID;
	system("CLS");

	do {
		cout << "************MENU************" << endl;
		cout << "1. Add Products" << endl;
		cout << "2. Update Products" << endl;
		cout << "3. Delete Products" << endl;
		cout << "4. Search for Product" << endl;
		cout << "5. Display all available products" << endl;
		cout << "6. Exit and Save to Textfile" << endl;
		cout << "=====================" << endl;

		cout << "Select option >> ";
		cin >> option;

		switch (option)
		{
		case 1:
			AddRecord();
			system("CLS");
			break;

		case 2:
			cin.ignore();
			cout << "Search by ID >> ";
			getline(cin, stockID);
			UpdateRecord(stockID);
			cin.ignore();
			system("CLS");
			break;

		case 3:
			cin.ignore();
			cout << "Delete by ID >> ";
			getline(cin, stockID);
			DeleteRecord(stockID);
			cin.ignore();
			system("CLS");
			break;

		case 4:
			cin.ignore();
			cout << "Search by ID >> ";
			getline(cin, stockID);
			SearchRecord(stockID);
			break;

		case 5:
			ListRecord();
			break;
		}


	} while (option != 6);
}