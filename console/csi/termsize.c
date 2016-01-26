// print width and height

#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>

int main( int argc, char **argv ){
    struct winsize size;
    ioctl( 0, TIOCGWINSZ, (char *) &size );
    printf( "Rows: %u\nCols: %u\n", size.ws_row, size.ws_col );
    return 0;
}
