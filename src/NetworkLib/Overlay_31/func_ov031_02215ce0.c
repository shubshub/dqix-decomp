#include <globaldefs.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Struct_ov031_02215ce0_6 Struct_ov031_02215ce0_6;
typedef struct Struct_ov031_02215ce0 Struct_ov031_02215ce0;
typedef struct Struct_ov031_02215ce0_2 Struct_ov031_02215ce0_2;
typedef struct Struct_ov031_02215ce0_3 Struct_ov031_02215ce0_3;
typedef struct Struct_ov031_02215ce0_4 Struct_ov031_02215ce0_4;
typedef struct Struct_0200f3a4_16 Struct_0200f3a4_16;
typedef struct Struct_0200f3a4_17 Struct_0200f3a4_17;
typedef struct Struct_ov031_02215ce0_5 Struct_ov031_02215ce0_5;

void VectorizedMemset(void*, int, unsigned int);
void VectorizedInvertedMemcpy(const void*, void*, unsigned int);
void InvalidateDataCacheRange(const void*, unsigned int);

struct Struct_ov031_02215ce0_6 {
    unsigned short unknown_0_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    unsigned long unknown_4_;
    unsigned short tgid;
    unsigned char unknown_a_;
    union {
        unsigned char unknown_b_;
        unsigned char unknown1_b_;
    };
    unsigned short unknown_c_;
    unsigned short unknown_e_;
    union {
        unsigned short unknown_10_[56];
        struct {
            unsigned short unknown_0_[4];
            unsigned short unknown_8_[8];
            unsigned short unknown_18_[44];
        } unknown1_10_;
    };
};
struct Struct_ov031_02215ce0 {
    unsigned short length;
    unsigned short unknown_2_;
    unsigned char bssid[6];
    unsigned short unknown_a_;
    unsigned char ssid[32];
    unsigned short unknown_2c_;
    struct {
        unsigned short unknown_0_;
        unsigned short unknown_2_;
    } unknown_2e_;
    unsigned short unknown_32_;
    unsigned short unknown_34_;
    unsigned short channel;
    unsigned short unknown_38_;
    unsigned short unknown_3a_;
    unsigned short unknown_3c_;
    unsigned short unknown_3e_;
    Struct_ov031_02215ce0_6 unknown_40_;
};
struct Struct_ov031_02215ce0_2 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned short state;
    unsigned short unknown_a_;
    unsigned char reserved[2];
    unsigned short unknown_e_;
    Struct_ov031_02215ce0* unknown_10_[16];
    unsigned short unknown_50_[16];
};

struct Struct_ov031_02215ce0_3 {
    unsigned char ssid[32];
    unsigned char unknown_20_[10];
    unsigned short unknown_2a_;
    unsigned char unknown_2c_[24];
    unsigned char unknown_44_[32];
    unsigned char channel;
    unsigned char unknown_65_;
    unsigned char unknown_66_;
    unsigned char reserved[5];
    unsigned short unknown_6c_;
    unsigned short unknown_6e_;
};

struct Struct_ov031_02215ce0_4 {
    unsigned short table[256];
};

struct Struct_0200f3a4_16 {
    Struct_ov031_02215ce0* unknown_0_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned short unknown_8_;
    unsigned char bssid[6];
    unsigned short unknown_10_;
    unsigned short unknown_12_;
    unsigned char ssid[32];
    unsigned short unknown_34_;
    unsigned short unknown_36_[7];
};

struct Struct_0200f3a4_17 {
    unsigned char i;
    unsigned char j;
    unsigned char reserved[2];
    unsigned char s[256];
};

struct Struct_ov031_02215ce0_5 {
    unsigned char unknown_0_[0xf00] __attribute__((aligned(32)));
    unsigned char unknown_f00_[0x400];
    Struct_0200f3a4_16 unknown_1300_;
    void (*callback)(void*);
    Struct_ov031_02215ce0_3 slots[16];
    unsigned short unknown_1a48_[16];
    unsigned short unknown_1a68_[16];
    long count;
    long unknown_1a8c_;
    unsigned long unknown_1a90_;
    unsigned short unknown_1a94_;
    Struct_ov031_02215ce0_4 unknown_1a96_;
    Struct_0200f3a4_17 unknown_1c96_;
};

extern Struct_ov031_02215ce0_5* data_ov031_0224e5d8;
void func_ov031_022118a8(Struct_0200f3a4_17*, const void*, unsigned long);
void func_ov031_02211938(Struct_0200f3a4_17*, const void*, unsigned long, void*);
void func_020d1be4(const unsigned short*, unsigned short*, const unsigned char*, unsigned int);
unsigned short func_020d1cc8(const unsigned short*, const unsigned char*, unsigned int);
int func_ov031_02215ccc(int);

#ifdef __cplusplus
}
#endif

// USA: func_ov031_02215ce0
#ifdef __cplusplus
extern "C"
#endif
ARM void func_ov031_02215ce0(void* argument) {
    Struct_ov031_02215ce0_2* var0 = (Struct_ov031_02215ce0_2*)argument;
    static const unsigned long magic = 0x57445321;
    InvalidateDataCacheRange(data_ov031_0224e5d8->unknown_f00_, 0x400);
    if (var0->unknown_2_ == 0 && var0->state == 5) {
        unsigned long entryIndex = 0;
        if (entryIndex < var0->unknown_e_) {
            do {
                if (var0->unknown_10_[entryIndex]->unknown_40_.unknown_0_ == 1 && var0->unknown_10_[entryIndex]->unknown_40_.unknown_4_ == 0x857) {
                    unsigned long index;
                    int found = 0;
                    index = 0;
                    if (index < data_ov031_0224e5d8->count) {
                        unsigned short id = var0->unknown_10_[entryIndex]->unknown_40_.tgid;
                        do {
                            unsigned short var5 = data_ov031_0224e5d8->unknown_1a68_[index];
                            if (var5 == id) {
                                found = 1;
                                break;
                            }
                            ++index;
                        } while (index < data_ov031_0224e5d8->count);
                    }
                    if (found != 1) {
                        unsigned char var6[8];
                        unsigned char* var7;
                        unsigned short var8;
                        Struct_ov031_02215ce0_5* state;
                        unsigned short var10;
                        VectorizedInvertedMemcpy(var0->unknown_10_[entryIndex]->unknown_40_.unknown_10_,
                            &data_ov031_0224e5d8->slots[data_ov031_0224e5d8->unknown_1a8c_], 0x70);
                        VectorizedInvertedMemcpy(&magic, var6, 4);
                        VectorizedInvertedMemcpy(var0->unknown_10_[entryIndex]->bssid + 2, var6 + 4, 4);
                        func_ov031_022118a8(&data_ov031_0224e5d8->unknown_1c96_, var6, 8);
                        func_ov031_02211938(&data_ov031_0224e5d8->unknown_1c96_,
                            &data_ov031_0224e5d8->slots[data_ov031_0224e5d8->unknown_1a8c_], 0x70,
                            &data_ov031_0224e5d8->slots[data_ov031_0224e5d8->unknown_1a8c_]);
                        var7 = (unsigned char*)&data_ov031_0224e5d8->slots[data_ov031_0224e5d8->unknown_1a8c_];
                        func_020d1be4(data_ov031_0224e5d8->unknown_1a96_.table, &data_ov031_0224e5d8->unknown_1a94_, var7, 0x6e);
                        var8 = func_020d1cc8(data_ov031_0224e5d8->unknown_1a96_.table, var7, 0x6e);
                        state = data_ov031_0224e5d8;
                        var10 = state->slots[state->unknown_1a8c_].unknown_6e_;
                        if (var8 != var10 && var10 != 0) {
                            VectorizedMemset(&state->slots[state->unknown_1a8c_], 0, 0x70);
                        } else {
                            state->unknown_1a48_[state->unknown_1a8c_] = func_ov031_02215ccc((unsigned char)var0->unknown_10_[entryIndex]->unknown_2_);
                            data_ov031_0224e5d8->unknown_1a68_[data_ov031_0224e5d8->unknown_1a8c_] = var0->unknown_10_[entryIndex]->unknown_40_.tgid;
                            data_ov031_0224e5d8->unknown_1a8c_ = (data_ov031_0224e5d8->unknown_1a8c_ + 1) % 16;
                            ++data_ov031_0224e5d8->count;
                            state = data_ov031_0224e5d8;
                            if (state->count > 16)
                                state->count = 16;
                        }
                    }
                }
                ++entryIndex;
            } while (entryIndex < var0->unknown_e_);
        }
    }
    data_ov031_0224e5d8->unknown_1a90_ = 2;
    if (data_ov031_0224e5d8->callback)
        data_ov031_0224e5d8->callback(var0);
}
