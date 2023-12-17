#include <stdio.h>
#include <mpi.h>

#define ARRAY_SIZE 3

int main(int argc, char *argv[])
{
    int world_rank, world_size;
    int send_data[] = {1, 2, 3};
    int recv_data[ARRAY_SIZE];

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
        MPI_Send(send_data, ARRAY_SIZE, MPI_AINT, 1, 0, MPI_COMM_WORLD);
        printf("Process %d sent data: ", world_rank);
        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            printf("%d ", send_data[i]);
        }
        printf("\n");
    }
    else if (world_rank == 1)
    {
        MPI_Recv(recv_data, ARRAY_SIZE, MPI_AINT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process %d received data: ", world_rank);
        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            printf("%d ", recv_data[i]);
        }
        printf("\n");
    }

    MPI_Finalize();
    return 0;
}
