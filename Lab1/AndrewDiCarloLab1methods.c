/*
Author: Andrew DiCarlo
Assignment Number: Lab Assignment 1
File Name: AndrewDiCarloLab1methods.c
Course/Section: CS 3843 Section 003
Due Date: 19 Feb 2019
Instructor: Dr. Ku

Functions to complete bitwise operations on numbers
A makefile is being included that will automatically build, run the program, and redirect the output

Alternately, the command to compile is:
gcc -g -Wall Lab1main.c AndrewDiCarloLab1methods.c -o Lab1
*/

//#include "Lab1.h"
#include <stdio.h>

// Displays an unsigned integer in bits
// Prints a space after every 8 bits
void displayBits(unsigned int n)
{
    int maskLen = (8 * sizeof(n)) - 1;
    unsigned int mask;
    int count = 0;

    printf("%7d =", n); // Spacing of 7 to match up with the output file
                        // No space after the = because the loop will print a space out the first iteration

    for (mask = 1 << maskLen; mask > 0; mask = mask >> 1) {
        if (!(count % 8)) { // Only print a space if the count is divisible by 8
            printf(" ");
        }
        count++; // Increment count

        // Check if there is a 1 bit in the mask position, print the right number
        if (mask & n) {
            printf("1");
        }
        else {
            printf("0");
        }
    }
    printf("\n");
}

// Set the Kth bit from the right of an unsigned integer to be 1
// Uses bit shifts on a mask and a bitwise OR to set the proper bit
unsigned int setKthBit(unsigned int n, int k)
{
    // If user tries to set a bit that is not in a 32 bit int, then just return the original number
    if (k < 1 || k > 32) {
        return n;
    }
    else {
        // Set a mask to the first bit
        unsigned int mask = 1;

        // Since mask already has a 1 in the 1st position, decrement k to match
        k -= 1;

        // Bitshift to the correct bit, and then return an OR of n and the mask
        mask = mask << k;
        return n | mask;
    }
}

// Check if a number is a power of 2
// Does this by performing a bitwise AND of n and n-1
int isPowerOfTwo(unsigned int n)
{
    // Check the result of an AND operation between n and n - 1
    // It should evaluate to 0 if n is a power of 2, and non-zero if n is not
    if (n & (n - 1) || n == 0) {
        return 0;
    }
    else {
        return 1;
    }
}

// Function that finds the number of bits that need to be changed to convert one number into another number
// Takes two unsigned integers, a and b, and finds the bits that are different using XOR
// Counts the number of bits that are equal to 1, which are the same as the number of bits that are different
int getNoBits(unsigned int a, unsigned int b)
{
    // XOR to find the bits that need to be changed between the two
    // Start a counter
    unsigned int diff = a ^ b;
    int count = 0;

    // Check that diff is greater than 0
    while (diff > 0) {

        // If there is a 1 in the 1st bit, increment count
        if ((diff & 1) == 1) {
            count++;
        }

        // shift diff to the right 1
        diff = diff >> 1;
    }
    return count;
}

// Function takes an unsigned int n and computes the xor of every number from 1 to n
// Uses a pattern that repeats every 4 numbers to simplify calculations
unsigned int computeXor(unsigned int n)
{
    // If you XOR consecutive numbers starting at 1, then there is a pattern
    // Depending on the result of n % 4, the output can be predicted as either n, 1, n + 1, or 0
    // We can use this to predict the values more easily
    switch (n % 4) {
        case 0: return n;
        case 1: return 1;
        case 2: return n + 1;
        case 3: return 0;

        // Should never reach this point, but the compiler will throw warnings without this
        default: return 0;
    }
}