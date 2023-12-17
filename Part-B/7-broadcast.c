#include <mpi.h>
#include <stdio.h>

int main()
{
    int rank;
    int buff[2];
    const int root = 1;
    MPI_Init(NULL, NULL);
    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    if (rank == root)
    {
        buff[0] = 111;
        buff[1] = 777;
    }

    printf("Process [%d] Before broadcast:\n", rank);
    for (int i = 0; i < 2; ++i)
    {
        printf("buff[%d] is %d\n", rank, i, buff[i]);
    }

    MPI_Bcast(buff, 2, MPI_INT, root, MPI_COMM_WORLD);

    printf("Process [%d] After broadcast:\n", rank);
    for (int i = 0; i < 2; ++i)
    {
        printf("buff[%d] is %d\n", rank, i, buff[i]);
    }
    MPI_Finalize();
    return 0;
}
