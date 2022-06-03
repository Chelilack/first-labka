#include"StringPro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


StringPro* initialize()
{
    StringPro* StrPro=malloc(sizeof(StringPro*));
    StrPro->ProInfo=Create(&justInput,&concatenate,&subString,&pro_strtok,&print,&fredom);
    StrPro->len=0;
    StrPro->ptr=NULL;
}

void* justInput(void* str)
{
    StringPro* StrPro=(StringPro*) str;
    char keyBoardInputStr[100];
    scanf("%s",keyBoardInputStr);
    char * keyBoardInputPtr= malloc(sizeof(char*)+1);
    memcpy(keyBoardInputPtr,keyBoardInputStr,strlen(keyBoardInputStr)*sizeof(char));
    StrPro->ptr=keyBoardInputPtr;
    StrPro->len=strlen(keyBoardInputPtr);
}
void* concatenate(void* str,char * addStr)
{
    StringPro* StrPro=(StringPro*) str;
    if(StrPro->ptr!=NULL) 
        StrPro->ptr=realloc(StrPro->ptr,(StrPro->len+strlen(addStr)+1)*sizeof(char));
    else 
        StrPro->ptr=malloc(strlen(addStr)+1);
    memcpy(StrPro->ptr+strlen(StrPro->ptr),addStr,strlen(addStr)+1);
    StrPro->len+=strlen(addStr);
}
void* subString(void* str)
{
    StringPro* StrPro =(StringPro*) str;
    printf("begin ind\n->");
    int i,j;
    scanf("%d",&i);
    printf("end ind (<=%d)\n->",StrPro->len);
    scanf("%d",&j);
    if (j>StrPro->len){j=StrPro->len;}
    if (i<0){i=0;}
    char* pass=malloc(((j-i+1)+1)*sizeof(char));
    char* pass_ptr=StrPro->ptr;
    memcpy(pass,pass_ptr+i,(j-i+1));
    StrPro = initialize(StrPro);
    StrPro->ptr=pass;
    StrPro->len=(j-i+1);
    StrPro->ProInfo->print(StrPro);
    StrPro->ProInfo->fredom(StrPro);
}
void* pro_strtok(void*str)
{
    StringPro* StrPro = (StringPro*) str;
    if(!StrPro->len)
    {
        printf("input smth pls :)\n");
        return NULL ;
    }
    char *pass_ptr = (char*) StrPro->ptr;
    char* copy_ptr = malloc(sizeof(char) * (strlen(pass_ptr) + 1));
    memcpy(copy_ptr, pass_ptr, (strlen(pass_ptr) + 1) * sizeof(char));
    char* word = strtok(copy_ptr, " \t");

    StringPro** Word = malloc(sizeof(StringPro*));
    int i = 0;
    while(word != NULL) 
    {
        Word=realloc(Word, (i + 1) * sizeof(StringPro*));
        Word[i]=initialize(StrPro);
        Word[i]->ptr=malloc((strlen(word) + 1) * sizeof(char));
        Word[i]->len=strlen(word);
        memcpy(Word[i]->ptr, word, strlen(word));
        Word[i]->ProInfo->print(Word[i]);
        word = strtok(NULL, " \t");
        i++;
    }

}

void* print(void* str) {
    StringPro* StrPro = (StringPro*) str;
    if(!StrPro->ptr) 
    {
        printf("\n -> :( \n");
        return NULL;
    }
  printf("\n ->%s \n", StrPro->ptr);
}
void* fredom(void*str)
{
    StringPro* StrPro = (StringPro*) str;
    if(StrPro != NULL) free(StrPro->ptr);
    free(StrPro->ProInfo);
    free(StrPro);
}