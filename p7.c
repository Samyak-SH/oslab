/*inputs
5
4
100
500
200
300
600
212
417
112
462
*/

#include <stdio.h>
#define MAX 10

int main()
{
    int nb, nf;
    int blockFree[MAX], frag[MAX], block[MAX], fblockNo[MAX], file[MAX], fileAlloc[MAX];

    printf("Enter no of blocks : ");
    scanf("%d", &nb);
    printf("Enter no of files : ");
    scanf("%d", &nf);

    for(int i = 0; i < nb; i++){
        printf("Enter Block %d size : ", i + 1);
        scanf("%d", &block[i]);
        blockFree[i] = 1;   // block is free initially
    }
    for(int i = 0; i < nf; i++){
        printf("Enter File %d size : ", i + 1);
        scanf("%d", &file[i]);
        fileAlloc[i] = 0;   // file not allocated initially
        frag[i] = 0;        // fragmentation for each file
    }

    // First Fit allocation
    for(int i = 0; i < nf; i++){
        for(int j = 0; j < nb; j++){
            if(blockFree[j] && block[j] >= file[i]){
                fileAlloc[i] = 1;        // mark file allocated
                blockFree[j] = 0;        // mark block occupied
                fblockNo[i] = j;         // record block index (0-based)
                frag[i] = block[j] - file[i]; // fragmentation for file i
                break;                   // move to next file after allocation
            }
        }
    }

    printf("File No\tFile Size\tBlock no\tBlock Size\tFragment\n");
    for(int i = 0; i < nf; i++){
        if(fileAlloc[i]){
            printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, file[i], fblockNo[i] + 1, block[fblockNo[i]], frag[i]);
        }
        else{
            printf("%d\t%d\t\t%s\n", i + 1, file[i], "Not allocated---------------");
        }
    }

    return 0;
}
