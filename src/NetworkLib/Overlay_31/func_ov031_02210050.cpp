#include <globaldefs.h>
#include "NitroSDK/Memory.h"
#include "NitroSDK/Mutex.h"

struct Struct_ov031_02210050_2 { int unknown_0_; int unknown_4_; };
struct Struct_ov031_02210050 {
    int unknown_0_;
    int unknown_4_;
    Mutex unknown_8_;
    char unknown_20_[8];
    int unknown_28_;
    int unknown_2c_;
    int unknown_30_;
    int unknown_34_;
    char name[8];
    int unknown_40_;
    char unknown_44_[0x174];
    int unknown_1b8_;
    Mutex unknown_1bc_;
    char unknown_1d4_[0x800];
    int unknown_9d4_;
    char unknown_9d8_[0xc];
    void (*callback)(unsigned int);
    int* unknown_9e8_;
    int unknown_9ec_;
    char unknown_9f0_[0x14];
    Struct_ov031_02210050_2 pending;
    int unknown_a0c_;
    ProcessorContext context;
    char unknown_ad8_[0x800];
};
extern Struct_ov031_02210050* data_ov031_0224e588;
extern char data_ov031_022499f4[];
extern int data_ov031_02249928;
extern int data_ov031_0224992c;
extern "C" void func_020d2f28(char*, const char*, int);
extern "C" void func_ov031_02211018(unsigned int);
extern "C" void func_ov031_02210674();

static inline Struct_ov031_02210050_2* inline_ov031_02210050(Struct_ov031_02210050* state) {
    return &state->pending;
}

// USA: func_ov031_02210050
extern "C" ARM void func_ov031_02210050(Struct_ov031_02210050* state, int arg1, int arg2) {
    data_ov031_0224e588 = state;
    VectorizedMemset(state, 0, 0x12d0);
    data_ov031_0224e588->unknown_0_ = 0;
    data_ov031_0224e588->unknown_4_ = 0;
    ZeroInitializeMutex(&data_ov031_0224e588->unknown_8_);
    data_ov031_0224e588->unknown_28_ = arg1;
    data_ov031_0224e588->unknown_2c_ = arg2;
    func_020d2f28(data_ov031_0224e588->name, data_ov031_022499f4, 5);
    Struct_ov031_02210050* reset = data_ov031_0224e588;
    reset->unknown_34_ = 0;
    data_ov031_0224e588->unknown_40_ = 0;
    data_ov031_0224e588->unknown_1b8_ = -59;
    data_ov031_0224e588->unknown_9d4_ = data_ov031_02249928;
    data_ov031_0224e588->unknown_9e8_ = &data_ov031_0224992c;
    data_ov031_0224e588->unknown_9ec_ = 1;
    data_ov031_0224e588->callback = func_ov031_02211018;
    ZeroInitializeMutex(&data_ov031_0224e588->unknown_1bc_);
    Struct_ov031_02210050* pending = data_ov031_0224e588;
    Struct_ov031_02210050_2* fields = inline_ov031_02210050(pending);
    pending->pending.unknown_0_ = fields->unknown_4_ = 0;
    Struct_ov031_02210050* current = data_ov031_0224e588;
    unsigned int priority = GetContextPriority(data_02111304.activeContext);
    PopulateContext(&current->context, (unsigned int)func_ov031_02210674, 0, (unsigned int)(current->unknown_ad8_ + sizeof(current->unknown_ad8_)), 0x800, priority);
    MarkContextStackTopUnknownSubspace(&data_ov031_0224e588->context, 0x80);
}
