#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Vec3 { int x; int y; int z; };

struct U16Field0x6_020375f8 { char unk[0x6]; unsigned short field; };

struct SePlayer;
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);

struct Obj02033834;
extern "C" void GameObject_SetFacing(struct Obj02033834* obj, int arg);

struct Obj02033b68;
extern "C" void GameObject_SetMotionState(struct Obj02033b68* obj, int newVal);

struct S02037418;

extern "C" struct Vec3 func_02034104(void* combatant);
extern "C" int fix32_Atan2(int x, int z);

extern char g_sePlayer;

struct Struct_02078898 {
    char pad0[0x6];
    unsigned short field6;
    char pad1[0x44 - 0x8];
    struct Vec3 unknown_44_;
    char pad2[0xb2 - 0x50];
    unsigned short fieldB2;
    char pad3[0x166 - 0xb4];
    unsigned short unknown_166_;
    char pad4[0x17c - 0x168];
    unsigned char unknown_17c_;
};

#if defined(jpn)
enum { Enum_02078898_1844 = 0x524 };
#else
enum { Enum_02078898_1844 = 0x734 };
#endif

// USA: func_02078898
extern "C" ARM int func_02078898(struct Struct_02078898* p) {
    GameState* bs = GameState::GetInstance();
    unsigned short id = p->unknown_166_;
    GameObject* combatant = bs->GetWanderingMonsterByIndex(id);
    if (combatant == 0) return 0;

    void* ov = GetGameResources();
    char* g = (char*)ov + 0x3000;
    void* var5 = *(void**)(g + Enum_02078898_1844);

    GameObject* other = bs->GetProtagonist();
    unsigned short a = ((Object3D*)((struct U16Field0x6_020375f8*)other))->GetField06();
    unsigned short b = ((Object3D*)((struct U16Field0x6_020375f8*)p))->GetField06();
    if (a == b && *((unsigned char*)var5 + 3) == 0) {
        SePlayer_Play((struct SePlayer*)&g_sePlayer, 6, 0);
    }

    struct Vec3 pos = func_02034104(combatant);
    struct Vec3 diff;
    Vector3fix_Subtract((const Vector3fix*)&pos, (const Vector3fix*)&p->unknown_44_, (Vector3fix*)&diff);
    Vector3fix_Normalize((const Vector3fix*)&diff, (Vector3fix*)&diff);
    int angle = fix32_Atan2(diff.x, diff.z);
    GameObject_SetFacing((struct Obj02033834*)p, angle);

    p->fieldB2 = 0;
    GameObject_SetMotionState((struct Obj02033b68*)p, 0);
    ((Object3D*)((unsigned char*)p))->DisableFlag(0x80);
    ((Object3D*)((struct S02037418*)p))->SetInheritedAlpha(0x1f);
    p->unknown_17c_ = 0;
    return 1;
}
