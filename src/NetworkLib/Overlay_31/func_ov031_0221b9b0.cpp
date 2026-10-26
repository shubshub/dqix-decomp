#include <globaldefs.h>
#include "NitroSDK/Memory.h"

#if defined(jpn)
#define func_020ca390 func_020cbe5c
#endif

struct Struct_ov031_0221b9b0 {
    unsigned char payload[0xef];
    unsigned char unknown_ef_;
    unsigned char key[0xe];
    unsigned short unknown_fe_;
};

struct Struct_ov031_0221b9b0_2 {
    Struct_ov031_0221b9b0 slots[4];
    unsigned char unknown_400_[0x100];
    unsigned short unknown_500_[0x100];
};

extern "C" int func_ov031_0221afb4(void*);
extern "C" int func_ov031_0221aff8(int);
extern "C" void func_020d1ba0(unsigned short*, unsigned short);
extern "C" unsigned short func_020d1cc8(const unsigned short*, const unsigned char*, unsigned int);
extern "C" int func_ov031_0221bcb8(Struct_ov031_0221b9b0*);
extern "C" void func_ov031_0221b140(void*);
extern "C" int func_ov031_0221bdb8(char*);
extern "C" int func_ov031_0221b0ac(void*);
extern "C" void func_ov031_0221be38(Struct_ov031_0221b9b0*, int);
extern "C" void func_020ca390(int, void*, unsigned int);

// USA: func_ov031_0221b9b0
extern "C" ARM int func_ov031_0221b9b0(Struct_ov031_0221b9b0_2* state) {
    VectorizedMemset(state, 0, 0x700);
    if (!func_ov031_0221afb4(state))
        return -10001;
    func_020d1ba0(state->unknown_500_, 0xa001);
    if (!func_ov031_0221aff8((int)state))
        return -10001;

    int var0[4];
    VectorizedMemset(var0, 0, sizeof(var0));
    int index = 0;
    const unsigned char* block = (const unsigned char*)state->slots;
    Struct_ov031_0221b9b0* slot = state->slots;
    do {
        unsigned short var4 = func_020d1cc8(state->unknown_500_, block, 0xfe);
        if (var4 == state->slots[index].unknown_fe_) {
            if (func_ov031_0221bcb8(slot))
                var0[index] = 1;
        }
        ++index;
        block += 0x100;
        ++slot;
    } while (index < 3);
    unsigned short var5 = func_020d1cc8(state->unknown_500_, (const unsigned char*)&state->slots[3], 0xfe);
    if (var5 == state->slots[3].unknown_fe_)
        var0[3] = 1;

    if (var0[0] && var0[1] && var0[2] && var0[3]) {
        func_ov031_0221b140(state->slots[0].key);
        return 0;
    }
    if (!var0[0] && !var0[1] && !var0[2] && !var0[3]) {
        func_ov031_0221bdb8((char*)state);
        return func_ov031_0221b0ac(state) ? 0 : -10000;
    }
    if (!(var0[0] && var0[1]) && !(var0[2] && var0[3])) {
        func_ov031_0221bdb8((char*)state);
        return func_ov031_0221b0ac(state) ? 0 : -10000;
    }
    if (!var0[0] && !var0[1]) {
        func_ov031_0221bdb8((char*)state);
        return func_ov031_0221b0ac(state) ? -10003 : -10000;
    }
    if (!var0[0]) {
        func_ov031_0221be38(state->slots, 0);
        VectorizedInvertedMemcpy(state->slots[1].key, state->slots[0].key, 0xe);
        state->slots[0].unknown_ef_ = state->slots[1].unknown_ef_;
    } else if (!var0[1]) {
        func_ov031_0221be38(state->slots, 1);
        VectorizedInvertedMemcpy(state->slots[0].key, state->slots[1].key, 0xe);
        state->slots[1].unknown_ef_ = state->slots[0].unknown_ef_;
    }
    func_ov031_0221b140(state->slots[0].key);
    if (!var0[2])
        func_ov031_0221be38(state->slots, 2);
    if (!var0[3])
        func_020ca390(0, &state->slots[3], 0x100);

    int changed = 0;
    index = 0;
    do {
        if (!var0[index] && (state->slots[0].unknown_ef_ & (1 << index))) {
            state->slots[0].unknown_ef_ &= ~(1 << index);
            changed = 1;
            state->slots[1].unknown_ef_ = state->slots[0].unknown_ef_;
        }
        ++index;
    } while (index < 3);
    if (!func_ov031_0221b0ac(state))
        return -10000;
    return changed ? -10002 : 0;
}
