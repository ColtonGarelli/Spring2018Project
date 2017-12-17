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

    int uniqueID;
    TaskList* masterList;
    //thisView must always be deleted and set back to nullptr
    ArrayList* thisView;
    ArrayList* masterView;
    Task* taskToMod;



public:

    Controller();

    void taskHandler();

    void runTaskManager();

    TaskList* readFile();

    void printPartsToFile(std::string lineToPrint, char delimiter);

    void writeFile(TaskList* masterList);

    int intEntry();

    int optionEntry();

    Task* taskIn();

    void editTask();

    int selectView();

    void view();

    bool viewAll();

    bool viewToday();
    bool viewIncomplete();
    bool viewTomorrow();
    bool viewComplete();
    bool viewThisWeek();

    void taskToChange();

    int modifier();

};


#endif //PRO_JECT_CONTROLLER_H
