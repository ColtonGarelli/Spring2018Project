//
// Created by Taylor Yowan on 10/10/17.
//
#include <stdexcept>
#include <string>
#include <iostream>
#include "ArrayList.h"
#include "ArrayLib.h"

/**
 * replaces the old array with an array twice the size
 * private method only called within ArrayList when necessary
 * @post: array points to a new array of twice the size with values copied from the old one,
 *        the old array is deleted.
 */
void ArrayList::doubleCapacity(){
    int doubCap = (currCapacity * 2);
    currCapacity = doubCap;
    int timer = 0;
    int* tempArray = copyArray(array, doubCap);
    delete[] array;
    array = tempArray;
    tempArray = nullptr;
}


/**
 * Constructor
 * creates an arrayList
 * @param: initialCapacity (the starting size of the array, defaults to size 5
 */
ArrayList::ArrayList(int initialCapacity){
    this -> currCapacity = initialCapacity;
    array = new int[currCapacity];
    currItemCount = 0;
}

//Copy Constructor
ArrayList::ArrayList(const ArrayList& arrayListToCopy){
    currItemCount = arrayListToCopy.currItemCount;
    currCapacity = arrayListToCopy.currCapacity;
    array = new int[currCapacity];
    for(int i = 0; i < currItemCount; i ++ ){
        array[i] = arrayListToCopy.array[i];
    }
}

//Overloaded Assignment Operator
ArrayList& ArrayList::operator=(const ArrayList& arrayListToCopy){
    if(this != &arrayListToCopy){
        delete[] array;
    }
    currCapacity = arrayListToCopy.currCapacity;
    currItemCount = arrayListToCopy.currItemCount;
    for(int i = 0; i < currItemCount; i++){
        array[i] = arrayListToCopy.array[i];
    }
    return *this;
}

//Destructor
ArrayList::~ArrayList(){
    delete[] array;
}

/**
 * appends the new item to the end of the list
 * @param itemToAdd the item to add to the end of the array
 * @post the list has an additional value in it, at the end
 */
void ArrayList::insertAtEnd(int itemToAdd) {
    if (currItemCount < currCapacity) {
        array[currItemCount] = itemToAdd;
    } else {
        doubleCapacity();
        array[currItemCount] = itemToAdd;
    }
    currItemCount++;
}

/**
 * appends the new item to the beginning of the list
 * @param itemToAdd the item to add to the beginning of the list
 * @post the list has an additional value in it, at the beginning
 *    all other items are shifted down by one index
 */
void ArrayList::insertAtFront(int itemToAdd){
    if(currItemCount == currCapacity){
        this -> doubleCapacity();
        std::cout <<"the current capacity is" << std::endl;
        std::cout << currCapacity << std::endl;
    }
    for(int i = currItemCount; i > 0; i--){
        array[i] = array[i-1];
    }
    array[0] = itemToAdd;
    currItemCount++;
}

/**
 * inserts the item into the list so that it can be found with get(index)
 * @param itemToAdd the item to add
 * @param index the location in which to insert this item
 * @post the list has an additional value in it at the specified index,
 *        all further values have been shifted down by one index
 * @throws out_of_range exception if index is invalid (< 0 or >currItemCount)
 */
void ArrayList::insertAt(int itemToAdd, int index){
    if(index < 0){
        throw std::out_of_range("<Error:index not in range>");
    }
    else if(index > currItemCount){
        throw std::out_of_range("<Error: index not in range>");
    }
    else{
        for(int i = currItemCount; i > index; i--){
            array[i] = array[i-1];
        }
        array[index] = itemToAdd;
        currItemCount++;
    }
}



/**
 * gets a value from the list
 * @param index the location from which to get the value
 * @returns a copy of the item at index
 * @throws out_of_range exception if index is invalid
 */
int ArrayList::getValueAt(int index){
    if(index < 0){
        throw std::out_of_range("<index not in range>");
    }
    else if(index > currItemCount){
        throw std::out_of_range("<index not in range>");
    }
    else{
        return array[index];
    }
}

/**
 * removes the item at index from the list, and returns a copy of that item
 * @param index the location from which to get the value
 * @post the item at index is removed from the list, everything else is shifted down one
 * @returns a copy of the item at index
 * @throws out_of_range exception if index is invalid
 */
int ArrayList::removeValueAt(int index){
    if(index < 0){
        throw std::out_of_range("<index not in range>");
    }
    else if(index > currItemCount){
        throw std::out_of_range("<index not in range>");
    }
    int in = array[index];
    if(index <= currItemCount){
        if(currItemCount <= currCapacity){
            for(int i = index; i < currItemCount; i++){
                array[i] = array[i+1];
            }
            currItemCount--;
        }
    }
    return in;
}

/**
 * checks if there are any valid items in the list
 * @returns true if there are no valid items in the list, false otherwise
 */
bool ArrayList::isEmpty(){
    if(currItemCount == 0){
        return true;
    }
    else{
        return false;
    }
}

/**
 * returns a count of valid items currently in the list
 * @returns the number of valid items in the list
 */
int ArrayList::itemCount(){
    return currItemCount;
}

/**
 * removes all valid items from the list
 * @post the list is completely clear of valid items
 */
void ArrayList::clearList(){
    for(int i = 0; i < currItemCount; i++){
        array[i] = 0;
    }
    currItemCount = 0;
}

/**
 * gives a string representation of the current list
 * @returns a string representing the given list in the exact format shown below
 * {1, 2, 3, 4, 5}
 */
std::string ArrayList::toString(){
    return ::toString(array, currItemCount);
}

/**
 * finds the largest value in the array
 * @post numLinesRun is updated to include lines run by this function
 * @return the first index of the maximum value, or -1 if size < 1
 */
//int ArrayList::findMaxIndex(){
//    int timer = 0;
//    return :: findMaxIndex(array,currItemCount,timer);
//}

/**
 * Searches an int array for a certain value
 * @post numLinesRun is updated to include lines run by this function
 * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
 */
//int ArrayList::find(int numToFind){
//    int timer = 0;
//    return:: find(array,currItemCount, numToFind,timer);
//}

/**
 * Searches an int array for a certain value
 * @post numLinesRun is updated to include lines run by this function
 * @return the index of the last occurrence of numToFind if it is present, otherwise returns -1
 */
//int ArrayList::findLast(int numToFind){
//    int timer = 0;
//    return:: findLast(array,currItemCount,numToFind,timer);
//}
