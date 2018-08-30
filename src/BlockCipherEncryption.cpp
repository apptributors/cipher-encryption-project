#include "BlockCipherEncryption.h"

BlockCipherEncryption::BlockCipherEncryption(std::string &code) : key(code) {}

std::string BlockCipherEncryption::getEncryptionKey() {
	return "1x1";
}

std::string *BlockCipherEncryption::encrypt(std::string &message)
{
	std::string *output = new std::string;
	const char *mkey = key.c_str();
	int idx = 0;
	for (char &letter : message)
	{
		if (idx >= key.size())
		{
			idx = 0;
		}
		char encodedValue = (letter ^ *(mkey + idx)) - *(mkey + idx);
		output->push_back(encodedValue);
		idx++;
	}
	output->append(getEncryptionKey());
	return output;
}

std::string *BlockCipherEncryption::decrypt(std::string &cipher)
{
	std::string *output = new std::string;
	const char *mkey = key.c_str();
	int idx = 0;
	for (char &letter : cipher)
	{
		if (idx >= key.size())
		{
			idx = 0;
		}
		char decodeValue = (letter + *(mkey + idx)) ^ *(mkey + idx);
		output->push_back(decodeValue);
		idx++;
	}
	return output;
}