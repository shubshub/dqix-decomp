#if defined(jpn)
enum { Enum_ov017_021c6bc8_1816 = 0x508 };
#else
enum { Enum_ov017_021c6bc8_1816 = 0x718 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" int func_020a35e0(unsigned char* obj, unsigned char index);
extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021c6bc8 {
    unsigned short f0;
    unsigned short f2;
    unsigned short f4;
    unsigned short unknown_6_;
    int f8;
    int fc;
};

struct Struct_ov017_021c6bc8_2 {
    unsigned char tag;
    unsigned char pad[3];
    struct Struct_ov017_021c6bc8 fields;
};

// USA: func_ov017_021c6bc8
extern "C" ARM void func_ov017_021c6bc8() {
    GameState* bs = GameState::GetInstance();
    unsigned char* table = *(unsigned char**)((char*)GetGameResources() + 0x3000 + Enum_ov017_021c6bc8_1816);
    unsigned char* search = (unsigned char*)func_ov017_021b8478(table);
    void* data = LinkMessageQueue_GetInstance();

    struct Struct_ov017_021c6bc8_2 msg;
    msg.tag = 0x6e;
    struct Struct_ov017_021c6bc8* fp = &msg.fields;

    for (int i = 0; i < 4; i++) {
        if (!func_020a35e0(search, i)) {
            continue;
        }
        GameObject* c = bs->GetCombatantByIndex(i);
        if (*(unsigned char*)(*(char**)((char*)c + 0x138) + 0x26) == 0) {
            continue;
        }
        fp->f0 = *(unsigned short*)(search + 0x8);
        fp->f2 = (unsigned short)i;
        fp->f4 = *(unsigned short*)(*(char**)((char*)c + 0x138) + 0x0);
        fp->unknown_6_ = *(unsigned short*)(*(char**)((char*)c + 0x138) + 0x2);
        fp->f8 = *(int*)(*(char**)((char*)c + 0x138) + 0x14);
        fp->fc = *(int*)(*(char**)((char*)c + 0x138) + 0x18);
        func_0205e330(data, &msg, 0);
    }
}
