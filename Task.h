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
    int duration;
    Task* nextTask;
    Task* dependsOn; //may not need this
    //pointer to Parent Project
    //Time dueDate
    short Priority; //Will be a number from 1-4 (we could also define this as a char-8 bits-if we are trying to be space efficient)

public:

    //todo update these setters and getters as needed.
    const std::string &getTitle() const;

    void setTitle(const std::string &title);

    int getDuration() const;

    void setDuration(int duration);

    Task *getNextTask() const;

    void setNextTask(Task *nextTask);

    Task *getDependsOn() const;

    void setDependsOn(Task *dependsOn);

    short getPriority() const;

    void setPriority(short Priority);

};


#endif //PRO_JECT_TASK_H
