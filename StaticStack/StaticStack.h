#ifndef STATICSTACK_H
#define STATICSTACK_H

#include <iostream>
#include <string>
#include <sstream>

namespace ds
{
	template <class T>
	class StaticStack
	{
	private:
		int top;
		int capacity;
		T* data;
	public:
		StaticStack() : StaticStack(20) {}

		StaticStack(int capacity) : top(-1), capacity(capacity)  
		{
			if(this->capacity <= 0)
			{
				this->capacity = 20;
			}
			data = new T[this->capacity];
		}

		StaticStack(const StaticStack<T>& obj)
		{
			top = obj.top;
			capacity = obj.capacity;
			data = new T[capacity];

			for(int i = 0;i <= top;i += 1)
			{
				data[i] = obj.data[i];
			}
		}

		StaticStack& operator=(const StaticStack<T>& rhs)
		{
			if(this != &rhs)
			{
				top = rhs.top;
				capacity = rhs.capacity;
				delete[] data;
				data = new T[capacity];

				for(int i = 0;i <= top;i += 1)
				{
					data[i] = rhs.data[i];
				}
			}

			return *this;	
		}

		~StaticStack() 
		{
			delete[] data;
		}

		void Push(const T& value)
		{
			if((top + 1) < capacity)
			{
				top += 1;
				data[top] = value; 
			}
		}

		bool IsEmpty() const {return top == -1;}
	
		void Pop() 
		{
			if(top != -1)
			{
				top -= 1;
			}
		}

		const T& Top() const 
		{
			if(top != -1)
			{
				return data[top];
			}
			throw "Empty Stack";
		}

		bool IsFull() const {return (top + 1) == capacity;}

		int Size() const {return (top + 1);}

		int Capacity() const {return capacity;}

		std::string ToString() const
		{
			std::stringstream out;

			if(top != -1)
			{
				out << data[top];
			}
			else 
			{
				out << "";
			}
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const StaticStack<T>& obj)
		{
			out << obj.ToString();
			return out;
		}
	};
}	
	
#endif
