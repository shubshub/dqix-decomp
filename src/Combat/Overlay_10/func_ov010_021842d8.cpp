#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"

extern AllocatorUnion g_mainAllocator;

extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern "C" void GameObject_EnableControl(void* obj);

extern "C" void* func_02057924();
extern "C" void func_02057f00(void* head, int value);
extern "C" void func_ov010_021842a0(void* param);

struct Struct_ov010_021842d8 {
    unsigned char pad0[4];
    int field4;
    unsigned char pad8[0xc];
    SafeAllocator unknown_14_;
};

// USA: func_ov010_021842d8
extern "C" ARM void func_ov010_021842d8(struct Struct_ov010_021842d8* obj) {
    func_02057f00(func_02057924(), 0x11);
    void* p = obj->unknown_14_.GetSignedAllocator();
    if (p != NULL) {
        obj->unknown_14_.Destroy();
        AllocatorUnion_Free(&g_mainAllocator, p);
    }
    if (obj->field4 >= 0) {
        int x = (int)BackgroundLoader::GetInstance();
        ((BackgroundLoader*)(x))->RemoveTask((int)(obj->field4));
        obj->field4 = -1;
    }
    GameObject* c = GameState::GetInstance()->GetLeader();
    if (c != NULL) {
        GameObject_EnableControl(c);
    }
    func_ov010_021842a0(obj);
}
