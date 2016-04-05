/*
 *   Filename: dpi.c
 *
 * Created on: 4 April 2016
 *     Author: Synergiance
 *
 * Calculates the dpi of a screen based on the size in inches and the
 * dimensions in pixels.
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void showhelp() {
    printf("Usage: [width] [height] [size]\n\n");
    printf("   Width: This is the width of the screen in pixels\n");
    printf("  Height: This is the height of the screen in pixels\n");
    printf("    Size: This is the diagonal size of the screen in inches\n\n");
}

int main (int argc, char* argv[]) {
    int width;
    int height;
    float size;
    int dpi;

    if (argc != 4) {
        showhelp();
        return 1;
    }

    if ((width = atoi(argv[1])) && (height = atoi(argv[2])) && (size = atof(argv[3]))) {
        dpi = (int) (((sqrt((width * width) + (height * height)) / size) + 0.5) / 1);
        printf("This screen is %d dpi.\n", dpi);
    } else {
        showhelp();
        return 1;
    }
}
