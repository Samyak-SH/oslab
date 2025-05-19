#include <stdio.h>

int main() {
    int bt[20], wt[20], tat[20], ct[20], cpbt[20];
    int n, slice, cp = 0, count = 0, time = 0;
    float wtavg = 0, tatavg = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time of\n");
    for (int i = 0; i < n; i++) {
        printf("P%d : ", i);
        scanf("%d", &bt[i]);
        cpbt[i] = bt[i];
        ct[i] = 0;
    }

    printf("Enter time slice: ");
    scanf("%d", &slice);

    while (count < n) {
        if (bt[cp] > 0) {
            if (bt[cp] <= slice) {
                time += bt[cp];
                bt[cp] = 0;
                ct[cp] = time;
                count++;
                // printf("P%d completed at %d\n", cp, time);
            } else {
                bt[cp] -= slice;
                time += slice;
            }
        }
        cp = (cp + 1) % n;
    }

    // Calculate TAT and WT
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i];
        wt[i] = tat[i] - cpbt[i];
        tatavg += tat[i];
        wtavg += wt[i];
    }

    wtavg /= n;
    tatavg /= n;

    // Print results
    printf("\nPROCESS\tBURST TIME\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t%d\t%d\n", i, cpbt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage WT : %.2f\n", wtavg);
    printf("Average TAT: %.2f\n", tatavg);

    return 0;
}
