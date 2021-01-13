#include <string>
#include <sstream>
#include "Item.h"
#include <iostream>


Item::Item() {
	name = "";
	calories = 0;
	price = 0.0f;
}

std::string Item::toString() {
	std::ostringstream returnStream;
	returnStream << "> " << name << " -- " << calories << "kcal -- $";
	std::string price = std::to_string(Item::price).substr(0, std::to_string(Item::price).find(".") + 3);

	returnStream << price;

	return returnStream.str();
}

void Item::setName(std::string name) {
	Item::name = name;
}

void Item::setPrice(float price) {
	Item::price = price;
}

void Item::setCalories(int calories) {
	Item::calories = calories;
}

Appetiser::Appetiser() {
	shareable = false;
	twoForOne = false;
}

std::string Appetiser::toString() {
	std::ostringstream returnStream;
	returnStream << Appetiser::Item::toString();
	if (shareable)
		returnStream << " -- Share Dish";
	if (twoForOne)
		returnStream << " -- Two For One";
	return returnStream.str();
}

void Appetiser::setShareable(bool shareable) {
	Appetiser::shareable = shareable;
}

void Appetiser::setTwoForOne(bool twoForOne) {
	Appetiser::twoForOne = twoForOne;
}

Beverage::Beverage() {
	abv = 0.0f;
	volume = 0;
}

std::string Beverage::toString() {
	std::ostringstream returnStream;
	returnStream << Beverage::Item::toString();
	returnStream << " -- AbV " << abv << "% -- " << volume << " mL";
	return returnStream.str();
}

bool Beverage::isAlcoholic() {
	return (abv != 0);
}

void Beverage::setAbv(float abv) {
	Beverage::abv = abv;
}

void Beverage::setVolume(int volume) {
	Beverage::volume = volume;
}

MainCourse::MainCourse() {};