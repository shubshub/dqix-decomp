#include <globaldefs.h>
#include "Resource/Script.h"

struct ResetStruct;

struct StreamState;
struct StreamHeader;

struct Struct_0201f040_3;

extern int data_021536c4;
extern int data_020f2e2c;

// USA: func_020e57f4
extern "C" ARM int func_020e57f4(int arg0, int arg1, struct StreamHeader* buffer, int length) {
    char local[0x430];
    *(int*)((char*)&data_021536c4 + 4) = arg0;
    *(int*)&data_021536c4 = arg1;
    ((Script*)((struct ResetStruct*)local))->Initialize();
    ((Script*)((struct ResetStruct*)local))->SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_020f2e2c);
    ((Script*)((struct StreamState*)local))->Load(buffer, length);
    ((Script*)((struct Struct_0201f040_3*)local))->Execute();
    return 0;
}
