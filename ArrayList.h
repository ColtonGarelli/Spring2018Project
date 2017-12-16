//
// Created by Toby Dragon on 9/30/16.
//

#ifndef COMP220_ARRAYLIST_H
#define COMP220_ARRAYLIST_H

#include <stdexcept>
#include <string>
#include "TaskList.h"
#include "ArrayLib.h"
#include "Task.h"


class ArrayList : public TaskList{
private:
    //pointer to the start of the array
    Task** array;
    //count of the number of valid items currently stored in the array
    int currItemCount;
    //size of the current array
    int currCapacity;

public:

    /**
     * replaces the old array with an array twice the size
     * private method only called within ArrayList when necessary
     * @post: array points to a new array of twice the size with values copied from the old one,
     *        the old array is deleted.
     */
    void doubleCapacity();

    /**
     * Constructor
     * creates an arrayList
     * @param: initialCapacity (the starting size of the array, defaults to size 5
     */

    ArrayList(TaskList* importList);

    ArrayList();

    //Copy Constructor
    ArrayList(const ArrayList& arrayListToCopy);

    //Overloaded Assignment Operator
    ArrayList& operator=(const ArrayList& arrayListToCopy);

    //Destructor
    ~ArrayList();
/**
 * adds Task to the list
 * @param taskToAdd - pointer to the Task to be added to the List
 * @post the List has an additional Task in it, Ordered by Priority (highest to lowest priority)
 **/
    void addToList(Task* taskToAdd);

    /**
     * Extends the end of the List to point at taskToAdd
     * @param taskToAdd - pointer to the Task to be added to the List
     * @post the list has an additional Task in it, at the end

     */
    void insertAtEnd(Task* taskToAdd);

    /**
     * Shifts all Tasks down the List and adds pointer to Task at front
     * @param taskToAdd - pointer to the Task to be added to the List
     * @post the list has an additional Task in it
     */
    void insertAtFront(Task* tasktoAdd);

    /**
     * adds Task to the list, at index specified
     * @param taskToAdd - pointer to the Task to be added to the List
     * @param index - the index in the List to add the task, everything after it gets shifted down
     * @post the list has an additional Task in it
     */
    void insertAt(Task* taskToAdd, int index);

//    /**
//      * Searches a List for a passed id, returns a pointer to the task with that Id
//      * @returns pointer to the first occurrence of a task with specified id if it is present, otherwise throws Bad_Task_Id error
//      */
//    virtual Task* findTaskById(int id)=0;
//
//    /**
//     * Searches an list for a certain id
//     * @returns pointer to the last occurrence of a task with specified id if it is present, otherwise throws Bad_Task_Id error
//     */
//    virtual Task* findLastTaskById(int id)=0;
//    //todo do we need a findLast or find function? probably good idea to have them just to beable to scan through the id's of the tasks in a list

    /**
     * returns the id of the first Task with the passed Priority
     * @param lookFor - the priority to look for
     * @return the id of the first Task in the list with the passed priority
     */
    int findFirstPriority(int lookFor);

    /**
     * returns the id of the last Task with the passed priority
     //TODO the controller should call this function more often with +1 priority when looking to add a Task.
     * @param lookFor - the priority to look for
     * @return the id of the last Task in the list with the passed priority.
     */
    int findLastPriority(int lookFor);

    //todo reverse order?, findFirstDate, findLastDate

    /**
     * gets a pointer to a Task in the list
     * @param index the index from which to get the value
     * @returns a pointer to the Task with the passed Id
     * @throws out_of_range exception if index is not in List
     */

    Task* getTaskByIndex(int index);

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
    Task* removeTaskById(int idToFind);

    /**
     * checks if there are any valid items in the list
     * @returns true if there are no valid items in the list, false otherwise
     */
    bool isEmpty();

    /**
     * returns a count of un-complete Tasks currently in the list
     * @returns the number of un-complete Tasks in the list
     */
    int itemCount();

    /**
     * removes and deletes all Tasks from the List
     * @post the List is completely clear of valid items and has values reset to defaults
     */
    void clearList();

    /**
     * gives a string representation of the title of each Task in the current list.
     * @returns a string representing the given list, broken by line in the format shown below
     * 1. Task_title1
     * 2. Task_title2
     * 3. Task_title3
     * ...
     */
    std::string toString();





};


#endif //COMP220_ARRAYLIST_H

