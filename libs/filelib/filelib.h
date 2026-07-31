// Some file bs.

#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int len;
    char * str;
} str;

#define ERROR_STRING (str){-1, NULL}
#define CHECK_STR(x) ((x.len == -1) || (!x.str))
#define FREE_STR(x) TRY_FREE(x.str)
#define TRY_FREE(x) if (x) free(x)

str r_file(char * fpath);
str charop(str s, int sz, void (*t_f)(char, int, char*));