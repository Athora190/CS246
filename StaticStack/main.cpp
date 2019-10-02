#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "StaticStack.h"
using namespace ds;

int main()
{
	srand(time(NULL));
	ds::StaticStack<int> stack;
	std::string output, input;
	int value;

	input = "{";
	for(int i = 0;i < 10;i += 1)
	{
		value = rand() % 24 + 5;
		stack.Push(value);
		input += std::to_string(value) + ",";
	}
	input[input.length()-1] = '}';

	std::cout << "Inputs: " << input << "\n";

	std::cout << value << "\n";

	output = "{";
	while(!stack.IsEmpty())
	{
		output += stack.ToString() + ",";
		stack.Pop();
	}
	output[output.length()-1] = '}';
	
	std::cout << "Outputs: " << output << "\n";
 
	return 0;
}
