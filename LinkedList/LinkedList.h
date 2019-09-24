#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <sstream>
#include "Node.h"

namespace ds
{
	template <class T>
	class LinkedList
	{
	private:
		Node<T>* front;
		Node<T>* back;
	public:
		LinkedList() : front(NULL), back(NULL) {}

		~LinkedList() 
		{
			Node<T>* tmp;

			while(front != NULL)
			{
				tmp = front;
				front = front->GetLink();
				delete tmp;
				tmp = NULL;
			}
		}

		std::string ToString() const
		{
			std::stringstream out;
			out << data;
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const LinkedList<T>& obj)
		{
			out << obj.ToString();
			return out;
		}
	};
}
		
#endif
