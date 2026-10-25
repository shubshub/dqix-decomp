#include <globaldefs.h>

struct Struct_0201099c_3;
struct Struct_ov023_021db45c;
struct Struct_ov023_021dbb34;
struct Struct_ov023_021dbc58_2;
struct Struct_ov023_021e257c;

extern "C" void WindowPane_Init(void* buf);
int InitBufferFromDataField4_021ddc34(void* obj, short a, short b, short c, short d);
void UpdateEntryAndReset_021db45c(void* obj, struct StructAcAe021db45c* p1, int p2, short* p3, short* p4);
extern "C" void* func_ov023_021db4e4(void* obj, int key);
extern "C" void __clear(void* buf, int len);
void DecodePacked021dbb34(void* handle, struct Unpacked021dbb34* out);
void ConvertModelDataToFloats_021dbc58(void*, FloatModelOut_021dbc58*, int);
int KeyTable_Get(struct Container020e0310* c, int key);
void SetEntryFields_021e23d0(void* obj, int val, int f0xc, unsigned char lowNib, unsigned char highNib);
void ComputeShortPair_021e2bdc(void* a, int unused, short* out1, short* out2);
extern "C" void func_0204f41c(void* buf, short x, short y, int text, int d, int e, short* f, short* g, int h);
#if defined(jpn)
extern "C" void func_02050678(void*,short,short,int,int,int,short*,short*);
#endif
extern "C" void func_ov023_021db3c0(void* arg0, int arg1, short arg2, float arg3, unsigned char arg4);
extern "C" void func_ov023_021e24b0(void* arg0, int arg1, int arg2, unsigned char arg3, unsigned char arg4, unsigned char arg5, unsigned char arg6, unsigned char arg7, unsigned char arg8);
extern "C" void func_ov023_021e257c(void* arg0);
extern "C" void* func_ov023_021db544(void* arg0, void* arg1, int arg2, int arg3);
extern "C" int func_020dd718(int arg0, int arg1);
extern "C" int func_020dd4c4(int arg0, void* arg1);
extern "C" int func_ov023_021ddc98(void* arg0, int arg1, unsigned short arg2, int arg3);
extern "C" long labs(long);

#if defined(jpn)
struct Struct_ov023_021ff9e0_11 {
    struct Struct_0201099c_3* unknown_14_;
    int unknown_4_;
    int unknown_8_;
    int unknown_c_;
    int unknown_10_;
    int unknown1_4_;
};
#else
struct Struct_ov023_021ff9e0_11 {
    int unknown_0_;
    int unknown1_4_;
    int unknown_8_;
    int unknown_c_;
    int unknown_10_;
    struct Struct_0201099c_3* unknown_14_;
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
    int unknown_0_;
    int unknown_4_;
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
    struct Struct_ov023_021ddf5c* unknown_0_;
    int unknown_4_;
    unsigned int unknown_8_0_ : 4;
    char unknown_9_[0x18 - 0xc];
    short unknown_16_;
};

struct Struct_ov023_021ddf5c_3 {
    char unknown_0_[0x16];
    unsigned char unknown_16_;
};

struct Struct_ov023_021ddf5c_4 {
    char unknown_0_[0x4c];
    struct Struct_ov023_021ddf5c_2* unknown_4c_;
    char unknown_50_[0xcc - 0x50];
    char unknown_cc_[4];
    void* unknown_d0_;
    char unknown_d4_[0xde - 0xd4];
    short unknown_de_;
#if defined(jpn)
    char unknown_e0_[0x6d8 - 0xe0];
#else
    char unknown1_e0_[0x75c - 0xe0];
#endif

    int unknown_75c_;
    char unknown_760_[0x768 - 0x760];
    int unknown_768_;
    int unknown_76c_;
    char unknown_770_[0x77a - 0x770];
    signed char unknown_77a_;
};

#define SetEntryOn(obj, key) do {     struct Struct_ov023_021ddf5c_3* e_ = (struct Struct_ov023_021ddf5c_3*)func_ov023_021db4e4((obj)->unknown_cc_, (key));     if (e_) e_->unknown_16_ |= 1; } while (0)

#define SetEntryOff(obj, key) do {     struct Struct_ov023_021ddf5c_3* e_ = (struct Struct_ov023_021ddf5c_3*)func_ov023_021db4e4((obj)->unknown_cc_, (key));     if (e_) e_->unknown_16_ &= ~1; } while (0)

#define FlushList(obj, buf) do {     if (data_ov023_021ff9e0.unknown1_4_) {         (obj)->unknown_d0_ = (buf);         (obj)->unknown_de_ = 1;         func_ov023_021e257c((obj)->unknown_cc_);     } } while (0)

// USA: func_ov023_021ddf5c
extern "C" ARM void func_ov023_021ddf5c(struct Obj021ddf5c* obj) {
    char buf[0xe0];
    unsigned char i;
    WindowPane_Init(buf);
    if (!InitBufferFromDataField4_021ddc34(buf, 0, 0, 0x14, 9)) return;

    if (arg0->unknown_77a_ < 0) {
        short var2;
        int var3;
        float var4;
        short var5;
        short var6;
        int var7;
        unsigned char var8;
        struct Struct_ov023_021ddf5c_2* var9 = arg0->unknown_4c_;
        short var10, var11;
        short var12, var13;
        short var14, var15;
        func_ov023_021db45c(arg0->unknown_cc_, (struct Struct_ov023_021db45c*)var0, 0xb, &var15, &var14);
        SetEntryOn(arg0, 0xb);
        SetEntryOn(arg0, 0x2d);
        SetEntryOff(arg0, 0x2e);
        SetEntryOff(arg0, 0x2c);
        float var16[6];
        float var17[12];
        unsigned char var18[6];
        __clear(var17, 0x30);
        __clear(var18, 6);
        func_ov023_021dbb34(var9, (struct Struct_ov023_021dbb34*)var17);
        var8 = 0;
        __clear(var16, 0x18);
        for (var1 = 0; var1 < 12; var1++) {
            if (var17[var1] != 0.0f) {
                var16[var8] = var17[var1];
                var18[var8] = var1;
                var8++;
                if (var8 >= 4) break;
            }
        }
        for (var1 = 0; var1 < 4; var1++) {
            var2 = data_ov023_021fd5be[var1];
            if (var1 < var8) {
                SetEntryOn(arg0, var2);
                SetEntryOn(arg0, data_ov023_021fd5c6[var1]);
                SetEntryOff(arg0, data_ov023_021fd5ce[var1]);
            } else {
                SetEntryOff(arg0, var2);
                SetEntryOff(arg0, data_ov023_021fd5c6[var1]);
                SetEntryOff(arg0, data_ov023_021fd5ce[var1]);
            }
        }
        for (i = 0; i < n; i++) {
            v = vals[i];
            key = (short)(idx[i] + 12);
            SetEntryFields_021e23d0(obj->list, data_ov023_021fd5c6[i], KeyTable_Get(data_ov023_021ff9e0.field14, key), 10, 0xf);
            k = data_ov023_021fd5d6[i];
            ComputeShortPair_021e2bdc(obj->list, k, &p0, &p1);
            switch (key) {
            case 14:
            case 15:
            case 16:
            case 17:
                if (data_ov023_021ff9e0.unknown1_4_) {
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
                    func_ov023_021db3c0(var0, (short)(var11 + 8), var10, var4, 0xf);
#else
#if defined(jpn)
                    func_ov023_021db3c0(var0, (short)(p0 + 8), p1, v, 0xf);
#else
#if defined(jpn)
                    func_ov023_021db3c0(var0, (short)(p0 + 8), p1, v, 0xf);
#else
                    func_ov023_021db3c0(var0, var11, var10, var4, 0xf);
#endif

#endif

#endif

                }
                SetEntryOff(arg0, var5);
                break;
            default:
                if (v < 0.0f) {
                    k3 = data_ov023_021fd5ce[i];
                    SetEntryOn(obj, k3);
                    SetEntryFields_021e23d0(obj->list, k3, KeyTable_Get(data_ov023_021ff9e0.field14, 0x19), 8, 0xf);
                }
                var7 = labs((int)var4);
                func_ov023_021e24b0(arg0->unknown_cc_, data_ov023_021fd5d6[var1], var7, 8, 0xf, 1, 3, 0, 0);
                SetEntryOn(arg0, data_ov023_021fd5d6[var1]);
                break;
            }
        }
        FlushList(arg0, var0);
        func_ov023_021db544(arg0->unknown_cc_, (void*)0xb, var15, var14);
        SetEntryOff(arg0, 0xb);
    } else if (func_020dd718(arg0->unknown_77a_, arg0->unknown_4c_->unknown_16_)) {
        short var19;
        int var20;
        float var21;
        short var22;
        int var23;
        short var24;
        unsigned char var25;
        int var26 = arg0->unknown_77a_;
        struct Struct_ov023_021ddf5c_2* var27 = arg0->unknown_4c_;
        short var28, var29;
        short var30, var31;
        short var32, var33;
        func_ov023_021db45c(arg0->unknown_cc_, (struct Struct_ov023_021db45c*)var0, 0xb, &var33, &var32);
        SetEntryOn(arg0, 0xb);
        SetEntryOn(arg0, 0x2d);
        SetEntryOff(arg0, 0x2e);
        SetEntryOff(arg0, 0x2c);
        float var34[6];
        float var35[12];
        float var36[12];
        unsigned char var37[6];
        __clear(var36, 0x30);
        __clear(var35, 0x30);
        __clear(var37, 6);
        func_ov023_021dbc58((void*)var26, (Struct_ov023_021dbc58_2*)var36, (int)0);
        func_ov023_021dbb34(var27, (struct Struct_ov023_021dbb34*)var35);
        var25 = 0;
        __clear(var34, 0x18);
        for (var1 = 0; var1 < 12; var1++) {
            int var38 = 0;
            if (var1 == 3 && var27->unknown_8_0_ == 1) {
                if (var36[3]) var38 = 1;
            }
            if (var38 || var35[var1] != 0.0f) {
                var34[var25] = var36[var1];
                var37[var25] = var1;
                var25++;
                if (var25 >= 4) break;
            }
        }
        for (var1 = 0; var1 < 4; var1++) {
            var19 = data_ov023_021fd5de[var1];
            if (var1 < var25) {
                SetEntryOn(arg0, var19);
                SetEntryOn(arg0, data_ov023_021fd5e6[var1]);
                SetEntryOn(arg0, data_ov023_021fd5ee[var1]);
            } else {
                SetEntryOff(arg0, var19);
                SetEntryOff(arg0, data_ov023_021fd5e6[var1]);
                SetEntryOff(arg0, data_ov023_021fd5ee[var1]);
            }
        }
        for (i = 0; i < n; i++) {
            v = vals[i];
            key = (short)(idx[i] + 12);
            SetEntryFields_021e23d0(obj->list, data_ov023_021fd5e6[i], KeyTable_Get(data_ov023_021ff9e0.field14, key), 10, 0xf);
            k = data_ov023_021fd5f6[i];
            ComputeShortPair_021e2bdc(obj->list, k, &p0, &p1);
            switch (key) {
            case 14:
            case 15:
            case 16:
            case 17:
                if (data_ov023_021ff9e0.unknown1_4_) {
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
                    func_ov023_021db3c0(var0, (short)(var29 + 8), var28, var21, 0xf);
#else
#if defined(jpn)
                    func_ov023_021db3c0(var0, (short)(p0 + 8), p1, v, 0xf);
#else
#if defined(jpn)
                    func_ov023_021db3c0(var0, (short)(p0 + 8), p1, v, 0xf);
#else
                    func_ov023_021db3c0(var0, var29, var28, var21, 0xf);
#endif

#endif

#endif

                }
                SetEntryOff(arg0, var22);
                break;
            default:
                var23 = labs((int)var21);
                func_ov023_021e24b0(arg0->unknown_cc_, data_ov023_021fd5f6[var1], var23, 8, 0xf, 1, 3, 0, 0);
                SetEntryOn(arg0, data_ov023_021fd5f6[var1]);
                break;
            }
            k3 = data_ov023_021fd5ee[i];
            SetEntryOn(obj, k3);
            SetEntryFields_021e23d0(obj->list, k3, KeyTable_Get(data_ov023_021ff9e0.field14, 0x22), 8, 0xf);
        }
        FlushList(arg0, var0);
        func_ov023_021db544(arg0->unknown_cc_, (void*)0xb, var33, var32);
        SetEntryOff(arg0, 0xb);
    } else if (!func_020dd4c4(arg0->unknown_77a_, arg0->unknown_4c_)) {
        short var39;
        unsigned char var40;
        short var41;
        short var42;
        float var43;
        float var44;
        unsigned char var45;
        short var46;
        int var47;
        unsigned char var48;
        struct Struct_ov023_021ddf5c_2* var49 = arg0->unknown_4c_;
        int var50 = arg0->unknown_77a_;
        short var51, var52;
        short var53, var54;
        short var55, var56;
        func_ov023_021db45c(arg0->unknown_cc_, (struct Struct_ov023_021db45c*)var0, 0xb, &var56, &var55);
        SetEntryOn(arg0, 0xb);
        SetEntryOff(arg0, 0x2d);
        SetEntryOn(arg0, 0x2e);
        SetEntryOff(arg0, 0x2c);
        unsigned char var57[12];
        float var58[12];
        float var59[12];
        __clear(var59, 0x30);
        func_ov023_021dbc58((void*)var50, (Struct_ov023_021dbc58_2*)var59, (int)0);
        __clear(var58, 0x30);
        func_ov023_021dbc58((void*)var50, (Struct_ov023_021dbc58_2*)var58, (int)var49);
        struct Struct_ov023_021ddf5c* var60 = 0;
        __clear(var57, 0xc);
        if (var49 && var49->unknown_16_ > 0) var60 = var49->unknown_0_;
        if (var60) {
            if (var60->unknown_8_0_) var57[0] = 1;
            if (var60->unknown_9_2_) var57[1] = 1;
            if ((float)var60->unknown_a_4_ / 10.0f != 0.0f) var57[2] = 1;
            if ((float)var60->unknown_c_0_ / 10.0f != 0.0f) var57[3] = 1;
            if ((float)var60->unknown_d_2_ / 10.0f != 0.0f) var57[4] = 1;
            if (var60->unknown_10_0_) var57[6] = 1;
            if (var60->unknown_11_2_) var57[7] = 1;
            if (var60->unknown_12_4_) var57[8] = 1;
            if (var60->unknown_14_0_) var57[9] = 1;
            if (var60->unknown_15_2_) var57[10] = 1;
            if (var60->unknown_16_4_) var57[11] = 1;
            if (var49->unknown_8_0_ == 1) {
                if (var59[3] || var58[3]) var57[3] = 1;
            }
        }
        unsigned char var61[6];
        __clear(var61, 6);
        var48 = 0;
        for (var1 = 0; var1 < 12; var1++) {
            if (var57[var1] || var59[var1] - var58[var1] != 0.0f) {
                var61[var48] = var1;
                var48++;
                if (var48 >= 4) break;
            }
        }
        for (var40 = 0; var40 < 4; var40++) {
            var39 = data_ov023_021fd5fe[var40];
            if (var40 < var48) {
                SetEntryOn(arg0, var39);
                SetEntryOn(arg0, data_ov023_021fd606[var40]);
            } else {
                SetEntryOff(arg0, var39);
                SetEntryOff(arg0, data_ov023_021fd606[var40]);
            }
        }
        for (i = 0; i < n; i++) {
            j = idx[i];
            key = j + 12;
            SetEntryFields_021e23d0(obj->list, data_ov023_021fd606[i], KeyTable_Get(data_ov023_021ff9e0.field14, key), 10, 0xf);
            k = data_ov023_021fd60e[i];
            ComputeShortPair_021e2bdc(obj->list, k, &p0, &p1);
            v = cur[j];
            switch (key) {
            case 14:
            case 15:
            case 16:
            case 17:
                if (data_ov023_021ff9e0.unknown1_4_) {
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
                    func_ov023_021db3c0(var0, (short)(var52 + 8), var51, var43, 0xf);
#else
#if defined(jpn)
                    func_ov023_021db3c0(var0, (short)(p0 + 8), p1, v, 0xf);
#else
#if defined(jpn)
                    func_ov023_021db3c0(var0, (short)(p0 + 8), p1, v, 0xf);
#else
                    func_ov023_021db3c0(var0, var52, var51, var43, 0xf);
#endif

#endif

#endif

                }
                SetEntryOff(arg0, var42);
                break;
            default:
                var47 = labs((int)var43);
                func_ov023_021e24b0(arg0->unknown_cc_, data_ov023_021fd60e[var1], var47, 8, 0xf, 1, 3, 0, 0);
                SetEntryOn(arg0, data_ov023_021fd60e[var1]);
                break;
            }
            SetEntryFields_021e23d0(obj->list, data_ov023_021fd616[i], KeyTable_Get(data_ov023_021ff9e0.field14, 0x20), 8, 0xf);
            w = next[j];
            color = 9;
            if (v == w) color = 0xf;
            else if (v < w) color = 5;
            k5 = data_ov023_021fd61e[i];
            ComputeShortPair_021e2bdc(obj->list, k5, &p0, &p1);
            switch (key) {
            case 14:
            case 15:
            case 16:
            case 17:
                if (data_ov023_021ff9e0.unknown1_4_) {
#if defined(jpn)
                    func_02050678(buf, p0 + 16, p1, KeyTable_Get(data_ov023_021ff9e0.field14, 0x1a), 8, color, &o0, &o1);
#else
                    func_0204f41c(buf, p0 + 1, p1, KeyTable_Get(data_ov023_021ff9e0.field14, 0x1a), 8, color, &o0, &o1, 0);
#endif

#if defined(jpn)
                    func_ov023_021db3c0(var0, (short)(var52 + 8), var51, var44, var45);
#else
                    func_ov023_021db3c0(var0, var52, var51, var44, var45);
#endif

                }
                SetEntryOff(arg0, var46);
                break;
            default:
                var47 = labs((int)var44);
                func_ov023_021e24b0(arg0->unknown_cc_, data_ov023_021fd61e[var1], var47, 8, var45, 1, 3, 0, 0);
                SetEntryOn(arg0, data_ov023_021fd61e[var1]);
                break;
            }
        }
        FlushList(arg0, var0);
        func_ov023_021db544(arg0->unknown_cc_, (void*)0xb, var56, var55);
        SetEntryOff(arg0, 0xb);
    } else {
        short var62, var63;
        func_ov023_021db45c(arg0->unknown_cc_, (struct Struct_ov023_021db45c*)var0, 0xb, &var63, &var62);
        SetEntryOn(arg0, 0xb);
        SetEntryOn(arg0, 0x2c);
#if defined(jpn)

#else
        {
            struct Struct_ov023_021ddf5c_3* var64 = (struct Struct_ov023_021ddf5c_3*)func_ov023_021db4e4(arg0->unknown_cc_, 0x2c);
            if (var64) var64->unknown_16_ |= 8;
        }

#endif
        SetEntryFields_021e23d0(obj->list, 0x2c, KeyTable_Get(data_ov023_021ff9e0.field14, 0x21), 10, 0xf);
        SetEntryOff(obj, 0xa);
        SetEntryOff(obj, 0xc);
        SetEntryOff(obj, 0xd);
        SetEntryOff(obj, 0xe);
        SetEntryOff(obj, 0x2d);
        SetEntryOff(obj, 0x2e);
        FlushList(obj, buf);
        CreateAndSetFields8A_021db544(obj->list, (void*)0xb, d0, d1);
        SetEntryOff(obj, 0xb);
    }

    if (arg0->unknown_768_) {
        func_ov023_021ddc98(var0, arg0->unknown_768_, (unsigned short)data_ov023_021ff9e0.unknown_c_, 0);
    } else {
        int var65 = func_ov023_021ddc98(var0, arg0->unknown_75c_, (unsigned short)data_ov023_021ff9e0.unknown_c_, 0);
        arg0->unknown_768_ = arg0->unknown_75c_;
        arg0->unknown_76c_ = var65;
        arg0->unknown_75c_ = arg0->unknown_75c_ + var65;
    }
}
