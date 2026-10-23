#include <globaldefs.h>

extern "C" void* func_ov000_02174da4(int arg0, void* arg1);
extern "C" int func_ov000_0217542c(void* arg0);
extern "C" int func_02041c08(char* arg0, int arg1, int arg2, int arg3, int arg4, int arg5);
extern "C" int func_02041ea4(char* arg0, int arg1);
extern "C" int func_02042058(char* arg0, const char* arg1);
extern "C" int func_02041b70(char* arg0, int arg1, const char* arg2);

struct Container020e0310;
int KeyTable_Get(struct Container020e0310* c, int key);
int CallFunc020e0434With02153694_020e51cc(int value);

extern short data_ov000_021834c4[4];

#if defined(jpn)
struct Struct_ov000_021845c6 { char unknown_0_[4][9]; };
extern const Struct_ov000_021845c6 data_ov000_021845c6;
#endif

// USA: func_ov000_0217737c
extern "C" ARM void func_ov000_0217737c(void* arg0, char* arg1) {
    char* var0 = (char*)arg0;
    if (arg1 == 0) {
        return;
    }
    int var1[4];
    func_ov000_02174da4((int)var0, var1);
#if defined(jpn)
    int var4 = 0;
    Struct_ov000_021845c6 var2(data_ov000_021845c6);
    signed char var3 = *(signed char*)(var0 + 0x1fa1);
#else
    signed char var3 = *(signed char*)(var0 + 0x1d69);
#endif
#if !defined(jpn)
    int var4 = 0;
#endif
    if (func_ov000_0217542c(var0)) {
        func_02041c08(arg1, var3, 8, 5, 5, 5);
    }
    func_02041ea4(arg1, var3);
    int var5 = 0;
    for (int var6 = 0; var6 < 4; var6++) {
        int var7 = var1[var6];
        if (var7 < 0) {
            continue;
        }
        if (nameIdx != 0) {
            int f = KeyTable_Get((struct Container020e0310*)(obj + 0xb8), keyArg);
            AppendString02042058(dst, (const char*)f);
        }
#if defined(jpn)
        char* var9 = var2.unknown_0_[var7];
#else
        int var9 = func_020e51cc(data_ov000_021834c4[var7]);
#endif
        func_02041b70(arg1, var4, (const char*)var9);
        var4++;
    }
}
