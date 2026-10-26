#if defined(jpn)
enum { Enum_ov017_021b3678_336 = 0x144 };
#else
enum { Enum_ov017_021b3678_336 = 0x150 };
#endif

#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

struct Struct_ov017_021b3444;
extern "C" unsigned char func_ov017_021b354c(Struct_ov017_021b3444* obj);
extern "C" int func_02053c6c(unsigned char* obj);

extern int data_ov017_021d7ab6;
extern short data_ov017_021d6b56;
extern short data_ov017_021d6b54;

struct Struct_ov017_021b3678 {
    unsigned char pad0[8];
    short id;
    unsigned char pad1[4];
    int result;
};

// USA: func_ov017_021b3678
extern "C" ARM int func_ov017_021b3678(struct Struct_ov017_021b3678* obj) {
    GameState* bs = GameState::GetInstance();
    int field4 = (int)BackgroundLoader::GetInstance();
    GameObject* combatant = func_0200ff1c(bs, obj->id);
    if (!combatant) {
        return 0;
    }
    if (!func_02053c6c((unsigned char*)combatant)) {
        return 0;
    }

    if (func_ov017_021b354c((Struct_ov017_021b3444*)combatant)) {
        char* sub = *(char**)((char*)combatant + Enum_ov017_021b3678_336);
        if (sub) {
            *(unsigned char*)(sub + 0x56e) = 0;
        }
        obj->result = ((BackgroundLoader*)(field4))->QueueLoadFile((const char*)((int)&data_ov017_021d7ab6), (SafeAllocator*)(0));
        return 1;
    }

    char* var4 = *(char**)((char*)combatant + Enum_ov017_021b3678_336);
    char* arrA = var4 + 0x194;
    char* arrB = var4 + 0x2f4;
    unsigned char i;
    for (i = 0; i < 8; i = (i + 1) & 0xff) {
        short t2 = *(short*)((char*)&data_ov017_021d6b54 + i * 4);
        if (t2 < 0) {
            continue;
        }
        short var9 = *(short*)((char*)&data_ov017_021d6b56 + i * 4);
        short valA = *(short*)(arrA + t2 * 0x20 + 0x18);
        short valB = *(short*)(arrB + var9 * 0x2c + 0x28);
        if (valA == valB) {
            continue;
        }
        obj->result = ((BackgroundLoader*)(field4))->QueueLoadFile((const char*)((int)&data_ov017_021d7ab6), (SafeAllocator*)(0));
        return 1;
    }
    return 1;
}
