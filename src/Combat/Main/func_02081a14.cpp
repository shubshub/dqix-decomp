#include <globaldefs.h>
#include "std_library_functions.h"

#if defined(jpn)
#define MessageSystem_FormatText func_020474a8
#define func_0204f41c func_02050678
#endif

struct TableA68;
struct StoreStruct;

extern "C" int MessageSystem_GetInstance();
extern "C" void* func_02072a68(struct TableA68* table, int key);
extern "C" void func_020465c0(struct StoreStruct* base, int index, int value);

extern "C" void func_02046380(int g);
#if defined(jpn)
extern "C" void func_020465d8(unsigned char*, int, unsigned char);
extern "C" void func_020465f0(unsigned char*, int, unsigned char);
extern "C" void MessageSystem_FormatText(int g, int nibble, void* found, void* buf);
extern "C" void func_0204f41c(void* b, short diff, int field8, void* field18, int nibble, int arg5, short* arg6, short* arg7);
#else
extern "C" void MessageSystem_FormatText(int g, int nibble, void* found, void* buf, int a5, int a6, int a7);
extern "C" int Font_GetTextWidth(void* value, int flag);
extern "C" void func_0204f41c(void* b, short diff, int field8, void* field18, int nibble, int arg5, short* arg6, short* arg7, int zero);
#endif

struct Struct_02081a14 {
    struct TableA68* field0;
    char pad4[0x18 - 0x4];
    void* field18;
};

struct Struct_02081a14_2 {
    char pad[0xb4];
    unsigned short fieldB4;
    unsigned short fieldB6;
};

struct Struct_02081a14_3 {
    int field0;
    char pad1[0x6 - 0x4];
    short field6;
    short field8;
    short fieldA;
    short fieldC;
    short unknown_e_;
    short field10;
    char pad2[0x13 - 0x12];
    unsigned char field13nibble : 4;
    unsigned char unknown_13_4_ : 4;
    unsigned char field14 : 2;
#if defined(jpn)
    unsigned char unknown_14_2_ : 6;
#endif
    char pad3[0x28 - 0x15];
    short field28;
    unsigned char field2a;
};

// USA: func_02081a14
extern "C" ARM void func_02081a14(struct Struct_02081a14* a, struct Struct_02081a14_2* b, struct Struct_02081a14_3* e) {
    int var0 = e->unknown_13_4_;
    if (e->field2a & 0x4) {
        var0 = 5;
    }

    int g = MessageSystem_GetInstance();
#if defined(jpn)
    memset(a->field18, 0, 0x800);
    func_02046380(g);
    int index = e->field10;
    func_020465c0((struct StoreStruct*)g, index, e->field0);
    func_020465d8((unsigned char*)g, index, e->field14);
    func_020465f0((unsigned char*)g, index, e->unknown_14_2_);

    void* found = func_02072a68(a->field0, e->unknown_e_);
    MessageSystem_FormatText(g, e->field13nibble, found, a->field18);

    int nibble = e->field13nibble;
    b->fieldB4 = nibble;
    b->fieldB6 = nibble + 1;

    func_0204f41c(b, (short)(e->field6 + e->field28), e->field8, a->field18,
                  e->field13nibble, var0, &e->fieldA, &e->fieldC);
#else
    memset(a->field18, 0, 0x960);
    func_02046380(g);
    func_020465c0((struct StoreStruct*)g, e->field10, e->field0);

    void* found = func_02072a68(a->field0, e->unknown_e_);
    MessageSystem_FormatText(g, e->field13nibble, found, a->field18, 0x100, 0, 0);

    int y = 0;
    if (e->field14 != 0) {
        y = Font_GetTextWidth(a->field18, 0);
    }

    int nibble = e->field13nibble;
    b->fieldB4 = nibble;
    b->fieldB6 = nibble + 1;

    func_0204f41c(b, (short)(e->field6 + e->field28 - y), e->field8, a->field18,
                  e->field13nibble, var0, &e->fieldA, &e->fieldC, 0);
#endif
}
