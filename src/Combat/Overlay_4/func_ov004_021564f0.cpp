#include <globaldefs.h>
#include "std_library_functions.h"

#if defined(jpn)
#define func_ov024_021f6f10 func_ov023_021f6f10
extern "C" int func_ov023_021f6f10(void* arg0);
#endif

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" int func_ov024_021f6f10(void* arg0);
extern "C" int func_ov023_021fa598(void*);
extern "C" int func_ov023_021f9bc8(void*);
extern "C" void func_ov023_021f809c(void* arg0, void* arg1);

int MessageSystem_GetInstance(void);

struct Struct_020a15bc_2 { unsigned int unknown_0_0_ : 9; unsigned int unknown_1_1_ : 23; unsigned int unknown_4_; unsigned int unknown_8_; };
struct Struct_020a15bc { struct Struct_020a15bc_2* unknown_0_; unsigned short unknown_4_; unsigned short unknown_6_; };
extern "C" struct Struct_020a15bc_2* func_020a15bc(struct Struct_020a15bc* arg0, int arg1);

struct Struct_02072a68 { short unknown_0_; void* unknown_4_; };
struct Struct_02072a68_2 { struct Struct_02072a68* unknown_0_; short unknown_4_; };
extern "C" void* func_02072a68(struct Struct_02072a68_2* arg0, int arg1);

int AppendXYTag_02041a90(char* dst, int x, int y);
int Text_Append(char* dst, const char* src);

extern "C" int Font_GetTextWidth(void* entry, int flag);
extern "C" int MessageSystem_FormatText(void* g, int a, unsigned int b, void* buf, int c, int d, int e);

#if defined(jpn)
struct Data021707c8 { char pad[4]; short* keys; struct Array020a15bc* arr; };
extern "C" void func_02041f50(void* entry, char* dst);
extern "C" void func_02042428(char* dst, int size);
int STD_GetStringLength(const char* s);
void SetOffset100Fields_021f8960(char* node, short a, unsigned short b);
#else
struct Struct_ov004_021707c8 { char unknown_0_[8]; short* unknown1_8_; struct Struct_020a15bc* unknown_c_; };
#endif
extern Struct_ov004_021707c8 data_ov004_021707c8;

// USA: func_ov004_021564f0
extern "C" ARM int func_ov004_021564f0(void* arg0) {
    void* var0 = func_ov011_021849c8(arg0);

    void* var1 = func_ov023_021f6880(var0, 3);
    if (!var1) {
        return 0;
    }
    if (func_ov024_021f6f10(var1) != 7) {
        return 0;
    }

    short var2 = *(short*)((char*)var1 + 0x5c);
    short var3 = *(short*)((char*)var1 + 0x5e);

    void* var4 = func_ov023_021f6880(var0, 0xb);
    if (!var4) {
        return 0;
    }
    if (func_ov024_021f6f10(var4) != 4) {
        return 0;
    }

    struct Struct_02072a68_2* var5 = (struct Struct_02072a68_2*)func_ov023_021fa598(var4);
    if (!data_ov004_021707c8.unknown1_8_) {
        return 0;
    }

#if defined(jpn)
    int var6 = func_ov023_021f9bc8(var1) + (short)(var2 * 16);
    short var7 = data_ov004_021707c8.unknown1_8_[var6];

    struct Struct_020a15bc_2* var8 = func_020a15bc(data_ov004_021707c8.unknown_8_, var7);
    if (var8 != NULL) {

    void* g = (void*)MessageSystem_GetInstance();
    char* buf = *(char**)((char*)g + 0x28);

    void* var11 = func_ov023_021f6880(var0, 0x82);
    if (!var11) {
        return 0;
    }
    if (func_ov024_021f6f10(var11) != 8) {
        return 0;
    }

    *(void**)((char*)node3 + 0x20) = 0;
    if (key > 0) {
        memset(buf, 0, 0x800);
        void* entry = FindEntryByKey_02072a68(table, key);
        func_02041f50(entry, buf + 0x700);
        int len = STD_GetStringLength(buf + 0x700);
        int x = (0x80 - (len / 2) * 12) / 2;
        int y = 6;
        if (len != STD_GetStringLength((const char*)entry)) {
            y = 8;
        }
        func_02042428(buf, 0xc);
        AppendXYTag_02041a90(buf, x, y);
        Text_Append(buf, (const char*)entry);
        *(void**)((char*)node3 + 0x20) = buf;
    }

    void* var16 = func_ov023_021f6880(var0, 0x35);
    if (!var16) {
        return 0;
    }
    if (func_ov024_021f6f10(var16) != 6) {
        return 0;
    }
    *(short*)((char*)var16 + 0x104) = var2;
    *(short*)((char*)var16 + 0x106) = var3;
    func_ov023_021f809c(var16, arg0);

    void* var17 = func_ov023_021f6880(var0, 0x83);
    if (!var17) {
        return 0;
    }
    if (func_ov024_021f6f10(var17) != 8) {
        return 0;
    }

    *(void**)((char*)var17 + 0x20) = 0;
    if (var7 > 0) {
        *(void**)((char*)var17 + 0x20) = (void*)var8->unknown_4_;
    }

    void* var18 = func_ov023_021f6880(var0, 0x36);
    if (!var18) {
        return 0;
    }
    if (func_ov024_021f6f10(var18) != 6) {
        return 0;
    }
    func_ov023_021f8960((char*)var18, 0, 8);
    *(short*)((char*)var18 + 0x104) = var2;
    *(short*)((char*)var18 + 0x106) = var3;
    func_ov023_021f809c(var18, arg0);

    }
#else
    int var19 = func_ov023_021f9bc8(var1) + (short)(var2 * 12);
    short var20 = data_ov004_021707c8.unknown1_8_[var19];

    struct Struct_020a15bc_2* var21 = func_020a15bc(data_ov004_021707c8.unknown_c_, var20);
    if (var21 != NULL) {

    void* g = (void*)MessageSystem_GetInstance();
    char* buf = *(char**)((char*)g + 0x5c);

    void* var24 = func_ov023_021f6880(var0, 0x82);
    if (!var24) {
        return 0;
    }
    if (func_ov024_021f6f10(var24) != 8) {
        return 0;
    }

    *(void**)((char*)node3 + 0x20) = 0;
    if (key > 0) {
        memset(buf, 0, 0x960);
        void* entry = FindEntryByKey_02072a68(table, key);
        int diff = 0xa0 - Font_GetTextWidth(entry, 1);
        int half = diff / 2;
        if (half < 0) {
            half = 0;
        }
        AppendXYTag_02041a90(buf, half, 6);
        if (entry) {
            Text_Append(buf, (const char*)entry);
        }
        *(void**)((char*)var24 + 0x20) = var23;
    }

    void* var28 = func_ov023_021f6880(var0, 0x35);
    if (!var28) {
        return 0;
    }
    if (func_ov024_021f6f10(var28) != 6) {
        return 0;
    }
    *(short*)((char*)var28 + 0x104) = var2;
    *(short*)((char*)var28 + 0x106) = var3;
    func_ov023_021f809c(var28, arg0);

    void* var29 = func_ov023_021f6880(var0, 0x83);
    if (!var29) {
        return 0;
    }
    if (func_ov024_021f6f10(var29) != 8) {
        return 0;
    }

    *(void**)((char*)node5 + 0x20) = 0;
    if (key > 0) {
        memset(buf, 0, 0x960);
        MessageSystem_FormatText(g, 0xc, elem->w1, buf, 0xe3, 0, 1);
        *(void**)((char*)node5 + 0x20) = buf;
    }

    void* var30 = func_ov023_021f6880(var0, 0x36);
    if (!var30) {
        return 0;
    }
    if (func_ov024_021f6f10(var30) != 6) {
        return 0;
    }
    *(short*)((char*)var30 + 0x104) = var2;
    *(short*)((char*)var30 + 0x106) = var3;
    func_ov023_021f809c(var30, arg0);

    }
#endif
    return 0;
}
