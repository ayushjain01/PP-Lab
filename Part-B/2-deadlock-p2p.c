#include <stdio.h>
#include <mpi.h>

int main()
{
    int world_rank, world_size;
    int send_data = 10, recv_data;

    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    if (world_size < 2)
    {
        printf("This program requires at least 2 processes\n");
        MPI_Finalize();
        return 1;
    }

    if (world_rank == 0)
    {
        MPI_Send(&send_data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        printf("Process %d sent data: %d\n", world_rank, send_data);

        // Process 0 tries to receive data from process 1, leading to a deadlock
        MPI_Recv(&recv_data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }
    else if (world_rank == 1)
    {
        MPI_Send(&send_data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        printf("Process %d sent data: %d\n", world_rank, send_data);

        // Process 1 tries to receive data from process 0, leading to a deadlock
        MPI_Recv(&recv_data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }

    MPI_Finalize();
    return 0;
}
