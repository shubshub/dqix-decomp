#include <globaldefs.h>

#include "Combat/Main/BattleList.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

extern "C" void func_020534ac(char* combatant);
extern "C" int GameObject_GetGestureSlot(void* obj);
extern "C" int GameState_GetProtagonistIndex(GameState* gameState);
extern "C" int func_02053604(signed char* obj);

struct Struct_ov017_02199684 { unsigned char pad[0x14]; int val; unsigned char pad2[0x20 - 0x18]; };
extern "C" void func_ov017_02199684(Struct_ov017_02199684* arr, int count, int value);
extern "C" void func_ov017_021996bc(Struct_ov017_02199684* arr, int count);

struct Cont0205d1e0;
struct Cont0205d228;
struct Cont0205d274;
extern "C" void Window_ClearLayers(Cont0205d1e0*);
extern "C" void Window_DrawPanes(Cont0205d228*);
extern "C" void Window_FlushLayers(Cont0205d274*);
extern "C" void func_0205da88(void*, int, int, int);
struct Obj0205d2bc;
extern "C" void Window_TransferLayers(Obj0205d2bc*);

struct Elem_0205d81c {
    char pad0[0xA8];
    short w;
    short h;
    short x;
    short y;
};
struct Struct_0205d81c;
extern "C" Elem_0205d81c* func_0205d81c(Struct_0205d81c* s, int key);

struct TileMap0204bc74;
extern "C" void Background_FillRect(TileMap0204bc74* obj, unsigned short tile, int x, int y, int w, int h, unsigned short palette);

// USA: func_ov017_0219a18c
extern "C" ARM void func_ov017_0219a18c(unsigned char* self) {
#if defined(jpn)
 enum {regionalOffset0=0x3e60, regionalOffset1=0x3e54, regionalOffset2=0x3e58, regionalOffset3=0x294, regionalOffset4=0x3800, regionalOffset5=0xa90};
#else
 enum {regionalOffset0=0x4080, regionalOffset1=0x4074, regionalOffset2=0x4078, regionalOffset3=0xb4, regionalOffset4=0x3c00, regionalOffset5=0xcb0};
#endif
    for (int i = 0; i < 4; i++) {
        GameObject* combatant = func_0200ff1c(GameState::GetInstance(), i);
        if (combatant != 0) {
            func_020534ac((char*)combatant);
        }
    }

    if (*(int*)(self + (regionalOffset0)) == 0 || *(int*)(self + (regionalOffset1)) == 0) {
        return;
    }
    if (*(int*)(self + (regionalOffset2)) < 4) {
        return;
    }

    GameState* gs = GameState::GetInstance();
    if (GameObject_GetGestureSlot(gs->GetLeader()) != -1) {
        return;
    }

    func_ov017_02199684((Struct_ov017_02199684*)(self + regionalOffset3 + regionalOffset4), 2, 0x800);
    Window_ClearLayers(*(Cont0205d1e0**)(self + 0x3000 + regionalOffset5));
    Window_DrawPanes(*(Cont0205d228**)(self + 0x3000 + regionalOffset5));
    func_0205da88(*(void**)(self + 0x3000 + regionalOffset5), 1, 2, 1);

    GameObject* protagonist = gs->GetProtagonist();
    GameObject* combatant = func_0200ff1c(gs, GameState_GetProtagonistIndex(gs));
    int found = 0;
    int key;
    int mode = GameObject_GetGestureSlot(protagonist);
    int entry = func_02053604((signed char*)combatant);
    switch (mode) {
    case -1:
        break;
    case 0:
        found = 1;
        key = 0;
        break;
    case 1:
        found = 1;
        key = 1;
        break;
    case 2:
        found = 1;
        key = 2;
        break;
    case 3:
        found = 1;
        key = 3;
        break;
    }

    if (found && entry >= 0) {
        Elem_0205d81c* elem = func_0205d81c(*(Struct_0205d81c**)(self + 0x3000 + regionalOffset5), key);
        if (elem != 0) {
            Background_FillRect((TileMap0204bc74*)(self + regionalOffset3 + regionalOffset4), 1, elem->x, elem->y, elem->w, elem->h, 0xf);
        }
    }

    Window_FlushLayers(*(Cont0205d274**)(self + 0x3000 + regionalOffset5));
    if (TestFlags04((GameResources*)self, 0x10000) == 0) {
        Window_TransferLayers(*(Obj0205d2bc**)(self + 0x3000 + regionalOffset5));
    }
    func_ov017_021996bc((Struct_ov017_02199684*)(self + regionalOffset3 + regionalOffset4), 2);
}
