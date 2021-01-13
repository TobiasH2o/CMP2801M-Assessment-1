#include "Item.h"
#include <string>
#include <sstream>

ItemList::ItemList()
{
}

std::string ItemList::toString() {
	std::ostringstream returnStream;
	for (int i = 0; i < items.size(); i++) {
		returnStream << items[i].toString() << "\n";
	}
	return returnStream.str();
}