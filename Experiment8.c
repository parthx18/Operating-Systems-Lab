//Implementation Logic
//We use a fixed number of frames (memory slots).
//We track the current position using a pointer (or a simple counter) that wraps around.
//A Page Fault occurs when the required page is not present in the frames.
//C Program for FIFO Page Replacement

#include <stdio.h>

int main() {
    int incomingStream[] = {4, 1, 2, 4, 5}; // Example page reference string
    int pageFaults = 0;
    int frames = 3;
    int m, n, s, pages;

    pages = sizeof(incomingStream) / sizeof(incomingStream[0]);

    printf("Incoming \t Frame 1 \t Frame 2 \t Frame 3\n");
    int temp[frames];
    for(m = 0; m < frames; m++) {
        temp[m] = -1; // Initialize frames as empty
    }

    for(m = 0; m < pages; m++) {
        s = 0;
        for(n = 0; n < frames; n++) {
            if(incomingStream[m] == temp[n]) {
                s++; // Page Hit
                pageFaults--;
            }
        }
        pageFaults++;

        if((pageFaults <= frames) && (s == 0)) {
            temp[m] = incomingStream[m];
        } else if(s == 0) {
            temp[(pageFaults - 1) % frames] = incomingStream[m];
        }

        printf("%d\t\t", incomingStream[m]);
        for(n = 0; n < frames; n++) {
            if(temp[n] != -1)
                printf(" %d\t\t", temp[n]);
            else
                printf(" - \t\t");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
    return 0;
}
