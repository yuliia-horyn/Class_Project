#ifndef INFO_H
#define INFO_H
#include<string>
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
	void PrintInfo();
};
#endif 
