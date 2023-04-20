#include <iostream>     // includes iostream which is needed for printing and taking in values
#include <string>       // includes the string class
#include <fstream>      // includes fstream which is needed for taking file input
#include <ctime>        // includes ctime which is used to record time
#include <time.h>       // includes time.h which is also needed to record time
#include "json.hpp"     // include json.hpp used for json files
#include "insertionsort.h"  // includes the insertion sort program to be able to use insertion sort
#include "mergesort.h"  // includes the merge sort program to be able to use merge sort
#include "quicksort.h"  // includes the quick sort program to be able to use quick sort
using namespace std;    // Allows utilization of many facets of std
int main(int argc, char** argv) {   // starts the program and allows user input
    std::ifstream file; // initializes a variable to store the file passed in by the user
    file.open(argv[1]); // opens the file specified by the user
    nlohmann::json jsonObject;  //initializes a json object to hold the data from the file
    if (file.is_open()){    // checks that the file opened properly
        file >> jsonObject; // passes the data from the file to the json object
    }   // end if
    int insertionComparisons;   // initializes a variable to keep track of the number of comparisons insertion uses
    int insertionMemAccesses;   // initializes a variable to keep track of the number of memory accesses insertion uses
    float insertionTime;    // initializes a variable to keep track of the amount of time insertion takes
    int mergeComparisons;   // initializes a variable to keep track of the number of comparisons merge uses
    int mergeMemAccesses;   // initializes a variable to keep track of the number of memory accesses merge uses
    float mergeTime;    // initializes a variable to keep track of the amount of time merge takes
    int quickComparisons;   // initializes a variable to keep track of the number of comparisons quicksort uses
    int quickMemAccesses;   // initializes a variable to keep track of the number of memory accesses quicksort uses
    float quickTime;    // initializes a variable to keep track of the amount of time quicksort takes
    std::cout << "Sample";  // prints out the first word of the header Sample
    std::cout << "," << "InsertionSortTime" << "," << "InsertionSortCompares" << "," << "InsertionSortMemaccess";   //  prints out all portions of the header pertaining to insertion sort in csv style
    std::cout << "," << "MergeSortTime" << "," << "MergeSortCompares" << "," << "MergeSortMemaccess";   //  prints out all portions of the header pertaining to merge sort in csv style
    std::cout << "," << "QuickSortTime" << "," << "QuickSortCompares" << "," << "QuickSortMemaccess" << "\n";   //  prints out all portions of the header pertaining to quick sort in csv style and the new line
    for(auto itr = jsonObject.begin(); itr != jsonObject.end(); ++itr){ // a for each loop that iterates through all the samples
        if(itr.key() != "metadata"){    // makes sure the current sample isnt the metadata
            clock_t i;  //initializes a variable to keep track of the time insertion sort takes
            clock_t m;  //initializes a variable to keep track of the time merge sort takes
            clock_t q;  //initializes a variable to keep track of the time quick sort takes
            insertionComparisons = 0;   // sets insertionComparisons to zero to clear it of previous data
            insertionMemAccesses = 0;   // sets insertionMemAccesses to zero to clear it of previous data
            insertionTime = 0;  // sets insertionTime to zero to clear it of previous data
            mergeComparisons = 0;   // sets mergeComparisons to zero to clear it of previous data
            mergeMemAccesses = 0;   // sets mergeMemAccesses to zero to clear it of previous data
            mergeTime = 0;  // sets mergeTime to zero to clear it of previous data
            quickComparisons = 0;   // sets quickComparisons to zero to clear it of previous data
            quickMemAccesses = 0;   // sets quickMemAccesses to zero to clear it of previous data
            quickTime = 0;  // sets quickTime to zero to clear it of previous data
            std::vector<int> originalVector = itr.value().get<vector<int>>();   // sets a vector to be equal to the array in the current sample
            std::vector<int> vectorCopy = originalVector;   // creates a copy of the origianl vector so that it can be manipulated without changing the original
            i = clock();    // starts the timer for insertion sort
            InsertionSort(&vectorCopy, &insertionComparisons, &insertionMemAccesses);   // calls insertion sort on the vector and passes it variables to store the number of comparisons and memory accesses
            i = clock() - i;    // stops the timer for insertion sort
            insertionTime = ((float)i) / CLOCKS_PER_SEC;    // converts the timer into seconds and stores it in insertionTime
            vectorCopy = originalVector;    // resets the vectorCopy back to the original value
            m = clock();    // starts the timer for merge sort
            MergeSort(&vectorCopy, &mergeComparisons, &mergeMemAccesses);   // calls merge sort on the vector and passes it variables to store the number of comparisons and memory accesses
            m = clock() - m;    // stops the timer for merge sort
            mergeTime = ((float)m) / CLOCKS_PER_SEC;    // converts the timer into seconds and stores it in mergeTime
            vectorCopy = originalVector;    // resets the vectorCopy back to the original value
            q = clock();    // starts the timer for quick sort
            QuickSort(&vectorCopy, &quickComparisons, &quickMemAccesses);   // calls quick sort on the vector and passes it variables to store the number of comparisons and memory accesses
            q = clock() - q;    // stops the timer for quick sort
            quickTime = ((float)q) / CLOCKS_PER_SEC;    // converts the timer into seconds and stores it in quickTime
            std::cout << itr.key(); // prints out the name of the current sample
            std::cout << "," << insertionTime << "," << insertionComparisons << "," << insertionMemAccesses;    // prints out the time, number of comparisons, and number of mem accesses for insertion sort in csv style
            std::cout << "," << mergeTime << "," << mergeComparisons << "," << mergeMemAccesses;    // prints out the time, number of comparisons, and number of mem accesses for merge sort in csv style
            std::cout << "," << quickTime << "," << quickComparisons << "," << quickMemAccesses << "\n";    // prints out the time, number of comparisons, and number of mem accesses for quick sort in csv style
        }
    }
}
