#pragma once

#include"Repository.h"
#include"Drone.h"
#include<string>
using namespace std;

class DroneRepository : public Repository<Drone>
{
protected:
	string GetFileName() { return "Out_drones.txt"; }
	string GetTitle() { return "Drones:"; }
public:
	DroneRepository(int max) : Repository(max) {}

	~DroneRepository()
	{
		WriteToFile();
	}

};