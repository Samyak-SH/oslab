#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define MAX 1024

int main(int argc, char* argv[]){
    FILE* fp;
    char fline[MAX];
    char* newline;

    int count=0;//line count
    int occur = 0;
    if(argc!=3){
        printf("incorrect usage\n");
        return 1;
    }

    fp = fopen(argv[1], "r");
    if(fp==NULL){
        printf("failed to open file\n");
        return 1;
    }

    while(fgets(fline, MAX, fp)!=NULL){
        count++;

        if((newline=strchr(fline, '\n'))!=NULL){
            *newline = '\0';//if new line character exists set it to endline for neat output formatting
        }
        if(strstr(fline, argv[2])!=NULL){
            printf("%d %s\n", count, fline);
            occur++;
        }
    }
    if(occur==0){
        printf("no occurences found\n");
    }
    fclose(fp);
    return 0;
}