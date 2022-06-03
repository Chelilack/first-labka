#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
void* menu(StringPro* str)
{
	int option = 0;

	while (option >= 0)
	{
		printf("=================================================================================\n");
		printf("------------------------------\n");
        printf("|0. Quit                     |\n");
		printf("|1. Input with keyboard      |\n");
		printf("|2. Concatenate              |\n");
		printf("|3. Get substring from i to j|\n");
		printf("|4. Split into words         |\n");
		printf("|5. Print out                |\n");
		printf("------------------------------\n");
		printf("->");
        scanf("%d",&option);
		switch (option)
		{
		case 0:
			option=-1;
			break;

		case 1:
			str->ProInfo->justInput(str);
			break;

		case 2:
		    printf("Enter addString\n-> ");
            char addStr[100];
			scanf("%s",addStr);
			str->ProInfo->concatenate(str,addStr);
			free(addStr);
			break;

		case 3:
			str->ProInfo->subString(str);
			break;

		case 4:
			str->ProInfo->pro_strtok(str);
			break;

		case 5:
			str->ProInfo->print(str);
        }
    }
}