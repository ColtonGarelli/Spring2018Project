//
// Created by Colton Garelli on 12/15/17.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "Controller.h"
#include "Task.h"




//could use controller objects to have different projects/lists
Controller::Controller(){
    ArrayList* masterView= nullptr;
    int uniqueID = 0;
    TaskLinkedList* masterList= nullptr;
    ArrayList* thisView= nullptr;
    Task* taskToMod=nullptr;
}


void Controller::runTaskManager(){
    masterList=readFile();
    std::cout << "\nImporting from last session:\n" << masterList->toString() << "\n\n";
    int userDirection=-1;
    //must create empty list of tasks, add first task to that
    //add to task
    masterView = new ArrayList(masterList);
    while (userDirection != 0) {
        masterView = new ArrayList(masterList);
        userDirection = optionEntry();
        if (userDirection == 1) {
            Task* newTask=taskIn();
//            uniqueID++;
            masterList->addToList(newTask);
        }
            //complete tasks
        else if (userDirection == 2) {
            view();
        }
        delete masterView;
        masterView= nullptr;
        // enter 0 to quit program
    }
    int toDelete=-1;
    std::cout<<"Would you like to delete any tasks before quitting?"
            "\n\nEnter\n"
            "1: To delete tasks\n"
            "0: To quit program"<<std::endl;
    while(toDelete!=0) {
        toDelete=intEntry();
        while (toDelete>1||toDelete<0){
            std::cout<<"\nPlease Enter\n"
                    "1: To delete tasks\n"
                    "0: To exit Task Manager.\n"<<std::endl;
            toDelete=intEntry();
        }while(toDelete!=0) {
            if(!viewAll())
            {
                taskToChange();
                Task* taskRemoved= masterList->removeTaskById(taskToMod->getId());
                //taskToMod = nullptr;
                std::cout<<"\n\nTask deleted:\n"<<taskRemoved->toString()<<std::endl;
                std::cout << "Would you like to delete any more tasks before quitting?\n\nEnter\n"
                        "1: To delete another task.\n"
                        "0: To quit" << std::endl;
            }else{
                std::cout<<"\n\n\nThere are no tasks in the Task Manager."<<std::endl;
                toDelete=0;
            }
            toDelete=intEntry();
        }
    }

    //upon quit writes to file

    writeFile(masterList);
    std::cout << "\n\nThank you for using the JTC TaskManager." << std::endl;
}


void Controller::view(){
    int viewRequest=-1;
    while(viewRequest!=0) {
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
//        else if(viewRequest!=0){
////            std::cout<<"The list is empty."<<std::endl;
//        }
    }
}

bool Controller::viewAll(){
    if(masterList!= nullptr) {
        thisView=masterView;
        std::cout << "All Tasks:\n\n" << thisView->toString() << std::endl;
        return false;
    }else{
        return true;
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
        std::cout << "Tomorrow's Tasks:\n\n" << thisView->toString() << std::endl;
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
            if(taskToMod != nullptr){
                if (taskToMod->getComplete()) {
                    std::cout << taskToMod->getTitle() << " has already been completed\nCompletion status unchanged" << std::endl;
                } else {
                    taskToMod->toggleTaskCompletion();
                    std::cout << taskToMod->getTitle() << " is now complete" << std::endl;
                }
            }
            std::cout<<"__The Current View__\n"<<thisView->toString()<<std::endl;
        }
        else if (action == 2) {
            taskToChange();
            if(taskToMod != nullptr){
                editTask();
//                std::cout << taskToMod->toString() << std::endl;
            } else{
                std::cout << "Stopping Task Modification" << std::endl;
            }
            std::cout<<"__The Current View__\n"<<thisView->toString()<<std::endl;

        }
//        std::cout<<'\n'<<thisView->toString()<<std::endl;

    }
}


//User can choose to complete, edit, or return to view
int Controller::modifier(){
    std::cout<<"||To complete a task enter 1\n"
            "||To edit a task enter 2\n"
            "||To return to view selection enter 0"<<std::endl;
    int userIn=intEntry();
    if(userIn!=0) {
//        std::cout << thisView->toString() << std::endl;
        while (userIn > 2 || userIn < 0) {
            std::cout << thisView->toString() << std::endl;
            std::cout
                    << "Invalid Entry.\n||To complete a task enter 1\n"
                            "||To edit a task enter 2\n"
                            "||To return to view selection enter 0"
                    << std::endl;
            userIn = intEntry();
        }
    }
    return userIn;
}


//select which task of the list displayed to change
void Controller::taskToChange(){
    std::cout<<"Enter the number associated with a task,"
            " or enter 0 to exit"<<std::endl;
    int taskSelect=intEntry();
    //repeat command if the number is not between 0 and length of list
    while(taskSelect>(thisView->itemCount()) ||taskSelect<0){
        std::cout<<"Invalid Entry.\n"
                "Enter the number associated with a task,"
                " or enter 0 to exit"<<std::endl;
        taskSelect=intEntry();
    }
    if (taskSelect != 0 ){ //check if user entered 0
        taskToMod=thisView->getTaskByIndex(taskSelect-1);
    } else {//if 0 entered just finish function
        taskToMod = nullptr;
    }
}


//User in: which parameter to change, and edits that task
void Controller::editTask(){
    int pToChange=-1;
    std::cout <<"---Current Task Selected:---\n\t" << taskToMod->toPrint() <<std::endl;
    while(pToChange!=0){
        std::cout<<"Enter\n1: Change task title\n"
                "2: Change task due date\n"
                "3: Change task priority\n"
                "4: Change completion status\n"
                "0: Return to list view"<<std::endl;
        pToChange=intEntry();
        while(pToChange>4||pToChange<0){
            std::cout<<"\nInvalid entry.\n\n"
                    "Enter\n"
                    "1: Change task title\n"
                    "2: Change task due date\n"
                    "3: Change task priority\n"
                    "4: Change completion status\n"
                    "0: To go back to view"<<std::endl;
            pToChange=intEntry();
        }
        if(pToChange==1){
            std::string inTitle;
            std::string input;
            std::cout<<"Please don't use commas.\n\nEnter a new task name: "<<std::endl;
            std::getline(std::cin>>inTitle,input);
            inTitle+=input;
            bool commas = hasCommas(inTitle+input);
            while(commas) {
                commas= false;
                std::cout<<"I'm sorry, Please don't use commas.\n\nEnter the new task name: "<<std::endl;
                std::getline(std::cin >> inTitle, input);
                commas = hasCommas(inTitle + input);
            }
            taskToMod->setTitle(inTitle);
            std::cout << ">>>Title Updated to: \"" << taskToMod->getTitle() << "\"<<<"<< std::endl;
        }//change due date
        else if(pToChange==2){
            std::cout << "Enter new due date: " << std::endl;
            taskToMod->setDueDate(intEntry());
            std::cout << ">>>Dated Updated, Task now due in : " << taskToMod->getDueDate() << " day(s) <<<" << std::endl;
        }//change priority
        else if(pToChange==3) {
            std::cout << "Enter new priority: " << std::endl;
            int priority = intEntry();
            while(priority>5||priority<1){
                std::cout << "Please enter a valid priority: " << std::endl;
                priority = intEntry();
            }
            taskToMod->setPriority(priority);
            std::cout << ">>>Priority Updated to: " << taskToMod->getPriority() << "<<<" << std::endl;
        }
        else if(pToChange==4){
            taskToMod->toggleTaskCompletion();
            std::cout << ">>>Task Completion is now: " << std::to_string(taskToMod->getComplete()) << "<<<" << std::endl;

        }
    }
}


//add a task to the master list
Task* Controller::taskIn(){
    std::string inTitle;
    std::string input;
    //print directions
    bool commas= true;
    while(commas) {
        commas= false;
        std::cout<<"Please don't use commas.\n\nEnter a task name: "<<std::endl;
        std::getline(std::cin >> inTitle, input);
        inTitle = inTitle + input;
        for (int i = 0; i < inTitle.size(); i++) {
            if (inTitle[i] == ',') {
                commas= true;
                i=inTitle.size();
            }
        }
    }
    std::cout << "Enter days until due: " << std::endl;
    int dueDate = intEntry();
    std::cout<<"Enter priority: 1-5, 5 being top priority, 1 being low"<<std::endl;
    int priority=intEntry();
    while(priority>5 || priority<1){
        std::cout<<"Please enter a number 1-5"<<std::endl;
        priority=intEntry();
    }
    uniqueID+=1;
    Task *newTask = new Task(uniqueID, inTitle, dueDate, priority);
    std::cout<<">>>Task Added to List<<<"<<std::endl;
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

bool Controller::hasCommas(const std::string &inString) const {
    bool commas;
    for (int i = 0; i < inString.size(); i++) {
        if (inString[i] == ',') {
            commas = true;
            i = inString.size(); // automatically ends the loop
        }
    }
    return commas;
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
    while (userDirection < 0 || userDirection > 2) {
        std::cout << "Invalid entry."
                  << std::endl;
        userDirection = optionEntry();
    }
    return userDirection;
}


//reads file in to masterList
TaskList* Controller::readFile(){
    TaskList* masterList = new TaskLinkedList();
    int maxId=1;
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
                if(idIn > maxId){
                    maxId = idIn;
                }
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
                masterList->addToList(newTask);
            }
        }
    }
    fin.close();
//    for(int i=0;i<masterList->itemCount();i++){
//        if(maxId>uniqueID) {
//            maxId = (masterList->getTaskByIndex(i)->getId());
//        }
//    }
    uniqueID=maxId;
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
        std::cout<<"Error in opening file. Please contact Jeremy Taylor or Colton";
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