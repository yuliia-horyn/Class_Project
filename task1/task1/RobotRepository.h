#pragma once
#include"Repository.h"
#include"Robot.h"
#include<string>
using namespace std;

class RobotRepository : public Repository<Robot>
{
protected:
	string GetFileName() { return "C:\\Users\\goryn\\Documents\\projects\\Class_Project\\task1\\x64\\Debug\\Out_robot.txt"; }
	string GetTitle() { return "Robot:"; }
public:
	RobotRepository(int max) : Repository(max)
	{
		ReadFromFile();
	}

	~RobotRepository()
	{
		WriteToFile();
	}
};