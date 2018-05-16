

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE* pFile = fopen("./test_file", "r");
    if (!pFile)
    {
        perror("fopen failed");
        return -1;
    }
    
    // get the size of this file
    int nOffset = fseek(pFile, 0, SEEK_END);
    if (nOffset < 0)
    {
        perror("fseek failed");
        return -1;
    }
    
    void* pBuffer = malloc(nOffset);
    if (!pBuffer)
    {
        perror("malloc failed");
        return -1;
    }

    // move file position indicator to the beggining
    rewind(pFile);

    // read content from file
    size_t nCount = fread(pBuffer, 1, nOffset-1, pFile);

    printf("fread ret = %u\n", nCount);
    
    return 0;
}


