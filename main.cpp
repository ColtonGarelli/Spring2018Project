#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "TaskList.h"
#include "ArrayList.h"
#include "TaskLinkedList.h"
#include "Controller.h"


//
//
//TaskList* readFile(int& uniqueID){
//    TaskList* masterList = new TaskLinkedList();
//    std::string textIn;
//    std::ifstream fin("storetasks.txt");
//    while (!fin.eof()) {
//        getline(fin, textIn);
//        std::stringstream parts(textIn);
//        char delimiter = ',';
//        std::string string;
//        while (parts) {
//            std::string holder;
//            getline(parts, holder, delimiter);
//            if (holder == ""){}
//            else {
//                int idIn;
//                std::stringstream makeID(holder);
//                makeID >> idIn;
//                getline(parts, holder, delimiter);
//                std::string title = holder;
//                int dueDate;
//                getline(parts, holder, delimiter);
//                std::stringstream makeDue(holder);
//                makeDue >> dueDate;
//                int priority;
//                getline(parts, holder, delimiter);
//                std::stringstream priorityS(holder);
//                priorityS >> priority;
//                bool complete;
//                getline(parts, holder, delimiter);
//                std::stringstream makeComplete(holder);
//                makeComplete >> complete;
//                Task *newTask = new Task(idIn, title, dueDate, priority,complete);
//                uniqueID = idIn+1;
//                masterList->addToList(newTask);
//            }
//        }
//    }
//    fin.close();
//    return masterList;
//}
//
//
//
//
//
//void printPartsToFile(std::string lineToPrint, char delimiter){
//    std::ofstream fout("storetasks.txt"); //writes to file storetasks.txt
//    if(fout){
//        std::stringstream parts(lineToPrint);
//        while(parts){
//            std::string part;
//            getline(parts,part,delimiter);
//            fout<<part<<std::endl;
//        }
//        fout.close();
//    }
//    else{
//        std::cout<<"error in opening parts";
//    }
//
//
//}
//
//
//
//
//void writeFile(TaskList* masterList){
//    //ArrayList passed in should be master
//    std::string line;//=(std::to_string(masterList->itemCount())+" ");
//    for(int i =0; i<masterList->itemCount(); i++){
//        Task* taskToCopy=masterList->getTaskByIndex(i);
//        line+=std::to_string(taskToCopy->getId());
//        line +=","+taskToCopy->getTitle();
//        line+=","+std::to_string(taskToCopy->getDueDate());
//        line+=","+std::to_string(taskToCopy->getPriority());
//        line+=","+std::to_string(taskToCopy->getComplete())+"\n";
//
//    }
//    printPartsToFile(line,'\n');
//
//
//}
//
//
//int userDirection(int someInt){
//
//}
//int intEntry(){
//    int userDirection=-1;
//    std::string userString;
//    std::cin >> userString;
//    std::stringstream convertor;
//    convertor << userString;
//    convertor >> userDirection;
//    bool invalid=false;
//    if(convertor.fail()){
//        invalid=true;
//    }
//    while(invalid) {
//        std::cout << "Please enter a valid number." << std::endl;
//        std::cin >> userString;
//        std::stringstream convertor;
//        convertor << userString;
//        convertor >> userDirection;
//        if(convertor.fail()){
//            invalid=true;
//        }
//        else{
//            invalid=false;
//        }
//    }
//    return userDirection;
//
//}
//
//int optionEntry() {
//    int userDirection = -1;
//    std::cout << "Enter 1 to add a new task, 2 to view tasks, 0 to quit: " << std::endl;
//    std::string userString;
//    std::cin >> userString;
//    std::stringstream convertor;
//    convertor << userString;
//    convertor >> userDirection;
//    bool invalid = false;
//    if (convertor.fail()) {
//        invalid = true;
//    }
//    while (invalid) {
//        std::cout << "Please enter a valid number." << std::endl;
//        std::cout << "Enter 1 to add a new task, 2 to view tasks, 0 to quit: " << std::endl;
//        std::cin >> userString;
//        std::stringstream convertor;
//        convertor << userString;
//        convertor >> userDirection;
//        if (convertor.fail()) {
//            invalid = true;
//        } else {
//            invalid = false;
//        }
//    }
//    while (userDirection < 0 || userDirection > 3) {
//        std::cout << "Invalid entry."
//                  << std::endl;
//        userDirection = optionEntry();
//    }
//    return userDirection;
//}
//
//Task* taskIn(int& uniqueID){
//    std::string inTitle;
//    std::string input;
//    //print directions
//    std::cout << "Enter the name of the task: " << std::endl;
//    std::getline(std::cin >> inTitle, input);
//    inTitle = inTitle + input;
//    std::cout << inTitle << std::endl;
//    std::cout << "Enter days until due: " << std::endl;
//    int dueDate = intEntry();
//    std::cout<<"Enter priority: 1-5"<<std::endl;
//    int priority=intEntry();
//    while(priority>5 || priority<1){
//        std::cout<<"Please enter a number 1-5, 5 being top priority, 1 being low"<<std::endl;
//        priority=intEntry();
//    }
//    int ID = uniqueID;
//    Task *newTask = new Task(ID, inTitle, dueDate, priority);
//    return newTask;
//}
//
////make view that only adds certain tasks via parameters
//void selectView(ArrayList* masterList){
//    std::cout<<"Enter\n1: To view today's tasks\n2: To view tomorrow's tasks\n3: To view this week's tasks\n4: To view all tasks"
//}
//
////generic view
////handles asking user to enter which view they wnat, and if they'd like to edit a task or complete a task
//
//void view(TaskList* masterView){
//    TaskList *viewArrayList = new ArrayList(masterView);
//    //std::cout<<"View All:\n\n\nTo complete a task enter its respective number\nTo finish viewing enter '0'"<<std::endl;
//    std::cout << viewArrayList->toString()<<std::endl;
//    int taskSelect=viewHelper(masterView->itemCount());
//    int index=taskSelect-1;
//    int parameterTochange=0;
//    int paramaterToChange(masterView);
//
//    if (taskSelect!=0){
//        Task* modify = viewArrayList->getTaskByIndex(index);
//        int moveID= modify->getId();
//        std::cout<<"Task Completed:\n"<<taskSelect<<". "<<modify->toString()<<std::endl;
//        //archiveList->addToList(masterArrayList->removeTaskById(moveID));
//
//    }
//    else{
//        std::cout<<"View All closed"<<std::endl;
//    }
//
//}
//
//
//
//
//
//
//
//void Controller() {
//
//    TaskList *archiveList = new ArrayList();
//    int uniqueID = 0;
//    TaskList* masterList = readFile(uniqueID);
//    TaskList *masterArrayList = view(masterList,)
//    std::cout << "\nImporting from last session:\n" << masterList->toString() << "\n\n";
//    int userDirection=-1;
//    //must create empty list of tasks, add first task to that
//    //add to task
//    while (userDirection != 0) {
//        userDirection = optionEntry();
//        if (userDirection == 1) {
//            Task* newTask=taskIn(uniqueID);
//            uniqueID++;
//            masterList->addToList(newTask);
//            masterArrayList->addToList(newTask);
//        }
//            //view all tasks
//        else if (userDirection == 2) {
//            viewAll(masterList,masterArrayList,archiveList);
//        }//view today
//
//        // enter 0 to quit program
//    }
//    //upon quit writes to file
//    writeFile(masterList);
//    std::cout << "\n\nThank you for using the JTC TaskManager." << std::endl;
//}




int main(){
    srand(time(NULL));
    std::cout << "Welcome to the JTC TaskManager\n" << std::endl;
//    TaskList* fileRead = readFile();
//    std::cout << fileRead->toString() << "\n\n";
    /*
     * todo: write views---for each view allow user to mark complete (and move to archive list)
     * todo: write demo code
     */

     Controller UI = Controller();
    UI.runStuff();

//    if(TestLinkedList() && TestArrayList()) {
//        PrototypeController();
//    }
    //Task::Task(std::string inTitle="newTask", int inDue=1, bool inTaskComplete=false, int inIdNum=-1)
//    Task* myTask = new Task("task1",1,false,-1);
//    std::string title = myTask->getTitle();
//    std::cout<< title <<std::endl;
    return 0;
}