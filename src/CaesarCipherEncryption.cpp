#include "CaesarCipherEncryption.h"

std::string CaesarCipherEncryption::getEncryptionKey() {
	return "2x2";
}

std::string * CaesarCipherEncryption::encrypt(std::string &message) 
{
	std::string * encrypt = new std::string;
	for (char& letter : message) 
	{
			*encrypt += static_cast<char>(letter + 5);
	}
	encrypt->append(getEncryptionKey());
	return encrypt;
}

std::string * CaesarCipherEncryption::decrypt(std::string &message) 
{
	std::string * decrypt = new std::string;
	for (char& letter : message) 
	{
			*decrypt += static_cast<char>(letter - 5);
	}
	return decrypt;
}