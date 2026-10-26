#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Cache.h"
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

struct GameResources;
void SetBrightness(GameResources*, int, int);

struct Struct_02097b34;
extern "C" void func_02097b34(struct Struct_02097b34* obj);

struct Struct_02074bd0;
extern "C" void func_02074bd0(struct Struct_02074bd0* obj);

extern "C" int LoadToMainBG1CharacterData(int arg0, int arg1, unsigned int arg2);

extern "C" void func_ov028_021d98d4(void* obj);
extern "C" void func_ov028_021d8b90(void* obj);

// USA: func_ov028_021d8c20
extern "C" ARM void func_ov028_021d8c20(char* self) {
    void* battle = GameState::GetInstance();
    void* word = (void*)((GameState*)battle)->GetResources();
    SetBrightness((GameResources*)word, -16, 0);

    *(int*)0x4000014 = 0;
    *(int*)0x4001014 = 0;

    if (((SafeAllocator*)(self + 0x44))->GetSignedAllocator() != 0) {
        ((SafeAllocator*)(self + 0x44))->Destroy();
    }
    func_02097b34((struct Struct_02097b34*)(self + 0x20));
    func_02074bd0((struct Struct_02074bd0*)(self + 0xc));

    void* buf = *(void**)(self + 0x40);
    if (buf != 0) {
        memset(buf, 0, 0x20);
        buf = *(void**)(self + 0x40);
        CleanInvalidateCacheRange(buf, 0x20);
        buf = *(void**)(self + 0x40);
        LoadToMainBG1CharacterData((int)buf, 0, 0x20);
    }

    func_ov028_021d98d4(self);

    unsigned int* var3 = (unsigned int*)word;
    ClearFlags00((GameResources*)var3, ~0u);
    ClearFlags04((GameResources*)var3, ~0u);
    ClearFlags08((GameResources*)var3, ~0u);
    SetFlags00((GameResources*)var3, *(unsigned int*)(self + 0x74));
    SetFlags04((GameResources*)var3, *(unsigned int*)(self + 0x78));
    SetFlags08((GameResources*)var3, *(unsigned int*)(self + 0x7c));

    unsigned int* var4 = (unsigned int*)0x4000000;
    *var4 = (*var4 & ~0x1f00) | (*(unsigned int*)(self + 0x58) << 8);
    unsigned int* var5 = (unsigned int*)0x4001000;
    *var5 = (*var5 & ~0x1f00) | (*(unsigned int*)(self + 0x5c) << 8);

    func_ov028_021d8b90(self);
}
