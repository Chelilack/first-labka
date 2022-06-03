#include "StringProInfo.h"
#include <stdlib.h>

StringProInfo* Create(void* (*justInput)(void *), void* (*concatenate)(void *, char * ), void* (*subString)(void*), void* (*pro_strtok)(void *), void* (*print)(void*), void* (*fredom)(void*))
{
  StringProInfo * strInfo      = (StringProInfo*) malloc(sizeof(StringProInfo));
  strInfo->justInput=justInput;
  strInfo->concatenate=concatenate;
  strInfo->subString=subString;
  strInfo->pro_strtok=pro_strtok;
  strInfo->print=print;
  strInfo->fredom=fredom;
  return strInfo;
}