#pragma once
#include <iostream>
using namespace std;

class ArrayException : public std::exception
{
private:
	std::string m_error;

public:
	ArrayException(std::string error) : m_error(error) {}

	// ���������� std::string � �������� ����������� ������ C-style
	const char* what() const noexcept { return m_error.c_str(); } // C++11 � �������
};

template <class T>
class Array {
protected:
	int size; //����������� �������
	int capacity; //������� �������
	int init_capacity;
	T* Data; //������ ��������� (�������)

public:
	Array(); //����������� �� ���������
	Array(int c); //����������� � �����������
	Array(const Array<T>&arr); //����������� �����������
	~Array(); //����������

	int Capacity(); //����� ������� �������
	int Size(); //����� ������� �������
	T& search_pos(int pos); //����� �� ������� � �������
	bool search_val(T val, int& num); //����� �� �������� � �������
	int idx_val(T val, int& num); //��������� ������� ��������� �������� � �������
	void push_back(T val); //������� � ����� �������
	bool push_pos(T val, int pos, int& num); //��������� ������ �������� � ������� � �������� �������
	bool erase(T val, int& num); //�������� ��������
	bool erase_pos(int pos, int& num); //�������� �������� �� �������
	bool change(T val, int pos); //��������� �������� ���� � ������ �������
	void show(); //����� ������� ���������������
	void clear(); //������� ������
	bool is_empty(); //�������� �� �������

	class Iterator {
		Array<T>* arr; //��������� �� ������
		int cur; //��������� �� ������� ������� ������������������
	public:
		Iterator(); //� ����� �� ���������
		Iterator(Array<T>*ar, int ind); //� ����� �� ���������
		Iterator(const Iterator&iter);

		T& operator *(); //������ � ������ �������� ��������
		Iterator& operator++()
		{
			if (cur >= 0 && cur < arr->size)
			{
				cur++;
				return *this;
			}
			else throw ArrayException("Invalid index");
		}
		Iterator& operator--()
		{
			if (cur >= 0 && cur < arr->size)
			{
				cur--;
				return *this;
			}
			else throw ArrayException("Invalid index");
		}
		bool operator ==(const Iterator& iter)
		{
			if (arr == iter.arr && cur == iter.cur)
				return true;
			else return false;
		}
		bool operator !=(const Iterator& iter)
		{
			if (arr != iter.arr || cur != iter.cur)
				return true;
			else return false;
		}
	};
	friend class Iterator;

	Iterator begin()		//��������� ��������� begin( )
	{
		Iterator iter(this, 0);
		return iter;
	}
	Iterator end()			//��������� ��������� end( )
	{
		Iterator iter(this, size);
		return iter;
	}
	Iterator rbegin()		//��������� ��������� rbegin( )
	{
		Iterator iter(this, size - 1);
		return iter;
	}
	Iterator rend()		//��������� ��������� rend( )
	{
		Iterator iter(this, -1);
		return iter;
	}
};

template <class T>
Array <T>::Array() //����������� ��� ����������
{
	size = 0;
	capacity = 2;
	init_capacity = 2;
	Data = new T[capacity];
}

template <class T>
Array <T>::Array(int c) //����������� � ����������
{
	size = 0;
	capacity = c;
	init_capacity = c;
	Data = new T[capacity];
}

template <class T>
Array <T>::Array(const Array<T>&arr) //����������� �����������
{
	size = arr.size;
	capacity = arr.capacity;
	init_capacity = arr.init_capacity;
	Data = new T[capacity];
	for (int i = 0; i < size; i++)
	{
		Data[i] = arr.Data[i];
	}
}

template <class T>
Array <T>::~Array() //����������
{
	delete[] Data;
}

template<class T>
int Array<T>::Capacity()
{
	return capacity;
}

template<class T>
int Array<T>::Size()
{
	return size;
}

template<class T>
T & Array<T>::search_pos(int pos)
{
	if (pos < size && pos >= 0)
		return Data[pos];
	else
	{
		throw ArrayException("Invalid index");
		//cout << "������� �� ����������" << endl;
	}
}

template<class T>
bool Array<T>::search_val(T val, int& num)
{
	num = 0;
	bool flag = false;
	for (int i = 0; i < size; i++)
	{
		num++;
		if (Data[i] == val)
		{
			flag = true;
			break;
		}
	}
	return flag;
}

template<class T>
int Array<T>::idx_val(T val, int& num)
{
	num = 0;
	int ind = -1;
	for (int i = 0; i < size; i++)
	{
		num++;
		if (val == Data[i])
		{
			ind = i;
			break;
		}
	}

	if (ind == -1) throw ArrayException("Nonexistent element");
	//cout << "�������� �� ����������" << endl;
	return ind;
}

template<class T>
void Array<T>::push_back(T val)
{
	if (size == capacity) //���������� �������
	{
		T* temp = new T[capacity];
		for (int i = 0; i < size; i++)
			temp[i] = Data[i];

		capacity *= 2;
		delete[] Data;
		Data = new T[capacity];

		for (int i = 0; i < size; i++)
			Data[i] = temp[i];
		delete[] temp;
	}

	Data[size] = val;
	size++;
}

template<class T>
bool Array<T>::push_pos(T val, int pos, int& num)
{
	num = 0;
	if (pos <= size && pos >= 0)
	{
		if (size == capacity) //���������� �������
		{
			T* temp = new T[capacity];
			for (int i = 0; i < size; i++)
				temp[i] = Data[i];

			capacity *= 2;
			delete[] Data;
			Data = new T[capacity];

			for (int i = 0; i < size; i++)
				Data[i] = temp[i];
			delete[] temp;
		}

		for (int i = size; i > pos; i--) //�����
		{
			Data[i] = Data[i - 1];
			num++;
		}

		Data[pos] = val;
		size++;

		return true;
	}

	else return false;
}

template<class T>
bool Array<T>::erase(T val, int& num)
{
	int ind = -1;
	num = 0;

	if (size * 2 <= capacity) //���������� �������
	{
		T* temp = new T[size];
		for (int i = 0; i < size; i++)
			temp[i] = Data[i];

		delete[] Data;
		capacity = capacity / 2 + init_capacity;
		Data = new T[capacity];

		for (int i = 0; i < size; i++)
			Data[i] = temp[i];
		delete[] temp;
	}

	for (int i = 0; i < size; i++) //����� �� ��������
	{
		if (Data[i] == val)
		{
			ind = i;
			break;
		}
	}

	if (ind != -1)
	{
		for (int i = ind; i < size - 1; i++) // ����� 
		{
			Data[i] = Data[i + 1];
			num++;
		}
		size--;
	}

	if (ind != -1) return true;
	else return false;
}

template<class T>
bool Array<T>::erase_pos(int pos, int& num)
{
	num = 0;
	if (pos < size && pos >= 0)
	{
		if (size * 2 <= capacity) //���������� �������
		{
			T* temp = new T[size];
			for (int i = 0; i < size; i++)
				temp[i] = Data[i];

			delete[] Data;
			capacity = capacity / 2 + init_capacity;
			Data = new T[capacity];

			for (int i = 0; i < size; i++)
				Data[i] = temp[i];
			delete[] temp;
		}

		for (int i = pos; i < size - 1; i++)
		{
			Data[i] = Data[i + 1];
			num++;
		}

		size--;
		return true;
	}

	else return false;
}

template<class T>
bool Array<T>::change(T val, int pos)
{
	if (pos < size)
	{
		Data[pos] = val;
		return true;
	}

	else return false;
}

template<class T>
void Array<T>::show()
{
	if (size == 0)
		cout << "[ ]" << endl;
	else
	{
		cout << "[ ";
		for (int i = 0; i < size - 1; i++)
			cout << Data[i] << ", ";
		cout << Data[size - 1] << " ]" << endl;
	}
}

template<class T>
void Array<T>::clear()
{
	size = 0;
	capacity = init_capacity;
	delete[] Data;
	Data = new T[capacity];
}

template<class T>
bool Array<T>::is_empty()
{
	if (size == 0)
		return true;
	else return false;
}

template<class T>
Array<T>::Iterator::Iterator()
{
	arr = NULL;
	cur = 0;
}

template<class T>
Array<T>::Iterator::Iterator(Array<T>*ar, int ind)
{
	arr = ar;
	cur = ind;
}

template<class T>
Array<T>::Iterator::Iterator(const Iterator&iter)
{
	arr = iter.arr;
	cur = iter.cur;
}

template<class T>
T& Array<T>::Iterator::operator *()
{
	if (cur >= 0 && cur < arr->size)
	{
		return arr->Data[cur];
	}

	else throw ArrayException("Invalid index");
}
