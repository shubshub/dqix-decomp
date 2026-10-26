#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int func_020881c4(unsigned char* obj);
extern "C" void func_02088150(void* obj);
extern "C" void func_02088220(void*, int);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
extern "C" void func_ov000_0215a88c(void* objRaw, void* arg1, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, unsigned long long arg4, int g);
extern "C" void func_ov000_0215fe84(void* obj, void* node, int idx);

struct Struct_ov024_021e5ec4 { char pad0[0x2d]; unsigned char unknown_2d_; };
struct Struct_ov024_021e5ec4_2 { char pad0[8]; struct Struct_ov024_021e5ec4* unknown_8_; char pad1[4]; unsigned char* unknown_10_; };
struct Struct_ov024_021e5ec4_3 { char pad0[0x24]; unsigned char level; };

// USA: func_ov024_021e5ec4
extern "C" ARM void func_ov024_021e5ec4(struct Struct_ov024_021e5ec4_2* obj, int id) {
    GameObject* c = GetCombatantByID((int)obj->unknown_10_, id);
    if (!c) return;
    if (!func_020881c4((unsigned char*)c->currentStats_)) return;

    int level;
    int msg = 0;
    level = ((struct Struct_ov024_021e5ec4_3*)c->currentStats_)->level;
    switch (level + 1) {
    case 1: msg = 0x31; break;
    case 2: msg = 0x32; break;
    case 3: msg = 0x33; break;
    case 4: msg = 0x34; break;
    }

    void* entry = func_ov000_0215e958(obj->unknown_10_);
    if (!entry) return;
    union { struct { int lo; int hi; }; unsigned long long v; } local;
    local.lo = 0;
    local.hi = 0;
    if (level + 1 >= 4) {
        func_02088150(c->currentStats_);
        func_ov000_02159eac(obj->unknown_10_, &local, 7);
        func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, local.v, 0);
        func_ov000_0215fe84(obj->unknown_8_, entry, 2);
        obj->unknown_10_[0x8e02]++;
        obj->unknown_8_->unknown_2d_ = 1;
    } else {
        func_02088220(c->currentStats_, level + 1);
        func_ov000_02159eac(obj->unknown_10_, &local, 0x23);
        func_ov000_0215cd44(obj->unknown_10_, entry, c, (short)(level + 1), local.v, 0);
        func_ov000_0215fe84(obj->unknown_8_, entry, 2);
        obj->unknown_10_[0x8e02]++;
    }
    func_ov000_0215a88c(obj->unknown_10_, entry, (unsigned short)msg);
}
