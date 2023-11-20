#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mpi.h>

#include "defaults.h"
#include "initialize.h"
#include "infection.h"
#include "core.h"
#include "finalize.h"

#if defined(X_DISPLAY) || defined(TEXT_DISPLAY)
#include "display.h"
#endif

#define DEBUG 1

int is_zero_string(char* input) {
    for(int i = 0;i < strlen(input);i++){
        if(input[i] != '0') {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char** argv){
    /*
    -n number of people
    -i number of initally infected
    -w width of environment
    -h height of environment
    -t number of time days in the model
    -T duration of disease in days
    -c contagiousness factor of disease
    -d infection radius
    -D deadliness factor
    -m number of actual microseconds between days
    */

    // for(int i = 0;i < argc;i++){
    //     printf("%d: %s\n",i, argv[i]);
    // }
    init(&global, &our, &constant, &stats, &dpy, &argc, &argv);
    // for(our.current_day = 0; our.current_day <= constant.total_number_of_days; our.current_day++)
    // {
    // }


    //mpi variables/setting up:
    int my_rank;
    int world_size;


    printf("There are %d nodes in this world\n", world_size);

    if(DEBUG && my_rank == 0){
        // printf("'%s': %d\n", "n_people", n_people);
        // printf("'%s': %d\n", "init_inf", init_inf);
        // printf("'%s': %d\n", "env_width", env_width);
        // printf("'%s': %d\n", "env_height", env_height);
        // printf("'%s': %d\n", "time_days", time_days);
        // printf("'%s': %d\n", "disease_dur", disease_dur);
        // printf("'%s': %d\n", "contagin_factor", contagin_factor);
        // printf("'%s': %d\n", "infect_radius", infect_radius);
        // printf("'%s': %d\n", "deadliness", deadliness);
        // printf("'%s': %d\n", "msec_in_day", msec_in_day);
    }
    if(my_rank == 0){
        printf("(%d) Hi, I am root\n", my_rank);
    }else {
        printf("(%d) I am a node!\n", my_rank);
    }

	MPI_Finalize( );
    return 0;
}