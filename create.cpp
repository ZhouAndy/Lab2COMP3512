//
// Created by andyr on 2019-01-18.
//

#include "create.hpp"
#include <random>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void create() {

    const int minLines = 512;
    const int maxLines = 1024;
    const double minDouble = 50.000;
    const double maxDouble = 90.000;

    //Create and open file for writing
    ofstream fOut;
    fOut.open("../Readings.txt");

    //Generate int between 512 and 1024
    random_device rd;
    mt19937 generator (rd());
    uniform_int_distribution <> distribution(minLines, maxLines);
    int numLines = distribution(generator);

    uniform_int_distribution <> doubleDistribution(minDouble, maxDouble);

    for(int i; i <= numLines; i++) {
        double randDouble = doubleDistribution(generator);
        fOut << i << setw(10) << fixed << setprecision(3) << randDouble << endl;
    }
}
