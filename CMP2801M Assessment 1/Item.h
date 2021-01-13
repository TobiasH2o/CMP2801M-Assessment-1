#pragma once
#ifndef Item_h
#define Item_h
#include <string>
#include <vector>

class Item {
protected:
	std::string name;
	int calories;
	float price;
public:
	Item();
	std::string toString();
	void setName(std::string name);
	void setPrice(float price);
	void setCalories(int calories);
};

class Appetiser : public Item{
private:
	bool shareable;
	bool twoForOne;
public:
	Appetiser();
	std::string toString();
	void setShareable(bool shareable);
	void setTwoForOne(bool twoForOne);
};

class MainCourse : public Item {
public:
	MainCourse();
};

class Beverage : public Item {
private:
	float abv;
	int volume;
public:
	Beverage();
	std::string toString();
	bool isAlcoholic();
	void setAbv(float abv);
	void setVolume(int volume);
};

class ItemList{
protected:
	std::vector<Item> items;
public:
	ItemList();
	virtual std::string toString() = 0;
};

#endif