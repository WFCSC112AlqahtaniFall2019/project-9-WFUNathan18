//
// Created by Nathan Maynard on 12/5/19.
//

#include <iostream>
#include "Data.h"

Data::Data() {
    entryNumber = 0;
    name = "NoName";
    year = 0000;
    gender = "N";
    numberOccurrences = 0;
}

Data::Data(ifstream& in) {
    //Temporary strings for integer values, will be converted to ints when reading file
    string strEntNum, strYear, strNumOcc;

    //Read and assign members
    getline(in, strEntNum, ','); entryNumber = stoi(strEntNum);
    getline(in, name, ',');
    getline(in, strYear, ','); year = stoi(strYear);
    getline(in, gender, ',');
    getline(in, strNumOcc, ','); numberOccurrences = stoi(strNumOcc);

}

ostream& operator<<(ostream& out, const Data &D) {
    out << D.entryNumber << ","
        << D.name << ","
        << D.year << ","
        << D.gender << ","
        << D.numberOccurrences << endl;

    return out;
}

bool Data::operator>(const Data& D) const {
    if (numberOccurrences > D.numberOccurrences)
        return true;

    return false;
}

bool Data::operator<(const Data& D) const {
    if (numberOccurrences < D.numberOccurrences)
        return true;

    return false;
}

bool Data::operator<= (const Data& D) const {
    if (numberOccurrences <= D.numberOccurrences)
        return true;

    return false;
}