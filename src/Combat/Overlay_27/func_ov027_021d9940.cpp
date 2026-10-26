#if defined(jpn)
#define R(j,u) (j)
#define data_ov001_02164ca4 data_ov001_02166270
#define data_ov028_021d9aa0 data_ov028_021da400
#define func_ov014_02188330 func_ov014_02189234
#define func_ov014_0218854c func_ov014_0218942c
#define func_ov014_021885bc func_ov014_0218948c
#define func_ov015_02191f04 func_ov015_02192a48
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"


extern char* data_ov027_021e33ec;

extern "C" ARM void func_ov027_021d9d5c(int index);
extern "C" ARM int func_ov027_021da8d4(void* out, void* table, unsigned int key, void* rawElems);
extern "C" void* func_ov027_021dd638(void* in, void* out);
extern "C" ARM int func_ov027_021dd180(void* obj, unsigned int addr, void* buf, unsigned int size);
extern "C" ARM int func_ov027_021dd3e0(void* p);
extern "C" ARM void func_ov027_021dd3f8(void* a0, unsigned int a1, unsigned int a2, unsigned int a3);
extern "C" ARM void HaltSystem(void);
extern "C" int func_ov027_021dab00(int a, int b, void* c);

struct Struct_ov027_021d989c;
extern "C" ARM void func_ov027_021d989c(Struct_ov027_021d989c* arg0);

struct Struct_ov027_021d9940 {
    unsigned char unknown_0_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
};

struct Struct_ov027_021d9940_2 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
    unsigned char unknown_c_;
};

struct Struct_ov027_021d9940_3 {
    unsigned int unknown_0_;
    unsigned int unknown_4_;
    unsigned int unknown_8_;
    unsigned int unknown_c_;
};

#pragma optimize_for_size off
// USA: func_ov027_021d9940
extern "C" ARM int func_ov027_021d9940(void) {
    if (*(unsigned char*)(data_ov027_021e33ec + 0x1524) == 0) {
        return 0x15;
    }

    unsigned char var0 = 0;
    unsigned char var1;
    for (;;) {
        *(unsigned char*)(data_ov027_021e33ec + 0x1525) =
            (unsigned char)((*(unsigned char*)(data_ov027_021e33ec + 0x1525) + 1) % 0x10);
        var1 = *(unsigned char*)(data_ov027_021e33ec + 0x1525);
        char* var2 = data_ov027_021e33ec + var1 * 0x5d4;
        if (*(unsigned char*)(var2 + 0x1d52) != 0 && *(unsigned short*)(var2 + 0x1d4c) != 0) {
            break;
        }
        var0 = (var0 + 1) & 0xff;
        if (var0 >= 0x10) break;
    }
    if (var0 == 0x10) {
        return 0x15;
    }
    func_ov027_021d9d5c(var1);

    char* var3 = data_ov027_021e33ec;
    unsigned char var4 = *(unsigned char*)(var3 + 0x1525);
    int var5 = var4 * 0x5d4;
    Struct_ov027_021d9940_2 var6;
    unsigned short var7 = *(unsigned short*)(var3 + var5 + 0x1d48);
    if (!func_ov027_021da8d4(&var6, var3 + 0x1d2c + var5, var7, var3 + 0x1788 + var5)) {
        return 0x15;
    }

    Struct_ov027_021d9940 var8;
    var8.unknown_0_ = 4;
    unsigned char var9 = *(unsigned char*)(data_ov027_021e33ec + 0x1525);
    var8.unknown_2_ = var9;
    var9 = *(unsigned char*)(data_ov027_021e33ec + 0x1525);
    var8.unknown_4_ = *(unsigned short*)(data_ov027_021e33ec + var9 * 0x5d4 + 0x1d48);
    void* var10 = func_ov027_021dd638(&var8, data_ov027_021e33ec);

    unsigned char var11 = var6.unknown_c_;
    unsigned char var12 = *(unsigned char*)(data_ov027_021e33ec + 0x1525);
    int var13 = var6.unknown_8_;
    int var14 = var6.unknown_4_;
    char* var15 = data_ov027_021e33ec + var12 * 0x5d4;
    void** var16 = *(void***)(var15 + 0x1000 + 0xd58);
    int var17 = *(int*)(var15 + var11 * 4 + 0x1000 + 0xd2c);
    int var18 = (var13 - var17) + (int)var16[var11];
    void* var19 = *(void**)(var15 + 0x1000 + 0xd54);
    if (!func_ov027_021dd180(var19, var18, var10, var14)) {
        char* var20 = data_ov027_021e33ec + 0x7ce0;
        if (func_ov027_021dd3e0(var20)) {
            goto fail;
        }
        if (*(int*)var19 != 0) {
            *(int*)var19 -= 1;
            goto fail;
        }
        Struct_ov027_021d9940_3* var21 = (Struct_ov027_021d9940_3*)((char*)var19 + 0x30);
        Struct_ov027_021d9940_3* var22 = 0;
        int var23 = 0;
        Struct_ov027_021d9940_3* var24 = var21;
        do {
            if (var21[var23].unknown_c_ == 2) {
                if (var22 == 0 || var22->unknown_0_ > var21[var23].unknown_0_) {
                    var22 = var24;
                }
            }
            p++;
            i++;
        } while (i < 4);
        if (best == 0) {
            HaltSystem();
        }
        *(int*)var19 = 2;
        var22->unknown_c_ = 1;
        var22->unknown_0_ = var18 & ~0x1f;
        *(void**)(var20 + 0x10) = var22;
        *(void**)(var20 + 0x14) = var19;
        func_ov027_021dd3f8(var20, (unsigned int)&func_ov027_021d989c, 0, 4);
        goto fail;
    fail:
        return 0x15;
    }

    unsigned short var25 = *(unsigned short*)(data_ov027_021e33ec +
        (*(unsigned char*)(data_ov027_021e33ec + 0x1525)) * 0x5d4 + 0x1d4c);
    return func_ov027_021dab00(var6.unknown_4_ + 6, var25, data_ov027_021e33ec);
}
