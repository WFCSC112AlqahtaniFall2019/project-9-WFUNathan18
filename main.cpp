// Author: Nathan Maynard
// Course: CSC 112 Section B (Fall 2019)
// Project: Project 8
// Due Date: 3:30pm, Dec. 5, 2019

#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include "Data.h"
using namespace std;

// Important, code for bubbleSort(), mergeSort(), and selectSort() borrowed from the lecture slides

template <typename T>
void bubbleSort(vector <T>& arr, int size) {
    int i, j; 
    bool swapped; 
    for (i = 0; i < size-1; i++){ 
        swapped=false; 
        // Last i elements are already in place 
        for (j = 0; j < size-i-1; j++) 
        if (arr[j] > arr[j+1]) { 
            swap(&arr[j], &arr[j + 1]); 
            swapped=true; 
        } 
        //if there wasn't any swap in the inner loop, stop 
        if(!swapped) 
        break; 
    } 
}

template <typename T> 
void MinSort(vector <T>& arr, int size) { 
    int min; 
    for (int i = 0; i < size - 1; ++i) { 
    // Find index of smallest remaining element 
        min = i; 
        for (int j = i + 1; j < size; ++j) { 
            if (arr[j] < arr[min]) { 
                min = j; 
            } 
        } 
        swap(arr[i],arr[min]);
    }
}

template <typename Comparable>
void merge(vector<Comparable>& a, vector<Comparable>& tmpArray, int leftPos, int rightPos, int rightEnd) {
    int leftEnd = rightPos - 1;
    int tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    while (leftPos <= leftEnd && rightPos <= rightEnd) {
        if (a[leftPos] <= a[rightPos]) {
            tmpArray[tmpPos++] = move(a[leftPos++]);
        } else {
            tmpArray[tmpPos++] = move(a[rightPos++]);
        }
    }

    while (leftPos <= leftEnd)
        tmpArray[tmpPos++] = move(a[leftPos++]);

    while (rightPos <= rightEnd)
        tmpArray[tmpPos++] = move(a[rightPos++]);

    for (int i = 0; i < numElements; ++i, --rightEnd)
        a[rightEnd] = move(tmpArray[rightEnd]);
}

template <typename Comparable>
void mergeSort(vector<Comparable>& a, vector<Comparable>& tmpArray, int left, int right) {
    if (left < right) {
        int center = (left + right) / 2;
        mergeSort(a, tmpArray, left, center);
        mergeSort(a, tmpArray, center + 1, right);
        mergeSort(a, tmpArray, left, center+1, right);
    }
}

template <typename Comparable>
void mergeSort(vector<Comparable>& a) {
    vector <Comparable> tmpArray(a.size());
    mergeSort(a, tmpArray, 0, a.size() - 1);
}

int main() {
    ifstream inFile; //Input
    ofstream bubbleFile, bubbleBestFile, selectFile, selectBestFile, quickFile, quickBestFile, mergeFile, mergeBestFile; //Outputs
    int seed;
    int iter = 0;

    //Open files
    cout << "Opening Files..." << endl;
    bubbleFile.open("../bubbleTvN.csv");
    selectFile.open("../selectTvN.csv");
    quickFile.open("../quickTvN.csv");
    mergeFile.open("../mergeTvN.csv");
    bubbleBestFile.open("../bubbleTvNBest.csv");
    selectBestFile.open("../selectTvNBest.csv");
    quickBestFile.open("../quickTvNBest.csv");
    mergeBestFile.open("../mergeTvNBest.csv");

    if (!bubbleFile.is_open()) {
        cout << "Error opening bubbleTvN.csv" << endl;
        return 1;
    }
    if (!selectFile.is_open()) {
        cout << "Error opening selectTvN.csv" << endl;
        return 1;
    }
    if (!quickFile.is_open()) {
        cout << "Error opening quickTvN.csv" << endl;
        return 1;
    }
    if (!mergeFile.is_open()) {
        cout << "Error opening mergeTvN.csv" << endl;
        return 1;
    }
    if (!bubbleBestFile.is_open()) {
        cout << "Error opening bubbleTvNBest.csv" << endl;
        return 1;
    }
    if (!selectBestFile.is_open()) {
        cout << "Error opening selectTvNBest.csv" << endl;
        return 1;
    }
    if (!quickBestFile.is_open()) {
        cout << "Error opening quickTvNBest.csv" << endl;
        return 1;
    }
    if (!mergeBestFile.is_open()) {
        cout << "Error opening mergeTvNBest.csv" << endl;
        return 1;
    }


    while (5433 + (10000 * iter) <= 1825433) {}
    vector<Data> dataV(5433 + (10000 * iter)),
                 dataV_B(dataV.size()),
                 dataV_S(dataV.size()),
                 dataV_Q(dataV.size()),
                 dataV_M(dataV.size());
    vector<int> intV(5433 + (10000 * iter)),
                 intV_B(intV.size()),
                 intV_S(intV.size()),
                 intV_Q(intV.size()),
                 intV_M(intV.size());
    srand(clock());

    //Fill Data Vector
    inFile.open("../NationalNames.csv");
    if (!inFile.is_open()) {
        cout << "Error opening input file" << endl;
        return 1;
    }
    for (int i = 0; i < dataV.size(); i++) {
        Data nameData(inFile);
        dataV.at(i) = nameData;
    }
    inFile.close();

    //Copy Data Vector
    dataV_B = dataV;
    dataV_M = dataV;
    dataV_Q = dataV;
    dataV_S = dataV;

    //Fill Int Vector
    for (int i = 0; i < intV.size(); i++) {
        intV.at(i) = rand() % 1000;
    }

    //Copy Int Vector
    intV_B = intV;
    intV_M = intV;
    intV_Q = intV;
    intV_S = intV;

    //Close files
    cout << "Closing Files.." << endl;
    bubbleFile.close();
    selectFile.close();
    quickFile.close();
    mergeFile.close();
    bubbleBestFile.close();
    selectBestFile.close();
    quickBestFile.close();
    mergeBestFile.close();

    return 0;
}