#include <globaldefs.h>

#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum { Enum_ov003_02158214_505 = 0x1f5 };
enum { Enum_ov003_02158214_812 = 0x328 };
enum { Enum_ov003_02158214_494 = 0x1ea };
enum { Enum_ov003_02158214_492 = 0x1e8 };
enum { Enum_ov003_02158214_516 = 0x200 };
enum { Enum_ov003_02158214_512 = 0x1fc };
enum { Enum_ov003_02158214_504 = 0x1f4 };
#else
enum { Enum_ov003_02158214_505 = 0x1f9 };
enum { Enum_ov003_02158214_812 = 0x32c };
enum { Enum_ov003_02158214_494 = 0x1ee };
enum { Enum_ov003_02158214_492 = 0x1ec };
enum { Enum_ov003_02158214_516 = 0x204 };
enum { Enum_ov003_02158214_512 = 0x200 };
enum { Enum_ov003_02158214_504 = 0x1f8 };
#endif

extern "C" int MessageSystem_GetInstance();
extern "C" void MessageSystem_Reset(char* obj);

struct Struct_020e28dc;
extern "C" int func_020e28dc(struct Struct_020e28dc* o);
struct Struct_020e25e8;
extern "C" void func_020e25e8(struct Struct_020e25e8* obj);

struct GameResources;
void SetSubBrightness(GameResources*, int, int);
int IsSubBrightnessTransitionActive(GameResources*);
extern "C" void func_ov023_021eb414(char* obj);
extern "C" void func_ov023_021eb43c(void* obj);
extern "C" void func_ov023_021eb26c(void* obj);

// USA: func_ov003_02158214
extern "C" ARM void func_ov003_02158214(void* p) {
    char* self = (char*)p;
    GameState* bs = GameState::GetInstance();
    int word0 = (int)bs->GetResources();
    unsigned char state = *(unsigned char*)(self + Enum_ov003_02158214_505);

    if (state == 0) {
        *(int*)(self + Enum_ov003_02158214_812) = 0;
        MessageSystem_Reset((char*)MessageSystem_GetInstance());

        *(short*)(self + Enum_ov003_02158214_494) = -1;
        *(short*)(self + Enum_ov003_02158214_492) = *(short*)(self + Enum_ov003_02158214_494);

        if (*(void**)(self + 0x1c) != 0 &&
            func_020e28dc((struct Struct_020e28dc*)*(void**)(self + 0x1c)) != 0) {
            func_020e25e8((struct Struct_020e25e8*)*(void**)(self + 0x1c));
        }

        unsigned char var4 = 3;
        *(unsigned char*)(self + Enum_ov003_02158214_505) = var4;
        if (*(void**)(self + Enum_ov003_02158214_516) == 0) return;
        SetSubBrightness((GameResources*)word0, var4 - 0x13, 0);
        *(unsigned char*)(self + Enum_ov003_02158214_505) = 1;
        return;
    }

    if (state == 1) {
        if (IsSubBrightnessTransitionActive((GameResources*)word0) != 0) return;
        func_ov023_021eb414(*(char**)(self + Enum_ov003_02158214_516));
        *(unsigned char*)(self + Enum_ov003_02158214_505) = 2;
        return;
    }

    if (state == 2) {
        func_ov023_021eb43c(*(void**)(self + Enum_ov003_02158214_516));
        if (*(unsigned short*)(*(char**)(self + Enum_ov003_02158214_516) + 0x438) & 4) {
            func_ov023_021eb26c(*(void**)(self + Enum_ov003_02158214_516));
            ((SafeAllocator*)(*(char**)(self + 0) + 0x64))->Reset();
            *(int*)(self + Enum_ov003_02158214_516) = 0;
            *(int*)(self + Enum_ov003_02158214_512) = 0;
            *(unsigned char*)(self + Enum_ov003_02158214_505) = 3;
        }
        return;
    }

    if (state == 3) {
        *(unsigned char*)(self + Enum_ov003_02158214_504) = 5;
        *(unsigned char*)(self + Enum_ov003_02158214_505) = 0;
    }
}
