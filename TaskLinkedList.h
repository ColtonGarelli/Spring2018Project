//
// Created by Jeremy Block on 10/31/17.
// Revisions by Jeremy Block on 11/06/17
//

#ifndef PRO_JECT_TASKLINKEDLIST_H
#define PRO_JECT_TASKLINKEDLIST_H

#include <string>
#include "Task.h"
#include "List.h"

//todo: convert this to a linked List of Tasks not Integers
template <class T>
class TaskLinkedList : public List<T> {

private:
    int currLength;
    T* front;
    T* end;
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
    void addToList(T *itemToAdd);

    /**
     * gets a value from the list
     * @efficiency - O(n-1) if index is for penultimate item in list,
     *               but the first and last index are accessible in O(1)
     *               operations.
     * @param index the location from which to get the value
     * @returns a copy of the item at index
     * @throws out_of_range exception if index is invalid
     */
    T* getValueAt(int index);

    /**
     * removes the item at index from the list, and returns a copy of that item
     * @efficiency - O(n); Special Case when index is 0 then it's O(1)
     * @param index the location from which to get the value
     * @post the item at index is removed from the list, everything else is shifted down one
     * @returns a copy of the item at index
     * @throws out_of_range exception if index is invalid
     */
    T* removeValueAt(int index);

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
     * Searches an int array for a certain value
     * @efficiency - O(n) - if the first occurance of
     *                      numToFind is the last in list or is not present
     * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
     */
    int find(int numToFind);

    /**
     * Searches an int array for a certain value
     * @efficiency - O(n) - every time will be o(n)
     * @return the index of the last occurrence of numToFind if it is present, otherwise returns -1
     */
    int findLast(int numToFind);

    T* getFront();

};

#include "TaskLinkedList.inl"

#endif // PRO_JECT_TASKLINKEDLIST_H