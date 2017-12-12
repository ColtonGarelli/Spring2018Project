//
// Created by Toby Dragon on 10/17/17.
// Added by Taylor Yowan on 12/07/17.
// Converted to handle Task* by Jeremy Block on 12/09/17
//
#include "LinkedNode.h"

LinkedNode::LinkedNode(Task* item){
    this->item = item;
    next = nullptr;
}

LinkedNode::LinkedNode(const LinkedNode& nodeToCopy){
    //todo readthrough this and call the task cunstructor
    item = nodeToCopy.item;
    next = nullptr;
}
LinkedNode::~LinkedNode(){
    delete item;
}

Task* LinkedNode::getTask(){
    return item;
}
int LinkedNode::getId(){
    return item->getId();
}

LinkedNode* LinkedNode::getNext(){
    return next;
}

void LinkedNode::setItem(Task* newItem){
    item = newItem;
}

void LinkedNode::setNext(LinkedNode* newNext){
    next = newNext;
}
