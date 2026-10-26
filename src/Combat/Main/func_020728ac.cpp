#include <globaldefs.h>
#include "Resource/Script.h"

struct ResetStruct;

struct StreamState;
struct StreamHeader;

struct Struct_0201f040_3;

extern int data_020f0cc8;

struct Struct_02108db0 {
    unsigned char f0;
    char pad1;
    short f2;
    int f4;
    int f8;
    int fc;
    int f10;
};
extern struct Struct_02108db0 data_02108db0;

// USA: func_020728ac
extern "C" ARM void func_020728ac(int param0, int param1, struct StreamHeader* buffer, int length, int arg4, unsigned short arg5, unsigned char arg6) {
    char local[0x430];
    data_02108db0.f10 = param0;
    data_02108db0.fc = param1;
    data_02108db0.f8 = arg4;
    data_02108db0.f2 = arg5;
    data_02108db0.f4 = 0;
    data_02108db0.f0 = arg6;
    ((Script*)((struct ResetStruct*)local))->Initialize();
    ((Script*)((struct ResetStruct*)local))->SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_020f0cc8);
    ((Script*)((struct StreamState*)local))->Load(buffer, length);
    ((Script*)((struct Struct_0201f040_3*)local))->Execute();
}
