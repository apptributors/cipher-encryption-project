#ifndef CAESAR_CIPHER_ENCRYPTION_H
#define CAESAR_CIPHER_ENCRYPTION_H
#include <string>

#include "CipherEncryption.h"

class CaesarCipherEncryption : public CipherEncryption
{
  public:
	std::string getEncryptionKey() override;
	std::string *encrypt(std::string &) override;
	std::string *decrypt(std::string &) override;
};

#endif
