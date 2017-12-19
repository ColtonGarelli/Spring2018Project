//
// Created by Jeremy Block on 12/18/17.
// Linked List Tests written by Jeremy Block
// ArrayList Tests written by Taylor Yowan
//

#include <iostream>
#include "Tester.h"
#include "Task.h"
#include "TaskList.h"
#include "TaskLinkedList.h"
#include "ArrayList.h"

bool Tester::removeValueAtLLTest() {
    std::cout << "\nremoveTaskTest for Linked List () \n---------------------------------------" << std::endl;
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

bool Tester::doubleCapacityTest(){
    std::cout << ("\nTesting Double Capacity\n");
    int numErrors = 0;
    bool errors = false;
    ArrayList testList;
    for (int i=0; i< 100; i++){
        Task* testTask = new Task(i,"testTask");
        testList.insertAtEnd(testTask);
    }
    for (int i=0; i<100; i++){
        if (testList.getValueAt(i)->getId() != i){
            numErrors++;
        }
    }
    if (numErrors == 0){
        std::cout << "pass"<<std::endl;
        errors= false;
    }
    else {
        std::cout << "FAIL:" << numErrors << " errors in double Capacity Test" << std::endl;
        errors = true;
    }
    //clear memory
    for (int i=0;i<100; i++){
        delete testList.removeTaskById(i);
    }
    return errors;
}

bool Tester::rangeErrorTests(){
    bool errors = false;
    ArrayList list = ArrayList();
    Task* t1 = new Task(76543,"This is a test");
    list.addToList(t1);
    std::cout << ("Testing out of range errors:\n");
    try {
        list.removeValueAt(100);
        std::cout << ("Failed on removing big index\n");
        errors = true;
    } catch(std::out_of_range& e) {

    }
    try {
        list.removeValueAt(-5);
        std::cout << ("Failed on removing negative index\n");
        errors = true;
    } catch(std::out_of_range& e) {

    }
    try {
        list.getValueAt(100);
        std::cout << ("Failed on getting big index\n");
        errors = true;
    } catch(std::out_of_range& e) {

    }
    try {
        list.getValueAt(-5);
        std::cout << ("Failed on getting negative index\n");
        errors = true;
    } catch(std::out_of_range& e) {

    }
    if (!errors){
        std::cout << "pass"<<std::endl;
    }
    //clear memory
    for(int i = 0; i < list.itemCount();i++){
        delete list.getTaskByIndex(i);
    }
    return errors;
}


bool Tester::insertAtTester(){
    std::cout << ("\nTesting insertAt:\n");
    //std::cout << ("Adding to a bunch of indexes\n");
    //fill up a list with 1-5
    bool errors = false;
    ArrayList tester = ArrayList();
    for (int j = 0; j < 5; j++) {
        Task* testTask = new Task(j,"testTask");
        tester.insertAtEnd(testTask);
    }
    for (int i = 5; i > -1; i--) {
        Task* testTask = new Task(i,"testTask");
        tester.insertAt(testTask, i);
    }
    for (int i=0; i < tester.itemCount()-1; i+=2) {
        if (tester.getValueAt(i)->getId() != tester.getValueAt(i+1)->getId()) {
            errors = true;
            std::cout << ("FAIL: Two tasks do not match\n");
        }
    }
    if (!errors){
        std::cout << "pass"<<std::endl;
    }
    //clear memory
    for(int i = 0; i < tester.itemCount();i++){
        delete tester.getTaskByIndex(i);
    }
    return errors;
}

bool Tester::testCopyConstructor(){
    std::cout << ("\nTesting Copy Constructor\n");
    int numErrors = 0;
    //create object, add some stuff
    ArrayList original;
    for (int i=0; i<4; i++){
        Task* testTask = new Task(i,"testTask");
        original.insertAtEnd(testTask);
    }
    //copy it
    std::cout<<"test1"<<std::endl;
    ArrayList copy = ArrayList(original);
    std::cout<<"test2"<<std::endl;
    //check they're the same
    if (!(original.toString() == copy.toString())){
        std::cout << "FAIL: error in copy checking toString" << std::endl;
        numErrors++;
    }
    //remove and add stuff to one
    original.removeValueAt(0);
    original.removeValueAt(0);
    Task* testTask = new Task(4,"testTask1");
    original.insertAtEnd(testTask);
    Task* testTask2 = new Task(5,"testTask2");
    original.insertAtEnd(testTask2);
    //check that they're different
    if (!( original.getTaskByIndex(0)->getId() == copy.getTaskByIndex(2)->getId())){
        std::cout << "FAIL: error in changing original, it is now:" <<original.toString() << std::endl;
        numErrors++;
    }
    if (!( original.getTaskByIndex(1)->getId() == copy.getTaskByIndex(3)->getId())){
        std::cout << "FAIL: error in changing original, it is now:" <<original.toString() << std::endl;
        numErrors++;
    }
    if (( original.getTaskByIndex(2)->getId() == copy.getTaskByIndex(2)->getId())){
        std::cout << "FAIL: error in changing original, it is now:" <<original.toString() << std::endl;
        numErrors++;
    }
    if (( original.getTaskByIndex(3)->getId() == copy.getTaskByIndex(3)->getId())){
        std::cout << "FAIL: error in changing original, it is now:" <<original.toString() << std::endl;
        numErrors++;
    }

    //When this function ends, they'll both be deleted, which will check they don't have shared memory
    while(!original.isEmpty()){
        delete original.removeValueAt(0);
    }
    if (numErrors == 0){
        std::cout << "pass"<<std::endl;
        return false;
    } else {
        return true;
    }
}

bool Tester::testAssnOperator(){
    std::cout << ("\nTesting Assignment Operator\n");
    int numErrors = 0;
    //create object, add some stuff
    std::cout << "Fill two ArrayLists with different Tasks" << std::endl;
    ArrayList original;
    for (int i=0; i<4; i++){
        Task* testTask = new Task(i,"testTask");
        original.insertAtEnd(testTask);
    }
    //create a new list with its own data
    ArrayList listToSet;
    for (int i=10; i<14; i++){
        Task* testTask = new Task(i,"testTask");
        listToSet.insertAtEnd(testTask);
    }
    std::cout << "Test assignment operator" << std::endl;

    //assign the original to the new
    listToSet = original;

    //check they're the same
    std::cout << "check that they are the same" << std::endl;
    if (!(original.toString() == listToSet.toString())){
        std::cout << "FAIL: error in copy checking toString" << std::endl;
        numErrors++;
    }
    std::cout << "check that they are looking at different Memory:" << std::endl;
    if( &original == &listToSet ){
        numErrors++;
        std::cout <<"FAIL: Array's are looking at the same Memory Addresses" << std::endl;
    } else{
        std::cout << "pass" <<std::endl;
    }
    //remove and add stuff to one
    std::cout << "remove first two tasks from list1" << std::endl;
    original.removeValueAt(0);
    original.removeValueAt(0);
    std::cout << "fill it with two more Tasks" << std::endl;
    Task* testTask = new Task(4,"testTask1");
    original.insertAtEnd(testTask);
    Task* testTask2 = new Task(5,"testTask2");
    original.insertAtEnd(testTask2);

    std::cout << "check they do not match" << std::endl;
    //check that they're different
    for(int i = 0; i < original.itemCount(); i++){
        if(original.getValueAt(i)->getId() == listToSet.getValueAt(i)->getId()){
            std::cout << "FAIL: the Lists are pointing at the same Task" << std::endl;
            numErrors++;
        }
    }
    //check that there is no bad effect if you set an object to itself
    std::cout << "try assigning an object to itself" << std::endl;
    try{
        original = original;
    } catch (std::exception){
        numErrors++;
    }
    try{
        listToSet = listToSet;
    } catch (std::exception) {
        numErrors++;
    }

    if (numErrors == 0){
        std::cout << "pass"<<std::endl;
    }

    if (numErrors == 0 ) {
        return false;
    } else{
        return true;
    }
}


bool Tester::testLinkedList() {
    bool error1 = false;
    error1 = removeValueAtLLTest();

    std::cout<<" ---- Linked List Tests Complete ----"<<std::endl;

    if (error1) { // if a test failed return false
        return false;
    } else { //else all tests passed because there were no errors
        return true;
    }

}
bool Tester::testArrayList(){
    bool error1,error2,error3,error4,error5 = false;
    error1 = doubleCapacityTest();
    error2 = rangeErrorTests();
    error3 = insertAtTester();
    error4 = testCopyConstructor();
    error5 = testAssnOperator();
    //if any tests have an error, return false for testArrayList
    std::cout<<" ---- Array List Tests Complete ----"<<std::endl;
    if(error1 || error2 || error3 || error4 || error5){
        return false;
    }else{
        return true;
    }
}
bool Tester::testAll(){
    std::cout << ("\n*************************\n*********TESTER:*********\n*************************");
    if(testLinkedList() && testArrayList()){
        return true;
    }else{
        return false;
    }

}