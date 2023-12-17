#include <stdio.h>
#include <mpi.h>

int main()
{
    MPI_Init(NULL, NULL);
    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Perform Phase 1
    printf("Process %d performing Phase 1.\n", world_rank);

    fflush(stdout);
    MPI_Barrier(MPI_COMM_WORLD);

    // Perform Phase 2
    printf("Process %d performing Phase 2.\n", world_rank);

    MPI_Finalize();
    return 0;
}
