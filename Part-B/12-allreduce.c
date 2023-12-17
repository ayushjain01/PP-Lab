#include <stdio.h>
#include <mpi.h>

int main()
{
    MPI_Init(NULL, NULL);

    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int send_value = world_rank + 1;
    int recv_max, recv_min, recv_sum, recv_prod;

    MPI_Allreduce(&send_value, &recv_max, 1, MPI_INT, MPI_MAX, MPI_COMM_WORLD);

    MPI_Allreduce(&send_value, &recv_min, 1, MPI_INT, MPI_MIN, MPI_COMM_WORLD);

    MPI_Allreduce(&send_value, &recv_sum, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);

    MPI_Allreduce(&send_value, &recv_prod, 1, MPI_INT, MPI_PROD, MPI_COMM_WORLD);

    printf("Process %d - MPI_MAX result: %d\n", world_rank, recv_max);
    printf("Process %d - MPI_MIN result: %d\n", world_rank, recv_min);
    printf("Process %d - MPI_SUM result: %d\n", world_rank, recv_sum);
    printf("Process %d - MPI_PROD result: %d\n", world_rank, recv_prod);

    MPI_Finalize();
    return 0;
}
