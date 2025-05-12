#pragma once

// Defines the string type

typedef struct string {
    char c;
    struct string *n;
} ctr_t;

typedef struct cmgr {
    ctr_t *head;
    ctr_t *tail;
} ctrm_t;