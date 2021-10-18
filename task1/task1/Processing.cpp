#include "Processing.h"
#include "Drone.h"
#include "Error.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

Processing::Processing(int max_value): droneRepository(max_value), robotRepository(max_value)
{
	ReadDroneFromFile();
	ReadRobotFromFile();
}
Processing::~Processing()
{
}

void Processing::AddDrone(Drone& drone)
{
	droneRepository.Add(drone);
}

void Processing::RemoveDrone(int index)
{
	droneRepository.Remove(index);
}
void Processing::PrintDrone()
{
	droneRepository.Print();
}
void Processing::AddRobot(Robot& robot)
{
	robotRepository.Add(robot);
}

void Processing::RemoveRobot(int index)
{
	robotRepository.Remove(index);
}
void Processing::PrintRobot()
{
	robotRepository.Print();
}
void Processing::ReadDroneFromFile()
{
	string text;
	ifstream MyReadDrones("In_drones.txt");
	while (getline(MyReadDrones, text)) {
		int index = 0;
		int k = 0;
		index = text.find(".", index + 1);
		string brand1 = text.substr(k, index - k);
		k = index+2;
		index = text.find(".", index + 1);
		string model1 = text.substr(k, index - k);
		k = index+2;
		index = text.find(".", index + 1);
		string y = text.substr(k, index - k);
		int year1 = stoi(y);
		k = index+2;
		index = text.find(".", index + 1);
		string p = text.substr(k, index - k);
		int price1 = stoi(p);
		k = index+2;
		index = text.find(".", index + 1);
		string q = text.substr(k, index - k);
		int quantity1 = stoi(q);
		Drone drone1(brand1, model1, year1, price1, quantity1);
		droneRepository.Add(drone1);
	}
	MyReadDrones.close();
}

void Processing::ReadRobotFromFile()
{
	string text;
	ifstream MyReadRobot("In_robot.txt");
	while (getline(MyReadRobot, text)) {
		int index = 0;
		int k = 0;
		index = text.find(".", index + 1);
		string brand1 = text.substr(k, index - k);
		k = index + 2;
		index = text.find(".", index + 1);
		string function1 = text.substr(k, index - k);
		k = index + 2;
		index = text.find(".", index + 1);
		string y = text.substr(k, index - k);
		int year1 = stoi(y);
		k = index + 2;
		index = text.find(".", index + 1);
		string p = text.substr(k, index - k);
		int price1 = stoi(p);
		k = index + 2;
		index = text.find(".", index + 1);
		string q = text.substr(k, index - k);
		int quantity1 = stoi(q);
		Robot robot1(brand1, function1, year1, price1, quantity1);
		robotRepository.Add(robot1);
	}
	MyReadRobot.close();
}
Drone& Processing::GetBiggerQuantity(Drone& drone1, Drone& drone2) {
	if (drone1 != drone2) {
		if (drone1 > drone2) {
			return drone1;
		}
		else {
			return drone2;
		}
	}
}
Robot& Processing::GetBiggerQuantity(Robot& robot1, Robot& robot2) {
	if (robot1 != robot2) {
		if (robot1 > robot2) {
			return robot1;
		}
		else {
			return robot2;
		}
	}
}
void Processing::GetMostPopularDroneBrand() {
	cout << droneRepository.GetMostPopularDroneBrand();
}
void Processing::GetTheCheapestDrone() {
	cout << droneRepository.GetTheCheapestDrone();
}
void Processing::GetQuantityOfDronesMadeThisYear(int year) {
	cout << droneRepository.GetQuantityOfDronesMadeThisYear(year);
}
void Processing::GetMostPopularRobotBrand() {
	cout << robotRepository.GetMostPopularDroneBrand();
}
void Processing::GetTheCheapestRobot() {
	cout << robotRepository.GetTheCheapestDrone();
}
void Processing::GetQuantityOfRobotMadeThisYear(int year1) {
	cout << robotRepository.GetQuantityOfRobotMadeThisYear(year1);
}