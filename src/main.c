/*
 * main.c
 *
 *  Created on: Feb. 26, 2024
 *      Author: Vulpovile
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_SIZE 64


int main(int argc, char ** argv)
{
	char buf[BUFFER_SIZE];
	int a;
	int b;
	int c;
	begin:
	printf("%s\n", "Please enter your first number:");
	fgets(buf, BUFFER_SIZE, stdin);
	a = atoi(buf);

	printf("%s\n", "Please enter your second number:");
	fgets(buf, BUFFER_SIZE, stdin);
	b = atoi(buf);

	operator:
	printf("%s\n", "Please enter your operator:");
	fgets(buf, BUFFER_SIZE, stdin);

	goto end_operations;

	add:
	c = a + b;
	goto print_results;

	subtract:
	c = a - b;
	goto print_results;

	multiply:
	c = a * b;
	goto print_results;


	divide:
	if(b == 0)
	{
		strncpy(buf, "You can't divide by zero!", BUFFER_SIZE);
		goto print_error;
	}
	c = a / b;
	goto print_results;

	modulus:
	if(b == 0)
	{
		strncpy(buf, "You can't modulo by zero!", BUFFER_SIZE);
		goto print_error;
	}
	c = a % b;
	goto print_results;

	print_results:
	printf("%d %c %d = %d\n", a, *buf, b, c);
	goto request_repeat;

	print_error:
	printf("%s\n", buf);
	goto request_repeat;


	end_operations:

	switch(*buf)
	{
		case '+':
			goto add;
			break;
		case '-':
			goto subtract;
			break;
		case '*':
			goto multiply;
			break;
		case '/':
			goto divide;
			break;
		case '%':
			goto modulus;
			break;
		default:
			goto operator;
			break;
	}

	request_repeat:
	printf("Do you want to try again? (y/n)");
	fgets(buf, BUFFER_SIZE, stdin);
	if(*buf == 'y')
		goto begin;
	else if(*buf == 'n')
		goto end;
	else
		goto request_repeat;

	end:
	return 0;
}
