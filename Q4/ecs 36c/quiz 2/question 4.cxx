#include "json.hpp"
#include <iostream>
#include <string>
#include <fstream>
nlohmann::json jsonObject;
nlohmann::json metadata;

jsonObject["MyData"] = {1, 4};
metadata["quiz1"] = "finished";
metadata["value"] = 100;
jsonObject["metadata"] = metadata;
std::cout << finalObject.dump(2) << "\n";
