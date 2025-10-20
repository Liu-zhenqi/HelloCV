#include <iostream>
#include <string>
#include "Menu.h"
#include "Crypto.h"
#include "FileHandler.h"
void Menu::PrintMenu()
{
    std::cout<<"下面是使用菜单:\n";
    std::cout<<"[1]加密文本\n";
    std::cout<<"[2]解密文本\n";
    std::cout<<"[3]加密文件\n";
    std::cout<<"[4]解密文件\n";
    std::cout<<"请输入想要功能前面的数字：";
}
void Menu::InputeAndPing()
{
    int a;
    std::cin>>a;//用户输入的数字
    std::cin.ignore();//消除缓存区的\n(否则text的值为空)
    std::string text;
    std::string key;
    std::string filepath1;
    std::string filepath2;
    Crypto Encrypt1;
    Crypto Decrypt1;
    FileHandler file_handler1;
    switch (a)
    {
        case 1:
        std::cout<<"请输入要加密的文本：";
        getline(std::cin,text);
        std::cout<<"请输入密钥：";
        getline(std::cin,key);
        std::cout<<"加密结果：";
        std::cout<<Encrypt1.EncryptOrDecrypt(text,key);
        break;

        case 2:
        std::cout<<"请输入要解密的文本：";
        getline(std::cin,text);
        std::cout<<"请输入密钥：";
        getline(std::cin,key);
        std::cout<<"解密结果：";
        std::cout<<Decrypt1.EncryptOrDecrypt(text,key);
        break;

        case 3:
        std::cout<<"请输入要加密的文件路径：";
        getline(std::cin,filepath1);
        std::cout<<"请输入密钥：";
        getline(std::cin,key);
        std::cout<<"请指明保存路径：";//我人为这样更人性化，就稍稍改了一下
        getline(std::cin,filepath2);
        file_handler1.SaveAFile(filepath2,Encrypt1.EncryptOrDecrypt(file_handler1.ReadAFile(filepath1),key));
        std::cout<<"加密结果已保存到："<<filepath2<<"\n";
        break;

        case 4:
        std::cout<<"请输入要解密的文件路径：";
        getline(std::cin,filepath1);
        std::cout<<"请输入密钥：";
        getline(std::cin,key);
        std::cout<<"请指明保存路径：";
        getline(std::cin,filepath2);
        file_handler1.SaveAFile(filepath2,Encrypt1.EncryptOrDecrypt(file_handler1.ReadAFile(filepath1),key));
        std::cout<<"解密结果已保存到："<<filepath2<<"\n";
        break;

        default:
        std::cout<<"超出范围，重新打开软件，重新输入";
        break;
    }
}
