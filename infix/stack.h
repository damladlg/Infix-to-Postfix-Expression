/*
 * stack.h
 *
 *  Created on: November 25, 2019
 *      Author: Damla Dalgic -> damlabileydi@gmail.com
 */
#define MAX 10
struct Stack
{
	char data[MAX]; 
	int top = -1;
};
bool isEmpty(struct Stack *s); // checks whether the stack is empty
bool isFull(struct Stack *s); // checks whether the stack is full
void push(struct Stack* s, int item); // add to stack
char pop(struct Stack* s); // deletes from stack
void list(struct Stack *s); // lists the stack
void count(struct Stack *s); // finds the number of the stack
