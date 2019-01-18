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

    const int minLines = 512; //minimum line count
    const int maxLines = 1024; //maximum line count
    const double minDouble = 50000; //smallest double is 50.000
    const double maxDouble = 90000; //largest double is 90.000

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
        double randDecimal = randDouble / 1000;
        fOut << i << setw(10) << fixed << setprecision(3) << randDecimal << endl;
    }
    fOut.close();
}
