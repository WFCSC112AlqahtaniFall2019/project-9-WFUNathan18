//
// Created by Nathan Maynard on 12/5/19.
//

#ifndef PROJECT9_DATA_H
#define PROJECT9_DATA_H
#include <iostream>
#include <fstream>

using namespace std;

class Data {
public:
    Data();
    Data(ifstream& inFile); //Constructor
    friend ostream& operator<<(ostream& out, const Data& D); //Overloaded Output Operator
    bool operator> (const Data& D) const; //Overloaded Comparison operators
    bool operator< (const Data& D) const;
    bool operator<= (const Data& D) const;
    bool operator>= (const Data& D) const;
private:
    int entryNumber; //The rank as given in the original .csv file
                     //(the most popular girl's name in 1880 has an entryNumber of 1 and
                     //the least popular boy's name in 2014 has an entryNumber of 1825433)
    string name; //The name being evaluated
    int year; //The year the name was evaluated
    string gender; //Whether it is a girl's name (F) or boy's name (M)
    int numberOccurrences; //How popular a name is during a certain year
};

#endif //PROJECT9_DATA_H
