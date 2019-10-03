#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "StaticQueue.h"
using namespace ds;

int main()
{
	srand(time(NULL));
	ds::StaticQueue<int> queue;
	std::string output, input;
	int value;

	input = "{";
	for(int i = 0;i < 10;i += 1)
	{
		value = rand() % 24 + 5;
		queue.Enqueue(value);
		input += std::to_string(value) + ",";
	}
	input[input.length()-1] = '}';
	
	std::cout << "Inputs: " << input << "\n";

	output = "{";
	while(!queue.IsEmpty())
	{
		output += queue.ToString() + ",";
		queue.Dequeue();
	}
	output[output.length()-1] = '}';
	
	std::cout << "Outputs: " << output << "\n";
 
	return 0;
}
