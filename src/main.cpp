#include <iostream>
#include "Application.h"

int main()
{
    Application app;
    char ch;
    do
    {
        app.startApp();
        std::cout << "\n\nDo you want to continue(Y/n) : ";
        std::cin >> ch;
    } while (ch == 'Y' || ch == 'y');
    return 0;
}
