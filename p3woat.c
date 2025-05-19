#include "stdio.h"

int main(){
    int bt[20], wt[20], tat[20], ct[20];
    int n, time=0;
    float wtavg=0;
    float tatavg=0;
    printf("Enter number of processes : ");
    scanf("%d", &n);

    printf("Enter burt time of\n");
    for(int i=0;i<n;i++){
        printf("P%d : ", i);
        scanf("%d", &bt[i]);
    }
    for(int i=0;i<n;i++){
        time += bt[i];
        ct[i] = time;
        tat[i] = ct[i];
        wt[i] = tat[i]-bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }
    wtavg/=n;
    tatavg/=n;
    printf("PROCESS\tBURST TIME\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++){
        printf("P%d\t%d\t\t%d\t%d\t%d\n",i, bt[i], ct[i], tat[i], wt[i]);
    }
    printf("average WT : %f\n", wtavg);
    printf("average TAT : %f", tatavg);


}