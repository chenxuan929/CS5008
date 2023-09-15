#include <stdio.h>
#include <stdlib.h> 
#include <stdint.h>
#include <stdbool.h>

#define MAX 50000

typedef uint64_t ull;

static ull fib_table[MAX];

ull fib_iterative(int n) {
    uint64_t fibTotal = 0, fib1 = 0, fib2 = 1;
    for (int i = 0; i < n; i++) {
        fibTotal = fib1 + fib2;
        fib1 = fib2;
        fib2 = fibTotal;
    }
    return fib1;
}

ull fib_recursive(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fib_recursive(n-1) + fib_recursive(n-2);
    }
}

ull fib_dynamic(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    fib_lst[0] = 0;
    fib_lst[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib_lst[i] = fib_lst[i - 1] + fib_table[i - 2];
    }
    ull answer = fib_lst[n];
    return answer;
}

int getFib(int n, int version) {
    int temp;
    if (version == 0) {
        temp = fib_iterative(n);
    } else if (version == 1) {
        temp = fib_recursive(n);
    } else {
        for (int i = 0; i < MAX; i++) {
            fib_table[i] = 0;
        }
        fib_table[1] = 1;
        temp = fib_dynamic(n);
    }
    return temp;
}

int* print_fib_series(int n, bool print, int version) {
    int* fibArr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        int temp = getFib(i, version);
        fibArr[i] = temp;
        if (print) {
            printf("%d\t", temp);
        }
    }
    if (print) {
        printf("\n");
    }
    free(fibArr);
    return fibArr;
}

void help() {
printf("./fibonacci.out N [Type] [Print Level]\n");
printf("\tN is the number in the Fibonacci series to calculate, required.\n");
printf("\t[Type] is either 2 for dynamic programming version, 1 for recursive version, 0 for iterative version, defaults to 0.\n");
printf("\t[Print Level] is 0 for no print/speed compare only, 1 for print nth value only, 2 for print first N values, defaults to 0.\n");
}


int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Need 2 or more arguments.\n");
        help();
        return 1;
    }

    const int n = atoi(argv[1]);
    int version = 0;
    int printLevel = 0;

    if (argc > 2) {
        version = atoi(argv[2]);
    }

    if (argc > 3) {
        printLevel = atoi(argv[3]);
    }
    bool print = false;
    if (printLevel > 1) {
        print = true;
    }
    int* fib_series = print_fib_series(n, print, version);
    if (printLevel == 1) {
        printf("%d\n", getFib(n, version));
    }

    return 0;
}
    
