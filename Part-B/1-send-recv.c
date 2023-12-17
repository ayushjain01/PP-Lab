#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int world_rank, world_size;
    int send_data, recv_data;

    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    if (world_size < 2)
    {
        printf("This program requires at least 2 processes\n");
        MPI_Finalize();
        return 1;
    }

    if (world_size == 0)
    {
        send_data = 123;
        MPI_Send(&send_data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        printf("Process %d sent data: %d\n", world_rank, send_data);
    }
    else if (world_rank == 1)
    {
        MPI_Recv(&recv_data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process %d received data: %d\n", world_rank, recv_data);
    }

    MPI_Finalize();
    return 0;
}
