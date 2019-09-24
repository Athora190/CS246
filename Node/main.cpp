#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Node.h"
using namespace ds;

template<class T>
void append(Node<T>*& root,const T& data)
{
	if(root == NULL)
	{
		root = new Node<T>(data);
	}
	else
	{
		Node<T>* tmp = root;
		
		while(tmp->GetLink() != NULL)
		{
			tmp = tmp->GetLink();
		}
		
		tmp->SetLink(new Node<T>(data));
	}
}

template <class T>
void traverse(Node<T>* root)
{
	Node<T>* tmp = root;
	std::cout << "[";

	while(tmp != NULL)
	{
		std::cout << tmp->GetData();
		
		if(tmp->GetLink() != NULL)
		{
			std::cout << ",";
		}
		tmp = tmp->GetLink();
	}
	std::cout << "]";
}

int main()
{
	srand(time(NULL));
	ds::Node<int>* value = NULL;

	for(int i = 0;i < 10;i += 1)
	{
		append(value,(rand() % 24 + 5));
		traverse(value);
		std::cout << "\n";
	}

	return 0;
}
