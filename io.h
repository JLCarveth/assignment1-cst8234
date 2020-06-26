#define MAJOR_VERSION 1
#define MINOR_VERSION 0
#define PATCH_VERSION 0

// static strings to be printed to the console
#define WELCOME_MSG "Welcome to the Student Information and Registration System (SIRS)"
#define INQUIRY_STUDENTS "How many students do you wish to register?"
#define INQUIRY_STUDENT_ID "Please enter the ID for student %d: "
#define INQUIRY_COURSES "How many courses are you offering?"
#define INQUIRY_COURSE_CODE "Please enter the 7-digit course code for course %d: "
#define MAIN_LOOP_PROMPT "Please choose one of the following actions: "
#define ACTION_REGISTER "1. Register a student in a course"
#define ACTION_DROP "2. Drop a student's course"
#define ACTION_PRINT "3. Print registration table"
#define ACTION_QUIT "4. Quit"
#define ACTION_PROMPT "Please enter the number cooresponding to the desired action: "
#define INVALID_INPUT "Invalid input."
#define PROMPT_STUDENT "Please enter the student ID: "
#define PROMPT_COURSE "Please enter the course code: "
#define STUDENT_NOT_FOUND "Student with ID %d could not be found."
#define COURSE_NOT_FOUND "Course %s could not be found."
// Functions to gather user input
int getMaxStudents();
int * getNStudents();
int getMaxCourses();
char ** getNCourses();
int getAction();
int indexOfInt(int * array, int size, int value);
int indexOfString(char ** array, int size, char * value);
char * getCourseCode();
int getStudentID();
// Functions to output information to the user
void printInfo();
void printMainLoop();

// misc
void flush();
char* getVersion();