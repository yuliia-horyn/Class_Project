#pragma once

#include"Repository.h"
#include"Drone.h"
#include<string>
using namespace std;

class DroneRepository : public Repository<Drone>
{
protected:
	string GetFileName() { return "C:\\Users\\goryn\\Documents\\projects\\Class_Project\\task1\\x64\\Debug\\Out_drones.txt"; }
	string GetTitle() { return "Drones:"; }
public:
	DroneRepository(int max) : Repository(max)
	{
		ReadFromFile();
	}

	~DroneRepository()
	{
		WriteToFile();
	}

};