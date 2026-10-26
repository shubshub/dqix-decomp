#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Input/Input.h"

extern "C" int Window_Update(void* p, int val);
extern "C" int func_ov023_021e2868(void* obj);

struct Struct_ov003_0217f5c0 { unsigned int w[16]; };
extern struct Struct_ov003_0217f5c0 data_ov003_0217f5c0;
struct Struct_020e6d5c_17 { unsigned int a; unsigned int b; };
extern struct Struct_020e6d5c_17 __ptmf_null;
struct Struct_ov003_0216e124 { unsigned int fn; unsigned int unknown_4_; };

struct Struct_ov003_0216e124_2 {
    char pad0[1];
    signed char field1;
    char pad1[0xc - 2];
    short fieldC;
    short unknown_e_;
    char pad2[0x3c - 0x10];
    void* field3c;
    char pad3[0xd4 - 0x40];
    void* unknown_d4_;
};

// USA: func_ov003_0216e124
extern "C" ARM int func_ov003_0216e124(struct Struct_ov003_0216e124_2* obj) {
    unsigned int scaleCount = GameState::GetInstance()->GetTickCount();
    if (obj->field3c != 0) {
        Window_Update(obj->field3c, scaleCount);
    }
    if (obj->unknown_d4_ != 0) {
        obj->fieldC = (short)func_ov023_021e2868(obj->unknown_d4_);
        if (g_touchInput.pressed_ != 0) {
            obj->unknown_e_ = obj->fieldC;
        } else {
            obj->unknown_e_ = 0;
        }
    }

    struct Struct_ov003_0217f5c0 buf;
    buf = data_ov003_0217f5c0;
    struct Struct_020e6d5c_17* var2 = &__ptmf_null;
    unsigned int var3 = var2->b;
    unsigned int var4 = var2->a;
    ((struct Struct_ov003_0216e124*)&buf)[7].unknown_4_ = var3;
    ((struct Struct_ov003_0216e124*)&buf)[7].fn = var4;

    signed char idx = obj->field1;
    struct Struct_ov003_0216e124* entries = (struct Struct_ov003_0216e124*)&buf;
    if (entries[idx].fn == 0) return 0;
    struct Struct_ov003_0216e124* d = &entries[idx];
    void* base = (char*)obj + ((int)d->unknown_4_ >> 1);
    void (*callback)(void*);
    if (d->unknown_4_ & 1) {
        callback = (void(*)(void*))(*(void**)((char*)*(void**)base + d->fn));
    } else {
        callback = (void(*)(void*))d->fn;
    }
    callback(base);
    return 1;
}
