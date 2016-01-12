/*
 * rawreadwrite.cpp
 *
 *  Created on: 2 January 2016
 *      Author: Synergiance
 *
 * This is a test method that uses read() and write() functions entirely
 * in order to interact with the console.  This may act like we expect or
 * some way completely unexpected, but hey, we won't know until we try.
 *
 */

#include <unistd.h>     // Contains read() and write()
#include <sys/types.h>  // Some unix size measurements
#include <termios.h>    // Terminal tricks
#include <signal.h>     // Signal handler
#include <string.h>     // C strings, only used for strncmp
#include <sys/select.h> // Listen to many file descriptors
#include <stdbool.h>    // C boolean library

#define BUFSIZE 32

volatile bool stopping = false; // This only tells the main loop when to stop

int spfd[2];

void sigHandler(int signum)
{// Simple signal handler for interrupts
    switch (signum)
    {
        case 2:
            stopping = true;
            write(spfd[1], "\4", 1);
    }
}

int main(int argc, char* argv[])
{// Our main method, we'll do our work in here.
    unsigned    char buf[BUFSIZE];     // Our buffer
             ssize_t bytes_read;       // How many bytes have been read
                 int fd;               // File descripter
              fd_set mfd;              // File descripter set

    struct   termios initial_settings; // This will backup the terminal settings
    struct   termios settings;         // This will be our terminal settings

                bool bHex = false;     // Tells us whether we're using hex mode
    unsigned    char hex[BUFSIZE * 2]; // Double the buffer size for hex mode
              size_t pos;              // This is our position variable
    unsigned    char cTmp[2];          // Temporary storage

    // Check to see if there's a "-h" after our program for hex mode
    if ((argc > 1) && (strncmp(argv[1], "-h", 2) == 0)) bHex = true;

    pipe(spfd);                 // Signal pipe
    signal(SIGINT, sigHandler); // Install a signal handler

    tcgetattr(STDIN_FILENO, &initial_settings); // Get current term settings
    settings = initial_settings;                // Copy them for our reference

    // Set the console mode to no-echo, raw input.
    settings.c_cc[VTIME] = 1;                // Timeout is 100ms * VTIME
    settings.c_cc[VMIN]  = 1;                // Minimum characters to return
    settings.c_iflag    &= ~(IXOFF);         // No software flow control
    settings.c_lflag    &= ~(ECHO | ICANON); // No echo, single char mode

    // Write settings to console
    tcsetattr(STDIN_FILENO, TCSANOW, &settings);

    // Set up select listener
    FD_ZERO(&mfd);              // Zero out our file descriptor set
    FD_SET(STDIN_FILENO, &mfd); // Set stdin to our set
    FD_SET(spfd[0],      &mfd); // Set the read side of our pipe

  /* On posix compliant systems these will be as follows:
   * STDIN_FILENO  = 0
   * STDOUT_FILENO = 1
   * STDERR_FILENO = 2
   */
    while (!stopping) {
        if (select(spfd[0] + 1, &mfd, NULL, NULL, NULL) == -1) stopping = true;
        if (FD_ISSET(spfd[0], &mfd)) stopping = true;
        if (!stopping && FD_ISSET(STDIN_FILENO, &mfd))
            bytes_read = read(STDIN_FILENO, buf, BUFSIZE);
        if (bytes_read < 0) stopping = true;
        if (bHex) { // Hex mode
            for (pos = 0; pos < bytes_read; pos++) {
                cTmp[0] = buf[pos] / 16;
                cTmp[1] = buf[pos] % 16;
                for (char c = 0; c <= 1; c++) {
                    if (cTmp[c] > 9) cTmp[c] += 7;
                    cTmp[c] += 48;
                    hex[pos * 2 + c] = cTmp[c];
                }
            }
            if (!stopping) write(STDOUT_FILENO, hex, bytes_read * 2);
        } else { // Not hex mode
            if (!stopping) write(STDOUT_FILENO, buf, bytes_read);
        }
    }

    // Write initial settings to console
    tcsetattr(STDIN_FILENO, TCSANOW, &initial_settings);

    // Close pipe
    close(spfd[0]);
    close(spfd[1]);

    // End all programs with a newline
    write(STDOUT_FILENO, "\n", 1);
    return 0;
}
