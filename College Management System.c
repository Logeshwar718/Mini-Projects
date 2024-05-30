#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    int rollNo;
    char name[50];
    int age;
    char course[50];
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Cannot add more students. Limit reached.\n");
        return;
    }
    
    Student s;
    printf("Enter roll number: ");
    scanf("%d", &s.rollNo);
    printf("Enter name: ");
    scanf(" %[^\n]%*c", s.name);
    printf("Enter age: ");
    scanf("%d", &s.age);
    printf("Enter course: ");
    scanf(" %[^\n]%*c", s.course);
    
    students[studentCount++] = s;
    printf("Student added successfully!\n");
}

void listStudents() {
    if (studentCount == 0) {
        printf("No students to display.\n");
        return;
    }
    
    for (int i = 0; i < studentCount; i++) {
        printf("Roll Number: %d\n", students[i].rollNo);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Course: %s\n", students[i].course);
        printf("------------------------\n");
    }
}

void searchStudent() {
    int rollNo;
    printf("Enter roll number to search: ");
    scanf("%d", &rollNo);
    
    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNo == rollNo) {
            printf("Roll Number: %d\n", students[i].rollNo);
            printf("Name: %s\n", students[i].name);
            printf("Age: %d\n", students[i].age);
            printf("Course: %s\n", students[i].course);
            return;
        }
    }
    printf("Student with roll number %d not found.\n", rollNo);
}

void deleteStudent() {
    int rollNo;
    printf("Enter roll number to delete: ");
    scanf("%d", &rollNo);
    
    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNo == rollNo) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("Student with roll number %d deleted.\n", rollNo);
            return;
        }
    }
    printf("Student with roll number %d not found.\n", rollNo);
}

int main() {
    int choice;
    
    while (1) {
        printf("1. Add Student\n");
        printf("2. List Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                listStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
