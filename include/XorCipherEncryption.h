#ifndef XOR_CIPHER_ENCRYPTION_H
#define XOR_CIPHER_ENCRYPTION_H
#include <string>

#include "CipherEncryption.h"

class XorCipherEncryption : public CipherEncryption
{
	char key;

  public:
	XorCipherEncryption(char &);
	std::string getEncryptionKey() override;
	std::string *encrypt(std::string &) override;
	std::string *decrypt(std::string &) override;
};

#endif