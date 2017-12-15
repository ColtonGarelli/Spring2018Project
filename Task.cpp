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
Task::Task(int inIdNum, std::string inTitle) {
    title = inTitle;
    dueDate = 0;
    priority = 3;
    completed = false;
    Id = inIdNum;
}

//Constructor
Task::Task(int inIdNum, std::string inTitle, int inDue, int inPriority){
    title = inTitle;
    dueDate = inDue;
    priority = inPriority;
    completed = false;
    Id = inIdNum;
}

Task::Task(const Task* taskToCopy){
    title = taskToCopy->title;
    dueDate = taskToCopy->dueDate;
    priority = taskToCopy->priority;
    completed = taskToCopy->completed;
    Id = taskToCopy->Id;
}


//Default Destructor is sufficient here because the task is not responsible for it's memory/dependencies
Task::~Task() {
    title = "";
    dueDate=0;
    priority=0;
    completed=true;
    Id=-12345;
}


//asignment operator
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
std::string Task::tostring() {
    std::string priotiryStr = "";
    std::string completedStr = "";

    for (int i = 0; i < priority; i++) {
        priotiryStr += "!";
    }

    if(completed){
        completedStr = "Task has been completed :-)";
    } else{
        completedStr = "Task is not Complete";
    }

    return "\nTask ID: " + std::to_string(Id) + "\n" + title + " is due in " + std::to_string(dueDate) +
           " days.\nPriority: " + priotiryStr + "\t "+completedStr+"\n";
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
