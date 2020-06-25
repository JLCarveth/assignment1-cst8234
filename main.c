/*
CST 8234
Assignment 1

    Author(s):
        - John L. Carveth (040937145) <jlcarveth@gmail.com>
*/

#include <stdio.h>

// Project dependencies
#include "io.h"
#include "helper.h"
#include "registration.h"

int MAX_STUDENTS;
int MAX_COURSES;

int main() {
    
    setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
    
    // Print software info - title, version, author, etc
    printInfo();

    // prompt user for # of students to register
    MAX_STUDENTS = getMaxStudents();

    // prompt user for student ids
    int *pStudents;
    pStudents = getNStudents(MAX_STUDENTS);
    printIntArray(pStudents,MAX_STUDENTS);

    // prompt the user for # of courses
    MAX_COURSES = getMaxCourses();

    // prompt the user for course codes
    char **pCourses;
    pCourses = getNCourses(MAX_COURSES);
    printStringArray(pCourses,MAX_COURSES);

    // Initialize the registration table
    int * registrationTable = initializeTable(MAX_STUDENTS,MAX_COURSES);

    printMainLoop();
    int action;

    while (action != 4) {
        action = getAction();
    
        //register student in a course
    	if(action == 1) {
            //TODO
            // get student id
            // get course id
            // get index of both
            // set registrationTable value to 1
            printf("Register...\n");
    	}

    	//drop a student's course
    	else if (action ==2 ) {
            //TODO
            // get student id
            // get course id
            // get index of both
            // set registrationTable value to 0
            printf("Drop...\n");
    	}

    	//print registration table
    	else if (action ==3 ) {
            print2DArray(registrationTable, MAX_STUDENTS, MAX_COURSES);
    	}

    	//exit
    	else if (action == 4) {
            // Nothing todo here :)
    		return 0;
    	}
    
    }

    return 0;
}
