#include <globaldefs.h>
#include "World/Object3D.h"

struct Entry_02028bd0;
struct Entry_02028bd0* ZoneRecords_GetInstance(void);
struct Entry_02028bd0* FindInlineEntryById(struct Entry_02028bd0* base, int key);

struct Struct_02039df4;

struct Struct_020283fc;
extern "C" int func_020283fc(struct Struct_020283fc* arg0, int arg1);

extern "C" int func_02073d58(int arg0, void* arg1, int arg2);

struct Struct_02003d14;
struct Struct_02073ec4_2;
struct Struct_02078e60_2 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned int unknown_4_0_ : 3;
    unsigned int unknown_4_3_ : 10;
    unsigned int unknown_5_5_ : 8;
    unsigned int unknown_6_5_ : 11;
    unsigned char unknown_8_[0x20 - 8];
};
extern "C" struct Struct_02078e60_2* func_0209bd94(struct Struct_02073ec4_2* arg0, int arg1);

struct Struct_02078e60_3 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
};

struct Struct_02028430_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char unknown_3_[0xc - 3];
    struct Struct_02078e60_3** unknown_c_;
};
extern "C" struct Struct_02028430_2* func_02028430(struct Struct_02028430* arg0, int arg1);

struct Struct_02078e60 {
    char unknown_0_[2];
    short unknown_2_;
    short unknown_4_;
    char unknown_6_[0xb8 - 6];
    unsigned short unknown_b8_;
    char unknown_ba_[0x168 - 0xba];
    unsigned short unknown_168_;
    char unknown_16a_[0x17d - 0x16a];
    unsigned char unknown_17d_;
};

extern "C" int rand(void);

// USA: func_02078e60
extern "C" ARM unsigned short func_02078e60(void* arg0, char* arg1) {
    struct Struct_02078e60* var0 = (struct Struct_02078e60*)arg0;
    struct Struct_020fdd44* var1;
    struct Struct_020fdd44* var2;
    struct Struct_02028430_2* var3;
    struct Struct_02078e60_2* var4;
    struct Struct_02078e60_3* var5;
    struct Struct_02078e60_3* var6[16];
    struct Struct_02078e60_3* var7;
    int var8;
    int var9;
    int var10;
    int var11;

    *out = 0;
    table = ZoneRecords_GetInstance();
    entry = FindInlineEntryById(table, ((Object3D*)((struct U16Field0x6_020375f8*)o))->GetField06());
    if (entry == NULL) {
        return 0;
    }
#if defined(jpn)
    var3 = func_02028430((struct Struct_02028430*)((char*)var2 + 0x14), var0->unknown_b8_);
#else
    var3 = func_02028430((struct Struct_02028430*)((char*)var2 + 0x18), var0->unknown_b8_);
#endif
    if (var3 == NULL) {
        return 0;
    }
    if (var3->unknown_2_ == 0) {
        return 0;
    }
    if ((var0->unknown_17d_ & 0x40) == 0) {
        if (func_02073d58(var3->unknown_0_, var2, var0->unknown_4_) != 0) {
            *arg1 = 1;
            return var3->unknown_0_;
        }
        *arg1 = 0;
        var0->unknown_17d_ |= 0x40;
        return var3->unknown_0_;
    }
#if defined(jpn)
    var4 = func_0209bd94((struct Struct_02073ec4_2*)((char*)var2 + 0x5c), var0->unknown_168_);
#else
    var4 = func_0209bd94((struct Struct_02073ec4_2*)((char*)var2 + 0x60), var0->unknown_168_);
#endif
    var8 = 0;
    var10 = 0;
    if (var4 != NULL) {
        for (var9 = 0; var9 < var3->unknown_2_; var9++) {
            var5 = var3->unknown_c_[var9];
            if ((var5->unknown_1_ & var4->unknown_5_5_) == 0 && var5->unknown_1_ != 0) {
                continue;
            }
            if (func_02073d58(var5->unknown_0_, var2, -1) != 0) {
                var10 = 1;
            } else {
                var6[var8++] = var3->unknown_c_[var9];
            }
        }
    }
    if (var10 == 1 && var8 == 0) {
#if defined(jpn)
        var11 = func_020283fc((struct Struct_020283fc*)((char*)var2 + 0x14), var3->unknown_0_);
#else
        var11 = func_020283fc((struct Struct_020283fc*)((char*)var2 + 0x18), var3->unknown_0_);
#endif
        if (var11 != -1) {
            var0->unknown_b8_ = var11;
        }
        return var3->unknown_0_;
    }
    var7 = 0;
    if (var8 != 0) {
        var7 = var6[rand() % var8];
    }
    if (var7 == 0) {
#if defined(jpn)
        var11 = func_020283fc((struct Struct_020283fc*)((char*)var2 + 0x14), var3->unknown_0_);
#else
        var11 = func_020283fc((struct Struct_020283fc*)((char*)var2 + 0x18), var3->unknown_0_);
#endif
        if (var11 != -1) {
            var0->unknown_b8_ = var11;
        }
        return var3->unknown_0_;
    }
#if defined(jpn)
    var11 = func_020283fc((struct Struct_020283fc*)((char*)var2 + 0x14), var7->unknown_0_);
#else
    var11 = func_020283fc((struct Struct_020283fc*)((char*)var2 + 0x18), var7->unknown_0_);
#endif
    if (var11 != -1) {
        var0->unknown_b8_ = var11;
    }
    return var7->unknown_0_;
}
