#include <globaldefs.h>
#include "Resource/Script.h"

struct ResetStruct;

struct StreamState;
struct StreamHeader;

struct Struct_0201f040_3;

struct Struct_02109404_6 {
    char pad0;
    unsigned char f1;
    unsigned char f2;
    char pad3[3];
    unsigned short unknown_6_;
};
extern struct Struct_02109404_6 data_02109404;
extern short data_020f13d8;
extern char data_020f13dc[];

// USA: func_020957f4
extern "C" ARM int func_020957f4(void* unused, struct StreamHeader* buffer, int length) {
    char local[0x430];

    data_02109404.unknown_6_ = 0;
    data_02109404.f1 = 1;
    data_02109404.f2 = 0;
    data_020f13d8 = -1;

    ((Script*)((struct ResetStruct*)local))->Initialize();
    ((Script*)local)->SetOpcodeLookup((Script::OpcodeLookupEntry*)data_020f13dc);
    ((Script*)((struct StreamState*)local))->Load(buffer, length);
    ((Script*)((struct Struct_0201f040_3*)local))->Execute();

    return data_02109404.unknown_6_;
}
