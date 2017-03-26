/*
 *   Filename: info.c
 *
 * Created on: 18 March 2016
 *     Author: Synergiance
 *
 * This tells me my screen info
 */

#include <linux/fb.h>
#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/ioctl.h>

inline uint32_t pixel_color(uint8_t r, uint8_t g, uint8_t b, struct fb_var_screeninfo *vinfo) {
    return (r<<vinfo->red.offset) | (g<<vinfo->green.offset) | (b<<vinfo->blue.offset);
}

int main() {
    struct fb_fix_screeninfo finfo;
    struct fb_var_screeninfo vinfo;

    int fb_fd = open("/dev/fb0",O_RDWR);

    // Get Variable Screen Information
    ioctl(fb_fd,FBIOGET_VSCREENINFO, &vinfo);
    vinfo.grayscale = 0;
    vinfo.bits_per_pixel = 32;
    ioctl(fb_fd,FBIOPUT_VSCREENINFO, &vinfo);
    ioctl(fb_fd,FBIOGET_VSCREENINFO, &vinfo);

    ioctl(fb_fd,FBIOGET_FSCREENINFO, &finfo);

    printf("Virtual size  (x,y): %ju,%ju\n", vinfo.xres_virtual, vinfo.yres_virtual);
    printf("Screen size   (x,y): %ju,%ju\n", vinfo.xres, vinfo.yres);
    printf("Screen offset (x,y): %ju,%ju\n", vinfo.xoffset, vinfo.yoffset);
    printf("Bits Per Pixel: %ju\n", vinfo.bits_per_pixel);
    printf("Bit lengths (r,g,b,a): %ju,%ju,%ju,%ju\n", vinfo.red.length, vinfo.green.length, vinfo.blue.length, vinfo.transp.length);
    printf("Bit offsets (r,g,b,a): %ju,%ju,%ju,%ju\n", vinfo.red.offset, vinfo.green.offset, vinfo.blue.offset, vinfo.transp.offset);
    printf("Color range (r,g,b,a): %ju,%ju,%ju,%ju\n", 1<<vinfo.red.length, 1<<vinfo.green.length, 1<<vinfo.blue.length, 1<<vinfo.transp.length);
    printf("Pixel format: %ju\n", vinfo.nonstd);

    return 0;
}
