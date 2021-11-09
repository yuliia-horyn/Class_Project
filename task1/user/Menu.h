#ifndef MENU_H
#define MENU_H

#include"Processing.h"
class Menu
{
public:
	void ShowMenu();

private:
	Processing processing;
	void showMainMenu();
	void handleUserInput(char user_input);
	void safeHandleUserInput(char user_input);
};
#endif 
