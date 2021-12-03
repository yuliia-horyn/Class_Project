#ifndef INFO_H
#define INFO_H
#include<string>
#include<iostream>
using namespace std;
class Info
{
private:
	string phone;
	string address_of_production;
	string address_of_shops;
	string email;
public:
	Info(string phone = "", string address_of_production = "", string address_of_shops = "", string email = "");
	string toStr();
	string toStr1();
	
};
Info::Info(string phone, string address_of_production, string address_of_shops, string email) {
	this->phone = phone;
	this->address_of_production = address_of_production;
	this->address_of_shops = address_of_shops;
	this->email = email;

}
string Info::toStr()
	{
		return "Information for user: \n1)Phone: " + phone +  "\n2)Address of shops : " + address_of_shops + " \n3)E - mail: " + email;
	}
string Info::toStr1()
{
	return "Information for admin: \n1)Phone: " + phone + " \n2)Address of production: " + address_of_production + " \n3)E-mail: " + email;
}
class Information {
public:
	static Information *show_info(int choice);
	virtual void get_c() = 0;
};
class User_info: public Information
{
public:
	
	void get_c() {
		Info info_u("+380673754392", "","Lviv, M.Dragomanov57", "drones_for_question13@gmail.com");
		cout << info_u.toStr();
	}
};
class Admin_info : public Information
{
public:

	void get_c() {
		Info info_a("+380964680467","Lviv, Chervonoyi Kalyny 46","", "drones_for_employees13@gmail.com");
		cout << info_a.toStr1();
	}
};
Information* Information::show_info(int choice) {
	if (choice == 1)
		return new User_info;
	else 
		return new Admin_info;
}
#endif 
