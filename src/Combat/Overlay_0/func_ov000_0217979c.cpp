#include <globaldefs.h>

struct UnkStruct0205c508;
void ComputeProductSums0205c508(struct UnkStruct0205c508* s, int* out1, int* out2);
struct Container020e0310;
char* KeyTable_Get(struct Container020e0310* c, int key);
int IsField0x118Equal2_ov000_0217542c(void* obj);
int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag_02041ea4(char* dst, int cursor);
void* GetPointerField_02171b9c_02171b9c(void* obj, int idx);
int AppendNameTag_02041b70(char* dst, int n, const char* name);
extern "C" void __clear(void* buf, int n);
int AppendString02042058(char* dst, const char* src);
#if defined(jpn)
extern "C" int func_02042158(char* arg0, int arg1);
#define func_02041acc func_02042158
#else
extern "C" int func_02041acc(char* arg0, int arg1);
#endif
extern "C" void func_0206819c(const char* arg0, char* arg1, int arg2);

#if defined(jpn)
#define data_ov000_02184069 data_ov000_021851a9
#endif
extern char data_ov000_02184069[];

struct Struct_ov000_0217979c {
    int unknown_0_;
    const char* unknown_4_;
    unsigned int unknown_8_0_ : 4;
};

struct Struct_ov000_0217979c_2 {
    char unknown_0_[0x22];
    signed char unknown_22_;
};

// USA: func_ov000_0217979c
extern "C" ARM void func_ov000_0217979c(char* arg0, struct Struct_ov000_0217979c_2* arg1, char* arg2) {
    if (arg1 == NULL || arg2 == NULL) {
        return;
    }
    int var0;
    int var1;
    func_0205c508((struct Struct_0205c508*)(arg0 + 0x1dc), &var0, &var1);
    signed char var2 = var0;
    signed char var3 = var1;
    signed char var4 = arg1->unknown_22_;
#if !defined(jpn)
    char* prefix = KeyTable_Get((struct Container020e0310*)(obj + 0xb8), 0x13);
    char* separator = KeyTable_Get((struct Container020e0310*)(obj + 0xb8), 0);
#endif
    if (func_ov000_0217542c(arg0)) {
        func_02041c08(arg2, var4 - var2, 8, 5, 5, 5);
    }
    func_02041ea4(arg2, var4 - var2);
    for (signed char var7 = var2; var7 < var3; var7++) {
        struct Struct_ov000_0217979c* var8 = (struct Struct_ov000_0217979c*)func_ov000_02171b9c(arg1, var7);
        if (var8 == NULL) {
            func_02041b70(arg2, var7 - var2, data_ov000_02184069);
            continue;
        }
        char var9[0x80];
        __clear(var9, 0x80);
        int var10 = var8->unknown_8_0_ <= 7;
        if (var10) {
#if defined(jpn)
            AppendString02042058(text, KeyTable_Get((struct Container020e0310*)(obj + 0xb8), 0x13));
#else
            func_02042058(var9, var5);
            func_02041acc(var9, 3);
#endif
        } else {
            func_02041acc(var9, 8);
        }
#if defined(jpn)
        func_02042058(var9, var8->unknown_4_);
#else
        char var11[0x100];
        __clear(var11, 0x100);
        func_0206819c(var8->unknown_4_, var11, 0);
        func_02042058(var9, var11);
#endif
        func_02041b70(arg2, var7 - var2, var9);
        if (var7 != var3 - 1) {
#if defined(jpn)
            AppendString02042058(dst, KeyTable_Get((struct Container020e0310*)(obj + 0xb8), 0));
#else
            func_02042058(arg2, var6);
#endif
        }
    }
}
