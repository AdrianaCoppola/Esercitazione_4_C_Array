#include "Utils.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream Infile("data.csv");
    if (Infile.fail())
    {
        cerr << "Errore nell'apertura del file" << endl;
        return 1;
    }
    string line;
    char c;
    double S;
    lettura(Infile,line)>>c>>c>>S;
    int n;
    lettura(Infile,line)>>c>>c>>n;
    getline(Infile,line);

    double *ptrw=new double[n];
    double *ptr=new double[n];
    for (int i=0;i<n;i++)
    {
        lettura(Infile,line)>>ptrw[i]>>c>>ptr[i];
    }
    double V=portafoglio(n, S, ptr, ptrw);
    double r=V/S-1;
    ofstream Outfile("result.txt");
    Outfile.precision(2);
    Outfile << "S=" << fixed << S << ", n=" << n <<endl;
    Outfile << "w=";
    stampa(Outfile, n, ptrw) << endl;
    Outfile << "r=";
    stampa(Outfile, n, ptr) << endl;
    Outfile.precision(4);
    Outfile << "Rate of return of the portfolio: " << r << endl;
    Outfile.precision(2);
    Outfile << "V: " << V << endl;

    Infile.close();
    Outfile.close();

    ifstream screen("result.txt");
    if (screen.fail())
    {
        cerr << "Errore nell'apertura del file" << endl;
        return 1;
    }
    while(!screen.eof())
    {
        getline(screen,line);
        cout << line << endl;
    }

    screen.close();
    delete [] ptr;
    delete [] ptrw;
    return 0;
}
