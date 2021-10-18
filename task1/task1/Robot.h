#ifndef ROBOT_H
#define ROBOT_H

#include<iostream>
#include<string>
#include "Error.h"
using namespace std;

class Robot
{
private:
	string brand;
	string function;
	int year;
	int price;
	int quantity;
public:
	Robot(string brand="", string function="", int p_year=0, int p_price=0, int p_quantity=0)
	{
		this->brand = brand;
		this->function = function;
		if (p_year < 0 || p_year > 2021)
			throw Error(ErrorCode::Incorrect_year);
		year = p_year;
		if (p_price < 0)
			throw Error(ErrorCode::Incorrect_price);
		price = p_price;
		if (p_quantity < 0)
			throw Error(ErrorCode::Incorrect_quantity);
		quantity = p_quantity;
	}
	
	string to_str()
	{
		return "Robot: " + brand + " " + function + " " + to_string(year) + " " + to_string(price) + " " + to_string(quantity);
	}
	string GetBrand()
	{
		return brand;
	}
	int GetPrice()
	{
		return price;
	}
	int GetYear()
	{
		return year;
	}
	int GetQuantity()
	{
		return quantity;
	}
	ostream& operator<<(ostream& out)
	{
		return out << brand << " " << function << " " << year << " " << price << " " << quantity << "\n";
	}

	friend ostream& operator<<(ostream& out, Robot& robot)
	{
		return robot << cout;
	}
	friend istream& operator>>(istream& in, Robot& robot)
	{
		char* brand = new char[50];
		char* function = new char[50];
		int year;
		int price;
		int quantity;

		in >> brand >> function >> year >> price >> quantity;

		robot = Robot(brand, function, year, price, quantity);

		return in;
	}
	friend bool operator== (const Robot& robot1, const Robot& robot2)
	{
		return (robot1.brand == robot2.brand &&
			robot1.function == robot2.function && robot1.year == robot2.year && robot1.price == robot2.price && robot1.quantity == robot2.quantity);
	}
	friend bool operator!=(const Robot& robot1, const Robot& robot2) {
		return !(robot1 == robot2);
	}
	bool operator>(Robot& robot)
	{
		return this->quantity > robot.quantity;
	}
};

#endif 


