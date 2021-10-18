#ifndef PROCESSING_H
#define PROCESSING_H
#include "Drone.h"
#include "Robot.h"
#include "DroneRepository.h"
#include "RobotRepository.h"
class Processing {
	DroneRepository droneRepository;
	RobotRepository robotRepository;
	
public:
	Processing(int max_value = 100);
	~Processing();

	void AddDrone(Drone& drone);
	void RemoveDrone(int index);
	void PrintDrone();
	void ReadDroneFromFile();
	void GetMostPopularDroneBrand();
	void GetTheCheapestDrone();
	void GetQuantityOfDronesMadeThisYear(int year);
	Drone& GetBiggerQuantity(Drone& drone1, Drone& drone2);
	

	void AddRobot(Robot& robot);
	void RemoveRobot(int index);
	void PrintRobot();
	void ReadRobotFromFile();
	void GetMostPopularRobotBrand();
	void GetTheCheapestRobot();
	void GetQuantityOfRobotMadeThisYear(int year);
	Robot& GetBiggerQuantity(Robot& robot1, Robot& robot2);
	
};
#endif