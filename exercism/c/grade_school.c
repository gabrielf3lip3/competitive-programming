#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 20
#define MAX_STUDENTS 20

typedef struct {
   uint8_t grade;
   char name[MAX_NAME_LENGTH];
} student_t;

typedef struct {
   size_t count;
   student_t students[MAX_STUDENTS];
} roster_t;

void init_roster(roster_t *r) {
    r->count = 0;
}

bool existe(roster_t *r, student_t student) {
    for(size_t i = 0; i < r->count; i++) {
        if(strcmp(r->students[i].name, student.name) == 0) {
            return true;
        }
    }

    return false;
}

void sort_roster(roster_t* r) {
    for(size_t i = 0; i < r->count; i++) {
        for(size_t j = 0; j < r->count - 1; j++) {
            if(r->students[j].grade > r->students[j+1].grade) {
                student_t temp = r->students[j];
                r->students[j] = r->students[j+1];
                r->students[j+1] = temp;
            }
            else if(r->students[j].grade == r->students[j+1].grade) {
                if(strcmp(r->students[j].name, r->students[j+1].name) > 0) {
                    char aux[20];
                    strcpy(aux, r->students[j].name);
                    strcpy(r->students[j].name, r->students[j+1].name);
                    strcpy(r->students[j+1].name, aux);
                }
            }
        }
    }
}

bool add_student(roster_t *r, char* name, uint8_t grade) {
    student_t new;
    new.grade = grade;
    sprintf(new.name, name);

    if(existe(r, new)) return false;

    r->students[r->count] = new;
    r->count++;

    sort_roster(r);

    return true;
}

roster_t get_grade(roster_t *r, uint8_t grade) {
    roster_t retorno;
    init_roster(&retorno);

    for(size_t i = 0; i < r->count; i++) {
        if(r->students[i].grade == grade) {
            add_student(&retorno, r->students[i].name, grade);
        }
    }

    sort_roster(&retorno);
    return retorno;
}
