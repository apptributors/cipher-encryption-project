#include "Utils.h"

void print(const char *content)
{
    std::cout << content;
}

void print(std::string &content)
{
    std::cout << content;
}

void print(const std::string *content)
{
    std::cout << *content;
}

void println(const char *content)
{
    std::cout << content << std::endl;
}

void println(std::string &content)
{
    std::cout << content << std::endl;
}

void println(const std::string *content)
{
    std::cout << *content << std::endl;
}

void printcnt(const char *content)
{
    int length = strlen(content);
    int position = static_cast<int>((SCREEN_WIDTH - length) / 2);
    std::cout << std::string(position - 1, ' ');
    println(content);
}

void printcnt(std::string &content)
{
    int length = content.size();
    int position = static_cast<int>((SCREEN_WIDTH - length) / 2);
    std::cout << std::string(position - 1, ' ');
    println(content);
}

void printcnt(const std::string *content)
{
    int length = content->size();
    int position = static_cast<int>((SCREEN_WIDTH - length) / 2);
    std::cout << std::string(position - 1, ' ');
    println(content);
}

bool areTheSame(int a, int b)
{
    return a == b;
}

bool areTheSame(char a, char b)
{
    return a == b;
}

bool areTheSame(std::string &a, std::string &b)
{
    return a == b;
}

bool areTheSame(std::string *a, std::string *b)
{
    return *a == *b;
}

bool areTheSame(std::string *a, std::string b)
{
    return *a == b;
}

bool isWithInTheRange(char value, char lowerLimit, char upperLimit)
{
    return value >= lowerLimit && value <= upperLimit;
}

bool isWithInTheRange(int value, int lowerLimit, int upperLimit)
{
    return value >= lowerLimit && value <= upperLimit;
}

bool isWithInTheRange(float value, float lowerLimit, float upperLimit)
{
    return value >= lowerLimit && value <= upperLimit;
}

bool isWithInTheRange(double value, double lowerLimit, double upperLimit)
{
    return value >= lowerLimit && value <= upperLimit;
}

template <typename T>
std::string toString(T t)
{
    std::ostringstream oss;
    oss << t;
    return oss.str();
}

void clearScreen()
{
    int state = std::system("cls||clear");
    while (state == -1) {
        state = std::system("cls||clear");
    }
}

void printHeading(std::string &title, std::string &decoration)
{
    printcnt(decoration);
    printcnt(title);
    printcnt(decoration);
}

void printNextLine()
{
    std::cout << std::endl;
}

void printLines(int noOfLines)
{
    for (int i = 0; i < noOfLines; i++)
    {
        printNextLine();
    }
}