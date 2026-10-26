#include <globaldefs.h>

extern "C" void* func_ov031_0223c560(int a, int b);
extern "C" void OS_GetMacAddress(void* dst);
int VariadicForward020c7170(char*, unsigned long, const char*, ...);
extern "C" void func_ov031_0223dd60(void*, const void*, int);
extern "C" void func_ov031_0223c980(void* arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, void* arg7);
extern "C" void func_ov031_0221ae00(void* arg0);
extern "C" void func_ov031_0223caec(void* arg0);

extern const char data_ov031_0224b8ac[];
extern const char data_ov031_0224b8cc[];
extern const char data_ov031_0224b8e0[];

struct Struct_ov031_02228c60 {
    unsigned long long unknown_0_;
    unsigned long long unknown_8_;
    unsigned short unknown_10_;
    unsigned short unknown_12_;
};

// USA: func_ov031_02228c60
extern "C" ARM void func_ov031_02228c60(void) {
    void* var0;
    Struct_ov031_02228c60 var1;
    unsigned long long var2;
    unsigned int var3[4];
    int var4;
    unsigned short var5[20];
    char var6[20];
    unsigned char var7[6] __attribute__((aligned(4)));

    obj = func_ov031_0223c560(0, 0);
    OS_GetMacAddress(mac);
    VariadicForward020c7170(buf, 20, data_ov031_0224b8ac, mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
    func_ov031_0223dd60(text, buf, 20);
    func_ov031_0223c980(obj, 8, 0x40, 0xf0, 0x1c, 2, 0x480, text);

    func_ov031_0221ae00(&var1);
    var2 = var1.unknown_0_;
    if (var2 != 0) {
        var3[3] = (var2 % 10) * 1000;
        var2 /= 10;
        var4 = 0;
        do {
            var3[2 - var4] = var2 % 10000;
            var2 /= 10000;
            var4++;
        } while (var4 < 3);
        func_020c7170(var6, 20, data_ov031_0224b8cc, var3[0], var3[1], var3[2], var3[3]);
        func_ov031_0223dd60(var5, var6, 20);
    } else {
        func_020c7170(var6, 20, data_ov031_0224b8e0);
        func_ov031_0223dd60(var5, var6, 20);
    }
    func_ov031_0223c980(var0, 8, 0x78, 0xf0, 0x1c, 2, 0x480, var5);
    func_ov031_0223caec(var0);
}
