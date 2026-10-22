#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Input/Input.h"

extern "C" int func_0205d0e0(void* p, int val);
extern "C" int func_ov023_021e2868(void* obj);

struct Block16Words0216e124 { unsigned int w[16]; };
extern struct Block16Words0216e124 data_ov003_0217f5c0;
struct Pair0216e124 { unsigned int a; unsigned int b; };
extern struct Pair0216e124 __ptmf_null;
struct DispatchEntry0216e124 { unsigned int fn; unsigned int locator; };

struct Obj0216e124 {
    char pad0[1];
    signed char field1;
    char pad1[0xc - 2];
    short fieldC;
    short fieldE;
    char pad2[0x3c - 0x10];
    void* field3c;
    char pad3[0xd4 - 0x40];
    void* fieldD4;
};

// USA: func_ov003_0216e124
extern "C" ARM int func_ov003_0216e124(struct Obj0216e124* obj) {
    unsigned int scaleCount = GameState::GetInstance()->GetTickCount();
    if (obj->field3c != 0) {
        func_0205d0e0(obj->field3c, scaleCount);
    }
    if (obj->fieldD4 != 0) {
        obj->fieldC = (short)func_ov023_021e2868(obj->fieldD4);
        if (g_touchInput.pressed_ != 0) {
            obj->fieldE = obj->fieldC;
        } else {
            obj->fieldE = 0;
        }
    }

    struct Block16Words0216e124 buf;
    buf = data_ov003_0217f5c0;
    struct Pair0216e124* pr = &__ptmf_null;
    unsigned int tmp1 = pr->b;
    unsigned int tmp0 = pr->a;
    ((struct DispatchEntry0216e124*)&buf)[7].locator = tmp1;
    ((struct DispatchEntry0216e124*)&buf)[7].fn = tmp0;

    signed char idx = obj->field1;
    struct DispatchEntry0216e124* entries = (struct DispatchEntry0216e124*)&buf;
    if (entries[idx].fn == 0) return 0;
    struct DispatchEntry0216e124* d = &entries[idx];
    void* base = (char*)obj + ((int)d->locator >> 1);
    void (*callback)(void*);
    if (d->locator & 1) {
        callback = (void(*)(void*))(*(void**)((char*)*(void**)base + d->fn));
    } else {
        callback = (void(*)(void*))d->fn;
    }
    callback(base);
    return 1;
}
