// usage after compiling gcc ./p2ls.c -o p2ls
// ./p2ls <directory name (relative)>, eg : ./p2ls ../

#include "stdio.h"
#include "stdlib.h"
#include "dirent.h"

int main(int argc, char* argv[]){
    DIR* dp;
    struct dirent* link;
    if(argc<2){
        printf("incorrect usage\n");
        return 0;
    }
    dp = opendir(argv[1]);
    if(dp==NULL){
        printf("failed to open director\n");
        return 0;
    }

    printf("contents of the directory are: \n");
    while((link=readdir(dp))!=NULL){
        
        printf("%s\n", link->d_name);
    }

    closedir(dp);
    return 1;
}