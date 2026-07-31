#include "hexlib.h"

// Shit out hex values.

// Jarvis disable freaky mode (msvc)
#pragma optimize("", off)

/*Turns the 8 bit value x into a a valid fix-size hex string ([0x]FF). Supply a 2 character vector for storage.*/
/* DATA IS RAW, NO NULLTERM!!!! DO NOT RAWDOG IT!!! assume 2byte len. */
hexstr char_to_hexstr(char x)
{
    hexstr r;
    unsigned char _2n8bv[2] = {0};

    for (int i = 0; i < 2; ++i) 
    {
        // Digest bits at index.
        unsigned char y = (x >> (i * 4)) & 0xF;

        // Select character bank.
        // Number range. (0-9)
        if (y < 10)  
            // Start of range : 0x30 -> 0
            y = y + 0x30;

        // Else it should be a letter. Start of range: 0x41 -> A 
        else y = (y-9) + 0x40;
        
        // yay
        _2n8bv[i] = y;
    }
    // pack it up.
    r.t0 = '0';
    r.t1 = 'x';
    r.x = _2n8bv[1];
    r.y = _2n8bv[0];
    r.nt = 0x0;
    return r;
}


// Diddy mode on (msvc)
#pragma optimize("", on)

// yay
void template_hexstring(char in, int index, char*outvec) 
{
    hexstr x = char_to_hexstr(in);
    outvec[0] = x.t0;
    outvec[1] = x.t1;
    outvec[2] = x.x;
    outvec[3] = x.y;
    if (index % NEWLINE_SPACING == NEWLINE_SPACING-1)
        outvec[4] = '\n';
    else 
        outvec[4] = ' ';
    return;
}
