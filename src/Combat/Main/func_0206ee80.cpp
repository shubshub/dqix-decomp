#include <globaldefs.h>
#include "Resource/Script.h"

struct ResetStruct;

struct StreamState;
struct StreamHeader;

struct Struct_0201f040_3;

struct Struct_02108d04 {
    short field0;
    short pad2;
    void* field4;
    void* field8;
    void* fieldC;
};
extern struct Struct_02108d04 data_02108d04;
extern int data_020f0a3c;

// USA: func_0206ee80
extern "C" ARM void func_0206ee80(void* p0, void* p1, struct StreamHeader* buffer, int length, void* p4, short p5) {
    char local[0x430];
    data_02108d04.fieldC = p0;
    data_02108d04.field8 = p4;
    data_02108d04.field0 = p5;
    data_02108d04.field4 = p1;
    ((Script*)((struct ResetStruct*)local))->Initialize();
    ((Script*)((struct ResetStruct*)local))->SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_020f0a3c);
    ((Script*)((struct StreamState*)local))->Load(buffer, length);
    ((Script*)((struct Struct_0201f040_3*)local))->Execute();
}
