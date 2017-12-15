#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <vector>
#include "ArrayList.h"
#include "ArrayLib.h"
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



    if (error) { // if a test failed return false
        return false;
    } else { //else all tests passed because there were no errors
        return true;
    }

}

bool TestArrayList(){
    std::cout << ("\n*************************\nTESTER:\n");
    TaskList* masterList = new TaskLinkedList();
    Task* task1 = new Task(0, "Task1");
    Task* task2 = new Task(1, "Task2");
    Task* task3 = new Task(2, "Task3");
    Task* task4 = new Task(3, "Task4");
    Task* task5 = new Task(4, "Task5");

    masterList->addToList(task1);
    masterList->addToList(task2);
    masterList->addToList(task3);
    masterList->addToList(task4);
    masterList->addToList(task5);
    TaskList* masterArrayList = new ArrayList(masterList->itemCount());
    masterArrayList->insertAtEnd(task1);
    masterArrayList->insertAtEnd(task2);
    masterArrayList->insertAtEnd(task3);
    masterArrayList->insertAtEnd(task4);
    masterArrayList->insertAt(task5,2);
    Task* getTaskTest = masterArrayList->getTaskByIndex(2);
    std::cout << masterArrayList->toString();

//    std::string title = myTask->getTitle();
//    std::cout<< title <<st0d::endl;
    return true;
}

TaskList* readFile() {
    TaskList* masterList = new TaskLinkedList();
    std::string textIn;
    std::ifstream fin("storetasks.txt");
    while (!fin.eof()) {
        getline(fin, textIn);
        std::stringstream parts(textIn);
        char delimiter = ',';
        std::string string;
        while (parts) {
            std::string holder;
            getline(parts, holder, delimiter);
            if (holder == ""){}
            else {
                int idIn;
                getline(parts, holder, delimiter);
                std::string title = holder;
                std::stringstream makeID(holder);
                makeID >> idIn;
                int dueDate;
                getline(parts, holder, delimiter);
                std::stringstream makeDue(holder);
                makeDue >> dueDate;
                int priority;
                getline(parts, holder, delimiter);
                std::stringstream priorityS(holder);
                priorityS >> priority;
                bool complete;
                getline(parts, holder, delimiter);
                std::stringstream makeComplete(holder);
                makeComplete >> complete;
                Task *newTask = new Task(idIn, title, dueDate, complete);
                masterList->addToList(newTask);
            }
        }
    }
    fin.close();
    return masterList;
}





void printPartsToFile(std::string lineToPrint, char delimiter){
    std::ofstream fout("storetasks.txt"); //writes to file storetasks.txt
    if(fout){
        std::stringstream parts(lineToPrint);
        while(parts){
            std::string part;
            getline(parts,part,delimiter);
            fout<<part<<std::endl;
        }
        fout.close();
    }
    else{
        std::cout<<"error in opening parts";
    }


}




void writeFile(TaskList* masterList){
    //ArrayList passed in should be master
    std::string line;//=(std::to_string(masterList->itemCount())+" ");
    for(int i =0; i<masterList->itemCount(); i++){
        Task* taskToCopy=masterList->getTaskByIndex(i);
        line+=std::to_string(taskToCopy->getId());
        line +=","+taskToCopy->getTitle();
        line+=","+std::to_string(taskToCopy->getDueDate());
        line+=","+std::to_string(taskToCopy->getPriority());
        line+=","+std::to_string(taskToCopy->getComplete())+" ";

    }
    printPartsToFile(line,' ');


}


int userDirection(int someInt){

}
int intEntry(){
    int userDirection=-1;
    std::string userString;
    std::cin >> userString;
    std::stringstream convertor;
    convertor << userString;
    convertor >> userDirection;
    bool invalid=false;
    if(convertor.fail()){
        invalid=true;
    }
    while(invalid) {
        std::cout << "Please enter a valid number." << std::endl;
        std::cin >> userString;
        std::stringstream convertor;
        convertor << userString;
        convertor >> userDirection;
        if(convertor.fail()){
            invalid=true;
        }
        else{
            invalid=false;
        }
    }

}

int optionEntry() {
    int userDirection = -1;
    std::cout << "Enter 1 to add a new task, 2 to view tasks, 0 to quit: " << std::endl;
    std::string userString;
    std::cin >> userString;
    std::stringstream convertor;
    convertor << userString;
    convertor >> userDirection;
    bool invalid = false;
    if (convertor.fail()) {
        invalid = true;
    }
    while (invalid) {
        std::cout << "Please enter a valid number." << std::endl;
        std::cout << "Enter 1 to add a new task, 2 to view tasks, 0 to quit: " << std::endl;
        std::cin >> userString;
        std::stringstream convertor;
        convertor << userString;
        convertor >> userDirection;
        if (convertor.fail()) {
            invalid = true;
        } else {
            invalid = false;
        }
    }
    while (userDirection < 0 || userDirection > 3) {
        std::cout << "Invalid entry."
                  << std::endl;
        userDirection = optionEntry();
    }
    return userDirection;
}
Task* taskIn(){
    std::string inTitle;
    std::string input;
    //print directions
    std::cout << "Enter the name of the task: " << std::endl;
    std::getline(std::cin >> inTitle, input);
    inTitle = inTitle + input;
    std::cout << inTitle << std::endl;
    int dueDate;
    std::cout << "Enter days until due: " << std::endl;
    intEntry();
    bool complete = false;
    int ID = 0;
//            int ID = genRandInt(0,500);
//            for(int i; i<(masterList->itemCount());i++){
//                if(ID == masterList->getTaskByIndex(i)->getId()){
//                    ID=genRandInt(0,500);
//                    i=0;
//                }
//            }
    Task *newTask = new Task(ID, inTitle, dueDate, complete);
    return newTask;
}




void PrototypeController() {
    TaskList *masterList = new TaskLinkedList();
    TaskList *masterArrayList = new ArrayList();
    int userDirection=-1;
    //must create empty list of tasks, add first task to that
    //add to task
    while (userDirection != 0) {
        userDirection = optionEntry();
        if (userDirection == 1) {
            Task* newTask=taskIn();
            masterList->addToList(newTask);
            masterArrayList->addToList(newTask);
        }
            //view all tasks
        else if (userDirection == 2) {
            std::cout << masterArrayList->toString() << "\n\n";
        }
        else if(userDirection==3){

        }
        else if(userDirection==4){

        }
        else if(userDirection==5){

        }
            //enter 0 to quit program
    }
    //upon quit writes to file

    writeFile(masterArrayList);
    std::cout << "\n\nThank you for using the JTC TaskManager." << std::endl;
}




int main() {

    std::cout << "Welcome to the JTC TaskManager\n" << std::endl;
    TaskList* fileRead = readFile();
    std::cout << fileRead->toString() << "\n\n";

    // PrototypeController();


//    if(TestLinkedList() && TestArrayList()) {
//        PrototypeController();
//    }
    //Task::Task(std::string inTitle="newTask", int inDue=1, bool inTaskComplete=false, int inIdNum=-1)
//    Task* myTask = new Task("task1",1,false,-1);
//    std::string title = myTask->getTitle();
//    std::cout<< title <<std::endl;
    return 0;
}