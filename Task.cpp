//
// Created by Jeremy Block on 11/21/17.
// Modified by Jeremy Block on 12/09/17
//
#include <sstream>
#include <iostream>
#include "Task.h"
#include "TaskLinkedList.h"


//Constructors/Destructor

//Default Constructor
Task::Task() {
    Id = 12345;
    title = "<-No-Title->";
    dueDate = 0;
    priority = 3;
    completed = false;
}
Task::Task(int inIdNum, std::string inTitle) {
    Id = inIdNum;
    title = inTitle;
    dueDate = 0;
    priority = 3;
    completed = false;
}

//Constructor
Task::Task(int inIdNum, std::string inTitle, int inDue, int inPriority){
    Id = inIdNum;
    title = inTitle;
    dueDate = inDue;
    priority = inPriority;
    completed = false;
}

//Constructor
Task::Task(int inIdNum ,std::string inTitle ,int inDue ,int inPriority,bool complete ){
    Id = inIdNum;
    title = inTitle;
    dueDate = inDue;
    priority = inPriority;
    completed = complete;
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
    Id=-12345;
    title = "";
    dueDate=0;
    priority=0;
    completed=true;
}


//asignment operator
Task& Task::operator=(const Task& taskToCopy){
    if(this != &taskToCopy){
        Id= taskToCopy.Id;
        title = taskToCopy.title;
        dueDate = taskToCopy.dueDate;
        priority = taskToCopy.priority;
        completed = taskToCopy.completed;
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

bool Task::setTaskCompletion(){
    //TODO think about what this will throw if task already completed
    if(completed == false){
        completed = true;
    }else{
        completed= false;
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

std::string Task::toString() {
//    std::string priotiryStr = "";
//    std::string completedStr = "";
    std::string printable = "To Do:\n\n";
    printable +=this->getTitle() + "\n";
    printable += "Due Date: "+std::to_string(this->dueDate) + "\n";
    printable += "Priority: "+std::to_string(this->getPriority()) + "\n";
    if(!getComplete()){
        printable += "Complete: No \n\n";
    }
    else{
        printable+="Complete: Yes \n\n";
    }
    return printable;
}




//    for (int i = 0; i < priority; i++) {
//        priotiryStr += "!";
//    }
//
//    if(completed){
//        completedStr = "Task has been completed :-)";
//    } else{
//        completedStr = "Task is not Complete";
//    }
//
//    return "\nTask ID: " + std::to_string(Id) + "\n" + title + " is due in " + std::to_string(dueDate) +
//           " days.\nPriority: " + priotiryStr + "\t "+completedStr+"\n";
//
//}
std::string Task::toFile() {
    //todo have not tested this
//    if(Id != -12345 &&
//       title != "" &&
//       dueDate != 0 &&
//       priority != 0 &&
//       completed != true) {
        return std::to_string(Id) + "," + title + "," + std::to_string(dueDate) + "," + std::to_string(priority) + "," +
               std::to_string(completed)+"\n";
//    } else{
//        throw Bad_Task_Id();
//    }

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
