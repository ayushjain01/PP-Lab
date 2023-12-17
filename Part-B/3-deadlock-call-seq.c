#include <stdio.h>
#include <mpi.h>

int main()
{
    MPI_Init(NULL, NULL);
    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int number;
    MPI_Request request;

    if (world_rank == 0)
    {
        number = 0;
        MPI_Ssend(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Recv(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("\nProcess 0 sent number %d to process 1 ", number);
    }

    if (world_rank == 1)
    {
        number = 1;
        MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Ssend(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        printf("\nProcess 1 received number %d from process 0", number);
    }

    MPI_Finalize();
    return 0;
}
