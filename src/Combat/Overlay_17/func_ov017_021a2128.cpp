#include <globaldefs.h>
#include "GameState/GameState.h"

struct Entry_02028bd0;
struct Struct_02073ec4_2;
struct Struct_0206f01c_2;
struct List_020283fc;
struct Struct_02072adc;
struct Obj02033874;
struct Struct_020795e8;
struct Struct_020795e8_2;
struct Struct_02076cc4;
struct Struct_ov017_021a2128_3 { char field_0[0xc]; short radius; short height; };
struct AreaEntry021a2128 {
    short id;
    unsigned short category : 2;
    unsigned short flags : 14;
    short unknown_4_;
    unsigned short unknown_6_;
#if defined(jpn)
    char field_8[0xc];
#else
    char field_8[0x10];
#endif
    char list[0x48];
    char unknown_60_[0x298];
    char monsters[0xc];
    char nodes[0xc];
};
struct FieldMonster021a2128 {
    Object3D object;
    char field_ac[0xc];
    short listIndex;
    char field_ba[0xaa];
    short entryId;
    short unknown_166_;
    short variant;
    short state;
    char unknown_16c_[0x11];
    unsigned char flags;
    char unknown_17e_[2];
    Struct_ov017_021a2128_3* info;
    void* node;
};
#if defined(jpn)
struct Struct_ov017_021a2128 { char field_0[0x2fe0]; int context; };
#else
struct Struct_ov017_021a2128 { char field_0[0x31f0]; int context; };
#endif
extern "C" Entry_02028bd0* ZoneRecords_GetInstance();
extern "C" AreaEntry021a2128* ZoneRecords_Find(Entry_02028bd0*, int);
extern "C" Struct_ov017_021a2128_3* func_0206f4f0(Struct_0206f01c_2*, int);
extern "C" void* func_0206ef18(void*, int);
extern "C" int func_ov017_021a20c0(int, int, int);
extern "C" unsigned short* Zone3D_GetInstance();
extern "C" int* LinkSession_GetInstance();
extern "C" void FieldMonsterState_Init(void*);
extern "C" Struct_02072adc* func_ov017_021a2738(void*, int);
extern "C" void func_02072adc(Struct_02072adc*, Struct_02072adc*);
struct Struct_ov017_021a2128_2 { short field_0; short scale; };
extern "C" Struct_ov017_021a2128_2* func_0209be84(Struct_02073ec4_2*, unsigned int, int);
extern "C" int Zone3D_GetGroundHeight(void*, Vector3fix*);
extern "C" int NodeGraph_FindNodeIndexById(List_020283fc*, int);
extern "C" void GameObject_SnapFacing(Obj02033874*, int);
extern "C" void func_020795e8(Struct_020795e8*, Struct_020795e8_2*);
extern "C" void func_02076ccc(void*, int);
extern "C" void func_02076cc4(Struct_02076cc4*, int);
extern "C" int func_ov017_021a1944();
extern "C" int LinkSession_IsActive(int*);
extern "C" void func_ov017_021c8f3c(int, int);

// USA: func_ov017_021a2128
extern "C" ARM int func_ov017_021a2128(Struct_ov017_021a2128* arena, unsigned short areaId, int monsterId, int variant, const Vector3fix* position, int y, unsigned short entryId, unsigned char flags) {
    AreaEntry021a2128* area = ZoneRecords_Find(ZoneRecords_GetInstance(), areaId);
    if (!area) return 0;
    Struct_ov017_021a2128_3* info = func_0206f4f0((Struct_0206f01c_2*)area->monsters, (short)monsterId);
    void* node = func_0206ef18(area->nodes, (short)monsterId);
    if (!info) return 0;
    if (!node) return 0;
    GameState* state = GameState::GetInstance();
    unsigned short* currentArea = Zone3D_GetInstance();
    int* manager = LinkSession_GetInstance();
    int slot = func_ov017_021a20c0((int)arena, area->category, 12);
    if (slot < 0) return 0;
    FieldMonster021a2128* monster = (FieldMonster021a2128*)state->GetFieldMonsterByIndex(slot);
    if (!monster) return 0;
    FieldMonsterState_Init(monster);
    Struct_02072adc* previous = func_ov017_021a2738(arena, monsterId);
    if (areaId == *currentArea && previous) func_02072adc(previous, (Struct_02072adc*)monster);
    int scale = 0x1000;
    Struct_ov017_021a2128_2* entry = func_0209be84((Struct_02073ec4_2*)area->unknown_60_, monsterId, variant);
    if (entry) scale = entry->scale;
    Vector3fix location __attribute__((aligned(4))) = *position;
    if (areaId == *currentArea) location.y = Zone3D_GetGroundHeight(currentArea, &location);
    monster->object.unknown_2_ = monsterId;
    monster->object.actorIndex_ = slot;
    monster->object.SetField06(areaId);
    monster->variant = variant;
    monster->info = info;
    monster->node = node;
    monster->listIndex = NodeGraph_FindNodeIndexById((List_020283fc*)area->list, entryId);
    monster->entryId = entryId;
    monster->object.position_ = location;
    GameObject_SnapFacing((Obj02033874*)monster, y);
    monster->object.SetRadius(info->radius << 2);
    monster->object.SetHeight(info->height);
    Struct_020795e8_2* fields = (Struct_020795e8_2*)func_0206ef18(area->nodes, (short)monsterId);
    if (fields) func_020795e8((Struct_020795e8*)monster, fields);
    int var13 = (int)(((long long)scale * 0x10a + 0x800) >> 12);
    monster->object.SetScale(var13, var13, var13);
    func_02076ccc(monster, 0);
    func_02076cc4((Struct_02076cc4*)monster, (int)&arena->context);
    monster->state = func_ov017_021a1944();
    monster->flags |= flags;
    monster->object.MakeVisible();
    ++area->unknown_6_;
    if (LinkSession_IsActive(manager)) func_ov017_021c8f3c(slot, -1);
    return slot;
}
