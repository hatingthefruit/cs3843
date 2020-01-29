#include "Lab1.h"
#include <stdio.h>

void displayBits(unsigned int n)
{
    int maskLen = (8 * sizeof(n)) - 1;
    unsigned int mask;

    for (mask = 1 << maskLen; mask > 0; mask = mask >> 1) {
        printf("%d", mask & n);
        if (!(mask % 8)) { // Prints out spaces every time, needs to be changed
            printf(" ");
        }
    }
    printf("\n");
}
unsigned int setKthBit(unsigned int n, int k);
int isPowerOfTwo(unsigned int n);
int getNoBits(unsigned int a, unsigned int b);
unsigned int computeXor(unsigned int n);