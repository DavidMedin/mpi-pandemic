#pragma once
#include "defaults.h"

void parse_args(struct global_t* global, struct const_t* const_arg, int* argc, int*** argv){

    if(*argc > 1) {
        // Find what arguments were used
        for(int arg_i = 1;arg_i < *argc; arg_i+=2){
            char* option_str = (*argv)[arg_i];
            char* option_str_val = (*argv)[arg_i+1];

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
                global->total_number_of_people = option_val;
            }else if(strcmp(option_str, "-i") == 0){
                // init_inf = option_val;
                global->total_num_initially_infected = option_val;
            }else if(strcmp(option_str, "-w") == 0){
                // env_width = option_val;
                const_arg->environment_width = option_val;
            }else if(strcmp(option_str, "-h") == 0){
                // env_height = option_val;
                const_arg->environment_height = option_val;
            }else if(strcmp(option_str, "-t") == 0){
                // time_days = option_val;
                const_arg->total_number_of_days = option_val;
            }else if(strcmp(option_str, "-T") == 0){
                // disease_dur = option_val;
                const_arg->duration_of_disease = option_val;
            }else if(strcmp(option_str, "-c") == 0){
                // contagin_factor = option_val;
                const_arg->contagiousness_factor = option_val;
            }else if(strcmp(option_str, "-d") == 0){
                // infect_radius = option_val;
                const_arg->infection_radius = option_val;
            }else if(strcmp(option_str, "-D") == 0){
                // deadliness = option_val;
                const_arg->deadliness_factor = option_val;
            }else if(strcmp(option_str, "-m") == 0){
                // msec_in_day = option_val;
                const_arg->microseconds_per_day = option_val;
            }else{
                printf("Invalid option '%s'.\n", option_str);
                exit(1); // tip over
            }

        }
    }
}

void init(struct global_t* global,struct our_t* our,struct const_t* const_arg,struct stats_t* stats,struct display_t* display, int* argc, int*** argv){
    MPI_Init(argc, argv);

    #ifdef _MPI
    MPI_Comm_rank(MPI_COMM_WORLD, &our->our_rank); 
    MPI_Comm_size(MPI_COMM_WORLD, &global->total_number_of_processes);
    #else
        our->our_rank = 0;
        global->total_number_of_processes = 1;
    #endif
    

    init_check(global);
    parse_args(global, const_arg, argc, argv);
    allocate_array(global, our, const_arg, dpy);
    init_array(our, const_arg);
    // if use X_DISPLAY, do init_display()
    #ifdef X_DISPLAY
        init_display(our, const_arg, dpy);
    #endif
}
