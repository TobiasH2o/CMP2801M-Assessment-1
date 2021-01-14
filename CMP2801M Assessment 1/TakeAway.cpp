/* ------------------------------------------------------
CMP2801M: Advanced Programming
Driver program for "Takeaway" assignment
Autumn 2020

Written by James Brown

This file is a representative test file.
During marking, we will use the exact same notation
as provided in the brief, so make sure you follow that guideline.
Also make sure that you don't modify the code provided here,
but instead add what you need to complete the tasks.

Good luck!
------------------------------------------------------ */
#define _CRT_SECURE_NO_WARNINGS

#include "Menu.h"
#include "Order.h"
#include "Item.h"

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
	string userCommand;
	vector <string> parameters;

	// Create a menu object from a CSV file
	Menu menu = Menu("menu.csv");

	// Create an order object
	Order order = Order();

	while (userCommand != "exit")
	{
		getline(cin, userCommand);
		char* cstr = new char[userCommand.length() + 1];
		strcpy(cstr, userCommand.c_str());

		char* token;
		token = strtok(cstr, " ");

		//Clears console
		system("CLS");

		while (token != NULL)
		{
			parameters.push_back(token);
			token = strtok(NULL, " ");
		}

		// Stops crashing if no input is provided
		string command = "skip";
		if (parameters.size() > 0)
			command = parameters[0];

		if (command.compare("menu") == 0) {
			cout << menu.toString();
		}
		else if (command.compare("add") == 0)
		{
			int number = 1;
			if (parameters.size() > 1) {
				for (int i = 1; i < parameters.size(); i++) {
					Item* choice = menu.getItem(std::stoi(parameters[i])); // you need to instantiate this using the menu object!
					if (choice != NULL) {
						order.add(choice);
					}
				}
			}
			else {
				cout << menu.toString();
				cout << "> You must specify a menu item" << endl;
			}

		}
		else if (command.compare("remove") == 0)
		{
		
		}
		else if (command.compare("checkout") == 0)
		{
			cout << order.toString();
		}
		else if (command.compare("help") == 0) {
			std::cout << "#################################################" << std::endl;
			std::cout << "#> Restraunt Ordering                           #" << std::endl;
			std::cout << "#> To view the menu type 'menu'                 #" << std::endl;
			std::cout << "#> To finish your order type 'checkout'         #" << std::endl;
			std::cout << "#> To exit type 'exit'                          #" << std::endl;
			std::cout << "#> To add an item to your order type 'add'      #" << std::endl;
			std::cout << "#> followed by the item numbers                 #" << std::endl;
			std::cout << "#> e.g. add 1 5 3 7                             #" << std::endl;
			std::cout << "#> To remove an item type 'remove'              #" << std::endl;
			std::cout << "#> followed by the item and number              #" << std::endl;
			std::cout << "#> e.g. remove 2 1                              #" << std::endl;
			std::cout << "#################################################" << std::endl;
		}

		if (parameters.size() > 0)
			parameters.clear();

	}

	cout << "Press any key to quit...";
	std::getchar();

}