#ifndef PPM_H
#define PPM_H

#include <stdint.h>
#include <stdbool.h>


typedef struct{
    uint16_t r, g, b;

} pixel; //class/struct type of pixel, unsigned int max value is 16-bits, a single pixel will have r,g,b

typedef struct{
    unsigned int rows;
    unsigned int cols;
    unsigned int maxval;

    pixel **pixels; //why? because pointers are arrays
} ppmimage;


ppmimage *ppm_readimage(const char *filename); //returns us a pointer
void ppm_destroy(ppmimage* image); //destroys the pointer
bool ppm_writeimage(const char *filename, ppmimage* image); //we will pass array filename and pointer to ppmimage type
#endif
