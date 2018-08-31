#include <iostream>
#include <string>
#include "Application.h"
#include "Utils.h"

int main()
{
    std::string projectTitle = "Cipher Encryption";
    std::string decoration(projectTitle.size(), '*');
    printHeading(projectTitle, decoration);
    std::cout << std::endl;
    Application *app = new Application();
    app->runApp();
    delete app;
    return 0;
}
