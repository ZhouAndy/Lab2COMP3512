//
// Created by andyr on 2019-01-18.
//

#include "read.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

void read() {
    //Open file for reading
    ifstream file;
    file.open("../Readings.txt");

    int lineCount = 0;
    string line;

    while (getline(file, line)) {
        lineCount++;
    }

    

    file.close();


};