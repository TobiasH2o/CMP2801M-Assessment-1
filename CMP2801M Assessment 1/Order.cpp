#include <String>
#include <vector>
#include <iostream>
#include "Item.h"
#include "Order.h"

	Order::Order() {
		total = 0.0f;
	}

	void Order::add(Item * item) {
		items.push_back(item);
	}

	void Order::remove(int index) {
	}

	std::string Order::toString() {
		calculateTotal();
		return ItemList::toString();
	}

	float Order::calculateTotal()
	{
		int total = 0;
		int twoForOne = 0;
		for (int i = 0; i < items.size(); i++) {
			total += items[i]->getPrice();
			if (dynamic_cast<Appetiser*>(items[i])) {};
		}
		return 0.0f;
	}

	void Order::printReciept() {

	}
