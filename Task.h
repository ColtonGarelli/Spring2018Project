//
// Created by Jeremy Block on 11/21/17.
// Modified by Jeremy Block on 12/09/17
//

#ifndef PRO_JECT_TASK_H
#define PRO_JECT_TASK_H


#include <string>

class Bad_Task_Id : std::exception{};


class Task {
private:
    int Id;
    std::string title;
//    int duration;
    //Task* dependant;
    int dueDate;//days till due not including today (today = 0, tomorrow = 1, yesterday = -1)
    int priority; //Will be a number from 1-5
    bool completed; //true: task is done, false default




public:

    //Default Constructor
    Task();
    //Basic Constructor
    Task(int idNum, std::string title);
    //Full Constructor
    Task(int idNum, std::string title, int due, int priority=1);
    Task(int idIn, std::string title, int dueDate,int priority,bool complete);
    //copyConstructor
    Task(const Task* taskToCopy);
    //default Destructor
    ~Task();

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
    bool setTaskCompletion();

    bool getComplete();

    void setId(int id);

    int getId();

    std::string toString();


    /**
     * returns all the parts of a task as a comma delemited string
     * @return id,title,due,priority,isCompleted
     * @throws Bad_Task_Id if the task you try to file is not valid/has been deleted
     */
    std::string toFile();



//  int getDuration() const;
// void setDuration(int duration);
//Task* getDependant() const;
// void setDependant(Task* nextTask);
//  int calcPriority();

};


#endif //PRO_JECT_TASK_H
