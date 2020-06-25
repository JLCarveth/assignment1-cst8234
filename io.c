/*
Module manages input and output operations

    Author:
        - John L. Carveth <jlcarveth@gmail.com>
*/
#include <stdio.h>
#include <stdlib.h>

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

// Clears input streams of extraneous input
void flush() {
    int c;
    while( (c = fgetc( stdin )) != EOF && c != '\n' );
}
