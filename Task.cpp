//
// Created by Jeremy Block on 11/21/17.
// Modified by Jeremy Block on 12/09/17
// Modified by Jeremy Block on 12/18/17
//
#include <sstream>
#include <iostream>
#include "Task.h"
#include "TaskLinkedList.h"


//Constructors/Destructor

//Default Constructor is unnecessary, but values are defined so it can be determined if this constructor has been run.
Task::Task() {
    Id = 12345;
    title = "<-No-Title->";
    dueDate = 0;
    priority = 3;
    completed = false;
}
//Basic Constructor for testing
Task::Task(int inIdNum, std::string inTitle) {
    Id = inIdNum;
    title = inTitle;
    dueDate = 0;
    priority = 3;
    completed = false;
}

//Mostly full constructor for creating a new task from User input
Task::Task(int inIdNum, std::string inTitle, int inDue, int inPriority){
    if (inPriority >= 1 || inPriority <= 5){
        Id = inIdNum;
        title = inTitle;
        dueDate = inDue;
        priority = inPriority;
        completed = false;
    } else {
        throw std::out_of_range("Priority is not within agreed range 1-5");
    }

}

//Full Constructor for reading in from file
Task::Task(int inIdNum ,std::string inTitle ,int inDue ,int inPriority,bool complete ){
    if (inPriority >= 1 || inPriority <= 5) {
        Id = inIdNum;
        title = inTitle;
        dueDate = inDue;
        priority = inPriority;
        completed = complete;
    } else {
        throw std::out_of_range("Priority is not within agreed range 1-5");
    }
}
//copy constructor
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


//assignment operator
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
        throw std::out_of_range("Priority is not within agreed range 1-5");
    }
}

int Task::getPriority() {
    return priority;
}

bool Task::toggleTaskCompletion(){
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
    std::string printable = "";
    printable += title + "\n";
    printable += "Due Date: "+std::to_string(dueDate) + "\n";
    printable += "Priority: "+std::to_string(priority) + "\n";
    if(!completed){
        printable += "Complete: No \n\n";
    }
    else{
        printable+="Complete: Yes \n\n";
    }
    return printable;
}

std::string Task::toPrint(){
    std::string priorityStr = "";
    std::string completedStr = "";
    for (int i = 0; i < priority; i++) {
        priorityStr += "!";
    }
    if(completed){
        completedStr = "Task has been completed :-)";
    } else{
        completedStr = "Task is not Complete";
    }
    return "\n" + title + " is due in " + std::to_string(dueDate) +
           " days.\nPriority: " + priorityStr + "\t "+completedStr+"\n";
}
std::string Task::toFile() {
        return std::to_string(Id) + "," + title + "," + std::to_string(dueDate) + "," + std::to_string(priority) + "," +
               std::to_string(completed)+"\n";
}
