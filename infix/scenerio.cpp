/*
 * scenerio.cpp
 *
 *  Created on: November 25, 2019
 *      Author: Damla Dalgic -> damlabileydi@gmail.com
 */
#include <stdio.h>
#include <string.h>
#include<iostream>
#include <ctype.h>
#include "scenerio.h"
using namespace std;
/**
* @brief : this code define operators
* @param opr : define the operators
* @return : returns true if the operators are correct 
*/
int isOperator(char opr)
{
	if (opr == '+' || opr == '-' || opr == '*' || opr == '/') return 1;
	else return 0;
}
/**
* @brief : this code compare by operator
* @param opr : define the operators.
* @return : to be makes assignment
		  --> pri : returns value given to pris
*/
int priority(char opr)
{
	int pri = 0;
	if (opr == '*' || opr == '/')
		pri = 2;
	else if (opr == '+' || opr == '-')
		pri = 1;
	return pri;
}
/**
* @brief : this code performs the conversion process
* @param *infix : holds elements in infix
* @param *postfix : holds elements in postfix
*/
void infixToPostfix(char *infix, char *postfix)
{
	char *i, *p; // A variables that holds characters is defined.
	
	char n1; // defines the element used
	struct Stack X;

	i = &infix[0];
	p = &postfix[0];

	while (*i) // condition that faces the entered expression
	{
		if (isdigit(*i) || isalpha(*i)) // if element is an alphabetic character or element is a number
		{
			*p = *i; // transfers i to p
			p++;  
			i++;
		}
		if (*i == '(')
		{
			push(&X, *i); // if element is a '(' it adds i
			i++;
		}
		if (*i == ')')
		{
			n1 = pop(&X); // element is removed if parentheses close
			while (n1 != '(')
			{
				*p = n1;
				p++;
				n1 = pop(&X);
			}
			i++;
		}
		if (isOperator(*i))
		{
			if (isEmpty(&X))
				push(&X, *i); // if i is an operator and the array is empty, it adds the i.
			else
			{
				n1 = pop(&X);
				while (priority(n1) >= priority(*i)) // precedence of characters
				{
					*p = n1;
					p++;
					n1 = pop(&X);
				}
				push(&X, n1);
				push(&X, *i);
			}
			i++;
		}
	}
	while (!isEmpty(&X))
	{
		n1 = pop(&X);
		*p = n1;
		p++;
	}
	*p = '\0'; //finish 

	
}
void menu()
{
	char in[50] = { 0 }, post[50] = { 0 };

	cout << "Enter the expression you want to convert: " << endl;
	fgets(in, sizeof(in), stdin);
	in[strlen(in) - 1] = '\0';

	infixToPostfix(&in[0], &post[0]);
	cout << endl;

	cout << "Infix to Postfix: " << &post[0] << endl;
	cout << "Number of elements: " << strlen(post) << endl;
}
