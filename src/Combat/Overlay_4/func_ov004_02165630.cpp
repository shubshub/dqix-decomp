#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/TreasureMapMetadata.h"

struct Struct_ov004_021549e4_2;
struct Struct_02011930;

struct GameResources;
int IsBrightnessTransitionActive(GameResources*);
extern "C" void* func_ov011_021849c8(void* obj);
extern "C" void* func_ov023_021f6880(void* list, int id);
extern "C" int func_ov023_021f6f10(void* obj);
extern "C" void func_ov011_021848a0(void* obj, int val);
extern "C" void func_ov004_02165a1c(void* obj);
extern "C" void* LinkSession_GetInstance(void);
extern "C" void* Zone3D_GetInstance(void);
extern "C" int LinkSession_IsGuest(void* p);
extern "C" unsigned char func_02011930(void* obj, struct Struct_02011930* info, void* name1, void* name2);
extern "C" int func_ov004_021634dc(void* a);
extern "C" unsigned char func_020119f8(char* obj, void* dst);
extern "C" unsigned int func_ov023_021f9bb0(struct Struct_ov004_021549e4_2* obj);
extern "C" unsigned int func_ov023_021f9ba0(void* obj);
extern "C" int GameState_IsInGrotto(GameState* state);

extern char* data_ov004_02171010;

struct Struct_ov004_02165630 {
    char pad[0x5c];
    short x;
    short y;
    char pad60;
    unsigned char active;
};

// USA: func_ov004_02165630
extern "C" ARM int func_ov004_02165630(void* a) {
#if defined(jpn)
 enum { Enum_ov004_02165630_2292 = 0x9f4, Enum_ov004_02165630_452 = 0x1e4, flagOffset = 0x9fd };
#else
 enum { Enum_ov004_02165630_2292 = 0x8f4, Enum_ov004_02165630_452 = 0x1c4, flagOffset = 0x8fd };
#endif
    if (*(unsigned char*)(data_ov004_02171010 + 0x1000 + Enum_ov004_02165630_2292) == 0) return 0;

    Struct_ov004_02165630* node = (Struct_ov004_02165630*)func_ov023_021f6880(func_ov011_021849c8(a), 0xa);
    if (!node || func_ov023_021f6f10(node) != 7) return 0;

    GameState* state = GameState::GetInstance();
    if (IsBrightnessTransitionActive((GameResources*)((int*)state->GetResources())) != 0) {
        node->active = 0;
        return 0;
    }
    node->active = 1;

    Struct_ov004_02165630* node2 = (Struct_ov004_02165630*)func_ov023_021f6880(func_ov011_021849c8(a), 0xa);
    if (!node2) return 0;
    if (func_ov023_021f6f10(node2) != 7) return 0;

    if (func_02011930(state, NULL, NULL, NULL) != 0) {
        int idx = func_ov004_021634dc(a);
        if (((TreasureMapMetadata*)(data_ov004_02171010 + idx * 0x1c))->GetInitialByteUnknownBit()) {
            node->active = 0;
            return 0;
        }
        func_ov011_021848a0(a, 0x68);
    } else if (func_020119f8((char*)state, NULL) != 0) {
        unsigned int k = func_ov023_021f9bb0((struct Struct_ov004_021549e4_2*)node2);
        if (*(unsigned char*)(data_ov004_02171010 + k * Enum_ov004_02165630_452 + 0xad4) != 3) {
            node->active = 0;
        } else {
            func_ov004_02165a1c(a);
        }
    } else {
        void* search = LinkSession_GetInstance();
        Zone3D_GetInstance();
        if (LinkSession_IsGuest(search)) {
            func_ov011_021848a0(a, 0x6e);
        } else if (GameState_IsInGrotto(state)) {
            func_ov011_021848a0(a, 0x76);
        } else {
            short x = node2->x;
            unsigned int col = func_ov023_021f9bb0((struct Struct_ov004_021549e4_2*)node2);
            unsigned short idx = x * func_ov023_021f9ba0(node2) + col;
            if (((TreasureMapMetadata*)(data_ov004_02171010 + idx * 0x1c))->GetInitialByteUnknownBit()) {
                func_ov011_021848a0(a, 0x74);
            } else {
                *(unsigned char*)(data_ov004_02171010 + 0x1000 + flagOffset) = 1;
                func_ov011_021848a0(a, 0x66);
            }
        }
    }
    return 0;
}
