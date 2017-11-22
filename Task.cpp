//
// Created by Jeremy Block on 11/21/17.
//

#include "Task.h"

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

Task *Task::getDependancy() const {
    //todo write
    //todo test
    return nextTask;
}

void Task::setDependancy(Task *nextTask) {
    //todo test if this works
    if (this->nextTask == nullptr){
        this->nextTask = nextTask;
    }else{
        Task* curr = this->nextTask;
        nextTask->setDependancy(curr);
        this->nextTask = nextTask;
    }
}

Task *Task::getDependsOn() const {
    //todo write
    //todo test
    return dependsOn;
}

void Task::setDependsOn(Task *dependsOn) {
    //todo write
    //todo test
    Task::dependsOn = dependsOn;
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
