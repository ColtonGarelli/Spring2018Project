//
// Created by Jeremy Block on 10/31/17.
// Revisions by Jeremy Block on 11/06/17
//

#ifndef PRO_JECT_TASKLINKEDLIST_H
#define PRO_JECT_TASKLINKEDLIST_H

#include <string>
#include "Task.h"
#include "TaskList.h"
#include "LinkedNode.h"

//todo Update the Efficiency
class TaskLinkedList : public TaskList {

private:
    int currLength;
    LinkedNode* front;
    LinkedNode* end;
    LinkedNode* returnNodeWhere(int property, int equals);
    LinkedNode* extractNodeAfter(LinkedNode *here);

        public:
    /**
     * @efficiency - O(1)
     * Default constructor
     */
    TaskLinkedList();

    /**
     * @efficiency - O(n)
     * Copy constructor
     */
    TaskLinkedList(const TaskLinkedList& listToCopy);

    /**
     * @efficiency - O(n)
     * @post - Tasks are deleted when the LinkedNodes are deleted
     * Destructor
     */
    ~TaskLinkedList();

    /**
     * @efficiency - O(2n)
     * Assignment operator
     */
    TaskLinkedList& operator=(const TaskLinkedList& listToCopy);

    /**
     * appends the new item to the end of the list
     * @efficiency - O(1)
     * @param itemToAdd the item to add to the end of the array
     * @post the list has an additional value in it, at the end
     */
    void addToList(Task* itemToAdd);

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
    void insertAtFront(Task* taskToAdd);

    /**
     * adds Task to the list, at index specified
     * @param taskToAdd - pointer to the Task to be added to the List
     * @param index - the index in the List to add the task, everything after it gets shifted down
     * @post the list has an additional Task in it
     */
    void insertAt(Task* taskToAdd, int index);

    /**
     * returns the id of the first Task with the passed Priority
     * @efficiency - O(n)
     * @param lookFor - the priority to look for
     * @return the id of the first Task in the list with the passed priority
     */
    int findFirstPriority(int lookFor);

    /**
     * returns the id of the last Task with the passed priority
     * @efficiency - O(n)
     * @param lookFor - the priority to look for
     * @return the id of the last Task in the list with the passed priority.
     */
    int findLastPriority(int lookFor);

    /**
     * gets a value from the list
     * @efficiency - O(n-1) if index is for penultimate item in list,
     *               but the first and last index are accessible in O(1)
     *               operations.
     * @param index the location from which to get the value
     * @returns a copy of the item at index
     * @throws out_of_range exception if index is invalid
     */
    Task* getTaskByIndex(int index);

    /**
     * returns an arrayList of pointers to tasks, organized by highest priority, within the number of days remaining
     * @param masterList - A Linked node structure with pointers to Tasks to be searched through
     * @param daysRemaining - the number of days till the Task is due. if a Task is <= the daysRemaining it will be added to the retruned ArrayList
     * @return A pointer to an ArrayList of pointers to Tasks, if no tasks are due in daysRemaining range, Arraylist will be empty.
     */
    ArrayList* buildView(TaskLinkedList* masterList, int daysRemaining);

    /**
     * removes the item at index from the list, and returns a copy of that item
     * @efficiency - O(n); Special Case when index is 0 then it's O(1)
     * @param index the location from which to get the value
     * @post the item at index is removed from the list, everything else is shifted down one
     * @returns a copy of the item at index
     * @throws out_of_range exception if index is invalid
     */
    Task* removeTaskById(int idToFind);

    /**
     * checks if there are any valid items in the list
     * @efficiency - O(1)
     * @returns true if there are no valid items in the list, false otherwise
     */
    bool isEmpty();

    /**
     * returns a count of valid items currently in the list
     * @efficiency - O(1)
     * @returns the number of valid items in the list
     */
    int itemCount();

    /**
     * removes all valid items from the list
     * @efficiency - O(n)
     * @post the list is completely clear of valid items
     */
    void clearList();

    /**
     * gives a string representation of the current list
     * @efficiency - O(n)
     * @returns a string representing the given list in the exact format shown below
     * {1, 2, 3, 4, 5}
     */
    std::string toString();

    /**
     * takes the Linked Structure and puts it in order (highest to lowest) priority
     */
    //TODO SHOULD WE ADD SOME SORTING FUNCTIONS TO TASKLIST???;
//    void reorderByPriority();

};

#endif // PRO_JECT_TASKLINKEDLIST_H