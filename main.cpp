#include <iostream>
#include "Controller.h"
int main(){
    srand(time(NULL));
    std::cout << "Welcome to the JTC TaskManager\n" << std::endl;
    Controller UI = Controller();
    UI.runTaskManager();
    return 0;
}