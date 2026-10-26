#if defined(jpn)
enum { Enum_02077500_24 = 0x14 };
#else
enum { Enum_02077500_24 = 0x18 };
#endif

#include <globaldefs.h>
#include "World/Object3D.h"

struct Entry_02028bd0;
struct Struct_0201a300_11;
struct U16Field0x6_020375f8;
struct Struct020372b8;

struct Struct_02077500 {
    int x;
    int y;
    int z;
};

struct Struct_02077500_2 {
    char pad0[4];
    short x;
    short y;
    short z;
};

struct Struct_02077500_3 {
    char pad0[2];
    short f2;
    short f4;
    char pad6[0xa8];
    short unknown_ae_;
    char unknown_b0_[2];
    short unknown_b2_;
    char unknown_b4_[0xa4];
    Struct_02077500 pos;
    unsigned short entryId;
};

extern "C" Entry_02028bd0* ZoneRecords_GetInstance();
extern "C" Entry_02028bd0* ZoneRecords_Find(Entry_02028bd0* table, int id);
extern "C" Struct_02077500_2* func_020283c0(Struct_0201a300_11* list, int id);
extern "C" void LinkSession_GetInstance();
extern "C" int LinkSession_IsHostOrSolo();
extern "C" void func_ov017_021c927c(int a, int b, int c, Struct_02077500 pos, int d, int e, int f);

// USA: func_02077500
extern "C" ARM int func_02077500(Struct_02077500_3* obj) {
    Entry_02028bd0* table = ZoneRecords_GetInstance();
    if (table == 0) {
        return 0;
    }
    Entry_02028bd0* entry = ZoneRecords_Find(table, ((Object3D*)((U16Field0x6_020375f8*)obj))->GetField06());
    if (entry == 0) {
        return 0;
    }
    Struct_0201a300_11* list = (Struct_0201a300_11*)((char*)entry + Enum_02077500_24);
    if (list == 0) {
        return 0;
    }
    obj->unknown_b2_ = 0;
    ((Object3D*)((Struct020372b8*)obj))->TransitionInheritedAlpha(0, 0xfa);
    ((Object3D*)((unsigned char*)obj))->EnableFlag(0x80);
    LinkSession_GetInstance();
    if (LinkSession_IsHostOrSolo() != 0) {
        Struct_02077500_2* row = func_020283c0(list, obj->entryId);
        if (row == 0) {
            return 0;
        }
        obj->pos.x = row->x << 0xc;
        obj->pos.y = row->y << 0xc;
        obj->pos.z = row->z << 0xc;
        int id = ((Object3D*)((U16Field0x6_020375f8*)obj))->GetField06();
        int wanted = obj->f4 - 0x70;
        int heading = obj->f2;
        Struct_02077500* pos = &obj->pos;
        int height = obj->unknown_ae_;
        int slot = wanted % 0xc;
        if (slot >= 0 && slot < 0xc) {
            func_ov017_021c927c(id, slot, heading, *pos, height, 3, -1);
        }
    }
    return 1;
}
