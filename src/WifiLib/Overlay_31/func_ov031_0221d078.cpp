#include <globaldefs.h>

struct Struct_ov031_0224eda8 {
    int kind;
    unsigned int unknown_4_;
    char ssid[0x28];
    char keys[4][0x40];
};
struct Struct_ov031_0224f008 {
    int kind;
    unsigned int unknown_4_;
    char ssid[0x28];
    char key[0x40];
};
struct Struct_ov031_0221d078 {
    char unknown_0_[4][6];
    char unknown_18_[0x21];
    char unknown_39_[4][14];
    char unknown_71_[0x21];
    char unknown_92_[0x40];
    char unknown_d2_[0x21];
    char unknown_f3_[0x40];
    char unknown_133_[0x21];
};
struct SessionState {
    unsigned char pad0[0x2c];
    unsigned int mode;
    unsigned int offset;
};
struct Struct_ov031_0221d078_2 {
    unsigned short unknown_0_;
    char pad2[0x114];
    unsigned char state;
};

extern SessionState data_ov031_0224e6e0;
extern Struct_ov031_0224eda8 data_ov031_0224eda8;
extern Struct_ov031_0224eda8 data_ov031_0224eed8;
extern Struct_ov031_0224f008 data_ov031_0224f008;
extern Struct_ov031_0224f008 data_ov031_0224f078;
extern "C" void func_ov031_0221e51c(void*, const void*, unsigned int);
extern "C" void func_ov031_0221e52c(void*, int, unsigned int);
extern "C" int func_ov031_0221e650(const char*);
extern "C" int func_ov031_0221d270(const char*, int);

// USA: func_ov031_0221d078
extern "C" THUMB int func_ov031_0221d078(Struct_ov031_0221d078_2* ctx) {
    Struct_ov031_0221d078* var0 = (Struct_ov031_0221d078*)((unsigned char*)ctx + 0x117);
    Struct_ov031_0224eda8* var1 = &data_ov031_0224eda8;
    Struct_ov031_0224eda8* var2 = &data_ov031_0224eed8;
    Struct_ov031_0224f008* var3 = &data_ov031_0224f008;
    Struct_ov031_0224f008* var4 = &data_ov031_0224f078;
    if (var0 == 0) {
        return -1;
    }
    ctx->unknown_0_ = data_ov031_0224e6e0.mode & data_ov031_0224e6e0.offset;
    func_ov031_0221e52c(var0, 0, sizeof(Struct_ov031_0221d078));
    if (ctx->unknown_0_ & 1) {
        func_ov031_0221e51c(var0->unknown_0_[0], var1->keys[0], var1->unknown_4_);
        func_ov031_0221e51c(var0->unknown_0_[1], var1->keys[1], var1->unknown_4_);
        func_ov031_0221e51c(var0->unknown_0_[2], var1->keys[2], var1->unknown_4_);
        func_ov031_0221e51c(var0->unknown_0_[3], var1->keys[3], var1->unknown_4_);
        if (func_ov031_0221d270(var1->ssid, func_ov031_0221e650(var1->ssid)) != 0) {
            goto fail;
        }
        func_ov031_0221e51c(var0->unknown_18_, var1->ssid, func_ov031_0221e650(var1->ssid));
    }
    if (ctx->unknown_0_ & 2) {
        func_ov031_0221e51c(var0->unknown_39_[0], var2->keys[0], var2->unknown_4_);
        func_ov031_0221e51c(var0->unknown_39_[1], var2->keys[1], var2->unknown_4_);
        func_ov031_0221e51c(var0->unknown_39_[2], var2->keys[2], var2->unknown_4_);
        func_ov031_0221e51c(var0->unknown_39_[3], var2->keys[3], var2->unknown_4_);
        if (func_ov031_0221d270(var2->ssid, func_ov031_0221e650(var2->ssid)) != 0) {
            goto fail;
        }
        func_ov031_0221e51c(var0->unknown_71_, var2->ssid, func_ov031_0221e650(var2->ssid));
    }
    if (ctx->unknown_0_ & 4) {
        if (func_ov031_0221d270(var3->key, var3->unknown_4_ - 1) != 0) {
            goto fail;
        }
        func_ov031_0221e51c(var0->unknown_92_, var3->key, var3->unknown_4_);
        if (func_ov031_0221d270(var3->ssid, func_ov031_0221e650(var3->ssid)) != 0) {
            goto fail;
        }
        func_ov031_0221e51c(var0->unknown_d2_, var3->ssid, func_ov031_0221e650(var3->ssid));
    }
    if (ctx->unknown_0_ & 8) {
        if (func_ov031_0221d270(var4->key, var4->unknown_4_ - 1) != 0) {
            goto fail;
        }
        func_ov031_0221e51c(var0->unknown_f3_, var4->key, var4->unknown_4_);
        if (func_ov031_0221d270(var4->ssid, func_ov031_0221e650(var4->ssid)) != 0) {
            goto fail;
        }
        func_ov031_0221e51c(var0->unknown_133_, var4->ssid, func_ov031_0221e650(var4->ssid));
    }
    ctx->state = 0;
    return 0;
fail:
    func_ov031_0221e52c(var0, 0, sizeof(Struct_ov031_0221d078));
    return -1;
}
