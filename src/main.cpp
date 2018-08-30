#include <iostream>
#include "Application.h"

int main()
{
    Application *app = new Application();
    char choice;
    do {
        app->startApp();
        std::cout << "\n\nDo you want to continue(Y/n)? ";
        std::cin >> choice;
        std::cout << std::endl;
    } while (choice == 'Y' || choice == 'y');
    delete app;
    return 0;
}
