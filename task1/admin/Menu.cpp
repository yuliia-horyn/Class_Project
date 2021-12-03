#include "Menu.h"
#include "Drone.h"
#include "Processing.h"
#include "Error.h"
#include "Repository.h"
#include <iostream>
#include <string>
#include <vector>
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
	cout << "1 - Add new drone;\n";
	cout << "2 - Print drones;\n";
	cout << "3 - Remove drone;\n";
	cout << "a - Add new robot;\n";
	cout << "b - Print robots;\n";
	cout << "c - Remove robot;\n";
	cout << "4 - Get most popular drone and robot brand;\n";
	cout << "5 - Get the cheapest drone and robot;\n";
	cout << "6 - Get information\n";
	cout << "7 - Show quantity of drones and robots made in this yeah\n";
	cout << "8 - Get biggest quantity among two drones\n";
	cout << "9 - Just to show that operator [] works\n";
	cout << "0 - Exit.\n";
}

void Menu::showAndHadnleAddDroneMenu()
{

	cout << "Enter the property of drone using space: " << endl;
	Drone drone;
	cin >> drone;
	processing.AddDrone(drone);
	cout << "Drone added!\n";

}
void Menu::showAndHadnleAddRobotMenu()
{
	cout << "Enter the property of robot using space: " << endl;
	Robot robot;
	cin >> robot;
	processing.AddRobot(robot);
	cout << "Robot added!\n";
}
void Menu::showAndHadnleRemoveDroneMenu()
{
	int index;
	cout << "Input drone index\n";
	cin >> index;
	processing.RemoveDrone(index);
	cout << "Drone removed!\n";
}
void Menu::showAndHadnleRemoveRobotMenu()
{
	int index;
	cout << "Input robot index\n";
	cin >> index;
	processing.RemoveRobot(index);
	cout << "Robot removed!\n";
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
	Drone drone1("Fly", "tp231", 2019, 25000, 3421);
	Drone drone2("WL toys", "cr212", 2019, 30000, 2451);
	Drone drone3("WL toys", "cw110", 2020, 35000, 1087);
	Drone drones[] = { drone1,drone2,drone3 };
	vector<Information*> inf;
	switch (user_input)
	{
	case '1':
		showAndHadnleAddDroneMenu();
		break;
	case '2':
		processing.PrintDrone();
		cout << endl;
		break;
	case '3':
		showAndHadnleRemoveDroneMenu();
		break;
	case 'a':
		showAndHadnleAddRobotMenu();
		break;
	case 'b':
		processing.PrintRobot();
		cout << endl;
		break;
	case 'c':
		showAndHadnleRemoveRobotMenu();
		break;
	case '4':
		cout << "Most popular drone brand is ";
		processing.GetMostPopularDroneBrand();
		cout << "\nMost popular drone robot is ";
		processing.GetMostPopularRobotBrand();
		break;
	case '5':
		cout << "Most cheapest drone cost ";
		processing.GetTheCheapestDrone();
		cout << "\nMost cheapest robot cost ";
		processing.GetTheCheapestRobot();
		break;
	case '6':
		
		int choice;
		cout << "Enter 1 to get information as user or 2 to get information as admin"<<endl;
		cin >> choice;	
		inf.push_back(Information::show_info(choice));
		
		for (int i = 0; i < inf.size(); i++) {
			inf[i]->get_c();
		}
		for (int i = 0; i < inf.size(); i++) {
			delete inf[i];
		}
		break;
	case '7':
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
	case '8':
		cout << "Bigger quantity " << processing.GetBiggerQuantity(drone1, drone2) << endl;
		break;
	case '9':
		int idx;
		cout << "Input index from 0 to 2 to get the element of array\n";
		cin >> idx;
		cout << drones[idx] << endl;
		break;
	case '0':
		break;
	default:
		cout << "Wrong command selected\n";
		break;
	}
}