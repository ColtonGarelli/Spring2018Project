//
// Created by Jeremy Block on 10/31/17.
// Revisions by Jeremy Block on 11/06/17
//

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
            LinkedNode* tempNewPtr; // the address of the penultimate-ly created node
            LinkedNode* tempOldPtr; // The address of the node to copied from the listToCopy
            LinkedNode* newNodePtr; // The newest node created based on the tempOldPtr->getItem.
            tempOldPtr = listToCopy.front;
            newNodePtr = new LinkedNode(tempOldPtr->getItem());
            front = newNodePtr;
            tempNewPtr = front;

            for (int i = 1; i < currLength; i++){
                tempOldPtr = tempOldPtr->getNext();
                newNodePtr = new LinkedNode(tempOldPtr->getItem());
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
    void RecursiveDelete (LinkedNode* oldNode) {
        while (oldNode != nullptr) {
            LinkedNode *temp = (*oldNode).getNext();
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
                LinkedNode *tempNewPtr; // the address of the penultimate-ly created node
                LinkedNode *tempOldPtr; // The address of the node to copied from the listToCopy
                LinkedNode *newNodePtr; // The newest node created based on the tempOldPtr->getItem.
                tempOldPtr = listToCopy.front;
                newNodePtr = new LinkedNode(tempOldPtr->getItem());
                front = newNodePtr;
                tempNewPtr = front;

                for (int i = 1; i < currLength; i++) {
                    tempOldPtr = tempOldPtr->getNext();
                    newNodePtr = new LinkedNode(tempOldPtr->getItem());
                    tempNewPtr->setNext(newNodePtr);
                    tempNewPtr = tempNewPtr->getNext();
                    end = newNodePtr;
                }
            }
        }
        return *this;
    }

    void TaskLinkedList::insertAtEnd(Task* itemToAdd) {
        LinkedNode *tempItem = new LinkedNode(itemToAdd);
        if (currLength == 0) {
            front = tempItem;
            end = tempItem;
        } else {
            end->setNext(tempItem);
            end = tempItem;
        }
        currLength++;
    }

    void TaskLinkedList::insertAtFront(Task* itemToAdd) {
        LinkedNode *tempItem = new LinkedNode(itemToAdd);
        tempItem->setNext(front);
        front = tempItem;
        currLength++;
        if (currLength == 1) {
            end = front;
        }
    }

    void TaskLinkedList::insertAt(Task* itemToAdd, Task* index) {
        if (index < 0 || index > currLength) {
            throw std::out_of_range("Cannot Insert outside of function");
        } else {
            if (index == 0) {
                insertAtFront(itemToAdd);
            } else if (index == currLength) {
                insertAtEnd(itemToAdd);
            } else {
                LinkedNode *beforePtr = front;
                for (int i = 0; i < index - 1; i++) {
                    beforePtr = beforePtr->getNext();
                }
                LinkedNode *nextNode = beforePtr->getNext();
                LinkedNode *newNode = new LinkedNode(itemToAdd);
                beforePtr->setNext(newNode);
                newNode->setNext(nextNode);
                currLength++;
            }
        }
    }


    Task* TaskLinkedList::getValueAt(int index) {
        if (index < 0 || index >= currLength) {
            throw std::out_of_range("index not defined in List");
        } else if (index == 0) {
            return front->getItem();
        } else if (index == currLength - 1) {
            return end->getItem();
        } else {
            LinkedNode *findNode = front->getNext();
            for (int i = 1; i < index; i++) {
                findNode = findNode->getNext();
            }
            return findNode->getItem();
        }
    }

    Task* TaskLinkedList::removeValueAt(int index) {
        if (index < 0 || index >= currLength) {
            throw std::out_of_range("Cannot remove a value outside of list");
        } else if (index == 0) {
            LinkedNode *delPtr = front;
            int tempReturn = delPtr->getItem();
            front = front->getNext();

            delete delPtr;
            currLength--;
            return tempReturn;
        } else {
            LinkedNode *delPtr = front;
            for (int i = 0; i < index - 1; i++) {
                delPtr = delPtr->getNext();
            }
            LinkedNode *deleteNode = delPtr->getNext();
            LinkedNode *nextNode = deleteNode->getNext();
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
        LinkedNode *tempPtr = front;
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

    int IntLinkedList::findMaxIndex() {
        int returnIndex;
        if (currLength < 1) {
            returnIndex = -1;
        } else {
            LinkedNode *tempPtr = front;
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
    int findFirstHelper(LinkedNode *thisnode, int lookFor) {
        //todo do you need the findFirstHelper function
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

    int IntLinkedList::find(int numToFind) {
        //todo do you need tge find function
        return findFirstHelper(front, numToFind);
    }

    int IntLinkedList::findLast(int numToFind) {
        //todo you need the find function
        LinkedNode *aNode = front;
        int lastIndex = -1;
        for (int i = 0; i < currLength; i++) {
            if (aNode->getItem() == numToFind) {
                lastIndex = i;
            }
            aNode = aNode->getNext();
        }
        return lastIndex;
    }
