#include <globaldefs.h>

#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif

struct Struct_ov012_0218b008 {
    unsigned char key;
    unsigned char v1;
    unsigned char v2;
    signed char v3;
    signed char v4;
    unsigned char v5;
    unsigned char v6;
};
extern struct Struct_ov012_0218b008 data_ov012_0218b008[];

struct Struct_ov012_021893b4 {
    char pad[LOW_REGION(0x130, 0xa0)];
    short unknown_a0_;
    short unknown_a2_;
    short unknown_a4_;
    short unknown_a6_;
    short unknown_a8_;
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
    char unknown_b0_;
    unsigned char unknown_b1_;
    char unknown_b2_[3];
    unsigned char unknown_b5_;
};

// USA: func_ov012_021893b4
extern "C" ARM void func_ov012_021893b4(void* obj, int key, int p2, int p3) {
    struct Struct_ov012_021893b4* d = (struct Struct_ov012_021893b4*)((char*)obj + LOW_REGION(0, 0xac));
    int i;
    for (i = 0; data_ov012_0218b008[i].key != 0xff; i++) {
        struct Struct_ov012_0218b008* e = &data_ov012_0218b008[i];
        if (e->key == key) {
            unsigned char t2, var4;
            signed char var5, var6;
            unsigned char var7, var8;
            d->unknown_b1_ = e->key;
            d->unknown_a4_ = p2;
            d->unknown_a6_ = p3;
            t2 = e->v2;
            var4 = e->v1;
            d->unknown_a8_ = var4;
            d->unknown_aa_ = t2;
            var5 = e->v4;
            var6 = e->v3;
            d->unknown_a0_ = var6;
            d->unknown_a2_ = var5;
            var7 = e->v6;
            var8 = e->v5;
            d->unknown_ac_ = var8;
            d->unknown_ae_ = var7;
            d->unknown_b5_ = 1;
            return;
        }
    }
}
