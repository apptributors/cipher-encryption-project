#include "Utils.h"

void print(char ch)
{
    std::cout << ch;
}

void print(int i)
{
    std::cout << i;
}

void print(float f)
{
    std::cout << f;
}

void print(double d)
{
    std::cout << d;
}

void print(std::string &content)
{
    std::cout << content;
}

void print(const char *content)
{
    std::cout << content;
}

void print(const std::string *content)
{
    std::cout << *content;
}

void println(char ch)
{
    std::cout << ch << std::endl;
}

void println(int i)
{
    std::cout << i << std::endl;
}

void println(float f)
{
    std::cout << f << std::endl;
}

void println(double d)
{
    std::cout << d << std::endl;
}

void println(std::string &content)
{
    std::cout << content << std::endl;
}

void println(const char *content)
{
    std::cout << content << std::endl;
}

void println(const std::string *content)
{
    std::cout << *content << std::endl;
}

void printcnt(char content)
{
    int length = 1;
    int position = static_cast<int>((SCREEN_WIDTH - length) / 2);
    std::cout << std::string(position - 1, ' ');
    println(content);
}

void printcnt(int content)
{
    int length = toString(content).size();
    int position = static_cast<int>((SCREEN_WIDTH - length) / 2);
    std::cout << std::string(position - 1, ' ');
    println(content);
}

void printcnt(float content)
{
    int length = toString(content).size();
    int position = static_cast<int>((SCREEN_WIDTH - length) / 2);
    std::cout << std::string(position - 1, ' ');
    println(content);
}

void printcnt(double content)
{
    int length = toString(content).size();
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

void printcnt(const char *content)
{
    int length = strlen(content);
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

bool areTheSame(float a, float b)
{
    return a == b;
}

bool areTheSame(double a, double b)
{
    return a == b;
}

bool areTheSame(std::string &a, std::string &b)
{
    return a == b;
}

bool areTheSame(char *a, char *b)
{
    return strcmp(a, b) == 0;
}

bool areTheSame(std::string *a, std::string *b)
{
    return *a == *b;
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
    std::system(CLEAR);
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