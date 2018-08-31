#ifndef UTILS_H
#define UTILS_H
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>

//Constants
#define SCREEN_WIDTH 80
#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

void print(char);
void print(int);
void print(float);
void print(double);
void print(std::string &);
void print(const char *);
void print(const std::string *);

void println(char);
void println(int);
void println(float);
void println(double);
void println(std::string &);
void println(const char *);
void println(const std::string *);

void printcnt(char);
void printcnt(int);
void printcnt(float);
void printcnt(double);
void printcnt(std::string &);
void printcnt(const char *);
void printcnt(const std::string *);

bool areTheSame(int, int);
bool areTheSame(char, char);
bool areTheSame(float, float);
bool areTheSame(double, double);
bool areTheSame(std::string &, std::string &);
bool areTheSame(char *, char *);
bool areTheSame(std::string *, std::string *);
bool areTheSame(std::string *, std::string);


bool isWithInTheRange(char, char, char);
bool isWithInTheRange(int, int, int);
bool isWithInTheRange(float, float, float);
bool isWithInTheRange(double, double, double);

template<typename T>
std::string toString(T);

void clearScreen();

void printHeading(std::string &, std::string &);
void printNextLine();
void printLines(int);

#endif