#if defined(jpn)
enum {regionalOffset0=0x134, regionalOffset1=0x4e0, regionalOffset2=0x4e3, regionalOffset3=0x4e2, regionalOffset4=0xe2};
#else
enum {regionalOffset0=0x138, regionalOffset1=0x4e4, regionalOffset2=0x4e7, regionalOffset3=0x4e6, regionalOffset4=0xe6};
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"

struct GameResources;
void SetBrightness(GameResources*, int, int);
int IsBrightnessTransitionActive(GameResources*);
extern "C" int func_0209ca2c(void* obj);
extern "C" void GameState_SetCamera(GameState* battleStruct, int value);
extern int g_bgmPlayer;

struct Struct_ov023_021e3f34 { char pad[regionalOffset0]; int field138; char pad2[regionalOffset1 - regionalOffset0 - 4]; unsigned char unknown_4e4_; };

// USA: func_ov023_021e3f34
extern "C" ARM void func_ov023_021e3f34(struct Struct_ov023_021e3f34* obj) {
    GameState* bs = GameState::GetInstance();
    int val = (int)bs->GetResources();
    if (obj->unknown_4e4_ == 0) {
        SetBrightness((GameResources*)val, -16, 15);
        obj->unknown_4e4_++;
    }
    if (IsBrightnessTransitionActive((GameResources*)val)) return;
    if (func_0209ca2c(&g_bgmPlayer)) return;
    GameState_SetCamera(bs, obj->field138);
    obj->unknown_4e4_ = 0;
    *(signed char*)((char*)obj + regionalOffset2) = *(signed char*)((char*)obj + 0x400 + regionalOffset4);
    *(signed char*)((char*)obj + regionalOffset3) = -1;
}
