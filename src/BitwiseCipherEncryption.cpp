#include "BitwiseCipherEncryption.h"

std::string BitwiseCipherEncryption::getEncryptionKey()
{
	return "0x0";
}

std::string *BitwiseCipherEncryption::encrypt(std::string &message)
{
	std::string *encrypt = new std::string;
	for (char &letter : message)
	{
		*encrypt += ~letter;
	}
	encrypt->append(getEncryptionKey());
	return encrypt;
}

std::string *BitwiseCipherEncryption::decrypt(std::string &cipher)
{
	std::string *decrypt = new std::string;
	for (char &letter : cipher)
	{
		*decrypt += ~letter;
	}
	return decrypt;
}