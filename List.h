//
// Created by Toby Dragon on 10/31/17.
//

#ifndef PRO_JECT_LIST_H
#define PRO_JECT_LIST_H

#include <stdexcept>


template <class T>
class List{
public:
    //Destructor
//    virtual ~List()=0;

    /**
     * appends the new item to the end of the list
     * @param itemToAdd the item to add to the end of the array
     * @post the list has an additional value in it, at the end
     */
    virtual void addToList(T* itemToAdd)=0;

    /**
     * gets a value from the list
     * @param index the location from which to get the value
     * @returns a copy of the item at index
     * @throws out_of_range exception if index is invalid
     */

//    virtual T* getValueAt(T index)=0;


    /**
     * removes the item at index from the list, and returns a copy of that item
     * @param index the location from which to get the value
     * @post the item at index is removed from the list, everything else is shifted down one
     * @returns a copy of the item at index
     * @throws out_of_range exception if index is invalid
     */

//    virtual T* removeValueAt(T index)=0;
    
    /**
     * checks if there are any valid items in the list
     * @returns true if there are no valid items in the list, false otherwise
     */
    virtual bool isEmpty()=0;

    /**
     * returns a count of valid items currently in the list
     * @returns the number of valid items in the list
     */
    virtual int itemCount()=0;

    /**
     * removes all valid items from the list
     * @post the list is completely clear of valid items
     */
    virtual void clearList()=0;

    /**
     * gives a string representation of the titled from the current list.
     * @returns a string representing the given list in the exact format shown below
     * {1, 2, 3, 4, 5}
     */
    virtual std::string toString()=0;

    /**
     * Searches an list for a certain id
     * @return the index of the first occurrence of the matching task id if it is present, otherwise returns -1
     */
//    virtual int find(int id)=0;

    /**
     * Searches an list for a certain id
     * @return the index of the last occurrence of numToFind if it is present, otherwise returns -1
     */

//    virtual int findLast(T numToFind)=0;

    //todo do we need a findLast or find function? probably good idea to have them just to beable to scan through the id's of the tasks in a list
};


#endif //PRO_JECT_LIST_H
