#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
#include <sstream>
#include "Node.h"

namespace ds
{
	template <class T>
	class Stack
	{
	private:
		Node<T>* head;
	public:
		Stack() : head(NULL) {}

		Stack(const Stack<T>& obj)
		{
			head = Copy(obj.head);
		}

		Stack<T>& operator=(const Stack<T>& rhs)
		{
			if(this != &rhs)
			{
				Clear(head);
				head = Copy(rhs.head);
			}

			return *this;			
		}

		~Stack() 
		{
			Clear(head);
		}

		void Push(const T& data)
		{
			if(head == NULL)
			{
				head = new Node<T>(data);
			}
			else 
			{
				Node<T> *tmp = new Node<T>(data);
				tmp->SetLink(head);
				head = tmp;
			}
		}

		bool IsEmpty() const {return head == NULL;}
	
		void Pop() 
		{
			if(head != NULL)
			{
				Node<T>* tmp = head;
				head = head->GetLink();
				delete tmp;
				tmp = NULL;
			}
		}

		const T& Top() const 
		{
			if(head != NULL)
			{
				return head->GetData();
			}
			throw "Empty Stack";
		}

		std::string ToString() const
		{
			std::stringstream out;

			if(head != NULL)
			{
				out << head->GetData();
			}
			else 
			{
				out << "";
			}
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const Stack<T>& obj)
		{
			out << obj.ToString();
			return out;
		}
	};
}	
	
#endif
