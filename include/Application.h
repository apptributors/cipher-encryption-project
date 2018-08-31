#ifndef APPLICATION_H
#define APPLICATION_H
#include <cstdlib>
#include <iostream>
#include <string>

#include "CipherEncryption.h"
#include "BitwiseCipherEncryption.h"
#include "BlockCipherEncryption.h"
#include "CaesarCipherEncryption.h"
#include "FileHandler.h"
#include "TransposeCipherEncryption.h"
#include "XorCipherEncryption.h"
#include "VigenereCipherEncryption.h"
#include "StreamCipherEncryption.h"
#include "Utils.h"

class Application
{
	void showMainMenu();
	int getMainMenuChoice();
	void showEncryptionOptions();
	int getEncryptionChoice();
	void showInputOptions();
	int getInputChoice();
	std::string getFileInfo();
	std::string *getInputInfo();
	void manageEncryption();
	void showEncryptedMessage(std::string *);
	void manageDecryption();
	void showDecryptedCipher(std::string *);
	void showEndCredits();
	void saveInfoToFile(std::string *);
	
public:
	void runApp();
};

#endif