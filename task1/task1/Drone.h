#ifndef DRONE_H
#define DRONE_H

#include<string>
using namespace std;

class Drone
{
private:
	string brand; 
	string model;
	int year;
	int price;
	int quantity;
public:
	Drone(string brand = "", string model = "", int year = 0, int price = 0, int quantity = 0);
	string to_str();
	string GetBrand();
	int GetYear();
	int GetPrice();
	int GetQuantity();
	
	ostream& operator<<(ostream& out);
	friend ostream& operator<<(ostream& out, Drone& drone);
	friend istream& operator>>(istream& in, Drone& drone);
	friend bool operator== (const Drone& drone1, const Drone& drone2);
	friend bool operator!=(const Drone& drone1, const Drone& drone2);
	bool operator>(Drone& drone);
	friend ifstream& operator>>(ifstream& fin, Drone& drone);
};

#endif 
