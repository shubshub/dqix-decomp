#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"
#include "NitroSDK/Memory.h"

extern "C" int func_ov027_021dd0ac(void);
extern "C" int func_ov027_021da808(void* out, void* arg1);
extern "C" void func_ov027_021dab84(void* obj, void* src, int extra);
extern "C" void func_ov027_021da61c(void* dst, void* src);
struct Struct_ov027_021da38c;
extern "C" void func_ov027_021dadac(Struct_ov027_021da38c* node);
extern "C" int func_ov027_021dd3b0(void);
extern "C" void func_ov027_021dd3cc(void* p);
extern "C" void func_ov027_021dd330(void* arg0, unsigned int size);

extern unsigned char* data_ov027_021e33ec;
extern unsigned char data_ov027_021dd924;

// USA: func_ov027_021da38c
extern "C" ARM int func_ov027_021da38c(void* desc, void* arg1) {
    unsigned char var0 = 0xff;
    int var1 = DisableIRQInterrupts();
    if (!func_ov027_021dd0ac()) {
        SetIRQInterruptState(var1);
        return 0;
    }

    unsigned char var2 = data_ov027_021e33ec[0x1524];
    if (var2 + 1 > 0x10) {
        SetIRQInterruptState(var1);
        return 0;
    }

    unsigned char i = 0;
    do {
        unsigned char* slot = data_ov027_021e33ec + i * 0x5d4;
        slot = slot + 0x1000;
        if (*(int*)(slot + 0xd40) == (int)desc) {
            SetIRQInterruptState(var1);
            return 0;
        }
        if (slot[0xd52] == 0) {
            var0 = i;
            break;
        }
        i++;
    } while (i < 0x10);
    if (i == 0x10) {
        SetIRQInterruptState(var1);
        return 0;
    }

    int off = var0 * 0x5d4;
    *(int*)(data_ov027_021e33ec + off + 0x1000 + 0xd40) = (int)desc;

    unsigned char* sub = data_ov027_021e33ec + 0x1788 + off;
    func_ov027_021da61c(sub, arg1);
    VectorizedInvertedMemcpy((char*)desc + 0x1c, sub + 0xc4, 0x20);

    if (!func_ov027_021da808(data_ov027_021e33ec + 0x1d2c + off, sub)) {
        SetIRQInterruptState(var1);
        return 0;
    }

    func_ov027_021dab84(data_ov027_021e33ec + 0x186c + off, desc, (int)(data_ov027_021e33ec + 0x1300));

    (data_ov027_021e33ec + off + 0x1000)[0xd21] = var0;

    func_ov027_021dadac((Struct_ov027_021da38c*)(data_ov027_021e33ec + 0x186c + off));

    unsigned char var7 = data_ov027_021dd924;
    unsigned char var8 = var7 + 1;
    char* var9 = (char*)arg1 + 0x1e8;
    char* var10 = (char*)arg1 + 0x258;
    (data_ov027_021e33ec + off + 0x1000)[0xd1f] = var7;
    *(unsigned short*)(data_ov027_021e33ec + off + 0x1d00 + 0x4e) = 1;

    *(void**)(data_ov027_021e33ec + off + 0x1000 + 0xd44) = arg1;
    *(char**)(data_ov027_021e33ec + off + 0x1000 + 0xd54) = var9;
    *(char**)(data_ov027_021e33ec + off + 0x1000 + 0xd58) = var10;
    data_ov027_021dd924 = var8;

    char* p = *(char**)(data_ov027_021e33ec + off + 0x1000 + 0xd54);
    if (*(int*)(p + 0x6c) != 0) {
        if (!func_ov027_021dd3b0()) {
            func_ov027_021dd3cc(data_ov027_021e33ec + 0x7ce0);
            func_ov027_021dd330(data_ov027_021e33ec + 0x74e0, 0x800);
        }
    }

    (data_ov027_021e33ec + off + 0x1000)[0xd52] = 1;
    data_ov027_021e33ec[0x1524]++;

    SetIRQInterruptState(var1);
    return 1;
}
