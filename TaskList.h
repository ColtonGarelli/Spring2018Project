//
// Created by Toby Dragon on 10/31/17.
//

#ifndef PRO_JECT_LIST_H
#define PRO_JECT_LIST_H

#include <stdexcept>
//#include "ArrayList.h"
#include "TaskLinkedList.h"

class Bad_Task_Id : std::exception{};


class TaskList{
public:
    //Destructor
//    virtual ~TaskList()=0;

    /**
     * adds Task to the list
     * @param taskToAdd - pointer to the Task to be added to the List
     * @post the List has an additional Task in it, Ordered by Priority (highest to lowest priority)
     */
    virtual void addToList(Task* taskToAdd)=0;

    /**
     * Extends the end of the List to point at taskToAdd
     * @param taskToAdd - pointer to the Task to be added to the List
     * @post the list has an additional Task in it, at the end

     */
    virtual void insertAtEnd(Task* taskToAdd)=0;

    /**
     * Shifts all Tasks down the List and adds pointer to Task at front
     * @param taskToAdd - pointer to the Task to be added to the List
     * @post the list has an additional Task in it
     */
    virtual void insertAtFront(Task* tasktoAdd)=0;

    /**
     * adds Task to the list, at index specified
     * @param taskToAdd - pointer to the Task to be added to the List
     * @param index - the index in the List to add the task, everything after it gets shifted down
     * @post the list has an additional Task in it
     */
    virtual void insertAt(Task* taskToAdd, int index)=0;

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
    virtual int findFirstPriority(int lookFor)=0;

    /**
     * returns the id of the last Task with the passed priority
     //TODO the controller should call this function more often with +1 priority when looking to add a Task.
     * @param lookFor - the priority to look for
     * @return the id of the last Task in the list with the passed priority.
     */
    virtual int findLastPriority(int lookFor)=0;

    //todo reverse order?, findFirstDate, findLastDate

    /**
     * gets a pointer to a Task in the list
     * @param index the index from which to get the value
     * @returns a pointer to the Task with the passed Id
     * @throws out_of_range exception if index is not in List
     */

    virtual Task* getTaskByIndex(int index)=0;

//    /**
//     * returns an arrayList of pointers to tasks, organized by highest priority, within the number of days remaining
//     * @param masterList - A Linked node structure with pointers to Tasks to be searched through
//     * @param daysRemaining - the number of days till the Task is due. if a Task is <= the daysRemaining it will be added to the retruned ArrayList
//     * @return A pointer to an ArrayList of pointers to Tasks, if no tasks are due in daysRemaining range, Arraylist will be empty.
//     */
//    virtual ArrayList* buildView(TaskLinkedList* masterList, int daysRemaining)=0;


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
    virtual Task* removeTaskById(int idToFind)=0;
    
    /**
     * checks if there are any valid items in the list
     * @returns true if there are no valid items in the list, false otherwise
     */
    virtual bool isEmpty()=0;

    /**
     * returns a count of un-complete Tasks currently in the list
     * @returns the number of un-complete Tasks in the list
     */
    virtual int itemCount()=0;

    /**
     * removes and deletes all Tasks from the List
     * @post the List is completely clear of valid items and has values reset to defaults
     */
    virtual void clearList()=0;

    /**
     * gives a string representation of the title of each Task in the current list.
     * @returns a string representing the given list, broken by line in the format shown below
     * 1. Task_title1
     * 2. Task_title2
     * 3. Task_title3
     * ...
     */
    virtual std::string toString()=0;

};


#endif //PRO_JECT_LIST_H
