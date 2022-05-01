#pragma once
#include "Macro.h"
#include "Standard.h"

template <class TemplateClass>
class DynamicArray
{
private:
	TemplateClass* _array = nullptr;
	int _capacity;
	int _size;
public:
	int size() const { return _size; }
	TemplateClass getAt(int index) const { return _array[index]; }
	TemplateClass operator[](int index) const { return getAt(index); }
	void removeAt(int index)
	{
		for (int i = index + 1; i < _size; i++)
		{
			_array[i - 1] = _array[i];
		}
	}
	void push_back(TemplateClass object)
	{
		if (_size >= _capacity)
		{
			// Khởi tạo vùng nhớ mới
			_capacity += PARTITION_SIZE;
			TemplateClass* temp = new TemplateClass[_capacity];

			// Sao chép dữ liệu sang
			for (int i = 0; i < _size; i++)
			{
				temp[i] = _array[i];
			}

			// Xóa vùng nhớ cũ
			delete[] _array;

			// Trao quyền vùng nhớ
			_array = temp;
		}

		_array[_size] = object;
		_size += 1;
	}
public:
	DynamicArray()
	{
		_capacity = PARTITION_SIZE;
		_array = new TemplateClass[_capacity];
		_size = 0;
	}
	DynamicArray(const DynamicArray& other)
	{
		_capacity = other._capacity;
		_size = other._size;
		_array = new TemplateClass[_capacity];

		for (int i = 0; i < other.size(); i++)
		{
			_array[i] = other[i];
		}
	}
	DynamicArray& operator=(const DynamicArray& other)
	{
		_capacity = other._capacity;
		_size = other._size;
		_array = new TemplateClass[_capacity];

		for (int i = 0; i < other.size(); i++)
		{
			_array[i] = other[i];
		}

		return *this;
	}
	~DynamicArray() { delete[] _array; }
};

