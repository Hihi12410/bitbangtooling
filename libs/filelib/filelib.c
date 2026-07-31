/*
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/


// Some file bs.

#include "filelib.h"

// Read file contents. also malloc mem. (yay)
// DO NOT PRINT!!! NOT PRINT SAFE!!!
// Caller must call free.
str r_file(char * fpath) 
{
    // Open file for reading.
    FILE * file = fopen(fpath, "rb");
    if (!file) 
    {
        perror("File could not be opened.");
        return ERROR_STRING;
    }

    // Get file len.
    fseek(file, 0, SEEK_END);
    int sz = ftell(file);
    rewind(file);

    // Malloc container.
    char * cont = malloc(sz * sizeof(char));
    if (!cont) 
    {
        perror("Malloc failed.");
        fclose(file);
        return ERROR_STRING;
    }

    // Copy contents.
    fread(cont, sizeof(char), sz, file);
    fclose(file);
    return (str){sz, cont};
}


// define transform for chars in string.
str charop(str s, int sz, void (*t_f)(char, int, char*)) 
{
    // Make a cache container.
    int len = s.len * sz;
    char* cont = malloc(sz * sizeof(char));
    char* ret = malloc(len * sizeof(char));
    if (!cont || !ret) 
    {
        perror("Error while allocating memory.");
        TRY_FREE(ret);
        TRY_FREE(cont);
    }
    
    // fuck me
    for (int i = 0; i < s.len; ++i) 
    {
        t_f(s.str[i], i, cont);
        for (int j = 0; j < sz; ++j) 
        {
            ret[(i*sz)+j] = cont[j];
        }
    }

    TRY_FREE(cont);
    return (str){len, ret};
}