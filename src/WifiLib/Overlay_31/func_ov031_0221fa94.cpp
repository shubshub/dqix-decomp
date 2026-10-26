#include <globaldefs.h>

struct Struct_ov031_0224f670_12 {
    char field_0x0[4];
    void* (*unknown_4_)(unsigned int size);
    char unknown_8_[0x38];
    unsigned char* unknown_40_;
    char unknown_44_[0x10];
    void* allocation;
    char unknown_58_[4];
    unsigned char* unknown_5c_;
    char unknown_60_[0x10];
    int mode;
};

extern Struct_ov031_0224f670_12 data_ov031_0224f670;

extern "C" void func_ov031_0221f9f8();
extern "C" int func_ov031_0221f8d8(void (*callback)(int, int), unsigned char* memory, unsigned int size);
void SleepCurrentContext(unsigned int);
extern "C" int func_ov031_0221fa20();
extern "C" void func_ov031_0221fa58(int event, int);

static inline unsigned long long inline_ov031_0221fa94(unsigned long long value) {
    return (value + 0x1f) & ~0x1fULL;
}

// USA: func_ov031_0221fa94
extern "C" THUMB int func_ov031_0221fa94(int mode) {
    int var0 = 1;
    int result;
    data_ov031_0224f670.mode = mode;
    func_ov031_0221f9f8();
    unsigned int n = mode * 0xd0;
    void* allocation = data_ov031_0224f670.unknown_4_(n + 0x24d0 + mode * 0xc0);
    data_ov031_0224f670.allocation = allocation;
    if (allocation == NULL) {
        return -1;
    }
    unsigned char* memory = (unsigned char*)inline_ov031_0221fa94((unsigned int)allocation);
    data_ov031_0224f670.unknown_40_ = memory;
    data_ov031_0224f670.unknown_5c_ = (unsigned char*)inline_ov031_0221fa94((unsigned int)memory + (n + 0x2490));
    if (func_ov031_0221f8d8(func_ov031_0221fa58, memory, n + 0x2490) == 0) {
        return -2;
    }
    do {
        SleepCurrentContext(10);
        int event = func_ov031_0221fa20();
        while (event != 0) {
            switch (event) {
            case 4:
            case 5:
                break;
            case 6:
                var0 = 0;
                result = 1;
                break;
            default:
                var0 = 0;
                result = -2;
                break;
            }
            event = func_ov031_0221fa20();
        }
    } while (var0);
    return result;
}
