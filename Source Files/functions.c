#include "..\Headers\functions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

cstr_t *init_cstr() {
    cstr_t *newcstr = malloc(sizeof(cstr_t));
    if (newcstr == NULL) return NULL;
    newcstr->c = '\0';
    newcstr->n = NULL;
    return newcstr;
}

void free_cstr(cstr_t *cstr) {
    cstr_t *current = cstr;
    while (current != NULL) {
        cstr_t *temp = current;
        current = current->n;
        free(temp);
    }
}

unsigned int cstr_length(cstr_t *cstr) {
    unsigned int len = 0;
    cstr_t *current = cstr;
    while (current != NULL) {
        len += 1;
    }
    return len;
}

cstr_t *convert_cstr(char *str) {
    cstr_t *newcstr = init_cstr();
    cstr_t *current = newcstr;
    unsigned int i = 0;
    while (str[i] != '\0') {
        current->c = str[i];
        current->n = init_cstr();
        current = current->n;
    }
    current->n = NULL;
    return newcstr;
}

char *convert_nstr(cstr_t *cstr) {
    cstr_t *current = cstr;
    unsigned int length = cstr_length(cstr);
    char newstr[length+1];
    unsigned int i = 0;
    while (current != NULL) {
        newstr[i] = current->c;
        i++;
    }
    newstr[i] = '\0';
    return newstr;
}