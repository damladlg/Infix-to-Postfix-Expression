/*
 * scenerio.h
 *
 *  Created on: November 25, 2019
 *      Author: Damla Dalgic -> damlabileydi@gmail.com
 */
#include"stack.h"
int isOperator(char opr); // controls operators
int priority(char opr); // looks at operators' priority 
void infixToPostfix(char* infix, char * postfix); // performs the conversion process
void menu();