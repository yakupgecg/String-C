#include "..\Headers\functions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

ctr_t *init_ctr() {
    ctr_t *newstr = malloc(sizeof(ctr_t));
    if (newstr == NULL) return NULL;
    newstr->c = '\0';
    newstr->n = NULL;
    return newstr;
}

void free_ctr(ctr_t *ctr) {
    ctr_t *current = ctr;
    while (current != NULL) {
        ctr_t *temp = current;
        current = current->n;
        free(temp);
    }
}

unsigned int length_ctr(ctr_t *ctr) {
    unsigned int len = 0;
    ctr_t *current = ctr;
    while (current != NULL) {
        len++;
        current = current->n;
    }
    return len;
}

ctr_t *to_ctr(char *str) {
    ctr_t *newstr = init_ctr();
    ctr_t *current = newstr;
    unsigned int i = 0;
    while (str[i] != '\0') {
        current->c = str[i];
        current->n = init_ctr();
        current = current->n;
    }
    current->n = NULL;
    return newstr;
}

char *ctr_to_string(ctr_t *ctr) {
    ctr_t *current = ctr;
    unsigned int length = ctr_length(ctr);
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