//
// Created by Jeremy Block on 11/21/17.
//

#ifndef PRO_JECT_TASK_H
#define PRO_JECT_TASK_H


#include <string>

class Task {
private:
    //todo Define a Time class
    std::string title;
    std::string item;
    //int duration;
   // Task* dependant;
    //int* Project; //pointer to Parent Project
    int dueDate;//days till due not including today //todo Write and Replace int with TaskTime class
    //short Priority; //Will be a number from 1-4 (we could also define this as a char-8 bits-if we are trying to be space efficient)
    bool completed; //true: task is done, false default
    int Id;
    Task* next;


public:

    //Default
    Task();

    //Constructor
    Task(std::string title, int due, bool taskComplete, int IdNum);

    //Destructor
    ~Task();

    std::string getItem();



    //todo update these setters and getters as needed.
    const std::string &getTitle();

    void setTitle(const std::string &title);

    void setDueDate(int dueDate);

    int getDueDate();

    void setId(int Id);
    int getId();
    bool completeTask();
    bool getComplete();
    void setNext(Task* newNext);
    Task* getNext();



   // int getDuration() const;

   // void setDuration(int duration);

    //Task* getDependant() const;

   // void setDependant(Task* nextTask);

    short getPriority() const;

   // void setPriority(short Priority);

    // int calcPriority();

};


#endif //PRO_JECT_TASK_H
