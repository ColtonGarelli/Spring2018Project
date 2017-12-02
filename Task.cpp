//
// Created by Jeremy Block on 11/21/17.
//

#include "Task.h"

//test add taylor

//todo update these setters and getters as needed.

const std::string &Task::getTitle() const {
    //todo write
    //todo test
    return title;
}

void Task::setTitle(const std::string &title) {
    //todo write
    //todo test
    Task::title = title;
}

int Task::getDuration() const {
    //todo write
    //todo test
    return duration;
}

void Task::setDuration(int duration) {
    //todo write
    //todo test
    Task::duration = duration;
}

Task *Task::getDependant() const {
    //todo write
    //todo test
    return dependant;
}

void Task::setDependant(Task *nextTask) {
    //todo test if this works
    if (this->dependant == nullptr){
        this->dependant = nextTask;
    }else{
        Task* curr = this->dependant;
        nextTask->setDependant(curr);
        this->dependant = nextTask;
    }
}

Task *Task::getRoot() const {
    //todo write
    //todo test
    return root;
}

void Task::setRoot(Task* newRoot) {
    //todo write
    //todo test
    Task::root = newRoot;
}

short Task::getPriority() const {
    //todo write
    //todo test
    return Priority;
}

void Task::setPriority(short Priority) {
    //todo write
    //todo test
    Task::Priority = Priority;
}
