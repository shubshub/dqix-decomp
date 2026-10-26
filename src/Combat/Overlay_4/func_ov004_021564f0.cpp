#include <globaldefs.h>
#include "std_library_functions.h"

#if defined(jpn)
#define func_ov024_021f6f10 func_ov023_021f6f10
extern "C" int func_ov023_021f6f10(void* self);
#endif

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" int func_ov024_021f6f10(void* self);
extern "C" int func_ov023_021fa598(void*);
extern "C" int func_ov023_021f9bc8(void*);
extern "C" void func_ov023_021f809c(void* node, void* obj);

extern "C" int MessageSystem_GetInstance(void);

struct Struct_020a15bc_2 { unsigned int field : 9; unsigned int pad : 23; unsigned int w1; unsigned int w2; };
struct Struct_020a15bc { struct Struct_020a15bc_2* base; unsigned short pad4; unsigned short count; };
extern "C" struct Struct_020a15bc_2* func_020a15bc(struct Struct_020a15bc* arr, int id);

struct Struct_02072a68 { short key; void* value; };
struct TableA68 { struct Struct_02072a68* entries; short count; };
extern "C" void* func_02072a68(struct TableA68* table, int key);

extern "C" int func_02041a90(char* dst, int x, int y);
extern "C" int Text_Append(char* dst, const char* src);

extern "C" int Font_GetTextWidth(void* entry, int flag);
extern "C" int MessageSystem_FormatText(void* g, int a, unsigned int b, void* buf, int c, int d, int e);

#if defined(jpn)
struct Struct_ov004_021707c8 { char pad[4]; short* keys; struct Struct_020a15bc* arr; };
extern "C" void func_02041f50(void* entry, char* dst);
extern "C" void func_02042428(char* dst, int size);
extern "C" int STD_GetStringLength(const char* s);
extern "C" void func_ov023_021f8960(char* node, short a, unsigned short b);
#else
struct Struct_ov004_021707c8 { char pad[8]; short* keys; struct Struct_020a15bc* arr; };
#endif
extern Struct_ov004_021707c8 data_ov004_021707c8;

// USA: func_ov004_021564f0
extern "C" ARM int func_ov004_021564f0(void* obj) {
    void* base = func_ov011_021849c8(obj);

    void* var1 = func_ov023_021f6880(base, 3);
    if (!var1) {
        return 0;
    }
    if (func_ov024_021f6f10(var1) != 7) {
        return 0;
    }

    short var2 = *(short*)((char*)var1 + 0x5c);
    short var3 = *(short*)((char*)var1 + 0x5e);

    void* node2 = func_ov023_021f6880(base, 0xb);
    if (!node2) {
        return 0;
    }
    if (func_ov024_021f6f10(node2) != 4) {
        return 0;
    }

    struct TableA68* table = (struct TableA68*)func_ov023_021fa598(node2);
    if (!data_ov004_021707c8.keys) {
        return 0;
    }

#if defined(jpn)
    int addr = func_ov023_021f9bc8(var1) + (short)(var2 * 16);
    short key = data_ov004_021707c8.keys[addr];

    struct Struct_020a15bc_2* elem = func_020a15bc(data_ov004_021707c8.arr, key);
    if (elem != NULL) {

    void* g = (void*)MessageSystem_GetInstance();
    char* buf = *(char**)((char*)g + 0x28);

    void* node3 = func_ov023_021f6880(base, 0x82);
    if (!node3) {
        return 0;
    }
    if (func_ov024_021f6f10(node3) != 8) {
        return 0;
    }

    *(void**)((char*)node3 + 0x20) = 0;
    if (key > 0) {
        memset(buf, 0, 0x800);
        void* entry = func_02072a68(table, key);
        func_02041f50(entry, buf + 0x700);
        int len = STD_GetStringLength(buf + 0x700);
        int x = (0x80 - (len / 2) * 12) / 2;
        int y = 6;
        if (len != STD_GetStringLength((const char*)entry)) {
            y = 8;
        }
        func_02042428(buf, 0xc);
        func_02041a90(buf, x, y);
        Text_Append(buf, (const char*)entry);
        *(void**)((char*)node3 + 0x20) = buf;
    }

    void* node4 = func_ov023_021f6880(base, 0x35);
    if (!node4) {
        return 0;
    }
    if (func_ov024_021f6f10(node4) != 6) {
        return 0;
    }
    *(short*)((char*)node4 + 0x104) = var2;
    *(short*)((char*)node4 + 0x106) = var3;
    func_ov023_021f809c(node4, obj);

    void* node5 = func_ov023_021f6880(base, 0x83);
    if (!node5) {
        return 0;
    }
    if (func_ov024_021f6f10(node5) != 8) {
        return 0;
    }

    *(void**)((char*)node5 + 0x20) = 0;
    if (key > 0) {
        *(void**)((char*)node5 + 0x20) = (void*)elem->w1;
    }

    void* var18 = func_ov023_021f6880(base, 0x36);
    if (!var18) {
        return 0;
    }
    if (func_ov024_021f6f10(var18) != 6) {
        return 0;
    }
    func_ov023_021f8960((char*)var18, 0, 8);
    *(short*)((char*)var18 + 0x104) = var2;
    *(short*)((char*)var18 + 0x106) = var3;
    func_ov023_021f809c(var18, obj);

    }
#else
    int addr = func_ov023_021f9bc8(var1) + (short)(var2 * 12);
    short key = data_ov004_021707c8.keys[addr];

    struct Struct_020a15bc_2* elem = func_020a15bc(data_ov004_021707c8.arr, key);
    if (elem != NULL) {

    void* g = (void*)MessageSystem_GetInstance();
    char* buf = *(char**)((char*)g + 0x5c);

    void* node3 = func_ov023_021f6880(base, 0x82);
    if (!node3) {
        return 0;
    }
    if (func_ov024_021f6f10(node3) != 8) {
        return 0;
    }

    *(void**)((char*)node3 + 0x20) = 0;
    if (key > 0) {
        memset(buf, 0, 0x960);
        void* entry = func_02072a68(table, key);
        int diff = 0xa0 - Font_GetTextWidth(entry, 1);
        int half = diff / 2;
        if (half < 0) {
            half = 0;
        }
        func_02041a90(buf, half, 6);
        if (entry) {
            Text_Append(buf, (const char*)entry);
        }
        *(void**)((char*)node3 + 0x20) = buf;
    }

    void* node4 = func_ov023_021f6880(base, 0x35);
    if (!node4) {
        return 0;
    }
    if (func_ov024_021f6f10(node4) != 6) {
        return 0;
    }
    *(short*)((char*)node4 + 0x104) = var2;
    *(short*)((char*)node4 + 0x106) = var3;
    func_ov023_021f809c(node4, obj);

    void* node5 = func_ov023_021f6880(base, 0x83);
    if (!node5) {
        return 0;
    }
    if (func_ov024_021f6f10(node5) != 8) {
        return 0;
    }

    *(void**)((char*)node5 + 0x20) = 0;
    if (key > 0) {
        memset(buf, 0, 0x960);
        MessageSystem_FormatText(g, 0xc, elem->w1, buf, 0xe3, 0, 1);
        *(void**)((char*)node5 + 0x20) = buf;
    }

    void* var30 = func_ov023_021f6880(base, 0x36);
    if (!var30) {
        return 0;
    }
    if (func_ov024_021f6f10(var30) != 6) {
        return 0;
    }
    *(short*)((char*)var30 + 0x104) = var2;
    *(short*)((char*)var30 + 0x106) = var3;
    func_ov023_021f809c(var30, obj);

    }
#endif
    return 0;
}
