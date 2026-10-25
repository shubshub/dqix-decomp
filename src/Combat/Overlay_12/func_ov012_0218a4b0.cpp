#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#if defined(jpn)
extern char data_ov012_0218bfdf[];
#endif
#include <globaldefs.h>

struct Struct_02072a68 {
    short unknown_0_;
    void* unknown_4_;
};

struct Struct_02072a68_2 {
    struct Struct_02072a68* unknown_0_;
    short unknown_4_;
};

int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
int Text_AppendCursorTag(char* dst, int cursor);
void* FindEntryByKey_02072a68(struct TableA68* table, int key);
int Text_AppendNTag(char* dst, int n, const char* name);
int Text_Append(char* dst, const char* src);
int Text_AppendPaletteTag(char* dst, int palette);

// USA: func_ov012_0218a4b0
extern "C" ARM void func_ov012_0218a4b0(unsigned char* arg0, char* arg1, int arg2) {
    if (arg1 == 0) return;

    int cursor = *(int*)(self + R(0x1440,0x13e8));
    if (c != 0) {
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor);

    void* name = FindEntryByKey_02072a68((struct TableA68*)(self + R(0x1314,0x133c)), 0xa);
    Text_AppendNTag(dst, 0, (const char*)name);

    Text_Append(dst, *(char**)(self + R(0x1348,0x1378)));

    unsigned short var2 = *(unsigned short*)(arg0 + R(0x141c,0x13c4));
    unsigned int var3 = ((unsigned int)var2 << 16) >> 21;
    if (var3 == 0) {
#if defined(jpn)
        Text_Append(dst, data_ov012_0218bfdf);
#else
        Text_AppendPaletteTag(dst, 3);
#endif
    }

    void* name2 = FindEntryByKey_02072a68((struct TableA68*)(self + R(0x1314,0x133c)), 0xb);
    Text_AppendNTag(dst, 1, (const char*)name2);
}
