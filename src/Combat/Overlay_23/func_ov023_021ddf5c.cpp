#include <globaldefs.h>

struct Container020e0310;
struct Struct_ov023_021db45c;
struct Struct_ov023_021dbb34;
struct Struct_ov023_021dbc58_2;
struct Struct_ov023_021e257c;

extern "C" void WindowPane_Init(void* buf);
extern "C" int func_ov023_021ddc34(void* obj, short a, short b, short c, short d);
extern "C" void func_ov023_021db45c(void* obj, struct Struct_ov023_021db45c* p1, int p2, short* p3, short* p4);
extern "C" void* func_ov023_021db4e4(void* obj, int key);
extern "C" void __clear(void* buf, int len);
extern "C" void func_ov023_021dbb34(void* handle, struct Struct_ov023_021dbb34* out);
extern "C" void func_ov023_021dbc58(void*, Struct_ov023_021dbc58_2*, int);
extern "C" int KeyTable_Get(struct Container020e0310* c, int key);
extern "C" void func_ov023_021e23d0(void* obj, int val, int f0xc, unsigned char arg3, unsigned char arg4);
extern "C" void func_ov023_021e2bdc(void* a, int unused, short* out1, short* out2);
extern "C" void func_0204f41c(void* buf, short x, short y, int text, int d, int e, short* f, short* g, int h);
#if defined(jpn)
extern "C" void func_02050678(void*,short,short,int,int,int,short*,short*);
#endif
extern "C" void func_ov023_021db3c0(void* buf, int x, short y, float v, unsigned char color);
extern "C" void func_ov023_021e24b0(void* obj, int val, int f0xc, unsigned char arg3, unsigned char p5, unsigned char p6, unsigned char p7, unsigned char p8, unsigned char p9);
extern "C" void func_ov023_021e257c(void* obj);
extern "C" void* func_ov023_021db544(void* a, void* b, int c, int d);
extern "C" int func_020dd718(int combatantId, int value);
extern "C" int func_020dd4c4(int id, void* node);
extern "C" int func_ov023_021ddc98(void* buf, int val, unsigned short len, int flag);
extern "C" long labs(long);

#if defined(jpn)
struct Struct_ov023_021ff9e0_11 {
    struct Container020e0310* field14;
    int field0;
    int field8;
    int fieldc;
    int field10;
    int field4;
};
#else
struct Struct_ov023_021ff9e0_11 {
    int field0;
    int field4;
    int field8;
    int fieldc;
    int field10;
    struct Container020e0310* field14;
};
#endif

extern struct Struct_ov023_021ff9e0_11 data_ov023_021ff9e0;

extern const short data_ov023_021fd5be[];
extern const short data_ov023_021fd5c6[];
extern const short data_ov023_021fd5ce[];
extern const short data_ov023_021fd5d6[];
extern const short data_ov023_021fd5de[];
extern const short data_ov023_021fd5e6[];
extern const short data_ov023_021fd5ee[];
extern const short data_ov023_021fd5f6[];
extern const short data_ov023_021fd5fe[];
extern const short data_ov023_021fd606[];
extern const short data_ov023_021fd60e[];
extern const short data_ov023_021fd616[];
extern const short data_ov023_021fd61e[];

struct Struct_ov023_021ddf5c {
    int unk0;
    int unk4;
    int unknown_8_0_ : 10;
    int unknown_9_2_ : 10;
    unsigned int unknown_a_4_ : 10;
    unsigned int unknown_c_0_ : 10;
    unsigned int unknown_d_2_ : 10;
    unsigned int unknown_e_4_ : 12;
    int unknown_10_0_ : 10;
    int unknown_11_2_ : 10;
    int unknown_12_4_ : 10;
    int unknown_14_0_ : 10;
    int unknown_15_2_ : 10;
    int unknown_16_4_ : 10;
};

struct Struct_ov023_021ddf5c_2 {
    struct Struct_ov023_021ddf5c* packed;
    int unk4;
    unsigned int unknown_8_0_ : 4;
    char unknown_9_[0x18 - 0xc];
    short field18;
};

struct Struct_ov023_021ddf5c_3 {
    char pad[0x16];
    unsigned char flags;
};

struct Struct_ov023_021ddf5c_4 {
    char pad0[0x4c];
    struct Struct_ov023_021ddf5c_2* node;
    char unknown_50_[0xcc - 0x50];
    char list[4];
    void* buf;
    char unknown_d4_[0xde - 0xd4];
    short active;
#if defined(jpn)
    char unknown_e0_[0x6d8 - 0xe0];
#else
    char unknown1_e0_[0x75c - 0xe0];
#endif

    int pos;
    char unknown_760_[0x768 - 0x760];
    int unknown_768_;
    int unknown_76c_;
    char unknown_770_[0x77a - 0x770];
    signed char id;
};

#define SetEntryOn(obj, key) do {     struct Struct_ov023_021ddf5c_3* e_ = (struct Struct_ov023_021ddf5c_3*)func_ov023_021db4e4((obj)->list, (key));     if (e_) e_->flags |= 1; } while (0)

#define SetEntryOff(obj, key) do {     struct Struct_ov023_021ddf5c_3* e_ = (struct Struct_ov023_021ddf5c_3*)func_ov023_021db4e4((obj)->list, (key));     if (e_) e_->flags &= ~1; } while (0)

#define FlushList(obj, buf) do {     if (data_ov023_021ff9e0.field4) {         (obj)->buf = (buf);         (obj)->active = 1;         func_ov023_021e257c((obj)->list);     } } while (0)

// USA: func_ov023_021ddf5c
extern "C" ARM void func_ov023_021ddf5c(struct Struct_ov023_021ddf5c_4* obj) {
    char buf[0xe0];
    unsigned char i;
    WindowPane_Init(buf);
    if (!func_ov023_021ddc34(buf, 0, 0, 0x14, 9)) return;

    if (obj->id < 0) {
        short k0;
        int key;
        float v;
        short k;
        short k3;
        int var7;
        unsigned char n;
        struct Struct_ov023_021ddf5c_2* node = obj->node;
        short p1, p0;
        short o1, o0;
        short a1, a0;
        func_ov023_021db45c(obj->list, (struct Struct_ov023_021db45c*)buf, 0xb, &a0, &a1);
        SetEntryOn(obj, 0xb);
        SetEntryOn(obj, 0x2d);
        SetEntryOff(obj, 0x2e);
        SetEntryOff(obj, 0x2c);
        float var16[6];
        float var17[12];
        unsigned char idx[6];
        __clear(var17, 0x30);
        __clear(idx, 6);
        func_ov023_021dbb34(node, (struct Struct_ov023_021dbb34*)var17);
        n = 0;
        __clear(var16, 0x18);
        for (i = 0; i < 12; i++) {
            if (var17[i] != 0.0f) {
                var16[n] = var17[i];
                idx[n] = i;
                n++;
                if (n >= 4) break;
            }
        }
        for (i = 0; i < 4; i++) {
            k0 = data_ov023_021fd5be[i];
            if (i < n) {
                SetEntryOn(obj, k0);
                SetEntryOn(obj, data_ov023_021fd5c6[i]);
                SetEntryOff(obj, data_ov023_021fd5ce[i]);
            } else {
                SetEntryOff(obj, k0);
                SetEntryOff(obj, data_ov023_021fd5c6[i]);
                SetEntryOff(obj, data_ov023_021fd5ce[i]);
            }
        }
        for (i = 0; i < n; i++) {
            v = var16[i];
            key = (short)(idx[i] + 12);
            func_ov023_021e23d0(obj->list, data_ov023_021fd5c6[i], KeyTable_Get(data_ov023_021ff9e0.field14, key), 10, 0xf);
            k = data_ov023_021fd5d6[i];
            func_ov023_021e2bdc(obj->list, k, &p0, &p1);
            switch (key) {
            case 14:
            case 15:
            case 16:
            case 17:
                if (data_ov023_021ff9e0.field4) {
#if defined(jpn)
                    func_02050678(buf, p0 + 16, p1, KeyTable_Get(data_ov023_021ff9e0.field14, 0x1a), 8, 0xf, &o0, &o1);
#else
#if defined(jpn)
                    func_02050678(buf, p0 + 16, p1, KeyTable_Get(data_ov023_021ff9e0.field14, 0x1a), 8, 0xf, &o0, &o1);
#else
#if defined(jpn)
                    func_02050678(buf, p0 + 16, p1, KeyTable_Get(data_ov023_021ff9e0.field14, 0x1a), 8, 0xf, &o0, &o1);
#else
                    func_0204f41c(buf, p0 + 1, p1, KeyTable_Get(data_ov023_021ff9e0.field14, 0x1a), 8, 0xf, &o0, &o1, 0);
#endif

#endif

#endif

#if defined(jpn)
                    func_ov023_021db3c0(buf, (short)(p0 + 8), p1, v, 0xf);
#else
#if defined(jpn)
                    func_ov023_021db3c0(buf, (short)(p0 + 8), p1, v, 0xf);
#else
#if defined(jpn)
                    func_ov023_021db3c0(buf, (short)(p0 + 8), p1, v, 0xf);
#else
                    func_ov023_021db3c0(buf, p0, p1, v, 0xf);
#endif

#endif

#endif

                }
                SetEntryOff(obj, k);
                break;
            default:
                if (v < 0.0f) {
                    k3 = data_ov023_021fd5ce[i];
                    SetEntryOn(obj, k3);
                    func_ov023_021e23d0(obj->list, k3, KeyTable_Get(data_ov023_021ff9e0.field14, 0x19), 8, 0xf);
                }
                var7 = labs((int)v);
                func_ov023_021e24b0(obj->list, data_ov023_021fd5d6[i], var7, 8, 0xf, 1, 3, 0, 0);
                SetEntryOn(obj, data_ov023_021fd5d6[i]);
                break;
            }
        }
        FlushList(obj, buf);
        func_ov023_021db544(obj->list, (void*)0xb, a0, a1);
        SetEntryOff(obj, 0xb);
    } else if (func_020dd718(obj->id, obj->node->field18)) {
        short k0;
        int key;
        float v;
        short k;
        int var23;
        short k3;
        unsigned char n;
        int id = obj->id;
        struct Struct_ov023_021ddf5c_2* node = obj->node;
        short p1, p0;
        short o1, o0;
        short b1, b0;
        func_ov023_021db45c(obj->list, (struct Struct_ov023_021db45c*)buf, 0xb, &b0, &b1);
        SetEntryOn(obj, 0xb);
        SetEntryOn(obj, 0x2d);
        SetEntryOff(obj, 0x2e);
        SetEntryOff(obj, 0x2c);
        float var34[6];
        float var35[12];
        float model[12];
        unsigned char idx[6];
        __clear(model, 0x30);
        __clear(var35, 0x30);
        __clear(idx, 6);
        func_ov023_021dbc58((void*)id, (Struct_ov023_021dbc58_2*)model, (int)0);
        func_ov023_021dbb34(node, (struct Struct_ov023_021dbb34*)var35);
        n = 0;
        __clear(var34, 0x18);
        for (i = 0; i < 12; i++) {
            int force = 0;
            if (i == 3 && node->unknown_8_0_ == 1) {
                if (model[3]) force = 1;
            }
            if (force || var35[i] != 0.0f) {
                var34[n] = model[i];
                idx[n] = i;
                n++;
                if (n >= 4) break;
            }
        }
        for (i = 0; i < 4; i++) {
            k0 = data_ov023_021fd5de[i];
            if (i < n) {
                SetEntryOn(obj, k0);
                SetEntryOn(obj, data_ov023_021fd5e6[i]);
                SetEntryOn(obj, data_ov023_021fd5ee[i]);
            } else {
                SetEntryOff(obj, k0);
                SetEntryOff(obj, data_ov023_021fd5e6[i]);
                SetEntryOff(obj, data_ov023_021fd5ee[i]);
            }
        }
        for (i = 0; i < n; i++) {
            v = var34[i];
            key = (short)(idx[i] + 12);
            func_ov023_021e23d0(obj->list, data_ov023_021fd5e6[i], KeyTable_Get(data_ov023_021ff9e0.field14, key), 10, 0xf);
            k = data_ov023_021fd5f6[i];
            func_ov023_021e2bdc(obj->list, k, &p0, &p1);
            switch (key) {
            case 14:
            case 15:
            case 16:
            case 17:
                if (data_ov023_021ff9e0.field4) {
#if defined(jpn)
                    func_02050678(buf, p0 + 16, p1, KeyTable_Get(data_ov023_021ff9e0.field14, 0x1a), 8, 0xf, &o0, &o1);
#else
#if defined(jpn)
                    func_02050678(buf, p0 + 16, p1, KeyTable_Get(data_ov023_021ff9e0.field14, 0x1a), 8, 0xf, &o0, &o1);
#else
#if defined(jpn)
                    func_02050678(buf, p0 + 16, p1, KeyTable_Get(data_ov023_021ff9e0.field14, 0x1a), 8, 0xf, &o0, &o1);
#else
                    func_0204f41c(buf, p0 + 1, p1, KeyTable_Get(data_ov023_021ff9e0.field14, 0x1a), 8, 0xf, &o0, &o1, 0);
#endif

#endif

#endif

#if defined(jpn)
                    func_ov023_021db3c0(buf, (short)(p0 + 8), p1, v, 0xf);
#else
#if defined(jpn)
                    func_ov023_021db3c0(buf, (short)(p0 + 8), p1, v, 0xf);
#else
#if defined(jpn)
                    func_ov023_021db3c0(buf, (short)(p0 + 8), p1, v, 0xf);
#else
                    func_ov023_021db3c0(buf, p0, p1, v, 0xf);
#endif

#endif

#endif

                }
                SetEntryOff(obj, k);
                break;
            default:
                var23 = labs((int)v);
                func_ov023_021e24b0(obj->list, data_ov023_021fd5f6[i], var23, 8, 0xf, 1, 3, 0, 0);
                SetEntryOn(obj, data_ov023_021fd5f6[i]);
                break;
            }
            k3 = data_ov023_021fd5ee[i];
            SetEntryOn(obj, k3);
            func_ov023_021e23d0(obj->list, k3, KeyTable_Get(data_ov023_021ff9e0.field14, 0x22), 8, 0xf);
        }
        FlushList(obj, buf);
        func_ov023_021db544(obj->list, (void*)0xb, b0, b1);
        SetEntryOff(obj, 0xb);
    } else if (!func_020dd4c4(obj->id, obj->node)) {
        short k0;
        unsigned char j;
        short key;
        short k;
        float v;
        float w;
        unsigned char color;
        short var46;
        int var47;
        unsigned char n;
        struct Struct_ov023_021ddf5c_2* node = obj->node;
        int id = obj->id;
        short p1, p0;
        short o1, o0;
        short c1, c0;
        func_ov023_021db45c(obj->list, (struct Struct_ov023_021db45c*)buf, 0xb, &c0, &c1);
        SetEntryOn(obj, 0xb);
        SetEntryOff(obj, 0x2d);
        SetEntryOn(obj, 0x2e);
        SetEntryOff(obj, 0x2c);
        unsigned char changed[12];
        float next[12];
        float cur[12];
        __clear(cur, 0x30);
        func_ov023_021dbc58((void*)id, (Struct_ov023_021dbc58_2*)cur, (int)0);
        __clear(next, 0x30);
        func_ov023_021dbc58((void*)id, (Struct_ov023_021dbc58_2*)next, (int)node);
        struct Struct_ov023_021ddf5c* pk = 0;
        __clear(changed, 0xc);
        if (node && node->field18 > 0) pk = node->packed;
        if (pk) {
            if (pk->unknown_8_0_) changed[0] = 1;
            if (pk->unknown_9_2_) changed[1] = 1;
            if ((float)pk->unknown_a_4_ / 10.0f != 0.0f) changed[2] = 1;
            if ((float)pk->unknown_c_0_ / 10.0f != 0.0f) changed[3] = 1;
            if ((float)pk->unknown_d_2_ / 10.0f != 0.0f) changed[4] = 1;
            if (pk->unknown_10_0_) changed[6] = 1;
            if (pk->unknown_11_2_) changed[7] = 1;
            if (pk->unknown_12_4_) changed[8] = 1;
            if (pk->unknown_14_0_) changed[9] = 1;
            if (pk->unknown_15_2_) changed[10] = 1;
            if (pk->unknown_16_4_) changed[11] = 1;
            if (node->unknown_8_0_ == 1) {
                if (cur[3] || next[3]) changed[3] = 1;
            }
        }
        unsigned char idx[6];
        __clear(idx, 6);
        n = 0;
        for (i = 0; i < 12; i++) {
            if (changed[i] || cur[i] - next[i] != 0.0f) {
                idx[n] = i;
                n++;
                if (n >= 4) break;
            }
        }
        for (j = 0; j < 4; j++) {
            k0 = data_ov023_021fd5fe[j];
            if (j < n) {
                SetEntryOn(obj, k0);
                SetEntryOn(obj, data_ov023_021fd606[j]);
            } else {
                SetEntryOff(obj, k0);
                SetEntryOff(obj, data_ov023_021fd606[j]);
            }
        }
        for (i = 0; i < n; i++) {
            j = idx[i];
            key = j + 12;
            func_ov023_021e23d0(obj->list, data_ov023_021fd606[i], KeyTable_Get(data_ov023_021ff9e0.field14, key), 10, 0xf);
            k = data_ov023_021fd60e[i];
            func_ov023_021e2bdc(obj->list, k, &p0, &p1);
            v = cur[j];
            switch (key) {
            case 14:
            case 15:
            case 16:
            case 17:
                if (data_ov023_021ff9e0.field4) {
#if defined(jpn)
                    func_02050678(buf, p0 + 16, p1, KeyTable_Get(data_ov023_021ff9e0.field14, 0x1a), 8, 0xf, &o0, &o1);
#else
#if defined(jpn)
                    func_02050678(buf, p0 + 16, p1, KeyTable_Get(data_ov023_021ff9e0.field14, 0x1a), 8, 0xf, &o0, &o1);
#else
#if defined(jpn)
                    func_02050678(buf, p0 + 16, p1, KeyTable_Get(data_ov023_021ff9e0.field14, 0x1a), 8, 0xf, &o0, &o1);
#else
                    func_0204f41c(buf, p0 + 1, p1, KeyTable_Get(data_ov023_021ff9e0.field14, 0x1a), 8, 0xf, &o0, &o1, 0);
#endif

#endif

#endif

#if defined(jpn)
                    func_ov023_021db3c0(buf, (short)(p0 + 8), p1, v, 0xf);
#else
#if defined(jpn)
                    func_ov023_021db3c0(buf, (short)(p0 + 8), p1, v, 0xf);
#else
#if defined(jpn)
                    func_ov023_021db3c0(buf, (short)(p0 + 8), p1, v, 0xf);
#else
                    func_ov023_021db3c0(buf, p0, p1, v, 0xf);
#endif

#endif

#endif

                }
                SetEntryOff(obj, k);
                break;
            default:
                var47 = labs((int)v);
                func_ov023_021e24b0(obj->list, data_ov023_021fd60e[i], var47, 8, 0xf, 1, 3, 0, 0);
                SetEntryOn(obj, data_ov023_021fd60e[i]);
                break;
            }
            func_ov023_021e23d0(obj->list, data_ov023_021fd616[i], KeyTable_Get(data_ov023_021ff9e0.field14, 0x20), 8, 0xf);
            w = next[j];
            color = 9;
            if (v == w) color = 0xf;
            else if (v < w) color = 5;
            var46 = data_ov023_021fd61e[i];
            func_ov023_021e2bdc(obj->list, var46, &p0, &p1);
            switch (key) {
            case 14:
            case 15:
            case 16:
            case 17:
                if (data_ov023_021ff9e0.field4) {
#if defined(jpn)
                    func_02050678(buf, p0 + 16, p1, KeyTable_Get(data_ov023_021ff9e0.field14, 0x1a), 8, color, &o0, &o1);
#else
                    func_0204f41c(buf, p0 + 1, p1, KeyTable_Get(data_ov023_021ff9e0.field14, 0x1a), 8, color, &o0, &o1, 0);
#endif

#if defined(jpn)
                    func_ov023_021db3c0(buf, (short)(p0 + 8), p1, w, color);
#else
                    func_ov023_021db3c0(buf, p0, p1, w, color);
#endif

                }
                SetEntryOff(obj, var46);
                break;
            default:
                var47 = labs((int)w);
                func_ov023_021e24b0(obj->list, data_ov023_021fd61e[i], var47, 8, color, 1, 3, 0, 0);
                SetEntryOn(obj, data_ov023_021fd61e[i]);
                break;
            }
        }
        FlushList(obj, buf);
        func_ov023_021db544(obj->list, (void*)0xb, c0, c1);
        SetEntryOff(obj, 0xb);
    } else {
        short var62, var63;
        func_ov023_021db45c(obj->list, (struct Struct_ov023_021db45c*)buf, 0xb, &var63, &var62);
        SetEntryOn(obj, 0xb);
        SetEntryOn(obj, 0x2c);
#if defined(jpn)

#else
        {
            struct Struct_ov023_021ddf5c_3* e = (struct Struct_ov023_021ddf5c_3*)func_ov023_021db4e4(obj->list, 0x2c);
            if (e) e->flags |= 8;
        }

#endif
        func_ov023_021e23d0(obj->list, 0x2c, KeyTable_Get(data_ov023_021ff9e0.field14, 0x21), 10, 0xf);
        SetEntryOff(obj, 0xa);
        SetEntryOff(obj, 0xc);
        SetEntryOff(obj, 0xd);
        SetEntryOff(obj, 0xe);
        SetEntryOff(obj, 0x2d);
        SetEntryOff(obj, 0x2e);
        FlushList(obj, buf);
        func_ov023_021db544(obj->list, (void*)0xb, var63, var62);
        SetEntryOff(obj, 0xb);
    }

    if (obj->unknown_768_) {
        func_ov023_021ddc98(buf, obj->unknown_768_, (unsigned short)data_ov023_021ff9e0.fieldc, 0);
    } else {
        int len = func_ov023_021ddc98(buf, obj->pos, (unsigned short)data_ov023_021ff9e0.fieldc, 0);
        obj->unknown_768_ = obj->pos;
        obj->unknown_76c_ = len;
        obj->pos = obj->pos + len;
    }
}
