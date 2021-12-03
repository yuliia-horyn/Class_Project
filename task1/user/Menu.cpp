#include "Menu.h"
#include "Drone.h"
#include "Processing.h"
#include "Error.h"
#include "Repository.h"
#include <iostream>
#include <string>
#include<vector>
#include "Info.h"
using namespace std;

void Menu::ShowMenu()
{
	char user_input;
	do {
		showMainMenu();
		cin >> user_input;
		safeHandleUserInput(user_input);
		cout << endl;
	} while (user_input != '0');
}

void Menu::showMainMenu()
{
	cout << "Production of robots and drones\nPlease choose the option:\n";
	cout << "1 - Print drones;\n";
	cout << "2 - Print robots;\n";
	cout << "3 - Get the cheapest drone and robot;\n";
	cout << "4 - Show quantity of drones and robots made in this yeah\n";
	cout << "5 - Get information\n";
	cout << "0 - Exit.\n";
}

void Menu::safeHandleUserInput(char user_input)
{
	try
	{
		handleUserInput(user_input);
	}
	catch (Error& error)
	{
		cout << "Error occurs: " << error.to_str() << endl;
	}
	catch (...)
	{
		cout << "Some error occurs" << endl;
	}
}

void Menu::handleUserInput(char user_input)
{
	vector<Information*> inf;
	switch (user_input)
	{
	
	case '1':
		processing.PrintDrone();
		cout << endl;
		break;
	case '2':
		processing.PrintRobot();
		cout << endl;
		break;
	case '3':
		cout << "Most cheapest drone cost ";
		processing.GetTheCheapestDrone();
		cout << "\nMost cheapest robot cost ";
		processing.GetTheCheapestRobot();
		break;
	case '4':
		int year2;
		cout << "Show quantity of drones made in this yeah" << endl;
		cout << "Type the year you want \n";
		cin >> year2;
		cout << "In this year was made ";
		processing.GetQuantityOfDronesMadeThisYear(year2);
		cout << " drones" << endl;
		int year3;
		cout << "Show quantity of robots made in this yeah" << endl;
		cout << "Type the year you want \n";
		cin >> year3;
		cout << "In this year was made ";
		processing.GetQuantityOfRobotMadeThisYear(year3);
		cout << " robots" << endl;
		break;
	case '5':
		int choice;
		cout << "Enter 1 to get information as user or 2 to get information as admin";
		cin >> choice;
			
		inf.push_back(Information::show_info(choice));
		
		for (int i = 0; i < inf.size(); i++) {
			inf[i]->get_c();
		}
		for (int i = 0; i < inf.size(); i++) {
			delete inf[i];
		}
		break;
		break;
	case '0':
		break;
	default:
		cout << "Wrong command selected\n";
		break;
	}
}