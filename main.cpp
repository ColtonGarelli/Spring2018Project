#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include "ArrayList.h"
#include "TaskLinkedList.h"
#include "Task.h"
#include "TaskList.h"

//void constructorTest (){
//    //todo
//}
//void copyTest() {
//    //todo
//    std::cout << "\nCopyTest () " << std::endl;
//    IntLinkedList *l1 = new IntLinkedList();
//    for (int p = 1; p < 7; p++) {
//        l1->insertAt(p, p - 1);
//    }
//    int size = l1->itemCount();
//    bool errors = false;
//    std::cout << &l1 << "|" << l1->toString() << std::endl;
//    IntLinkedList l2 = IntLinkedList(*l1);
//    std::cout << &l2 << "|" << l2.toString() << std::endl;
//
//
//    while (!l1->isEmpty()) {
//        int temp1 = l1->removeValueAt(0);
//        int temp2 = l2.removeValueAt(0);
//        if (temp1 != temp2) {
//            errors = true;
//        }
//    }
//    if (errors) {
//        std::cout << "FAIL - copy constructor DID NOT WORK" << std::endl;
//    } else {
//        std::cout << "pass" << std::endl;
//
//
//    }
//}
//void assignmentTest(){
//    //todo
//}
//
//
//int getValueAtTest(){
//    //todo
//    std::cout << "\ngetValueAtTest () "<< std::endl;
//    IntList* l1 = new IntLinkedList();
//    for(int p = 1; p < 7; p++){
//        l1->insertAt(p,p-1);
//    }
//    std::cout << l1->toString() << std::endl;
//    bool errors = false;
//    //regular case
//    for( int i = 0; i<l1->itemCount(); i++){
//        int checker = l1->getValueAt(i);
//        if(i != checker-1){
//            errors = true;
//        }
//    }
//    if(errors){
//        std::cout<<"FAIL"<<std::endl;
//    }else{
//        std::cout<<"Pass"<<std::endl;
//    }
//    try{
//        int checker = l1->getValueAt(-1);
//    } catch (std::out_of_range){
//        std::cout<<"Pass"<<std::endl;
//    }
//
//
//}

void printPartsToFile(std::string lineToPrint, char delimiter){
    //char* charString = new char[lineToPrint.length()+1];

    //std::strcpy(charString,lineToPrint.c_str());
    std::ofstream fout; //writes to file storetasks.txt
    if(fout){
        fout.open("storetasks.txt");
        std::stringstream ss (lineToPrint);
        fout<<ss.rdbuf()<<std::endl;
        fout << lineToPrint << std::endl;
    }

    fout.close();
}


void writeFile(TaskList* masterList){
    //ArrayList passed in should be master
    for(int i =0; i<masterList->itemCount(); i++){
        std::string line;
        Task* taskToCopy=masterList->getTaskByIndex(i);
        line = taskToCopy->getTitle();
        line+=","+std::to_string(taskToCopy->getDueDate());
        line+=","+std::to_string(taskToCopy->getPriority());
        line+=","+std::to_string(taskToCopy->getId());
        line+=" ";
        //deal with bool later
        printPartsToFile(line,' ');
    }

}

void readFile(){


}

bool removeValueAtLLTest(){
    std::cout << "\nremoveTaskByIDTest for Linked List () "<< std::endl;
    TaskList* l1 = new TaskLinkedList();
    //fill the list with 6 tasks
    for(int p = 1; p < 7; p++){
        Task* tempPtr = new Task(p, "Test Task #"+std::to_string(p));
        l1->addToList(tempPtr);
        tempPtr = nullptr;
    }
    std::cout << l1->toString() << std::endl;
    bool errors = false;
    //regular removal case
    for( int i = 1; !l1->isEmpty(); i++){
        Task* checker = l1->removeTaskById(i);
        if(i != checker->getId()){
            errors = true;
        }
        delete checker;
        checker = nullptr;
    }
    if(errors){
        std::cout<<"FAIL"<<std::endl;
    }else{
        std::cout<<"Pass"<<std::endl;
    }
    std::cout << l1->toString() << std::endl;
    l1->clearList();

    //refill the list with 6 items
    std::cout <<"refilling list with 6 Tasks" << std::endl;
    for(int p = 1; p < 7; p++){
        Task* tempPtr = new Task(p, "Second Test Task #"+std::to_string(p));
        l1->addToList(tempPtr);
        tempPtr = nullptr;
    }
    //remove the last one
    //todo write a for loop that searched for each id in reverse order.
    std::cout << "Try remove Task with id of 6" << std::endl;
    Task* catcher = l1->removeTaskById(6);
    std::cout << "Caught: " <<catcher->tostring();
    delete catcher;
    catcher= nullptr;
    std::cout << "pass" <<std::endl;
    l1->toString();

    //try things out of bounds
    try {
        std::cout << "Try remove Task with id of 6 again" << std::endl;
        Task* catcher = l1->removeTaskById(6);
        std::cout << "Caught: " <<catcher->tostring();
        delete catcher;
        catcher= nullptr;
    } catch (std::out_of_range& e){
        std::cout << "pass for id of 6 because " << e.what() << std::endl;
    }try {
        Task* catcher = l1->removeTaskById(-1);
        std::cout << "Caught: " <<catcher->tostring();
        delete catcher;
        catcher= nullptr;
    } catch (std::out_of_range& e){
        std::cout << "pass for id of -1 because " << e.what() << std::endl;
    }try {
        Task* catcher = l1->removeTaskById(0);
        std::cout << "Caught: " <<catcher->tostring();
        delete catcher;
        catcher= nullptr;
    } catch (std::out_of_range& e){
        std::cout << "pass for id of 0 because " << e.what() << std::endl;
    }

    std::cout << l1->toString() << std::endl;
    int lastTaskIndex = l1->itemCount()-1;
    std::cout << "removing index "<<lastTaskIndex<<"| aka item # "<<lastTaskIndex+1<<"| relates to value: {"<<l1->getTaskByIndex(lastTaskIndex)->tostring()<<"}"<<std::endl;
    std::cout << l1->toString() << std::endl;
    return errors;
}

//
//int findMaxIndexTest(){
//    //todo
//    std::cout << "\nfindLastTest () "<< std::endl;
//    IntList* l1 = new IntLinkedList();
//    for(int p = 1; p < 7; p++){
//        l1->insertAt(p,p-1);
//    }
//    std::cout << l1->toString() << " | Largest Value is at index " << l1->findMaxIndex() << " | "<< (l1->itemCount()-1==l1->findMaxIndex()) <<std::endl;
//
//    int addBigAt = 2;
//    l1->insertAt(100,addBigAt);
//    std::cout << l1->toString() << " | Largest Value is at index " << l1->findMaxIndex() << " | "<< (addBigAt==l1->findMaxIndex()) <<std::endl;
//
//    IntList* l2 = new IntLinkedList();
//    std::cout << l2->toString() << " | Largest Value is at index " << l2->findMaxIndex() << " | "<< (-1==l2->findMaxIndex()) <<std::endl;
//    l2->insertAtFront(3);
//    std::cout << l2->toString() << " | Largest Value is at index " << l2->findMaxIndex() << " | "<< (0==l2->findMaxIndex()) <<std::endl;
//
//
//}
//
//int findTest(){
//    //todo
//    std::cout << "\nfindTest () "<< std::endl;
//    IntList* l1 = new IntLinkedList();
//    for(int p = 1; p < 7; p++){
//        l1->insertAt(p,p-1);
//    }
//    std::cout << l1->toString() << std::endl;
//    int size = l1->itemCount();
//
//    bool errors = false;
//    for(int i = 1; i < size;i++){
//        if(l1->find(i)!= i-1){
//            errors = true;
//        }
//    }
//
//    if(errors){
//        std::cout<<"FAIL"<<std::endl;
//    } else{
//        std::cout<<"Pass"<<std::endl;
//    }
//
//    if(l1->find(7)!=-1){
//        errors = true;
//    }
//    if(errors){
//        std::cout<<"FAIL"<<std::endl;
//    } else{
//        std::cout<<"Pass"<<std::endl;
//    }
//    if(l1->find(0)!=-1){
//        errors = true;
//    }
//
//    if(errors){
//        std::cout<<"FAIL"<<std::endl;
//    } else{
//        std::cout<<"Pass"<<std::endl;
//    }
//    errors = false;
//    l1->insertAt(6,size);
//    std::cout << l1->toString() << std::endl;
//
//    if(l1->find(6)!=size-1) {
//        errors = true;
//    }
//    if(errors){
//        std::cout<<"FAIL"<<std::endl;
//    } else{
//        std::cout<<"Pass"<<std::endl;
//    }
//
//}
//
//int findLastTest(){
//
//    std::cout << "\nfindLastTest () "<< std::endl;
//    IntList* l1 = new IntLinkedList();
//    for(int p = 1; p < 7; p++){
//        l1->insertAt(p,p-1);
//    }
//    std::cout << l1->toString() << std::endl;
//    int size = l1->itemCount();
//    bool errors = false;
//    for(int i = 1; i < size+1;i++){
//        int tempIdx = l1->findLast(i);
//        if(tempIdx+1 != i){
//            errors = true;
//        }
//    }
//    if(errors){
//        std::cout<<"FAIL"<<std::endl;
//    } else{
//        std::cout<<"Pass"<<std::endl;
//    }
//
//    int valToFind = 5;
//    l1->insertAt(valToFind,size-3);
//    l1->insertAt(valToFind,size-3);
//    l1->insertAt(valToFind,size-3);
//
//    std::cout << l1->toString() << " | The last occurrence of "<< valToFind << " is at " << l1->findLast(valToFind) <<std::endl;
//
//    valToFind = 100;
//    std::cout << l1->toString() << " | The last occurrence of "<< valToFind << " is at " << l1->findLast(valToFind) <<std::endl;
//
//
//
//}
//


bool TestLinkedList() {
    //todo write tests
    bool error = false;
    error = removeValueAtLLTest();
//    findTest();
//    findLastTest();
//    copyTest();
//    findMaxIndexTest();
//    getValueAtTest();


    std::cout<<" ---- Linked List Tests Complete ----"<<std::endl;

    if (error) { // if a test failed return false
        return false;
    } else { //else all tests passed because there were no errors
        return true;
    }

}

bool TestArrayList(){
    std::cout << ("\n*************************\nTESTER:\n");
    TaskList* masterList = new ArrayList(2);
    Task* task1 = new Task(0, "Task1");
    Task* task2 = new Task(1, "Task2");
    Task* task3 = new Task(2, "Task3");
    Task* task4 = new Task(3, "Task4");
    Task* task5 = new Task(4, "Task5");
    Task* task6 = new Task(5, "Task6");

    masterList->addToList(task1);
    masterList->addToList(task2);
    masterList->addToList(task3);
    masterList->addToList(task4);
    masterList->addToList(task5);
    masterList->addToList(task6);

//    masterArrayList->insertAtEnd(task1);
//    masterArrayList->insertAtEnd(task2);
//    masterArrayList->insertAtEnd(task3);
//    masterArrayList->insertAtEnd(task4);
//    masterArrayList->insertAt(task5,2);
    Task* getTaskTest = masterList->getTaskByIndex(2);
    std::cout << masterList->toString();

//    std::string title = myTask->getTitle();
//    std::cout<< title <<st0d::endl;
    return true;
}




void PrototypeController() {
    TaskList* masterList = new TaskLinkedList();
    TaskList* masterArrayList = new ArrayList(3);

    //must create empty list of tasks, add first task to that
    int userDirection = -1;
    while (userDirection != -2) {
        std::cout << "Enter 0 to add a new task, 1 to view tasks, 2 to quit: " << std::endl;
        std::cin >> userDirection;
        //add to task
        if (userDirection == 0) {
            std::string inTitle;
            std::string input;
            //print directions
            std::cout<<"Enter the name of the task: "<<std::endl;
            std::getline(std::cin>>inTitle,input);
            inTitle=inTitle+input;
            std::cout << inTitle << std::endl;


            int dueDate;
            std::cout << "Enter days until due: " << std::endl;
            std::cin >> dueDate;
            std::cout << dueDate << std::endl;
            bool complete = false;
            int ID = 0; //todo MUST CHANGE TO PRODUCE SOME INTEGER
            Task *newTask = new Task(ID, inTitle, dueDate, complete);
            masterList->addToList(newTask);
            masterArrayList->addToList(newTask);
        }
            //view tasks
        else if (userDirection == 1) {
           std::string printable;
            printable= masterArrayList->toString();
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
            userDirection=-2;
            writeFile(masterArrayList);
        }
        else {
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

    if(TestLinkedList() && TestArrayList()) {
        PrototypeController();
    }
    //Task::Task(std::string inTitle="newTask", int inDue=1, bool inTaskComplete=false, int inIdNum=-1)
//    Task* myTask = new Task("task1",1,false,-1);
//    std::string title = myTask->getTitle();
//    std::cout<< title <<std::endl;
    return 0;
}