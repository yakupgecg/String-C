#pragma once

// Defines the string type

typedef struct string {
    char c;
    struct string *n;
} cstr_t;