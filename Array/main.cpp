#include <iostream>
#include "Array.h"

int main()
{
	ds::Array<int> values(20);
	values.Fill(120);
	std::cout << values << "\n";

	return 0;
}
