#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H
#include <string>
#include <fstream>

class FileHandler
{
public:
	void writeToFile(std::string &, std::string *);
	std::string *readFromFile(std::string &);
};

#endif