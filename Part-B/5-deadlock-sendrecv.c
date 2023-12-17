#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main()
{

    MPI_Init(NULL, NULL);
    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    if (world_size < 2)
    {
        printf("This program requires at least 2 processes.\n");
        MPI_Finalize();
        return 1;
    }

    int send_number = world_rank;
    int recv_number;

    int target_rank = (world_rank + 1) % world_size;
    int source_rank = (world_rank - 1 + world_size) % world_size;

    MPI_Sendrecv(&send_number, 1, MPI_INT, target_rank, 0, &recv_number, 1, MPI_INT, source_rank, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

    printf("\nProcess %d sent %d to process %d and received %d from process %d ", world_rank, send_number, target_rank, recv_number, source_rank);

    MPI_Finalize();
    return 0;
}