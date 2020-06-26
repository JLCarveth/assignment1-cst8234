/*
Module for initializing and modifying the registration table
initializeTable must be called first, as the function returns
a pointer to the memory allocated for the table.
This pointer is then passed to getValue or setValue to modify
the table contents

    Author(s):
        - John L. Carveth <jlcarveth@gmail.com>
*/
#include <stdlib.h>

#include "registration.h"

int MAX_STUDENTS;
int MAX_COURSES;

// Initializes a 2D integer array of size 
// [students][courses]
// Returns a pointer to the array
int * initializeTable (int students, int courses) {
    int *table = (int *) malloc(students * courses * sizeof(int));
    MAX_STUDENTS = students;
    MAX_COURSES = courses;
    // Initialize all values in matrix to 0
    for (int i = 0; i < students; i++) {
        for (int j = 0; j < courses; j++) {
            *(table + i*students + j) = 0;
        }
    }
    return table;
}

// Returns the value of the given position
// Returns -1 if coordinates out of bounds
int getValue (int * table, int s, int c) {
    if (s < 0 || s > MAX_STUDENTS-1 || c < 0 || c > MAX_COURSES-1) {
        return -1;
    }
    return *(table + s*MAX_STUDENTS + c);
}

// Inserts value into the given position of table
void setValue (int * table, int s, int c, int value) {
    if (s < 0 || s > MAX_STUDENTS-1 || c < 0 || c > MAX_COURSES-1) {
        return;
    }
    *(table + s*MAX_STUDENTS + c) = value;
}