
#include <stdexcept>
#include <string>
#include <iostream>
#include "ArrayList.h"
#include<sstream>


/**
 * Constructor
 * creates an arrayList
 * @param: initialCapacity (the starting size of the array, defaults to size 5
 */

ArrayList::ArrayList(){
    currCapacity=2;
    currItemCount=0;
    array= new Task*[currCapacity];
}

ArrayList::ArrayList(TaskList* importList){
    //this->currCapacity=importList->itemCount();
    currCapacity=importList->itemCount();
    array=new Task*[currCapacity];
    currItemCount=0;
    for(int i=0; i< sizeof(array);i++){
        if(importList->itemCount()>i) {
            array[i] = importList->getTaskByIndex(i);
            this->currItemCount++;
        }else{
            array[i]= nullptr;
        }
    }
        //write to create arraylist upon import
}

////Copy Constructor
ArrayList::ArrayList(const ArrayList& arrayListToCopy){
    currItemCount = arrayListToCopy.currItemCount;
    currCapacity = arrayListToCopy.currCapacity;
    array = new Task*[currCapacity];
    for(int i = 0; i < currItemCount; i++){
        array[i] = arrayListToCopy.array[i];
    }
}

////Overloaded Assignment Operator
ArrayList& ArrayList::operator=(const ArrayList& arrayListToCopy){
    if( this != &arrayListToCopy){
        delete[] array;
        array= nullptr;
        currCapacity = arrayListToCopy.currCapacity;
        currItemCount = arrayListToCopy.currItemCount;
        for(int i = 0; i < currItemCount; i++){
            array[i] = arrayListToCopy.array[i];
        }
    }
    return *this;
}


//Destructor
ArrayList::~ArrayList() {
    currCapacity = 2;
    //Arraylist is not responsible for it's memory, but still deleting just in case
    delete[] array;
    currItemCount = 0;
}


/**
 * replaces the old array with an array twice the size
 * private method only called within ArrayList when necessary
 * @post: array points to a new array of twice the size with values copied from the old one,
 *        the old array is deleted.
 **/
void ArrayList::doubleCapacity() {
    //tested and Working!
    int doubCap = (currCapacity * 2);
    Task** tempArray=new Task*[doubCap];
    for (int i = 0; i < currCapacity; i++) {
        tempArray[i]=array[i];
    }
    currCapacity = doubCap;
    delete[] array;
    array = tempArray;
    tempArray = nullptr;

}


/**
* adds Task to the list
* @param taskToAdd - pointer to the Task to be added to the List
* @post the List has an additional Task in it
*/
void ArrayList::addToList(Task* taskToAdd){
        insertAtEnd(taskToAdd);
}

/**
 * Extends the end of the List to point at taskToAdd
 * @param taskToAdd - pointer to the Task to be added to the List
 * @post the list has an additional Task in it, at the end

 */
void ArrayList::insertAtEnd(Task* taskToAdd){
    if(currItemCount < currCapacity){
        if(currItemCount==0) {
            array[0]=taskToAdd;
            currItemCount++;
        }
        else{
            array[currItemCount] = taskToAdd;
            currItemCount++;
        }
    }
    else{
        this->doubleCapacity();
        array[currItemCount] = taskToAdd;
        currItemCount++;
    }
}

/**
 * Shifts all Tasks down the List and adds pointer to Task at front
 * @param taskToAdd - pointer to the Task to be added to the List
 * @post the list has an additional Task in it
 **/
 void ArrayList::insertAtFront(Task* tasktoAdd){
    if(currItemCount == currCapacity){
        this->doubleCapacity();
    }
    for (int i = currItemCount; i >0; i--){
        array[i] = array[i-1];
    }
    array[0] = tasktoAdd;
}

/**
 * adds Task to the list, at index specified
 * @param taskToAdd - pointer to the Task to be added to the List
 * @param index - the index in the List to add the task, everything after it gets shifted down
 * @post the list has an additional Task in it
 */
 void ArrayList::insertAt(Task* taskToAdd, int index){
    if(index < 0 ){
        throw std::out_of_range("<Error:index not in range>");
    }
    else if (index > currItemCount){
        throw std::out_of_range("<Error:index not in range>");
    }
    else{
        for(int i = currItemCount; i > index; i--){
            array[i] = array[i - 1];
        }
        array[index] = taskToAdd;
        currItemCount++;
    }
}

/**
 * returns the id of the first Task with the passed Priority
 * @param lookFor - the priority to look for
 * @return the id of the first Task in the list with the passed priority
 */
int ArrayList::findFirstPriority(int lookFor){
    for(int i = 0; i < currItemCount; i++){
        if(array[i]->getPriority() == lookFor){
            return array[i]->getId();
        }
    }
    return -1;
}

/**
 * returns the id of the last Task with the passed priority
 * @param lookFor - the priority to look for
 * @return the id of the last Task in the list with the passed priority.
 */
 int ArrayList::findLastPriority(int lookFor){
    for(int i = currItemCount; i>-1; i--) {
        if (array[i]->getPriority() == lookFor) {
            return array[i]->getId();
        }
    }
    return -1;
}


/**
 * gets a pointer to a Task in the list
 * @param index the index from which to get the value
 * @returns a pointer to the Task with the passed Id
 * @throws out_of_range exception if index is not in List
 */

 Task* ArrayList::getTaskByIndex(int index){
    if(index < 0 ){
        throw std::out_of_range("<index not in range>");
    }
    else if(index > currItemCount){
        throw std::out_of_range("index not in range");
    }
    else{
        return array[index];
    }
}



/**
 * removes the Task from the List
 * @param id of the task to remove from the List
 * @post the Task with id is removed from the list,
 *      everything else is shifted down one,
 *      whoever catches task needs to delete task.
 *      Task is set to complete.
 * @returns the only pointer to the item at index
 * @throws out_of_range exception if id is not in List
 */
 Task* ArrayList::removeTaskById(int idToFind){
    if(currItemCount == 0){
        return nullptr;
    }
    if(idToFind < 0){
        throw std::out_of_range("<id not in range>");
    }
    else{
        for(int i = 0; i<currItemCount; i++){
            if(array[i]->getId() == idToFind){
                int returnVal = array[i]->getId();
                Task* returnTask = array[i];
                for(int i=i;i<currItemCount;i++){
                    if(i==currItemCount-1){
                        array[i]= nullptr;
                    }
                    else{
                        array[i] = array[i+1];
                    }
                }
                return returnTask;
            }

            currItemCount--;
        }
        return nullptr;
    }

}

/**
 * checks if there are any valid items in the list
 * @returns true if there are no valid items in the list, false otherwise
 */
 bool ArrayList::isEmpty(){
    if(currItemCount == 0){
        return true;
    }else{
        return false;
    }
}

/**
 * returns a count of un-complete Tasks currently in the list
 * @returns the number of un-complete Tasks in the list
 */
 int ArrayList::itemCount(){
    return currItemCount;
}

/**
 * removes and deletes all Tasks from the List
 * @post the List is completely clear of valid items and has values reset to defaults
 */
 void ArrayList::clearList(){
    for(int i = 0; i < currItemCount;i++){
        array[i] = 0;
    }
    currItemCount = 0;
}

/**
 * gives a string representation of the title of each Task in the current list.
 * @returns a string representing the given list, broken by line in the format shown below
 * 1. Task_title1
 * 2. Task_title2
 * 3. Task_title3
 * ...
 */
std::string ArrayList::toString() {

    std::string printable = "To Do:\n\n";
    for(int i = 0; i < currItemCount; i++){
        printable += std::to_string(i + 1) + ". " + array[i]->getTitle() + "\n";
        printable += "Due Date: "+std::to_string(array[i]->getDueDate()) + "\n";
        printable += "Priority: "+std::to_string(array[i]->getPriority()) + "\n";
        if(!array[i]->getComplete()){
            printable += "Complete: No \n\n";
        }
        else{
            printable+="Complete: Yes \n\n";
        }

    }
    return printable;
}

/**
 * gets a value from the list
 * @param index the location from which to get the value
 * @returns a copy of the item at index
 * @throws out_of_range exception if index is invalid
 */
Task* ArrayList::getValueAt(int index) {
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
Task* ArrayList::removeValueAt(int index) {
    if (index < 0) {
        throw std::out_of_range("<index not in range>");
    } else if (index > currItemCount) {
        throw std::out_of_range("<index not in range>");
    }
    Task* in = array[index];
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
