#include <stdio.h>
#include <omp.h>

int main()
{
    int sum = 0;

#pragma omp parallel for
    for (int i = 1; i <= 100; i++)
    {
#pragma omp critical
        sum += i;
    }

    printf("The sum of the first 100 numbers is: %d\n", sum);

    return 0;
}
