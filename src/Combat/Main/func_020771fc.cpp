#include <globaldefs.h>
#include "World/Object3D.h"

#if defined(jpn)
enum { EntryListOffset = 0x14 };
#else
enum { EntryListOffset = 0x18 };
#endif

struct Struct_020771fc {
    char pad0[4];
    short x;
    short y;
    short z;
};

struct Struct_020771fc_2 {
    char pad0[2];
    short f2;
    short f4;
    char pad6[0x3e];
    Vector3i unknown_44_;
    Vector3i unknown_50_;
    char unknown_5c_[0xae - 0x5c];
    short unknown_ae_;
    char unknown_b0_[2];
    unsigned short unknown_b2_;
    unsigned short unknown_b4_;
    char unknown_b6_[0x139 - 0xb6];
    unsigned char mode;
    char unknown_13a_[0x154 - 0x13a];
    int f154;
    Vector3i unknown_158_;
    unsigned short unknown_164_;
    char unknown_166_[0x17c - 0x166];
    unsigned char unknown_17c_;
};

struct Entry_02028bd0;
struct Struct_0201a300_11;
struct Obj02033b68;
struct BitFlag02033f44;
struct Obj02033834;
struct SearchStruct0202c1a4;
struct Probe_02012fe4 {
    unsigned short key;
#if defined(jpn)
    char pad2[0x442];
#else
    char pad2[0x422];
#endif
    int f424;
};

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void* g);
extern "C" int func_020322c0(void* p, int* s);
extern "C" void func_020794f8(Struct_020771fc_2* obj, int a, int b);
extern "C" Probe_02012fe4* Zone3D_GetInstance(void);
extern "C" int Zone3D_GetGroundHeight(Probe_02012fe4* p, Vector3i* d);
extern "C" void func_ov017_021c9400(int id, int slot, int heading, Vector3i pos, Vector3i vec, int last);
extern "C" int LinkSession_GetOwnSlot(SearchStruct0202c1a4* s);
extern "C" int LinkSession_IsActive(int* g);
extern "C" Entry_02028bd0* ZoneRecords_GetInstance(void);
extern "C" Entry_02028bd0* ZoneRecords_Find(Entry_02028bd0* base, int key);
extern "C" Struct_020771fc* func_020283c0(Struct_0201a300_11* list, int key);
extern "C" void GameObject_SetMotionState(Obj02033b68* obj, int value);
extern "C" void* GameObject_GetWallHit(BitFlag02033f44* obj);
extern "C" void func_02076ccc(void* obj, int mode);
extern "C" void GameObject_SetFacing(Obj02033834* obj, int value);

// USA: func_020771fc
extern "C" ARM void func_020771fc(Struct_020771fc_2* obj) {
    void* g = LinkSession_GetInstance();
    Vector3i a = obj->unknown_44_;
    a.y = 0;
    Vector3i b = obj->unknown_158_;
    b.y = 0;
    int dist = Vector3fix_Distance(&a, &b);
    GameObject_SetMotionState((Obj02033b68*)obj, 1);
    switch (obj->mode) {
    case 0:
        obj->unknown_b4_ = 0;
        obj->unknown_b2_ = 0;
        break;
    case 1:
        obj->unknown_b4_ = 0x9a;
        obj->unknown_b2_ = 0x9a;
        break;
    case 2:
        obj->unknown_b4_ = 0xe6;
        obj->unknown_b2_ = 0xe6;
        break;
    case 3:
        obj->unknown_b4_ = 0x1c2;
        obj->unknown_b2_ = 0x1c2;
        break;
    }
    int moved = 0;
    void* p = GameObject_GetWallHit((BitFlag02033f44*)obj);
    int found = 0;
    if (p != 0) {
        int s = obj->unknown_ae_;
        if (func_020322c0(p, &s) < 0x199) {
            found = 1;
        }
    }
    if (found != 0) {
        func_02076ccc(obj, 1);
        obj->f154 = 0;
        obj->unknown_17c_ = 1;
        if (LinkSession_IsActive((int*)g) != 0) {
            func_020794f8(obj, 0, 1);
        }
        return;
    }
    if (p == 0) {
        Vector3i c;
        Vector3fix_Subtract(&obj->unknown_158_, &a, &c);
        if (Vector3fix_Length(&c) < 0x1000) {
            moved = 1;
            func_02076ccc(obj, 1);
        }
        Vector3fix_Normalize(&c, &c);
        GameObject_SetFacing((Obj02033834*)obj, fix32_Atan2(c.x, c.z));
    }
    if (dist < 0x1000) {
        Vector3i d = obj->unknown_44_;
        if (LinkSession_IsHostOrSolo(g) != 0) {
            Entry_02028bd0* table = ZoneRecords_GetInstance();
            int id = ((Object3D*)obj)->GetField06();
            Entry_02028bd0* entry = ZoneRecords_Find(table, id);
            if (entry != 0) {
                Struct_0201a300_11* list = (Struct_0201a300_11*)((char*)entry + EntryListOffset);
                if (list != 0) {
                    Struct_020771fc* row = func_020283c0(list, obj->unknown_164_);
                    if (row != 0) {
                        d.y = row->y << 0xc;
                        obj->unknown_44_ = d;
                    }
                }
            }
            Probe_02012fe4* probe = Zone3D_GetInstance();
            unsigned short key = probe->key;
            if (key == ((Object3D*)obj)->GetField06() && probe->f424 == 0) {
                d.y = Zone3D_GetGroundHeight(probe, &d);
                obj->unknown_44_ = d;
            }
        }
        moved = 1;
        func_02076ccc(obj, 1);
    }
    if (moved == 0) {
        return;
    }
    if (LinkSession_IsActive((int*)g) == 0) {
        return;
    }
    if (LinkSession_GetOwnSlot((SearchStruct0202c1a4*)g) != 0) {
        return;
    }
    int id = ((Object3D*)obj)->GetField06();
    int heading = obj->f2;
    int wanted = obj->f4 - 0x70;
    Vector3i* pos = &obj->unknown_44_;
    Vector3i* vec = &obj->unknown_50_;
    int slot = wanted % 0xc;
    if (slot >= 0 && slot < 0xc) {
        func_ov017_021c9400(id, slot, heading, *pos, *vec, -1);
    }
}
