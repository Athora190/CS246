#include <iostream>
#include "LinkedList.h"
using namespace ds;

int main()
{
	LinkedList<double> list;

	list.InsertInFront(23);
	list.InsertInBack(5);
	list.InsertInBack(78);

	std::cout << list << "\n";

	list.Remove(5);

	std::cout << list << "\n\n";
 	
	return 0;
}
