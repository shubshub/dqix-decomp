#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

struct TableA68;
struct StoreStruct;
struct Struct_ov004_021549e4_3;
struct Obj02046574;
#if defined(jpn)
extern "C" void* func_ov004_02168f08(void* ctx, int value);
extern "C" void func_020474a8(void* a, int b, char* c, char* d);
#else
extern "C" void* func_ov023_021f6524(void* ctx, int value);
#endif
#if defined(jpn)
extern "C" struct TableA68* func_ov004_02169040(void* a, int key);
#else
extern "C" struct TableA68* func_ov004_02168b08(void* a, int key);
#endif
extern "C" int MessageSystem_GetInstance(void);
extern "C" void* func_02053c6c(unsigned char* obj);
extern "C" void* Scenario_GetInstance(void* obj);
extern "C" int func_ov023_021f9bc8(char* obj);
extern "C" unsigned int func_ov023_021f9b6c(struct Struct_ov004_021549e4_3* obj, unsigned int a, unsigned int b);
extern "C" void __clear(void* buf, int len);
extern "C" void Font_DecodeText(const char* name, char* dest, int flag);
extern "C" void* func_ov004_02168a6c(void* a, int id);
extern "C" void* func_02072a68(struct TableA68* table, int key);
extern "C" void func_02046380(void* global);
extern "C" void MessageSystem_SetStringArgument(struct Obj02046574* obj, int index, char* str);
extern "C" void MessageSystem_FormatText(void* a, int b, char* c, char* d, int e, int f, int g);
extern "C" char* func_020d2f88(char* arg0, char* arg1);
extern "C" int func_020ac4c0(void* dst);
extern "C" void func_020465c0(struct StoreStruct* base, int index, int value);
extern "C" int Scenario_TestFlag(int unused, unsigned char* arr, int index);
extern "C" void func_020465f0(unsigned char* base, int index, unsigned char value);
extern "C" void func_020465d8(unsigned char* base, int index, unsigned char value);
#if defined(jpn)
extern "C" void* func_ov004_02168fa4(void*, int);
extern "C" void func_ov023_021f809c(void*, void*);
#else
extern "C" int func_ov023_021f6680(void* obj, int id);
#endif

struct Struct_ov004_02169b4c {
    unsigned int unknown_0_0_ : 14;
    unsigned int unknown_1_6_ : 17;
    unsigned int unknown_3_7_ : 1;
    unsigned int unknown_4_0_ : 14;
    unsigned int unknown_5_6_ : 17;
    unsigned int unknown_7_7_ : 1;
    unsigned int unknown_8_0_ : 7;
    unsigned int unknown_8_7_ : 7;
    unsigned int unknown_9_6_ : 7;
    unsigned int unknown_a_5_ : 7;
    unsigned int unknown_b_4_ : 4;
    unsigned int unknown_c_0_ : 10;
    unsigned int unknown_d_2_ : 14;
    unsigned int unknown_f_0_ : 7;
    unsigned int unknown_f_7_ : 1;
    unsigned int unknown_10_0_ : 9;
    unsigned int unknown_11_1_ : 14;
    unsigned int unknown_12_7_ : 7;
    unsigned int unknown_13_6_ : 2;
    short f14;
    unsigned char unknown_16_0_ : 1;
};

struct Struct_ov004_02169b4c_2 {
    char pad[6];
    char name[0xe];
    struct Struct_ov004_02169b4c rec;
};

struct Struct_ov004_02169b4c_3 {
    unsigned short unknown_0_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    unsigned short f04;
    unsigned char unknown_6_;
    unsigned char unknown_7_;
    unsigned int f08 : 24;
    unsigned int unknown_b_0_ : 8;
    unsigned int unknown_c_0_ : 14;
    unsigned int unknown_d_6_ : 14;
    unsigned int unknown_f_4_ : 4;
    char rest[0xb0 - 0x10];
};

struct Struct_ov004_02169b4c_4 {
#if defined(jpn)
    char pad[0x10];
#else
    char pad[0x190];
#endif
    char* unknown_190_;
    struct Struct_ov004_02169b4c* unknown_194_;
    unsigned char unknown_198_;
    char unknown_199_[3];
    char* unknown_19c_;
};

struct Struct_ov004_02169b4c_5 { char pad[0x5c]; short unknown_5c_; };
struct Struct_ov004_02169b4c_6 { int a, b, c; };

class Struct_ov004_02169b4c_7 {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void Apply(struct Struct_ov004_02169b4c_6* t);
    virtual struct Struct_ov004_02169b4c_6 Get();
    char pad4[8];
    unsigned char b0 : 3;
    unsigned char hidden : 1;
    char pad0d[0x20 - 0xd];
    char* text;
    char pad24[0x45 - 0x24];
    unsigned char unknown_45_0_ : 1;
    unsigned char mode : 6;
};

extern struct Struct_ov004_02169b4c_4* data_ov004_02171030;
extern char data_ov004_02170704[];

// JPN: func_ov004_02169b4c (0216a044)
// USA: func_ov004_02169b4c
extern "C" ARM int func_ov004_02169b4c(void* a) {
    char* areas = data_ov004_02171030->unknown_190_;
    if (!areas) return 0;

#if defined(jpn)
    struct Struct_ov004_02169b4c_5* grid = static_cast<Struct_ov004_02169b4c_5*>(func_ov004_02168f08(a, 0x64));
#else
    struct Struct_ov004_02169b4c_5* grid = static_cast<Struct_ov004_02169b4c_5*>(func_ov023_021f6524(a, 0x64));
#endif
#if defined(jpn)
    struct TableA68* tblA = func_ov004_02169040(a, 3);
#else
    struct TableA68* tblA = func_ov004_02168b08(a, 3);
#endif
    void* g = (void*)MessageSystem_GetInstance();
    unsigned char* prot = (unsigned char*)func_02053c6c((unsigned char*)GameState::GetInstance()->GetProtagonist());
    unsigned char* flags = (unsigned char*)Scenario_GetInstance(prot);
#if defined(jpn)
    struct TableA68* var6 = func_ov004_02169040(a, 9);
#else
    struct TableA68* var6 = func_ov004_02168b08(a, 9);
#endif
#if defined(jpn)
    struct TableA68* var7 = func_ov004_02169040(a, 6);
#else
    struct TableA68* var7 = func_ov004_02168b08(a, 6);
#endif
#if defined(jpn)
    struct TableA68* var8 = func_ov004_02169040(a, 7);
#else
    struct TableA68* var8 = func_ov004_02168b08(a, 7);
#endif
    short var9 = grid->unknown_5c_;
    int var10 = func_ov023_021f9bc8((char*)grid);
    int idx = var10 + var9 * 8;
    if (!func_ov023_021f9b6c((struct Struct_ov004_021549e4_3*)grid, (unsigned short)var10, 0)) return 0;

    struct Struct_ov004_02169b4c_2* area = (struct Struct_ov004_02169b4c_2*)(areas + 4) + idx;
#if !defined(jpn)
    char buf[0x30];
    __clear(buf, 0x30);
#endif
    char* name;
    struct Struct_ov004_02169b4c* rec;
    if (data_ov004_02171030->unknown_198_) {
        name = (char*)(prot + 0x3c);
        rec = data_ov004_02171030->unknown_194_;
    } else {
        rec = &area->rec;
#if defined(jpn)
        name = area->name;
#else
        Font_DecodeText(area->name, buf, 1);
        name = buf;
#endif
    }

    char* out = data_ov004_02171030->unknown_19c_;
    memset(out, 0, 4);
    Struct_ov004_02169b4c_7* node;

#if defined(jpn)
    func_02046380(g);
    char* format = static_cast<char*>(func_02072a68(tblA, 0x23));
    func_020465c0(static_cast<StoreStruct*>(g), 0, rec->unknown_0_0_);
    func_020465f0(static_cast<unsigned char*>(g), 0, 4);
    func_020465d8(static_cast<unsigned char*>(g), 0, 1);
    func_020465c0(static_cast<StoreStruct*>(g), 1, rec->unknown_8_0_);
    func_020465f0(static_cast<unsigned char*>(g), 1, 2);
    func_020465d8(static_cast<unsigned char*>(g), 1, 1);
    func_020474a8(g, 8, format, out);
    node = static_cast<Struct_ov004_02169b4c_7*>(func_ov004_02168a6c(a, 0x190));
    node->text = out;
    out += strlen(out) + 1;

    func_02046380(g);
    func_020465c0(static_cast<StoreStruct*>(g), 0, rec->unknown_4_0_);
    func_020465f0(static_cast<unsigned char*>(g), 0, 4);
    func_020465d8(static_cast<unsigned char*>(g), 0, 1);
    func_020465c0(static_cast<StoreStruct*>(g), 1, rec->unknown_8_7_);
    func_020465f0(static_cast<unsigned char*>(g), 1, 2);
    func_020465d8(static_cast<unsigned char*>(g), 1, 1);
    func_020474a8(g, 8, static_cast<char*>(func_02072a68(tblA, 0x23)), out);
    node = static_cast<Struct_ov004_02169b4c_7*>(func_ov004_02168a6c(a, 0x191));
    node->text = out;
    out += strlen(out) + 1;

#else
    node = static_cast<Struct_ov004_02169b4c_7*>(func_ov004_02168a6c(a, 0x190));
    node->mode = 2;
    sprintf(out, static_cast<char*>(func_02072a68(tblA, 0x23)), rec->unknown_0_0_);
    node->text = out;
    out += strlen(out) + 1;

    node = static_cast<Struct_ov004_02169b4c_7*>(func_ov004_02168a6c(a, 0x1c2));
    node->mode = 2;
    sprintf(out, static_cast<char*>(func_02072a68(tblA, 0x23)), rec->unknown_8_0_);
    node->text = out;
    out += strlen(out) + 1;

    node = static_cast<Struct_ov004_02169b4c_7*>(func_ov004_02168a6c(a, 0x191));
    node->mode = 2;
    sprintf(out, static_cast<char*>(func_02072a68(tblA, 0x23)), rec->unknown_4_0_);
    node->text = out;
    out += strlen(out) + 1;

    node = static_cast<Struct_ov004_02169b4c_7*>(func_ov004_02168a6c(a, 0x1c3));
    node->mode = 2;
    sprintf(out, static_cast<char*>(func_02072a68(tblA, 0x23)), rec->unknown_8_7_);
    node->text = out;
    out += strlen(out) + 1;

#endif
    func_02046380(g);
    char* title;
    if (rec->f14 >= 700) {
        title = static_cast<char*>(func_02072a68(var6, (short)(rec->f14 + 20000)));
    } else if (rec->unknown_16_0_) {
        title = static_cast<char*>(func_02072a68(var8, rec->f14));
    } else {
        title = static_cast<char*>(func_02072a68(var7, rec->f14));
    }
    MessageSystem_SetStringArgument((struct Obj02046574*)g, 0, title);
    MessageSystem_SetStringArgument((struct Obj02046574*)g, 1, name);
#if defined(jpn)
    func_020474a8(g, 0xa, static_cast<char*>(func_02072a68(tblA, 0x22)), out);
#else
    MessageSystem_FormatText(g, 0xa, static_cast<char*>(func_02072a68(tblA, 0x22)), out, 0xf0, 1, 0);
#endif

    node = static_cast<Struct_ov004_02169b4c_7*>(func_ov004_02168a6c(a, 0x192));
    node->text = out;
#if !defined(jpn)
    struct Struct_ov004_02169b4c_6 t = node->Get();
    t.b = 0x7000;
    if (func_020d2f88(out, data_ov004_02170704)) t.b = 0x2000;
    node->Apply(&t);
#endif
    out += strlen(out) + 1;

    func_02046380(g);
    unsigned char count = 0;
    unsigned char mask = 0;
    struct Struct_ov004_02169b4c_3 blk;
    func_020ac4c0(&blk);
    mask |= 1;
    func_020465c0(static_cast<StoreStruct*>(g), count++, rec->unknown_5_6_);
    if (Scenario_TestFlag((int)flags, flags + 0x8c, 0x1198)) {
        mask |= 2;
        func_020465c0(static_cast<StoreStruct*>(g), count++, rec->unknown_1_6_);
    }
    mask |= 4;
    func_020465c0(static_cast<StoreStruct*>(g), count++, rec->unknown_c_0_);
    if (blk.unknown_b_0_) {
        mask |= 8;
        func_020465c0(static_cast<StoreStruct*>(g), count++, rec->unknown_10_0_);
    }
    if (blk.unknown_d_6_) {
        mask |= 0x10;
        func_020465c0(static_cast<StoreStruct*>(g), count++, rec->unknown_d_2_);
    }
    if (Scenario_TestFlag((int)flags, flags + 0x8c, 0x1199)) {
        mask |= 0x20;
        func_020465c0(static_cast<StoreStruct*>(g), count++, rec->unknown_11_1_);
    }

    unsigned char k = 0;
    int i;
    for (i = 0; i < 6; i++) {
        if (mask & (1 << i)) {
            func_020465f0(static_cast<unsigned char*>(g), k, 5);
            func_020465d8(static_cast<unsigned char*>(g), k, 1);
            strcpy(out, static_cast<char*>(func_02072a68(tblA, (short)(i + 0x28))));
            int base = k * 3;
            node = static_cast<Struct_ov004_02169b4c_7*>(func_ov004_02168a6c(a, base + 0x1f4));
            if (!node) continue;
            node->text = out;
            out += strlen(out) + 1;
#if defined(jpn)
            func_020474a8(g, 8, static_cast<char*>(func_02072a68(tblA, (short)(k + 0x14))), out);
#else
            MessageSystem_FormatText(g, 8, static_cast<char*>(func_02072a68(tblA, (short)(k + 0x14))), out, 0x100, 0, 0);
#endif
            node = static_cast<Struct_ov004_02169b4c_7*>(func_ov004_02168a6c(a, base + 0x1f5));
            if (!node) continue;
            node->text = out;
            out += strlen(out) + 1;
            int key;
            if (i == 5) {
                key = 0x30;
            } else if ((i == 2) | (i == 3)) {
                key = 0x2f;
            } else {
                key = 0x2e;
            }
            strcpy(out, static_cast<char*>(func_02072a68(tblA, key)));
            node = static_cast<Struct_ov004_02169b4c_7*>(func_ov004_02168a6c(a, base + 0x1f6));
            if (!node) continue;
            node->text = out;
            out += strlen(out) + 1;
            k++;
        }
    }
    for (int j = k; j < 6; j++) {
        int base = j * 3;
        (static_cast<Struct_ov004_02169b4c_7*>(func_ov004_02168a6c(a, base + 0x1f4)))->hidden = 1;
        (static_cast<Struct_ov004_02169b4c_7*>(func_ov004_02168a6c(a, base + 0x1f5)))->hidden = 1;
        (static_cast<Struct_ov004_02169b4c_7*>(func_ov004_02168a6c(a, base + 0x1f6)))->hidden = 1;
    }

    func_02046380(g);
    func_020465c0(static_cast<StoreStruct*>(g), 0, rec->unknown_9_6_);
    func_020465f0(static_cast<unsigned char*>(g), 0, 3);
    func_020465d8(static_cast<unsigned char*>(g), 0, 1);
    func_020465c0(static_cast<StoreStruct*>(g), 1, rec->unknown_f_0_);
    func_020465f0(static_cast<unsigned char*>(g), 1, 3);
    func_020465d8(static_cast<unsigned char*>(g), 1, 1);
    func_020465c0(static_cast<StoreStruct*>(g), 2, rec->unknown_a_5_);
    func_020465f0(static_cast<unsigned char*>(g), 2, 3);
    func_020465d8(static_cast<unsigned char*>(g), 2, 1);
    func_020465c0(static_cast<StoreStruct*>(g), 3, rec->unknown_12_7_);
    func_020465f0(static_cast<unsigned char*>(g), 3, 3);
    func_020465d8(static_cast<unsigned char*>(g), 3, 1);

    int rows = (mask & 2) ? 4 : 3;
    for (int r = 0; r < rows; r++) {
#if defined(jpn)
        func_020474a8(g, 8, static_cast<char*>(func_02072a68(tblA, (short)(r + 0x1e))), out);
#else
        MessageSystem_FormatText(g, 8, static_cast<char*>(func_02072a68(tblA, (short)(r + 0x1e))), out, 0x100, 0, 0);
#endif
        (static_cast<Struct_ov004_02169b4c_7*>(func_ov004_02168a6c(a, r * 2 + 6 + 0x200)))->text = out;
        out += strlen(out) + 1;
    }
    if (rows == 3) {
        (static_cast<Struct_ov004_02169b4c_7*>(func_ov004_02168a6c(a, 0x19c)))->hidden = 1;
        (static_cast<Struct_ov004_02169b4c_7*>(func_ov004_02168a6c(a, 0x20c)))->hidden = 1;
        (static_cast<Struct_ov004_02169b4c_7*>(func_ov004_02168a6c(a, 0x20d)))->hidden = 1;
    }

#if defined(jpn)
    {
        void* panel = func_ov004_02168fa4(a, 0x18);
        if (panel != 0) func_ov023_021f809c(panel, a);
    }
    {
        void* panel = func_ov004_02168fa4(a, 0x19);
        if (panel != 0) func_ov023_021f809c(panel, a);
    }
    {
        void* panel = func_ov004_02168fa4(a, 0x1c);
        if (panel != 0) func_ov023_021f809c(panel, a);
    }
    {
        void* panel = func_ov004_02168fa4(a, 0x1a);
        if (panel != 0) func_ov023_021f809c(panel, a);
    }
    {
        void* panel = func_ov004_02168fa4(a, 0x1d);
        if (panel != 0) func_ov023_021f809c(panel, a);
    }
    {
        void* panel = func_ov004_02168fa4(a, 0x1b);
        if (panel != 0) func_ov023_021f809c(panel, a);
    }
#else
    func_ov023_021f6680(a, 0x18);
    func_ov023_021f6680(a, 0x19);
    func_ov023_021f6680(a, 0x1c);
    func_ov023_021f6680(a, 0x1a);
    func_ov023_021f6680(a, 0x1d);
    func_ov023_021f6680(a, 0x1b);
#endif
    return 0;
}
