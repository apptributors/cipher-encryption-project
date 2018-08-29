#ifndef STREAM_CIPHER_ENCRYPTION_H
#define STREAM_CIPHER_ENCRYPTION_H
#include <string>

#include "CipherEncryption.h"

class StreamCipherEncryption : public CipherEncryption
{
  public:
	std::string getEncryptionKey() override;
	std::string *encrypt(std::string &) override;
	std::string *decrypt(std::string &) override;
};

#endif