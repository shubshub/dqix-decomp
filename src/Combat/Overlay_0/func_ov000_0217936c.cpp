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
int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
int Text_AppendCursorTag(char* dst, int cursor);
int* GetBoundedField420_0217199c(void* obj, int index);
int IsBitFlagSet0217c4e8(void* obj, int index);
int Text_AppendPaletteTag(char* dst, int palette);
extern "C" void __clear(void* buf, int size);
extern "C" void func_020e4864(int id, char* dst, int a, int b, int c, int d);
void CopyTextAndUppercaseIfFlagged0206819c(const char* src, char* dst, int flag);
int Text_AppendNTag(char* dst, int n, const char* name);
int KeyTable_Get(struct Container020e0310* c, int key);
int Text_Append(char* dst, const char* src);

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
    ComputeProductSums0205c508((struct UnkStruct0205c508*)window->scroll, &first, &last);
    short top = first;
    short end = last;
    short cursor = menu->cursor;
    if (IsField0x118Equal2_ov000_0217542c(window)) {
        Text_AppendFrameTag(dst, cursor - top, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor - top);
    for (short i = top; i < end; i++) {
        int* entry = GetBoundedField420_0217199c(menu, i);
        if (entry == NULL) {
            continue;
        }
#if defined(jpn)
        if (IsBitFlagSet0217c4e8(menu, i)) {
            Text_AppendPaletteTag(dst, 0xf);
        } else {
            Text_AppendPaletteTag(dst, 3);
        }
        Text_AppendNTag(dst, i - top, (const char*)*entry);
#else
        int var9 = 3;
        if (func_ov000_0217c4e8(arg1, var7)) {
            var9 = 0xf;
        }
        Text_AppendPaletteTag(dst, palette);
        __clear(name, sizeof(name));
        __clear(upper, sizeof(upper));
        func_020e4864(*entry, name, 1, 0, 0, 0);
        CopyTextAndUppercaseIfFlagged0206819c(name, upper, 0);
        Text_AppendNTag(dst, i - top, name);
#endif
        if (i != end - 1) {
            Text_Append(dst, (const char*)KeyTable_Get((struct Container020e0310*)window->texts, 0));
        }
    }
}
