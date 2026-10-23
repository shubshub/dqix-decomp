#include <globaldefs.h>
#include "Resource/ActionDataTables.h"

struct Struct_0201099c_3;

int KeyTable_Get(struct Container020e0310* c, int key);
int AppendString02042058(char* dst, const char* src);
int IsField0x118Equal2_ov000_0217542c(void* obj);
int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);

extern "C" int func_02041e70(char* arg0, int arg1);
extern "C" const char** func_02079e2c(char* arg0, int arg1);
extern "C" int func_02041ea4(char* arg0, int arg1);
extern "C" int func_02041b70(char* arg0, int arg1, const char* arg2);
extern "C" int func_020420e8(const char* arg0, int arg1);
extern "C" int func_02041a90(char* arg0, int arg1, int arg2);
extern "C" int func_02041cc0(char* arg0, int arg1);
#if defined(jpn)
extern "C" void* func_020421a0();
extern "C" void func_02046380(void*);
extern "C" void func_02046574(void*, int, const char*);
extern "C" void __clear(void*, int);
extern "C" void func_02041f50(const char*, char*);
extern char data_ov000_021851af[];
#endif

struct Struct_ov000_0217a2dc {
    char unknown_0_[0x10];
    unsigned short unknown_10_[5];
    signed char unknown_1a_;
#if defined(jpn)
    char unknown_1b_[0x1fa5 - 0x1b];
#else
    char unknown1_1b_[0x1d6d - 0x1b];
#endif
    signed char unknown_1d6d_;
    char unknown_1d6e_[0x1d81 - 0x1d6e];
    unsigned char unknown_1d81_;
};

// USA: func_ov000_0217a2dc
extern "C" ARM void func_ov000_0217a2dc(struct ItemMenu0217a2dc* menu, int unused, char* dst) {
    struct Container020e0310* strings = (struct Container020e0310*)((char*)menu + 0xb8);
    const char* emptyName = (const char*)KeyTable_Get(strings, 0x1f);
    const char* separator = (const char*)KeyTable_Get(strings, 0);
    signed char cursor = menu->cursor;
    AppendString02042058(dst, separator);

    if (arg0->unknown_1d81_) {
        if (func_ov000_0217542c(arg0)) {
            func_02041c08(arg2, var3, 8, 5, 5, 5);
        }
        Struct_02108e10* var4 = func_020797dc();
        if (var4 == NULL) {
            return;
        }
        for (int var5 = 0; var5 < arg0->unknown_1a_; var5++) {
#if defined(jpn)
            if (var5 == var3) {
                func_02041e70(arg2, 5);
            } else {
                func_02041e70(arg2, 3);
            }
#else
            int var6 = 3;
            if (var5 == var3) {
                var6 = 5;
            }
            func_02041e70(arg2, var6);
#endif
            if (arg0->unknown_10_[var5] == 0) {
                func_02042058(arg2, var1);
            } else {
                const char** var7 = func_02079e2c((char*)var4, (short)arg0->unknown_10_[var5]);
                if (var7 == NULL) {
                    continue;
                }
#if defined(jpn)
                char var8[0x40];
                __clear(var8, sizeof(var8));
                func_02041f50(*var7, var8);
                func_02042058(arg2, var8);
#else
                func_02042058(arg2, *var7);
#endif
            }
            if (var5 == arg0->unknown_1a_ - 1) {
                continue;
            }
            func_02042058(arg2, var2);
        }
    } else {
        if (func_ov000_0217542c(arg0)) {
            func_02041c08(arg2, var3, 8, 5, 5, 5);
        }
        func_02041ea4(arg2, var3);
        Struct_02108e10* var9 = func_020797dc();
        if (var9 == NULL) {
            return;
        }
        for (int var10 = 0; var10 < arg0->unknown_1a_; var10++) {
            if (arg0->unknown_10_[var10] == 0) {
                func_02041b70(arg2, var10, var1);
            } else {
                const char** var11 = func_02079e2c((char*)var9, (short)arg0->unknown_10_[var10]);
                if (var11 == NULL) {
                    continue;
                }
#if defined(jpn)
                char var12[0x40];
                __clear(var12, sizeof(var12));
                func_02041f50(*var11, var12);
                func_02041b70(arg2, var10, var12);
#else
                func_02041b70(arg2, var10, *var11);
#endif
            }
            if (var10 == arg0->unknown_1a_ - 1) {
                continue;
            }
            func_02042058(arg2, var2);
        }
    }

    func_02041e70(arg2, 0xf);
#if defined(jpn)
    void* formatter = GetGlobalField0x1c020421a0();
    func_02046380(formatter);
    _Z22SetIndexedName02046574P11Obj02046574iPc(formatter, 0,
        (const char*)KeyTable_Get(strings, 0x21));
    AppendString02042058(dst, data_ov000_021851af);
#else
    const char* title = (const char*)KeyTable_Get(strings, 0x21);
    AppendXYTag_02041a90(dst, (0xb0 - func_020420e8(title, 0)) >> 1, 5);
    AppendString02042058(dst, title);
    AppendLineTag02041cc0(dst, 0x11);
#endif
}
