// libcc.h
#ifndef LIBCC_H
#define LIBCC_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

uint64_t lcm_c(uint64_t a, uint64_t b);
void rev_c(char *buf, size_t len);
void revnum_c(char *buf, int len);
void printarray_c(void);


#ifdef __cplusplus
}
#endif

#endif // LIBCC_H

