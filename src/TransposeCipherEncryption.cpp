#include "TransposeCipherEncryption.h"

std::string TransposeCipherEncryption::getEncryptionKey()
{
    return "5x5";
}

std::string *TransposeCipherEncryption::encrypt(std::string &message)
{
    std::string *output = new std::string;
    const int SIZE = message.size();
    int blockSize = static_cast<int>(sqrt(SIZE)) + 1;
    for (int i = 0; i < blockSize; i++)
    {
        for (int j = 0; j < blockSize; j++)
        {
            int position = i + (j * blockSize);
            if (position > SIZE)
            {
                *output += static_cast<char>(1);
            }
            else
            {
                *output += message[position];
            }
        }
    }
    output->append(getEncryptionKey());
    return output;
}

std::string *TransposeCipherEncryption::decrypt(std::string &cipher)
{
    std::string *output = new std::string;
    const int SIZE = cipher.size();
    int blockSize = static_cast<int>(sqrt(SIZE));
    for (int i = 0; i < blockSize; i++)
    {
        for (int j = 0; j < blockSize; j++)
        {
            int position = i + j * blockSize;
            char letter = cipher[position];
            if (letter != 1)
            {
                *output += letter;
            }
        }
    }
    return output;
}