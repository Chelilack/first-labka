struct StringProInfo {
  void* (*justInput)(void*);
  void* (*concatenate)(void*,char *);
  void* (*subString)(void*);
  void* (*pro_strtok)(void*);
  void* (*print)(void*);
  void* (*fredom)(void*);
} typedef StringProInfo;
StringProInfo* Create(void* (*justInput)(void *), void* (*concatenate)(void *,char*), void* (*subString)(void*), void* (*pro_strtok)(void *), void* (*print)(void*), void* (*fredom)(void*));
