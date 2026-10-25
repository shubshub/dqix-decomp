#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

extern "C" void* Zone3D_GetInstance(void);
struct ListNode0x2037a50;
extern "C" int _ZN8Object3D4DrawEb(void* obj, int flag);
struct Bits40_37464;

struct Vec3_37774 { int a[3]; };
struct Src_37774;
extern "C" void _ZNK8Object3D20MaybeGetShadowSourceEv(struct Vec3_37774* dst, struct Src_37774* src);
void SyncBattleState0208f87c(const void* self, int b, int c, int d, int polygonId);

#if defined(jpn)
enum { RegionOffset38 = 0x58, RegionOffset3c = 0x5c };
#else
enum { RegionOffset38 = 0x38, RegionOffset3c = 0x3c };
#endif

// USA: func_ov017_021973e8  (semantic: SyncCombatantsInRange_021973e8)
extern "C" ARM void func_ov017_021973e8(unsigned int* flagsObj) {
    GameState* bs = GameState::GetInstance();
    void* ctx = Zone3D_GetInstance();
    unsigned short field38 = *(unsigned short*)((char*)ctx + RegionOffset38);
    unsigned int field3c = *(unsigned int*)((char*)ctx + RegionOffset3c);

    if (TestFlags04((GameResources*)flagsObj, 0x100) != 0) return;

    int flag9 = 1;
    if (TestFlags04((GameResources*)flagsObj, 0x1000) != 0) {
        flag9 = 0;
    }

    int id;
    for (id = 0xa0; id < 0xc0; id++) {
        GameObject* c = bs->GetGameObjectByIndex(id);
        if (!c) continue;
        if (((Object3D*)((struct ListNode0x2037a50*)c))->IsChild()) continue;
        if (c->obj3D_.GetFlag(0x40000000) != 0) continue;
        ((Object3D*)((unsigned char*)c))->EnableFlag(4);
        if (!_ZN8Object3D4DrawEb(c, flag9)) continue;
        if (c->obj3D_.GetFlag(0x10) != 0) continue;

        int bits = ((Object3D*)((struct Bits40_37464*)c))->GetInheritedAlpha();
        int computed = (int)((float)field3c / 31.0f * (float)bits);

        struct Vec3_37774 vec;
        _ZNK8Object3D20MaybeGetShadowSourceEv(&vec, (struct Src_37774*)c);
        int intAt64 = ((Object3D*)((unsigned char*)c))->GetRadius();
        SyncBattleState0208f87c(&vec, field38, intAt64, computed, 8);
    }
}
