// funcs.c
#include <stdint.h>
#include <stddef.h>
#include "libcc.h"

uint64_t lcm_c(uint64_t a, uint64_t b) {
    if (a > b) { uint64_t t = a; a = b; b = t; }
    uint64_t orig = b;
    while (1) {
        if (b % a == 0) return b;
        b += orig;
    }
}

void rev_c(char *buf, size_t len) {
    for (size_t i = 0, j = len ? len - 1 : 0; i < j; i++, j--) {
        char t = buf[i];
        buf[i]  = buf[j];
        buf[j]  = t;
    }
}
void revnum_c(char *buf, int len) {
    char *start = buf;
    char *end = buf + len - 1;
    while (start < end) {
        char tmp = *start;
        *start++ = *end;
        *end-- = tmp;
    }
}

void printarray_c(void) {
    int arr[] = {11, 1, 8, 2, 4, 0, 5, 1, 20, 5};
    size_t n = sizeof(arr) / sizeof(arr[0]);
    printf("The output array (specified in the program) is:\n");
    for (size_t i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i + 1 < n) printf(" ");
    }
    printf("\n");
}

