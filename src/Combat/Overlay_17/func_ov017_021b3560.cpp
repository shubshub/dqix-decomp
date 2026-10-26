#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

struct Struct_020534ac;
extern "C" int func_02053c6c(unsigned char* obj);
struct Struct_02082828_2;
extern "C" void func_02083508(struct Struct_02082828_2* o);
extern "C" int func_020deef4(int a0, int a1, int a2, short* a3, short a4);

extern "C" {
    void func_02072afc(int id, int* arr, short* arr2);
    void func_02052d7c(void* combatant, int arg1, int arg2);
}

struct Struct_ov017_021d6b74 { int a; int b; };
extern struct Struct_ov017_021d6b74 data_ov017_021d6b78[];
extern struct Struct_ov017_021d6b74 data_ov017_021d6b74[];

struct Struct_ov017_021b3560 {
    unsigned char pad0[8];
    short field8;
    char pad1[6];
    int field10;
};

// USA: func_ov017_021b3560
extern "C" ARM int func_ov017_021b3560(struct Struct_ov017_021b3560* self) {
    GameState* bs = GameState::GetInstance();
    int var1 = (int)BackgroundLoader::GetInstance();
    if (!((BackgroundLoader*)(var1))->GetTaskStatus((int)(self->field10))) {
        return 0;
    }

    GameObject* combatant = func_0200ff1c(bs, self->field8);
    if (!combatant) {
        return 0;
    }

    void* obj150 = (void*)func_02053c6c((unsigned char*)combatant);
    if (!obj150) {
        return 0;
    }

    int bufA[11];
    short var5[12];
    func_02072afc(self->field8, bufA, var5);

    int out1, out2;
    ((BackgroundLoader*)((struct Struct_020534ac*)var1))->GetLoadedFileByID((int)(self->field10), (void**)(&out1), (unsigned int*)(&out2));
    func_02083508((struct Struct_02082828_2*)obj150);
    func_020deef4((int)((char*)obj150 + 0x194), out1, out2, var5, 11);
    ((BackgroundLoader*)(var1))->RemoveTask((int)(self->field10));
    self->field10 = -1;

    int idx;
    for (idx = 0; data_ov017_021d6b74[idx].a >= 0; idx++) {
        int entry = data_ov017_021d6b78[idx].a;
        short valA = *(short*)((char*)obj150 + entry * 0x20 + 0x1ac);
        if (valA != var5[entry]) {
            func_02052d7c(combatant, data_ov017_021d6b74[idx].a, -1);
        }
    }
    return 1;
}
