#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SIZE 1000000

void parallel_vector_addition(int *a, int *b, int *result, int size)
{
#pragma omp parallel for
    for (int i = 0; i < size; i++)
    {
        result[i] = a[i] + b[i];
    }
}

int main()
{
    int *vectorA, *vectorB, *result;
    int i;

    vectorA = (int *)malloc(SIZE * sizeof(int));
    vectorB = (int *)malloc(SIZE * sizeof(int));
    result = (int *)malloc(SIZE * sizeof(int));

    for (i = 0; i < SIZE; i++)
    {
        vectorA[i] = rand() % 100;
        vectorB[i] = rand() % 100;
    }

    double start = omp_get_wtime();
    parallel_vector_addition(vectorA, vectorB, result, SIZE);
    double end = omp_get_wtime();

    printf("Vector A:\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d\t", vectorA[i]);
    }

    printf("\nVector B:\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d\t", vectorB[i]);
    }

    printf("\nResult Array :\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d\t", result[i]);
    }

    printf("\nTime taken for parallel vector addition is %f", end - start);
    free(vectorA);
    free(vectorB);
    free(result);

    return 0;
}
