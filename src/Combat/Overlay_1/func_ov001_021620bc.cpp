#include <globaldefs.h>
#include "Combat/Main/CopyRecord0200fbb4.h"
#include "GameState/GameState.h"

extern "C" void* GameState_GetZoneTransition(GameState*);
extern "C" void* Zone3D_GetInstance(void);
struct Vector3i;
extern "C" void func_02070378(char*);

#if defined(jpn)
enum { Enum_ov001_021620bc_9147 = 0x23db, Enum_ov001_021620bc_9152 = 0x23e0, Enum_ov001_021620bc_9164 = 0x23ec };
#else
enum { Enum_ov001_021620bc_9147 = 0x23bb, Enum_ov001_021620bc_9152 = 0x23c0, Enum_ov001_021620bc_9164 = 0x23cc };
#endif

struct S3f8 {
    short field0;
    char field2;
    char pad1[4];
    char unknown_7_;
    char pad2[8];
    int unknown_10_[3];
    short field1c;
    char pad3[0x68 - 0x1e];
    char field68;
};

// USA: func_ov001_021620bc
extern "C" ARM int func_ov001_021620bc(void) {
    int var0[3];
    void* battle = GameState::GetInstance();
    struct S3f8* obj = (struct S3f8*)GameState_GetZoneTransition((GameState*)battle);
    char* data = (char*)Zone3D_GetInstance();
    *(Vector3i*)var0 = *(Vector3i const*)((int*)(data + Enum_ov001_021620bc_9152));
    short var4 = *(short*)(data + Enum_ov001_021620bc_9164);
    func_02070378((char*)obj);
    obj->field2 = 1;
    obj->unknown_7_ = 1;
    obj->field0 = (short)(*(signed char*)(data + Enum_ov001_021620bc_9147) + 0x1c40 + 0x8000);
    *(Vector3i*)obj->unknown_10_ = *(Vector3i const*)var0;
    obj->field1c = var4;
    obj->field68 = 1;
    GameState_SetZoneTransition(battle, obj);
    return 1;
}
