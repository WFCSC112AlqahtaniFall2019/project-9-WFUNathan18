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

//
// Important, code for bubbleSort(), mergeSort(), selectSort(),
// and quickSort()'s median-of-three algorithm borrowed from the lecture slides
//

template <typename T>
void bubbleSort(vector <T>& arr, int size) {
    int i, j; 
    bool swapped; 
    for (i = 0; i < size-1; i++){ 
        swapped=false; 
        // Last i elements are already in place 
        for (j = 0; j < size-i-1; j++) 
        if (arr[j] < arr[j+1]) { 
            swap(arr[j], arr[j + 1]); 
            swapped=true; 
        } 
        //if there wasn't any swap in the inner loop, stop 
        if(!swapped) 
        break; 
    } 
}

template <typename T> 
void MaxSort(vector <T>& arr, int size) { 
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

template <typename T>
const T& median3 (vector<T>& a, int left, int right) {
    int center = (left + right) / 2;

    if (a[center] > a[left])
        swap(a[left], a[center]);
    if (a[right] > a[left])
        swap(a[left],a[right]);
    if (a[right] > a[center])
        swap(a[center], a[right]);

    swap(a[center], a[right - 1]);
    return a[right - 1];
}

template <typename T>
int qsPartition(vector<T>& a, T pivot, int lowIndex, int highIndex) {
    //Move pivot out of the way
    swap(a[highIndex], pivot);

    int i = lowIndex - 1;
    int j = lowIndex;

    while (j < highIndex - 1) {
        if (a[j] > pivot) {
            i++;
            swap(a[i], a[j]);
        }
        j++;
    }
    swap(a[i + 1], a[highIndex]); //highIndex is the pivot index

    return (i + 1); //Return
}

template <typename T>
void quickSort(vector<T>& a, int lowIndex, int highIndex) {
    if (lowIndex < highIndex) { //If distance between indexes is more than 0
        T pivot = median3(a, lowIndex, highIndex); //Assign pivot
        int partInd = qsPartition(a, pivot, lowIndex, highIndex); //Partitioning Index
        quickSort(a, lowIndex, (partInd - 1)); //Sort group s1
        quickSort(a, (partInd + 1), highIndex); //Sort group s2
    }
}

template <typename T> //Driver function
void quickSort(vector<T>& a) {
    quickSort(a, 0, (a.size() - 1));
}

template <typename T>
void merge(vector<T>& a, vector<T>& tmpArray, int leftPos, int rightPos, int rightEnd) {
    int leftEnd = rightPos - 1;
    int tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    while (leftPos >= leftEnd && rightPos >= rightEnd) {
        if (a[leftPos] >= a[rightPos]) {
            tmpArray[tmpPos++] = move(a[leftPos++]);
        } else {
            tmpArray[tmpPos++] = move(a[rightPos++]);
        }
    }

    while (leftPos >= leftEnd)
        tmpArray[tmpPos++] = move(a[leftPos++]);

    while (rightPos >= rightEnd)
        tmpArray[tmpPos++] = move(a[rightPos++]);

    for (int i = 0; i < numElements; ++i, --rightEnd)
        a[rightEnd] = move(tmpArray[rightEnd]);
}

template <typename T>
void mergeSort(vector<T>& a, vector<T>& tmpArray, int left, int right) {
    if (left < right) {
        int center = (left + right) / 2;

        //Divide
        mergeSort(a, tmpArray, left, center);
        mergeSort(a, tmpArray, center + 1, right);

        //Conquer
        merge(a, tmpArray, left, center+1, right);
    }
}

template <typename T>
void mergeSort(vector<T>& a) {
    vector <T> tmpArray(a.size());
    mergeSort(a, tmpArray, 0, a.size() - 1);
}

int main() {
    ifstream inFile; //Input
    ofstream bubbleSortedFile, selectSortedFile, quickSortedFile, mergeSortedFile, bubbleFile, bubbleBestFile, selectFile, selectBestFile, quickFile, quickBestFile, mergeFile, mergeBestFile; //Outputs
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

    cout << "2";
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

    while (/*5433 + (10000 * iter) <= 1825433*/ iter < 8) {
        vector<Data> dataV(5433 + (1000 * iter)),
                dataV_B(dataV.size()),
                dataV_S(dataV.size()),
                dataV_Q(dataV.size()),
                dataV_M(dataV.size());
        vector<int> intV(5433 + (1000 * iter)),
                intV_B(intV.size()),
                intV_S(intV.size()),
                intV_Q(intV.size()),
                intV_M(intV.size());
        srand(clock());

        //Open sorted output files
        bubbleSortedFile.open("../bubbleSorted.csv");
        selectSortedFile.open("../selectSorted.csv");
        quickSortedFile.open("../quickSorted.csv");
        mergeSortedFile.open("../mergeSorted.csv");
        cout << "1";
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

        //Bubble Sort
        bubbleSort<Data> (dataV_B, dataV_B.size());
        clock_t start = clock();
        bubbleSort<int> (intV_B, intV_B.size());
        clock_t end = clock();
        double elapsedTime = double(end - start) / CLOCKS_PER_SEC;

        //Bubble Sort with sorted vector
        bubbleSort<Data> (dataV_B, dataV_B.size());
        start = clock();
        bubbleSort<int> (intV_B, intV_B.size());
        end = clock();
        double elapsedTimeBest = double(end - start) / CLOCKS_PER_SEC;

        //Write to output files
        for (int i = 0; i < dataV_B.size(); i++) {
            bubbleSortedFile << dataV_B.at(i);
        }
        bubbleSortedFile.close();
        bubbleFile << intV_B.size() << "," << elapsedTime << endl;
        bubbleBestFile << intV_B.size() << "," << elapsedTimeBest << endl;

        //Select Sort
        MaxSort<Data> (dataV_S, dataV_S.size());
        start = clock();
        MaxSort<int> (intV_S, intV_S.size());
        end = clock();
        elapsedTime = double(end - start) / CLOCKS_PER_SEC;

        //Select Sort with sorted vector
        MaxSort<Data> (dataV_S, dataV_S.size());
        start = clock();
        MaxSort<int> (intV_S, intV_S.size());
        end = clock();
        elapsedTimeBest = double(end - start) / CLOCKS_PER_SEC;

        //Write to output files
        for (int i = 0; i < dataV_S.size(); i++) {
            selectSortedFile << dataV_S.at(i);
        }
        selectSortedFile.close();
        selectFile << intV_S.size() << "," << elapsedTime << endl;
        selectBestFile << intV_S.size() << "," << elapsedTimeBest << endl;

        //Quick Sort
        quickSort<Data> (dataV_Q);
        start = clock();
        quickSort<int> (intV_Q);
        end = clock();
        elapsedTime = double(end - start) / CLOCKS_PER_SEC;

        //Quick Sort with sorted vector
        quickSort<Data> (dataV_Q);
        start = clock();
        quickSort<int> (intV_Q);
        end = clock();
        elapsedTimeBest = double(end - start) / CLOCKS_PER_SEC;

        //Write to output files
        for (int i = 0; i < dataV_Q.size(); i++) {
            quickSortedFile << dataV_Q.at(i);
        }
        quickSortedFile.close();
        quickFile << intV_Q.size() << "," << elapsedTime << endl;
        quickBestFile << intV_Q.size() << "," << elapsedTimeBest << endl;

        //Merge Sort
        mergeSort<Data> (dataV_M);
        start = clock();
        mergeSort<int> (intV_M);
        end = clock();
        elapsedTime = double(end - start) / CLOCKS_PER_SEC;

        //Bubble Sort with sorted vector
        mergeSort<Data> (dataV_M);
        start = clock();
        mergeSort<int> (intV_M);
        end = clock();
        elapsedTimeBest = double(end - start) / CLOCKS_PER_SEC;

        //Write to output files
        for (int i = 0; i < dataV_M.size(); i++) {
            selectSortedFile << dataV_M.at(i);
        }
        mergeSortedFile.close();
        mergeFile << intV_M.size() << "," << elapsedTime << endl;
        mergeBestFile << intV_M.size() << "," << elapsedTimeBest << endl;

        //Increment iterator
        iter++;
    }

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