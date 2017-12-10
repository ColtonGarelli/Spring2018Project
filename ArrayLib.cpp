//
// Created by Taylor Yowan on 9/6/17.
// Worked with Jeremy Block during lab time.
//
#include <cmath>
#include <cstdlib>
#include <iostream>
#include "ArrayLib.h"


int genRandInt (int min, int max,int& numLinesRun){
    (numLinesRun) += 3;
    if (min > max) {
        std::cout << "ERROR:: Please provide min and max in proper order" << std::endl;
        (numLinesRun) += 1;
        return -1;
    }
    (numLinesRun) +=1;
    return rand()%(max-min+1)+min;
}


int* genRandArray(int size, int min, int max, int& numLinesRun){
    (numLinesRun) += 4;
    if(min > max){
        int temp = max;
        max = min;
        min = temp;
        (numLinesRun) +=3;
    }
    int* myArray = new int[size];
    (numLinesRun) += 2;
    for(int i = 0; i < size; i++){
        (numLinesRun) += 3;
        myArray[i] = rand()%(max-min +1)+min;
        (numLinesRun) += 1;
    }
    return myArray;

}

int* genShuffledArray(int size, int& numLinesRun){
    int* myShuffledArray = new int[size];
    (numLinesRun) += 3;
    for (int i= 0; i<= size; i++){
        (numLinesRun) +=3;
        myShuffledArray[i] = i+1;
        (numLinesRun) +=1;
    }
    for (int i = 0; i < size;i++ ){
        (numLinesRun) +=3;
        int tempTimer = 0;
        int index = genRandInt(0, size-1, tempTimer);
        int temp = myShuffledArray[index];
        myShuffledArray[index] = myShuffledArray[i];
        myShuffledArray[i] = temp;
        (numLinesRun) +=5;
    }
    return myShuffledArray;

}

std::string toString(const int* const arrayPtr, const int size, const std::string printable){
    if(size <= 0){
        return "}";
    } else if (size == 1){
        return std::to_string(arrayPtr[0]) + "}";
    }
    else{
        std::string tempStr = (std::to_string(arrayPtr[0])) + ", " +  toString(arrayPtr+1,size-1,printable);
        return tempStr;
    }
}

std::string toString(const int* const arrayPtr,const int size){
    std::string printable = "{";
    return printable + toString(arrayPtr,size,printable);
}


int find(const int* arrayPtr, int size, int numToFind){
    //(numLinesRun) += 4;
    for (int i = 0; i < size; i++){
        //(numLinesRun) +=3;
        if (arrayPtr[i] == numToFind){
            return i;
        }
       // (numLinesRun) +=1;
    }
    return -1;


}

int findLast(const int* arrayPtr, int size, int numToFind, int& numLinesRun){
    (numLinesRun) += 4;
    for (int i = size-1; i >= 0; i--){
        (numLinesRun) +=3;
        if (arrayPtr[i] == numToFind){
            (numLinesRun) +=1;
            return i;
        }
    }
    return -1;

};

int findMaxIndex(const int* arrayPtr, int size, int& numLinesRun){
    int Max = arrayPtr[0];
    int MaxIndex = 0;
    (numLinesRun) +=5;
    for(int i = 0; i < size; i++ ){
        (numLinesRun) +=3;
        for(int i = 1; i < size; i++){
            (numLinesRun) +=3;
            if(Max < arrayPtr[i]){
                MaxIndex = i;
                (numLinesRun) +=1;
            }
            (numLinesRun) += 1;
        }

    }
    (numLinesRun) +=1;
    if(size < 1){
        return -1;
    }
    else{
        return MaxIndex;
    }
}


/*
 * This is bubble sort
 * */
void sort(int* arrayToSort, int size, int& numLinesRun){
    bool swapped = true;
    int j = 0;
    int tmp;
    (numLinesRun) += 6;
    while (swapped) {
        swapped = false;
        j++;
        (numLinesRun) +=3;
        //for loop compares each set of two elements in the array
        //if the value of i is greater then i+1 then the values are swapped
        //does this until all elements of the array are sorted from least to greatest value
        for (int i = 0; i < size - j; i++) {
            (numLinesRun) +=3;
            if (arrayToSort[i] > arrayToSort[i + 1]) {
                tmp = arrayToSort[i];
                arrayToSort[i] = arrayToSort[i + 1];
                arrayToSort[i + 1] = tmp;
                swapped = true;
                (numLinesRun) +=4;
            }
            (numLinesRun) += 1;
        }
    }

}

int* copyArray(const int* arrayToCopy, const int size, int& numLinesRun){
    int* copyArray = new int[size];
    (numLinesRun) += 4;
    for (int i = 0;  i < size; i++){
        copyArray[i] = arrayToCopy[i];
        (numLinesRun) +=4;
    }
    return copyArray;
}





/**
 * uses binary search on an int array for a certain value
 * @pre the array must be sorted before this function is called
 * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
 * Non-tail recursion
 */
int binFind(const int* const arrayPtr, const int size, const int numToFind,int& numLinesRun) {
    (numLinesRun) +=4;
    int idx=0;
    int mid = ceil(size / 2);
    (numLinesRun) +=2;
    if (size == 0) {
        return -1;

    }
    if (arrayPtr[mid] == numToFind) {
        return mid;
    }
    else if(size%2 == 0){
        if(arrayPtr[mid] > numToFind){
            idx = binFind(arrayPtr,mid,numToFind,numLinesRun);
            (numLinesRun) += 4;
            if( idx == -1){
                return -1;
            }
            else{
                return idx;
            }
        }
        else{
            idx = binFind(arrayPtr+mid,mid,numToFind,numLinesRun);
            (numLinesRun) += 4;
            if(idx == -1){
                return -1;
            }
            else{
                return idx + mid;
            }
        }
    }
    else{
        if(arrayPtr[mid] > numToFind){
            idx = binFind(arrayPtr,mid,numToFind,numLinesRun);
            (numLinesRun) +=4;
            if(idx == -1){
                return -1;
            }
            else{
                return idx;
            }
        }
        else{
            idx = binFind(arrayPtr+mid+1,mid,numToFind,numLinesRun);
            (numLinesRun) +=4;
            if(idx == -1){
                return -1;
            }
            else{
                return idx+mid+1;
            }
        }
    }
}








