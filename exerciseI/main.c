#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    char address[100];
    int registration;
} student;

void student_write(student *s) {
    printf("Enter student name: ");
    fgets(s->name, sizeof(s->name), stdin);

    printf("Enter student address: ");
    fgets(s->address, sizeof(s->address), stdin);

    printf("Enter student registration: ");
    scanf("%d", &s->registration);
    getchar();
}

void student_print(student *s) {
    printf("Name: %s\n", s->name);
    printf("Address: %s\n", s->address);
    printf("Registration: %d\n", s->registration);
}

int main() {
    int number_students;
    student *students;

    printf("Enter number of students: ");
    scanf("%d", &number_students);
    getchar();

    students = (student *) malloc(number_students * sizeof(student));

    if (students == NULL) {
        printf("Memory allocation error\n");
        return 1;
    }

    for (int i = 0; i < number_students; i++) {
        student_write(&students[i]);
    }

    printf("\nStudent Information:\n");
    printf("=======================\n");
    for (int i = 0; i < number_students; i++) {
        student_print(&students[i]);
        printf("=======================\n");
    }

    free(students);
    return 0;
}
