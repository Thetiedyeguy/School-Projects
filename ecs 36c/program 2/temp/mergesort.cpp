// Merge Sort
//
// Author: Rob Gysel
// ECS60, UC Davis
// Adapted from: Lysecky & Vahid "Data Structures Essentials", zyBooks

#include "mergesort.h"

void MergeSort(std::vector<int>* numbers, int* comparisons, int* memAccesses) { // takes in pointer to variables used to store the number of comparisons and memory accesses
    MergeSortRecurse(numbers, 0, numbers->size() - 1, comparisons, memAccesses);    //passes pointers to varaibles used to store the number of compartisons and memory accesses
}


void MergeSortRecurse(std::vector<int>* numbers, int i, int k, int* comparisons, int* memAccesses) {    // takes in pointer to variables used to store the number of comparisons and memory accesses
    int j = 0;

    if (i < k) {
        j = (i + k) / 2;  // Find the midpoint in the partition

        // Recursively sort left and right partitions
        MergeSortRecurse(numbers, i, j, comparisons, memAccesses);  //passes pointers to varaibles used to store the number of compartisons and memory accesses
        MergeSortRecurse(numbers, j + 1, k, comparisons, memAccesses);  //passes pointers to varaibles used to store the number of compartisons and memory accesses

        // Merge left and right partition in sorted order
        Merge(numbers, i, j, k, comparisons, memAccesses);  //passes pointers to varaibles used to store the number of compartisons and memory accesses
    }
}

void Merge(std::vector<int>* numbers, int i, int j, int k, int* comparisons, int* memAccesses) {    // takes in pointer to variables used to store the number of comparisons and memory accesses
    int mergedSize = k - i + 1;                     // Size of merged partition
    int mergePos = 0;                                  // Position to insert merged number
    int leftPos = 0;                                    // Position of elements in left partition
    int rightPos = 0;                                  // Position of elements in right partition
    std::vector<int> mergedNumbers;
    mergedNumbers.resize(mergedSize);             // Dynamically allocates temporary array
                                                             // for merged numbers

    leftPos = i;                                         // Initialize left partition position
    rightPos = j + 1;                                  // Initialize right partition position

    // Add smallest element from left or right partition to merged numbers
    while (leftPos <= j && rightPos <= k) {
        *comparisons = *comparisons + 1;    // increments comparisons for the comparison in the if statement
        *memAccesses = *memAccesses + 4;    // increases memAccesses by four for the two in the if statement and the two that happen no matter the result of the if
        if ((*numbers)[leftPos] < (*numbers)[rightPos]) {
            mergedNumbers[mergePos] = (*numbers)[leftPos];
            ++leftPos;
        }
        else {
            mergedNumbers[mergePos] = (*numbers)[rightPos];
            ++rightPos;

        }
        ++mergePos;
    }

    // If left partition is not empty, add remaining elements to merged numbers
    while (leftPos <= j) {
        *memAccesses = *memAccesses + 2;    // increases memAccesses by two for the two on the next line
        mergedNumbers[mergePos] = (*numbers)[leftPos];
        ++leftPos;
        ++mergePos;
    }

    // If right partition is not empty, add remaining elements to merged numbers
    while (rightPos <= k) {
        *memAccesses = *memAccesses + 2;    // increases memAccesses by two for the two on the next line
        mergedNumbers[mergePos] = (*numbers)[rightPos];
        ++rightPos;
        ++mergePos;
    }

    // Copy merge number back to numbers
    for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
        *memAccesses = *memAccesses + 2;    // increases memAccesses by two for the two on the next line
        (*numbers)[i + mergePos] = mergedNumbers[mergePos];
    }
}
