//
// Created by Jeremy Block on 11/21/17.
// Modified by Jeremy Block on 12/09/17
//

#ifndef PRO_JECT_TASK_H
#define PRO_JECT_TASK_H


#include <string>

class Task {
private:
    std::string title;
    //int duration;
    //Task* dependant;
    int dueDate;//days till due not including today (today = 0, tomorrow = 1, yesterday = -1)
    int priority; //Will be a number from 1-5
    bool completed; //true: task is done, false default
    int Id;


public:

//    //Default Constructor
//    Task();
//    //Basic Constructor
    Task(std::string title, int idNum);
    //Full Constructor
//    Task(std::string title, int due, int priority=1, int IdNum=0);
    //Assignment Operator
    Task& operator=(const Task& taskToCopy);

    void setTitle(std::string title);

    std::string getTitle();

    void setDueDate(int dueDate);

    int getDueDate();

    /**
     * @param priority - must be a number from 1 - 5
     * @throw std::out_of_range error if priority is not in range
     */
    void setPriority(int priority);

    int getPriority();
    /**
     * @post - task.completed = true
     * @return task.completed
     * @throws - todo Should do something?
     */
    bool completeTask();

    bool getComplete();

    void setId(int id);

    int getId();

//  int getDuration() const;
// void setDuration(int duration);
//Task* getDependant() const;
// void setDependant(Task* nextTask);
//  int calcPriority();

};


#endif //PRO_JECT_TASK_H
