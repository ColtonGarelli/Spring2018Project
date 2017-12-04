#include <iostream>
#include "TaskLinkedList.h"
#include "Task.h"
#include "TaskTest.h"
#include "List.h"


int main() {
    std::cout << "Hello, World!" << std::endl;
    List<Task>* masterList = new TaskLinkedList<Task>();
    //Task::Task(std::string inTitle="newTask", int inDue=1, bool inTaskComplete=false, int inIdNum=-1)
//    Task* myTask = new Task("task1",1,false,-1);
//    std::string title = myTask->getTitle();
//    std::cout<< title <<std::endl;
    return 0;
}