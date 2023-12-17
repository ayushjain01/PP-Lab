#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int isPrime(int num)
{
    if (num <= 1)
        return 0; 
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    double start_serial = omp_get_wtime();
    printf("Prime numbers from 1 to %d (serial):\n", n);
    for (int i = 1; i <= n; i++)
    {
        if (isPrime(i))
        {
            printf("%d\n", i);
        }
    }
    printf("\n");
    double end_serial = omp_get_wtime();
    printf("Serial Execution Time: %f seconds\n", end_serial - start_serial);

    double start_parallel = omp_get_wtime(); 
    printf("Prime numbers from 1 to %d (parallel):\n", n);
#pragma omp parallel for
    for (int i = 1; i <= n; i++)
    {
        if (isPrime(i))
        {
#pragma omp critical
            printf("%d (Thread - %d)\n", i, omp_get_thread_num());
        }
    }
    printf("\n");
    double end_parallel = omp_get_wtime(); 
    printf("Parallel Execution Time: %f seconds\n", end_parallel - start_parallel);

    return 0;
}
