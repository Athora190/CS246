#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <sstream>

namespace ds
{
	template <class T>
	class Array
	{
	private:
		T* data;
		int size;
	public:
		Array() : Array(10) {}
	
		Array(int size) : size(size)
		{
			if(this->size > 0)
			{
				data = new T[this->size];
	
				for(int i = 0;i < this->size;i += 1)
				{
					data[i] = T();
				}
			}
			else 
			{
				data = NULL;
				this->size = 0;
			}
		}
	
		Array(const Array<T>& obj)
		{
			size = obj.size;
	
			if(size > 0)
			{
				data = new T[size];

				for(int i = 0;i < size;i += 1)
				{
					data[i] = obj.data[i];
				}
			}
			else 
			{
				data = NULL;
			}
		}

		Array<T>& operator=(const Array<T>& rhs)
		{
			if(this != &rhs)
			{
				size = rhs.size;
				delete[] data;

				if(size > 0)
				{
					data = new T[size];

					for(int i = 0;i < size;i += 1)
					{
						data[i] = rhs.data[i];
					}
				}
				else
				{
					data = NULL;
				}
			}

			return *this;
		}

		~Array() {delete[] data;}

		int Length() const {return size;}

		bool IsEmpty() const {return size == 0;}

		T& operator[](int index) 
		{
			if(index >= 0 && index < size)
			{
				return data[index];
			}
			throw "Out Of Bound";
		}

		const T& operator[](int index) const 
		{
			if(index >= 0 && index < size)
			{
				return data[index];
			}
			throw "Out Of Bound";
		}

		T& At(int index) 
		{
			if(index >= 0 && index < size)
			{
				return data[index];
			}
			throw "Out Of Bound";
		}


		const T& At(int index) const 
		{
			if(index >= 0 && index < size)
			{
				return data[index];
			}
			throw "Out Of Bound";
		}

		void Fill(const T& value)
		{
			for(int i = 0;i < size;i += 1)
			{
				data[i] = value;
			}
		}

		std::string ToString() const
		{
			std::stringstream out;

			out << "[";

			for(int i = 0;i < size;i += 1)
			{
				out << data[i];

				if(i + 1 < size)
				{
					out << ",";
				}
			}

			out << "]";
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const Array<T>& obj)
		{
			out << obj.ToString();
			return out;
		}
	};
}
		
#endif
