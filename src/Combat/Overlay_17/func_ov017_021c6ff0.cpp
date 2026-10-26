#if defined(jpn)
enum { Enum_ov017_021c6ff0_1816 = 0x508 };
#else
enum { Enum_ov017_021c6ff0_1816 = 0x718 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"
#include "Resource/GameResources.h"

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" int func_020a35e0(unsigned char* obj, unsigned char index);
extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021c6ff0 {
    unsigned short f0;
    unsigned short f2;
    int f4;
    short f8;
    short fa;
    short fc;
    short fe;
};

struct Struct_ov017_021c6ff0_2 {
    unsigned char tag;
    unsigned char pad[3];
    struct Struct_ov017_021c6ff0 fields;
};

// USA: func_ov017_021c6ff0
extern "C" ARM void func_ov017_021c6ff0() {
    GameState* bs = GameState::GetInstance();
    unsigned char* table = *(unsigned char**)((char*)GetGameResources() + 0x3000 + Enum_ov017_021c6ff0_1816);
    unsigned char* search = (unsigned char*)func_ov017_021b8478(table);
    void* data = LinkMessageQueue_GetInstance();

    struct Struct_ov017_021c6ff0_2 msg;
    msg.tag = 0x70;
    struct Struct_ov017_021c6ff0* fp = &msg.fields;

    for (int i = 0; i < 4; i++) {
        if (!func_020a35e0(search, i)) {
            continue;
        }
        GameObject* c = bs->GetCombatantByIndex(i);
        if (c == 0 || *(unsigned char*)(*(char**)((char*)c + 0x138) + 0x26) == 0) {
            continue;
        }
        fp->f0 = *(unsigned short*)(search + 0x8);
        fp->f2 = (unsigned short)i;
        memcpy(&fp->f4, *(char**)((char*)c + 0x138) + 0x58, 4);
        fp->f8 = *(short*)(*(char**)((char*)c + 0x138) + 0x28);
        fp->fa = *(short*)(*(char**)((char*)c + 0x138) + 0x2a);
        fp->fc = *(short*)(*(char**)((char*)c + 0x138) + 0x2c);
        fp->fe = *(short*)(*(char**)((char*)c + 0x138) + 0x2e);
        func_0205e330(data, &msg, 0);
    }
}
