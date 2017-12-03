//
// Created by Jeremy Block on 11/21/17.
//

#include "Task.h"

//test add taylor

//todo update these setters and getters as needed.

//Constructors/Destructor

//Constructor
Task::Task(std::string title, int due, bool taskComplete, int IdNum){

    //call sets on all variables
    //setting next ptr to nullptr for now?

}

//Destructor

~Task::Task(){

}
const std::string &Task::getTitle(){
    //todo write
    //todo test
    return title;
}

void Task::setTitle(const std::string &title) {
    //todo write
    //todo test
    Task::title = title;
}

void Task::setDueDate(int dueDate){
    //todo write
    //todo test
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
