#include <iostream>
#include "Controller.h"




int main() {
    /**
     * Run the tester, if all pass, then ...
     */
    /**
     *  ... Run the Application
     */
        srand(time(NULL));
        std::cout << "\n\nWelcome to the JTC TaskManager\n" << std::endl;
        Controller UI = Controller();
        UI.runTaskManager();

    return 0;
}