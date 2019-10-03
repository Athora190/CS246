#ifndef SET_H
#define SET_H

#include <iostream>
#include <string>
#include <sstream>

namespace ds
{
	template <class T>
	class Set
	{
	private:
		T* data;
		int size;// the amount of elements in the array
		int capacity; // size of dynamic array
		
		void Resize()
		{
			int oldCapacity = capacity; //holds the old capacity
			T* tmp = new T[oldCapacity];//dynamic array
			
			for(int i = 0;i < oldCapacity;i += 1)//copys element by element of the array (Deep copy)
			{
				tmp[i] = data[i];
			}

			delete[] data;// deletes the data
			capacity *= 2;//changes the capacity
			data = new T[capacity];//reallocates the old capacity

			for(int i = 0;i < oldCapacity;i += 1) //copys back the informaton of data
			{
				data[i] = tmp[i];
			}
			delete[] tmp;//deallocate temp
		}
	public:
		Set() : size(0), capacity(20) 
		{
			data = new T[capacity];
		}

		Set(const Set<T>& obj)//copy contructor proforms a copy by reference to an object
		{
			size = obj.size;
			capacity = obj.capacity;
			data = new T[capacity];

			for(int i = 0;i < size;i += 1)//copys the information over
			{
				data[i] = obj.data[i];
			}
		}

		Set& operator=(const Set<T>& rhs)// assigning an existent object to another objects
		{
			if(this != &rhs)//solution of trying not the copy yourself
			{
				//the same as the copy contrustor but with rhs. in stead of obj.
				size = rhs.size;
				capacity = rhs.capacity;
				delete[] data;
				data = new T[capacity];

				for(int i = 0;i < size;i += 1)
				{
					data[i] = rhs.data[i];
				}
			}

			return *this;	
		}

		~Set() {delete[] data;}//dealloctes data

		bool Contains(const T& value) const //checks if any items in a set are the same (value we look for in permater)
		{
			for(int i = 0;i < size;i += 1)
			{
				if(value == data[i]) //sees of the value is the same as the items in the set or data. If true then the value is the same, if false then they are not
				{
					return true;
				}
			}
			return false;
		}

		void Add(const T& value)// takes a const T reference as a permater
		{
			if(!Contains(value))//checks if the value is already in the array or set
			{
				if(size == capacity)//checks if size = the capacity 
				{
					Resize();
				}
				
				data[size] = value;//adds the value in the array
				size += 1;
			}
		}
		//steps to remove
		//1. find the index of the element you want to remove
		
		void Remove(const T& value)
		{
			int i;
			
			while(i < size && data[i] != value)//checks if i is less then size and the data of i is not = value
			{
				i += 1;
			}

			if(i != size) // when you find the item then check is i is not = to size
			{
				size -= 1;//first decrease the size by 1 (makes the process easier)
				
				for(;i < size;i += 1)
				{
					data[i] = data[i+1];//assignes the index the the nest index of the array
				}
			}
		}

		bool IsEmpty() const {return (size == 0);}//returns size = 0 if true

		int Cardinality() const {return size;}//returns the size of the array or set

		std::string ToString() const
		{
			std::stringstream out;
			out << "{";

			for(int i = 0;i < size;i += 1)
			{
				out << data[i];
				
				if((i + 1) != size)
				{
					out << ",";
				}
			}
			out << "}";
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const Set<T>& obj)
		{
			out << obj.ToString();
			return out;
		}
	};
}
		
#endif
