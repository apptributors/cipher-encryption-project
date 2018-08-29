#include "Application.h"

int Application::encryptOrDecrypt()
{
	std::cout << "Menu:\n";
	std::cout << "1 - Encryption\n";
	std::cout << "2 - Decryption\n";
	std::cout << "3 - Exit\n";
	int choice;
	std::cout << "Enter your choice : ";
	std::cin >> choice;
	return (choice > 3 || choice < 1) ? -1 : choice;
}

std::string &Application::getMessage()
{
	FileHandler *file;
	int type;
	std::string *message = new std::string();
	std::cout << "Data input type:\n";
	std::cout << "1 - Console input\n";
	std::cout << "2 - File input\n";
	std::cout << "Enter your choice: ";
	std::cin >> type;
	if (type == 2)
	{
		file = new FileHandler;
		std::string filedir;
		std::cout << "\nEnter file directory : ";
		getline(std::cin, filedir, '\n');
		std::string *content = file->readFromFile(filedir);
		delete file;
		return *content;
	}
	else if (type == 1)
	{
		std::cout << "NOTE : End your message with ~ (tilde) symbol.\n";
		std::cout << "Enter your message:\n";
		getline(std::cin, *message, '~');
	}

	if (*message == "")
		*message = "NULL";
	return *message;
}

int Application::getEncryptionId()
{
	int type;
	std::cout << "Types of Cipher Encryption:\n";
	std::cout << "1 - Bitwise" << std::endl;
	std::cout << "2 - Block" << std::endl;
	std::cout << "3 - Caesar" << std::endl;
	std::cout << "4 - Transpose" << std::endl;
	std::cout << "5 - Xor (Exclusive or)" << std::endl;
	std::cout << "6 - Vigenere " << std::endl;
	std::cout << "7 - Stream" << std::endl;
	std::cout << "Enter type : ";
	std::cin >> type;
	return (type < 1 || type > 7) ? -1 : type;
}

void Application::showMessage(int type, std::string &message)
{
	if (message != "NULL")
	{
		if (type == 2)
			std::cout << "Decrypted Version:";
		else
			std::cout << "Encrypted Version:\n";
		std::cout << message;
	}
	else
	{
		std::cout << "Invalid input..\n";
	}
}

void Application::saveToFile(std::string &message)
{
	FileHandler *file = new FileHandler;
	std::string filedir;
	std::cout << "\nEnter file directory: ";
	getline(std::cin, filedir, '\n');
	file->writeToFile(filedir, message);
	std::cout << "\nFile saved.";
	delete file;
}

std::string &Application::processEncrypt(std::string &message)
{
	CipherEncryption *ce;
	std::string *m = new std::string();
	std::string key = "Keepass";
	switch (getEncryptionId())
	{
	case 1:
		ce = new BitwiseCipherEncryption;
		break;
	case 2:
		ce = new BlockCipherEncryption(key);
		break;
	case 3:
		ce = new CaesarCipherEncryption;
		break;
	case 4:
		ce = new StreamCipherEncryption;
		break;
	case 5:
		ce = new TransposeCipherEncryption;
		break;
	case 6:
		ce = new VigenereCipherEncryption;
		break;
	case 7:
		ce = new XorCipherEncryption(message[0]);
		break;
	default:
		std::cout << "\n Wrong cipher type...\n";
		*m = "NULL";
		break;
	}
	if (*m != "NULL")
	{
		m = ce->encrypt(message);
		delete ce;
	}
	return *m;
}

std::string &Application::processDecrypt(std::string &message)
{
	CipherEncryption *ce;
	std::string *m = new std::string();
	std::string key = "Keepass";
	std::string enc = message.substr(0, message.size() - 3);
	switch (getDecryptionId(message))
	{
	case 1:
		ce = new BitwiseCipherEncryption;
		break;
	case 2:
		ce = new BlockCipherEncryption(key);
		break;
	case 3:
		ce = new CaesarCipherEncryption;
		break;
	case 4:
		ce = new StreamCipherEncryption;
		break;
	case 5:
		ce = new TransposeCipherEncryption;
		break;
	case 6:
		ce = new VigenereCipherEncryption;
		break;
	case 7:
		ce = new XorCipherEncryption(message[0]);
		break;
	default:
		*m = "NULL";
		std::cout << "\n Inputed Cipher is not compatible.. \n";
		return *m;
	}
	m = ce->decrypt(enc);
	return *m;
}

int Application::getDecryptionId(std::string &message)
{
	std::string type = message.substr(message.size() - 3, 3);
	if (type == "0x0")
	{
		return 1;
	}
	else if (type == "1x1")
	{
		return 2;
	}
	else if (type == "2x2")
	{
		return 3;
	}
	else if (type == "3x3")
	{
		return 4;
	}
	else if (type == "4x4")
	{
		return 5;
	}
	else if (type == "5x5")
	{
		return 6;
	}
	else if (type == "6x6")
	{
		return 7;
	}
	else
	{
		return -1;
	}
}

void Application::startApp()
{
	int type = encryptOrDecrypt();
	std::cout << std::endl;
	if (type == 3)
	{
		exit(0);
	}
	std::string message = getMessage();
	std::string processed;
	std::cout << std::endl;
	if (message == "NULL")
	{
		std::cout << "Invalid input...";
	}
	else
	{
		if (type == 1)
		{
			processed = processEncrypt(message);
		}
		else if (type == 2)
		{
			processed = processDecrypt(message);
		}
		else
		{
			std::cout << "Choice not found.";
		}

		showMessage(type, processed);
		char ch;
		std::cout << std::endl;
		std::cout << "\nDo you want to save ";
		if (type == 1)
		{
			std::cout << "encrypted data ? ";
		}
		else
		{
			std::cout << "decrypted data ? ";
		}
		std::cin >> ch;
		if (ch == 'y' || ch == 'Y')
			saveToFile(processed);
	}
}