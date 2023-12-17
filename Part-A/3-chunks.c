#include <stdio.h>
#include <omp.h>

int main()
{
    int num_iterations;
    printf("Enter number of iterations:");
    scanf("%d", &num_iterations);
    int thread_id, i;

    omp_set_num_threads(2);

#pragma omp parallel private(thread_id, i)
    {
        thread_id = omp_get_thread_num();

#pragma omp for schedule(static, 2)
        for (i = 0; i < num_iterations; i++)
        {
            printf("Thread %d : Iterations %d\n", thread_id, i);
        }
    }

    return 0;
}
