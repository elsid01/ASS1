#include <cstdlib>
#include "myStack.h"

template <class type>
myStack<type>::myStack() : capacity(1), size(1)
{
    
	stackElements = new type[capacity];
}

template <class type>
myStack<type>::myStack(const myStack<type>& copy)
{
	copyStack(copy);
}

template <class type>
const myStack<type>& myStack<type>::operator=(const myStack<type>& rhs)
{
	if (this != & rhs)
	{
		clearStack();
		copyStack(rhs);
	}

	return *this;
}

template <class type>
myStack<type>::~myStack()
{
	clearStack();
}

template <class type>
void myStack<type>::push(const type& item)
{
	if(size == capacity)
	{
		capacity *= 2;
		type* newStack = new type[capacity];
		for(std::size_t i = 0; i < size; i++)
		{
			newStack[i] = stackElements[i];
		}
		delete[] stackElements;
		stackElements = newStack;
	}
	stackElements[size++] = item;
}

template <class type>
type myStack<type>::peek() const
{
	if(isEmpty())
	  throw std::underflow_error("Stack is empty");

		return stackElements[size-1];
}

template <class type>
std::size_t myStack<type>::getSize() const
{
	return size;
}

template <class type>
type myStack<type>::pop()
{
  if(isEmpty())
	{
		throw std::underflow_error("stack is empty");
	}	
  return stackElements[--size];
}

template <class type>
bool myStack<type>::isEmpty() const
{
	return size == 0;
}

template <class type>
void myStack<type>::clearStack()
{
  delete[] stackElements;
	stackElements = nullptr;
	size = 0;
  capacity = 0;
}

template <class type>
void myStack<type>::copyStack(const myStack<type>& copyThisStack)
{
  capacity = copyThisStack.capacity;
	size = copyThisStack.size;
	stackElements = new type[capacity];

	for(std::size_t i = 0; i < size; i++)
	{
		stackElements[i] = copyThisStack.stackElements[i];
	}

}

