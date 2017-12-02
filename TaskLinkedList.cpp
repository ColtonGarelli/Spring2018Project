//
// Created by Jeremy Block on 10/31/17.
// Revisions by Jeremy Block on 11/06/17
//

//todo: convert this to Linked List of tasks
#include "TaskLinkedList.h"

    //constructor
    TaskLinkedList::TaskLinkedList() {
        currLength = 0;
        front = nullptr;
        end = nullptr;
    }
    //copy constructor
    TaskLinkedList::TaskLinkedList(const TaskLinkedList& listToCopy){
        currLength = listToCopy.currLength;
        if(listToCopy.front != nullptr){ // if the listToCopy is not empty
            Task* tempNewPtr; // the address of the penultimate-ly created node
            Task* tempOldPtr; // The address of the node to copied from the listToCopy
            Task* newNodePtr; // The newest node created based on the tempOldPtr->getItem.
            tempOldPtr = listToCopy.front;
            newNodePtr = new Task(tempOldPtr->getItem());
            front = newNodePtr;
            tempNewPtr = front;

            for (int i = 1; i < currLength; i++){
                tempOldPtr = tempOldPtr->getNext();
                newNodePtr = new Task(tempOldPtr->getItem());
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
    void RecursiveDelete (Task* oldNode) {
        while (oldNode != nullptr) {
            Task* temp = (*oldNode).getNext();
            delete oldNode;
            oldNode = temp;
        }
    }

    //destructor
    TaskLinkedList::~TaskLinkedList(){
        currLength=0;
        RecursiveDelete(front);
        front = nullptr;
        end = nullptr;

    }

    //Assignment operator
    TaskLinkedList& TaskLinkedList::operator=(const TaskLinkedList& listToCopy) {
        if(this != &listToCopy) {
            currLength=0;
            clearList();
            front = nullptr;
            end = nullptr;


            if (listToCopy.front != nullptr) {
                Task *tempNewPtr; // the address of the penultimate-ly created node
                Task *tempOldPtr; // The address of the node to copied from the listToCopy
                Task *newNodePtr; // The newest node created based on the tempOldPtr->getItem.
                tempOldPtr = listToCopy.front;
                newNodePtr = new Task(tempOldPtr->getItem());
                front = newNodePtr;
                tempNewPtr = front;

                for (int i = 1; i < currLength; i++) {
                    tempOldPtr = tempOldPtr->getNext();
                    newNodePtr = new Task(tempOldPtr->getItem());
                    tempNewPtr->setNext(newNodePtr);
                    tempNewPtr = tempNewPtr->getNext();
                    end = newNodePtr;
                }
            }
        }
        return *this;
    }

    void TaskLinkedList::insertAtEnd(int itemToAdd) {
        Task *tempItem = new Task(itemToAdd);
        if (currLength == 0) {
            front = tempItem;
            end = tempItem;
        } else {
            end->setNext(tempItem);
            end = tempItem;
        }
        currLength++;
    }

    void TaskLinkedList::insertAtFront(int itemToAdd) {
        Task *tempItem = new Task(itemToAdd);
        tempItem->setNext(front);
        front = tempItem;
        currLength++;
        if (currLength == 1) {
            end = front;
        }
    }

    void TaskLinkedList::insertAt(int itemToAdd, int index) {
        if (index < 0 || index > currLength) {
            throw std::out_of_range("Cannot Insert outside of function");
        } else {
            if (index == 0) {
                insertAtFront(itemToAdd);
            } else if (index == currLength) {
                insertAtEnd(itemToAdd);
            } else {
                Task* beforePtr = front;
                for (int i = 0; i < index - 1; i++) {
                    beforePtr = beforePtr->getNext();
                }
                Task *nextNode = beforePtr->getNext();
                Task *newNode = new Task(itemToAdd);
                beforePtr->setNext(newNode);
                newNode->setNext(nextNode);
                currLength++;
            }
        }
    }


    int TaskLinkedList::getValueAt(int index) {
        if (index < 0 || index >= currLength) {
            throw std::out_of_range("index not defined in List");
        } else if (index == 0) {
            return front->getItem();
        } else if (index == currLength - 1) {
            return end->getItem();
        } else {
            Task *findNode = front->getNext();
            for (int i = 1; i < index; i++) {
                findNode = findNode->getNext();
            }
            return findNode->getItem();
        }
    }

    int TaskLinkedList::removeValueAt(int index) {
        if (index < 0 || index >= currLength) {
            throw std::out_of_range("Cannot remove a value outside of list");
        } else if (index == 0) {
            Task *delPtr = front;
            int tempReturn = delPtr->getItem();
            front = front->getNext();

            delete delPtr;
            currLength--;
            return tempReturn;
        } else {
            Task *delPtr = front;
            for (int i = 0; i < index - 1; i++) {
                delPtr = delPtr->getNext();
            }
            Task *deleteNode = delPtr->getNext();
            Task *nextNode = deleteNode->getNext();
            int tempReturn = deleteNode->getItem();
            delete deleteNode;
            delPtr->setNext(nextNode);
            currLength--;
            return tempReturn;
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
                output += (std::to_string(tempPtr->getItem()) + ", ");
                tempPtr = tempPtr->getNext();
            } else {
                output += (std::to_string(tempPtr->getItem()));
            }
        }
        output += "}";
        return output;
    }

    int TaskLinkedList::findMaxIndex() {
        int returnIndex;
        if (currLength < 1) {
            returnIndex = -1;
        } else {
            Task *tempPtr = front;
            int maxVal = tempPtr->getItem();
            returnIndex = 0;
            for (int i = 0; i < currLength; i++) {
                if (maxVal < tempPtr->getItem()) {
                    maxVal = tempPtr->getItem();
                    returnIndex = i;
                }
                tempPtr = tempPtr->getNext();
            }
        }
        return returnIndex;
    }

    /**
     * Non-tail Recursive function for returning the index of the first occurence
     *                  of a specific number to look for
     * @param thisnode - the node to start searching on
     * @param lookFor  - the Value to look for
     * @return  - The first index of the value passed in relation to the thisNode
     */
    int findFirstHelper(Task *thisnode, int lookFor) {
        if (thisnode->getItem() == lookFor) {
            return 0;
        }
        if (thisnode->getNext() == nullptr) {
            return -1;
        } else {
            int temp = findFirstHelper(thisnode->getNext(), lookFor);
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
            if (aNode->getItem() == numToFind) {
                lastIndex = i;
            }
            aNode = aNode->getNext();
        }
        return lastIndex;
    }
