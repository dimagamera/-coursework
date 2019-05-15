#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <sstream>
#include "header.h"
#include <cstdlib>
#pragma warning(disable:4996)

using namespace std;

int main()
{

	char text[25];
	cout << "Enter FILE: ";
	cin >> text;
	system("cls");
	ifstream f1;
	ofstream f2;
	string ftext, fNum, fType, fProduct, fCharacteristic, fCount, fGoods, fRAM, fVideocard, fCPU;
	char symbol;
	int N = 0, ask = 0, ask2 = 0, ask4 = 0;
	header _inf[200];
	int war = 0;
	string arrayString[100];
	string tmp;
	FILE *count;
	int pCount = 0;

	do
	{
		f1.open(text);
		if (!f1.is_open())
		{
			cout << "File not found." << endl;
			return 1;
		}

		count = fopen(text, "r");
		while (!feof(count)) {
			symbol = getc(count);
			if (symbol == '\n')
			{
				N++;
			}
		}
		fclose(count);
		N++;
		for (int i = 0; i < N; i++)
		{
			f1 >> ftext;
			_inf[i].SefNum(ftext);
			f1 >> ftext;
			_inf[i].SefType(ftext);
			f1 >> ftext;
			_inf[i].SefProduct(ftext);
			f1 >> ftext;
			_inf[i].SefCharacteristic(ftext);
			f1 >> ftext;
			_inf[i].SefGoods(ftext);
			f1 >> ftext;
			_inf[i].SefCount(ftext);

		}

		cout << "\t# " << "\tType" << "\t\tProduct " << "\t\tCharacteristic"<< "\t\tGoods" << "\t\tPrice\n" << endl;
		for (int i = 0; i < N; i++)
		{
			cout << "\t" << _inf[i].GefNum() << "\t" << _inf[i].GefType() << "\t\t" << _inf[i].GefProduct() << "\t\t\t"  << _inf[i].GefCharacteristic() << "\t\t\t"<< _inf[i].GefGoods() << "\t\t" << _inf[i].GefCount() << endl;
		}
		cout << "\n\n----------------------------------------------------------------------------------------------------------------------------------------\n\n" << endl;
		f1.close();
		cout << "\n\n\n->:::::::::::::..........MENU..........:::::::::::::::." << endl;
		cout << "\nFULL Information -1\n [------] -2" << endl;
		cout << "[::::::] - 3" << endl;
		cout << "Search - 4" << endl;
		cout << "Add new - 5\nDelete product  - 6\nEdit product - 7" << endl;
		cout << "exit  - 8" << endl;
		cout << "\n —> Answer: ";
		cin >> ask;
		switch (ask) {
		case 1: {
			pCount = 0;
			system("cls");
			cout << "\n —> Enter number line: ";
			cin >> fNum;
			cout << endl;
			for (int i = 0; i < N; i++) {

				if (_inf[i].GefNum() == fNum) {
					pCount++;
					if (_inf[i].GefType() == "PC")
						cout << _inf[i].GefNum() << " || " << _inf[i].GefType() << " || " << _inf[i].GefProduct() << " || " << _inf[i].GefCharacteristic() << " ||" << _inf[i].GefGoods() << " || " << _inf[i].GefCount() << /*" || " << _inf[i].GefRAM() << " || " << _inf[i].GefVideocard() << " " << _inf[i].GefCPU() << " ||" <<*/ endl;
				}
				else if (_inf[i].GefType() == "PC") {

				}
				pCount = 0;
				break;
			}
		case 2: {


		}
		case 3:
		{

		}
		case 4:
		{
			pCount = 0;
			system("cls");
			cout << "\t*Search by Type  - 1\n\t*Search by Product - 2\n\t* :::::::::: — 3" << endl;
			cout << "\n —> Answer: ";
			cin >> ask2;
			//
			switch (ask2)
			{
			case 1:
			{
				pCount = 0;
				system("cls");
				cout << "\n —> Enter Type: ";
				cin >> fType;
				cout << endl;
				cout << "\t# " << "\tType" << "\t\tProduct " << "\t\tCharacteristic(Version) " << "\tGoods" << "\tPrice\n" << endl;
				for (int i = 0; i < N; i++) {
					if (_inf[i].GefType() == fType) {
						pCount++;
						cout << "\t" << _inf[i].GefNum() << "\t" << _inf[i].GefType() << "\t\t" << _inf[i].GefProduct() << "\t\t\t" << _inf[i].GefCharacteristic() << "\t\t\t\t" << _inf[i].GefGoods() << "\t\t" << _inf[i].GefCount() << endl;
					}
				}
				cout << endl;
				if (pCount == 0) {
					cout << "[X] ERROR: Type - " << fType << " Not found. \n" << endl;
				}
				pCount = 0;
				break;
			}
			case 2:
			{
				pCount = 0;
				system("cls");
				cout << "\n —> Enter Product: ";
				cin >> fProduct;
				cout << endl;
				cout << "\t# " << "\tType" << "\t\tProduct " << "\t\tCharacteristic(Version) " << "\tGoods" << "\tPrice\n" << endl;
				for (int i = 0; i < N; i++) {
					if (_inf[i].GefProduct() == fProduct) {
						pCount++;
						cout << "\t" << _inf[i].GefNum() << "\t" << _inf[i].GefType() << "\t\t" << _inf[i].GefProduct() << "\t\t\t" << _inf[i].GefCharacteristic() << "\t\t\t\t" << _inf[i].GefGoods() << "\t\t" << _inf[i].GefCount() << endl;
					}
				}
				cout << endl;
				if (pCount == 0) {
					cout << "[X] ERROR: Product - " << fType << " not found. \n" << endl;
				}
				pCount = 0;
				break;
			}
			case 3:
			{

				break;
			}
			default: cout << "\n[X] ERROR: The answer number you specified is not in the dial menu.\n" << endl; break;
			}

			N = 0;
			break;
		}
		case 5:
		{
			pCount = 0;
			system("cls");
			cout << "\nENTER TYPE: ";
			cin >> fType;
			_inf[N].SefType(fType);
			cout << "ENTER PRODUCT: ";
			cin >> fProduct;
			_inf[N].SefProduct(fProduct);
			cout << "ENTER VERSION ";
			cin >> fCharacteristic;
			_inf[N].SefCharacteristic(fCharacteristic);
			cout << "ENTER GOODS: ";
			cin >> fGoods;
			_inf[N].SefGoods(fGoods);
			cout << "ENTER PRICE: ";
			cin >> fCount;
			_inf[N].SefCount(fCount);
			/*cout << "Enter RAM: ";
			cin >> fRAM;
			_inf[N].SefRAM(fRAM);
			cout << "Enter VideoCard: ";
			cin >> fVideocard;
			_inf[N].SefVideocard(fVideocard);
			cout << "Enter CPU: ";
			cin >> fCPU;
			_inf[N].SefCPU(fCPU);*/
			stringstream D;
			D << N + 1;
			_inf[N].SefNum(D.str());
			//
			f2.open(text);
			for (int i = 0; i < N; i++)
			{
				f2 << _inf[i].GefNum() << " ";
				f2 << _inf[i].GefType() << " ";
				f2 << _inf[i].GefProduct() << " ";
				f2 << _inf[i].GefCharacteristic() << " ";
				f2 << _inf[i].GefGoods() << " ";
				f2 << _inf[i].GefCount() << " \n";
\
			}
			f2 << _inf[N].GefNum() << " ";
			f2 << _inf[N].GefType() << " ";
			f2 << _inf[N].GefProduct() << " ";
			f2 << _inf[N].GefCharacteristic() << " ";
			f2 << _inf[N].GefGoods() << " ";
			f2 << _inf[N].GefCount() << " ";
			f2.close();
			cout << "\nNEW INFORMATION ADDED." << endl;
			pCount = 0;
			N = 0;
			system("cls");
			break;
		}
		case 6:
		{
			pCount = 0;
			system("cls");
			cout << "\n Enter number line ";
			cin >> fNum;
			f2.open(text);
			for (int i = 0; i < N; i++)
			{
				if (_inf[i].GefNum() != fNum)
				{
					f2 << _inf[i].GefNum() << " ";
					f2 << _inf[i].GefType() << " ";
					f2 << _inf[i].GefProduct() << " ";
					f2 << _inf[i].GefCharacteristic() << " ";
					f2 << _inf[i].GefGoods() << " ";
					if (i != N - 1)
					{
						f2 << _inf[i].GefCount() << "\n";
					}
					else
					{
						f2 << _inf[i].GefCount();
					}
				}
			}
			f2.close();
			N = 0;
			pCount = 0;
			system("cls");
			break;
		}
		case 7:
		{
			pCount = 0;
			system("cls");
			cout << "\t*Edit type  — 1\n\t*Edit product  — 2\n\t*Edit version — 3\n\t*Edit goods — 4\n\t*Edit price — 5\n\t*Full editing — 6" << endl;
			cout << "\nEnter aswer: ";
			cin >> ask4;
			cout << "\nEnter line: ";
			cin >> fNum;
			switch (ask4)
			{
			case 1:
			{
				for (int i = 0; i < N; i++)
				{
					if (_inf[i].GefNum() == fNum)
					{
						war++;
						cout << "\nEnter new type: ";
						cin >> fType;
						_inf[i].SefType(fType);
					}
				}
				f2.open(text);
				for (int i = 0; i < N; i++)
				{
					f2 << _inf[i].GefNum() << " ";
					f2 << _inf[i].GefType() << " ";
					f2 << _inf[i].GefProduct() << " ";
					f2 << _inf[i].GefCharacteristic() << " ";
					f2 << _inf[i].GefGoods() << " ";
					if (i != N - 1)
					{
						f2 << _inf[i].GefCount() << "\n";
					}
					else
					{
						f2 << _inf[i].GefCount();
					}
				}
				f2.close();

				if (war > 0) {
					cout << "\nthe information has been edited.\n" << endl;
					war = 0;
					system("cls");
				}

				else cout << "\nYou have entered the line number incorrectly.\n" << endl;
				system("cls");
				break;
			}
			case 2:
			{
				system("cls");
				for (int i = 0; i < N; i++)
				{
					if (_inf[i].GefNum() == fNum)
					{
						war++;
						cout << "\nEnter new product: ";
						cin >> fProduct;
						_inf[i].SefProduct(fProduct);
					}
				}
				f2.open(text);
				for (int i = 0; i < N; i++)
				{
					f2 << _inf[i].GefNum() << " ";
					f2 << _inf[i].GefType() << " ";
					f2 << _inf[i].GefProduct() << " ";
					f2 << _inf[i].GefCharacteristic() << " ";
					f2 << _inf[i].GefGoods() << " ";
					if (i != N - 1)
					{
						f2 << _inf[i].GefCount() << "\n";
					}
					else
					{
						f2 << _inf[i].GefCount();
					}
				}
				f2.close();

				if (war > 0) {
					cout << "\n the information has been edited.\n" << endl;
					war = 0;
					system("cls");
				}
				else cout << "\n You have entered the line number incorrectly.\n" << endl;
				break;
				system("cls");
			}
			case 3:
			{
				for (int i = 0; i < N; i++)
				{
					if (_inf[i].GefNum() == fNum)
					{
						war++;
						cout << "\nEnter new version: ";
						cin >> fCharacteristic;
						_inf[i].SefCharacteristic(fCharacteristic);
					}
				}
				f2.open(text);
				for (int i = 0; i < N; i++)
				{
					f2 << _inf[i].GefNum() << " ";
					f2 << _inf[i].GefType() << " ";
					f2 << _inf[i].GefProduct() << " ";
					f2 << _inf[i].GefCharacteristic() << " ";
					f2 << _inf[i].GefGoods() << " ";
					if (i != N - 1)
					{
						f2 << _inf[i].GefCount() << "\n";
					}
					else
					{
						f2 << _inf[i].GefCount();
					}
				}
				f2.close();

				if (war > 0) {
					cout << "\n the information has been edited.\n" << endl;
					war = 0;
					system("cls");
				}
				else cout << "\n You have entered the line number incorrectly.\n" << endl;
				system("cls");
				break;
			}
			case 4:
			{
				for (int i = 0; i < N; i++)
				{
					if (_inf[i].GefNum() == fNum)
					{
						war++;
						cout << "\nEnter new goods: ";
						cin >> fGoods;
						_inf[i].SefGoods(fGoods);
					}
				}
				f2.open(text);
				for (int i = 0; i < N; i++)
				{
					f2 << _inf[i].GefNum() << " ";
					f2 << _inf[i].GefType() << " ";
					f2 << _inf[i].GefProduct() << " ";
					f2 << _inf[i].GefCharacteristic() << " ";
					f2 << _inf[i].GefGoods() << " ";
					if (i != N - 1)
					{
						f2 << _inf[i].GefCount() << "\n";
					}
					else
					{
						f2 << _inf[i].GefCount();
					}
				}
				f2.close();

				if (war > 0) {
					cout << "\n the information has been edited.\n" << endl;
					war = 0;
					system("cls");
				}
				else cout << "\n You have entered the line number incorrectly.\n" << endl;
				system("cls");
				break;
			}
			case 5:
			{
				for (int i = 0; i < N; i++)
				{
					if (_inf[i].GefNum() == fNum)
					{
						war++;
						cout << "\nEnter new price: ";
						cin >> fCount;
						_inf[i].SefCount(fCount);
					}
				}
				f2.open(text);
				for (int i = 0; i < N; i++)
				{
					f2 << _inf[i].GefNum() << " ";
					f2 << _inf[i].GefType() << " ";
					f2 << _inf[i].GefProduct() << " ";
					f2 << _inf[i].GefCharacteristic() << " ";
					f2 << _inf[i].GefGoods() << " ";
					if (i != N - 1)
					{
						f2 << _inf[i].GefCount() << "\n";
					}
					else
					{
						f2 << _inf[i].GefCount();
					}
				}
				f2.close();

				if (war > 0) {
					cout << "\n the information has been edited.\n" << endl;
					war = 0;
					system("cls");
				}
				else cout << "\n You have entered the line number incorrectly.\n" << endl;
				system("cls");
				break;
			}
			case 6:
			{
				for (int i = 0; i < N; i++)
				{
					if (_inf[i].GefNum() == fNum)
					{
						war++;
						cout << "\nEnter new type: ";
						cin >> fType;
						cout << "\nEnter new product: ";
						cin >> fProduct;
						cout << "\nEnter new version: ";
						cin >> fCharacteristic;
						cout << "\nEnter new goods: ";
						cin >> fGoods;
						cout << "\nEnter new price: ";
						cin >> fCount;
						_inf[i].SefType(fType);
						_inf[i].SefProduct(fProduct);
						_inf[i].SefCharacteristic(fCharacteristic);
						_inf[i].SefGoods(fGoods);
						_inf[i].SefCount(fCount);

					}
				}
				f2.open(text);
				for (int i = 0; i < N; i++)
				{
					f2 << _inf[i].GefNum() << " ";
					f2 << _inf[i].GefType() << " ";
					f2 << _inf[i].GefProduct() << " ";
					f2 << _inf[i].GefCharacteristic() << " ";
					f2 << _inf[i].GefGoods() << " ";
					if (i != N - 1)
					{
						f2 << _inf[i].GefCount() << "\n";
					}
					else
					{
						f2 << _inf[i].GefCount();
					}
				}
				f2.close();

				if (war > 0) {
					cout << "\n the information has been edited.\n" << endl;
					war = 0;
					system("cls");
				}
				else cout << "\n You have entered the line number incorrectly.\n" << endl;
				system("cls");
				break;
			}
			}
			N = 0;
			pCount = 0;
			break;
		}
		case 8: {
			system("cls");
			cout << "\nEnd of the program.." << endl;

			return 1;
			break;
		}
		default: {
			system("cls");
			cout << "\nYou have entered an incorrect answer.\n" << endl;
			N = 0;
			pCount = 0;
			break;
		}
		}
				system("pause");
				system("cls");
		}
	} while (ask != 8);
	system("pause");
	return (0);
}