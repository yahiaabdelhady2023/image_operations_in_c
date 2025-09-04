#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>

int main(){
    FILE *file_pointer = fopen("text_file.txt","rb"); 
    long file_size_1 = ftell(file_pointer);
    printf("File size 1 : %d \n",file_size_1);
    fseek(file_pointer,5,SEEK_END);
    long file_size_2 = ftell(file_pointer);
    printf("File size 2 : %d",file_size_2);
    
    return 0;
}