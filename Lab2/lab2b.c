/*
Author: Andrew DiCarlo
Assignment Number: Lab 2
File Name: lab2b.c
Course/Section: CS 3843 Section 003
Due Date: 02 Mar 2020
Instructor: Dr. Ku

Contains the modified code to complete the requirements of lab 2
*/


#include <stdio.h>
#include <string.h>
#define MAX 10

int readArray(int [], int);
void printArray(int [], int);
void reverseArray(int [], size_t);

int main(void) {
  int array[MAX], numElements;

  numElements = readArray(array, MAX);
  reverseArray(array, numElements);
  printArray(array, numElements);

  return 0;
}

int readArray(int arr[], int limit) {
  int i, input;

  printf("Enter up to %d integers, terminating with a negative integer.\n", limit);
  i = 0;
  scanf("%d", &input);
  while (input >= 0) {
    arr[i] = input;
    i++;
    scanf("%d", &input);
  }
  return i;
}

void reverseArray(int arr[], size_t size) {
    int *end, *start;
    int temp;
    start = arr;
    end = &arr[size - 1];
    
    while(start < end){
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
    
}

void printArray(int arr[], int size) {
  int i;

  for (i=0; i<size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
