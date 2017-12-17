//
// Created by Colton Garelli on 12/15/17.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "Controller.h"




//could use controller objects to have different projects/lists
Controller::Controller(){
    ArrayList* masterView= nullptr;
    int uniqueID = 0;
    TaskList* masterList= nullptr;
    ArrayList* thisView= nullptr;
    Task* taskToMod=nullptr;


}

//responsible for deleting arrayLists
void Controller::runStuff(){
    masterList=readFile(uniqueID);
    std::cout << "\nImporting from last session:\n" << masterList->toString() << "\n\n";
    int userDirection=-1;
    //must create empty list of tasks, add first task to that
    //add to task
    while (userDirection != 0) {
        userDirection = optionEntry();
        if (userDirection == 1) {
            Task* newTask=taskIn(uniqueID);
            uniqueID++;
            masterList->addToList(newTask);
        }
            //complete tasks
        else if (userDirection == 2) {
            view();
        }
        // enter 0 to quit program
    }
    //upon quit writes to file
    writeFile(masterList);
    std::cout << "\n\nThank you for using the JTC TaskManager." << std::endl;
}


void Controller::view(){
    int viewRequest=-1;
    while(viewRequest!=0) {
        masterView = new ArrayList(masterList);
        thisView = new ArrayList();
        viewRequest = selectView();
        bool empty= true;
        if (viewRequest == 1) {
            empty=viewToday();
        }//tomorrow's tasks
        else if (viewRequest == 2) {
            empty=viewTomorrow();

        } else if (viewRequest == 3) {
            empty=viewThisWeek();

        } else if (viewRequest == 4) {
            empty=viewIncomplete();

        }//view completed tasks
        else if (viewRequest == 5) {
            empty=viewComplete();
        }
        if(!empty) {
            taskHandler();
            delete thisView;
            thisView = nullptr;
            taskToMod = nullptr;
        }
        else if(viewRequest!=0){
            std::cout<<"The list is empty."<<std::endl;
        }
    }
}


bool Controller::viewIncomplete(){
    for (int i = 0; i < masterView->itemCount(); i++) {
        if (!masterView->getTaskByIndex(i)->getComplete()) {
            thisView->addToList(masterView->getTaskByIndex(i));
        }
    }if (thisView->itemCount() == 0) {
        std::cout<<"No incomplete tasks."<<std::endl;
        return true;
    }else {
        std::cout << "All Incomplete Tasks:\n\n" << thisView->toString() << std::endl;
        return false;
    }
}

bool Controller::viewToday() {
    for (int i = 0; i < masterView->itemCount(); i++) {
        if (masterView->getTaskByIndex(i)->getDueDate() == 0 && !masterView->getTaskByIndex(i)->getComplete()) {
            thisView->addToList(masterView->getTaskByIndex(i));
        }
    }
    if (thisView->itemCount() == 0) {
        std::cout << "No tasks due today." << std::endl;
        return true;
    }else {

        std::cout << "Today's Tasks:\n\n" << thisView->toString() << std::endl;
        return false;
    }
}

bool Controller::viewTomorrow() {
    for (int i = 0; i < masterView->itemCount(); i++) {
        if (masterView->getTaskByIndex(i)->getDueDate() == 1 && !masterView->getTaskByIndex(i)->getComplete()) {
            thisView->addToList(masterView->getTaskByIndex(i));
        }
    }
    if (thisView->itemCount() == 0) {
        std::cout << "No tasks due tomorrow." << std::endl;
        return true;
    }else {
        std::cout << "Tomoorow's Tasks:\n\n" << thisView->toString() << std::endl;
        return false;
    }
}

bool Controller::viewComplete() {

    for (int i = 0; i < masterView->itemCount(); i++) {
        if (masterView->getTaskByIndex(i)->getComplete()) {
            thisView->addToList(masterView->getTaskByIndex(i));
        }
    }
    if (thisView->itemCount() == 0) {
        std::cout<<"No complete tasks."<<std::endl;
        return true;
    } else {
        std::cout << "Completed Tasks:\n\n" << thisView->toString() << std::endl;
        return false;
    }
}

bool Controller::viewThisWeek() {
    for (int i = 0; i < masterView->itemCount(); i++) {
        if (masterView->getTaskByIndex(i)->getDueDate() < 7 && !masterView->getTaskByIndex(i)->getComplete()) {
            thisView->addToList(masterView->getTaskByIndex(i));
        }
    }
    if (thisView->itemCount() == 0) {
        std::cout << "No tasks due this week." << std::endl;
        return true;
    } else {
        std::cout << "This Week's Tasks:\n\n" << thisView->toString() << std::endl;
        return false;
    }
}

//completes task or calls parameterChange to edit tasks
void Controller::taskHandler(){
    //choose complete or edit
    int action=-1;
    while(action!=0) {
        action=modifier();
        if (action == 1) {
            //selects task, editTask uses taskToMod to access
            taskToChange();
            if (taskToMod->getComplete()) {
                std::cout << "This task has already been completed\n" << std::endl;
                std::cout << taskToMod->toString() << std::endl;
            } else {
                taskToMod->completeTask();
                std::cout << taskToMod->toString() << std::endl;
            }
        }
        else if (action == 2) {
            taskToChange();
            editTask();
            std::cout << taskToMod->toString() << std::endl;
        }
        std::cout<<thisView->toString()<<std::endl;
    }
}


//User can choose to complete, edit, or return to view
int Controller::modifier(){
    std::cout<<"To complete a task enter 1\n\n"
            "To edit a task enter 2\n\n"
            "To return to view enter 0"<<std::endl;
    int userIn=intEntry();
    if(userIn!=0) {
        std::cout << thisView->toString() << std::endl;
        while (userIn > 2 || userIn < 0) {
            std::cout << thisView->toString() << std::endl;
            std::cout
                    << "Invalid Entry.\nTo complete a task enter 1\n\n"
                            "To edit a task enter 2\n\n"
                            "To return to view enter 0"
                    << std::endl;
            userIn = intEntry();
        }
    }
    return userIn;
}


//select which taask of the list displayed to change
void Controller::taskToChange(){
    std::cout<<"Enter the number associated with a task,"
            " or enter 0 to exit"<<std::endl;
    int taskSelect=intEntry();
    while(taskSelect>(thisView->itemCount()) ||taskSelect<0){
        std::cout<<"Invalid Entry.\n"
                "Enter the number associated with a task,"
                " or enter 0 to exit"<<std::endl;
        taskSelect=intEntry();
    }
    taskToMod=thisView->getTaskByIndex(taskSelect-1);
}


//User in: which parameter to change, and edits that task
void Controller::editTask(){
    int pToChange=-1;
    while(pToChange!=0){
        std::cout<<"Enter\n1: Change task title\n"
                "2: Change task due date\n"
                "3: Change task priority\n"
                "0: Return to list view"<<std::endl;
        pToChange=intEntry();
        while(pToChange>3||pToChange<0){
            std::cout<<"\nInvalid entry.\n\n"
                    "Enter\n"
                    "1: Change task title\n"
                    "2: Change task due date\n"
                    "3: Change task priority\n"
                    "0: To go back to view"<<std::endl;
            pToChange=intEntry();
        }
        if(pToChange==1){
            std::string inTitle;
            std::string input;
            std::cout<<"Enter a new task name: "<<std::endl;
            std::getline(std::cin>>inTitle,input);
            taskToMod->setTitle(inTitle);
        }//change due date
        else if(pToChange==2){
            std::cout << "Enter new due date: " << std::endl;
            taskToMod->setDueDate(intEntry());
        }//change priority
        else if(pToChange==3) {
            std::cout << "Enter new priority: " << std::endl;
            int priority = intEntry();
            while(priority>5||priority<1){
                std::cout << "Please enter a valid priority: " << std::endl;
                priority = intEntry();
            }
            taskToMod->setPriority(priority);
        }
    }
}


//add a task to the master list
Task* Controller::taskIn(int& uniqueID){
    std::string inTitle;
    std::string input;
    //print directions
    std::cout << "Enter the name of the task: " << std::endl;
    std::getline(std::cin >> inTitle, input);
    inTitle = inTitle + input;
    std::cout << "Enter days until due: " << std::endl;
    int dueDate = intEntry();
    std::cout<<"Enter priority: 1-5"<<std::endl;
    int priority=intEntry();
    while(priority>5 || priority<1){
        std::cout<<"Please enter a number 1-5, 5 being top priority, 1 being low"<<std::endl;
        priority=intEntry();
    }
    int ID = uniqueID;
    Task *newTask = new Task(ID, inTitle, dueDate, priority);
    return newTask;
}


//select the desired ArrayList (view)
int Controller::selectView() {
    std::cout << "Enter\n1: To view today's tasks\n"
            "2: To view tomorrow's tasks\n"
            "3: To view this week's tasks\n"
            "4: To view all incomplete tasks\n"
            "5: To view all completed tasks\n"
            "0: To return to menu" << std::endl;
    int userIn = intEntry();
    while (userIn > 5 || userIn < 0) {
        std::cout << "Enter\n1: To view today's tasks\n"
                "2: To view tomorrow's tasks\n"
                "3: To view this week's tasks\n"
                "4: To view all incomplete tasks\n"
                "5: To view all completed tasks\n"
                "0: To return to menu" << std::endl;
        userIn = intEntry();
    }
    return userIn;
}

//generic integer entry function to make sure ints are entered
int Controller::intEntry(){
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


//select adding a task, viewing a task, or quit the program
int Controller::optionEntry() {
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
    }//print statement from here kind of weird consider changing
    while (invalid) {
        std::cout << "\nPlease enter a valid number.\n"
                "Enter 1 to add a new task, 2 to view tasks, 0 to quit: " << std::endl;
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


//reads file in to masterList
TaskList* Controller::readFile(int uniqueID){
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
                std::stringstream makeID(holder);
                makeID >> idIn;
                getline(parts, holder, delimiter);
                std::string title = holder;
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
                Task *newTask = new Task(idIn, title, dueDate, priority,complete);
                uniqueID = idIn+1;
                masterList->addToList(newTask);
            }
        }
    }
    fin.close();
    return masterList;
}


//creates strings to write to file
void Controller::printPartsToFile(std::string lineToPrint, char delimiter){
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


//writes to file
void Controller::writeFile(TaskList* masterList){
    //ArrayList passed in should be master
    std::string line;//=(std::to_string(masterList->itemCount())+" ");
    for(int i =0; i<masterList->itemCount(); i++){
        Task* taskToCopy=masterList->getTaskByIndex(i);
        line+=std::to_string(taskToCopy->getId());
        line +=","+taskToCopy->getTitle();
        line+=","+std::to_string(taskToCopy->getDueDate());
        line+=","+std::to_string(taskToCopy->getPriority());
        line+=","+std::to_string(taskToCopy->getComplete())+"\n";

    }
    printPartsToFile(line,'\n');


}