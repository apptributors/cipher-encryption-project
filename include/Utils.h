#ifndef UTILS_H
#define UTILS_H
#define SCREEN_WIDTH 80
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>

void print(const char *);
void print(std::string &);
void print(const std::string *);

void println(const char *);
void println(std::string &);
void println(const std::string *);

void printcnt(std::string &);
void printcnt(const char *);
void printcnt(const std::string *);

bool areTheSame(int, int);
bool areTheSame(char, char);
bool areTheSame(std::string &, std::string &);
bool areTheSame(std::string *, std::string *);
bool areTheSame(std::string *, std::string);

bool isWithInTheRange(char, char, char);
bool isWithInTheRange(int, int, int);

template <typename T>
std::string toString(T);

void clearScreen();

void printHeading(std::string &, std::string &);
void printNextLine();
void printLines(int);

#endif