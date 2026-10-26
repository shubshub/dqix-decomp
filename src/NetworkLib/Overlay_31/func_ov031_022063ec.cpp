#include <globaldefs.h>

unsigned int DisableIRQInterrupts(void);
void SetIRQInterruptState(int state);

struct BlockedContextList;
void BlockCurrentContext(BlockedContextList* p);

struct Struct_ov031_02206368 {
    char pad0[0x100];
    unsigned short unknown_100_;
    char pad1[0x104 - 0x100 - 2];
    char unknown_104_;
};

struct Struct_ov031_02206368_2 {
    char pad[0x68];
    Struct_ov031_02206368* q;
};

extern "C" ARM int func_ov031_022063ec(Struct_ov031_02206368_2* obj);

// USA: func_ov031_02206368
extern "C" ARM int func_ov031_02206368(Struct_ov031_02206368_2* obj, int arg1, int max, int* out, int flags) {
    Struct_ov031_02206368* q = obj->q;
    if (max > arg1) {
        max = arg1;
    }
    unsigned int state = DisableIRQInterrupts();
    int result;
    int bit0 = flags & 1;
    for (;;) {
        result = func_ov031_022063ec(obj);
        if (result >= max) {
            *out = q->unknown_100_;
            if (result >= arg1) {
                result = arg1;
            }
            break;
        }
        if (!bit0) {
            result = 0;
            break;
        }
        BlockCurrentContext((BlockedContextList*)&q->unknown_104_);
    }
    SetIRQInterruptState(state);
    return result;
}
