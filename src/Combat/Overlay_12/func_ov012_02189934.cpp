#if defined(jpn)
#define R(j,u) (j)
extern const char data_ov012_0218bfd7[];
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct TableA68;
extern "C" void* func_02072a68(struct TableA68* table, int key);
extern "C" int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
extern "C" int Text_AppendCursorTag(char* dst, int cursor);
extern "C" int Text_AppendNTag(char* dst, int n, const char* name);
extern "C" int Text_Append(char* dst, const char* src);
extern "C" int Text_AppendPaletteTag(char* dst, int palette);

struct Struct_ov012_02189934 {
    unsigned short field : 5;
};

// USA: func_ov012_02189934
extern "C" ARM void func_ov012_02189934(char* base, char* dst, int flag) {
    if (dst == NULL) return;

    int cursor = *(int*)(base + R(0x1430, 0x13d8));
    if (flag != 0) {
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor);

    Text_AppendNTag(dst, 0, (const char*)func_02072a68((struct TableA68*)(base + R(0x1314, 0x133c)), 7));
    Text_Append(dst, *(char**)(base + R(0x1348, 0x1378)));

    Text_AppendNTag(dst, 1, (const char*)func_02072a68((struct TableA68*)(base + R(0x1314, 0x133c)), 8));
    Text_Append(dst, *(char**)(base + R(0x1348, 0x1378)));

    if (((struct Struct_ov012_02189934*)(base + R(0x141c, 0x13c4)))->field == 0) {
        Text_AppendPaletteTag(dst, 3);
    }

    Text_AppendNTag(dst, 2, (const char*)func_02072a68((struct TableA68*)(base + R(0x1314, 0x133c)), 9));
    Text_Append(dst, *(char**)(base + R(0x1348, 0x1378)));

    if (((struct Struct_ov012_02189934*)(base + R(0x141c, 0x13c4)))->field == 0) {
#if defined(jpn)
        Text_Append(dst, data_ov012_0218bfd7);
#else
        Text_AppendPaletteTag(dst, 0xf);
#endif
    }

    Text_AppendNTag(dst, 3, (const char*)func_02072a68((struct TableA68*)(base + R(0x1314, 0x133c)), 0x6d));
}
