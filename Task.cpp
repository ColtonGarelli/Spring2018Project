//
// Created by Jeremy Block on 11/21/17.
//

#include "Task.h"

//todo update these setters and getters as needed.

const std::string &Task::getTitle() const {
    return title;
}

void Task::setTitle(const std::string &title) {
    Task::title = title;
}

int Task::getDuration() const {
    return duration;
}

void Task::setDuration(int duration) {
    Task::duration = duration;
}

Task *Task::getNextTask() const {
    return nextTask;
}

void Task::setNextTask(Task *nextTask) {
    Task::nextTask = nextTask;
}

Task *Task::getDependsOn() const {
    return dependsOn;
}

void Task::setDependsOn(Task *dependsOn) {
    Task::dependsOn = dependsOn;
}

short Task::getPriority() const {
    return Priority;
}

void Task::setPriority(short Priority) {
    Task::Priority = Priority;
}
