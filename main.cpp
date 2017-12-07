#include <iostream>
#include <string>
//#include "ArrayList.h"
#include "TaskLinkedList.h"
#include "Task.h"
#include "TaskList.h"


void PrototypeController() {
    List<Task>* masterList = new TaskLinkedList<Task>();
    //ArrayList<Task*>* masterArrayList = new ArrayList(masterList->itemCount());

    //must create empty list of tasks, add first task to that
    int userDirection = -1;
    while (userDirection != 2) {
        std::cout << "Enter 0 to add a new task, 1 to view tasks, 2 to quit: " << std::endl;
        std::cin >> userDirection;


        //add to task
        if (userDirection == 0) {
            std::string inTitle;
            std::string input;
            //print directions
            std::cout<<"Enter the name of the task: "<<std::endl;
            std::getline(std::cin>>inTitle,input);
            std::cout << inTitle << std::endl;


            int dueDate;
            std::cout << "Enter days until due: " << std::endl;
            std::cin >> dueDate;
            std::cout << dueDate << std::endl;
            bool complete = false;
            int ID = 0; //todo MUST CHANGE TO PRODUCE SOME INTEGER
            Task *newTask = new Task(inTitle, dueDate, complete, ID);
            masterList->addToList(newTask);
        }
            //view tasks
        else if (userDirection == 1) {
           std::string printable;
            printable= masterList->toString();
            std::cout<<printable<<"\n\n";
        }
            //complete a task
//        else if (userDirection == 2) {
//            //should call view w/ indicies????
//
//            //print tasks and associated numbers
//
//            //for each case do below
//            Task *taskPtr;
//            taskPtr=masterList->getFront();
//
//
//            std::cout<< "The task " << taskPtr->getTitle() <<" is "<< std::boolalpha<<taskPtr->getComplete()<< std::endl;
//
//        }
            //quit program
        else if (userDirection == 2) {
        } else {
            while (userDirection < 0 || userDirection > 3) {
                std::cout << "Invalid entry. Please enter 0 to add task, 1 to view, 2 to complete, 3 to quit"
                          << std::endl;
                std::cin >> userDirection;
            }
        }

    }

    std::cout << "\n\nThank you for using the JTC TaskManager." << std::endl;

    //prompts user with request to add a task


    //prompt user to input field variables (constructor calls set methods to construct new node)


    //add the node to the list


    //prompt user to view list, add new task, complete task, quit


    //do that thing

    //repeat above until quit is entered
}


int main() {

    std::cout << "Welcome to the JTC TaskManager\n" << std::endl;


    PrototypeController();
    //Task::Task(std::string inTitle="newTask", int inDue=1, bool inTaskComplete=false, int inIdNum=-1)
//    Task* myTask = new Task("task1",1,false,-1);
//    std::string title = myTask->getTitle();
//    std::cout<< title <<std::endl;
    return 0;
}