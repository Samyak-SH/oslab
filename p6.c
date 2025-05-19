#include "stdio.h"

int main()
{
    int n = 5; // Number of processes  
    int m = 3; // Number of resources
    int f[5] = {0,0,0,0,0};
    int ans[5];
    int index=0;
    int avail[3] = {3, 3, 2}; 
    int need[5][3];
    int alloc[5][3] = { 
        {0, 1, 0},  // P0
        {2, 0, 0},  // P1
        {3, 0, 2},  // P2
        {2, 1, 1},  // P3
        {0, 0, 2}   // P4
    };

    int max[5][3] = { 
        {7, 5, 3},  // P0
        {3, 2, 2},  // P1
        {9, 0, 2},  // P2
        {2, 2, 2},  // P3
        {4, 3, 3}   // P4
    };
    for(int i=0;i<n; i++){
        for(int j=0;j<m;j++){
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    //try every possible combination (give every process a chance)
    for(int k = 0;k<n;k++){

        //for every process
        for(int i=0;i<n; i++){  
            if(f[i]==0){
                int canExec = 1;

                //check if there is enough resources
                for(int j=0;j<m;j++){
                    if(need[i][j]>avail[j]){
                        canExec = 0;
                        break;
                    }
                }
                
                //execute and free resources
                if(canExec){
                    ans[index++] = i;
                    for(int j=0;j<m;j++){
                        avail[j] += alloc[i][j];
                    }
                    f[i]=1;
                }
            }
        }
    }

    int isSafe = 1;
    for(int i=0;i<n; i++){
        if(f[i]!=1){
            isSafe = 0;
            break;
        }
    }
    if(isSafe){
        printf("safe sequence is :\n");
        for(int i=0;i<n-1;i++){
            printf("P%d->", ans[i]);
        }
        printf("P%d\n", ans[n-1]);
        return 0;
    }
    printf("System not safe\n");

}