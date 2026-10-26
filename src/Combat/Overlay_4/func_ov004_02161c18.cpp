#include <globaldefs.h>

struct Struct_ov004_021707e8_4 {
#if defined(jpn)
    unsigned char pad0[4];
    signed char field6;
    unsigned char pad5;
    unsigned char unknown1_7_;
    unsigned char unknown_7_;
    signed char fieldB;
    unsigned char unknown_9_[3];
#else
    unsigned char pad0[6];
    signed char field6;
    unsigned char unknown1_7_;
    unsigned char pad8[3];
    signed char fieldB;
#endif
    char* textBuf;
    unsigned char pad10[0xc];
    int combatantId;
};

struct Struct_ov004_02161c18 {
    short ids[7];
    unsigned char unknown_e_[7];
    unsigned char active;
};

struct Struct_ov004_02170b90_3 {
    struct Struct_ov004_02161c18 entries[26];
    unsigned char cursor;
    unsigned char unknown_23d_[2];
    unsigned char count;
};

class Struct_ov004_02161c18_2 {
public:
    virtual void inline_ov004_02161c18_46(); virtual void inline_ov004_02161c18_47(); virtual void inline_ov004_02161c18_48(); virtual void inline_ov004_02161c18_49();
    virtual void inline_ov004_02161c18_50(); virtual void inline_ov004_02161c18_51(); virtual void inline_ov004_02161c18_52(); virtual void inline_ov004_02161c18_53();
    virtual void inline_ov004_02161c18_54(); virtual void inline_ov004_02161c18_55(); virtual void inline_ov004_02161c18(); virtual void inline_ov004_02161c18_2();
    virtual void inline_ov004_02161c18_3(); virtual void inline_ov004_02161c18_4(); virtual void inline_ov004_02161c18_5(); virtual void inline_ov004_02161c18_6();
    virtual void inline_ov004_02161c18_7(); virtual void inline_ov004_02161c18_8(); virtual void inline_ov004_02161c18_9(); virtual void inline_ov004_02161c18_10();
    virtual void inline_ov004_02161c18_11(); virtual void inline_ov004_02161c18_12(); virtual void inline_ov004_02161c18_13(); virtual void inline_ov004_02161c18_14();
    virtual void inline_ov004_02161c18_15(); virtual void inline_ov004_02161c18_16(); virtual void inline_ov004_02161c18_17(); virtual void inline_ov004_02161c18_18();
    virtual void inline_ov004_02161c18_19(); virtual void inline_ov004_02161c18_20(); virtual void inline_ov004_02161c18_21(); virtual void inline_ov004_02161c18_22();
    virtual void inline_ov004_02161c18_23(); virtual void inline_ov004_02161c18_24(); virtual void inline_ov004_02161c18_25(); virtual void inline_ov004_02161c18_26();
    virtual void inline_ov004_02161c18_27(); virtual void inline_ov004_02161c18_28(); virtual void inline_ov004_02161c18_29(); virtual void inline_ov004_02161c18_30();
    virtual void inline_ov004_02161c18_31(); virtual void inline_ov004_02161c18_32(); virtual void inline_ov004_02161c18_33(); virtual void inline_ov004_02161c18_34();
    virtual void inline_ov004_02161c18_35(); virtual void inline_ov004_02161c18_36(); virtual void inline_ov004_02161c18_37(); virtual void inline_ov004_02161c18_38();
    virtual void inline_ov004_02161c18_39(); virtual void inline_ov004_02161c18_40(); virtual void inline_ov004_02161c18_41(); virtual void inline_ov004_02161c18_42();
    virtual void inline_ov004_02161c18_43(); virtual void inline_ov004_02161c18_44();
    virtual void inline_ov004_02161c18_45(int arg);

    unsigned char pad4[8];
    unsigned char flags;
};

extern "C" void __clear(void* buf, int n);
extern "C" void* func_ov011_021849c8(void* self);
extern "C" Struct_ov004_02161c18_2* func_ov004_0215e47c(void* a, int key);
extern "C" void func_ov004_0215e574(void* a, unsigned short key, int c, int d, int e);
extern "C" void func_ov004_0215e49c(void*, int, int);
extern "C" Struct_ov004_02161c18_2* func_ov023_021f6880(void* list, int key);
extern "C" int func_ov023_021f6f10(Struct_ov004_02161c18_2* node);
extern "C" void func_ov004_0215f6f4(void* a, short v1, short v2, int flag);

extern struct Struct_ov004_021707e8_4 data_ov004_021707e8;
extern struct Struct_ov004_02170b90_3 data_ov004_02170b90;
extern int data_ov004_0216fe90[];
#if defined(jpn)
extern short data_ov004_021710a8[];
extern unsigned char data_ov004_02171090[];
#else
extern short data_ov004_02170818[];
extern unsigned char data_ov004_02170814[];
#endif

// JPN: func_ov004_02161c18 (021624fc)
// USA: func_ov004_02161c18
extern "C" ARM int func_ov004_02161c18(void* self) {
    int state;
    int var1;
    void* obj;
    int var3;
    int var4;
    int j;
    int i;
    int st;
    int k;
    Struct_ov004_02161c18_2* node;
    int found;
    int idx;
    int next;
    unsigned char var13[2];
    struct Struct_ov004_02170b90_3* page;
    struct Struct_ov004_02161c18* entry;

    data_ov004_021707e8.unknown1_7_ = 0x66;
    var3 = 0;
    obj = func_ov011_021849c8(self);
    if (data_ov004_021707e8.field6 == 0) {
        node = func_ov004_0215e47c(self, 3);
        if (node != 0) node->flags &= ~4;
    } else {
        node = func_ov004_0215e47c(self, 3);
        if (node != 0) node->flags |= 4;
    }

    if (data_ov004_02170b90.count != 0) {
        for (i = 0xd; i < 0xf; i++) func_ov004_0215e49c(self, i, 0x3a);
        for (i = 0xf; i < 0x1d; i++) func_ov004_0215e49c(self, i, 0x11e);
        func_ov004_0215e49c(self, 0x31, 0x3a);
        func_ov004_0215e49c(self, 0x32, 0x3a);
        for (j = 0; j < 3; j++) {
            node = func_ov023_021f6880(obj, j + 0x65);
            if (node != 0) node->flags &= ~8;
        }
    #if !defined(jpn)
    func_ov004_0215e574(self, 0xc, 0xff, 0, 0);
#endif

        page = &data_ov004_02170b90;
        if (page->count <= 1) page->cursor = 0;
        next = page->cursor;
        if (next >= 26) next = 0;
        var4 = 0;
        __clear(var13, 2);
        found = 0;
        for (i = next; i < 26; i++) {
            idx = data_ov004_0216fe90[i];
            entry = &page->entries[idx - 1];
            if (!entry->active) continue;
            {
                int cid;
                int base;
                func_ov004_0215e49c(self, var4 + 0xd, i + 0x19f);
#if !defined(jpn)
                if (var4 == 0) {
                    func_ov004_0215e574(self, var4 + 0xd, 0x80, 0, 0);
                } else {
                    func_ov004_0215e574(self, var4 + 0xd, 0x80, 0x80, 0);
                }
#endif
                node = func_ov023_021f6880(obj, var4 + 0xd);
                if (node == 0) continue;
                cid = data_ov004_021707e8.combatantId;
#if defined(jpn)
                if (idx != data_ov004_021710a8[cid] && idx <= 0xe) st = 3;
                else st = 0xf;
                if (idx == 0xd && data_ov004_02171090[cid] == 1) st = 0xf;
#else
                if (idx != data_ov004_02170818[cid] && idx <= 0xe) st = 3;
                else st = 0xf;
                if (idx == 0xd && data_ov004_02170814[cid] == 1) st = 0xf;
#endif
                node->inline_ov004_02161c18_45(st);
                if (st == 0xf) var13[var4] = 1;

                for (k = 0; k < 7; k++) {
                    int key = entry->ids[k];
                    if (key < 0) break;
                    base = 0xf;
                    if (var4 == 1) base = 0x16;
                    func_ov004_0215e49c(self, base + k, key);
                    node = func_ov023_021f6880(obj, base + k);
                    if (node != 0 && func_ov023_021f6f10(node) == 8) node->inline_ov004_02161c18_45(st);
                }
            }
            next = i + 1;
            found = 1;
            if (++var4 == 2) break;
        }
        if (found) {
            int var19 = 0;
            for (; next < 26; next++) {
                if (page->entries[data_ov004_0216fe90[next] - 1].active) {
                    var19 = 1;
                    break;
                }
            }
            if (!var19) next = 26;
            page->cursor = next;
        }
        if (var13[0] == 0 && var13[1] == 0) var3 = 1;
    } else {
        for (i = 0xd; i < 0xf; i++) func_ov004_0215e49c(self, i, 0x3a);
        for (i = 0xf; i < 0x1d; i++) func_ov004_0215e49c(self, i, 0x11e);
        for (j = 0; j < 3; j++) {
            node = func_ov023_021f6880(obj, j + 0x65);
            if (node != 0) node->flags |= 8;
        }
        func_ov004_0215e49c(self, 0x31, 0x1e2);
        func_ov004_0215e49c(self, 0x32, 0x1e3);
#if !defined(jpn)
        func_ov004_0215e574(self, 0x31, 0xff, 0, 0);
        func_ov004_0215e574(self, 0x32, 0xff, 0, 0);
#endif
    }

    state = 0xf;
    if (var3) state = 3;
    node = func_ov023_021f6880(obj, 0xc);
    if (node != 0 && func_ov023_021f6f10(node) == 8) node->inline_ov004_02161c18_45(state);
    for (var1 = 0; var1 < 4; var1++) {
        node = func_ov023_021f6880(obj, var1 + 0x64);
        if (node != 0 && func_ov023_021f6f10(node) == 0x13) node->inline_ov004_02161c18_45(state);
    }
    func_ov004_0215f6f4(self, data_ov004_021707e8.fieldB, data_ov004_021707e8.field6, var3);
    return 0;
}
