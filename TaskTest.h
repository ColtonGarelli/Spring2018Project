//
// Created by Jeremy Block on 11/22/17.
//
/**
 * This is a class for testing functions about a task
 */


#ifndef PRO_JECT_TASKTEST_H
#define PRO_JECT_TASKTEST_H


#include <string>
#include "Task.h"

class TaskTest {
private:
    Task* activeTask;
public:

    /**
     *
     * @param title
     * @return
     */
    Task* CreateDefaultTaskTest(std::string title);

    /**
     *
     * @param title
     * @param dueDate
     * @return
     */
    Task* CreateDateTaskTest(std::string title, int dueDate);

    /**
     *
     * @param title
     * @param dueDate
     * @param duration
     * @return
     */
    Task* CreateFullTaskTest(std::string title, int dueDate, int duration);

    /**
     *
     * Must also verify that a task can not be due before it's dependancies. Should throw an error.
     * @return
     */
    Task* create3DependentTasksTest();

    /**
     *
     * @param firstTask
     */
    void CompleteTasksTest(Task* firstTask);

    /**
     * print a Task and it's dependants to the screen
     * @param firstTask
     */
    void PrintTasksTest(Task* firstTask);

    /**
     * Will try Mutating a passed task's values and will verify if all of it's children have also been changed.
     * @param myTask - a task to be mutated
     * @post myTask (and it's dependants) will be called "changedTask", be part of the 0 project, due on -1, and have a 0 duration.
     */
    void MutateTaskTest(Task* myTask);

};


#endif //PRO_JECT_TASKTEST_H
