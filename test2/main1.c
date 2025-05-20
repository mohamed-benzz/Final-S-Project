                                                                                                                                                                                                                                                                                                       main1.c                                                                                                                                                                                                                                                                                                                  
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "c_lib/c_lib.h"
#include "asm_lib/asm_lib.h"



double diff_time(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
}

int main() {
    int choice_func;
    int running = 1;

    while (running) {
        printf("\nChoose function:\n");
        printf("1 - Max of array\n");
        printf("2 - GCD\n");
        printf("3 - Palindrome check\n");
        printf("0 - Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice_func);

        if (choice_func == 0) break;

        struct timespec start, end;
        double time_c, time_asm;

        switch (choice_func) {
            case 1: {
                int n;
                printf("Enter number of elements: ");
                scanf("%d", &n);
                int array[n];
                printf("Enter %d integers separated by space:\n", n);
                for (int i = 0; i < n; ++i) {
                    scanf("%d", &array[i]);
                }

                clock_gettime(CLOCK_MONOTONIC, &start);
                int max_val_c = max_c(array, n);
                clock_gettime(CLOCK_MONOTONIC, &end);
                time_c = diff_time(start, end);

                clock_gettime(CLOCK_MONOTONIC, &start);
                int max_val_asm = max_asm(array, n);
                clock_gettime(CLOCK_MONOTONIC, &end);
                time_asm = diff_time(start, end);

                printf("Max (C): %d\nExecution time: %.9f seconds\n", max_val_c, time_c);
                printf("Max (ASM): %d\nExecution time: %.9f seconds\n", max_val_asm, time_asm);
                break;
            }
            case 2: {
                long a, b;
                printf("Enter two integers separated by space: ");
                scanf("%ld %ld", &a, &b);

                clock_gettime(CLOCK_MONOTONIC, &start);
                long res_c = gcd_c(a, b);
                clock_gettime(CLOCK_MONOTONIC, &end);
                time_c = diff_time(start, end);

                clock_gettime(CLOCK_MONOTONIC, &start);
                long res_asm = gcd_asm(a, b);
                clock_gettime(CLOCK_MONOTONIC, &end);
                time_asm = diff_time(start, end);

                printf("GCD (C): %ld\nExecution time: %.9f seconds\n", res_c, time_c);
                printf("GCD (ASM): %ld\nExecution time: %.9f seconds\n", res_asm, time_asm);
                break;
            }
            case 3: {
    char str[1000];
    printf("Enter string: ");
    while ((getchar()) != '\n' && !feof(stdin));
    if (fgets(str, sizeof(str), stdin) != NULL) {
        size_t len = strlen(str);
        if (len > 0 && str[len - 1] == '\n') {
            str[len - 1] = '\0';
        }
    } else {
        printf("Error reading input.\n");
        break;
    }

    clock_gettime(CLOCK_MONOTONIC, &start);
    ispalindrome_c(str);
    clock_gettime(CLOCK_MONOTONIC, &end);
    time_c = diff_time(start, end);

    clock_gettime(CLOCK_MONOTONIC, &start);
    ispalindrome_asm(str, strlen(str) - 1, strlen(str) / 2);
    clock_gettime(CLOCK_MONOTONIC, &end);
    time_asm = diff_time(start, end);

    printf("Execution time (C): %.9f seconds\n", time_c);
    printf("Execution time (ASM): %.9f seconds\n", time_asm);
    break;
}

            default:
                printf("Invalid function choice.\n");
                break;
        }
    }

    printf("Program exited.\n");
    return 0;
}
 











































