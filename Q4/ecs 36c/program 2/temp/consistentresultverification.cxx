#include <iostream>     // includes iostream which is needed for printing and taking in values
#include <string>       // includes the string class
#include <fstream>      // includes fstream which is needed for taking file input
#include "json.hpp"     // include json.hpp used for json files
using namespace std;    // Allows utilization of many facets of std

int main(int argc, char **argv){    // starts the program and takes in user input
    std::ifstream file1;        // initializes a variable for the first file to be passed into
    std::ifstream file2;        // initializes a variable for the second file to be passed into
    file1.open(argv[1]);        // opens up the first file from user input so it can be accessed
    file2.open(argv[2]);        // opens up the second file from user input so it can be accessed
    nlohmann::json jsonObject1; // initializes a json object to hold the first files data
    nlohmann::json jsonObject2; // initializes a second json object to hold the second files data
    nlohmann::json finalObject; // initializes a third json file to hold the final results to be printed
    if (file1.is_open()){       // checks to make sure that the file passed in is usable
        file1 >> jsonObject1;   // passes the data from the file to jsonObject1
    }                           // end of if statement
    if (file2.is_open()){       // checks to make sure that the second file passed in is usable
        file2 >> jsonObject2;   // passes the data from the file to jsonObject2
    }                           // end of if statement
    jsonObject1["metadata"]["name"] = argv[1];  // puts the name of the file that its data represents into jsonObject1's metadata
    jsonObject2["metadata"]["name"] = argv[2];  // puts the name of the file that its data represents into jsonObject2's metadata
    int arraySize = jsonObject1["metadata"]["arraySize"];   //initializes a variable arraySize to be equal to the arraySize stored in the jsons metadata
    bool difference;    // initializes a boolean to track if the current sample has any differences
    int numConflicting = 0; // initializes an integer to trak the number of samples that have a difference
    auto itr1 = jsonObject1.begin();    // initializes an iterator for jsonObject1 for the loop
    auto itr2 = jsonObject2.begin();    // initializes an iterator for jsonObject2 for the loop
    for(; itr1 != jsonObject1.end() && itr2 != jsonObject2.end(); ++itr1, ++itr2){  // a for each loop that runs iterators through both jsons simultaneously
        if(itr1.key() != "metadata"){   // makes sure the iterator is not at metadata and is therefore looking at a sample
            difference = false; // sets the difference equal to false to erase data from previous samples
            nlohmann::json mismatches;  // creates a json object to store all of the differences
            auto arrayItr1 = itr1.value().begin();  //initializes an iterator to iterate through the array stored in the current sample in file 1
            auto arrayItr2 = itr2.value().begin();  //initializes an iterator to iterate through the array stored in the current sample in file 2
            int i = 0;  // initializes an integer to keep track of how many times the loop has run
            for(;arrayItr1 != itr1.value().end() && arrayItr2 != itr2.value().end(); ++arrayItr1, ++arrayItr2){ // for each loop to loop through both arrays
                if(*arrayItr1 != *arrayItr2){   // checks if the array iterators values are equal
                    if(!difference){    // checks if this is the first difference in the current sample
                        numConflicting++;   // increments the variable keeping track of the number of conflicting samples
                        difference = true;  // sets difference equal to tru to show that the samples being diffrent is already accounted for
                    }   // end if
                    mismatches[to_string(i)] = {*arrayItr1, *arrayItr2};    //records the difference that was found in the json mismatches
                }   // end if
                i++;    // increments i to show the loop has been run another time
            }   // end for loop
            if(difference){ // checks if the current sample had any difference
                finalObject[itr1.key()][argv[1]] = itr1.value();    //stores the current array1 in the final object under the name of the file it came from under the current sample name
                finalObject[itr2.key()][argv[2]] = itr2.value();    //stores the current array2 in the final object under the name of the file it came from under the current sample name
                finalObject[itr1.key()]["Mismatches"] = mismatches; //stores the mismatches found under the name Mismatches under the current sample name
            }   // end if
        }   // end if
    }   // end for loop
    finalObject["metadata"]["File1"] = jsonObject1["metadata"]; // stores the metadata of File1 in the metadata of the final object under File1
    finalObject["metadata"]["File2"] = jsonObject2["metadata"]; // stores the metadata of File2 in the metadata of the final object under File2
    finalObject["metadata"]["samplesWithConflictingResults"] = numConflicting;  // stores the number of conflicting samples in the metadata of the final object.
    std::cout << finalObject.dump(2) << "\n";   // prints out the final object
}   // end main
