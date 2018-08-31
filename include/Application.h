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
	void manageEncryption();
	void manageDecryption();
	void showEndCredits();
	
public:
	void runApp();
};

#endif