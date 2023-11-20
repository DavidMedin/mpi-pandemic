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


    int n_people = 10;
    int init_inf = 1;
    int env_width = 40;
    int env_height = 40;
    int time_days = 100;
    int disease_dur = 3;
    int contagin_factor = 3;
    int infect_radius = 2;
    int deadliness = 4;
    int msec_in_day = 10000;
    if(argc > 1) {
        // Find what arguments were used
        for(int arg_i = 1;arg_i < argc; arg_i+=2){
            char* option_str = argv[arg_i];
            char* option_str_val = argv[arg_i+1];

            int option_val = atoi(option_str_val); // atoi takes a string and tries to turn it into an interger. '12' -> 12
            //                                        But the return value 0 is also the error return value. So to find
            //                                        whether the user inputed '0' or 'hi', we need to see if the input string
            //                                        is just zeros to really determine whether it is an error or if the user
            //                                        ment 'zero'.
            if(option_val == 0 && !is_zero_string(option_str_val)){
                // Panic! (at the disco)
                printf("Malformed input parameters for '%s': \"%s\" is not a number.", option_str, option_str_val);
                exit(1); // Tip over.
            }

            if      (strcmp(option_str, "-n") == 0) {
                n_people = option_val;
            }else if(strcmp(option_str, "-i") == 0){
                init_inf = option_val;
            }else if(strcmp(option_str, "-w") == 0){
                env_width = option_val;
            }else if(strcmp(option_str, "-h") == 0){
                env_height = option_val;
            }else if(strcmp(option_str, "-t") == 0){
                time_days = option_val;
            }else if(strcmp(option_str, "-T") == 0){
                disease_dur = option_val;
            }else if(strcmp(option_str, "-c") == 0){
                contagin_factor = option_val;
            }else if(strcmp(option_str, "-d") == 0){
                infect_radius = option_val;
            }else if(strcmp(option_str, "-D") == 0){
                deadliness = option_val;
            }else if(strcmp(option_str, "-m") == 0){
                msec_in_day = option_val;
            }else{
                printf("Invalid option '%s'.\n", option_str);
                exit(1); // tip over
            }

        }
    }

    //mpi variables/setting up:
    int my_rank;
    int world_size;


    printf("There are %d nodes in this world\n", world_size);

    if(DEBUG && my_rank == 0){
        printf("'%s': %d\n", "n_people", n_people);
        printf("'%s': %d\n", "init_inf", init_inf);
        printf("'%s': %d\n", "env_width", env_width);
        printf("'%s': %d\n", "env_height", env_height);
        printf("'%s': %d\n", "time_days", time_days);
        printf("'%s': %d\n", "disease_dur", disease_dur);
        printf("'%s': %d\n", "contagin_factor", contagin_factor);
        printf("'%s': %d\n", "infect_radius", infect_radius);
        printf("'%s': %d\n", "deadliness", deadliness);
        printf("'%s': %d\n", "msec_in_day", msec_in_day);
    }
    if(my_rank == 0){
        printf("(%d) Hi, I am root\n", my_rank);
    }else {
        printf("(%d) I am a node!\n", my_rank);
    }

	MPI_Finalize( );
    return 0;
}