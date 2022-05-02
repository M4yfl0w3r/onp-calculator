#pragma once

#include "stack.h"

class Onp
{
private:
	int check_priority(char c);
	void calculate(char operation, Stack<double>& number_stack); 

public:
	std::string equation  = "";
	char operation = '\0';
	int priority = 0;

	void transform_n_calculate(std::string equation, Stack<char>& operator_stack, Stack<double>& number_stack);
};

