#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
int main()
{
    printf("program has began...\n");
    StringPro* str = initialize();
    menu(str);
    str->ProInfo->fredom(str);
    return 0;
}
