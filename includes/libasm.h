// libasm.h
#ifndef LIBASM_H
#define LIBASM_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

uint64_t lcm_asm(uint64_t a, uint64_t b);
void rev_asm(char *buf, size_t len);
void revnum_asm(char *buf, int len);
void printarray_asm(void);
int max_asm(int* array, int count);
long gcd_asm(long a, long b);
void ispalindrome_asm(char* str, long end, long mid);
#ifdef __cplusplus
}
#endif

#endif // LIBASM_H

