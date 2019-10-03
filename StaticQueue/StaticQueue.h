#ifndef STATICQUEUE_H
#define STATICQUEUE_H

#include <iostream>
#include <string>
#include <sstream>

namespace ds
{
	template <class T>
	class StaticQueue
	{
	private:
		int front;
		int back;
		int capacity;
		T* data;
	public:
		StaticQueue() : StaticQueue(20) {}

		StaticQueue(int capacity) : front(0), back(0), capacity(capacity) 
		{
			if(this->capacity <= 0)
			{
				this->capacity = 20;
			}
			data = new T[this->capacity];
		}

		StaticQueue(const StaticQueue<T>& obj)
		{
			front = obj.front;
			back = obj.back;
			capacity = obj.capacity;
			data = new T[capacity];
			
			for(int i = front;i != back;i = (i + 1) % capacity)
			{
				data[i] = obj.data[i];
			}
		}

		StaticQueue& operator=(const StaticQueue<T>& rhs)
		{
			if(this != &rhs)
			{
				front = rhs.front;
				back = rhs.back;
				capacity = rhs.capacity;
				delete[] data;
				data = new T[capacity];
			
				for(int i = front;i != back;i = (i + 1) % capacity)
				{
					data[i] = rhs.data[i];
				}
			}
			
			return *this;
		}
		
		~StaticQueue() 
		{
			delete[] data;
		}

		void Enqueue(const T& value)
		{
			if(!IsFull())
			{
				data[back] = value;
				back = (back + 1) % capacity;
			}
		}

		bool IsEmpty() const {return (front == back);}
	
		void Dequeue() 
		{
			if(front != back)
			{
				front = (front + 1) % capacity;
			}
		}

		const T& Peek() const 
		{
			if(front != back)
			{
				return data[front];
			}
			throw "Empty Queue";
		}

		bool IsFull() const {return (((back + 1) % capacity) == front);}

		int Size() const {return ((capacity + (back - front)) % capacity);}

		int Capacity() const {return capacity;}

		std::string ToString() const
		{
			std::stringstream out;

			if(front != back)
			{
				out << data[front];
			}
			else 
			{
				out << "";
			}
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const StaticQueue<T>& obj)
		{
			out << obj.ToString();
			return out;
		}
	};
}	
	
#endif
