#include <globaldefs.h>

struct Struct_ov031_02239bfc {
    unsigned char unknown_0_[0x58];
    unsigned long unknown_58_;
    unsigned short unknown_5c_;
    unsigned short unknown_5e_;
};

struct Struct_ov031_02290d18_19 {
    void (*unknown_0_)(int, const char*, ...);
    Struct_ov031_02239bfc* unknown_4_;
};

extern Struct_ov031_02290d18_19 data_ov031_02290d18 __attribute__((aligned(4)));

extern "C" void OS_GetMacAddress(void* mac);
void SetField54IfTagNot9Or10_ov031_022393e4(int v);
extern "C" void func_ov031_02239368(int);
extern "C" unsigned short func_ov031_02239cd4(unsigned short);

static inline unsigned long inline_0202d6c8() { return *(volatile unsigned long*)0x027ffc3c; }

// USA: func_ov031_02239bfc
extern "C" ARM int func_ov031_02239bfc(void) {
    unsigned short mac[3];
    OS_GetMacAddress(mac);
    data_ov031_02290d18.state->rand = mac[0] + OS_GetVBlankCount() + mac[1] + mac[2];
    data_ov031_02290d18.state->rand = data_ov031_02290d18.state->rand * 69069 + 12345;
    data_ov031_02290d18.state->channel = 0;
    data_ov031_02290d18.state->channelBusyRatio = 101;
    func_ov031_02239368(3);
    unsigned short var1 = func_ov031_02239cd4(1);
    if (var1 == 0x18) {
        func_ov031_022393e4(0x18);
        func_ov031_02239368(9);
        return 0;
    }
    if (var1 == 2) return 1;
    func_ov031_022393e4(var1);
    func_ov031_02239368(9);
    return 0;
}
