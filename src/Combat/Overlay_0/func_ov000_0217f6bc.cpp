#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov000_021719f8(int* obj);
extern "C" void* func_02053c6c(unsigned char* obj);

struct Struct_ov000_0217f6bc {
    char pad0[0x18];
    signed char field18;
    char pad2[0x24 - 0x19];
    unsigned char field24;
    char pad3[0x4c - 0x25];
    int field4c;
#if defined(jpn)
    char pad4[0xc7 - 0x50];
#else
    char pad4[0x87 - 0x50];
#endif
    unsigned char unknown_87_;
    char pad5[0x445 - 0x88];
    unsigned char unknown_445_;
    char pad6[0x448 - 0x446];
};

// USA: func_ov000_0217f6bc
extern "C" ARM int func_ov000_0217f6bc(char* obj) {
    GameState* bs = GameState::GetInstance();
    struct Struct_ov000_0217f6bc* entry;
    int i;
    for (i = 0; i < 4; i++) {
        signed char idx = *(signed char*)(obj + 0x6c + i);
        entry = (struct Struct_ov000_0217f6bc*)(obj + 0x958) + idx;
        if (entry->field4c < 0) continue;
        if (entry->unknown_87_ == 0) continue;
        if (entry->field24 & 4) continue;
        signed char v = *(signed char*)((char*)entry + entry->field18 + 0x10);
        if (v == 0x64) continue;
        if (func_ov000_021719f8((int*)entry)) continue;
        if (entry->unknown_445_ == 0) continue;
        GameObject* c = bs->GetPartyMemberByIndex(*(signed char*)(obj + 0x6c + i));
#if defined(jpn)
        enum { Enum_ov000_0217f6bc_2380 = 0x8b4 };
#else
        enum { Enum_ov000_0217f6bc_2380 = 0x94c };
#endif
        if (c == 0 || (signed char)(*(int*)((char*)func_02053c6c((unsigned char*)c) + Enum_ov000_0217f6bc_2380)) == 5) {
            return entry->field4c;
        }
    }
    return -1;
}
