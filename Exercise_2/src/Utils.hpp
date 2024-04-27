#ifndef __RATE_H
#define __RATE_H
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
istringstream lettura(ifstream& Infile, string& line);
ofstream& stampa(ofstream &Outfile, int n, double*&ptr);
double portafoglio(int n, double S, double*&ptrR, double*&ptrW);

#endif
