#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "Stack.h"
using namespace ds;

int main()
{
	srand(time(NULL));
	ds::Stack<int> stack;
	std::string output, input;
	
	input = "{";
	for(int i = 0;i < 10;i += 1)
	{
		stack.Push((rand() % 24 + 5));
		input += stack.ToString() + ",";
	}
	input[input.length()-1] = '}';

	std::cout << "Inputs: " << input << "\n";

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
