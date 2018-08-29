#ifndef VIGENERE_CIPHER_ENCRYPTION_H
#define VIGENERE_CIPHER_ENCRYPTION_H
#include <string>

#include "CipherEncryption.h"

class VigenereCipherEncryption : public CipherEncryption
{
	char encodeKeyValue(char);
	char decodeKeyValue(char);

  public:
	std::string getEncryptionKey() override;
	std::string *encrypt(std::string &) override;
	std::string *decrypt(std::string &) override;
};

#endif