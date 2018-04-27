#ifndef ospefunc_h
#define ospefunc_h

struct T_Offset {
      int Pos;
      int Value;
};

typedef struct T_ChangeList {
      char * RecvHex[];
      struct T_Offset Modify;
} TChangeList;


const char * GetBufferAsHex(char *, int);
const char * GetBufferAsText(char *, int);
int ChangeIfMatch(char *, int, TChangeList);
void ShowMessage (const char * );

#endif
