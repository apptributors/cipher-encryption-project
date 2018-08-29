#ifndef TRANSPOSE_CIPHER_ENCRYPTION_H
#define TRANSPOSE_CIPHER_ENCRYPTION_H
#include <cmath>
#include <string>

#include "CipherEncryption.h"

class TransposeCipherEncryption : public CipherEncryption
{
  public:
    std::string getEncryptionKey() override;
    std::string *encrypt(std::string &) override;
    std::string *decrypt(std::string &) override;
};

#endif