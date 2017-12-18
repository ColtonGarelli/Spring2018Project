//
// Created by Jeremy Block on 12/18/17.
//

#include <iostream>
#include "LinkedListTester.h"
#include "Task.h"
#include "TaskList.h"
#include "TaskLinkedList.h"

bool LinkedListTester::removeValueAtLLTest() {
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

bool LinkedListTester::TestLinkedList() {
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