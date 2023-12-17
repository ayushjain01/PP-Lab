#include <stdio.h>
#include <omp.h>
#include <time.h>

#define NUM_THREADS 12
static long num_steps = 100000000;
double step;

int main()
{
    int i;
    double pi_serial, pi_parallel;
    double start_serial, end_serial, start_parallel, end_parallel;
    step = 1.0 / (double)num_steps;
    double sum_parallel[NUM_THREADS];
    double sum_serial = 0.0;
    double x;

    // Sequential Calculation of pi
    start_serial = omp_get_wtime();
    for (i = 0; i < num_steps; i++)
    {
        x = (i + 0.5) * step;
        sum_serial += 4.0 / (1.0 + x * x);
    }
    pi_serial = step * sum_serial;
    end_serial = omp_get_wtime();

    printf("Serial pi = %6.12f\n", pi_serial);
    printf("Serial execution time: %f seconds\n", end_serial - start_serial);

    // Parallel Calculation of pi
    start_parallel = omp_get_wtime();

#pragma omp parallel private(i, x)
    {
        int id = omp_get_thread_num();
        for (i = id, sum_parallel[id] = 0.0; i < num_steps; i += NUM_THREADS)
        {
            x = (i + 0.5) * step;
            sum_parallel[id] += 4.0 / (1 + x * x);
        }
    }
    for (i = 1; i < NUM_THREADS; i++)
    {
        sum_parallel[0] += sum_parallel[i];
    }
    pi_parallel = sum_parallel[0] / num_steps;
    end_parallel = omp_get_wtime();

    printf("Parallel pi = %6.12f\n", pi_parallel);
    printf("Parallel execution time: %f seconds\n", end_parallel - start_parallel);

    return 0;
}
