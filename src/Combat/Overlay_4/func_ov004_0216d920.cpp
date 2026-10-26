#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Resource/Brightness.h"

extern "C" unsigned char func_0200fb9c(char* obj);
extern "C" void func_0200fb94(char* obj, unsigned char value);
extern "C" void func_02012010(void* obj, int value);
extern "C" unsigned char func_02012034(void* obj);
extern "C" void func_02012028(void* obj, unsigned char value);
extern "C" void func_ov017_0218d258(void* obj);
extern "C" void func_0209ca70(void* obj, int val);

struct Actor0209c678;
extern "C" void BgmPlayer_FadeOut(struct Actor0209c678* actor, int arg);
struct Actor0209c20c;
extern "C" void func_0209c20c(struct Actor0209c20c* actor);
struct Obj_0205e8ec;
extern "C" void func_0205e8ec(struct Obj_0205e8ec* a);
struct Obj0205e9f4;
extern "C" void func_0205e9f4(struct Obj0205e9f4* obj, int state);
struct Struct_02011544;
extern "C" void func_02011544(struct Struct_02011544* state);

extern int g_bgmPlayer;
extern int g_sePlayer;
extern unsigned char data_ov004_02171034[];

#if defined(jpn)
enum { kStateIndex = 6, Enum_ov004_0216d920_2 = 0, Enum_ov004_0216d920_3 = 5, kContextIndex = 7, Enum_ov004_0216d920_5 = 3 };
#else
enum { kStateIndex = 1, Enum_ov004_0216d920_2 = 2, Enum_ov004_0216d920_3 = 3, kContextIndex = 4, Enum_ov004_0216d920_5 = 5 };
#endif

// USA: func_ov004_0216d920
extern "C" ARM int func_ov004_0216d920() {
    GameState* bs = GameState::GetInstance();
    GameResources* obj = GetGameResources();
    if (func_0200fb9c((char*)bs) != 2) {
        BgmPlayer_FadeOut((struct Actor0209c678*)&g_bgmPlayer, 0);
        func_0209c20c((struct Actor0209c20c*)&g_bgmPlayer);
        func_0205e8ec((struct Obj_0205e8ec*)&g_sePlayer);
    }
    func_0209ca70((void*)&g_bgmPlayer, data_ov004_02171034[kContextIndex]);
    func_0205e9f4((struct Obj0205e9f4*)&g_sePlayer, data_ov004_02171034[kStateIndex]);
    ClearFlags00(obj, -1);
    ClearFlags04(obj, -1);
    ClearFlags08(obj, -1);
    func_ov017_0218d258(obj);
    func_02012010(bs, 5);
    if (data_ov004_02171034[Enum_ov004_0216d920_2] == 1 && data_ov004_02171034[Enum_ov004_0216d920_3] != 4) {
        func_0200fb94((char*)bs, 6);
        func_02012010(bs, 2);
    }
    if (func_02012034(bs) == 1) {
        func_0200fb94((char*)bs, 6);
        func_02012010(bs, 0);
        func_02012028(bs, 0);
    }
    if (data_ov004_02171034[Enum_ov004_0216d920_5] != 0) {
        func_02011544((struct Struct_02011544*)bs);
        data_ov004_02171034[Enum_ov004_0216d920_5] = 0;
    }
    return 0;
}
