#include "..\Headers\functions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Defines functions given by the header file functions.h


// Initializes a ctr_t
ctr_t *init_ctr() {
    ctr_t *newstr = malloc(sizeof(ctr_t));
    if (newstr == NULL) return NULL;
    newstr->c = '\0';
    newstr->n = NULL;
    return newstr;
}

// Initializes a ctrm_t
ctrm_t *init_ctrm(ctr_t *head, ctr_t *tail) {
    if (head == NULL) return NULL;
    ctrm_t *newm = malloc(sizeof(ctrm_t));
    if (newm == NULL) return NULL;
    newm->head = head;
    if (tail != NULL) {
        newm->tail = tail;
    } else {
        newm->tail = NULL;
    }
    return newm;
}

// Frees the given ctr_t and all the ctr_t after the given ctrm's head ctr_t
void free_ctr(ctrm_t *ctrm) {
    ctr_t *current = ctrm->head;
    while (current != NULL) {
        ctr_t *temp = current;
        current = current->n;
        free(temp);
    }
}

// Counts every ctr_t after the given ctrm's head ctr_t, and itself of course
unsigned int length_ctr(ctrm_t *ctrm) {
    unsigned int len = 0;
    ctr_t *current = ctrm->head;
    while (current != NULL) {
        len++;
        current = current->n;
    }
    return len;
}

// Converts a normal string to a ctr_t type string
ctr_t *to_ctr(char *str, ctrm_t *ctrm) {
    ctr_t *newstr = init_ctr();
    ctr_t *current = newstr;
    ctrm_t *unmd1 = init_ctrm(current, NULL);
    unsigned int i = 0;
    while (str[i] != '\0') {
        current->c = str[i];
        if (str[i + 1] != '\0') {
            current->n = init_ctr();
            current = current->n;
        } else {
            current->n = NULL;
            unmd1->tail = current;
        }
        i++;
    }
    return newstr;
}

// Converts a ctr_t type string to a normal string
char *ctr_to_string(ctr_t *ctr) {
    ctr_t *current = ctr;
    unsigned int length = length_ctr(ctr);
    char *newstr = malloc(length+1);
    unsigned int i = 0;
    while (current != NULL) {
        newstr[i] = current->c;
        current = current->n;
        i++;
    }
    newstr[i] = '\0';
    return newstr;
}

// Counts up to a specific ctr_t by the given index and returns it
ctr_t *get_ctr_byindex(ctrm_t *ctrm, unsigned int index) {
    ctr_t *current = ctrm->head;
    if (index > length_ctr(current)) return NULL;
    unsigned int i;
    for (i = 0; i < index; i++) {
        current = current->n;
    }
    return current;
}

// Adds a ctr_t after the given ctrm's tail ctr_t
ctr_t *add_ctr_e(ctrm_t *ctrm, char c) {
    if (ctrm->tail == NULL) return NULL;
    ctr_t *newctr = init_ctr();
    if (newctr == NULL) return NULL;
    newctr->c = c;
    newctr->n = NULL;
    ctrm->tail->n = newctr;
    ctrm->tail = newctr;
    return newctr;
}

// Adds a ctr_t after the given ctr_t and returns it
ctr_t *add_ctr_a(ctr_t *ctr, char c, ctrm_t *ctrm) {
    if (ctr == NULL) return NULL;
    ctr_t *newctr = init_ctr();
    if (newctr == NULL) return NULL;
    if (ctr->n == NULL) {
        newctr->n = NULL;
        ctr->n = newctr;
        if (ctrm != NULL) {
            ctrm->tail = newctr;
        }
    } else {
        newctr->n = ctr->n;
        ctr->n = newctr;
    }
    newctr->c = c;
    return newctr;
}

// Removes the last ctr_t and returns it
ctr_t *pop_ctr_e(ctrm_t *ctrm) {
    ctr_t *temp = ctrm->tail;
    free(ctrm->tail);
    ctrm->tail = NULL;
    return temp;
}

// Removes the ctr_t after the given ctr_t
ctr_t *pop_ctr_a(ctr_t *ctr) {
    ctr_t *temp = ctr->n;
    free(ctr->n);
    ctr->n = ctr->n->n;
    return temp;
}