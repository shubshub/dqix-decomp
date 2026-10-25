#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Resource/Brightness.h"

extern "C" unsigned char func_0200fb9c(char* arg0);
extern "C" void func_0200fb94(char* arg0, unsigned char arg1);
extern "C" void func_02012010(void* arg0, int arg1);
extern "C" unsigned char func_02012034(void* arg0);
extern "C" void func_02012028(void* arg0, unsigned char arg1);
extern "C" void func_ov017_0218d258(void* arg0);
extern "C" void func_0209ca70(void* arg0, int arg1);

struct Actor0209c678;
void BgmPlayer_FadeOut(struct Actor0209c678* actor, int arg);
struct Actor0209c20c;
void InitActorContext0209c20c(struct Actor0209c20c* actor);
struct Obj_0205e8ec;
void RefreshDisplayState0205e8ec(struct Obj_0205e8ec* a);
struct Obj0205e9f4;
void SetStateAndDispatch0205e9f4(struct Obj0205e9f4* obj, int state);
struct StateBits5ccc_11544;
void SetFlag0x5cccBit0_02011544(struct StateBits5ccc_11544* state);

extern int g_bgmPlayer;
extern int g_sePlayer;
extern unsigned char data_ov004_02171034[];

#if defined(jpn)
enum { Enum_ov004_0216d920_1 = 6, Enum_ov004_0216d920_2 = 0, Enum_ov004_0216d920_3 = 5, Enum_ov004_0216d920_4 = 7, Enum_ov004_0216d920_5 = 3 };
#else
enum { Enum_ov004_0216d920_1 = 1, Enum_ov004_0216d920_2 = 2, Enum_ov004_0216d920_3 = 3, Enum_ov004_0216d920_4 = 4, Enum_ov004_0216d920_5 = 5 };
#endif

// USA: func_ov004_0216d920
extern "C" ARM int func_ov004_0216d920() {
    GameState* bs = GameState::GetInstance();
    GameResources* obj = GetGameResources();
    if (GetByte0x4_0200fb9c((char*)bs) != 2) {
        BgmPlayer_FadeOut((struct Actor0209c678*)&g_bgmPlayer, 0);
        InitActorContext0209c20c((struct Actor0209c20c*)&g_bgmPlayer);
        RefreshDisplayState0205e8ec((struct Obj_0205e8ec*)&g_sePlayer);
    }
    SetModeClamped0209ca70((void*)&g_bgmPlayer, data_ov004_02171034[kContextIndex]);
    SetStateAndDispatch0205e9f4((struct Obj0205e9f4*)&g_sePlayer, data_ov004_02171034[kStateIndex]);
    ClearFlags00(obj, -1);
    ClearFlags04(obj, -1);
    ClearFlags08(obj, -1);
    SetFieldFlag17188_0218d258(obj);
    SetWord0x7f6c_02012010(bs, 5);
    if (data_ov004_02171034[kVariantIndex] == 1 && data_ov004_02171034[kModeIndex] != 4) {
        SetByte0x4_0200fb94((char*)bs, 6);
        SetWord0x7f6c_02012010(bs, 2);
    }
    if (func_02012034(var0) == 1) {
        func_0200fb94((char*)var0, 6);
        func_02012010(var0, 0);
        func_02012028(var0, 0);
    }
    if (data_ov004_02171034[Enum_ov004_0216d920_5] != 0) {
        func_02011544((struct Struct_02011544*)var0);
        data_ov004_02171034[Enum_ov004_0216d920_5] = 0;
    }
    return 0;
}
