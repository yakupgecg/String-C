#pragma once

#include "structure.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Declares functions for handling cstr_t

cstr_t *init_cstr();
unsigned int cstr_length(cstr_t *);
cstr_t *convert_cstr(char *);
char *convert_nstr(cstr_t *);