#include <globaldefs.h>
#include "GameState/GameState.h"

int MessageSystem_GetInstance();
void* GetGlobalPtr021075f4_0203cf4c(void);
void* FindEntryPointerByKey0203df78(void* base, int key);

struct Struct_0203de84;
struct Struct_0203de84_2;
extern "C" void func_020406f8(struct Struct_0203de84* arg0, struct Struct_0203de84_2* arg1);

struct Struct_ov004_021688d4 { unsigned int unknown_0_[3]; };

extern "C" int func_0203dfdc(void* arg0, int arg1);
struct Struct_02040a90;
extern "C" int func_02040a90(struct Struct_02040a90* arg0);

extern "C" int fix32_Atan2(int, int);
struct Obj02033834;
void GameObject_SetFacing(struct Obj02033834* obj, int arg);

extern "C" int func_0202ae18(void);
extern "C" int func_0202c508(void);

extern "C" int func_02011b50(void* arg0, int arg1);
extern "C" void func_02011b3c(void* arg0, unsigned char arg1);

struct SePlayer;
extern void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern struct SePlayer g_sePlayer;

// USA: func_ov004_021688d4
extern "C" ARM int func_ov004_021688d4(void) {
    char* base17 = (char*)(int)MessageSystem_GetInstance();
    void* ptr = GetGlobalPtr021075f4_0203cf4c();
    void* node = FindEntryPointerByKey0203df78(ptr, 6);
    if (node) {
        GameObject* combatant = GameState::GetInstance()->GetUnknownGameObject();
        struct Vec3Local_021688d4 v1;
        struct Vec3Local_021688d4 v2;
        struct Vec3Local_021688d4 tmp;
        SelectVec3FromSources020406f8((struct Vec3_020406f8*)&tmp, (struct Node020406f8*)node);
        v1 = tmp;
        v2 = *(struct Vec3Local_021688d4*)((char*)combatant + 0x44);

        int var7 = func_0203dfdc(var1, 6);
#if defined(jpn)
        *(int*)(var0 + 0x1708) = var7;
#else
        *(int*)(var0 + 0x1838) = var7;
#endif

        int var8 = func_02040a90((struct Struct_02040a90*)var2);
#if defined(jpn)
        *(int*)(var0 + 0x170c) = var8;
#else
        *(int*)(var0 + 0x183c) = var8;
#endif

        int dx = (int)v1.v[0] - (int)v2.v[0];
        int dz = (int)v1.v[2] - (int)v2.v[2];
        int mid = fix32_Atan2(dx, dz);
        int angle = fix32ReduceAngle0To2Pi(mid);
        GameObject_SetFacing((struct Obj02033834*)combatant, angle);
    }

    func_0202ae18();
    if (func_0202c508()) {
        GameState* bs = GameState::GetInstance();
        if (CheckBitsInField0x63dc_02011b50(bs, 0x10)) {
            SePlayer_Play(&g_sePlayer, 1, 0);
        }
        func_02011b3c(var13, 0x10);
    }
    return 0;
}
