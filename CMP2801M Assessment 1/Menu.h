#pragma once
#ifndef Menu_h
#define Menu_h
#include "Item.h"
#include <vector>
#include <string>
#include <iostream>

class Menu : public ItemList {
public:
	Menu(std::string fileLocation);
	std::string toString();
};

#endif Menu_h
