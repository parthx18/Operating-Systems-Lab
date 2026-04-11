/*Experiment 12: Producer-Consumer Problem
C Program (Using Semaphores)
Note: This code uses a simple switch-case simulation to demonstrate the logic without requiring complex POSIX thread libraries, making it easier to run and explain.
*/
#include <stdio.h>
#include <stdlib.h>

int mutex = 1;
int full = 0;
int empty = 10, x = 0; // Assuming buffer size is 10

void producer() {
    --mutex;    // Lock the buffer
    ++full;     // Increment full slots
    --empty;    // Decrement empty slots
    x++;        // Produce an item
    printf("\nProducer produces item %d", x);
    ++mutex;    // Unlock the buffer
}

void consumer() {
    --mutex;    // Lock the buffer
    --full;     // Decrement full slots
    ++empty;    // Increment empty slots
    printf("\nConsumer consumes item %d", x);
    x--;        // Consume an item
    ++mutex;    // Unlock the buffer
}

int main() {
    int n, i;
    printf("\n1. Press 1 for Producer"
           "\n2. Press 2 for Consumer"
           "\n3. Press 3 for Exit");

    for (i = 1; i > 0; i++) {
        printf("\n\nEnter your choice: ");
        scanf("%d", &n);

        switch (n) {
        case 1:
            if ((mutex == 1) && (empty != 0)) {
                producer();
            } else {
                printf("Buffer is full!");
            }
            break;

        case 2:
            if ((mutex == 1) && (full != 0)) {
                consumer();
            } else {
                printf("Buffer is empty!");
            }
            break;

        case 3:
            exit(0);
            break;
        }
    }
}
