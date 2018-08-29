#include "XorCipherEncryption.h"

XorCipherEncryption::XorCipherEncryption(char &keyCode)
{
	key = keyCode;
}

std::string XorCipherEncryption::getEncryptionKey()
{
	return "6x6";
}

std::string *XorCipherEncryption::encrypt(std::string &message)
{
	std::string *output = new std::string;
	for (char &letter : message)
	{
		*output += letter ^ key;
	}
	output->append(getEncryptionKey());
	return output;
}

std::string *XorCipherEncryption::decrypt(std::string &cipher)
{
	std::string *output = new std::string;
	for (char &letter : cipher)
	{
		*output += letter ^ key;
	}
	return output;
}