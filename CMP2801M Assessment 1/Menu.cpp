#include <String>
#include <iostream>
#include <fstream>
#include "Item.h"
#include "Menu.h"

	Menu :: Menu(std::string menu) {
		std::ifstream file(menu);
		std::string line;
		Appetiser app;
		MainCourse main;
		Beverage bev;
		std::string identifier;
		std::string data;
		int count;
		while(getline(file, line)){
			count = -1;
			identifier = line.substr(0, line.find(','));
			line.erase(0, 2);
			if (identifier == "a") {
				while (line.size() > 0) {
					count++;
					data = line.substr(0, line.find(','));
					line.erase(0, data.size() + 1);
					if (count == 0)
						app.setName(data);
					else if (count == 1)
						app.setPrice(std::stof(data));
					else if (count == 2)
						app.setCalories(std::stoi(data));
					else if (count == 3)
						app.setShareable(data == "y");
					else if (count == 4)
						app.setTwoForOne(data == "y");
				}
				items.push_back(app);
			}
			else if(identifier == "m")
				while (line.size() > 0) {
					count++;
					data = line.substr(0, line.find(','));
					line.erase(0, data.size() + 1);
					if (count == 0)
						main.setName(data);
					else if (count == 1)
						main.setPrice(std::stof(data));
					else if (count == 2)
						main.setCalories(std::stoi(data));
				}

			else if(identifier == "b")
				while (line.size() > 0) {
					count++;
					data = line.substr(0, line.find(','));
					line.erase(0, data.size() + 1);
					if (count == 0)
						bev.setName(data);
					else if (count == 1)
						bev.setPrice(std::stof(data));
					else if (count == 2)
						bev.setCalories(std::stoi(data));
					else if (count == 3)
						bev.setAbv(std::stof(data));
					else if (count == 4)
						bev.setVolume(std::stoi(data));
				}
		}
	}

	

	std::string Menu::toString() {
		std::string returnString = "----------MENU----------\n";
		for (int i = 0; i < items.size(); i++) {
			returnString += items[i].toString() + "\n";
		}
		return returnString;
	}