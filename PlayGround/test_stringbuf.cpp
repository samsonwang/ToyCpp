

#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <sstream>


int main (int argc, char* argv[])
{
    char* pBuf = new char[20];
    memset(pBuf, 0, 20);

    pBuf[0] = 0x11;
    pBuf[1] = 0x00;
    pBuf[2] = 0x12;
    pBuf[3] = 0x13;
    pBuf[4] = 0x14;
    pBuf[5] = 0x00;

    printf("char* buffer: ");
    for (size_t i=0; i<10; ++i)
    {
        printf("%u ", pBuf[i]);
    }
    printf("\n");
    
    std::string strBuf = std::string(pBuf);
    std::cout << "std::string size: " << strBuf.length() << std::endl;
    printf("std::string buffer: ");
    for (size_t i=0; i<strBuf.size(); ++i)
    {
        printf("%u ", strBuf[i]);
    }
    printf("\n");
    
    std::stringstream objStream;
    objStream.write(pBuf, 5);
    std::cout << "std::stringstream size: " << objStream.tellp() << std::endl;
    std::string strStream = objStream.str();
    printf("std::stringstream buffer: ");
    for (int i=0; i<objStream.tellp(); ++i)
    {
        printf("%u ", strStream[i]);
    }
    printf("\n");
    
    return 0;
}




