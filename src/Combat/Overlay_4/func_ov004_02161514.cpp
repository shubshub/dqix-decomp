#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov011_021849c8(void* p);
struct GameState;
extern "C" int func_02053c6c(unsigned char* obj);
extern "C" void func_0209a804(int* field);
struct Ctx0209a810 { void* field0; };
extern "C" void SpellTable_Load(Ctx0209a810* ctx, void* value);
extern "C" void func_ov004_0215e49c(void*, int, int);
extern "C" int func_ov004_0215e460(void);
extern "C" void func_ov004_0215e574(void* a, int key, int c, int d, int e);
extern "C" void func_ov004_0215f6f4(void* a, short v1, short v2, int flag);

struct Struct_ov004_02161514_3 {
    char pad0[0xc];
    unsigned char unknown_c_;
};
extern "C" Struct_ov004_02161514_3* func_ov004_0215e47c(void* a, int key);

class Struct_ov004_02161514_4 {
public:
    virtual void inline_ov004_02161514_45(); virtual void inline_ov004_02161514_46(); virtual void inline_ov004_02161514_47(); virtual void inline_ov004_02161514_48();
    virtual void inline_ov004_02161514_49(); virtual void inline_ov004_02161514_50(); virtual void inline_ov004_02161514_51(); virtual void inline_ov004_02161514_52();
    virtual void inline_ov004_02161514_53(); virtual void inline_ov004_02161514_54(); virtual void inline_ov004_02161514_55(); virtual void inline_ov004_02161514();
    virtual void inline_ov004_02161514_2(); virtual void inline_ov004_02161514_3(); virtual void inline_ov004_02161514_4(); virtual void inline_ov004_02161514_5();
    virtual void inline_ov004_02161514_6(); virtual void inline_ov004_02161514_7(); virtual void inline_ov004_02161514_8(); virtual void inline_ov004_02161514_9();
    virtual void inline_ov004_02161514_10(); virtual void inline_ov004_02161514_11(); virtual void inline_ov004_02161514_12(); virtual void inline_ov004_02161514_13();
    virtual void inline_ov004_02161514_14(); virtual void inline_ov004_02161514_15(); virtual void inline_ov004_02161514_16(); virtual void inline_ov004_02161514_17();
    virtual void inline_ov004_02161514_18(); virtual void inline_ov004_02161514_19(); virtual void inline_ov004_02161514_20(); virtual void inline_ov004_02161514_21();
    virtual void inline_ov004_02161514_22(); virtual void inline_ov004_02161514_23(); virtual void inline_ov004_02161514_24(); virtual void inline_ov004_02161514_25();
    virtual void inline_ov004_02161514_26(); virtual void inline_ov004_02161514_27(); virtual void inline_ov004_02161514_28(); virtual void inline_ov004_02161514_29();
    virtual void inline_ov004_02161514_30(); virtual void inline_ov004_02161514_31(); virtual void inline_ov004_02161514_32(); virtual void inline_ov004_02161514_33();
    virtual void inline_ov004_02161514_34(); virtual void inline_ov004_02161514_35(); virtual void inline_ov004_02161514_36(); virtual void inline_ov004_02161514_37();
    virtual void inline_ov004_02161514_38(); virtual void inline_ov004_02161514_39(); virtual void inline_ov004_02161514_40(); virtual void inline_ov004_02161514_41();
    virtual void inline_ov004_02161514_42(); virtual void inline_ov004_02161514_43();
    virtual void inline_ov004_02161514_44(int arg);
};
extern "C" Struct_ov004_02161514_4* func_ov023_021f6880(void* obj, int key);

struct Struct_ov004_02161514 {
    unsigned short id;
    unsigned short level;
};
struct Struct_ov004_02161514_2 {
    char pad[0x10c];
    Struct_ov004_02161514 rows[13][20];
    int counts[13];
};

struct Struct_ov004_021707e8_3 {
    unsigned char unknown0[2];
    unsigned char unknown_2_;
#if defined(jpn)
    unsigned char unknown3;
    signed char itemCount;
    unsigned char unknown5;
#else
    unsigned char unknown3[3];
    signed char itemCount;
#endif
    unsigned char state;
    unsigned char unknown_8_;
#if !defined(jpn)
    unsigned char unknown9[2];
#endif
    signed char unknown_b_;
#if defined(jpn)
    unsigned char unknown9[0x1c - 9];
#else
    unsigned char unknown_c_[0x1c - 0xc];
#endif
    int combatant;
};
extern Struct_ov004_021707e8_3 data_ov004_021707e8;
extern int data_ov004_02170854[];
#if defined(jpn)
extern unsigned char data_ov004_02170568[];
extern unsigned char data_ov004_021710b0[];
#else
extern unsigned char data_ov004_0216fde8[];
#endif
extern unsigned char data_ov004_02170838[];
extern unsigned char data_ov004_02170820[];

// JPN: func_ov004_02161514 (02161ea4)
// USA: func_ov004_02161514
extern "C" ARM int func_ov004_02161514(void* a) {
    Ctx0209a810 ctx;
    Struct_ov004_02161514_2 buf;
    void* obj;
    int var3;
    unsigned char flag;
    int t;
    unsigned char* field;
    unsigned int limit;
    int count;
    Struct_ov004_02161514* rows;
    unsigned char cnt;
    int i;
    int j;
    unsigned char k;
    int same;
    Struct_ov004_02161514_4* node;

    data_ov004_021707e8.state = 0x65;
    obj = func_ov011_021849c8(a);
    var3 = 0;
    flag = 0;
    if (data_ov004_021707e8.unknown_2_ != data_ov004_02170854[data_ov004_021707e8.unknown_8_]) flag = 1;

#if defined(jpn)
    if (data_ov004_021707e8.itemCount == 0) {
        func_ov004_0215e47c(a, 3)->unknown_c_ &= ~4;
    } else {
        func_ov004_0215e47c(a, 3)->unknown_c_ |= 4;
    }
#else
    func_ov004_0215e47c(a, 3)->unknown_c_ |= 4;
#endif

    t = data_ov004_02170854[data_ov004_021707e8.unknown_8_];
    if (t != 1 && t != 4 && t != 7) {
        unsigned char* combatant = (unsigned char*)func_0200ff1c((GameState*)(void*)GameState::GetInstance(), data_ov004_021707e8.combatant);
        if (!combatant) return 0;
        field = (unsigned char*)func_02053c6c(combatant);
        if (!field) return 0;
        limit = *(unsigned short*)(field + data_ov004_02170854[data_ov004_021707e8.unknown_8_] * 2 + 0x16c);
        func_0209a804((int*)&ctx);
        SpellTable_Load(&ctx, &buf);
        count = buf.counts[data_ov004_02170854[data_ov004_021707e8.unknown_8_]];
        rows = buf.rows[data_ov004_02170854[data_ov004_021707e8.unknown_8_]];
        cnt = 0;

        for (i = 0xc; i < 0x30; i++) func_ov004_0215e49c(a, i, 0x3a);
        func_ov004_0215e49c(a, 0x31, 0x3a);
        func_ov004_0215e49c(a, 0x32, 0x3a);
        func_ov004_0215e49c(a, 0xc, 0x3b);
        func_ov004_0215e49c(a, 0xd, 1);
        if (func_ov004_0215e460()) {
            func_ov004_0215e49c(a, 0xe, 4);
        } else {
            func_ov004_0215e49c(a, 0xe, data_ov004_02170854[data_ov004_021707e8.unknown_8_] + 4);
        }

        if (data_ov004_021707e8.unknown_2_ != data_ov004_02170854[data_ov004_021707e8.unknown_8_]) {
            for (k = 0; k < 3; k++) {
                node = func_ov023_021f6880(obj, k + 0xc);
                if (node) node->inline_ov004_02161514_44(3);
            }
            node = func_ov023_021f6880(obj, 0x64);
            if (node) node->inline_ov004_02161514_44(3);
        } else {
            for (k = 0; k < 3; k++) {
                node = func_ov023_021f6880(obj, k + 0xc);
                if (node) node->inline_ov004_02161514_44(0xf);
            }
            node = func_ov023_021f6880(obj, 0x64);
            if (node) node->inline_ov004_02161514_44(0xf);
        }

        for (i = 0; i < count; i++) {
            unsigned short id = rows[i].id;
            unsigned short level = rows[i].level;
            if (level != 0 && level <= limit) {
                int st;
                func_ov004_0215e49c(a, cnt + 0xf, id + 0x3f);
                st = 0xf;
                if (data_ov004_021707e8.unknown_2_ != data_ov004_02170854[data_ov004_021707e8.unknown_8_]) st = 3;
                node = func_ov023_021f6880(obj, cnt + 0xf);
                if (node) node->inline_ov004_02161514_44(st);
                cnt++;
            }
        }

        if (cnt == 0) {
            var3 = 1;
            for (j = 0xc; j < 0x30; j++) func_ov004_0215e49c(a, j, 0x3a);
            func_ov004_0215e49c(a, 0x31, 0x1e1);
            func_ov004_0215e49c(a, 0x32, 0x1e3);
#if !defined(jpn)
            func_ov004_0215e574(a, 0x31, 0xff, 0, 0);
#endif
#if !defined(jpn)
            func_ov004_0215e574(a, 0x32, 0xff, 0, 0);
#endif
            func_ov004_0215e49c(a, 0xc, 0x3b);
            func_ov004_0215e49c(a, 0xd, 1);
            if (func_ov004_0215e460()) {
                func_ov004_0215e49c(a, 0xe, 4);
            } else {
                func_ov004_0215e49c(a, 0xe, data_ov004_02170854[data_ov004_021707e8.unknown_8_] + 4);
            }
            same = 1;
            if (data_ov004_021707e8.unknown_2_ != data_ov004_02170854[data_ov004_021707e8.unknown_8_]) same = 0;
            for (int i = 0; i < 5; i++) {
#if defined(jpn)
                node = func_ov023_021f6880(obj, data_ov004_02170568[i]);
#else
                node = func_ov023_021f6880(obj, data_ov004_0216fde8[i]);
#endif
                if (node) {
                    if (same) node->inline_ov004_02161514_44(0xf);
                    else node->inline_ov004_02161514_44(3);
                }
            }
        }
    } else {
        int st;
        var3 = 1;
        for (j = 0xc; j < 0x30; j++) func_ov004_0215e49c(a, j, 0x3a);
        func_ov004_0215e49c(a, 0x31, 0x1e1);
        func_ov004_0215e49c(a, 0x32, 0x1e3);
#if !defined(jpn)
        func_ov004_0215e574(a, 0x31, 0xff, 0, 0);
#endif
#if !defined(jpn)
        func_ov004_0215e574(a, 0x32, 0xff, 0, 0);
#endif
        func_ov004_0215e49c(a, 0xc, 0x3b);
        func_ov004_0215e49c(a, 0xd, 1);
        if (func_ov004_0215e460()) {
            func_ov004_0215e49c(a, 0xe, 4);
        } else {
            func_ov004_0215e49c(a, 0xe, data_ov004_02170854[data_ov004_021707e8.unknown_8_] + 4);
        }
        same = 1;
        if (data_ov004_021707e8.unknown_2_ != data_ov004_02170854[data_ov004_021707e8.unknown_8_]) same = 0;
        for (int i = 0; i < 5; i++) {
#if defined(jpn)
            node = func_ov023_021f6880(obj, data_ov004_02170568[i]);
#else
            node = func_ov023_021f6880(obj, data_ov004_0216fde8[i]);
#endif
            if (node) {
                if (same) node->inline_ov004_02161514_44(0xf);
                else node->inline_ov004_02161514_44(3);
            }
        }
        st = 0xf;
        if (!same) st = 3;
        node = func_ov023_021f6880(obj, 0x64);
        if (node) node->inline_ov004_02161514_44(st);
        if (data_ov004_021707e8.itemCount == 0) {
            Struct_ov004_02161514_3* tag = func_ov004_0215e47c(a, 3);
            if (tag) tag->unknown_c_ &= ~4;
        }
    }

#if !defined(jpn)
    if (var3) {
        unsigned char n = 0;
        int m;
        for (m = 1; m < 0xd; m++) {
            if (data_ov004_02170838[m]) n++;
            if (n > 1) break;
        }
        if (n <= 1) func_ov004_0215e47c(a, 3)->unknown_c_ &= ~4;
    }

#endif

    {
        int d;
#if defined(jpn)
        data_ov004_021707e8.unknown_b_ = data_ov004_021710b0[data_ov004_02170854[data_ov004_021707e8.unknown_8_] - 1];
        d = data_ov004_021707e8.unknown_b_ - data_ov004_021710b0[data_ov004_021707e8.unknown_2_ - 1];
#else
        data_ov004_021707e8.unknown_b_ = data_ov004_02170820[data_ov004_02170854[data_ov004_021707e8.unknown_8_] - 1];
        d = data_ov004_021707e8.unknown_b_ - data_ov004_02170820[data_ov004_021707e8.unknown_2_ - 1];
#endif
        if (d < 0) d += data_ov004_021707e8.itemCount;
        data_ov004_021707e8.unknown_b_ = d;
    }
    func_ov004_0215f6f4(a, data_ov004_021707e8.unknown_b_, data_ov004_021707e8.itemCount, flag);
    return 0;
}
