#include <stdio.h>
#include <mpi.h>

int main()
{
    MPI_Init(NULL, NULL);
    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int number;
    MPI_Request send_request, recv_request;
    MPI_Status status;

    if (world_size < 2)
    {
        printf("This program requires at least 2 processes.\n");
        MPI_Finalize();
        return 1;
    }

    if (world_rank == 0)
    {
        number = 0;
        MPI_Isend(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &send_request);
        printf("Process 0 sent number %d to process 1 (non-blocking send).\n", number);

        MPI_Irecv(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &recv_request);
        MPI_Wait(&recv_request, &status);
        printf("Process 0 received number %d from process 1 (non-blocking receive).\n", number);
    }

    if (world_rank == 1)
    {
        number = 1;
        MPI_Irecv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &recv_request);
        MPI_Wait(&recv_request, &status);
        printf("Process 1 received number %d from process 0 (non-blocking receive).\n", number);

        MPI_Isend(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &send_request);
        printf("Process 1 sent number %d to process 0 (non-blocking send).\n", number);
    }

    MPI_Finalize();
    return 0;
}
