#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "sys/wait.h"

void perfromOperation(char op, int a, int b)
{
    int result = 0;
    switch (op)
    {
    case '+':
        result = a + b;
        exit(result);
        break;
    case '-':
        result = a - b;
        exit(result);
        break;
    case '*':
        result = a * b;
        exit(result);
        break;
    case '/':
        if (b == 0)
        {
            printf("Cannot divide by 0\n");
            exit(EXIT_FAILURE);
        }
        result = a / b;
        exit(result);

    default:
        printf("invalid operation\n");
        exit(EXIT_FAILURE);
        break;
    }
}

int main()
{
    char op;
    int a, b, status;
    printf("Enter a(operation)b values : ");
    scanf("%d%c%d", &a, &op, &b);
    printf("performing %d %c %d\n", a, op, b);
    pid_t pid = fork();

    if (pid < 0){
        perror("failed to create child process\n");
        return EXIT_FAILURE;
    }
    else if (pid == 0){
        perfromOperation(op, a, b);
    }
    else{
        waitpid(pid, &status, 0);
        if (WIFEXITED(status))
        {
            printf("Child process exited with result : %d\n", WEXITSTATUS(status));
        }
        else{
            printf("Child process did not terminate successfully\n");
        }
    }
}