#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template<typename T>
Array<T>::Array()
{
	CLASS("Constructor", "Array");
	this->_Tab = new T[0];
	this->_Size = new unsigned int(0);
}

template<typename T>
Array<T>::Array(unsigned int size)
{
	CLASS("Constructor with UNSIGNED INT param", "Array");
	this->_Tab = new T[size];
	this->_Size = new unsigned int(size);
}

template<typename T>
Array<T>::~Array()
{
	CLASS("Destructor", "Array");
	delete[] this->_Tab;
	delete this->_Size;
}

template<typename T>
Array<T>::Array(const Array& other)
{
	CLASS("Constructor by copy", "Array");
	if (this == &other)
		return ;
	this->_Tab = new T[*other._Size];
	this->_Size = new unsigned int(*other._Size);
}

template<typename T>
Array<T>& Array<T>::operator= (const Array& other)
{
	CLASS("Operand = Constructor", "Array");
	if (this == &other)
		return (*this);
	delete[] this->_Tab;
	delete this->_Size;
	this->_Tab = new T[*other._Size];
	this->_Size = new unsigned int(*other._Size);
	return (*this);
}

// template<typename T>
// T& Array<T>::operator[] (int i)
#endif