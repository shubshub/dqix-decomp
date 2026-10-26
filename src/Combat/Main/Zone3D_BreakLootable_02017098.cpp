#include <globaldefs.h>
#include "Graphics/Vector.h"
#include "Sound/SePlayer.h"
#include "World/LootableContainer.h"
#include "World/ZoneLootableRecord.h"

class Zone3D;
struct SelfObj792c;
struct Struct020478bc;

struct ZoneLootableRecord02017098* Zone3D_GetLootable(Zone3D* zone, int index);
extern "C" void func_0204792c(struct SelfObj792c* self, char* name);
void RecomputeField0x7c(struct Struct020478bc* o, int newIndex);
extern "C" float _fflt(int value);
extern "C" float _fmul(float a, float b);
extern "C" int _ffix(float value);

extern char data_020ef222[];

// The four fragments fly out a quarter turn apart, the first at this angle, at this speed sideways and four times it
// upwards (Zone3D_UpdateLootables then moves them and pulls them down)
enum {
    kFirstFragmentAngle = 0x4b5c,
    kFragmentSpeed = 0x80,
};

// The sound effects of a breaking pot and barrel
enum {
    kSoundEffect_PotBreak = 0x10,
    kSoundEffect_BarrelBreak = 0x11,
};

struct ZoneLootableRecord02017098 {
    unsigned short id;
    short state;                // ZoneLootableState
    short breakTimer;
    unsigned char reserved6[2];
    Foo02048004 primary[2];
    Foo02048004 fragments[4];
    Vector3i fragmentVelocities[4];
};

// Main, originally func_02017098 (USA 0x02017098, EUR 0x020170a8, JPN 0x02016e38)
extern "C" ARM void Zone3D_BreakLootable(Zone3D* zone, int index) {
    struct ZoneLootableRecord02017098* lootable = Zone3D_GetLootable(zone, index);
    if (lootable == NULL) return;

    lootable->state = ZoneLootableState_Breaking;
    func_0204792c((struct SelfObj792c*)&lootable->primary[0], data_020ef222);
    RecomputeField0x7c((struct Struct020478bc*)&lootable->primary[1], 1);

    fix32_t angle = kFirstFragmentAngle;
    for (int i = 0; i < 4; i++) {
        Foo02048004* fragment = &lootable->fragments[i];
        fragment->position = lootable->primary[0].position;
        int velocityX = FIX32_MULTIPLY(fix32sin(angle), kFragmentSpeed);
        int velocityY = _ffix(_fmul(4.0f, _fflt(kFragmentSpeed)));
        int velocityZ = FIX32_MULTIPLY(fix32cos(angle), kFragmentSpeed);
        Vector3i_Set(&lootable->fragmentVelocities[i], velocityX, velocityY, velocityZ);
        angle = fix32ReduceAngle0To2Pi(angle + FIX_2PI / 4);
    }

    LootableContainerManager::Container* container =
        LootableContainerManager::GetMainInstance()->GetContainerByID(lootable->id, NULL);
    if (container != NULL) {
        if (container->containerType == LootableContainerType_Pot) {
            SePlayer_Play(&g_sePlayer, kSoundEffect_PotBreak, 0);
        } else if (container->containerType == LootableContainerType_Barrel) {
            SePlayer_Play(&g_sePlayer, kSoundEffect_BarrelBreak, 0);
        }
    }

    lootable->breakTimer = 0;
}
