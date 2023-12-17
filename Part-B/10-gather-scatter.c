#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main()
{
    MPI_Init(NULL, NULL);
    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int data[world_size];
    for (int i = 0; i < world_size; i++)
    {
        data[i] = rand() % 100;
    }
    int recv_data;
    int gathered_data[world_size];

    MPI_Scatter(data, 1, MPI_INT, &recv_data, 1, MPI_INT, 0, MPI_COMM_WORLD);
    printf("\nProcess %d received data: %d", world_rank, recv_data);

    MPI_Barrier(MPI_COMM_WORLD);

    recv_data += 10;

    MPI_Gather(&recv_data, 1, MPI_INT, gathered_data, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (world_rank == 0)
    {
        printf("\nData gathered after adding 10 is:\n");
        for (int i = 0; i < world_size; i++)
        {
            printf("%d\t", gathered_data[i]);
        }
        printf("\n");
    }

    MPI_Finalize();
    return 0;
}
