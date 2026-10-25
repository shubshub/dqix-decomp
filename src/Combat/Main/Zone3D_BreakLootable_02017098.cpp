#include <globaldefs.h>
#include "Graphics/Vector.h"
#include "World/LootableContainer.h"
#include "World/ZoneLootableRecord.h"

class Zone3D;
struct SelfObj792c;
struct Struct020478bc;
struct SePlayer;

struct Entry02017098* Zone3D_GetLootable(Zone3D* zone, int index);
extern "C" void func_0204792c(struct SelfObj792c* self, char* name);
void RecomputeField0x7c(struct Struct020478bc* o, int newIndex);
extern "C" float _fflt(int value);
extern "C" float _fmul(float a, float b);
extern "C" int _ffix(float value);
void SePlayer_Play(struct SePlayer* obj, int a, int b);

extern char data_020ef222[];
extern int g_sePlayer;

struct Struct_02017098_5 {
    char unknown_0_[0x1c];
    Vector3i unknown_1c_;
    char unknown_28_[0x88 - 0x1c - 0xc];
};

struct Entry02017098 {
    unsigned short id;
    short state;                // ZoneLootableState
    short field4;
    char pad6[0x24 - 0x06];
    Vector3i position;
    char pad30[0x118 - 0x30];
    struct Segment02017098 segments[4];
    Vector3i offsets[4];
};

// Main, originally func_02017098 (USA 0x02017098, EUR 0x020170a8, JPN 0x02016e38)
extern "C" ARM void Zone3D_BreakLootable(Zone3D* zone, int index) {
    struct Entry02017098* e = Zone3D_GetLootable(zone, index);
    if (e == NULL) return;

    e->state = ZoneLootableState_Breaking;
    func_0204792c((struct SelfObj792c*)((char*)e + 8), data_020ef222);
    RecomputeField0x7c((struct Struct020478bc*)((char*)e + 0x90), 1);

    fix32_t var1 = 0x4b5c;
    for (int var2 = 0; var2 < 4; var2++) {
        struct Struct_02017098_5* var3 = &var0->unknown_118_[var2];
        var3->unknown_1c_ = var0->unknown_24_;
        int var4 = FIX32_MULTIPLY(fix32sin(var1), 0x80);
        int var5 = _ffix(_fmul(4.0f, _fflt(0x80)));
        int var6 = FIX32_MULTIPLY(fix32cos(var1), 0x80);
        func_020130a8(&var0->unknown_338_[var2], var4, var5, var6);
        var1 = fix32ReduceAngle0To2Pi(var1 + 0x1922);
    }

    LootableContainerManager::Container* container =
        LootableContainerManager::GetMainInstance()->GetContainerByID(e->id, NULL);
    if (container != NULL) {
        if (container->containerType == LootableContainerType_Pot) {
            SePlayer_Play((struct SePlayer*)&g_sePlayer, 0x10, 0);
        } else if (container->containerType == LootableContainerType_Barrel) {
            SePlayer_Play((struct SePlayer*)&g_sePlayer, 0x11, 0);
        }
    }

    var0->unknown_4_ = 0;
}
