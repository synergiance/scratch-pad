/*
 *       Name: colors.cpp
 * Created on: 3 January 2016
 *     Author: Synergiance
 *
 * This is a demonstration app that shows how to work with the ANSI color
 * escape codes for the terminal.  It will show all foregrounds on all
 * backgrounds.
 */

#include <unistd.h> // Contains the write() method we'll be using

// Misc arrays
char attr[]   = {'0','1','4','5','7'};             // Text attributes
char colors[] = {'0','1','2','3','4','5','6','7'}; // Second character colors

// Misc characters
char esc  = '\x1b'; // This is the ESC character.  1B in hex, 033 in octal.
char esc2 = '[';    // This tells the console it's an esc code.
char sep  = ';';    // This is the separator value, which is a semicolon.
char fore = '3';    // This is the first character in the foreground values.
char back = '4';    // This is the first character in the background values.
char done = 'm';    // The done character.

int main()
{// The main method, what else can be said here? This is the beginning?
    unsigned char x, y, z; // Coordinates? nah, just our counters
             char buf[20]; // Text buffer

    buf[0]  = esc;  // Set esc
    buf[1]  = esc2;
    buf[9]  = done;
    buf[3]  = sep;  // Set separators
    buf[6]  = sep;
    buf[4]  = fore; // Foreground prefix
    buf[7]  = back; // Background prefix
    buf[10] = ' ';  // Good old spacing
    buf[18] = ' ';
    buf[12] = sep;
    buf[15] = sep;
    buf[13] = fore;
    buf[16] = back;
    buf[19] = '\0'; // C string support because why not

    write(STDOUT_FILENO, "ESC[Attr;Fg;Bgm\n", 16);
    for (x = 0; x < sizeof(attr); x++) {
        write(STDOUT_FILENO, "----------------------------------------\n", 41);
        buf[2]  = attr[x];
        buf[11] = attr[x];
        for (y = 0; y < sizeof(colors); y++) {
            buf[5]  = colors[y];
            buf[14] = colors[y];
            for (z = 0; z < sizeof(colors); z++) {
                buf[8]  = colors[z];
                buf[17] = colors[z];
                write(STDOUT_FILENO, buf, 18);
            }
            write(STDOUT_FILENO, "\x1b[0m\n", 5); // Reset colors and newline
        }
        write(STDOUT_FILENO, "\n", 1); // Plain newline
    }
    write(STDOUT_FILENO, "0m\n", 3); // Reset code onscreen
    return 0; // Always return 0 to finish normally
}
