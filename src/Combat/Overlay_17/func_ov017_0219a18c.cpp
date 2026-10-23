#include <globaldefs.h>

#include "Combat/Main/BattleList.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

extern "C" void func_020534ac(char* arg0);
extern "C" int func_02039750(void* arg0);
extern "C" int func_020100a8(GameState* arg0);
extern "C" int func_02053604(signed char* arg0);

struct Struct_ov017_02199684 { unsigned char unknown_0_[0x14]; int unknown_14_; unsigned char unknown_18_[0x20 - 0x18]; };
extern "C" void func_ov017_02199684(Struct_ov017_02199684* arg0, int arg1, int arg2);
extern "C" void func_ov017_021996bc(Struct_ov017_02199684* arg0, int arg1);

struct Cont0205d1e0;
struct Cont0205d228;
struct Cont0205d274;
void Window_ClearLayers(Cont0205d1e0*);
void Window_DrawPanes(Cont0205d228*);
void Window_FlushLayers(Cont0205d274*);
extern "C" void func_0205da88(void*, int, int, int);
struct Obj0205d2bc;
void Window_TransferLayers(Obj0205d2bc*);

struct Struct_0205d0e0 {
    char unknown_0_[0xA8];
    short unknown_a8_;
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
};
struct Struct_0205d81c;
extern "C" Struct_0205d0e0* func_0205d81c(Struct_0205d81c* arg0, int arg1);

struct TileMap0204bc74;
extern "C" void Background_FillRect(TileMap0204bc74* obj, unsigned short tile, int x, int y, int w, int h, unsigned short palette);

// USA: func_ov017_0219a18c
extern "C" ARM void func_ov017_0219a18c(unsigned char* arg0) {
#if defined(jpn)
 enum {Enum_ov017_0219a18c_16512=0x3e60, Enum_ov017_0219a18c_16500=0x3e54, Enum_ov017_0219a18c_16504=0x3e58, Enum_ov017_0219a18c_180=0x294, Enum_ov017_0219a18c_15360=0x3800, Enum_ov017_0219a18c_3248=0xa90};
#else
 enum {Enum_ov017_0219a18c_16512=0x4080, Enum_ov017_0219a18c_16500=0x4074, Enum_ov017_0219a18c_16504=0x4078, Enum_ov017_0219a18c_180=0xb4, Enum_ov017_0219a18c_15360=0x3c00, Enum_ov017_0219a18c_3248=0xcb0};
#endif
    for (int var0 = 0; var0 < 4; var0++) {
        GameObject* var1 = func_0200ff1c(GameState::GetInstance(), var0);
        if (var1 != 0) {
            func_020534ac((char*)var1);
        }
    }

    if (*(int*)(arg0 + (Enum_ov017_0219a18c_16512)) == 0 || *(int*)(arg0 + (Enum_ov017_0219a18c_16500)) == 0) {
        return;
    }
    if (*(int*)(arg0 + (Enum_ov017_0219a18c_16504)) < 4) {
        return;
    }

    GameState* var2 = GameState::GetInstance();
    if (func_02039750(var2->GetUnknownGameObject()) != -1) {
        return;
    }

    FillEntriesEncoded_02199684((Entry_02199684*)(self + regionalOffset3 + regionalOffset4), 2, 0x800);
    Window_ClearLayers(*(Cont0205d1e0**)(self + 0x3000 + regionalOffset5));
    Window_DrawPanes(*(Cont0205d228**)(self + 0x3000 + regionalOffset5));
    func_0205da88(*(void**)(self + 0x3000 + regionalOffset5), 1, 2, 1);

    GameObject* var3 = var2->GetProtagonist();
    GameObject* var4 = func_0200ff1c(var2, func_020100a8(var2));
    int var5 = 0;
    int var6;
    int var7 = func_02039750(var3);
    int var8 = func_02053604((signed char*)var4);
    switch (var7) {
    case -1:
        break;
    case 0:
        var5 = 1;
        var6 = 0;
        break;
    case 1:
        var5 = 1;
        var6 = 1;
        break;
    case 2:
        var5 = 1;
        var6 = 2;
        break;
    case 3:
        var5 = 1;
        var6 = 3;
        break;
    }

    if (found && entry >= 0) {
        Elem_0205d81c* elem = FindElementByC40205d81c(*(Struct_0205d81c**)(self + 0x3000 + regionalOffset5), key);
        if (elem != 0) {
            Background_FillRect((TileMap0204bc74*)(self + regionalOffset3 + regionalOffset4), 1, elem->x, elem->y, elem->w, elem->h, 0xf);
        }
    }

    Window_FlushLayers(*(Cont0205d274**)(self + 0x3000 + regionalOffset5));
    if (TestFlags04((GameResources*)self, 0x10000) == 0) {
        Window_TransferLayers(*(Obj0205d2bc**)(self + 0x3000 + regionalOffset5));
    }
    func_ov017_021996bc((Struct_ov017_02199684*)(arg0 + Enum_ov017_0219a18c_180 + Enum_ov017_0219a18c_15360), 2);
}
