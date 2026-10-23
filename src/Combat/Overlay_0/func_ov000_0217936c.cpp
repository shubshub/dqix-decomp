#include <globaldefs.h>

struct Struct_0205c508;
struct Struct_0201099c_3;

struct Struct_ov000_0217936c_2 {
    char unknown_0_[0x1e];
    short unknown_1e_;
};

struct Struct_ov000_0217936c {
    char unknown_0_[0xb8];
    char unknown_b8_[0x1dc - 0xb8];
    char unknown_1dc_[4];
};

void ComputeProductSums0205c508(struct UnkStruct0205c508* s, int* out1, int* out2);
int IsField0x118Equal2_ov000_0217542c(void* obj);
int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag_02041ea4(char* dst, int cursor);
int* GetBoundedField420_0217199c(void* obj, int index);
int IsBitFlagSet0217c4e8(void* obj, int index);
int AppendPaletteTag_02041e70(char* dst, int palette);
extern "C" void __clear(void* buf, int size);
extern "C" void func_020e4864(int id, char* dst, int a, int b, int c, int d);
void CopyTextAndUppercaseIfFlagged0206819c(const char* src, char* dst, int flag);
int AppendNameTag_02041b70(char* dst, int n, const char* name);
int KeyTable_Get(struct Container020e0310* c, int key);
int AppendString02042058(char* dst, const char* src);

// USA: func_ov000_0217936c
extern "C" ARM void func_ov000_0217936c(struct Struct_ov000_0217936c* arg0, struct Struct_ov000_0217936c_2* arg1, char* arg2) {
#if !defined(jpn)
    char var0[0x80];
    char var1[0x80];
#endif
    int var2;
    int var3;
    if (arg1 == NULL || arg2 == NULL) {
        return;
    }
    func_0205c508((struct Struct_0205c508*)arg0->unknown_1dc_, &var2, &var3);
    short var4 = var2;
    short var5 = var3;
    short var6 = arg1->unknown_1e_;
    if (func_ov000_0217542c(arg0)) {
        func_02041c08(arg2, var6 - var4, 8, 5, 5, 5);
    }
    func_02041ea4(arg2, var6 - var4);
    for (short var7 = var4; var7 < var5; var7++) {
        int* var8 = func_ov000_0217199c(arg1, var7);
        if (var8 == NULL) {
            continue;
        }
#if defined(jpn)
        if (func_ov000_0217c4e8(arg1, var7)) {
            func_02041e70(arg2, 0xf);
        } else {
            func_02041e70(arg2, 3);
        }
        func_02041b70(arg2, var7 - var4, (const char*)*var8);
#else
        int var9 = 3;
        if (func_ov000_0217c4e8(arg1, var7)) {
            var9 = 0xf;
        }
        func_02041e70(arg2, var9);
        __clear(var0, sizeof(var0));
        __clear(var1, sizeof(var1));
        func_020e4864(*var8, var0, 1, 0, 0, 0);
        func_0206819c(var0, var1, 0);
        func_02041b70(arg2, var7 - var4, var0);
#endif
        if (i != end - 1) {
            AppendString02042058(dst, (const char*)KeyTable_Get((struct Container020e0310*)window->texts, 0));
        }
    }
}
