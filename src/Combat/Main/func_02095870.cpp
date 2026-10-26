#include <globaldefs.h>
#include "Resource/Script.h"

struct ResetStruct;

struct StreamState;
struct StreamHeader;

struct Struct_0201f040_3;

struct Struct_02109404_7 {
    char pad0;
    unsigned char f1;
    unsigned char f2;
    char pad3[3];
    unsigned short unknown_6_;
};
extern struct Struct_02109404_7 data_02109404;
extern short data_020f13d8;
extern char data_020f13fc[];

// USA: func_02095870
extern "C" ARM int func_02095870(void* unused, struct StreamHeader* buffer, int length, int flag, unsigned char* arg4) {
    char local[0x430];

    data_02109404.unknown_6_ = 0;
    data_02109404.f1 = 0;
    data_02109404.f2 = 0;
    data_020f13d8 = (short)flag;

    if (flag <= 0) {
        return 1;
    }

    ((Script*)((struct ResetStruct*)local))->Initialize();
    ((Script*)local)->SetOpcodeLookup((Script::OpcodeLookupEntry*)data_020f13fc);
    ((Script*)((struct StreamState*)local))->Load(buffer, length);
    ((Script*)((struct Struct_0201f040_3*)local))->Execute();

    *arg4 = data_02109404.f2;
    return 0;
}
