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

//void printPartsToFile(std::string lineToPrint, char delimiter){
//    //char* charString = new char[lineToPrint.length()+1];
//
//    //std::strcpy(charString,lineToPrint.c_str());
//    std::ofstream fout; //writes to file storetasks.txt
//    if(fout){
//        fout.open("storetasks.txt");
//        std::stringstream ss (lineToPrint);
//        fout<<ss.rdbuf()<<std::endl;
//        fout << lineToPrint << std::endl;
//    }
//
//    fout.close();
//}


//void writeFile(TaskList* masterList){
//    //ArrayList passed in should be master
//    for(int i =0; i<masterList->itemCount(); i++){
//        std::string line;
//        Task* taskToCopy=masterList->getTaskByIndex(i);
//        line = taskToCopy->getTitle();
//        line+=","+std::to_string(taskToCopy->getDueDate());
//        line+=","+std::to_string(taskToCopy->getPriority());
//        line+=","+std::to_string(taskToCopy->getId());
//        line+=" ";
//        //deal with bool later
//        printPartsToFile(line,' ');
//    }
//
//}


bool removeValueAtLLTest() {
    std::cout << "\nremoveTaskByIDTest for Linked List () \n---------------------------------------" << std::endl;
    TaskList *l1 = new TaskLinkedList();

    std::cout << "fill the list with 6 tasks" << std::endl;
    for (int p = 1; p < 7; p++) {
        Task *tempPtr = new Task(p, "Test Task #" + std::to_string(p));
        l1->addToList(tempPtr);
        tempPtr = nullptr;
    }

    std::cout << "try removing from front: ";
    bool errors = false;
    //regular removal case
    for (int i = 1; !l1->isEmpty(); i++) {
        Task *checker = l1->removeTaskById(i);
        if (i != checker->getId()) {
            errors = true;
        }
        delete checker;
        checker = nullptr;
    }
    if (errors) {
        std::cout << "FAIL" << std::endl;
    } else {
        std::cout << "Pass" << std::endl;
    }
//    std::cout << l1->toString() << std::endl;
//    l1->clearList();

    //refill the list with 6 items
    std::cout << "refilling list with 6 Tasks" << std::endl;
    for (int p = 1; p < 7; p++) {
        Task *tempPtr = new Task(p, "Second Test Task #" + std::to_string(p));
        l1->addToList(tempPtr);
        tempPtr = nullptr;
    }
    //remove Tasks from end including out of range
    for (int r = 7; r >= 0; r--) {
        std::cout << "Try remove Task with id of " << std::to_string(r) << ": ";
        try {
            Task *catcher = l1->removeTaskById(r);
//            std::cout << "Caught: " << catcher->toString();
            delete catcher;
            catcher = nullptr;
            std::cout << "pass" << std::endl;
        } catch (std::out_of_range &e) {
            std::cout << "pass for id of " << std::to_string(r) << " because " << e.what() << std::endl;
        }

    }

    std::cout << "\nMake a small array and try removing from middle" << std::endl;
    for (int p = 1; p < 4; p++) {
        Task *tempPtr = new Task(p, "Test Task #" + std::to_string(p), p + 2);
        l1->addToList(tempPtr);
        tempPtr = nullptr;
    }
    std::cout << l1->toString() << std::endl;
    int lastTaskIndex = l1->itemCount() - 2;
    try {
        Task *catcher = l1->getTaskByIndex(lastTaskIndex);
        std::cout << "getting index " << lastTaskIndex << "| has id of " << catcher->getId()
                  << "| relates to task: " << catcher->toString() << std::endl;
        catcher = nullptr;
        std::cout << "but the list remains unchanged from get method: " << l1->toString() << std::endl;
        Task *catcher2 = l1->removeTaskById(l1->getTaskByIndex(lastTaskIndex)->getId());
        delete catcher2;
        catcher2 = nullptr;
        std::cout << "Now remove task from index " << lastTaskIndex << ": " << l1->toString() << std::endl;
    } catch (std::out_of_range &e) {
        std::cout << "Fail" << std::endl;
    }

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

    Task* getTaskTest = masterList->getTaskByIndex(2);
    std::cout << masterList->toString();

    return true;
}

TaskList* readFile() {
    //todo Talk with group about how to handle when a user enters a task title with commas
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
        line+=taskToCopy->toFile();
//        line+=std::to_string(taskToCopy->getId());
//        line +=","+taskToCopy->getTitle();
//        line+=","+std::to_string(taskToCopy->getDueDate());
//        line+=","+std::to_string(taskToCopy->getPriority());
//        line+=","+std::to_string(taskToCopy->getComplete())+" ";

    }
    printPartsToFile(line,'\n');


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
    return userDirection;

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
Task* taskIn(int &uniqueID){
    std::string inTitle;
    std::string input;
    //print directions
    std::cout << "Enter the name of the task: " << std::endl;
    std::getline(std::cin >> inTitle, input);
    inTitle = inTitle + input;
    std::cout << inTitle << std::endl;

    std::cout << "Enter days until due: " << std::endl;
    int dueDate = intEntry();
    bool complete = false;
    int ID = uniqueID;
//            int ID = genRandInt(0,500);
//            for(int i; i<(masterList->itemCount());i++){
//                if(ID == masterList->getTaskByIndex(i)->getId()){
//                    ID=genRandInt(0,500);
//                    i=0;
//                }
//            }
    Task *newTask = new Task(ID, inTitle, dueDate, complete);
    uniqueID++;
    return newTask;
}




void PrototypeController() {
    TaskList *masterList = new TaskLinkedList();
    TaskList *masterArrayList = new ArrayList();
    int uniqueID = 0;
    masterList = readFile();
    std::cout << "\nImporting from last session:\n" << masterList->toString() << "\n\n";

    int userDirection=-1;
    //must create empty list of tasks, add first task to that
    //add to task
    std::cout << "Welcome to the JTC TaskManager\n" << std::endl;
    while (userDirection != 0) {
        userDirection = optionEntry();
        if (userDirection == 1) {
            Task* newTask=taskIn(uniqueID);
            masterList->addToList(newTask);
            masterArrayList->addToList(newTask);
        }
            //view all tasks
        else if (userDirection == 2) {
            std::cout <<  masterArrayList->toString() << "\n\n";
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

    writeFile(masterList);
    std::cout << "\n\nThank you for using the JTC TaskManager." << std::endl;
}




int main() {



//     PrototypeController();


    if(TestLinkedList() && TestArrayList()) {
        PrototypeController();
    }
    //Task::Task(std::string inTitle="newTask", int inDue=1, bool inTaskComplete=false, int inIdNum=-1)
//    Task* myTask = new Task("task1",1,false,-1);
//    std::string title = myTask->getTitle();
//    std::cout<< title <<std::endl;
    return 0;
}