//
// Created by Jeremy Block on 10/31/17.
// Revisions by Jeremy Block on 11/06/17
//

//todo: convert this To a templated version. It should be abstract and not related to tasks just because toby wants to see that we have mastery over abstraction.
#include "TaskLinkedList.h"


//constructor
TaskLinkedList::TaskLinkedList() {
    currLength = 0;
    front = nullptr;
    end = nullptr;
}

//copy constructor
TaskLinkedList::TaskLinkedList(const TaskLinkedList &listToCopy) {
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
void RecursiveDelete(Task *oldNode) {
    while (oldNode != nullptr) {
        Task *temp = (*oldNode).getNext();
        delete oldNode;
        oldNode = temp;
    }
}

//destructor
TaskLinkedList::~TaskLinkedList() {
    currLength = 0;
    RecursiveDelete(front);
    front = nullptr;
    end = nullptr;

}

//Assignment operator
TaskLinkedList &TaskLinkedList::operator=(const TaskLinkedList &listToCopy) {
    if (this != &listToCopy) {
        currLength = 0;
        clearList();
        front = nullptr;
        end = nullptr;


        if (listToCopy.front != nullptr) {
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
    return *this;
}

void TaskLinkedList::addToList(Task *itemToAdd) {
    Task *tempItem = itemToAdd;
    if (currLength == 0) {
        front = tempItem;
        end = tempItem;
    } else {
        end->setNext(tempItem);
        end = tempItem;
    }
    currLength++;
}

Task *TaskLinkedList::getValueAt(int index) {
    if (index < 0 || index >= currLength) {
        throw std::out_of_range("index not defined in List");
    } else if (index == 0) {
        return front;
    } else if (index == currLength - 1) {
        return end;
    } else {
        Task *findNode = front->getNext();
        for (int i = 1; i < index; i++) {
            findNode = findNode->getNext();
        }
        return findNode;
    }
}

Task *TaskLinkedList::removeValueAt(int index) {
    //todo Should this be an Task ID here? or do we want an index?
    if (index < 0 || index >= currLength) { //if out of the range throw error
        throw std::out_of_range("Cannot remove a value outside of list");
    } else if (index == 0) { // if removing the first element
        Task *prevPtr = front;
        Task *tempReturn = prevPtr;
        front = front->getNext();
        currLength--;
        return tempReturn;
    } else { //if removing any other task
        Task *prevPtr = front; //point to the one at the front
        for (int i = 0; i < index - 1; i++) { //move down the list till index
            prevPtr = prevPtr->getNext();
        } //delPtr now looks at the node before the passed index
        Task *deleteNode = prevPtr->getNext();
        Task *nextNode = deleteNode->getNext();
        //  [delPtr] [deleteNode] [nextNode]
        //           index^
        prevPtr->setNext(nextNode);
        currLength--;
        return deleteNode;
    }
}

bool TaskLinkedList::isEmpty() {
    return currLength == 0;
}

int TaskLinkedList::itemCount() {
    return currLength;
}

void TaskLinkedList::clearList() {
    currLength = 0;
    RecursiveDelete(front);
    front = nullptr;
    end = nullptr;
}

std::string TaskLinkedList::toString() {
    Task *tempPtr = front;
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

/**
 * Non-tail Recursive function for returning the index of the first occurence
 *                  of a specific number to look for
 * @param thisnode - the node to start searching on
 * @param lookForID  - the Value to look for
 * @return  - The first index of the lookForID passed in relation to the thisNode
 */
int findFirstHelper(Task *thisnode, int lookForID) {
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

int TaskLinkedList::find(int numToFind) {
    return findFirstHelper(front, numToFind);
}

int TaskLinkedList::findLast(int numToFind) {
    Task *aNode = front;
    int lastIndex = -1;
    for (int i = 0; i < currLength; i++) {
        if (aNode->getId() == numToFind) {
            lastIndex = i;
        }
        aNode = aNode->getNext();
    }
    return lastIndex;
}
