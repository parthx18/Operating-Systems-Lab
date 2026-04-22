//1. Single Fork (2^1 = 2 processes)A single fork() creates one child. There are now 2 total processes.
C#include <stdio.h>
#include <unistd.h>

int main() {
    fork(); 
    printf("Process ID: %d\n", getpid());
    return 0;
}


//2. Double Fork (2^2 = 4 processes)Two consecutive fork() calls result in 4 total processes.Fork 1: Creates 1 child (Total: 2).Fork 2: Both the original parent and the first child call fork (Total: 4).
C#include <stdio.h>
#include <unistd.h>

int main() {
    fork();
    fork();
    printf("Process ID: %d, Parent ID: %d\n", getpid(), getppid());
    return 0;
}


//3. Triple Fork (2^3 = 8 processes)Three consecutive fork() calls result in 8 total processes. This creates a "tree" structure where the original parent eventually has several generations of descendants.
C#include <stdio.h>
#include <unistd.h>

int main() {
    fork(); // 2 processes
    fork(); // 4 processes
    fork(); // 8 processes
    
    printf("Hello from Process: %d\n", getpid());
    return 0;
}

/*
Number of Forks,Total Processes,New Processes Created
1 (Single),2,1
2 (Double),4,3
3 (Triple),8,7
n,2n,2n−1
*/
