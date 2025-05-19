#include "stdio.h"
#include "stdlib.h"

int mutex = 1, full = 0, empty = 3, x=0;

void wait(int* s){
    *s -= 1;
}
void signal(int* s){
    *s += 1;
}

void producer(){
    wait(&mutex);
    signal(&full);
    wait(&empty);
    x++;
    printf("Producer produces item %x\n",x);
    signal(&mutex);
}

void consumer(){
    wait(&mutex);
    signal(&empty);
    wait(&full);
    printf("Consumer consumes item %x\n",x);
    x--;
    signal(&mutex);
}

int main()
{
    int n;
    printf("1)PRODUCE 2)CONSUME 3)EXIT\n");
    while(1){
        printf("Enter choice : ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            if(mutex && empty){
                producer();
            }
            else{
                printf("cannot produce\n");
            }
            break;
        case 2:
            if(mutex && full){
                consumer();
            }
            else{
                printf("cannot consume\n");
            }
            break;
        case 3:
            printf("Exiting...\n");
            exit(0);
            break;
        default:
            printf("invalid input\n");
            break;
        }
    }
}