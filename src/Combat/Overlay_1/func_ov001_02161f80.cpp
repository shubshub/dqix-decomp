#include <globaldefs.h>
#include "Combat/Main/CopyRecord0200fbb4.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" void* GameState_GetZoneTransition(GameState*);
extern "C" void Zone3D_GetInstance(void);
extern "C" int func_ov017_021d60f4(void* obj);
extern "C" float func_ov017_021d6110(void* obj);
struct Vector3i;
extern "C" void func_02070378(char*);

struct S3f8_02161f80 {
    short field0;
    char field2;
    char pad1[4];
    char unknown_7_;
    char pad2[8];
    int unknown_10_[3];
    short field1c;
    char pad3[2];
    int field20;
    char pad4[0x68 - 0x24];
    char field68;
    char unknown_69_;
};

// USA: func_ov001_02161f80
extern "C" ARM int func_ov001_02161f80(void* target, int count) {
    int var0[3];
    void* battle = GameState::GetInstance();
    struct S3f8_02161f80* obj = (struct S3f8_02161f80*)GameState_GetZoneTransition((GameState*)battle);
    Zone3D_GetInstance();
    int flag2 = -1;
    int var4;
    int flag = func_ov017_021d60f4(target);
    var0[0] = (int)(4096.0f * func_ov017_021d6110((char*)target + 0x8));
    var0[1] = (int)(4096.0f * func_ov017_021d6110((char*)target + 0x10));
    var0[2] = (int)(4096.0f * func_ov017_021d6110((char*)target + 0x18));
    var4 = (int)(4096.0f * func_ov017_021d6110((char*)target + 0x20));
    int cnt = count;
    if (cnt > 5) {
        flag2 = func_ov017_021d60f4((char*)target + 0x28);
    }
    func_02070378((char*)obj);
    obj->field2 = 1;
    obj->unknown_7_ = 1;
    obj->field0 = (short)flag;
    *(Vector3i*)obj->unknown_10_ = *(Vector3i const*)var0;
    obj->field1c = (short)var4;
    obj->field20 = flag2;
    void* p = ((char*)GetGameResources()) + 0x3000;
#if defined(jpn)
    void* q = *(void**)((char*)p + 0x524);
#else
    void* q = *(void**)((char*)p + 0x734);
#endif
    if (q != NULL && *((unsigned char*)q + 3) != 0) {
        unsigned short v = *(unsigned short*)((char*)q + 8);
        if (v == 0x733d || v == 0x7340) {
            obj->unknown_69_ = 1;
        }
    }
    GameState_SetZoneTransition(battle, obj);
    return 1;
}
