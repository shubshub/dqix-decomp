#include <globaldefs.h>

extern "C" int func_ov031_02207180(void* v);
unsigned int DisableIRQInterrupts();
unsigned int SetIRQInterruptState(int mask);
struct Struct_ov031_02206fa4;
extern "C" int func_ov031_02207074(Struct_ov031_02206fa4* obj);
extern "C" int func_ov031_022063ec(void* obj);

struct Struct_ov031_02206fa4_2 {
    char pad0[8];
    unsigned char field8;
    char pad1[0x70 - 9];
    volatile short unknown_70_;
    char pad2;
    signed char unknown_73_;
};

// USA: func_ov031_02206fa4
extern "C" ARM int func_ov031_02206fa4(Struct_ov031_02206fa4_2* obj) {
    int flags = 0;
    if (func_ov031_02207180(obj)) {
        flags |= 0x80;
        goto end;
    }

    if (obj->unknown_70_ & 0x40) flags |= 0x20;
    signed char var1 = obj->unknown_73_;
    if (var1 == 1 || (obj->unknown_70_ & 4)) {
        unsigned int status = DisableIRQInterrupts();
        if (func_ov031_02207074((Struct_ov031_02206fa4*)obj) > 0) flags |= 1;
        if (func_ov031_022063ec(obj) > 0) flags |= 8;
        SetIRQInterruptState(status);
    }

    {
        signed char var3 = obj->unknown_73_;
        int var4 = 1;
        if (var3 != 0 && var3 != 4) var4 = 0;
        if (!var4) goto end;
    }

    if ((obj->unknown_70_ & 4) && (obj->field8 != 4)) {
        if (!(flags & 1)) {
            obj->unknown_70_ = obj->unknown_70_ & ~6;
        }
    }

    if (obj->unknown_70_ & 2) goto end;
    if (!(obj->unknown_70_ & 4)) flags |= 0x40;
end:
    return flags;
}
