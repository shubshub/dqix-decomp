#include <globaldefs.h>
#include "Resource/Script.h"

struct ResetStruct;

struct StreamState;
struct StreamHeader;

struct Struct_0201f040_3;

extern int data_020fdd30;
extern int data_020ef6f4;

// USA: func_02028048
extern "C" ARM void func_02028048(int arg0, int arg1, struct StreamHeader* buffer, int length) {
    char local[0x430];
    *(int*)&data_020fdd30 = arg0;
    *(int*)((char*)&data_020fdd30 + 4) = arg1;
    ((Script*)((struct ResetStruct*)local))->Initialize();
    ((Script*)((struct ResetStruct*)local))->SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_020ef6f4);
    ((Script*)((struct StreamState*)local))->Load(buffer, length);
    ((Script*)((struct Struct_0201f040_3*)local))->Execute();
    *(int*)((char*)&data_020fdd30 + 4) = 0;
    *(int*)&data_020fdd30 = 0;
}
