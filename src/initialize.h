#pragma once
#include "defaults.h"
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
    parse_args(global, constant, argc, argv);
    allocate_array(global, our, constant, dpy);
    

}