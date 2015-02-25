//
//  Darin Nelson
//  Homework #4
//  2/24/15
//  CIVL 7903
//

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <limits>
#include <stdlib.h>
#include <math.h>

using namespace std;

void open_input(ifstream &chater, string chater2)
{
    chater.open(chater2.c_str());
}

void open_output(ofstream &chater, string chater2)
{
    chater.open(chater2.c_str());
}

void open_error(ofstream &chater, string chater2)
{
    chater.open(chater2.c_str());
}

void print_output(ofstream &chater, string chater2, string type, long int Fib, long int L)
{
    if (Fib == 1000)
    {
        cout   << "Cannot open " << type << " file: "
               << chater2
               << endl;
        if (type != "error")
        {
            chater << "Cannot open " << type << " file: "
                   << chater2
                   << endl;
        }
        exit(EXIT_FAILURE);
    } else {
        cout << left << setw(L) << Fib;
        chater << left << setw(L) << Fib;
    }
}
    

int main () {
    
    cout << "I was able to compile this code using the HPC at the University of Memphis.\n"
         << "When I compiled it there, it did not produce any warning message.\n"
         << "The HPC uses a GNU C++ compiler that can be considered a good up-to-date standard.\n"
         << "I also version-controlled this code using git, and used a remote repository hosted by github.\n"
         << "If I can do this, so can you!!!\n"
         << "I am so cool, that I was able to write a code that produces the first M numbers of the Fibonacci sequence.\n\n"
         << "Here they are:\n\n";
    
    string   inputfilename, outputfilename, errorfilename;
    ifstream inputfile;
    ofstream outputfile, errorfile;
    
    inputfilename = "darin.in.txt";
    outputfilename = "darin.out";
    errorfilename = "darin.err";
    open_input(inputfile, inputfilename);
    open_output(outputfile, outputfilename);
    open_error(errorfile, errorfilename);
    
    int bb = 1000;
    double Length = 1000;
    
    if ( !inputfile.is_open() )
    {
        print_output(errorfile, inputfilename, "input", bb, Length);
    } else if ( !outputfile.is_open() ) {
        print_output(errorfile, outputfilename, "output", bb, Length);
    } else if ( !errorfile.is_open() ) {
        print_output(errorfile, errorfilename, "error", bb, Length);
    }
    
    int M, N, counter, LengthInt;
    long long int FibPrev, FibCurr, FibNex;
    double phi;
    
    inputfile >> N;
    M = 10 * N;
    counter = 1;
    FibPrev = 0;
    FibCurr = 1;
    phi = (1 + sqrt(5))/2;
    Length = log10(pow(phi,M)/sqrt(5));
    LengthInt = ceil(Length) + 2;
    
    while (counter <= M)
    {
        print_output(outputfile, outputfilename, "input", FibPrev, LengthInt);
        FibNex = FibPrev + FibCurr;
        FibPrev = FibCurr;
        FibCurr = FibNex;
        if (counter % 10 == 0)
        {
            cout << "\n";
            outputfile << "\n";
        }
        counter++;
    }
    
    return 0;
}