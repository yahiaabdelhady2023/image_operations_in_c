#include "ppm.h"
#include <stdlib.h> //general purpose standard library for free(),malloc(),exit()
#include <fcntl.h> // "File Control" file control and manipulation, unlike stdio it allows low level file operations, while stdio allows high level file operations
#include <stdio.h> //standard input output header  standard streams stdin,stdout,stderr
#include <stdbool.h>
#include <string.h>
#include <windows.h>


ppmimage *ppm_readimage(const char *filename){
    FILE *file=fopen(filename, "rb"); //file pointer of type FILE, pointer name is file
    //file pointer points to File structure/data type rather than data itself or file content
    if(file==NULL){
        perror("Error: Could not open the file");
        return NULL;
    }


    fseek(file,0,SEEK_END); //get file size
    long file_size = ftell(file);
    printf(" file_size %d",file_size);

    int file_desc   = fileno(file); //returns file descp

    rewind(file); //go back to the beginning of the file

    ppmimage *result = malloc(sizeof *result);


    char type[3]={0};
    fscanf(file, "%2s",type);

    if(strcmp(type,"P6")!=0){
        //that means it is not P6
        perror("This is not a P6 PPM file");
        fclose(file);
        return NULL;
    }

    fscanf(file,"%u %u",&(result->cols),&(result->rows));
    fscanf(file,"%u",&(result->maxval));

    off_t offset=ftell(file);
    uint8_t *rawdata =mmap(NULL, file_size, PRO_READ)
}; //returns us a pointer



// void ppm_destroy(ppmimage* image); //destroys the pointer
// bool ppm_writeimage(const char *filename, ppmimage* image){

// };