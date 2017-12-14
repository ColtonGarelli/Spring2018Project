//
// Created by Jeremy Block on 10/31/17.
// Revisions by Jeremy Block on 11/06/17
//

#include <functional>
#include "TaskLinkedList.h"
#include "LinkedNode.h"

//constructor
    TaskLinkedList::TaskLinkedList() {
    //todo test this
        currLength = 0;
        front = nullptr;
        end = nullptr;
    }
    //copy constructor (makes it's own linked list with it's own nodes and with new copied tasks)
    TaskLinkedList::TaskLinkedList(const TaskLinkedList& listToCopy){
        //todo test this
        currLength = listToCopy.currLength;
        if(listToCopy.front != nullptr){ // if the listToCopy is not empty
            LinkedNode* tempNewPtr; // the address of the penultimate-ly created node
            LinkedNode* tempOldPtr; // The address of the node to copied from the listToCopy
            LinkedNode* newNodePtr; // The newest node created based on the tempOldPtr->getItem.
            tempOldPtr = listToCopy.front;
//            Task* newestTask = new Task(tempOldPtr->getTask()->getTitle(),tempOldPtr->getTask()->getDueDate(),tempOldPtr->getTask()->getPriority(), tempOldPtr->getTask()->getId());
            Task* newestTask(tempOldPtr->getTask()); //todo may make something on the stack and break stuff
            newNodePtr = new LinkedNode(newestTask);
            front = newNodePtr;
            tempNewPtr = front;

            for (int i = 1; i < currLength; i++){
                tempOldPtr = tempOldPtr->getNext();
//                Task* newestTask = new Task(tempOldPtr->getTask()->getTitle(),tempOldPtr->getTask()->getDueDate(),tempOldPtr->getTask()->getPriority(), tempOldPtr->getTask()->getId());
                Task* newestTask(tempOldPtr->getTask()); //todo may make something on the stack and break stuff
                newNodePtr = new LinkedNode(newestTask);
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
        //todo test this
        while (oldNode != nullptr) {
            LinkedNode *temp = (*oldNode).getNext();
            delete oldNode;
            oldNode = temp;
        }
    }

    //destructor
    TaskLinkedList::~TaskLinkedList(){
        //todo test this
        currLength=0;
        RecursiveDelete(front);
        front = nullptr;
        end = nullptr;

    }

    //Assignment operator
    TaskLinkedList& TaskLinkedList::operator=(const TaskLinkedList& listToCopy) {
        //todo test this
        if(this != &listToCopy) {
            clearList();
            if (listToCopy.front != nullptr) {
                LinkedNode *tempNewPtr; // the address of the penultimate-ly created node
                LinkedNode *tempOldPtr; // The address of the node to copied from the listToCopy
                LinkedNode *newNodePtr; // The newest node created based on the tempOldPtr->getItem.
                tempOldPtr = listToCopy.front;
//                Task* newestTask = new Task(tempOldPtr->getTask()->getTitle(),tempOldPtr->getTask()->getDueDate(),tempOldPtr->getTask()->getPriority(), tempOldPtr->getTask()->getId());
                Task* newestTask(tempOldPtr->getTask()); //todo may make something on the stack and be broken
                newNodePtr = new LinkedNode(newestTask);
                front = newNodePtr;
                tempNewPtr = front;

                for (int i = 1; i < currLength; i++) {
                    tempOldPtr = tempOldPtr->getNext();
//                    Task* newestTask = new Task(tempOldPtr->getTask()->getTitle(),tempOldPtr->getTask()->getDueDate(),tempOldPtr->getTask()->getPriority(), tempOldPtr->getTask()->getId());
                    Task* newestTask(tempOldPtr->getTask()); //todo may make something on the stack and be broken
                    newNodePtr = new LinkedNode(newestTask);
                    tempNewPtr->setNext(newNodePtr);
                    tempNewPtr = tempNewPtr->getNext();
                    end = newNodePtr;
                }
            }
        }
        return *this;
    }

//todo make a LinkedNode* TaskList::returnNodeWhereNext(int property, int Equals){}
//todo make a LinkedNode* TaskList::returnLastNodeWhere(int property, int Equals){}

    /**
     * Traversal function that returns a pointer to the first node with a task.[propery] == equals from the list
     * @param property - an identifier: 1. run on due date, 2. run on priority, or 3. run on id
     * @param equals - the value to look for.
     * @throws bad_function_call error when property is not either 1.DueDate 2.priority or 3.id
     * @throws out_of_range if a Task can not be found with the specified property/equals combination
     * @return - returns ptr to the first node in the LinkedList with a Task.[property] == Equals, otherwise throws out_of_range error
     */
    LinkedNode* TaskLinkedList::returnNodeWhere(int property, int equals) {
        //todo test me PLEASE
        LinkedNode *curr = front;
        if (property == 1) { //DueDate
            if (curr->getTask()->getDueDate() == equals) {
                return curr;
            } else {
                while (curr->getNext() != nullptr) {
                    curr = curr->getNext();
                    if (curr->getTask()->getDueDate() == equals) {
                        return curr;
                    }
                }
//                        return nullptr; //todo since this is the last in the list, check if InsertAfter is Checking if it's inserting at the end.
                throw std::out_of_range("No Task with DueDate Specified");
            }
        } else if (property == 2) { //Priority
            if (curr->getTask()->getPriority() == equals) {
                return curr;
            } else {
                while (curr->getNext() != nullptr) {
                    curr = curr->getNext();
                    if (curr->getTask()->getPriority() == equals) {
                        return curr;
                    }
                }
//                        return nullptr; //todo since this is the last in the list, check if InsertAfter is Checking if it's inserting at the end.
                throw std::out_of_range("No Task with Priority Specified");
            }
        } else if (property == 3) { //id
            if (curr->getTask()->getId() == equals) {
                return curr;
            } else {
                while (curr->getNext() != nullptr) {
                    curr = curr->getNext();
                    if (curr->getTask()->getId() == equals) {
                        return curr;
                    }
                }
//                        return nullptr; //todo since this is the last in the list, check if InsertAfter is Checking if it's inserting at the end.
                throw std::out_of_range("No Task with ID Specified");
            }
        } else {
            throw std::bad_function_call();
        }
    }

    /**
     *  helper function to take node out of a linked list without deleting the node;
     *  @param here - the node that precedes the item to be extracted
     *  @post currLength is reduced by 1
     *  @Throws std::out_of_range error if node after "here" is null
     */
    LinkedNode* TaskLinkedList::extractNodeAfter(LinkedNode *here) {
        //todo test this
        if (here->getNext() != nullptr) {
            LinkedNode *extractNode = here->getNext(); //identify extract node
            LinkedNode *nextNode = extractNode->getNext(); //identify third node
            here->setNext(nextNode); //relink
            currLength--;
            return extractNode;
        } else {
            throw std::out_of_range("the node after here is null");
        }
    }
    void insertAfter(LinkedNode* here, Task* newTask){
        //todo test if this works when the list is empty.
        LinkedNode* newItem = new LinkedNode(newTask);
        LinkedNode* tempPtr = here->getNext();
        here->setNext(newItem);
        newItem->setNext(tempPtr);
    }

    void TaskLinkedList::addToList(Task* itemToAdd){
        //TODO Write this all out
        if(front == nullptr){
            insertAtFront(itemToAdd);
        }else if (end->getTask()->getPriority() >= itemToAdd->getPriority()){
            insertAtEnd(itemToAdd);
        }
        else{
            int searchPriority = itemToAdd->getPriority();
            insertAfter(returnNodeWhere(2,searchPriority), itemToAdd);
        }
    }

    void TaskLinkedList::insertAtEnd(Task* taskToAdd) {
        //todo test this
        LinkedNode *tempItem = new LinkedNode(taskToAdd);
        if (currLength == 0) {
            front = tempItem;
            end = tempItem;
        } else {
            end->setNext(tempItem);
            end = tempItem;
        }
        currLength++;
    }

    void TaskLinkedList::insertAtFront(Task* taskToAdd) {
        //todo test this
        LinkedNode *tempItem = new LinkedNode(taskToAdd);
        tempItem->setNext(front);
        front = tempItem;
        currLength++;
        if (currLength == 1) {
            end = front;
        }
    }

    void TaskLinkedList::insertAt(Task* taskToAdd, int index) {
        //todo test this
        if (index < 0 || index > currLength) {
            throw std::out_of_range("Cannot Insert outside of function");
        } else {
            if (index == 0) {
                insertAtFront(taskToAdd);
            } else if (index == currLength) {
                insertAtEnd(taskToAdd);
            } else {
                LinkedNode *beforePtr = front;
                for (int i = 0; i < index - 1; i++) {
                    beforePtr = beforePtr->getNext();
                }
                LinkedNode *nextNode = beforePtr->getNext();
                LinkedNode *newNode = new LinkedNode(taskToAdd);
                beforePtr->setNext(newNode);
                newNode->setNext(nextNode);
                currLength++;
            }
        }
    }

    int TaskLinkedList::findFirstPriority(int lookFor){
        //todo test this
        LinkedNode *findNode = front;
        while(findNode->getTask()->getPriority() > lookFor){
            findNode=findNode->getNext();
        }
        return findNode->getId();

    }

    int TaskLinkedList::findLastPriority(int lookFor){
        //todo test this
        return findFirstPriority(lookFor-1);
    }

    Task* TaskLinkedList::getTaskByIndex(int index) {
        //todo test this
        if (index < 0 || index > currLength-1) {
            throw std::out_of_range("index not defined in List");
        } else if (index == 0) {
            return front->getTask();
        } else if (index == currLength - 1) {
            return end->getTask();
        } else {
            LinkedNode *findNode = front->getNext();
            for (int i = 1; i < index; i++) {
                findNode = findNode->getNext();
            }
            return findNode->getTask();
        }
    }

/**
 * Returns node that points at the node with the specified id so a remove can take place
 * @pre check the first node in the linked list. this recursive fuction will look at everything after it.
 * @param curr - the node to look from (also the node that will be returned if the next node matches the id)
 * @param idToFind - the id to search for
 * @return the node that points to a node with an id.
 */
    LinkedNode* findNextNodeWithId(LinkedNode *curr, int idToFind){
        if(curr->getNext() != nullptr){
            if (curr->getNext()->getId() == idToFind){
                return curr;
            } else{
                return findNextNodeWithId(curr->getNext(), idToFind);
            }
        }else {
            throw std::out_of_range("ID is not in list.");
        }
    }

    Task* TaskLinkedList::removeTaskById(int idToFind) {
        //todo test still do not pass
        //todo this needs to deal with end ptr when nothing is left in the list or
        //todo if front and end are pointed at the same (only) node in the list.
        if(front != nullptr) {
            LinkedNode *delPtr;
            Task *tempReturn;
            if (idToFind == front->getTask()->getId()) {
                delPtr = front;
                tempReturn = new Task(delPtr->getTask());
                front = front->getNext();

                delete delPtr;
            } else if(idToFind == end->getTask()->getId()){
                delPtr = end; //define a node that needs to be removed
                tempReturn = new Task(delPtr->getTask()); //make a copy of the task from the node
                LinkedNode *prvPtr = findNextNodeWithId(front, idToFind); //find the node that points at end
                end = prvPtr;
                end->setNext(nullptr);

                delete delPtr;
            } else {
                LinkedNode *prvPtr = findNextNodeWithId(front, idToFind);
                delPtr = prvPtr->getNext();
                tempReturn = new Task(prvPtr->getTask());
                prvPtr = delPtr->getNext();

                delete delPtr;
            }
            currLength--;
            if(isEmpty()){
                clearList();
            }
            return tempReturn;

        }
    }

    bool TaskLinkedList::isEmpty() {
        //todo test this
        return currLength == 0;
    }

    int TaskLinkedList::itemCount() {
        //todo test this
        return currLength;
    }

    void TaskLinkedList::clearList() {
        //todo test this
        currLength = 0;
        RecursiveDelete(front); //also deletes all the tasks obj
        front = nullptr;
        end = nullptr;
    }

    std::string TaskLinkedList::toString() {
        //todo test this
        LinkedNode *tempPtr = front;
        std::string output = "The List:\n";
        for (int i = 0; i < currLength; i++) {
            output += std::to_string(i + 1) + ".) " + tempPtr->getTask()->getTitle() + "\n";
            tempPtr = tempPtr->getNext();
        }
        return output;
    }