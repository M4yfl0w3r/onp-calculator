#pragma once

template<typename T>
struct Node
{
	T element;
	Node<T>* next;	
};

template<typename T>
struct Stack 
{	
	Node<T>* top = 0;

	void push(T value);
	T pop();

	bool stack_empty();
	T get_top();

	// template <typename G>
	// friend std::ostream& operator << (std::ostream& stream, Stack<G> const& Stack);
};

// template <typename G>
// std::ostream& operator << (std::ostream& stream, Stack<G> const& Stack);

