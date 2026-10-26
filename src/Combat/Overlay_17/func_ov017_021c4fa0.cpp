#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "World/ZoneResourceTree.h"

extern "C" void* LinkSession_GetInstance(void);
extern "C" unsigned short* Zone3D_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void* search);
extern "C" void func_0205e330(void* a, void* b, int c);
extern "C" void* memset(void* dst, int c, unsigned int n);
extern "C" void* LinkMessageQueue_GetInstance(void);

struct Entry_02028bd0 {
    unsigned short id;
    unsigned short unknown_2_0_ : 4;
    unsigned short value : 12;
    unsigned short unknown_4_;
};
extern "C" struct Entry_02028bd0* ZoneRecords_GetInstance(void);
extern "C" struct Entry_02028bd0* ZoneRecords_Find(struct Entry_02028bd0* base, int key);

struct Obj_021bd3a4;
extern "C" int func_ov017_021bd3a4(Obj_021bd3a4* obj);
extern "C" int func_020a35e0(unsigned char* obj, unsigned char index);
extern "C" void* func_ov017_021b8470(void* obj);
extern "C" int func_ov017_021b8b94(void* obj);

struct Struct_ov017_021c4fa0_6 {
    char pad0[8];
    unsigned short field8;
    char padA[8];
    unsigned char field12;
    char unknown_13_[5];
    unsigned short field18;
    unsigned short unknown_1a_;
    unsigned short field1c;
    char pad1e[0x32];
    unsigned short unknown_50_;
    short unknown_52_;
#if defined(jpn)
    char unknown_54_[0xae];
#else
    char unknown1_54_[0xb2];
#endif
    unsigned char unknown_106_;
};

struct Struct_ov017_021c4fa0 {
    char pad0[2];
    unsigned char active;
};

struct Struct_ov017_021c4fa0_2 {
    char pad0[0xc];
    int index;
};

struct Struct_ov017_021c4fa0_3 {
    unsigned short id;
    unsigned short value;
};

struct Struct_ov017_021c4fa0_4 {
    unsigned char unknown_0_;
    unsigned char mode;
    unsigned short field2;
    short field4;
    float time;
    unsigned short fieldC;
    unsigned short unknown_e_;
};

struct Struct_ov017_021c4fa0_5 {
    unsigned char tag;
    struct Struct_ov017_021c4fa0_4 payload;
};

// USA: func_ov017_021c4fa0
extern "C" ARM void func_ov017_021c4fa0(int arg0, int id) {
    GameState* gs;
    unsigned short* cur;
    void* data;
    char* var3;
    GameResources* res;
    Struct_ov017_021c4fa0_4* p;
    Struct_ov017_021c4fa0_2* slot;
    Struct_ov017_021c4fa0_6* unit;
    void* search;
    Struct_ov017_021c4fa0* zone;
    int ok;
    Entry_02028bd0* entry;
    Struct_ov017_021c4fa0_3* iv;
    Struct_ov017_021c4fa0_5 evt;

    gs = GameState::GetInstance();
    search = LinkSession_GetInstance();
    cur = Zone3D_GetInstance();
    res = GetGameResources();
    unit = (Struct_ov017_021c4fa0_6*)res->unknown_ptr_array_371c[6];
    ZoneRecords_GetInstance();
    data = LinkMessageQueue_GetInstance();

    evt.tag = 0x8f;
    p = &evt.payload;
    memset(p, 0, sizeof(*p));
    p->mode = 0;
    p->unknown_0_ = arg0;
    p->time = -1.0f;

    zone = (Struct_ov017_021c4fa0*)res->unknown_ptr_3718;
    var3 = (char*)func_ov017_021b8470(zone);
    slot = (Struct_ov017_021c4fa0_2*)func_ov017_021b8478(zone);

    if (LinkSession_IsHostOrSolo(search)) {
        ok = 1;
        if (unit->unknown_1a_ != id || (unit->unknown_50_ & 0x800)) {
            if (unit->field1c != id) {
                ok = 0;
            }
        }
        if (func_ov017_021bd3a4((Obj_021bd3a4*)unit) && unit->field12 != 0 && unit->unknown_106_ == 0 && ok) {
            p->mode = 1;
            if (unit->field18 == 0) {
                p->field2 = unit->field8;
                p->field4 = unit->unknown_52_;
            } else {
                p->field2 = unit->field18;
                p->field4 = unit->unknown_52_;
            }
        } else if (zone->active != 0 && !(var3 != NULL && var3[0x8e14] != 0) && slot != NULL &&
                   !func_020a35e0((unsigned char*)slot, arg0 & 0xff) && !func_ov017_021b8b94(zone) && slot->index >= 0) {
            p->mode = 2;
            p->field2 = slot->index;
            p->field4 = *cur;
        }

        p->time = gs->GetDayTimer();
        entry = ZoneRecords_Find(ZoneRecords_GetInstance(), id);
        if (entry != NULL) {
            p->fieldC = entry->value;
            p->unknown_e_ = entry->unknown_4_;
        } else {
#if defined(jpn)
            iv = (Struct_ov017_021c4fa0_3*)((char*)res + 0x4204);
#else
            iv = (Struct_ov017_021c4fa0_3*)((char*)res + 0x44b4);
#endif
            if (iv->id == id) {
                p->fieldC = iv->value;
            } else {
                p->fieldC = 0;
            }
            p->unknown_e_ = 0;
        }
    }
    func_0205e330(data, &evt, 0);
}
