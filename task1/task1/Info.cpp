#include "Info.h"
#include <string>
#include<iostream>
using namespace std;

Info::Info(string phone, string address_of_production, string address_of_shops, string email) {
	this->phone = phone;
	this->address_of_production = address_of_production;
	this->address_of_shops = address_of_shops;
	this->email = email;

}
string Info::toStr()
{
	return "Information for user: \n1)Phone: " + phone + " \n2)Address of production: " + address_of_production + " \n3)Address of shops: " + address_of_shops + " \n4)E-mail: "+email;
}
Info info("+380964680466", "Lviv, Chervonoyi Kalyny 46", "Lviv, M.Dragomanov57", "drones13@gmail.com");
void Info:: PrintInfo() {
	
	cout << info.toStr();
}
