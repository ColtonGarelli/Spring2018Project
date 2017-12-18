#include <iostream>
#include "Controller.h"


void doubleCapacityTest(){
    std::cout << ("\nTesting Double Capacity\n");
    int numErrors = 0;
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
    }
    else {
        std::cout << "FAIL:" << numErrors << " errors in double Capacity Test" << std::endl;
    }
    //clear memory
    for (int i=0;i<100; i++){
        delete testList.removeTaskById(i);
    }
}
void rangeErrorTests(ArrayList& list){
    bool errors = false;
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
    errors = false;
}


void insertAtTester(){
    std::cout << ("\nTesting insertAt:\n");
    //std::cout << ("Adding to a bunch of indexes\n");
    //fill up a list with 1-5
    bool errors = false;
    ArrayList tester;
    for (int j = 0; j < 5; j++) {
        Task* testTask = new Task(j,"testTask");
        tester.insertAtEnd(testTask);
    }
    for (int i = 5; i > -1; i--) {
        Task* testTask = new Task(i,"testTask");
        tester.insertAt(testTask, i);
    }
    //std::cout << tester.toString() <<std::endl;
    for (int i=0; i < tester.itemCount()-1; i+=2) {
        //std::cout << tester.get(i) <<std::endl;
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
}

void testCopyConstructor(){
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
    if (numErrors == 0){
        std::cout << "pass"<<std::endl;
    }
    //When this function ends, they'll both be deleted, which will check they don't have shared memory
    while(!original.isEmpty()){
        delete original.removeValueAt(0);
    }
}

void testAssnOperator(){
    std::cout << ("\nTesting Assignment Operator\n");
    int numErrors = 0;
    //create object, add some stuff
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
    //assign the original to the new
    std::cout<<"test1Operator"<<std::endl;
    listToSet = original;
    std::cout<<"test2Operator"<<std::endl;

    //check they're the same
    if (!(original.toString() == listToSet.toString())){
        std::cout << "FAIL: error in copy checking toString" << std::endl;
        numErrors++;
    }
    //remove and add stuff to one
    std::cout<<"test3Operator"<<std::endl;
    original.removeValueAt(0);
    std::cout<<"test4Operator"<<std::endl;
    original.removeValueAt(0);
    std::cout<<"test5Operator"<<std::endl;
    Task* testTask = new Task(4,"testTask1");
    original.insertAtEnd(testTask);
    std::cout<<"test6Operator"<<std::endl;
    Task* testTask2 = new Task(5,"testTask2");
    original.insertAtEnd(testTask2);
    std::cout<<"test7Operator"<<std::endl;
    //check that they're different
    if (!( original.toString() == "{2, 3, 4, 5}")){
        std::cout<<"test8Operator"<<std::endl;
        std::cout << "FAIL: error in changing original, it is now:" <<original.toString() << std::endl;
        numErrors++;
    }
    if (!( listToSet.toString() == "{0, 1, 2, 3}")){
        std::cout<<"test9Operator"<<std::endl;
        std::cout << "FAIL: error in copy after changes, it is now" << listToSet.toString() <<  std::endl;
        numErrors++;
    }

    //check that there is no bad effect if you set an object to itself
    std::cout<<"test10Operator"<<std::endl;
    original = original;
    std::cout<<"test11Operator"<<std::endl;
    listToSet = listToSet;
    std::cout<<"test12Operator"<<std::endl;

    if (numErrors == 0){
        std::cout << "pass"<<std::endl;
        std::cout<<"test13Operator"<<std::endl;
    }
    //When this function ends, original and listToSet will both be deleted, which will check they don't have shared memory
//    delete original;
//    delete listToSet;
    std::cout << &original << std::endl;
    std::cout << &listToSet <<std::endl;
}

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





int main(){
    std::cout << ("\n*************************\nTESTER:\n");

    doubleCapacityTest();
    insertAtTester();
    testCopyConstructor();
    testAssnOperator();
    TestLinkedList();


    srand(time(NULL));
    std::cout << "Welcome to the JTC TaskManager\n" << std::endl;
    Controller UI = Controller();
    UI.runTaskManager();
    return 0;
}