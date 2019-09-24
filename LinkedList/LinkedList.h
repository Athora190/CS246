#ifndef LINKEDLIST_H
#define LINKEDLIST_H

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
		Node<T>* head;
		Node<T>* rear;
		int size;
	public:
		LinkedList() : head(NULL), rear(NULL), size(0) {}

		LinkedList(const LinkedList<T>& obj)
		{
			size = obj.size;
			Node<T>* tmp = obj.head;

			if(tmp != NULL)
			{
				head = new Node<T>(tmp->GetData());
				rear = head;
				tmp = tmp->GetLink();

				while(tmp != NULL)
				{
					rear->SetLink(new Node<T>(tmp->GetData()));
					rear = rear->GetLink();
					tmp = tmp->GetLink();
				}
			}
		}

		LinkedList<T>& operator=(const LinkedList<T>& rhs)
		{
			if(this != &rhs)
			{
				size = rhs.size;
				Clear(head);
				rear = NULL;
				Node<T>* tmp = rhs.head;

				if(tmp != NULL)
				{
					head = new Node<T>(tmp->GetData());
					rear = head;
					tmp = tmp->GetLink();

					while(tmp != NULL)
					{
						rear->SetLink(new Node<T>(tmp->GetData()));
						rear = rear->GetLink();
						tmp = tmp->GetLink();
					}
				}
			}

			return *this;			
		}

		~LinkedList() 
		{
			Clear(head);
			rear = NULL;
		}

		void InsertInFront(const T& data)
		{
			if(head == NULL)
			{
				head = new Node<T>(data);
				rear = head;
			}
			else 
			{
				Node<T> *tmp = new Node<T>(data);
				tmp->SetLink(head);
				head = tmp;
			}
			size += 1;
		}

		void InsertInBack(const T& data)
		{
			if(rear == NULL)
			{
				rear = new Node<T>(data);
				head = rear;
			}
			else
			{
				rear->SetLink(new Node<T>(data));
				rear = rear->GetLink();
			}
			size += 1;
		}

		void RemoveFromFront() 
		{
			if(!IsEmpty())
			{
				Node<T> tmp = head;
				head = head->GetLink();
				delete tmp;
				tmp = NULL;

				if(head == NULL)
				{
					rear = NULL;
				}

				size -= 1;
			}
		}

		void RemoveFromBack()
		{
			if(!IsEmpty())
			{
				if(rear == head)
				{
					delete rear;
					rear = NULL;
					head = NULL;
				}
				else
				{
					Node<T> *tmp = head;
					
					while(tmp->GetLink() != rear)
					{
						tmp = tmp->GetLink();
					}
					
					delete rear;
					tmp->SetLink(NULL);
					rear = tmp;
				}
				
				size -= 1;
			}
		}

		bool IsEmpty() const { return (head == rear && head == NULL);}

		std::string ToString() const
		{
			std::stringstream out;

			out << "[";

			for(Node<T> *tmp = head;tmp != NULL;tmp = tmp->GetLink())
			{
				out << *tmp;
				
				if(tmp->GetLink() != NULL)
				{
					out << ",";
				}
			}	
			
			out << "]";

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
