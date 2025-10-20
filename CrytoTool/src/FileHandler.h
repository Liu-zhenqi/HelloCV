#include <string>
class FileHandler
{
    public:
    std::string ReadAFile(const std::string &filepath);//读取文件
    void SaveAFile(const std::string& filepath,const std::string &content);//保存文件
};