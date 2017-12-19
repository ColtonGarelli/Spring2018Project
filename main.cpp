#include <iostream>
#include "Controller.h"
#include "Tester.h"
int main() {
    /**
     * Run the tester, if all pass, then ...
     */
    Tester t1 = Tester();
    if (t1.testAll()){
        /**
        *  ... Run the Application:
        */
        srand(time(NULL));
        std::cout << "Welcome to the JTC TaskManager\n" << std::endl;
        Controller UI = Controller();
        UI.runTaskManager();
    } else {
        std::cout << "\n*******************************\nTests failed: terminating execution\n*******************************" << std::endl;
    }
    return 0;
}