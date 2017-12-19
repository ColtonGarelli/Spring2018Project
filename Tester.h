//
// Created by Jeremy Block on 12/18/17.
//

#ifndef PRO_JECT_LINKEDLISTTESTER_H
#define PRO_JECT_LINKEDLISTTESTER_H


class Tester {

private:
    //linked List tests
    bool removeValueAtLLTest();
    //Array List tests
    bool doubleCapacityTest();
    bool rangeErrorTests();
    bool insertAtTester();
    bool testCopyConstructor();
    bool testAssnOperator();

public:
    bool testLinkedList();
    bool testArrayList();
    bool testAll();
};


#endif //PRO_JECT_LINKEDLISTTESTER_H
