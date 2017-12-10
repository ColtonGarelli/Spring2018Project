//
// Created by Toby Dragon on 10/24/16.
// Converted to handle Task* by Jeremy Block on 12/09/17
//

#ifndef LINKEDNODE_H
#define LINKEDNODE_H

#include "Task.h"

class LinkedNode {

private:
    Task* item;
    LinkedNode* next;

public:
    LinkedNode(Task* item);
    LinkedNode(const LinkedNode& nodeToCopy); //only copies item, next is set to nullptr
    /**
     * @post Task is deleted when a node is deleted.
     */
    ~LinkedNode();
    Task* getTask();
    int getId();
    LinkedNode* getNext();
    void setItem(Task* newItem);
    void setNext(LinkedNode* newNext);
};


#endif //LINKEDNODE_H

