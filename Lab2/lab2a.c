/*
Author: Andrew DiCarlo
Assignment Number: Lab 2
File Name: lab2a.c
Course/Section: CS 3843 Section 003
Due Date: 02 Mar 2020
Instructor: Dr. Ku

Contains the modified code the complete the requirements of lab 2
*/


#include <stdio.h>

int main(){
	int a = 100;
	int b = 10;
	int c = a+b;
	int d = a-b;
	int e = b/a;
	int f = a*b;
  
	printf("Arithmetic operations:\n");
	printf("a+b = %d\n", c);
	printf("a-b = %d\n", d);
	printf("b/a = %d\n", e);
	printf("a*b = %d\n\n", f);

	return 0;
}
