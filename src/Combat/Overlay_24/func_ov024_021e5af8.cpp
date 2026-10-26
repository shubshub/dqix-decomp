#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov000_0215a004(void* a0, int arg1, int id2, int flags, void* buf, int extra, int zero, int arg7);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
extern "C" void func_ov000_0215a88c(void* objRaw, void* arg1, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, unsigned long long arg4, int g);
extern "C" void func_ov000_0215fe84(void* obj, void* node, int idx);

struct Struct_ov024_021e5af8 { char pad0[8]; void* unknown_8_; char pad1[4]; void* unknown_10_; };

// USA: func_ov024_021e5af8
extern "C" ARM void func_ov024_021e5af8(struct Struct_ov024_021e5af8* obj, int id, int extra) {
    GameObject* c = GetCombatantByID((int)obj->unknown_10_, id);
    if (!c) return;
    void* entry = func_ov000_0215e958(obj->unknown_10_);
    if (!entry) return;
    union { struct { int lo; int hi; }; unsigned long long v; } local;
    local.lo = 0;
    local.hi = 0;
    func_ov000_0215a004(obj->unknown_10_, id, id, 0xffff, &local, extra, 0, 0x10);
    local.lo = 0;
    local.hi = 0;
    func_ov000_02159eac(obj->unknown_10_, &local, 13);
    func_ov000_0215a88c(obj->unknown_10_, entry, 0x117);
    func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, local.v, 0);
    func_ov000_0215fe84(obj->unknown_8_, entry, 2);
    ((unsigned char*)obj->unknown_10_)[0x8e02]++;
}
