#include "BlockCipherEncryption.h"

BlockCipherEncryption::BlockCipherEncryption(std::string &code) : key(code) {}

std::string BlockCipherEncryption::getEncryptionKey() {
	return "1x1";
}

std::string *BlockCipherEncryption::encrypt(std::string &message)
{
	std::string *encrypt = new std::string;
	const char *mkey = key.c_str();
	int idx = 0;
	for (char &letter : message)
	{
		if (idx >= key.size())
		{
			idx = 0;
		}
		*encrypt += static_cast<char>((letter ^ *(mkey + idx)) - *(mkey + idx));
		idx++;
	}
	encrypt->append(getEncryptionKey());
	return encrypt;
}

std::string *BlockCipherEncryption::decrypt(std::string &cipher)
{
	std::string *decrypt = new std::string;
	const char *mkey = key.c_str();
	int idx = 0;
	for (char &letter : cipher)
	{
		if (idx >= key.size())
		{
			idx = 0;
		}
		*decrypt += static_cast<char>((letter + *(mkey + idx)) ^ *(mkey + idx));
		idx++;
	}
	return decrypt;
}