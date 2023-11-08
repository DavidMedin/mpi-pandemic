#include <stdio.h>
#include <mpi.h>

int main(){

    //mpi variables/setting up:
    int my_rank;
    int world_size;

    MPI_Init(NULL, NULL);

    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank); 
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    printf("There are %d nodes in this world\n", world_size);

    if(my_rank == 0){
        printf("(%d) Hi, I am root\n", my_rank);
    }else {
        printf("(%d) I am a node!\n", my_rank);
    }

	MPI_Finalize( );
    return 0;
}