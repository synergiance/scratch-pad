/*
 *   Filename: posixregex.cpp
 *
 * Created on: 8 January 2016
 *     Author: Synergiance
 *
 * Many systems in 2016 still don't have GCC 4.9 and support for the <regex>
 * library fully implemented.  This is a test of the old regex implementation
 * from c, which is <regex.h>.  This file is a test probably buggy
 * implementation which is for learning purposes only!
 */

#include <stdio.h>  // Input output library (printf)
#include <regex.h>  // POSIX compliant regex
#include <string.h> // Character strings

int main() {
    char source[] = "___ abc123def ___ ghi456 ___"; // Random pretty much
    char rgxStr[] = "[a-z]*([0-9]+)([a-z]*)";       // Match sequence
    
    char * cursor;      // With this we will "walk" up the source string
    char * matchCursor; // This is our copy string

    regex_t      rgxCmp; // This is our compiled regex
    regmatch_t * rgxGrp; // This will contain our match with groups

    size_t maxGrp; // This is a dynamically increasing max size
    size_t numGrp; // This is the number of groups

    char cBak; // This will store a displaced character

    size_t c;

  /*
   * regcomp returns 0 if successful, and takes a number of flags:
   *   REG_EXTENDED - Use extended regular expressions
   *      REG_ICASE - Ignore case in regular expression
   *      REG_NOSUB - Only report success or fail in regexec
   *    REG_NEWLINE - Change the handling of newline characters
   *
   * If REG_NOSUB is not set, re_nsub will be set to the number of groups
   * that have been found in the match
   */
    if (regcomp(&rgxCmp, rgxStr, REG_EXTENDED)) {
        printf("Could not compile regular expression\n");
        return 1;
    }// regcomp returns 0 if successful

    cursor = source; // Set the pointer of cursor to the beginning of source

    maxGrp = 32;                     // Set initial array size
    rgxGrp = new regmatch_t[maxGrp]; // Initialize our group array

    for (;;) {
        // Use regex on the string at cursor position
        if (regexec(&rgxCmp, cursor, maxGrp, rgxGrp, 0))
            break; // No more matches

        numGrp = rgxCmp.re_nsub; // Get number of groups

        // Uh oh, we have more groups than we have memory, allocate more
        if (numGrp > maxGrp) {
            maxGrp = numGrp;                             // Set new max
            delete rgxGrp;                               // Clean memory
            rgxGrp = new regmatch_t[maxGrp];             // Allocate new memory
            regexec(&rgxCmp, cursor, maxGrp, rgxGrp, 0); // Redo regex proper
        }

        for (c = 0; c < numGrp; c++) {
            if (rgxGrp[c].rm_so == (size_t)-1)
                break; // No more groups

            matchCursor = cursor + rgxGrp[c].rm_so; // Beginning of group
            cBak = cursor[rgxGrp[c].rm_eo];         // Backup char
            cursor[rgxGrp[c].rm_eo - 1] = 0;        // Set to string terminate
            printf("%s ", matchCursor);             // Print substring
            cursor[rgxGrp[c].rm_eo] = cBak;         // Restore char
        }
        printf("\n"); // Newline! \o/
        cursor += rgxGrp[0].rm_eo; // The character after the end of the match
    }

    regfree(&rgxCmp); // Free regex
    delete rgxGrp;    // Free memory

    return 0; // complete successfully
}
