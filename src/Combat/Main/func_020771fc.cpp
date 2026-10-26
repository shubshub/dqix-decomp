#include <globaldefs.h>
#include "World/Object3D.h"

#if defined(jpn)
enum { Enum_020771fc_24 = 0x14 };
#else
enum { Enum_020771fc_24 = 0x18 };
#endif

struct Struct_020771fc {
    char unknown_0_[4];
    short unknown_4_;
    short unknown_6_;
    short unknown_8_;
};

struct Struct_020771fc_2 {
    char unknown_0_[2];
    short unknown_2_;
    short unknown_4_;
    char unknown_6_[0x3e];
    Vector3i unknown_44_;
    Vector3i unknown_50_;
    char unknown_5c_[0xae - 0x5c];
    short unknown_ae_;
    char unknown_b0_[2];
    unsigned short unknown_b2_;
    unsigned short unknown_b4_;
    char unknown_b6_[0x139 - 0xb6];
    unsigned char unknown_139_;
    char unknown_13a_[0x154 - 0x13a];
    int unknown_154_;
    Vector3i unknown_158_;
    unsigned short unknown_164_;
    char unknown_166_[0x17c - 0x166];
    unsigned char unknown_17c_;
};

struct Struct_020fdd44;
struct Struct_0201a300_11;
struct Struct_02033b68;
struct Struct_02033f44;
struct Struct_02033834_2;
struct Struct_0202c1a4;
struct Struct_020771fc_3 {
    unsigned short unknown_0_;
#if defined(jpn)
    char unknown_2_[0x442];
#else
    char unknown1_2_[0x422];
#endif
    int unknown_424_;
};

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void* g);
extern "C" int func_020322c0(void* p, int* s);
extern "C" void func_020794f8(Actor_020771fc* obj, int a, int b);
extern "C" Probe_02012fe4* Zone3D_GetInstance(void);
extern "C" int Zone3D_GetGroundHeight(Probe_02012fe4* p, Vector3i* d);
extern "C" void func_ov017_021c9400(int id, int slot, int heading, Vector3i pos, Vector3i vec, int last);
int LinkSession_GetOwnSlot(SearchStruct0202c1a4* s);
int LinkSession_IsActive(int* g);
Entry_02028bd0* ZoneRecords_GetInstance(void);
Entry_02028bd0* ZoneRecords_Find(Entry_02028bd0* base, int key);
TableEntry_020771fc* FindListEntryById(List_020283c0* list, int key);
void GameObject_SetMotionState(Obj02033b68* obj, int value);
void* GameObject_GetWallHit(BitFlag02033f44* obj);
void TrySetMode02076ccc(void* obj, int mode);
void GameObject_SetFacing(Obj02033834* obj, int value);

// USA: func_020771fc
extern "C" ARM void func_020771fc(Actor_020771fc* obj) {
    void* g = LinkSession_GetInstance();
    Vector3i a = obj->pos44;
    a.y = 0;
    Vector3i b = obj->pos158;
    b.y = 0;
    int dist = Vector3fix_Distance(&a, &b);
    GameObject_SetMotionState((Obj02033b68*)obj, 1);
    switch (obj->mode) {
    case 0:
        arg0->unknown_b4_ = 0;
        arg0->unknown_b2_ = 0;
        break;
    case 1:
        arg0->unknown_b4_ = 0x9a;
        arg0->unknown_b2_ = 0x9a;
        break;
    case 2:
        arg0->unknown_b4_ = 0xe6;
        arg0->unknown_b2_ = 0xe6;
        break;
    case 3:
        arg0->unknown_b4_ = 0x1c2;
        arg0->unknown_b2_ = 0x1c2;
        break;
    }
    int moved = 0;
    void* p = GameObject_GetWallHit((BitFlag02033f44*)obj);
    int found = 0;
    if (p != 0) {
        int s = obj->fae;
        if (func_020322c0(p, &s) < 0x199) {
            found = 1;
        }
    }
    if (found != 0) {
        TrySetMode02076ccc(obj, 1);
        obj->f154 = 0;
        obj->f17c = 1;
        if (LinkSession_IsActive((int*)g) != 0) {
            func_020794f8(obj, 0, 1);
        }
        return;
    }
    if (var5 == 0) {
        Vector3i var8;
        Vector3fix_Subtract(&arg0->unknown_158_, &var1, &var8);
        if (Vector3fix_Length(&var8) < 0x1000) {
            var4 = 1;
            func_02076ccc(arg0, 1);
        }
        Vector3fix_Normalize(&c, &c);
        GameObject_SetFacing((Obj02033834*)obj, fix32_Atan2(c.x, c.z));
    }
    if (dist < 0x1000) {
        Vector3i d = obj->pos44;
        if (LinkSession_IsHostOrSolo(g) != 0) {
            Entry_02028bd0* table = ZoneRecords_GetInstance();
            int id = ((Object3D*)obj)->GetField06();
            Entry_02028bd0* entry = ZoneRecords_Find(table, id);
            if (entry != 0) {
                List_020283c0* list = (List_020283c0*)((char*)entry + EntryListOffset);
                if (list != 0) {
                    TableEntry_020771fc* row = FindListEntryById(list, obj->f164);
                    if (row != 0) {
                        d.y = row->y << 0xc;
                        obj->pos44 = d;
                    }
                }
            }
            Probe_02012fe4* probe = Zone3D_GetInstance();
            unsigned short key = probe->key;
            if (key == ((Object3D*)obj)->GetField06() && probe->f424 == 0) {
                d.y = Zone3D_GetGroundHeight(probe, &d);
                obj->pos44 = d;
            }
        }
        var4 = 1;
        func_02076ccc(arg0, 1);
    }
    if (var4 == 0) {
        return;
    }
    if (LinkSession_IsActive((int*)g) == 0) {
        return;
    }
    if (LinkSession_GetOwnSlot((SearchStruct0202c1a4*)g) != 0) {
        return;
    }
    int var17 = ((Object3D*)arg0)->GetField06();
    int var18 = arg0->unknown_2_;
    int var19 = arg0->unknown_4_ - 0x70;
    Vector3i* var20 = &arg0->unknown_44_;
    Vector3i* var21 = &arg0->unknown_50_;
    int var22 = var19 % 0xc;
    if (var22 >= 0 && var22 < 0xc) {
        func_ov017_021c9400(var17, var22, var18, *var20, *var21, -1);
    }
}
