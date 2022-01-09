#include <iostream>
#include <cstring>
#include <cctype>
#include <algorithm>

#include "onp.h"
#include "stack.h"

int main()
{
	Onp onp;

	Stack<double> number_stack;
	Stack<char> operator_stack;

	std::cout << "Enter the equation (infix form): ";	
	std::getline(std::cin, onp.equation);
	
	onp.equation.erase(std::remove_if(onp.equation.begin(), 
		onp.equation.end(), ::isspace), onp.equation.end());
	
	std::cout << "ONP form: ";

	onp.transform_n_calculate(onp.equation, operator_stack, number_stack);

	double result = number_stack.pop();

	std::cout << "Result: " << result << std::endl;
	
	return 0;
}

