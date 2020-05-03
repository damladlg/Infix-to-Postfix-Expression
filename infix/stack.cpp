/*
 * stack.cpp
 *
 *  Created on: November 25, 2019
 *      Author: Damla Dalgic -> damlabileydi@gmail.com
 */
#include<iostream>
#include "scenerio.h"
char in[50] = { 0 };
using namespace std;
/**
* @brief : this code checks whether the stack is empty
* @param s : s identifies the pointer
* @return : returns true if the stack is empty
*/
bool isEmpty(struct Stack *s)
{
	if (s->top < 0) return true;
	else return false;
}
/**
* @brief : this code checks whether the stack is full
* @param s : s identifies the pointer
* @return : returns true if the stack is full
*/
bool isFull(struct Stack *s)
{
	if (s->top == MAX - 1) return true;
	else return false;
}
/**
* @brief : this code adds elements to the end of the stack
* @param s : s identifies the pointer
* @param newitem : define the new element
*/
void push(struct Stack* s, int newitem)
{
	if (isFull(s))
		cout << "Stack is full!!";
	else
	{
		s->top++;
		s->data[s->top] = newitem;
	}
}
/**
* @brief : this code deletes and returns elements from the beginning of the stack
* @param s : s identifies the pointer
* @return : to be deleted
		  --> s->data[temp] : returns the deleted data
*/
char pop(struct Stack* s)
{
	int temp = s->top;
	s->top--;

	return s->data[temp];
}
/**
* @brief : this code lists the queue.
*/
void list(struct Stack *s)
{
	for (int i = 0; i < s->top + 1; i++)
	{
		cout << s->data[i] << " ";
	}
}
/**
* @brief : this code finds the number of elements in the stack
*/
void count(struct Stack *s)
{
	int i, counter = 0;
	for (i = 0; s->data[i]==NULL; i++)
	{
		counter++;
	}
}