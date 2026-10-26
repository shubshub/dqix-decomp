#include <globaldefs.h>
#include <NitroSDK/Interrupts.h>

struct Struct_ov031_0221f8d8 {
    int kind;
    unsigned char* allocation;
    unsigned int size;
    int unknown_c_;
};

struct Struct_ov031_0224f670_7 {
    char field_0x0[8];
    Struct_ov031_0221f8d8* arena;
    char unknown_c_[0x1c];
    unsigned char* memory;
    int state;
    char unknown_30_[0xc];
    void* unknown_3c_;
    char unknown_40_[0xc];
    void* unknown_4c_;
};

extern Struct_ov031_0224f670_7 data_ov031_0224f670;
extern int data_ov031_0224f6f0;
extern "C" int func_ov031_0220c970(void* arg0, unsigned int size);
extern "C" int func_ov031_0220cae0(Struct_ov031_0221f8d8* arena, void (*callback)());
extern "C" void func_ov031_0221f324();

// USA: func_ov031_0221f8d8
extern "C" THUMB int func_ov031_0221f8d8(int mode, unsigned char* memory, unsigned int size) {
    int var0 = DisableIRQInterrupts();
    Struct_ov031_0221f8d8* arena = (Struct_ov031_0221f8d8*)(((unsigned int)memory + 0x63) & ~3);
    unsigned int address = (unsigned int)arena + 0x2f;
    data_ov031_0224f670.memory = memory;
    data_ov031_0224f670.arena = arena;
    address &= ~0x1f;
    data_ov031_0224f670.unknown_3c_ = (void*)address;
    address = (address + 0x231f) & ~0x1f;
    data_ov031_0224f670.unknown_4c_ = (void*)address;
    address = (address + 0xdf) & ~0x1f;
    arena->allocation = (unsigned char*)address;
    data_ov031_0224f670.arena->size = memory + size - data_ov031_0224f670.arena->allocation;
    data_ov031_0224f670.arena->unknown_c_ = 0;
    data_ov031_0224f670.arena->kind = 3;
    data_ov031_0224f6f0 = mode;
    if (data_ov031_0224f670.state == 0) {
        if (func_ov031_0220c970(data_ov031_0224f670.unknown_3c_, 0x2300) != 0) {
            SetIRQInterruptState(var0);
            return 0;
        }
        data_ov031_0224f670.state = 1;
    }
    if (data_ov031_0224f670.state == 1) {
        if (func_ov031_0220cae0(data_ov031_0224f670.arena, func_ov031_0221f324) != 3) {
            SetIRQInterruptState(var0);
            return 0;
        }
        data_ov031_0224f670.state = 4;
        SetIRQInterruptState(var0);
        return 1;
    }
    SetIRQInterruptState(var0);
    return 0;
}
