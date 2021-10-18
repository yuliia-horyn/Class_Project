#pragma once
#include"Repository.h"
#include"Robot.h"
#include<string>
using namespace std;

class RobotRepository : public Repository<Robot>
{
protected:
	string GetFileName() { return "Out_robot.txt"; }
	string GetTitle() { return "Robot:"; }
public:
	RobotRepository(int max) : Repository(max) {}

	~RobotRepository()
	{
		WriteToFile();
	}
};