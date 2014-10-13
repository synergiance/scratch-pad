/*
 * consmanip.h
 *
 * Console Manip is a simple header that will allow you greater control over your
 * console if you know what you're doing.  This paired with CSI will be all you need
 * in order to create a fully immersive console application.
 *
 * Created on October 13, 2014
 *     By: Synergiance
 * Credit: Dioas http://pubs.opengroup.org/onlinepubs/7908799/xsh/termios.h.html
 *
 * How to use:
 * Always initialize before using, and finalize afterwatds
 */

#define INFINITE (-1)

bool initialize();
void finalize();

bool linebuffered(bool on = true);
bool echo(bool on = true);
bool iskeypressed(unsigned timeout_ms = 0);
