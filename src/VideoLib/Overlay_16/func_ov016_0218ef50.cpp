#include <globaldefs.h>

struct Struct_ov016_0218ef50 {
    int sum;
    char unknown_4_[8];
    int arr1[6];
    int arr2[6];
};

struct Struct_ov016_0218e6c0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4(unsigned int a, unsigned int b);
    virtual void v5();
};

struct Struct_ov016_0218ef50_2 {
    Struct_ov016_0218e6c0* child;
    char unknown_4_[8];
    unsigned int capacity;
    char unknown_10_[0xe];
    unsigned short unknown_1e_;
    char unknown_20_[0x14];
    Struct_ov016_0218ef50* out;
    char unknown_38_[0x24];
    int* unknown_5c_;
    int* unknown_60_;
    char unknown_64_[0xc];
    unsigned int unknown_70_[2];
    unsigned int unknown_78_[2];
    unsigned int unknown_80_[2];
    unsigned int unknown_88_[2];
    int unknown_90_;
    char unknown_94_[4];
    unsigned int unknown_98_;
    #if defined(jpn)
    char unknown_9c_[0xc];
#else
    char unknown1_9c_[0x10];
#endif
    int unknown_ac_[6];
    char unknown_c4_[4];
    int result;
};

// USA: func_ov016_0218ef50
extern "C" ARM int func_ov016_0218ef50(Struct_ov016_0218ef50_2* o) {
    if (o->unknown_98_ == o->capacity) {
        return 0;
    }
    o->unknown_98_ = o->unknown_98_ + 1;

    int var0 = o->unknown_90_;
    o->unknown_90_ = (var0 + 1) % 2;

    o->child->v5();

    unsigned int packed = *(unsigned int*)(o->unknown_80_[o->unknown_90_] + o->unknown_78_[o->unknown_90_] + o->unknown_70_[o->unknown_90_]);
    o->unknown_78_[var0] = packed >> 14;
    o->unknown_88_[var0] = packed & 0x3fff;

    o->out->sum = o->unknown_70_[o->unknown_90_] + o->unknown_80_[o->unknown_90_];

    if (o->unknown_98_ < o->capacity) {
        o->unknown_80_[var0] = o->child->v4(o->unknown_70_[var0], o->unknown_78_[var0] + 4);
    }

    int i = 0;
    do {
        o->out->arr1[i] = o->unknown_5c_[o->unknown_ac_[i]];
        o->out->arr2[i] = o->unknown_60_[o->unknown_ac_[i]];
        i++;
    } while (i < 6);

    o->result = o->unknown_1e_ * o->unknown_88_[o->unknown_90_];
    return 1;
}
