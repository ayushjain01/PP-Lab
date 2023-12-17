#include <stdio.h>
#include <mpi.h>

int main() {
    MPI_Init(NULL, NULL);
    
    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int send_value = world_rank + 1;
    int recv_max, recv_min, recv_sum, recv_prod;

    MPI_Reduce(&send_value, &recv_max, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);

    MPI_Reduce(&send_value, &recv_min, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);

    MPI_Reduce(&send_value, &recv_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    MPI_Reduce(&send_value, &recv_prod, 1, MPI_INT, MPI_PROD, 0, MPI_COMM_WORLD);

    if (world_rank == 0) {
        printf("MPI_MAX result: %d\n", recv_max);
        printf("MPI_MIN result: %d\n", recv_min);
        printf("MPI_SUM result: %d\n", recv_sum);
        printf("MPI_PROD result: %d\n", recv_prod);
    }

    MPI_Finalize();
    return 0;
}
