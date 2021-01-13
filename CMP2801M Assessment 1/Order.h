#pragma once
#ifndef Order_h
#define Order_h

class Order : public ItemList{
private:
	float total;
public:
	Order();
	void add(Item * item);
	void remove(int index);
	std::string toString();
	float calculateTotal();
	void printReciept();
};

#endif