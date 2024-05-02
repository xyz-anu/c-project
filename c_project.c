#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_FACULTY 50
#define MAX_COURSES 20

// Structure definitions
typedef struct {
    int id;
    char name[50];
    char department[50];
} Student;

typedef struct {
    int id;
    char name[50];
    char designation[50];
} Faculty;

typedef struct {
    int id;
    char name[50];
    char time[50];
    Student *students;
    int num_students;
    Faculty *faculty;
} Course;

// Function prototypes
void addStudent(Student *students, int *num_students);
void addFaculty(Faculty *faculty, int *num_faculty);
void addCourse(Course *courses, int *num_courses);
void printStudents(Student *students, int num_students);
void printFaculty(Faculty *faculty, int num_faculty);
void printCourses(Course *courses, int num_courses);

int main() {
    // Initialize arrays of students, faculty, and courses
    Student students[MAX_STUDENTS];
    Faculty faculty[MAX_FACULTY];
    Course courses[MAX_COURSES];
    int num_students = 0;
    int num_faculty = 0;
    int num_courses = 0;

    // Main menu loop
    int choice;
    while (1) {
        printf("\nSchool Management System\n");
        printf("========================\n");
        printf("1. Add Student\n");
        printf("2. Add Faculty\n");
        printf("3. Add Course\n");
        printf("4. Print Students\n");
        printf("5. Print Faculty\n");
        printf("6. Print Courses\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &num_students);
                break;
            case 2:
                addFaculty(faculty, &num_faculty);
                break;
            case 3:
                addCourse(courses, &num_courses);
                break;
            case 4:
                printStudents(students, num_students);
                break;
            case 5:
                printFaculty(faculty, num_faculty);
                break;
            case 6:
                printCourses(courses, num_courses);
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addStudent(Student *students, int *num_students) {
    Student new_student;
    printf("Enter student ID: ");
    scanf("%d", &new_student.id);
    printf("Enter student name: ");
    scanf("%s", new_student.name);
    printf("Enter student department: ");
    scanf("%s", new_student.department);
    students[*num_students] = new_student;
    (*num_students)++;
}

void addFaculty(Faculty *faculty, int *num_faculty) {
    Faculty new_faculty;
    printf("Enter faculty ID: ");
    scanf("%d", &new_faculty.id);
    printf("Enter faculty name: ");
    scanf("%s", new_faculty.name);
    printf("Enter faculty designation: ");
    scanf("%s", new_faculty.designation);
    faculty[*num_faculty] = new_faculty;
    (*num_faculty)++;
}

void addCourse(Course *courses, int *num_courses) {
    Course new_course;
    printf("Enter course ID: ");
    scanf("%d", &new_course.id);
    printf("Enter course name: ");
    scanf("%s", new_course.name);
    printf("Enter course time: ");
    scanf("%s", new_course.time);
    printf("Enter number of students for this course: ");
    scanf("%d", &new_course.num_students);
    new_course.students = (Student *)malloc(new_course.num_students * sizeof(Student));
    for (int i = 0; i < new_course.num_students; i++) {
        printf("Enter student ID for student %d: ", i + 1);
        scanf("%d", &new_course.students[i].id);
        printf("Enter student name for student %d: ", i + 1);
        scanf("%s", new_course.students[i].name);
        printf("Enter student department for student %d: ", i + 1);
        scanf("%s", new_course.students[i].department);
    }
    printf("Enter number of faculty for this course: ");
    scanf("%d", &new_course.faculty->num_faculty);
    new_course.faculty = (Faculty *)malloc(new_course.faculty->num_faculty * sizeof(Faculty));
    for (int i = 0; i < new_course.faculty->num_faculty; i++) {
        printf("Enter faculty ID for faculty %d: ", i + 1);
        scanf("%d", &new_course.faculty[i].id);
        printf("Enter faculty name for faculty %d: ", i + 1);
        scanf("%s", new_course.faculty[i].name);
printf("Enter faculty designation for faculty %d: ", i + 1);
        scanf("%s", new_course.faculty[i].designation);
    }
    courses[*num_courses] = new_course;
    (*num_courses)++;
}

void printStudents(Student *students, int num_students) {
    printf("\nList of Students:\n");
    printf("=================\n");
    printf("%-5s %-20s %-20s\n", "ID", "Name", "Department");
    for (int i = 0; i < num_students; i++) {
        printf("%-5d %-20s %-20s\n", students[i].id, students[i].name, students[i].department);
    }
}

void printFaculty(Faculty *faculty, int num_faculty) {
    printf("\nList of Faculty:\n");
    printf("=================\n");
    printf("%-5s %-20s %-20s\n", "ID", "Name", "Designation");
    for (int i = 0; i < num_faculty; i++) {
        printf("%-5d %-20s %-20s\n", faculty[i].id, faculty[i].name, faculty[i].designation);
    }
}

void printCourses(Course *courses, int num_courses) {
    printf("\nList of Courses:\n");
    printf("=================\n");
    printf("%-5s %-20s %-20s %-5s %-5s\n", "ID", "Name", "Time", "Students", "Faculty");
    for (int i = 0; i < num_courses; i++) {
        printf("%-5d %-20s %-20s %-5d %-5d\n", courses[i].id, courses[i].name, courses[i].time,
               courses[i].num_students, courses[i].faculty->num_faculty);
    }
}
