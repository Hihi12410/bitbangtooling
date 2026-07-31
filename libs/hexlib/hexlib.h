/*
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

// I hate headers

// Freaky union
typedef union _hexstr
{
    struct
    {
        char t0;
        char t1;
        char x;
        char y;
        char nt;
    };
    char str_view[5];
    char str_view_nonullterm[4];
} hexstr;

#define NEWLINE_SPACING 5

hexstr char_to_hexstr(char x);
void template_hexstring(char in, int index, char*outvec);
