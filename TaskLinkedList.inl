//
// Created by Jeremy Block on 10/31/17.
// Revisions by Jeremy Block on 11/06/17
//

//todo: convert this To a templated version. It should be abstract and not related to tasks just because toby wants to see that we have mastery over abstraction.
//#include "TaskLinkedList.h"



//constructor
template <class T>
TaskLinkedList<T>::TaskLinkedList() {
    currLength = 0;
    front = nullptr;
    end = nullptr;
}

//copy constructor
template <class T>
TaskLinkedList<T>::TaskLinkedList(const TaskLinkedList &listToCopy) {
    currLength = listToCopy.currLength;
    if (listToCopy.front != nullptr) { // if the listToCopy is not empty
        Task *tempNewPtr; // the address of the penultimate-ly created node
        Task *tempOldPtr; // The address of the node to copied from the listToCopy
        Task *newNodePtr; // The newest node created based on the tempOldPtr->getItem.
        tempOldPtr = listToCopy.front;
        newNodePtr = new Task(tempOldPtr->getTitle(), tempOldPtr->getDueDate(), tempOldPtr->getComplete(),
                              tempOldPtr->getId());
        front = newNodePtr;
        tempNewPtr = front;

        for (int i = 1; i < currLength; i++) {
            tempOldPtr = tempOldPtr->getNext();
            newNodePtr = new Task(tempOldPtr->getTitle(), tempOldPtr->getDueDate(), tempOldPtr->getComplete(),
                                  tempOldPtr->getId());
            tempNewPtr->setNext(newNodePtr);
            tempNewPtr = tempNewPtr->getNext();
            end = newNodePtr;
        }
    }
}

/**
 * Iterative helper destructor that deletes the rest of the
 *               list from a pointer to the end of the list
 * @param oldNode - the node from which to delete the rest of the chain
 */
template <class T>
void RecursiveDelete(T *oldNode) {
    while (oldNode != nullptr) {
        T *temp = (*oldNode).getNext();
        delete oldNode;
        oldNode = temp;
    }
}

//destructor
//template <class T>
//TaskLinkedList<T>::~TaskLinkedList() {
//    currLength = 0;
//    RecursiveDelete(front);
//    front = nullptr;
//    end = nullptr;
//
//}

//Assignment operator
template <class T>
TaskLinkedList<T> &TaskLinkedList<T>::operator=(const TaskLinkedList &listToCopy) {
    if (this != &listToCopy) {
        currLength = 0;
        clearList();
        front = nullptr;
        end = nullptr;


        if (listToCopy.front != nullptr) {
            T *tempNewPtr; // the address of the penultimate-ly created node
            T* tempOldPtr; // The address of the node to copied from the listToCopy
            T* newNodePtr; // The newest node created based on the tempOldPtr->getItem.
            tempOldPtr = listToCopy.front;
            newNodePtr = new Task(tempOldPtr->getTitle(), tempOldPtr->getDueDate(), tempOldPtr->getComplete(),
                                  tempOldPtr->getId());
            front = newNodePtr;
            tempNewPtr = front;

            for (int i = 1; i < currLength; i++) {
                tempOldPtr = tempOldPtr->getNext();
                newNodePtr = new Task(tempOldPtr->getTitle(), tempOldPtr->getDueDate(), tempOldPtr->getComplete(),
                                      tempOldPtr->getId());
                tempNewPtr->setNext(newNodePtr);
                tempNewPtr = tempNewPtr->getNext();
                end = newNodePtr;
            }
        }
    }
    return *this;
}
template <class T>
void TaskLinkedList<T>::addToList(T *itemToAdd) {
    T *tempItem = itemToAdd;
    if (currLength == 0) {
        front = tempItem;
        end = tempItem;
    } else {
        end->setNext(tempItem);
        end = tempItem;
    }
    currLength++;
}
template <class T>
T *TaskLinkedList<T>::getValueAt(int index) {
    if (index < 0 || index >= currLength) {
        throw std::out_of_range("index not defined in List");
    } else if (index == 0) {
        return front;
    } else if (index == currLength - 1) {
        return end;
    } else {
        T *findNode = front->getNext();
        for (int i = 1; i < index; i++) {
            findNode = findNode->getNext();
        }
        return findNode;
    }
}
template <class T>
T *TaskLinkedList<T>::removeValueAt(int index) {
    //todo Should this be an Task ID here? or do we want an index?
    if (index < 0 || index >= currLength) { //if out of the range throw error
        throw std::out_of_range("Cannot remove a value outside of list");
    } else if (index == 0) { // if removing the first element
        T *prevPtr = front;
        T *tempReturn = prevPtr;
        front = front->getNext();
        currLength--;
        return tempReturn;
    } else { //if removing any other task
        T *prevPtr = front; //point to the one at the front
        for (int i = 0; i < index - 1; i++) { //move down the list till index
            prevPtr = prevPtr->getNext();
        } //delPtr now looks at the node before the passed index
        T *deleteNode = prevPtr->getNext();
        T *nextNode = deleteNode->getNext();
        //  [delPtr] [deleteNode] [nextNode]
        //           index^
        prevPtr->setNext(nextNode);
        currLength--;
        return deleteNode;
    }
}
template <class T>
bool TaskLinkedList<T>::isEmpty() {
    return currLength == 0;
}
template <class T>
int TaskLinkedList<T>::itemCount() {
    return currLength;
}
template <class T>
void TaskLinkedList<T>::clearList() {
    currLength = 0;
    RecursiveDelete(front);
    front = nullptr;
    end = nullptr;
}
template <class T>
std::string TaskLinkedList<T>::toString() {
    Task *tempPtr = end;
    std::string output = "{";
    for (int i = 0; i < currLength; i++) {
        if (i < currLength - 1) {
            output += (tempPtr->getTitle()) + ", ";
            tempPtr = tempPtr->getNext();
        } else {
            output += (tempPtr->getTitle());
        }
    }
    output += "}";
    return output;
}

template <class T>
T* TaskLinkedList<T>::getLast(){
    return end;
}

/**
 * Non-tail Recursive function for returning the index of the first occurence
 *                  of a specific number to look for
 * @param thisnode - the node to start searching on
 * @param lookForID  - the Value to look for
 * @return  - The first index of the lookForID passed in relation to the thisNode
 */
template <class T>
int findFirstHelper(T *thisnode, int lookForID) {
    if (thisnode->getId() == lookForID) {
        return 0;
    }
    if (thisnode->getNext() == nullptr) {
        return -1;
    } else {
        int temp = findFirstHelper(thisnode->getNext(), lookForID);
        if (temp == -1) {
            return -1;
        } else {
            return 1 + temp;
        }
    }
}
template <class T>
int TaskLinkedList<T>::find(int numToFind) {
    return findFirstHelper(front, numToFind);
}
template <class T>
int TaskLinkedList<T>::findLast(int numToFind) {
    T *aNode = front;
    int lastIndex = -1;
    for (int i = 0; i < currLength; i++) {
        if (aNode->getId() == numToFind) {
            lastIndex = i;
        }
        aNode = aNode->getNext();
    }
    return lastIndex;
}
