#include <iostream>
#include "Application.h"
#include "Utils.h"

int main()
{
    for (int i = 0; i < 80; i++)
        std::cout << '-';
    std::cout << std::endl;
    printcnt("Cipher Encryption Project");
    for (int i = 0; i < 80; i++)
        std::cout << '-';
    std::cout << std::endl;
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
