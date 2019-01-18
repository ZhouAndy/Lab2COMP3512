//
// Created by andyr on 2019-01-18.
//

#include "read.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

void read() {
    //Open file for reading
    ifstream file;
    file.open("../Readings.txt");

    //Determine number of lines in the file
    int lineCount = 0;
    string line;
    while (getline(file, line)) {
        lineCount++;
    }

    file.close();
    //Store doubles into an array.
    double doubleValues[lineCount];
    double doubleValue;
    int i = 0;
    ifstream secondStream;
    secondStream.open("../Readings.txt");
    while(secondStream >> doubleValue) {
        secondStream >> doubleValue;
        doubleValues[i] = doubleValue;
        i++;
    }
    secondStream.close();
    //Sort the array
    sort(doubleValues, doubleValues + lineCount);

    //Perform calculations;
    double sum = 0;
    for (int j = 0; j < lineCount; j++) {
        sum += doubleValues[j];
    }

    double median = lineCount % 2 != 0 ? doubleValues[lineCount / 2] :
                    (doubleValues[lineCount / 2 - 1] + doubleValues[lineCount / 2]) / 2;

    double average = sum/lineCount;
    cout << "There are " << lineCount << " readings in the file" << endl;
    cout << "The average reading is " << average << endl;
    cout << "The highest reading is " << doubleValues[lineCount - 1] << endl;
    cout << "The lowest reading is " << doubleValues[0] << endl;
    cout << "The median reading is " << median << endl;
};