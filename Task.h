//
// Created by Jeremy Block on 11/21/17.
// Modified by Jeremy Block on 12/09/17
// Modified by Jeremy Block on 12/18/17
//

#ifndef PRO_JECT_TASK_H
#define PRO_JECT_TASK_H


#include <string>

class Bad_Task_Id : std::exception{};


class Task {
private:
    int Id; // a unique identifier so a task can be identified in different implementations of TaskList
    std::string title; //The title of the task
    int dueDate;//days till due not including today (today = 0, tomorrow = 1, yesterday = -1 ...)
    int priority; //Will be a number from 1-5
    bool completed; //true: task is done, false default

public:

    //Default Constructor
    Task();
    //Basic Constructor for testing
    Task(int idNum, std::string title);
    //Mostly full constructor for creating a new task from User input
    Task(int idNum, std::string title, int due, int priority=1);
    //Full Constructor for reading in from file
    Task(int idIn, std::string title, int dueDate,int priority,bool complete);
    //copyConstructor
    Task(const Task* taskToCopy);
    //default Destructor
    ~Task();

    //Assignment Operator
    Task& operator=(const Task& taskToCopy);

    void setId(int id);

    int getId();

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
     * @post - task.completed is swapped
     * @return the state of task.completed after swap
     */
    bool toggleTaskCompletion();

    bool getComplete();

    /**
     * prints all the parts of the task on new lines with a small title prepending each part
     *
     * @return in order id,title,due,priority,isCompleted
     */
    std::string toString();

    /**
     * similar to toString but does not include id in output.
     * good for getting a string to be sent to the user
     * @return title,due,priority,isCompleted
     */
    std::string toPrint();

    /**
     * returns all the parts of a task as a comma delemited string
     * @return id,title,due,priority,isCompleted
     */
    std::string toFile();

};


#endif //PRO_JECT_TASK_H
