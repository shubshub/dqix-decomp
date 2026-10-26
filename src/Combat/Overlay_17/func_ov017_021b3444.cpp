#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

struct Struct_ov017_021b3444;
extern "C" unsigned char func_ov017_021b354c(Struct_ov017_021b3444* obj);
extern "C" void func_02072afc(int id, int* arr, short* arr2);

extern int g_itemDataArchive;
extern int g_itemDataFile;

struct Struct_ov017_021b3444_2 {
    unsigned char pad0[8];
    short id;
    unsigned char pad1;
    unsigned char unknown_b_;
    unsigned char pad2[4];
    int result;
};

// USA: func_ov017_021b3444
extern "C" ARM int func_ov017_021b3444(struct Struct_ov017_021b3444_2* obj) {
    GameState* bs = GameState::GetInstance();
    int field4 = (int)BackgroundLoader::GetInstance();
    GameObject* combatant = func_0200ff1c(bs, obj->id);
    if (combatant != 0) {
        if (func_ov017_021b354c((Struct_ov017_021b3444*)combatant) != 0) {
#if defined(jpn)
            obj->result = ((BackgroundLoader*)(field4))->QueueLoadGP1((const char*)(g_itemDataArchive), (SafeAllocator*)(0));
#else
            obj->result = ((BackgroundLoader*)(field4))->QueueLoadFileInGP2((const char*)(g_itemDataArchive), (const char*)(g_itemDataFile), (SafeAllocator*)(0));
#endif
            return 1;
        }
    }

    int arr1[11];
    short arr2[11];
    func_02072afc(obj->id, arr1, arr2);
    int flag = obj->unknown_b_ & 1;

    int i;
    for (i = 0; i < 0xb; i++) {
        GameObject* c = bs->GetGameObjectByIndex(arr1[i]);
        if (c == 0) {
            continue;
        }
        short* p2 = &c->obj3D_.unknown_2_;
        if (flag) {
            *p2 = -1;
        }
        short var9 = arr2[i];
        short var10 = *p2;
        if (var9 == var10) {
            continue;
        }
#if defined(jpn)
        obj->result = ((BackgroundLoader*)(field4))->QueueLoadGP1((const char*)(g_itemDataArchive), (SafeAllocator*)(0));
#else
        obj->result = ((BackgroundLoader*)(field4))->QueueLoadFileInGP2((const char*)(g_itemDataArchive), (const char*)(g_itemDataFile), (SafeAllocator*)(0));
#endif
        return 1;
    }
    return 0;
}
