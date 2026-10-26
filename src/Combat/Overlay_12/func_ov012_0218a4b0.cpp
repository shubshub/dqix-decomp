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
    short key;
    void* value;
};

struct TableA68 {
    struct Struct_02072a68* entries;
    short count;
};

extern "C" int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
extern "C" int Text_AppendCursorTag(char* dst, int cursor);
extern "C" void* func_02072a68(struct TableA68* table, int key);
extern "C" int Text_AppendNTag(char* dst, int n, const char* name);
extern "C" int Text_Append(char* dst, const char* src);
extern "C" int Text_AppendPaletteTag(char* dst, int palette);

// USA: func_ov012_0218a4b0
extern "C" ARM void func_ov012_0218a4b0(unsigned char* self, char* dst, int c) {
    if (dst == 0) return;

    int cursor = *(int*)(self + R(0x1440,0x13e8));
    if (c != 0) {
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor);

    void* name = func_02072a68((struct TableA68*)(self + R(0x1314,0x133c)), 0xa);
    Text_AppendNTag(dst, 0, (const char*)name);

    Text_Append(dst, *(char**)(self + R(0x1348,0x1378)));

    unsigned short raw = *(unsigned short*)(self + R(0x141c,0x13c4));
    unsigned int t = ((unsigned int)raw << 16) >> 21;
    if (t == 0) {
#if defined(jpn)
        Text_Append(dst, data_ov012_0218bfdf);
#else
        Text_AppendPaletteTag(dst, 3);
#endif
    }

    void* name2 = func_02072a68((struct TableA68*)(self + R(0x1314,0x133c)), 0xb);
    Text_AppendNTag(dst, 1, (const char*)name2);
}
