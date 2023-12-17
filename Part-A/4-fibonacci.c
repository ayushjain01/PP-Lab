#include <stdio.h>
#include <omp.h>

void calculate_fibonacci_schedule(int n)
{
    int fib[n];
    fib[0] = 0;
    fib[1] = 1;

#pragma omp parallel
    {
#pragma omp for schedule(dynamic)
        for (int i = 2; i < n; i++)
        {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
    }

    printf("Fibonacci Sequence (Schedule): ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", fib[i]);
    }
    printf("\n");
}

void calculate_fibonacci_no_schedule(int n)
{
    int fib[n];
    fib[0] = 0;
    fib[1] = 1;

#pragma omp parallel
    {
#pragma omp for
        for (int i = 2; i < n; i++)
        {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
    }

    printf("Fibonacci Sequence (No Schedule): ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", fib[i]);
    }
    printf("\n");
}

int main()
{
    int n = 15; 
    calculate_fibonacci_schedule(n);
    calculate_fibonacci_no_schedule(n);
    return 0;
}