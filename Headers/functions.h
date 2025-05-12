#pragma once

#include "structure.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Declares functions for handling ctr_t

ctr_t *init_ctr();
ctrm_t *init_ctrm(ctr_t *, ctr_t *);
void free_ctr(ctr_t *);
unsigned int length_ctr(ctr_t *);
ctr_t *convert_to_ctr(char *);
char *convert_to_string(ctr_t *);
ctr_t *get_ctr_byindex(ctrm_t *, unsigned int);