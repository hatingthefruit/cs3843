#include "Lab1.h"
#include <stdio.h>

void displayBits(unsigned int n)
{
    int maskLen = (8 * sizeof(n)) - 1;
    unsigned int mask;
    int count = 0;

    printf("      %d =", n); // 6 spaces in order to match up with the provided output file
                             // No space after the = because the loop will print a space out the first iteration

    for (mask = 1 << maskLen; mask > 0; mask = mask >> 1) {
        if (!(count % 8)) { // Only print a space if the count is divisible by 8
            printf(" ");
        }
        count++;

        printf("%d", mask & n);
    }
    printf("\n");
}
unsigned int setKthBit(unsigned int n, int k)
{
    return k;
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