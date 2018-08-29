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
		*output += static_cast<char>(letter ^ key);
	}
	output->append(getEncryptionKey());
	return output;
}

std::string *XorCipherEncryption::decrypt(std::string &cipher)
{
	std::string *output = new std::string;
	for (char &letter : cipher)
	{
		*output += static_cast<char>(letter ^ key);
	}
	return output;
}