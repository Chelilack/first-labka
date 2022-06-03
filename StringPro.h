#include "StringProInfo.h"
struct StringPro
{
    StringProInfo* ProInfo;
    int len;
    void* ptr;
} typedef StringPro;
StringPro* initialize();
char *myreadline(const char *prompt);
void* justInput(void*str);
void* concatenate(void*str,char * addStr);
void* subString(void*str);
void* pro_strtok(void*str);
void* print(void*str);
void* fredom(void*str);