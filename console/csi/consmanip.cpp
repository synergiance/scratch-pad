/*
 * consmanip.cpp
 *
 * Sort of copy pasta cause I like how the source is laid out
 *
 * Created on October 13 2014
 *     By: Synergiance
 * Credit: Duoas http://www.cplusplus.com/forum/general/5304/#msg23940
 */

// Internal Includes
#include <cstdio>
#include <iostream>
#include <limits>
#include <string>

// Posix Includes
#include <unistd.h>
#include <termios.h>
#include <poll.h>

// Header
#include "consmanip.h"

/* termios.h usages:
 *
 * tcgetattr(<file descriptor>, &<termios>)
 * tcsetattr(<file descriptor>, TCSANOW, &<termios>)
 *
 * http://pubs.opengroup.org/onlinepubs/7908799/xsh/termios.h.html
 */

static bool initialized = false;
static struct termios settingsbak;

bool initialize() {
    if (!initialized) {
        initialized = (bool)isatty(0);
        if (initialized) initialized = (0 == tcgetattr(0, &settingsbak));
        if (initialized) std::cin.sync_with_stdio();
    }
    return initialized;
}

void finalize() {
    if (initialized) tcsetattr(0, TCSANOW, &settingsbak);
}

bool linebuffered(bool on = true) {
    struct termios settings;
    if (!initialized) return false;
    if (tcgetattr(0, &settings)) return false;

    if (on) settings.c_lflag |= ICANON;
    else    settings.c_lflag &= ~(ICANON);

    if (tcsetattr(0, TCSANOW, &settings)) return false;

    if (on) setlinebuf(stdin);
    else    setbuf(stdin, NULL);

    return true;
}

bool echo(bool on = true) {
   struct termios settings;
   if (!initialized) return false;
   if (tcgetattr(0, &settings)) return false;

   if (on) settings.c_lflag |= ECHO;
   else    settings.c_lflag &= ~(ECHO);

   return 0 = tcsetattr(0, TCSANOW, &settings);
}

// -1 for infinite waiting
bool iskeypressed(unsigned timeout_ms = 0) {
    if (!initialized) return false;
    struct pollfd pls[1];
    pls[0].fd = 0; // File descriptor 0 is stdin
    pls[0].events = POLLIN, POLLPRI;
    return poll(pls, 1, timeout_ms) > 0;
}
