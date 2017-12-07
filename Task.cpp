//
// Created by Jeremy Block on 11/21/17.
//
#include <sstream>
#include <iostream>
#include "Task.h"
#include "LinkedNode.h"

//Constructors/Destructor

//Default Constructor

//Constructor
Task::Task(std::string inTitle, int inDue, bool inTaskComplete, int inIdNum){
    //todo Add in the duration, priority and other data members to Task
    title = inTitle;
    dueDate = inDue;
    completed = inTaskComplete;
    Id = inIdNum;
    //call sets on all variables
    //setting next ptr to nullptr for now?

}

//Destructor

Task::~Task(){
    //todo - We don't have a Task destructor yet, cause the memory wont get deleted while the list is alive. WE will need to do this later when we implement file io

}
//todo Assignment operator.
const std::string &Task::getTitle(){
    return title;
}

void Task::setTitle(const std::string &title) {
    Task::title = title;
}

void Task::setDueDate(int dueDate){
    Task::dueDate = dueDate;
}

int Task::getDueDate(){
    return dueDate;
}

void Task::setId(int Id){
    Task::Id = Id;
}

int Task::getId() {
    return Id;
}

bool Task::completeTask(){
    //TODO think about what this will throw if task already completed
    if(completed == false){
        completed = true;
    }
    return completed;
}
bool Task::getComplete(){
    return completed;
}
//void Task::setNext(Task* newNext){
//    next = newNext;
//}

//Task* Task::getNext(){
//    return next;
//}

std::string Task::getItem() {
    return item;
}


//int Task::getDuration() const {
//    //todo write
//    //todo test
//    return duration;
//}

//void Task::setDuration(int duration) {
//    //todo write
//    //todo test
//    Task::duration = duration;
//}

//Task *Task::getDependant() const {
//    //todo write
//    //todo test
//    return dependant;
//}

//void Task::setDependant(Task *nextTask) {
//    //todo test if this works
//    if (this->dependant == nullptr){
//        this->dependant = nextTask;
//    }else{
//        Task* curr = this->dependant;
//        nextTask->setDependant(curr);
//        this->dependant = nextTask;
//    }
//}

//Task *Task::getRoot() const {
//    //todo write
//    //todo test
//    return root;
//}

//void Task::setRoot(Task* newRoot) {
//    //todo write
//    //todo test
//    Task::root = newRoot;
//}

//short Task::getPriority() const {
//    //todo write
//    //todo test
//    return Priority;
//}

//void Task::setPriority(short Priority) {
//    //todo write
//    //todo test
//    Task::Priority = Priority;
//}

//int Task::calcPriority(){
//    //todo automatically calculates priority on every new day bassed on duration of the project, and it's children.
//}
