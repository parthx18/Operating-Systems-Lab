/*Implementation Logic
We maintain a "time-stamp" or "recent use" counter for each page in the frames.
When a page fault occurs and memory is full, we find the frame whose page was used farthest back in time and replace it.
C Program for LRU Page Replacement
*/
#include <stdio.h>

int findLRU(int time[], int n) {
    int i, minimum = time[0], pos = 0;
    for (i = 1; i < n; ++i) {
        if (time[i] < minimum) {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int no_of_frames, no_of_pages, frames[10], pages[30], counter = 0, time[10];
    int flag1, flag2, i, j, pos, faults = 0;

    printf("Enter number of frames: ");
    scanf("%d", &no_of_frames);

    printf("Enter number of pages: ");
    scanf("%d", &no_of_pages);

    printf("Enter reference string: ");
    for (i = 0; i < no_of_pages; ++i) {
        scanf("%d", &pages[i]);
    }

    for (i = 0; i < no_of_frames; ++i) {
        frames[i] = -1; // Initialize frames as empty
    }

    printf("\nRef String\t Frame 1 \t Frame 2 \t Frame 3\n");
    for (i = 0; i < no_of_pages; ++i) {
        flag1 = flag2 = 0;

        // Check if page already exists in frames (Page Hit)
        for (j = 0; j < no_of_frames; ++j) {
            if (frames[j] == pages[i]) {
                counter++;
                time[j] = counter;
                flag1 = flag2 = 1;
                break;
            }
        }

        // Page Fault: If page is not in frame and there is empty space
        if (flag1 == 0) {
            for (j = 0; j < no_of_frames; ++j) {
                if (frames[j] == -1) {
                    counter++;
                    faults++;
                    frames[j] = pages[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }

        // Page Fault: If page is not in frame and memory is full (LRU logic)
        if (flag2 == 0) {
            pos = findLRU(time, no_of_frames);
            counter++;
            faults++;
            frames[pos] = pages[i];
            time[pos] = counter;
        }

        printf("%d\t\t", pages[i]);
        for (j = 0; j < no_of_frames; ++j) {
            if (frames[j] != -1)
                printf(" %d\t\t", frames[j]);
            else
                printf(" - \t\t");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);
    return 0;
}
