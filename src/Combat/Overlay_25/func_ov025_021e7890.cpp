#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_ov025_021e7890_3 {
#if defined(jpn)
    char pad[0x508];
#else
    char pad[0x718];
#endif
    void* ptr;
};
struct Struct_ov025_021e7890_4 {
    char pad[0x3000];
    Struct_ov025_021e7890_3 sub;
};

struct Struct_02070fe4 {
    unsigned int count : 12;
};
struct Struct_02070f98 {
    unsigned short f : 15;
    unsigned short p2 : 1;
};
struct Struct_02070f98_2 {
    Struct_02070fe4 head;
    struct Struct_02070f98* base;
};
struct Struct_ov025_021e7890_5 {
    char pad[0x400];
    Struct_02070f98_2 list;
};
struct Struct_ov025_021e7890_6 {
    char pad[0x284];
    Struct_ov025_021e7890_5 tableB;
};

struct Struct_ov025_021e7890_7 {
    unsigned int w[0x70 / 4];
};
struct Struct_ov025_021e7890_8 {
    char pad0[0x10];
    float v[3];
    unsigned char unknown_1c_;
    unsigned char unknown_1d_;
    unsigned char unknown_1e_;
    unsigned char unknown_1f_;
    int unknown_20_;
    char pad24[0x4c - 0x24];
    unsigned char unknown_4c_;
    unsigned char unknown_4d_;
    char unknown_4e_[0x70 - 0x4e];
};
struct Struct_ov025_021e7890 {
    char pad[0x13c];
    Struct_ov025_021e7890_8* sub;
};

struct Struct_ov000_0215440c_2;
struct Struct_ov000_0215440c_4 {
    char pad[0x20];
    unsigned short id;
};
struct Struct_ov025_021e7890_2 {
    unsigned short id;
};

extern "C" Struct_ov025_021e7890_6* func_ov017_021b8478(void* node);
extern "C" void* func_ov000_02160130(void);
extern "C" Struct_ov000_0215440c_4* func_ov000_02160094(Struct_ov000_0215440c_2* list, int index);
extern "C" int func_02070fe4(Struct_02070fe4* p);
extern "C" Struct_02070f98* func_02070f98(Struct_02070f98_2* list, int index);
extern "C" void func_0200fd48(GameState* battleStruct, int id);
extern "C" void __clear(void* buf, int n);
extern "C" int func_ov025_021e771c(short* ids, int count, int a, int b);
extern "C" void func_ov000_02161c0c(void* work, int id);
extern "C" void func_ov000_021677fc(void* work);
extern "C" void func_ov000_02167e6c(unsigned char*);
struct Vector3i;

#if defined(jpn)
#define data_ov025_021eef18 data_ov025_021ef200
#define data_ov025_021eef30 data_ov025_021ef218
#endif
extern const unsigned short data_ov025_021eef18[5];
extern const unsigned short data_ov025_021eef30[7];

// USA: func_ov025_021e7890
extern "C" ARM int func_ov025_021e7890(int self, Struct_ov025_021e7890_2* action) {
    Struct_ov025_021e7890_8 local;
    short ids[10];
    Struct_ov025_021e7890_5* tb;
    int i2;
    Struct_ov025_021e7890_4* res;
    Struct_ov025_021e7890_6* r;
    GameState* state;
    void* work;
    Struct_ov000_0215440c_4* node;
    unsigned char mode;
    unsigned char n;
    res = (Struct_ov025_021e7890_4*)GetGameResources();
    state = GameState::GetInstance();
    r = func_ov017_021b8478(res->sub.ptr);
    work = func_ov000_02160130();
    node = func_ov000_02160094((Struct_ov000_0215440c_2*)action, 0);
    if (node == 0) return 1;
    Struct_ov025_021e7890* unit = (Struct_ov025_021e7890*)state->GetCombatantByIndex(node->id);
    if (unit == 0) return 1;
    Struct_ov025_021e7890_8* obj = unit->sub;
    if (obj == 0) return 1;
    *(Struct_ov025_021e7890_7*)&local = *(Struct_ov025_021e7890_7*)obj;
    __clear(ids, 0x14);
    if (action->id == 0x153) {
        memcpy(ids, data_ov025_021eef18, 0xa);
        mode = 1;
        n = 5;
    } else if (action->id == 0x31a) {
        memcpy(ids, data_ov025_021eef30, 0xe);
        mode = 3;
        n = 7;
    } else {
        return 1;
    }
    tb = &r->tableB;
    int count = func_02070fe4(&tb->list.head);
    for (int i = 0; i < count; i++) {
        Struct_02070f98* elem = func_02070f98(&tb->list, i);
        if (elem == 0) continue;
        int found = 1;
        short* q = ids;
        int j = 0;
        while (j < n) {
            if (elem->f == *q) {
                found = 0;
                break;
            }
            j = j + 1;
            q = q + 1;
        }
        if (found) {
            ids[n++] = elem->f;
        }
    }
    func_ov025_021e771c(ids, mode, (int)ids, n);
    func_ov000_02161c0c(work, node->id);
    for (i2 = 0; i2 < 8; i2++) {
        short id = (short)(i2 + 0xc0);
        if (node->id != id) func_0200fd48(state, id);
    }
    func_ov000_021677fc(work);
    func_ov000_02167e6c((unsigned char*)work);
    Struct_ov025_021e7890* var20 = (Struct_ov025_021e7890*)state->GetCombatantByIndex(node->id);
    if (var20 != 0) {
        Struct_ov025_021e7890_8* obj2 = var20->sub;
        if (obj2 != 0) {
            *(Vector3i*)obj2->v = *(Vector3i const*)local.v;
            obj2->unknown_1c_ = local.unknown_1c_;
            obj2->unknown_1d_ = local.unknown_1d_;
            obj2->unknown_1e_ = local.unknown_1e_;
            obj2->unknown_1f_ = local.unknown_1f_;
            obj2->unknown_20_ = local.unknown_20_;
            obj2->unknown_4c_ = local.unknown_4c_;
            obj2->unknown_4d_ = local.unknown_4d_;
        }
    }
    return 1;
}
