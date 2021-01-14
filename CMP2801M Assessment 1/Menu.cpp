#include <String>
#include <sstream>
#include <iostream>
#include <fstream>
#include "Item.h"
#include "Menu.h"

Menu::Menu(std::string menu) {
	loadMenu(menu);
}

Item * Menu::getItem(int index) {
	if (index > 0 && index <= items.size())
		return items[index - 1];
	return NULL;
}

void Menu::loadMenu(std::string menu) {
	std::ifstream file(menu);
	std::string line;
	Appetiser * app;
	MainCourse * main;
	Beverage * bev;
	std::string identifier;
	std::string data;
	int count;
	while (getline(file, line)) {
		count = -1;
		identifier = line.substr(0, line.find(','));
		line.erase(0, 2);
		if (identifier == "a") {
			app = new Appetiser();
			while (line.size() > 0) {
				count++;
				data = line.substr(0, line.find(','));
				line.erase(0, data.size() + 1);
				if (count == 0)
					app->setName(data);
				else if (count == 1)
					app->setPrice(std::stof(data));
				else if (count == 2)
					app->setCalories(std::stoi(data));
				else if (count == 3)
					app->setShareable(data == "y");
				else if (count == 4)
					app->setTwoForOne(data == "y");
			}
			items.push_back(app);
		}
		else if (identifier == "m") {
			main = new MainCourse();
			while (line.size() > 0) {
				count++;
				data = line.substr(0, line.find(','));
				line.erase(0, data.size() + 1);
				if (count == 0)
					main->setName(data);
				else if (count == 1)
					main->setPrice(std::stof(data));
				else if (count == 2)
					main->setCalories(std::stoi(data));
			}
			items.push_back(main);
		}
		else if (identifier == "b") {
			bev = new Beverage();
			while (line.size() > 0) {
				count++;
				data = line.substr(0, line.find(','));
				line.erase(0, data.size() + 1);
				if (count == 0)
					bev->setName(data);
				else if (count == 1)
					bev->setPrice(std::stof(data));
				else if (count == 2)
					bev->setCalories(std::stoi(data));
				else if (count == 5)
					bev->setAbv(std::stof(data));
				else if (count == 6)
					bev->setVolume(std::stoi(data));
			}
			items.push_back(bev);
		}
	}
}

std::string Menu::toString() {
	std::ostringstream returnStream;
	returnStream << "----------MENU----------\n";
	returnStream << Menu::ItemList::toString();
	return returnStream.str();
}