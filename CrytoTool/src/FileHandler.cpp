#include <fstream>
#include <string>
#include <iostream>
#include "FileHandler.h"
std::string FileHandler:: ReadAFile(const std::string &filepath)//通过引用节省花销,而常引用保证filepath不被修改
{
    std::ifstream inputfile(filepath);

    //如果文件打开异常
    if (!inputfile)
    {
        throw std::runtime_error("unable to open this file.");//创建临时对象并抛出异常信息
    }

    //正常打开
    std::string content;
    std::string line;
    while(getline(inputfile,line))
    content+=line+"\n";//读取文件内容到content中
    content.pop_back();
    return content;
}
void FileHandler::SaveAFile(const std::string& filepath,const std::string &content)
{
    std::ofstream outputfile(filepath);

    //打开异常
    if(!outputfile)
    throw std::runtime_error("unable to open this file.");

    //正常打开
    outputfile << content;
}