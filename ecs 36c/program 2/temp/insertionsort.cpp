// Insertion Sort
//
// Author: Rob Gysel
// ECS60, UC Davis
// Adapted from: Lysecky & Vahid "Data Structures Essentials", zyBooks

#include "insertionsort.h"

void InsertionSort(std::vector<int>* numbers, int* comparisons, int* memAccesses) { // takes in pointer to variables used to store the number of comparisons and memory accesses
    int i = 0;
    int j = 0;
    int temp = 0;  // Temporary variable for swap

    for (i = 1; i < numbers->size(); ++i) {
        j = i;
        // Insert numbers[i] into sorted part
        // stopping once numbers[i] in correct position
        while (j > 0 && (*numbers)[j] < (*numbers)[j - 1]) {
            *comparisons = *comparisons + 1;    // increments the number of comparsions for the comparison in the loop header
            *memAccesses = *memAccesses + 6;    // increments the number of memory accesses 6 times for the two in the loop header and four within the loop
            // Swap numbers[j] and numbers[j - 1]
            temp = (*numbers)[j];
            (*numbers)[j] = (*numbers)[j - 1];
            (*numbers)[j - 1] = temp;
            --j;
        }
        if(j > 0){  // checks if the loop ended before checking if everything after the && is true
            *comparisons = *comparisons + 1;    // increments the number of comparsions for the comparison in the loop header the last time the loop conditions are checked
            *memAccesses = *memAccesses + 2;     // increments the number of memory accesses by two for the two in the loop header the last time the loop conditions are checked
        } // end if
    }

    return;
}
