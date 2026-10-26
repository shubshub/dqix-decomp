#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"
#include "NitroSDK/ProcessorContext.h"

struct Struct_ov031_022052b4 {
    char unknown_0_[0x64];
    void* unknown_64_;
    void* unknown_68_;
    int result;
    short state;
    signed char unknown_72_, unknown_73_;
    unsigned short unknown_74_, unknown_76_;
    unsigned int unknown_78_;
    Struct_ov031_022052b4* next;
};
struct Struct_ov031_022052b4_2 {
    int (*callback)(void*);
    Struct_ov031_022052b4* unknown_4_;
    void* unknown_8_;
    signed char unknown_c_, unknown_d_;
    unsigned char padding[2];
};
extern "C" int func_020c7fe0(void*, unsigned int*, int);
extern "C" void func_ov031_02205174(int);
extern "C" int func_020c7ea0(void*, unsigned int*, int);
extern "C" int func_020c7e0c(void*, unsigned int, int);

// USA: func_ov031_022052b4
extern "C" ARM void func_ov031_022052b4(void* queue) {
    Struct_ov031_022052b4_2* var0;
    int var1;
    int result;
    while (1) {
        func_020c7fe0(queue, (unsigned int*)&var0, 1);
        if (var0 == NULL) break;
        result = var0->callback(var0);
        var1 = DisableIRQInterrupts();
        AddContextSwitchLock();
        func_020c7ea0(queue, NULL, 0);
        if (var0->unknown_4_) var0->unknown_4_->result = result;
        if (var0->unknown_8_) func_020c7e0c(var0->unknown_8_, result, 0);
        func_ov031_02205174((int)var0);
        RemoveContextSwitchLock();
        SetIRQInterruptState(var1);
    }
}
