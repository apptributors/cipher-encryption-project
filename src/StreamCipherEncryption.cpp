#include "StreamCipherEncryption.h"

std::string StreamCipherEncryption::getEncryptionKey()
{
	return "3x3";
}

std::string *StreamCipherEncryption::encrypt(std::string &message)
{
	std::string *output = new std::string;
	for (std::size_t i = 1; i < message.size(); i += 2)
	{
		*output += message[i];
		*output += message[i - 1];
	}
	output->append(getEncryptionKey());
	return output;
}

std::string *StreamCipherEncryption::decrypt(std::string &cipher)
{
	std::string *output = new std::string;
	for (std::size_t i = 1; i < cipher.size(); i += 2)
	{
		*output += cipher[i];
		*output += cipher[i - 1];
	}
	return output;
}