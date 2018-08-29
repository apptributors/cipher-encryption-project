#ifndef APPLICATION_H
#define APPLICATION_H
#include <string>
#include <iostream>
#include <cstdlib>

#include "CipherEncryption.h"
#include "BitwiseCipherEncryption.h"
#include "BlockCipherEncryption.h"
#include "CaesarCipherEncryption.h"
#include "FileHandler.h"
#include "TransposeCipherEncryption.h"
#include "XorCipherEncryption.h"
#include "VigenereCipherEncryption.h"
#include "StreamCipherEncryption.h"

class Application
{
	int encryptOrDecrypt();
	int getEncryptionId();
	int getDecryptionId(std::string &);
	std::string & getMessage();
	std::string & processEncrypt(std::string &);
	std::string & processDecrypt(std::string &);
	void showMessage(int, std::string &);
	void saveToFile(std::string &);
public:
	void startApp();
};

#endif