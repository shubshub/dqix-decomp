#include <globaldefs.h>
#include "NitroSDK/Matrix.h"
#include "GameState/GameState.h"

typedef Vector3i Vec3;

class Struct_ov004_0216ba70 {
public:
    virtual void v00(); virtual void inline_ov004_0216ba70_20(); virtual void inline_ov004_0216ba70_21(); virtual void inline_ov004_0216ba70_22();
    virtual void v04(); virtual void inline_ov004_0216ba70_24(); virtual void inline_ov004_0216ba70_25();
    virtual void inline_ov004_0216ba70_26(Vec3* arg);
    virtual Vec3 inline_ov004_0216ba70_29();
    virtual void inline_ov004_0216ba70_31(); virtual void v10(); virtual void inline_ov004_0216ba70_37();
    virtual void inline_ov004_0216ba70_39(); virtual void inline_ov004_0216ba70_40(); virtual void v14(); virtual void inline_ov004_0216ba70_42();
    virtual void inline_ov004_0216ba70_43(); virtual void inline_ov004_0216ba70_44(); virtual void v18(); virtual void inline_ov004_0216ba70_46();
    virtual void v20(); virtual void inline_ov004_0216ba70_48(); virtual void inline_ov004_0216ba70_49(); virtual void inline_ov004_0216ba70_50();
    virtual void v24(); virtual void inline_ov004_0216ba70_52(); virtual void inline_ov004_0216ba70_53(); virtual void inline_ov004_0216ba70_54();
    virtual void v28(); virtual void inline_ov004_0216ba70_56(); virtual void v30(); virtual void inline_ov004_0216ba70_58();
    virtual void inline_ov004_0216ba70_59(); virtual void inline_ov004_0216ba70_60(); virtual void v34(); virtual void inline_ov004_0216ba70_62();
    virtual void inline_ov004_0216ba70_63(); virtual void inline_ov004_0216ba70_64(); virtual void v38(); virtual void inline_ov004_0216ba70();
    virtual void v40(); virtual void inline_ov004_0216ba70_3(); virtual void inline_ov004_0216ba70_4(); virtual void inline_ov004_0216ba70_5();
    virtual void v44(); virtual void inline_ov004_0216ba70_7(); virtual void inline_ov004_0216ba70_8(); virtual void inline_ov004_0216ba70_9();
    virtual void v48(); virtual void inline_ov004_0216ba70_11(); virtual void v50(); virtual void inline_ov004_0216ba70_13();
    virtual void inline_ov004_0216ba70_14(); virtual void inline_ov004_0216ba70_15();
    virtual void inline_ov004_0216ba70_16(int arg);
    virtual void inline_ov004_0216ba70_17();
    virtual void inline_ov004_0216ba70_18(int arg);
    char pad[0x1c];
    void* field20;
};

struct Struct_ov004_0216ba70_2 {
    char pad0[0x30];
    unsigned char unknown_30_;
    unsigned char unknown_31_;
    unsigned short field32;
};

struct Struct_ov004_0216ba70_3 {
    Struct_ov004_0216ba70_2 records[4];
    int unknown_d0_;
    unsigned char unknown_d4_;
    unsigned char unknown_d5_;
    unsigned char unknown_d6_;
    unsigned char unknown_d7_;
};

struct Struct_ov004_0216ba70_4 {
    char unknown_0_[0x4000];
    Struct_ov004_0216ba70_3 unknown_4000_;
};

struct Struct_ov004_0216ba70_5 {
    char unknown_0_[0x3e80];
    Struct_ov004_0216ba70_4 unknown_3e80_;
};

struct Struct_ov004_02171034 {
    char pad0[6];
    unsigned char unknown_6_;
    unsigned char byte7;
    unsigned short unknown_8_;
    char pad1[2];
    int fieldC;
};

struct Struct0200fb08;
extern "C" unsigned char GameState_GetLanguage(struct Struct0200fb08* obj);
extern "C" int StandardStrings_Get(int value);
struct Struct_ov004_0216b7bc;
extern "C" void func_ov011_02184ad8(struct Struct_ov004_0216b7bc* obj);
extern "C" void* func_ov004_0216ae9c(void* a, int id);

extern "C" void* func_ov011_021849c8(void*);
extern "C" Struct_ov004_0216ba70* func_ov023_021f6880(void* obj, int key);
extern "C" void func_ov023_021f8120(void* obj);
extern "C" void func_ov023_021f7eb8(void* node, void* a, int buf, int mode, int a5, int a6, int a7, int a8, int a9, int arg9);

extern "C" void func_ov004_0216afb0(void* a1, int p2, int p3, int p4,
    int p5, int p6, int p7, int p8, unsigned char p9);
extern "C" void func_ov004_0216b06c(void* obj, int p1, int p2, int p3, int p4, int p5, int p6, int p7, unsigned char p8);
extern "C" void func_ov004_0216b120(void* p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7);
extern "C" int func_ov004_0216aed0(void* a, int b, int c, int d);
extern "C" int func_ov004_0216af24(void* a, short key);

extern Struct_ov004_02171034 data_ov004_02171034;

static inline Struct_ov004_0216ba70_3* inline_ov004_0216ba70_27(GameState* bs) {
    return &((Struct_ov004_0216ba70_5*)bs)->unknown_3e80_.unknown_4000_;
}
struct Struct_ov004_0217017a { short a; short b; };
extern Struct_ov004_0217017a data_ov004_0217017a[];

static inline void inline_ov004_0216ba70_28(Struct_ov004_0216ba70* node, int x) {
    const Vec3& t = node->inline_ov004_0216ba70_29();
    Vec3 pos;
    *(Vector3i*)((int*)&pos) = *(Vector3i const*)((int*)&t);
    pos.x = x;
    node->inline_ov004_0216ba70_26(&pos);
}

static inline void inline_ov004_0216ba70_30(Struct_ov004_0216ba70* node, Vec3 p, int dx) {
    p.x = p.x + dx;
    node->inline_ov004_0216ba70_26(&p);
}

static inline void inline_ov004_0216ba70_32(void* a, Struct_ov004_0216ba70* node2, Vec3 savedPos) {
    inline_ov004_0216ba70_30(node2, savedPos, 0x4000);
    func_ov004_0216afb0(a, 0x5a, 2, 0xd3, 31, 60, 5, 8, 1);
}

static inline Vec3 inline_ov004_0216ba70_34(const Vec3& v) {
    Vec3 r = v;
    return r;
}

static inline Vec3 inline_ov004_0216ba70_35(const Vec3& v) {
    Vec3 r = inline_ov004_0216ba70_34(v);
    return r;
}

static inline Vec3 inline_ov004_0216ba70_36(const Vec3& v) {
    return inline_ov004_0216ba70_35(v);
}

static inline Vec3 inline_ov004_0216ba70_38(Struct_ov004_0216ba70* n) {
    const Vec3& t = n->inline_ov004_0216ba70_29();
    return inline_ov004_0216ba70_36(t);
}

// USA: func_ov004_0216ba70
extern "C" ARM int func_ov004_0216ba70(void* a) {
    int count;
    int i;
    int delta;
    int base;
    Struct_ov004_0216ba70_3* ext;
    GameState* bs2;
    Struct_ov004_0216ba70_3* var6;
    Vec3 v6c;

    ext = &((Struct_ov004_0216ba70_5*)GameState::GetInstance())->unknown_3e80_.unknown_4000_;
    count = ext->unknown_d4_;

    bs2 = GameState::GetInstance();
    var6 = inline_ov004_0216ba70_27(bs2);

    func_ov004_0216afb0(a, 0x37, 2, 0xd3, 6, 0x46, 4, 0xa, 1);

    delta = func_ov004_0216af24(a, 0x37);

    Struct_ov004_0216ba70* node = func_ov023_021f6880(func_ov011_021849c8(a), 0x37);
    if (node) {
        inline_ov004_0216ba70_28(node, ((0xd0 - delta) >> 1) << 12);
    }

    if (var6->unknown_d5_ != 0) {
        Struct_ov004_0216ba70* node2 = func_ov023_021f6880(func_ov011_021849c8(a), 0x37);
        Vec3 savedPos = inline_ov004_0216ba70_38(node2);
        inline_ov004_0216ba70_32(a, node2, savedPos);
        Struct_ov004_0216ba70* node3 = func_ov023_021f6880(func_ov011_021849c8(a), 0x5a);
        if (node3) {
            node3->inline_ov004_0216ba70_16(0xd);
            inline_ov004_0216ba70_30(node3, savedPos, -0x5000);
        }
    }

    func_ov004_0216b120(a, 0x28, 2, 0xd3, 2, 0x10, 0xcb, 1);

    {
    int flag = 0;
    if (GameState_GetLanguage((struct Struct0200fb08*)bs2) == 4 ||
        GameState_GetLanguage((struct Struct0200fb08*)bs2) == 2) {
        flag = 2;
    }
    base = 0;

    func_ov004_0216afb0(a, 0x38, 2, 0xd3, 0x3e7, 7, base + 0x13, 0xa, 1);
    func_ov004_0216afb0(a, 0x39, 2, 0xd3, 0x3e7, 0x57, base + 0x13, 0xa, 1);
    func_ov004_0216afb0(a, 0x3a, 2, 0xd3, 0x15, 0xa8 - flag, base + 0x13, 0xa, 1);

    Struct_ov004_0216ba70* node4 = func_ov023_021f6880(func_ov011_021849c8(a), 0x3a);
    if (node4) {
        node4->field20 = (void*)StandardStrings_Get(0x3f3);
    }

    func_ov004_0216afb0(a, 0x47, 2, 0xd3, 0x3e7, 0xa1, base + 0x13, 8, 1);
    func_ov004_0216b06c(a, 0x96, 2, 0xd3, 0xbe, base + 0x13, 8, 2, 0);

    base += 0xc;
    if (count > 1) {
        switch (count) {
        case 2: base += 2; break;
        case 3: base += 1; break;
        }

        int var14 = 0x3f3 - 0xc;
        for (i = 1; i < count; i++) {
            int var15 = i + i * 2;
            func_ov004_0216afb0(a, var15 + 0x38, 2, 0xd3, var14, 7, base + 0x13, 0xa, 1);
            func_ov004_0216afb0(a, var15 + 0x39, 2, 0xd3, var14, 0x57, base + 0x13, 0xa, 1);
            func_ov004_0216afb0(a, var15 + 0x3a, 2, 0xd3, 0x15, 0xa8 - flag, base + 0x13, 0xa, 1);

            Struct_ov004_0216ba70* node5 = func_ov023_021f6880(func_ov011_021849c8(a), var15 + 0x3a);
            if (node5) {
                node5->field20 = (void*)StandardStrings_Get(0x3f3);
            }

            func_ov004_0216afb0(a, i + 0x47, 2, 0xd3, var14, 0xa1, base + 0x13, 8, 1);
            func_ov004_0216b06c(a, i + 0x96, 2, 0xd3, 0xbe, base + 0x13, 8, 2, 0);

            base += 0xc;
        }
        if (count == 4) base -= 1;
    }

    func_ov004_0216b120(a, 0x29, 2, 0xd3, 2, base + 0x14, 0xcb, 1);
    func_ov004_0216afb0(a, 0x44, 2, 0xd3, 0x13, 7, base + 0x17, 0xa, 1);

    if (data_ov004_02171034.unknown_8_ != 0) {
        func_ov004_0216b06c(a, 0x9a, 2, 0xd3, 0x92, base + 0x18, 8, 4, 0);
        func_ov004_0216afb0(a, 0x4f, 2, 0xd3, 0x34, 0x98, base + 0x18, 0xa, 1);
    }
    func_ov004_0216b06c(a, 0x9b, 2, 0xd3, 0xa8, base + 0x18, 8, 2, 1);
    func_ov004_0216afb0(a, 0x50, 2, 0xd3, 0x34, 0xad, base + 0x18, 0xa, 1);
    func_ov004_0216b06c(a, 0x9c, 2, 0xd3, 0xbd, base + 0x18, 8, 2, 1);
    func_ov004_0216afb0(a, 0x45, 2, 0xd3, 0x14, 7, base + 0x22, 0xa, 1);
    func_ov004_0216afb0(a, 0x46, 2, 0xd3, 0x3e7, 0xbd, base + 0x22, 0xa, 1);
    }

    for (int j = 0; j < count; j++) {
        void* list = func_ov011_021849c8(a);
        Struct_ov004_0216ba70* var19 = func_ov023_021f6880(list, j * 3 + 0x38);
        if (var19) {
            var19->field20 = &ext->records[j];
        }

        int var20 = ext->records[j].unknown_30_;
        if (var20 >= 0 && var20 < 0xd) {
            int sl = 0x3e7;
            if (var20 != 0) sl = (short)(var20 + 6);
            unsigned char var22 = inline_ov004_0216ba70_27(GameState::GetInstance())->unknown_d6_;
            if (var22 == 1) sl = 0x46;
            func_ov004_0216aed0(a, j * 3 + 0x39, sl, 0);
        }

        int var23 = ext->records[j].unknown_31_;
        if (var23 >= 0 && var23 <= 0xa) {
            int lv = 0x3e7;
            if (var23 != 0) lv = (short)(var23 + 0x15);
            func_ov004_0216aed0(a, j + 0x47, lv, 0);
        }

        int var25 = (unsigned int)j * 3 + 0x39;
        int var26 = func_ov004_0216af24(a, var25);
        Struct_ov004_0216ba70* node2 = func_ov023_021f6880(func_ov011_021849c8(a), var25);
        if (node2) {
            const Vec3& var28 = node2->inline_ov004_0216ba70_29();
            *(Vector3i*)((int*)&v6c) = *(Vector3i const*)((int*)&var28);
            v6c.x = v6c.x + ((var26 + 2) << 12);

            Struct_ov004_0216ba70* node3 = func_ov023_021f6880(func_ov011_021849c8(a), j + 0x47);
            if (node3) {
                node3->inline_ov004_0216ba70_26(&v6c);
                unsigned char var30 = ext->records[j].unknown_31_;
                if (var30 == 0xa) {
                    node3->inline_ov004_0216ba70_16(0xd);
                } else if (var30 != 0) {
                    node3->inline_ov004_0216ba70_16(5);
                }
            }
        }

        unsigned short fieldVal = ext->records[j].field32;
        Struct_ov004_0216ba70* var32 = func_ov023_021f6880(func_ov011_021849c8(a), j + 0x96);
        if (var32) {
            var32->inline_ov004_0216ba70_18(fieldVal);
        }
    }

    int val = ext->unknown_d0_;
    int var34 = 0;
    if (val >= 1100 && val < 1200) var34 = 1;
    else if (val >= 100 && val < 200) var34 = 2;
    else if (val >= 1200 && val < 1300) var34 = 3;
    else if (val >= 1300 && val < 1400) var34 = 4;
    else if (val >= 4200 && val < 4300) var34 = 5;
    else if (val >= 1500 && val < 1600) var34 = 6;
    else if (val >= 5800 && val < 5900) var34 = 7;
    else if (val >= 1800 && val < 1900) var34 = 8;
    else if (val >= 1900 && val < 2000) var34 = 9;
    else if (val >= 200 && val < 300) var34 = 0xa;
    else if (val >= 2100 && val < 2200) var34 = 0xb;
    else if (val >= 2000 && val < 2100) var34 = 0xc;
    else if (val >= 2200 && val < 2300) var34 = 0xd;
    else if (val >= 2300 && val < 2400) var34 = 0xe;
    else if (val >= 5700 && val < 5800) var34 = 0xf;
    else if (val >= 400 && val < 500) var34 = 0x10;

    int msgId = -1;
    switch (var34) {
    case 0: msgId = 0x24; break;
    case 1: msgId = 0x25; break;
    case 2: msgId = 0x26; break;
    case 3: msgId = 0x27; break;
    case 4: msgId = 0x28; break;
    case 5: msgId = 0x29; break;
    case 6: msgId = 0x2a; break;
    case 7: msgId = 0x2b; break;
    case 8: msgId = 0x2c; break;
    case 9: msgId = 0x2d; break;
    case 0xa: msgId = 0x2e; break;
    case 0xb: msgId = 0x2f; break;
    case 0xc: msgId = 0x30; break;
    case 0xd: msgId = 0x31; break;
    case 0xe: msgId = 0x32; break;
    case 0xf: msgId = 0x33; break;
    case 0x10: msgId = 0x47; break;
    }

    if (inline_ov004_0216ba70_27(GameState::GetInstance())->unknown_d7_ != 0) {
        msgId = 0x2bc;
    }
    if (msgId >= 0) {
        func_ov004_0216aed0(a, 0x46, msgId, 1);
    }

    unsigned char var36;
    unsigned char var37;
    unsigned short w8;
    w8 = data_ov004_02171034.unknown_8_;
    var36 = data_ov004_02171034.unknown_6_;
    var37 = data_ov004_02171034.byte7;
    if (w8 != 0) {
        Struct_ov004_0216ba70* var39 = func_ov023_021f6880(func_ov011_021849c8(a), 0x9a);
        if (var39) var39->inline_ov004_0216ba70_18(w8);
    }
    Struct_ov004_0216ba70* nb = func_ov023_021f6880(func_ov011_021849c8(a), 0x9b);
    if (nb) nb->inline_ov004_0216ba70_18(var37);
    Struct_ov004_0216ba70* var41 = func_ov023_021f6880(func_ov011_021849c8(a), 0x9c);
    if (var41) var41->inline_ov004_0216ba70_18(var36);

    void* node5 = func_ov004_0216ae9c(a, 0xd3);
    func_ov023_021f8120(node5);

    int fieldC = data_ov004_02171034.fieldC;
    if (count >= 1 && count <= 4) {
        Struct_ov004_0217017a* e = &data_ov004_0217017a[count - 1];
        func_ov023_021f7eb8(node5, a, fieldC, 6, e->a, 0x1a, e->b, 0, 1, 0);
    }

    func_ov011_02184ad8((struct Struct_ov004_0216b7bc*)a);
    return 0;
}
