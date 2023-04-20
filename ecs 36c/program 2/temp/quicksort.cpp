// Quicksort
//
// Author: Rob Gysel
// ECS60, UC Davis
// Adapted from: Lysecky & Vahid "Data Structures Essentials", zyBooks

#include "quicksort.h"


void QuickSort(std::vector<int>* numbers, int* comparisons, int* memAccesses) { // takes in pointer to variables used to store the number of comparisons and memory accesses
    QuickSortRecurse(numbers, 0, numbers->size() - 1, comparisons, memAccesses);
}

void QuickSortRecurse(std::vector<int>* numbers, int i, int k, int* comparisons, int* memAccesses) {    // takes in pointer to variables used to store the number of comparisons and memory accesses
    int j = 0;

    /* Base case: If there are 1 or zero elements to sort,
     partition is already sorted */
    if (i >= k) {
        return;
    }

    /* Partition the data within the array. Value j returned
     from partitioning is location of last element in low partition. */
    j = Partition(numbers, i, k, comparisons, memAccesses); //passes pointers to varaibles used to store the number of compartisons and memory accesses

    /* Recursively sort low partition (i to j) and
     high partition (j + 1 to k) */
    QuickSortRecurse(numbers, i, j, comparisons, memAccesses);  //passes pointers to varaibles used to store the number of compartisons and memory accesses
    QuickSortRecurse(numbers, j + 1, k, comparisons, memAccesses);  //passes pointers to varaibles used to store the number of compartisons and memory accesses

    return;
}

int Partition(std::vector<int>* numbers, int i, int k, int* comparisons, int* memAccesses) {    // takes in pointer to variables used to store the number of comparisons and memory accesses
    int l = 0;
    int h = 0;
    int midpoint = 0;
    int pivot = 0;
    int temp = 0;
    bool done = false;

    /* Pick middle element as pivot */
    midpoint = i + (k - i) / 2;
    pivot = (*numbers)[midpoint];
    *memAccesses = *memAccesses + 1; // increments memAccesses do to the memory access in the line above

    l = i;
    h = k;

    while (!done) {

        /* Increment l while numbers[l] < pivot */
        while ((*numbers)[l] < pivot) {
            *memAccesses = *memAccesses + 1;    // increments memAccesses due to the memory being accessed in the loop header
            *comparisons = *comparisons + 1;    // increments comparisons due to the memory being accessed in the loop header
            ++l;
        }
        *memAccesses = *memAccesses + 1;    // increments memAccesses for the last time the loop header is evaluated
        *comparisons = *comparisons + 1;    // increments comparisons for the last time the loop header is evaluated
        /* Decrement h while pivot < numbers[h] */
        while (pivot < (*numbers)[h]) {
            *memAccesses = *memAccesses + 1;    // increments memAccesses due to the memory being accessed in the loop header
            *comparisons = *comparisons + 1;    // increments comparisons due to the memory being accessed in the loop header
            --h;
        }
        *memAccesses = *memAccesses + 1;     // increments memAccesses for the last time the loop header is evaluated
        *comparisons = *comparisons + 1;    // increments comparisons for the last time the loop header is evaluated

        /* If there are zero or one elements remaining,
         all numbers are partitioned. Return h */
        if (l >= h) {
            done = true;
        }
        else {
            /* Swap numbers[l] and numbers[h],
             update l and h */
            temp = (*numbers)[l];
            (*numbers)[l] = (*numbers)[h];
            (*numbers)[h] = temp;
            *memAccesses = *memAccesses + 4;    // increments memAccesses 4 times. once for line 78, twice for 79, and once for 80

            ++l;
            --h;
        }
    }

    return h;
}
