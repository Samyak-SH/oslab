// usage after compiling gcc ./p2cp.c -o p2cp
// ./p2cp <soruce file> <destination file> eg ./p2cp source.txt destination.txt
// dont have to create destination file

#include "stdio.h"
#include "stdlib.h"

int main(int argc, char *argv[])
{
    FILE *srcfile, *destfile;
    char ch;
    if(argc != 3){
        printf("incorrect number of arguements\n");
        return 1;
    }

    srcfile = fopen(argv[1], "rb");
    if(srcfile == NULL){
        printf("Unable to open source file\n");
        fclose(srcfile);
        return 1;
    }

    destfile = fopen(argv[2], "wb");
    if(destfile == NULL){
        printf("Unable to open destination file\n");
        fclose(destfile);
        return 1;
    }

    while(ch!=EOF){
        ch=fgetc(srcfile);
        fputc(ch, destfile);
    }

    printf("Copy complete\n");
    fclose(srcfile);
    fclose(destfile);


}