#if defined(jpn)
enum { RegionOffset36fc = 0x34ec, Enum_ov017_021cfb0c_15116 = 0x3afc };
#else
enum { RegionOffset36fc = 0x36fc, Enum_ov017_021cfb0c_15116 = 0x3b0c };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"

struct HeadNode02046b24;
struct ListHead02046b60;
struct TailList020469b4;
struct TailNode020469b4;
struct SearchStruct0202c1a4;

struct Struct_ov017_021be40c {
    unsigned char pad0[0x10];
    Vector3i pos;
    int zoneId;
};

struct Struct_ov017_021cfb0c {
    unsigned char pad0[0x14];
    int count;
};

struct Struct_ov017_021cfb0c_2 {
    unsigned char pad0[RegionOffset36fc];
    HeadNode02046b24** list;
    unsigned char unknown_3700_[Enum_ov017_021cfb0c_15116 - 0x3700];
    struct Struct_ov017_021cfb0c* counter;
    unsigned char unknown_3b10_[0x3ca4 - 0x3b10];
    struct Struct_ov017_021be40c* node;
};

struct Struct_ov017_021cfb0c_3 {
    unsigned char pad0[0xc];
    int zoneId;
    Vector3i pos;
};

extern "C" int LinkSession_IsHostOrSolo(struct SearchStruct0202c1a4* search);
extern "C" unsigned short* Zone3D_GetInstance(void);
extern "C" void* GameState_GetZoneTransition(GameState* battleStruct);
extern "C" int FieldTaskQueue_GetCurrentKind(HeadNode02046b24** list);
extern "C" int ZoneId_IsGrotto(int v);
extern "C" int func_02046b60(ListHead02046b60* list, int id);
extern "C" void func_ov017_021be40c(struct Struct_ov017_021be40c* obj);
extern "C" void func_020469b4(TailList020469b4* list, TailNode020469b4* node);

// USA: func_ov017_021cfb0c
extern "C" ARM void func_ov017_021cfb0c(int unused0, void* unused1, GameState* battleStruct, struct Struct_ov017_021cfb0c_2* ov, struct SearchStruct0202c1a4* search) {
    int flag;
    unsigned short* zone;
    struct Struct_ov017_021cfb0c_3* grotto;
    unsigned short zoneId;
    HeadNode02046b24** list;
    unsigned short* cur;
    struct Struct_ov017_021be40c* node;

    if (LinkSession_IsHostOrSolo(search) != 0) {
        return;
    }

    zone = Zone3D_GetInstance();
    battleStruct->GetLeader();
    zoneId = *zone;
    grotto = (struct Struct_ov017_021cfb0c_3*)battleStruct->GetGrottoStruct();
    list = ov->list;
    flag = 0;
    cur = (unsigned short*)GameState_GetZoneTransition(battleStruct);
    if (FieldTaskQueue_GetCurrentKind(list) == 3) {
        if (ZoneId_IsGrotto(*cur)) {
            flag = 1;
        }
    }
    if (!ZoneId_IsGrotto(zoneId) && !flag) {
        return;
    }

    Vector3i pos = grotto->pos;
    pos.z += 0x2000;
    if (func_02046b60((ListHead02046b60*)list, 3) || func_02046b60((ListHead02046b60*)list, 1)) {
        unsigned short id = *(unsigned short*)GameState_GetZoneTransition(battleStruct);
        if (id == 0xc3b5) {
            return;
        }
        if (!ZoneId_IsGrotto(id)) {
            return;
        }
    }

    if (FieldTaskQueue_GetCurrentKind(list) == 0x1a) {
        if (ov->counter->count >= 6) {
            return;
        }
    }
    if (func_02046b60((ListHead02046b60*)list, 0x4e)) {
        return;
    }

    node = ov->node;
    func_ov017_021be40c(node);
    node->pos = pos;
    node->zoneId = grotto->zoneId;
    func_020469b4((TailList020469b4*)list, (TailNode020469b4*)node);
}
