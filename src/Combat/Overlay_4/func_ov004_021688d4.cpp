#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int MessageSystem_GetInstance();
extern "C" void* func_0203cf4c(void);
extern "C" void* func_0203df78(void* base, int key);

struct Struct_0203de84;
struct Node020406f8;
extern "C" void func_020406f8(struct Struct_0203de84* dst, struct Node020406f8* n);

struct Struct_ov004_021688d4 { unsigned int v[3]; };

extern "C" int func_0203dfdc(void* base, int key);
struct Struct_02040a90;
extern "C" int func_02040a90(struct Struct_02040a90* obj);

extern "C" int fix32_Atan2(int, int);
struct Obj02033834;
extern "C" void GameObject_SetFacing(struct Obj02033834* obj, int arg);

extern "C" int LinkSession_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void);

extern "C" int func_02011b50(void* obj, int mask);
extern "C" void func_02011b3c(void* obj, unsigned char mask);

struct SePlayer;
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern struct SePlayer g_sePlayer;

// USA: func_ov004_021688d4
extern "C" ARM int func_ov004_021688d4(void) {
    char* base17 = (char*)(int)MessageSystem_GetInstance();
    void* ptr = func_0203cf4c();
    void* node = func_0203df78(ptr, 6);
    if (node) {
        GameObject* combatant = GameState::GetInstance()->GetLeader();
        struct Struct_ov004_021688d4 v1;
        struct Struct_ov004_021688d4 v2;
        struct Struct_ov004_021688d4 tmp;
        func_020406f8((struct Struct_0203de84*)&tmp, (struct Node020406f8*)node);
        v1 = tmp;
        v2 = *(struct Struct_ov004_021688d4*)((char*)combatant + 0x44);

        int idx = func_0203dfdc(ptr, 6);
#if defined(jpn)
        *(int*)(base17 + 0x1708) = idx;
#else
        *(int*)(base17 + 0x1838) = idx;
#endif

        int fieldVal = func_02040a90((struct Struct_02040a90*)node);
#if defined(jpn)
        *(int*)(base17 + 0x170c) = fieldVal;
#else
        *(int*)(base17 + 0x183c) = fieldVal;
#endif

        int dx = (int)v1.v[0] - (int)v2.v[0];
        int dz = (int)v1.v[2] - (int)v2.v[2];
        int var11 = fix32_Atan2(dx, dz);
        int angle = fix32ReduceAngle0To2Pi(var11);
        GameObject_SetFacing((struct Obj02033834*)combatant, angle);
    }

    LinkSession_GetInstance();
    if (LinkSession_IsHostOrSolo()) {
        GameState* bs = GameState::GetInstance();
        if (func_02011b50(bs, 0x10)) {
            SePlayer_Play(&g_sePlayer, 1, 0);
        }
        func_02011b3c(bs, 0x10);
    }
    return 0;
}
