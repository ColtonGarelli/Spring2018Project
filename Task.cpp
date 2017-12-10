//
// Created by Jeremy Block on 11/21/17.
// Modified by Jeremy Block on 12/09/17
//
#include <sstream>
#include <iostream>
#include "Task.h"

//Constructors/Destructor

//Default Constructor
Task::Task() {
    title = "<-No-Title->";
    dueDate = 0;
    priority = 3;
    completed = false;
    Id = 12345;
}
Task::Task(std::string inTitle, int inIdNum) {
    title = inTitle;
    dueDate = 0;
    priority = 3;
    completed = false;
    Id = inIdNum;
}

//Constructor
Task::Task(std::string inTitle, int inDue, int inPriority=1, int inIdNum = 0){
    title = inTitle;
    dueDate = inDue;
    priority = inPriority;
    completed = false;
    Id = inIdNum;
}

//Default Destructor is sufficient here because the task is not responsible for it's memory/dependencies

Task& Task::operator=(const Task& taskToCopy){
    if(this != &taskToCopy){
        title = taskToCopy.title;
        dueDate = taskToCopy.dueDate;
        priority = taskToCopy.priority;
        completed = taskToCopy.completed;
        Id= taskToCopy.Id;
    }
    return* this;
}
void Task::setTitle(std::string inTitle) {
    title = inTitle;
}

std::string Task::getTitle(){
    return title;
}

void Task::setDueDate(int dueDate){
    Task::dueDate = dueDate;
}

int Task::getDueDate(){
    return dueDate;
}

void Task::setPriority(int inPriority) {
    if (inPriority >= 1 || inPriority <= 5){
        priority = inPriority;
    } else {
        throw std::out_of_range("Priority is not in aggreed range 1-5");
    }
}

int Task::getPriority() {
    return priority;
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

void Task::setId(int Id){
    Task::Id = Id;
}

int Task::getId() {
    return Id;
}

//int Task::getDuration() {
//    return duration;
//}
//
//void Task::setDuration(int inDuration) {
//    duration = inDuration;
//}
//
//Task *Task::getDependant() {
//    return dependant;
//}
//
//void Task::setDependant(Task *nextTask) {
//    if (this->dependant == nullptr){
//        this->dependant = nextTask;
//    }else{
//        Task* curr = this->dependant;
//        nextTask->setDependant(curr);
//        this->dependant = nextTask;
//    }
//}
//
//int Task::calcPriority(){
//    //todo automatically calculates priority on every new day bassed on duration of the project, and it's children.
//}
