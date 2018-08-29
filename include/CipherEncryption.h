#ifndef CIPHER_ENCRYPTION_H
#define CIPHER_ENCRYPTION_H
#include <string>

class CipherEncryption
{
  public:
	virtual ~CipherEncryption() {}
	virtual std::string getEncryptionKey() = 0;
	virtual std::string *encrypt(std::string &) = 0;
	virtual std::string *decrypt(std::string &) = 0;
};

#endif
