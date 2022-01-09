#include <iostream>
#include <stdexcept>

#include "stack.h"

template<typename T>
void Stack<T>::push(T value)
{
	struct Node<T>* new_node = new Node<T>;	

	new_node -> element = value;

	new_node -> next = top;

	top = new_node;
}

template<typename T>
T Stack<T>::pop()
{
	if (top != NULL)
	{
		struct Node<T>* tmp_top = top;

		top = top -> next;

		tmp_top -> next = NULL;
	
		T tmp_val = tmp_top -> element;

		delete tmp_top;

		return tmp_val;
	}

	throw new std::underflow_error ("Stack is empty");
}

template<typename T>
bool Stack<T>::stack_empty()
{
	return top == NULL;
}

template<typename T> 
T Stack<T>::get_top()
{
	return top -> element;
}

template<typename T>
std::ostream& operator << (std::ostream& stream, Stack<T> const& s)
{
	if (s.top != NULL)	
	{
		struct Node<T>* tmp = s.top;

		while (tmp != NULL)
		{
			stream << tmp -> element << ' ';
			tmp = tmp -> next;
		}
	}

	return stream;
}






