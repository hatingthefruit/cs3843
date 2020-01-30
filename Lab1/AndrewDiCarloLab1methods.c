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
    // Check the result of an AND operation between n and n - 1
    // It should evaluate to 0 if n is a power of 2, and non-zero if n is not
    if (n & (n - 1) || n == 0) {
        return 0;
    }
    else {
        return 1;
    }
}
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
unsigned int computeXor(unsigned int n)
{
    // Start val at 0 and i at 1
    unsigned int val = 0;
    unsigned int i = 1;

    // Loop through every number and XOR i with val
    while (i < n) {
        val = val ^ i;
        i++;
    }

    // Finally, XOR val with n and return val
    val = val ^ n;
    return val;
}