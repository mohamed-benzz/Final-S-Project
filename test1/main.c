// main.c
#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include "libcc.h"
#include "libasm.h"


static inline double elapsed_us(struct timespec a, struct timespec b) {
    return (b.tv_sec - a.tv_sec)*1e6 + (b.tv_nsec - a.tv_nsec)/1e3;
}
  

int main(void) {
   
        printf("\nMenu:\n"
               " 1) LCM (C vs ASM)\n"
               " 2) Reverse string (C vs ASM)\n"
               " 3) Reverse number (C vs ASM)\n"
	       " 4) Print array (C vs ASM)\n"
               " 0) Quit\n"
               "Choice: ");

        int choice;
        if (scanf("%d%*c", &choice) != 1) {
            return 0;  // EOF or invalid → exit
        }

        if (choice == 0) {
            return 0;  // user chose to quit
        }

        struct timespec t0, t1;
        double dt_c, dt_asm;

        if (choice == 1) {
            uint64_t a, b;
            printf("Enter two numbers: ");
            if (scanf("%" SCNu64 " %" SCNu64, &a, &b) != 2) return 0;

            clock_gettime(CLOCK_MONOTONIC, &t0);
            uint64_t r1 = lcm_c(a,b);
            clock_gettime(CLOCK_MONOTONIC, &t1);
            dt_c = elapsed_us(t0, t1);

            clock_gettime(CLOCK_MONOTONIC, &t0);
            uint64_t r2 = lcm_asm(a,b);
            clock_gettime(CLOCK_MONOTONIC, &t1);
            dt_asm = elapsed_us(t0, t1);

            printf(" C  LCM = %" PRIu64 " @ %.3f μs\n", r1, dt_c);
            printf("ASM LCM = %" PRIu64 " @ %.3f μs\n", r2, dt_asm);
            printf(" Speedup = %.2f×\n", dt_c / dt_asm);

        } else if (choice == 2) {
            char buf[128];
            char newbuf[128];
            printf("Enter string: ");
            if (!fgets(buf, sizeof(buf), stdin)) return 0;
            size_t len = strcspn(buf, "\n");
            buf[len] = '\0';
            strcpy(newbuf, buf);

            clock_gettime(CLOCK_MONOTONIC, &t0);
            rev_c(buf, len);
            clock_gettime(CLOCK_MONOTONIC, &t1);
            dt_c = elapsed_us(t0, t1);
            printf(" C rev:  \"%s\" @ %.3f μs\n", buf, dt_c);

            clock_gettime(CLOCK_MONOTONIC, &t0);
            rev_asm(newbuf, len);
            clock_gettime(CLOCK_MONOTONIC, &t1);
            dt_asm = elapsed_us(t0, t1);
            printf("ASM rev: \"%s\" @ %.3f μs\n", newbuf, dt_asm);

            printf(" Speedup = %.2f×\n", dt_c / dt_asm);

        } else if (choice == 3) {
            char buf[128], orig[128];
            printf("Enter number: ");
            if (!fgets(buf, sizeof(buf), stdin)) return 0;
            size_t len = strcspn(buf, "\n");
            buf[len] = '\0';
            strcpy(orig, buf);

            clock_gettime(CLOCK_MONOTONIC, &t0);
            revnum_c(buf, len);
            clock_gettime(CLOCK_MONOTONIC, &t1);
            dt_c = elapsed_us(t0, t1);
            printf(" C revnum:  \"%s\" @ %.3f μs\n", buf, dt_c);

            strcpy(buf, orig);
            clock_gettime(CLOCK_MONOTONIC, &t0);
            revnum_asm(buf, len);
            clock_gettime(CLOCK_MONOTONIC, &t1);
            dt_asm = elapsed_us(t0, t1);
            printf("ASM revnum: \"%s\" @ %.3f μs\n", buf, dt_asm);

            printf(" Speedup = %.2f×\n", dt_c / dt_asm);

        } else if (choice == 4) {
            int arr[] = {11, 1, 8, 2, 4, 0, 5, 1, 20, 5};
          
            char buf[32];  // used by C version, just to match style

            clock_gettime(CLOCK_MONOTONIC, &t0);
            printarray_c();  // C version prints to stdout
            clock_gettime(CLOCK_MONOTONIC, &t1);
            dt_c = elapsed_us(t0, t1);
            printf(" C printarray done @ %.3f μs\n", dt_c);

            clock_gettime(CLOCK_MONOTONIC, &t0);
            printarray_asm();  // ASM version prints directly
            clock_gettime(CLOCK_MONOTONIC, &t1);
            dt_asm = elapsed_us(t0, t1);
            printf("ASM printarray done @ %.3f μs\n", dt_asm);

            printf(" Speedup = %.2f×\n", dt_c / dt_asm);
	}
       	else {
            // now catches any integer outside 0–3
            printf("Invalid choice\n");
        }
    return 0;
}

