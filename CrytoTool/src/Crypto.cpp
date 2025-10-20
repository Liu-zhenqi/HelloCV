#include <string>
#include "Crypto.h"
//下面使用XOR方法加密解密

std::string Crypto::EncryptOrDecrypt(const std::string &text,const std::string &key)
{
    std::string EncryptOrDecryptText=text;
    for(int i=0;i<text.size();i++)
    {
       EncryptOrDecryptText[i]=text[i]^key[i%key.size()];//使用^位运算符，简便了代码
    } 
    return EncryptOrDecryptText; 
}
