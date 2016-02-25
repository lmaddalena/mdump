#include <stdlib.h>
#include <stdio.h> 
#include "mdump.h"

int main(int argc, char **argv) {
    
    char s[] = "Hello";
    //mdump(stdout, s, 1024);
    
    FILE * pFile;
    pFile = fopen ("dump.dat", "w");
    if (pFile != NULL)
    {
        mdump(pFile, argv[0], 512);
        fclose (pFile);
    }
    return 0;
}