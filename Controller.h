//
// Created by Colton Garelli on 12/15/17.
//

#ifndef PRO_JECT_CONTROLLER_H
#define PRO_JECT_CONTROLLER_H


#include "TaskList.h"
#include "TaskLinkedList.h"
#include "ArrayList.h"
#include "Task.h"


class Controller {
private:

    int uniqueID=0;
    TaskList* masterList;
    //thisView must always be deleted and set back to nullptr
    ArrayList* thisView;
    ArrayList* masterView;
    Task* taskToMod;



public:

    Controller();

    void taskHandler();

    void runStuff();

    TaskList* readFile(int uniqueID);

    void printPartsToFile(std::string lineToPrint, char delimiter);

    void writeFile(TaskList* masterList);

    int intEntry();

    int optionEntry();

    Task* taskIn(int& uniqueID);

    void parameterToChange();

    void editTask(int taskToChange);

    int selectView();

    void view();

    void viewToday();
    void viewIncomplete();
    void viewTomorrow();
    void viewComplete();
    void viewThisWeek();

    void taskToChange();

    int modifier();

};


#endif //PRO_JECT_CONTROLLER_H
