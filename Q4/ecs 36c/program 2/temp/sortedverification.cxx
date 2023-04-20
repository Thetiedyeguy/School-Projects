#include <iostream>     // includes iostream which is needed for printing and taking in values
#include <string>       // includes the string class
#include <fstream>      // includes fstream which is needed for taking file input
#include "json.hpp"     // include json.hpp used for json files
using namespace std;    // Allows utilization of many facets of std

int main(int argc, char **argv){    // starts the program and takes in user input
    std::ifstream file; // initializes a variable to store the file passed in by the user
    file.open(argv[1]); // opens the file specified by the user
    nlohmann::json jsonObject;  //initializes a json object to hold the data from the file
    if (file.is_open()){    // checks that the file opened properly
        file >> jsonObject; // passes the data from the file to the json object
    }   // end if
    nlohmann::json metadata; // initializes a json object to store and manipulate the metadata
    metadata = jsonObject["metadata"];  // sets the metadata json object equal to the metadata from the original json object
    int arraySize = metadata["arraySize"];  // initializes an int called arraySize and sets it equal to the arraySize stored in the metadata
    int numSamples = metadata["numSamples"];    // initializes an int called numSamples and sets it equal to the numSamples stored in the metadata
    int count = 0; // initializes an int called count to keep track of the number of samples found to be unsorted
    bool found = false; // initializes a boolean called found to keep track of if the current sample is sorted
    nlohmann::json finalObject; // initializes a json object to keep track of the result data that is to be printed
    for(auto itr = jsonObject.begin(); itr != jsonObject.end(); ++itr){ // start of a for each loop that iterates through the json
        if(itr.key() != "metadata"){ // makes sure the current json object is not the metadata
            found = false; // resets the found variable from previous loop runs
            nlohmann::json ConsecutiveInversion;    // initializes a new json object to keep track of the inversions
            int i = 0; // initializes an int to keep track of how many times the loop runs
            for(auto arrayItr = itr.value().begin() + 1; arrayItr != itr.value().end(); ++arrayItr){    // start of a for each loop to iterate through the array values
                if(*(arrayItr - 1) > *arrayItr){    // checks if the current value and the value before it are sorted properly
                    ConsecutiveInversion[to_string(i)] = {*(arrayItr -1), *arrayItr};   // records the out of order numbers and where they came from
                    if(!found){ // checks if this is the first inversion found
                        found = true;   // sets found equal to true to show that an inversion has been found
                        count++;    // increases the count to keep track of how many samples have inversions
                    }   // end if
                }   // end if
                i++;    // increments i to show the loop has run another time
            }   // end for
            if(found){  // checks if any inversions were found for the current sample
                nlohmann::json currentSample;   // initializes a json object to store information for the current sample
                currentSample["ConsecutiveInversions"] = ConsecutiveInversion;  // stores all the inversions found in the current sample json
                currentSample["sample"] = itr.value();  // stores the array from the current sample in the curren sample json
                finalObject[itr.key()] = currentSample; // stores the current sample json in the final json under the name of the current sample
            }   // end if
        }   // end if
    } // end for
    metadata["file"] = argv[1]; // stores the name of the file in the metadata json
    metadata["samplesWithInversions"] = count;  // stores the number of inversions in the metadat json
    finalObject["metadata"] = metadata; // stores the metadata in the final json
    std::cout << finalObject.dump(2) << "\n";   // prints out the final json
}   // end main
