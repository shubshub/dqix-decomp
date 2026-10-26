#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"


extern "C" {
}
extern "C" void* Zone3D_GetInstance(void);
extern "C" void* Scenario_GetInstance(void);
extern "C" void Scenario_LoadZoneTriggers(void* a, int b);
extern int data_ov017_021d7c3c;

struct Struct_020534ac_2;

struct Entry021b8c84 {
    unsigned char pad0;
    unsigned char flag;
    unsigned char pad1[6];
    int key;
};

// Overlay 17, originally ApplyOrAdvanceListEntry_021b8c84 (USA/EUR 0x021b8c84, JPN 0x021b917c)
extern "C" ARM void FieldTask_ReloadZoneTriggers(struct Entry021b8c84* obj, void* context) {
    GameState::GetInstance();
    int var0 = (int)BackgroundLoader::GetInstance();
    if (obj->key == -1) {
        obj->key = ((BackgroundLoader*)(var0))->QueueLoadFile((const char*)((int)&data_ov017_021d7c3c), (SafeAllocator*)(0));
        return;
    }
    if (!((BackgroundLoader*)(var0))->GetTaskStatus((int)(obj->key))) return;
    if (((BackgroundLoader*)((struct Struct_020534ac_2*)var0))->GetDetailedTaskStatus((int)(obj->key)) == 2) {
        void* a = Scenario_GetInstance();
        Scenario_LoadZoneTriggers(a, *(int*)((char*)Zone3D_GetInstance() + 8));
    }
    ((BackgroundLoader*)(var0))->RemoveTask((int)(obj->key));
    obj->key = -1;
    obj->flag = 1;
}
