/*
Module manages input and output operations

Potential improvements:
    - Generify some of the methods, for DRY principles.
        - Ex. single method to get string input of length n, same for int

    Author:
        - John L. Carveth <jlcarveth@gmail.com>
*/
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "io.h"
#include "format.h"

// Returns program version as string
char * getVersion() {
    char *buffer = malloc(11);
    int n = sprintf(buffer,"%d.%d.%d", MAJOR_VERSION, MINOR_VERSION, PATCH_VERSION);
    return buffer;
}

// Prints program information
void printInfo() {
    char *stars = repeatChar('*',100);
    printf("%s\n",stars);
    printf("%s\n", WELCOME_MSG);
    char *version = getVersion();
    printf("%s %s\n","Version: ", version);
    printf("%s\n",stars);
}

void printMainLoop() {
    printf(MAIN_LOOP_PROMPT"\n");
    printf("\t"ACTION_REGISTER"\n");
    printf("\t"ACTION_DROP"\n");
    printf("\t"ACTION_PRINT"\n");
    printf("\t"ACTION_QUIT"\n");
}

// Get user input for max students to register
int getMaxStudents() {
    printf("%s ", INQUIRY_STUDENTS);
    int max;
    scanf("%d", &max);
    return max;
}

// Get user input for max courses to register
int getMaxCourses() {
    printf("%s ", INQUIRY_COURSES);
    int max;
    scanf("%d", &max);
    return max;
}

int getStudentID() {
    int studentID;
    printf(PROMPT_STUDENT);
    scanf("%5d", &studentID);
    flush();
    return studentID;
}

// Get a 7-digit course code from the user
char * getCourseCode() {
    printf(PROMPT_COURSE);
    char * courseCode = malloc(8);
    scanf("%7s", courseCode);
    flush();
    return courseCode;
}

// Get n 5-digit student IDs from the user
// Longer inputs will be truncated
int * getNStudents(int n) {
    int *students = calloc(n, sizeof(int));
    for (int i=0; i < n; i++) {
        printf(INQUIRY_STUDENT_ID"\n", i+1);
        scanf("%5d", &students[i]);
        flush();
    }
    return students;
}

// Get n 7-digit alphanumeric course codes
char ** getNCourses(int n) {
    char **courses;
    courses = malloc(n * sizeof(char *));

    for (int i=0; i<n; i++) {
        printf(INQUIRY_COURSE_CODE"\n", i+1);
        courses[i] = malloc(8);
        scanf("%7s", courses[i]);
        flush();
    }

    return courses;
}

// Gathers integer between 1-4 from the user
int getAction() {
    int input;

    while (!(input <= 4 && input >= 1)) {
        printf(ACTION_PROMPT);
        scanf("%d", &input);
        flush();
    }

    return input;
}

// Returns the index of given value within array,
// or -1 if no such value was found
int indexOfInt(int * array, int size, int value) {
    int i;
    for (i = 0; i < size; i++) {
        if (value == array[i]) {
            return i;
        }
    }
    return -1;
}
// Returns the index of the given value within the array,
// or -1 if no such string is found
int indexOfString(char ** array, int size, char * value) {
    int i;
    for (int i=0; i<size; i++) {
        if (strcmp(array[i], value) == 0) {
            return i;
        }
    }
    return -1;
}

// Clears input streams of extraneous input
void flush() {
    int c;
    while( (c = fgetc( stdin )) != EOF && c != '\n' );
}
