#pragma once
// All the data needed globally. Holds EVERYONE's location, 
// states and other necessary counters.
struct global_t 
{
    // people counters
    int total_number_of_people;
    int total_num_initially_infected; 
    int total_num_infected;
    // locations
    int *x_locations;
    int *y_locations;
    // infected people's locations
    int *their_infected_x_locations;
    int *their_infected_y_locations;
    // state
    char *states;
    // MPI related
    int total_number_of_processes;
};

// All the data private to each node: Data being used by 
// each process on a node in a cluster when using MPI.
// Each process holds data for location, states and 
// other necessary counters for a subset of people.
struct our_t 
{
    // current day
    int current_day;
    // MPI related 
    int our_rank;
    // people counters
    int our_number_of_people;
    int our_num_initially_infected;
    // states counters
    int our_num_infected;
    int our_num_susceptible;
    int our_num_immune;
    int our_num_dead; 
    // our people's locations
    int *our_x_locations;
    int *our_y_locations;
    // our infected people's locations
    int *our_infected_x_locations;
    int *our_infected_y_locations;
    // our people's states
    char *our_states;
    // our people's infected time
    int *our_num_days_infected;
};
// Data being used as constant
struct const_t 
{
    // environment
    int environment_width;
    int environment_height;
    // disease
    int infection_radius;
    int duration_of_disease;
    int contagiousness_factor;
    int deadliness_factor;
    // time
    int total_number_of_days;
    int microseconds_per_day;
};
// Data being used for the X display
struct display_t 
{
    #ifdef TEXT_DISPLAY
    // Array of character arrays for text display 
    char **environment;
    #endif

    #ifdef X_DISPLAY
    // Declare X-related variables 
    Display         *display;
    Window          window;
    int             screen;
    Atom            delete_window;
    GC              gc;
    XColor          infected_color;
    XColor          immune_color;
    XColor          susceptible_color;
    XColor          dead_color;
    Colormap        colormap;
    char            *red;
    char            *green;
    char            *black;
    char            *white;
    #endif
};

struct global_t global;
struct our_t our;
struct const_t constant;
struct stats_t stats;
struct display_t dpy;