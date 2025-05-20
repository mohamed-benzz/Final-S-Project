  GNU nano 8.3                                                      c_lib.c                                                               
#include <string.h>
#include <stdio.h>

int max_c(int* array, int count) {
    int max = array[0];
    for (int i = 1; i < count; ++i)
        if (array[i] > max) max = array[i];
    return max;
}

long gcd_c(long a, long b) {
    while (b != 0) {
        long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void ispalindrome_c(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; ++i) {
        if (str[i] != str[len - i -1]) {
            printf("THIS IS NOT PALINDROME!\n");
            return;
        }
    }
    printf("THIS IS PALINDROME!\n");
}







