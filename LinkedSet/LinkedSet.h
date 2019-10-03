#ifndef LINKEDSET_H
#define LINKEDSET_H

#include <iostream>
#include <string>
#include <sstream>
#include "Node.h"

namespace ds
{
	template <class T>
	class LinkedSet
	{
	private:
		Node<T>* head;
		int size;
	public:
		LinkedSet() : size(0), head(NULL) {}

		LinkedSet(const LinkedSet<T>& obj)
		{
			size = obj.size;
			head = Copy(obj.head);
		}

		LinkedSet& operator=(const LinkedSet<T>& rhs)
		{
			if(this != &rhs)
			{
				size = rhs.size;
				Clear(head);
				head = Copy(rhs.head);
			}

			return *this;	
		}

		~LinkedSet() 
		{
			Clear(head);
			head = NULL;
		}

		bool Contains(const T& value) const 
		{
			for(Node<T>* tmp = head;tmp != NULL;tmp = tmp->GetLink())
			{
				if(value == temp->GetData())
				{
					return true;
				}
			}
			return false;
		}

		void Add(const T& value) {}

		void Remove(const T& value) {}

		bool IsEmpty() const {return (head == NULL);}

		int Cardinality() const {return size;}

		std::string ToString() const
		{
			std::stringstream out;
			out << "{";

			for(Node<T>* tmp = head;tmp != NULL;tmp = tmp->GetLink())
			{
				out << data[i];
				
				if(tmp->GetLink() != NULL)
				{
					out << ",";
				}
			}
			out << "}";
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const LinkedSet<T>& obj)
		{
			out << obj.ToString();
			return out;
		}
	};
}
		
#endif
