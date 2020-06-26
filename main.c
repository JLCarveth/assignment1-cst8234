/*
CST 8234
Assignment 1

Checkout this project on GitHub!
    https://github.com/jlcarveth/assignment1-cst8234

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
            printf(PROMPT_STUDENT);
            int studentID = getStudentID();
            int studentIndex = indexOfInt(pStudents, MAX_STUDENTS, studentID);
            while (studentIndex == -1) {
                printf(STUDENT_NOT_FOUND"\n", studentID);
                studentID = getStudentID();
                studentIndex = indexOfInt(pStudents, MAX_STUDENTS, studentID);
            }

            char * courseCode = getCourseCode();
            int courseIndex = indexOfString(pCourses, MAX_COURSES, courseCode);
            while (courseIndex == -1) {
                printf(COURSE_NOT_FOUND"\n", courseCode);
                courseCode = getCourseCode();
                courseIndex = indexOfString(pCourses, MAX_COURSES, courseCode);
            }

            setValue(registrationTable, studentIndex, courseIndex, 1);
    	}

    	//drop a student's course
        // TODO: This code block is duplicated from abover
        // extract to it's own method
    	else if (action ==2 ) {
            printf(PROMPT_STUDENT);
            int studentID = getStudentID();
            int studentIndex = indexOfInt(pStudents, MAX_STUDENTS, studentID);
            while (studentIndex == -1) {
                printf(STUDENT_NOT_FOUND"\n", studentID);
                studentID = getStudentID();
                studentIndex = indexOfInt(pStudents, MAX_STUDENTS, studentID);
            }

            char * courseCode = getCourseCode();
            int courseIndex = indexOfString(pCourses, MAX_COURSES, courseCode);
            while (courseIndex == -1) {
                printf(COURSE_NOT_FOUND"\n", courseCode);
                courseCode = getCourseCode();
                courseIndex = indexOfString(pCourses, MAX_COURSES, courseCode);
            }

            setValue(registrationTable, studentIndex, courseIndex, 0);
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
