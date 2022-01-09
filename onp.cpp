#include <iostream>
#include <stdlib.h>
#include <string>
#include <math.h>

#include "onp.h"

int Onp::check_priority(char c)
{
	switch(c)
	{
		case '^':
			return 4;

		case '*': 
		case '/':
			return 3;

		case '+':
		case '-':
			return 2;

		case '(':
			return 1;

		default:
			return 0;
	}
}

void Onp::calculate(char operation, Stack<double>& number_stack)
{
	double a = 0;
	double b = 0;

	a = number_stack.pop();
	b = number_stack.pop();

	switch (operation)	
	{	
		case '^':
			number_stack.push(pow(a, b));
			break;

		case '*': 
			number_stack.push(a*b);
			break;

		case '/':
			number_stack.push(b/a);
			break;

		case '+':
			number_stack.push(a+b);
			break;
		
		case '-':
			number_stack.push(b-a);
			break;

		default:
			std::cout << "Unknown operation: " << operation << std::endl;	
	}
}

void Onp::transform_n_calculate(std::string equation, Stack<char>& operator_stack, Stack<double>& number_stack)
{	
	for (int i=0; equation[i] != '\0'; i++)
	{
		if (isdigit(equation[i]))
		{
			int j = 0;
			std::string number = "";

			while (isdigit(equation[i+j]))
			{
				number.append(1, equation[i+j]);
				j++;
			}
			
			std::cout << number << " ";

			number_stack.push(atof(number.c_str()));
			i += j-1;
		}

		else if (equation[i] == '(')
		{
			operator_stack.push(equation[i]);
		}

		else if (equation[i] == ')')
		{
			while (operator_stack.get_top() != '(')		
			{
				char tmp = operator_stack.pop();
				calculate(tmp, number_stack);
				std::cout << tmp;
			}
			
			operator_stack.pop();	
		}

		else 	
		{			
			priority = check_priority(equation[i]);

			if (operator_stack.stack_empty())
			{
				operator_stack.push(equation[i]);
			}

			else
			{
				if (priority < check_priority(operator_stack.get_top())) 
				{
					while (!operator_stack.stack_empty() && 
						priority < check_priority(operator_stack.get_top()))
					{
						char tmp = operator_stack.pop();
						calculate(tmp, number_stack);
						std::cout << tmp;	
					}
				}
				
				operator_stack.push(equation[i]);
			}
		}	
	}

	while (!operator_stack.stack_empty()){
		char tmp = operator_stack.pop();
		calculate(tmp, number_stack);
		std::cout << tmp;
	}

	std::cout << '\n';
}

