#include <globaldefs.h>

struct Struct_ov004_021707e8_5 {
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

struct Struct_ov004_02162108 {
    short ids[7];
    unsigned char unknown_e_[7];
    unsigned char active;
};

struct Struct_ov004_02170b90_4 {
    struct Struct_ov004_02162108 entries[26];
    unsigned char cursor;
    unsigned char unknown_23d_[2];
    unsigned char count;
};

class Struct_ov004_02162108_2 {
public:
    virtual void inline_ov004_02162108_46(); virtual void inline_ov004_02162108_47(); virtual void inline_ov004_02162108_48(); virtual void inline_ov004_02162108_49();
    virtual void inline_ov004_02162108_50(); virtual void inline_ov004_02162108_51(); virtual void inline_ov004_02162108_52(); virtual void inline_ov004_02162108_53();
    virtual void inline_ov004_02162108_54(); virtual void inline_ov004_02162108_55(); virtual void inline_ov004_02162108(); virtual void inline_ov004_02162108_2();
    virtual void inline_ov004_02162108_3(); virtual void inline_ov004_02162108_4(); virtual void inline_ov004_02162108_5(); virtual void inline_ov004_02162108_6();
    virtual void inline_ov004_02162108_7(); virtual void inline_ov004_02162108_8(); virtual void inline_ov004_02162108_9(); virtual void inline_ov004_02162108_10();
    virtual void inline_ov004_02162108_11(); virtual void inline_ov004_02162108_12(); virtual void inline_ov004_02162108_13(); virtual void inline_ov004_02162108_14();
    virtual void inline_ov004_02162108_15(); virtual void inline_ov004_02162108_16(); virtual void inline_ov004_02162108_17(); virtual void inline_ov004_02162108_18();
    virtual void inline_ov004_02162108_19(); virtual void inline_ov004_02162108_20(); virtual void inline_ov004_02162108_21(); virtual void inline_ov004_02162108_22();
    virtual void inline_ov004_02162108_23(); virtual void inline_ov004_02162108_24(); virtual void inline_ov004_02162108_25(); virtual void inline_ov004_02162108_26();
    virtual void inline_ov004_02162108_27(); virtual void inline_ov004_02162108_28(); virtual void inline_ov004_02162108_29(); virtual void inline_ov004_02162108_30();
    virtual void inline_ov004_02162108_31(); virtual void inline_ov004_02162108_32(); virtual void inline_ov004_02162108_33(); virtual void inline_ov004_02162108_34();
    virtual void inline_ov004_02162108_35(); virtual void inline_ov004_02162108_36(); virtual void inline_ov004_02162108_37(); virtual void inline_ov004_02162108_38();
    virtual void inline_ov004_02162108_39(); virtual void inline_ov004_02162108_40(); virtual void inline_ov004_02162108_41(); virtual void inline_ov004_02162108_42();
    virtual void inline_ov004_02162108_43(); virtual void inline_ov004_02162108_44();
    virtual void inline_ov004_02162108_45(int arg);

    unsigned char pad4[8];
    unsigned char flags;
    unsigned char unknown_d_[0x13];
    void* data;
};

struct TableA68;

extern "C" void memset(void* dst, int value, int size);
extern "C" void __clear(void* buf, int n);
extern "C" void* func_ov011_021849c8(void* self);
extern "C" Struct_ov004_02162108_2* func_ov004_0215e47c(void* a, int key);
extern "C" void func_ov004_0215e574(void* a, unsigned short key, int c, int d, int e);
extern "C" void func_ov004_0215e49c(void*, int, int);
extern "C" Struct_ov004_02162108_2* func_ov023_021f6880(void* list, int key);
extern "C" int func_ov023_021f6f10(Struct_ov004_02162108_2* node);
extern "C" struct TableA68* func_ov023_021fa598(Struct_ov004_02162108_2* node);
#if !defined(jpn)
extern "C" char* func_02072a68(struct TableA68* table, short key);
#endif
extern "C" char* func_020d2f88(char* str, char* sub);
extern "C" int MessageSystem_GetInstance(void);
extern "C" void MessageSystem_FormatText(int g, int mode, char* fmt, char* dst, int size, int a, int b);
extern "C" void func_ov004_0215f6f4(void* a, short v1, short v2, int flag);

extern struct Struct_ov004_021707e8_5 data_ov004_021707e8;
extern struct Struct_ov004_02170b90_4 data_ov004_02170b90[];
#if defined(jpn)
extern Struct_ov004_02170b90_4 data_ov004_02171660;
extern short data_ov004_021710a8[];
extern unsigned char data_ov004_02171090[];
#else
extern struct Struct_ov004_02170b90_4 data_ov004_02170dd0;
#endif
extern int data_ov004_0216fe90[];
extern short data_ov004_02170818[];
extern unsigned char data_ov004_02170814[];
extern char data_ov004_02170527[];

// JPN: func_ov004_02162108 (02162964)
// USA: func_ov004_02162108
extern "C" ARM int func_ov004_02162108(void* self) {
    data_ov004_021707e8.unknown1_7_ = 0x67;
    int var0 = 0;
#if !defined(jpn)
    memset(data_ov004_021707e8.textBuf, 0, 0x800);
#endif
    void* obj = func_ov011_021849c8(self);
    if (data_ov004_021707e8.field6 == 0) {
        Struct_ov004_02162108_2* node = func_ov004_0215e47c(self, 3);
        if (node != 0) node->flags &= ~4;
    } else {
        Struct_ov004_02162108_2* node = func_ov004_0215e47c(self, 3);
        if (node != 0) node->flags |= 4;
    }
#if !defined(jpn)
    func_ov004_0215e574(self, 0xc, 0xff, 0, 0);
#endif

    if (data_ov004_02170b90[1].count != 0) {
        for (int i = 0xd; i < 0xf; i++) func_ov004_0215e49c(self, i, 0x3a);
        for (int i = 0xf; i < 0x1d; i++) func_ov004_0215e49c(self, i, 0x11e);
        func_ov004_0215e49c(self, 0x31, 0x3a);
        func_ov004_0215e49c(self, 0x32, 0x3a);
        for (int j = 0; j < 3; j++) {
            Struct_ov004_02162108_2* node = func_ov023_021f6880(obj, j + 0x65);
            if (node != 0) node->flags &= ~8;
        }
#if !defined(jpn)
        func_ov004_0215e574(self, 0xc, 0xff, 0, 0);
#endif

#if defined(jpn)
        Struct_ov004_02170b90_4* page = &data_ov004_02171660;
#else
        Struct_ov004_02170b90_4* page = &data_ov004_02170dd0;
#endif
        if (page->count <= 1) page->cursor = 0;
        int next = page->cursor;
        if (next >= 26) next = 0;
        int var10 = 0;
        unsigned char var11[2];
        __clear(var11, 2);
        int found = 0;
        for (int i = next; i < 26; i++) {
            int idx = data_ov004_0216fe90[i];
            if (!page->entries[idx - 1].active) continue;
            {
                int cid = data_ov004_021707e8.combatantId;
                int off;
                short* ids;
                int st = 0xf;
#if defined(jpn)
                if (idx != data_ov004_021710a8[cid] && idx <= 0xe) st = 3;
                if (idx == 0xd && data_ov004_02171090[cid] != 0) st = 0xf;
#else
                if (idx != data_ov004_02170818[cid] && idx <= 0xe) st = 3;
                if (idx == 0xd && data_ov004_02170814[cid] != 0) st = 0xf;
#endif
                if (st == 0xf) var11[var10] = 1;
                short id = var10 + 0xd;
                ids = page->entries[idx - 1].ids;
                func_ov004_0215e49c(self, id, i + 0x19f);
#if !defined(jpn)
                if (var10 == 0) {
                    func_ov004_0215e574(self, id, 0x80, 0, 0);
                } else {
                    func_ov004_0215e574(self, id, 0x80, 0x80, 0);
                }
#endif
                Struct_ov004_02162108_2* node = func_ov023_021f6880(obj, id);
                if (node != 0) node->inline_ov004_02162108_45(st);

                for (int k = 0; k < 7; k++) {
                    int key = ids[k];
                    short n;
                    Struct_ov004_02162108_2* msg;
                    if (key < 0) break;
                    n = k;
                    if (var10 == 0) {
                        id = n + 0xf;
                        off = 0;
                    } else {
                        id = n + 0x16;
                        off = 7;
                    }
#if defined(jpn)
                    func_ov004_0215e49c(self, id, key);
#else
                    msg = func_ov004_0215e47c(self, 0x320);
                    if (msg != 0 && func_ov023_021f6f10(msg) == 4) {
                        int indent;
                        char* text;
                        struct TableA68* table;
                        Struct_ov004_02162108_2* label;
                        table = func_ov023_021fa598(msg);
                        text = data_ov004_021707e8.textBuf + (k + off) * 0x80;
                        memset(text, 0, 0x80);
                        indent = 0;
                        if (func_020d2f88(func_02072a68(table, key), data_ov004_02170527)) indent = 0x14;
                        MessageSystem_FormatText(MessageSystem_GetInstance(), 0, func_02072a68(table, key), text, 0x78 - indent, 0, 0);
                        label = func_ov004_0215e47c(self, id);
                        if (label != 0 && func_ov023_021f6f10(label) == 8) label->data = text;
                    }
#endif
                    Struct_ov004_02162108_2* node = func_ov023_021f6880(obj, id);
                    if (node != 0) node->inline_ov004_02162108_45(st);
                }
            }
            next = i + 1;
            found = 1;
            if (++var10 == 2) break;
        }
        if (found) {
            int var30 = 0;
            for (; next < 26; next++) {
                if (page->entries[data_ov004_0216fe90[next] - 1].active) {
                    var30 = 1;
                    break;
                }
            }
            if (!var30) next = 26;
            page->cursor = next;
        }
        if (var11[0] == 0 && var11[1] == 0) var0 = 1;
    } else {
        void* obj2;
        for (int i = 0xd; i < 0xf; i++) func_ov004_0215e49c(self, i, 0x3a);
        for (int i = 0xf; i < 0x1d; i++) func_ov004_0215e49c(self, i, 0x11e);
        obj2 = func_ov011_021849c8(self);
        for (int i = 0; i < 3; i++) {
            Struct_ov004_02162108_2* node = func_ov023_021f6880(obj2, i + 0x65);
            if (node != 0) node->flags |= 8;
        }
        func_ov004_0215e49c(self, 0x31, 0x1e0);
        func_ov004_0215e49c(self, 0x32, 0x1e3);
#if !defined(jpn)
        func_ov004_0215e574(self, 0x31, 0xff, 0, 0);
        func_ov004_0215e574(self, 0x32, 0xff, 0, 0);
#endif
        if (data_ov004_021707e8.field6 == 0) {
            Struct_ov004_02162108_2* node = func_ov004_0215e47c(self, 3);
            if (node != 0) node->flags &= ~4;
        }
    }

    int state = 0xf;
    if (var0) state = 3;
    Struct_ov004_02162108_2* node = func_ov023_021f6880(obj, 0xc);
    if (node != 0 && func_ov023_021f6f10(node) == 8) node->inline_ov004_02162108_45(state);
    for (int var39 = 0; var39 < 4; var39++) {
        Struct_ov004_02162108_2* node = func_ov023_021f6880(obj, var39 + 0x64);
        if (node != 0 && func_ov023_021f6f10(node) == 0x13) node->inline_ov004_02162108_45(state);
    }
    func_ov004_0215f6f4(self, data_ov004_021707e8.fieldB, data_ov004_021707e8.field6, var0);
    return 0;
}
