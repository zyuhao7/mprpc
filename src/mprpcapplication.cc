#include "mprpcapplication.h"
#include <iostream>
#include <unistd.h>
#include <string>
void ShowArgsHelp()
{
    std::cout << "format: command -i <configfile>" << std::endl;
}
void MprpcApplication::Init(int argc, char **argv)
{
    if (argc < 2)
    {
        ShowArgsHelp();
        exit(-1);
    }
    int c = 0;
    std::string config_file;

    while ((c = getopt(argc, argv, "i:")) != -1)
    {
        switch (c)
        {
        case 'i':
            config_file = optarg;
            break;

        case '?':
            std::cout << "invalid args!" << std::endl;
            ShowArgsHelp();
            exit(-1);

        case ':':
            std::cout << "need <configfile>" << std::endl;
            ShowArgsHelp();
            exit(-1);
        default:
            break;
        }
    }

    // 开始加载配置文件 rpcserver_ip =  rpcserver_port  zookep
}

MprpcApplication &MprpcApplication::GetInstance()
{
    {
        static MprpcApplication app;
        return app;
    }
}