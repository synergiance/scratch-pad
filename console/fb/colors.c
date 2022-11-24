/*
 *   Filename: colors.c
 *
 * Created on: 18 March 2016
 *     Author: Synergiance
 *
 * This is a test project using code from a website that will draw directly to
 * the framebuffer.  It will be entertaining, and much enjoyment will be had.
 */

#include <linux/fb.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/ioctl.h>

uint32_t pixel_color(uint8_t r, uint8_t g, uint8_t b, struct fb_var_screeninfo *vinfo) {
    return (r<<vinfo->red.offset) | (g<<vinfo->green.offset) | (b<<vinfo->blue.offset);
}

int main() {
    struct fb_fix_screeninfo finfo;
    struct fb_var_screeninfo vinfo;

    char hidecursor[7] = {0x1b, '[', '?', '1', '6', 'c', 0};
    char restorecursor[6] = {0x1b, '[', '?', '0', 'c', 0};

    write((int)stdout, hidecursor, 6);

    int fb_fd = open("/dev/fb0",O_RDWR);

    // Get Variable Screen Information
    ioctl(fb_fd,FBIOGET_VSCREENINFO, &vinfo);
    vinfo.grayscale = 0;
    vinfo.bits_per_pixel = 32;
    ioctl(fb_fd,FBIOPUT_VSCREENINFO, &vinfo);
    ioctl(fb_fd,FBIOGET_VSCREENINFO, &vinfo);

    ioctl(fb_fd,FBIOGET_FSCREENINFO, &finfo);

    long screensize = vinfo.yres_virtual * finfo.line_length;

    uint8_t *fbp = mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fb_fd, (off_t)0);

    int x,y;

    for (x = 0; x < vinfo.xres; x++) {
        for (y = 0; y < vinfo.yres; y++) {
            long location = (x + vinfo.xoffset) * (vinfo.bits_per_pixel / 8) + (y + vinfo.yoffset) * finfo.line_length;
            *((uint32_t*)(fbp + location)) = pixel_color(x * (1<<vinfo.red.length) / vinfo.xres, 0x00, y * (1<<vinfo.blue.length) / vinfo.yres, &vinfo);
        }
    }

    sleep(1);

    write((int)stdout, restorecursor, 5);

    return 0;
}
