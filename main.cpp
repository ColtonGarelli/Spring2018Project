#include <iostream>
#include "TaskLinkedList.h"
#include "TaskTest.h"
#include "List.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    List<Task>* masterList = new TaskLinkedList<Task>();
    return 0;
}