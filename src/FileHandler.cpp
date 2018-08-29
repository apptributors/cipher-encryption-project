#include "FileHandler.h"

void FileHandler::writeToFile(std::string &filedir, std::string &content)
{
	std::ofstream out(filedir, std::ofstream::out);
	out << content;
	out.close();
}

std::string *FileHandler::readFromFile(std::string &filedir)
{
	std::ifstream inFile(filedir);
	std::string *content = new std::string;
	char *line = new char[100];
	while (!inFile.eof())
	{
		inFile.getline(line, 100);
		content->append(line);
	}
	delete line;
	return content;
}