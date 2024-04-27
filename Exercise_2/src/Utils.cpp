#include "Utils.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
istringstream lettura(ifstream& Infile, string& line)
{
    getline(Infile,line);
    istringstream conversion(line);
    return conversion;
}

ofstream& stampa(ofstream &Outfile, int n, double*& ptr)
{
    Outfile<<"[";
    for(int i=0;i<n;i++)
    {
        Outfile<<ptr[i]<<" ";
    }
    Outfile<<"]";
    return Outfile;
}

double portafoglio(int n, double S, double*& ptr, double*& ptrw)
{
    double V=0;
    for (int i=0;i<n;i++)
    {
        V+=(1+ptr[i])*ptrw[i]*S;
    }
    return V;
}
