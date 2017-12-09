//
// Created by Taylor Yowan on 10/10/17.
//
#include <stdexcept>
#include <string>
#include <iostream>
#include "ArrayList.h"
#include "TaskList.h"
#include "ArrayLib.h"

/**
 * Constructor
 * creates an arrayList
 * @param: initialCapacity (the starting size of the array, defaults to size 5
 */

ArrayList::ArrayList(int initialCapacity) {
    this->currCapacity = initialCapacity;
    array = new int[currCapacity];
    currItemCount = 0;
}


/**
 * replaces the old array with an array twice the size
 * private method only called within ArrayList when necessary
 * @post: array points to a new array of twice the size with values copied from the old one,
 *        the old array is deleted.
 */

void ArrayList::doubleCapacity() {
    int doubCap = (currCapacity * 2);
    currCapacity = doubCap;
    int timer = 0;
    int *tempArray = copyArray(array, doubCap);
    delete[] array;
    array = tempArray;
    tempArray = nullptr;
}


//Copy Constructor

ArrayList::ArrayList(const ArrayList& ListToCopy) {
    currItemCount = ListToCopy.currItemCount;
    currCapacity = ListToCopy.currCapacity;
    array = new int[currCapacity];
    for (int i = 0; i < currItemCount; i++) {
        array[i] = ListToCopy.array[i];
    }
}

//Overloaded Assignment Operator
ArrayList &ArrayList::operator=(const ArrayList &arrayListToCopy) {
    if (this != &arrayListToCopy) {
        delete[] array;
    }
    currCapacity = arrayListToCopy.currCapacity;
    currItemCount = arrayListToCopy.currItemCount;
    for (int i = 0; i < currItemCount; i++) {
        array[i] = arrayListToCopy.array[i];
    }
    return *this;
}

//Destructor
ArrayList::~ArrayList() {
    delete[] array;
}

/**
 * appends the new item to the end of the list
 * @param itemToAdd the item to add to the end of the array
 * @post the list has an additional value in it, at the end
 */

void ArrayList::addToList(Task* taskToAdd) {
    if (currItemCount < currCapacity) {
        Task* &arrayList[currItemCount];
        arrayList[currItemCount] = taskToAdd;
    } else {
        doubleCapacity();
        Task* &arrayList[currItemCount];
        arrayList[currItemCount] = taskToAdd;
    }
    currItemCount++;
}


/**
 * gets a value from the list
 * @param index the location from which to get the value
 * @returns a copy of the item at index
 * @throws out_of_range exception if index is invalid
 */
int ArrayList::getValueAt(int index) {
    if (index < 0) {
        throw std::out_of_range("<index not in range>");
    } else if (index > currItemCount) {
        throw std::out_of_range("<index not in range>");
    } else {
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

int ArrayList::removeValueAt(int index) {
    if (index < 0) {
        throw std::out_of_range("<index not in range>");
    } else if (index > currItemCount) {
        throw std::out_of_range("<index not in range>");
    }
    int in = array[index];
    if (index <= currItemCount) {
        if (currItemCount <= currCapacity) {
            for (int i = index; i < currItemCount; i++) {
                array[i] = array[i + 1];
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

bool ArrayList::isEmpty() {
    if (currItemCount == 0) {
        return true;
    } else {
        return false;
    }
}

/**
 * returns a count of valid items currently in the list
 * @returns the number of valid items in the list
 */

int ArrayList::itemCount() {
    return currItemCount;
}

/**
 * removes all valid items from the list
 * @post the list is completely clear of valid items
 */

void ArrayList::clearList() {
    for (int i = 0; i < currItemCount; i++) {
        array[i] = 0;
    }
    currItemCount = 0;
}

/**
 * gives a string representation of the current list
 * @returns a string representing the given list in the exact format shown below
 * {1, 2, 3, 4, 5}
 */
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

//std::string ArrayList::toString() {
//    return toString(array, currItemCount);
//}

/*
 * Searches an int array for a certain value
 * @post numLinesRun is updated to include lines run by this function
 * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
 */

//int ArrayList::find(int id) {
//    int timer = 0;
//    return find(array, currItemCount, id, timer);
//}
int find(const int* arrayPtr, int size, int id) {
    //(numLinesRun) += 4;
    for (int i = 0; i < size; i++) {
        //(numLinesRun) +=3;
        if (arrayPtr[i] == id) {
            return i;
        }
        // (numLinesRun) +=1;
    }
    return -1;
}


/**
 * Searches an int array for a certain value
 * @post numLinesRun is updated to include lines run by this function
 * @return the index of the last occurrence of numToFind if it is present, otherwise returns -1
 */

//int ArrayList::findLast(int numToFind) {
//    int timer = 0;
//    return findLast(array, currItemCount, numToFind, timer);
//}


/**
 * returns an arrayList of pointers to tasks, organized by highest priority, within the number of days remaining
 * @param masterList - A Linked node structure with pointers to Tasks to be searched through
 * @param daysRemaining - the number of days till the Task is due. if a Task is <= the daysRemaining it will be added to the retruned ArrayList
 * @return A pointer to an ArrayList of pointers to Tasks, if no tasks are due in daysRemaining range, Arraylist will be empty.
 */
ArrayList *ArrayList::buildView(TaskLinkedList *masterList, int daysRemaining) {
    TaskLinkedList *current = masterList->getFront();
    int currCapacity = masterList->itemCount();
    array = new int[currCapacity];
    //int i = 0;
    if (current == nullptr) {
        return this*;
    } else {
        Task *currTask = current->getFront();
        for (int i = 0; i < currCapacity; i++) {
            if (currTask->getDueDate() <= daysRemaining) {
                array[i] = currTask->getId();
                current = current->getNext; //should I be calling something else, does TaskLinkedList need a get next??
            }
        }
        //TODO sort by priority
    }
}
///currItemCount = ListToCopy.currItemCount;
//currCapacity = ListToCopy.currCapacity;
//array = new int[currCapacity];
//for (int i = 0; i < currItemCount; i++) {
//array[i] = ListToCopy.array[i];
//}
//}