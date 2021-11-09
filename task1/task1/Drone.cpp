#include "Drone.h"
#include"Error.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

Drone::Drone(string brand, string model , int p_year, int p_price, int p_quantity)
{
	this->brand = brand;
	this->model = model;
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

string Drone::to_str()
{
	return  brand + " " + model + " " + to_string(year) + " " + to_string(price) + " " + to_string(quantity);
}

 string Drone::GetBrand()
{
	return brand;
}
int Drone::GetPrice()
{
	return price;
}
int Drone::GetYear()
{
	return year;
}
int Drone::GetQuantity()
{
	return quantity;
}
ostream& Drone::operator<<(ostream& out)
{
	return out << brand << " " << model << " " << year << " " << price << " " << quantity << "\n";
}

ostream& operator<<(ostream& out, Drone& drone)
{
	return drone << cout;
}
istream& operator>>(istream& in, Drone& drone)
{
	char* brand = new char[50];
	char* model = new char[50];
	int year;
	int price;
	int quantity;

	in >> brand >> model >> year >> price >> quantity;

	drone = Drone(brand, model, year, price, quantity);

	return in;
}
bool operator== (const Drone& drone1, const Drone& drone2)
{
	return (drone1.brand == drone2.brand &&
		drone1.model == drone2.model && drone1.year == drone2.year && drone1.price == drone2.price && drone1.quantity == drone2.quantity);
}
bool operator!=(const Drone& drone1, const Drone& drone2){
	return !(drone1 == drone2);
}
bool Drone::operator>(Drone& drone)
{
	return this->quantity > drone.quantity;
}
ifstream& operator>>(ifstream& fin, Drone& drone)
{
	int max = 100;
	char* buff = new char[max + 1];

	fin.get(buff, max, ' ');
	drone.brand = buff;
	fin.get();

	fin.get(buff, max, ' ');
	drone.model = buff;
	fin.get();

	fin.get(buff, max, ' ');
	drone.year = atoi(buff);
	fin.get();

	fin.get(buff, max, ' ');
	drone.price = atoi(buff);
	fin.get();

	fin.getline(buff, max);
	drone.quantity = atoi(buff);

	delete[] buff;
	return fin;
}
