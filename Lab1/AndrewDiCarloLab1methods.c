#include "Lab1.h"
#include <stdio.h>

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
int isPowerOfTwo(unsigned int n)
{
    return n;
}
int getNoBits(unsigned int a, unsigned int b)
{
    return 32;
}
unsigned int computeXor(unsigned int n)
{
    return n;
}