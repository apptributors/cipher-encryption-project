#include "Application.h"

int Application::getEncryptionChoice()
{
	int choice = 0;
	print("Which cipher do you want now ? ");
	std::cin >> choice;
	if (isWithInTheRange(choice, 1, 7))
	{
		return choice;
	}
	return 0;
}

int Application::getMainMenuChoice()
{
	int choice = 0;
	print("What are you about to do ? ");
	std::cin >> choice;
	if (isWithInTheRange(choice, 1, 3))
	{
		return choice;
	}
	return 0;
}

int Application::getInputChoice()
{
	int choice = 0;
	print("How can I get the input ? ");
	std::cin >> choice;
	if (isWithInTheRange(choice, 1, 2))
	{
		return choice;
	}
	return 0;
}

std::string *Application::getInputInfo()
{
	showInputOptions();
	int inputForm = getInputChoice();
	while (inputForm == 0)
	{
		printNextLine();
		println("Try to give input from the available options.");
		printNextLine();
		showInputOptions();
		inputForm = getInputChoice();
	}
	std::string *input;
	if (inputForm == 1)
	{
		input = new std::string;
		printNextLine();
		println("Please end your message with a backtick symbol (`) ");
		std::getline(std::cin, *input, '`');
	}
	else
	{
		printNextLine();
		std::string filedir = getFileInfo();
		FileHandler file;
		input = file.readFromFile(filedir);
	}
	return input;
}

std::string Application::getFileInfo()
{
	std::string filedir, filename;
	std::cin.ignore();
	print("Where do you want to save the file at ? ");
	std::getline(std::cin, filedir, '\n');
	print("What should be the file name ? ");
	std::getline(std::cin, filename, '\n');
	if (!filedir.empty())
	{
		filedir.push_back('\\');
	}
	filedir.append(filename);
	return filedir;
}

CipherEncryption *Application::getSuitableCipher(int options)
{
	CipherEncryption *cipher;
	switch (options)
	{
	case 1:
		cipher = new BitwiseCipherEncryption;
		break;
	case 2:
	{
		std::string key = "<&Programming is real fun&/>";
		cipher = new BlockCipherEncryption(key);
		break;
	}
	case 3:
		cipher = new CaesarCipherEncryption;
		break;
	case 4:
		cipher = new StreamCipherEncryption;
		break;
	case 5:
		cipher = new TransposeCipherEncryption;
		break;
	case 6:
		cipher = new VigenereCipherEncryption;
		break;
	default:
	{
		char key = static_cast<char>(27);
		cipher = new XorCipherEncryption(key);
	}
	}
	return cipher;
}

void Application::showEncryptionOptions()
{
	println("Types of ciphers available : ");
	println("1 > Bitwise");
	println("2 > Block");
	println("3 > Caesar");
	println("4 > Stream");
	println("5 > Transpose");
	println("6 > Vigenere");
	println("7 > Xor (Exclusive OR)");
}

void Application::showMainMenu()
{
	println("What to do now ?");
	println("1 > Encryption");
	println("2 > Decryption");
	println("3 > Exit");
}

void Application::showInputOptions()
{
	println("How are you going to enter the information ?");
	println("1 > Type it now");
	println("2 > Retrieve it from a existing file");
}

void Application::showEncryptedMessage(std::string *message)
{
	println("Here is your encrypted message : ");
	println(message);
}

void Application::showDecryptedCipher(std::string *message)
{
	println("Here is your decrypted cipher text : ");
	println(message);
}

void Application::saveInfoToFile(std::string *content)
{
	std::string filedir = getFileInfo();
	FileHandler file;
	file.writeToFile(filedir, content);
	print("Happy to inform you that file is saved at ");
	println(filedir);
}

void Application::manageEncryption()
{
	showEncryptionOptions();
	int encryptionChoice = getEncryptionChoice();
	while (encryptionChoice == 0)
	{
		printNextLine();
		println("Try to choose an available cipher option.");
		printNextLine();
		showEncryptionOptions();
		encryptionChoice = getEncryptionChoice();
	}
	printNextLine();
	std::string *message = getInputInfo();
	CipherEncryption *cipher = getSuitableCipher(encryptionChoice);
	std::string *encrypted = cipher->encrypt(*message);
	printNextLine();
	char seeEncrypted = 0;
	print("Do you want to see encrypted message ? (Y/n) ");
	std::cin >> seeEncrypted;
	if (areTheSame(seeEncrypted, 'Y') || areTheSame(seeEncrypted, 'y'))
	{
		printNextLine();
		showEncryptedMessage(encrypted);
	}
	printNextLine();
	char saveEncrypted = 0;
	print("Do you want to save encrypted message ? (Y/n) ");
	std::cin >> saveEncrypted;
	if (areTheSame(saveEncrypted, 'Y') || areTheSame(saveEncrypted, 'y'))
	{
		printNextLine();
		saveInfoToFile(encrypted);
	}
	delete message;
	delete encrypted;
	delete cipher;
}

void Application::manageDecryption()
{
	std::string *message = getInputInfo();
	std::string key = message->substr(message->size() - 3, 3);
	int type = 0;
	if (areTheSame(&key, std::string("0x0")))
	{
		type = 1;
	}
	else if (areTheSame(&key, std::string("1x1")))
	{
		type = 2;
	}
	else if (areTheSame(&key, std::string("2x2")))
	{
		type = 3;
	}
	else if (areTheSame(&key, std::string("3x3")))
	{
		type = 4;
	}
	else if (areTheSame(&key, std::string("4x4")))
	{
		type = 5;
	}
	else if (areTheSame(&key, std::string("5x5")))
	{
		type = 6;
	}
	else if (areTheSame(&key, std::string("6x6")))
	{
		type = 7;
	}
	else
	{
		printNextLine();
		println("Your cipher text does not match the onces provided by us.");
		printNextLine();
		return;
	}
	*message = message->substr(0, message->size() - 3);
	CipherEncryption *cipher = getSuitableCipher(type);
	std::string *decrypted = cipher->decrypt(*message);
	printNextLine();
	char seeDecrypted = 0;
	print("Do you want to see decrypted message ? (Y/n) ");
	std::cin >> seeDecrypted;
	if (areTheSame(seeDecrypted, 'Y') || areTheSame(seeDecrypted, 'y'))
	{
		printNextLine();
		showDecryptedCipher(decrypted);
	}
	printNextLine();
	char saveDecrypted = 0;
	print("Do you want to save decrypted message ? (Y/n) ");
	std::cin >> saveDecrypted;
	if (areTheSame(saveDecrypted, 'Y') || areTheSame(saveDecrypted, 'y'))
	{
		printNextLine();
		saveInfoToFile(decrypted);
	}
	delete cipher;
	delete decrypted;
	delete message;
}

void Application::showEndCredits()
{
	clearScreen();
	std::string title = "Project done by the following students of XII - A :";
	std::string decoration(title.size(), '~');
	printHeading(title, decoration);
	printLines(3);
	printcnt("Abhishek Sriram, Roll No : 2");
	printcnt("Ashwin Kumar M, Roll No : 3");
	printcnt("Prajeen R G, Roll No : 20");
	printcnt("Vishal B, Roll No : 40");
	printLines(3);
}

void Application::runApp()
{
	char choice = 0;
	int menuChoice = 0;
	bool wantsToContinue = false;
	std::string projectTitle = "Cipher Encryption";
	std::string decoration(projectTitle.size(), '*');
	do
	{
		printHeading(projectTitle, decoration);
		printNextLine();
		showMainMenu();
		menuChoice = getMainMenuChoice();
		while (menuChoice == 0)
		{
			printNextLine();
			println("Try to follow the given instructions.");
			printNextLine();
			showMainMenu();
			menuChoice = getMainMenuChoice();
		}
		printNextLine();
		switch (menuChoice)
		{
		case 1:
			manageEncryption();
			break;
		case 2:
			manageDecryption();
			break;
		default:
			showEndCredits();
			return;
		}
		printNextLine();
		print("Do you want to continue ? (Y/n) ");
		std::cin >> choice;
		wantsToContinue = areTheSame(choice, 'Y') || areTheSame(choice, 'y');
		if (wantsToContinue)
		{
			clearScreen();
		}
	} while (wantsToContinue);
	showEndCredits();
}