/*
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

// View hex content of file.

#include "libs/filelib/filelib.h"
#include "libs/hexlib/hexlib.h"

char * usage_text = "HexView. View file contents in HEX format. Usage:\n hexview <file path>";

int main(int argc, char ** argv) 
{
    if (argc < 2) 
    {
        printf("%s\n", usage_text);
        return 0;
    }

    str fcont = r_file(argv[1]);
    if (CHECK_STR(fcont)) 
    {
        perror("An error occured while reading the designated file.\n");
        FREE_STR(fcont);
        return -1;
    }
    
    str tcont = charop(fcont, 5, template_hexstring);
    if (CHECK_STR(tcont)) 
    {
        perror("An error occured while processing the designated file.\n");
        FREE_STR(fcont);
        FREE_STR(tcont);
        return -1;
    }

    printf("%.*s\n",tcont.len, tcont.str);
    FREE_STR(fcont);
    FREE_STR(tcont);
    return 0;
}