#include <globaldefs.h>
#include <NitroSDK/Memory.h>
#include <NitroSDK/Mutex.h>
#include <NitroSDK/Cache.h>

struct Struct_020bf658_2;
extern "C" void func_020bf658(struct Struct_020bf658_2* obj);

struct Struct_020bf79c {
    struct {
        short unknown_0_;
        unsigned char unknown_2_;
        unsigned char padding;
    };
};

struct Struct_020bf79c_3;
typedef int (*Type_01ff8b48_2)(Struct_020bf79c_3* player, void* dest, unsigned int size, unsigned int offset);
enum Enum_020bf79c { Enum_020bf79c_0, Enum_020bf79c_1 };
typedef void (*Type_01ff8b48_3)(int status, int numChannels, void* buffer[], unsigned int len,
                                     Enum_020bf79c format, void* arg);

struct Struct_020bf79c_3 {
    char stream[0xa8];
    char unknown_a8_[0x18];
    unsigned char format;
    unsigned char unknown_c1_;
    unsigned char unknown_c2_;
    unsigned char unknown_c3_;
    unsigned short unknown_c4_;
    unsigned short timer;
    unsigned int unknown_c8_;
    unsigned int unknown_cc_;
    unsigned int unknown_d0_;
    unsigned int unknown_d4_;
    unsigned int unknown_d8_;
    unsigned int unknown_dc_;
    unsigned int unknown_e0_;
    unsigned int unknown_e4_;
    char unknown_e8_[0x10];
    Struct_020bf79c unknown_f8_[6];
    int unknown_110_0_ : 1;
    int unknown_110_1_ : 1;
    int unknown_110_2_ : 1;
    int unknown_110_3_ : 1;
    int unknown_110_4_ : 1;
    int unknown_110_5_ : 1;
    int unknown_110_6_ : 1;
    volatile int unknown_114_;
    volatile int unknown_118_;
    volatile int unknown_11c_;
    int unknown_120_;
    unsigned char unknown_124_;
    unsigned char padding;
    unsigned char unknown_126_[6];
    void* buffer;
    unsigned int unknown_130_;
    Type_01ff8b48_3 unknown_134_;
    void* unknown_138_;
    void* unknown_13c_;
    void* unknown_140_;
    int unknown_144_;
    int unknown_148_;
    void* handle;
    int unknown_150_;
    int unknown_154_;
    int unknown_158_;
    int volume;
    unsigned int unknown_160_;
    void* unknown_164_;
    void* unknown_168_;
    Type_01ff8b48_2 unknown_16c_;
    void* unknown_170_;
};

struct Struct_020bf79c_2 {
    void* link[2];
    Struct_020bf79c_3* player;
    int status;
    int unknown_10_;
    void* buffer[6];
    unsigned int unknown_2c_;
};

struct Struct_021103b0_6 {
    int f0;
    unsigned char* unknown_4_;
    unsigned char* unknown_8_;
};

extern const signed char data_020e9338[16];
extern const short data_020e9348[89];
extern struct Struct_021103b0_6 data_021103b0;
extern Mutex data_021103c8;

static inline short inline_020bf79c(int code, Struct_020bf79c* state) {
    int step;
    int sample;
    int index;
    int d;

    sample = state->unknown_0_;
    index = state->unknown_2_;

    step = data_020e9348[index];

    d = step >> 3;
    if (code & 4) d += step;
    if (code & 2) d += step >> 1;
    if (code & 1) d += step >> 2;

    if (code & 8) {
        sample -= d;
        if (sample < -32768) sample = -32768;
    } else {
        sample += d;
        if (sample > 32767) sample = 32767;
    }

    index += data_020e9338[code];

    if (index < 0) index = 0;
    else if (index > 89 - 1) index = 89 - 1;

    state->unknown_0_ = (short)sample;
    state->unknown_2_ = (unsigned char)index;

    return (short)sample;
}

// USA: func_020bf79c
extern "C" ARM void func_020bf79c(Struct_020bf79c_2* command) {
    Struct_020bf79c_3* player = command->player;
    int var1;
    long var2;
    unsigned int var3;
    unsigned int var4;
    unsigned int var5;
    unsigned int var6;
    unsigned int var7;
    unsigned int var8;
    unsigned int offset;
    unsigned int samples;
    unsigned int size;
    unsigned int var12;
    int ch;

    if (player->unknown_110_5_ && player->unknown_114_ > 0) {
        player->unknown_114_--;
    }

    var2 = 0;

    var3 = command->unknown_2c_;
    while (var3 > 0) {
        if (player->unknown_110_5_) {
            for (ch = 0; ch < command->unknown_10_; ch++) {
                VectorizedMemset((unsigned char*)(command->buffer[ch]) + var2, 0, var3);
            }
            break;
        }

        var4 = player->unknown_160_ / player->unknown_dc_;

        if (var4 < player->unknown_d4_ - 1) {
            var5 = player->unknown_d8_;
            var6 = player->unknown_dc_;
        } else {
            var5 = player->unknown_e0_;
            var6 = player->unknown_e4_;
        }

        var7 = player->unknown_160_;
        var7 -= var4 * player->unknown_dc_;

        samples = var3;
        if (player->format != 0) {
            samples >>= 1;
        }

        if (player->unknown_110_4_) {
            if (var7 == 0) {
                player->unknown_110_4_ = 0;
            } else {
                samples = var7;
                var7 = 0;
            }
        }

        var1 = 0;
        if (var7 + samples >= var6) {
            samples = var6 - var7;

            if (var4 >= player->unknown_d4_ - 1) {
                if (player->unknown_c1_) {
                    var1 = 1;
                } else {
                    player->unknown_110_5_ = 1;
                }
            }
        }

        var8 = var7;
        size = samples;
        switch (player->format) {
        case 0:
            var12 = size;
            break;
        case 1:
            var8 <<= 1;
            size <<= 1;
            var12 = size;
            break;
        case 2: {
            unsigned int var14 = var7 + samples;
            var8 >>= 1;
            var14++;
            var14 >>= 1;
            var12 = var14 - var8;
            if (var7 == 0) {
                var12 += sizeof(Struct_020bf79c);
            } else {
                var8 += sizeof(Struct_020bf79c);
            }
            size <<= 1;
            break;
        }
        }

        offset = var8;
        offset += var4 * player->unknown_d8_ * player->unknown_c2_;
        offset += player->unknown_d0_;

        for (ch = 0; ch < command->unknown_10_; ch++) {
            void* dest;
            void* var16;

            dest = var16 = (unsigned char*)(command->buffer[ch]) + var2;

            if (ch < player->unknown_c2_) {
                int var17;

                if (player->format == 2) {
                    LockMutex(&data_021103c8);
                    var16 = data_021103b0.unknown_8_;
                }

                var17 = player->unknown_16c_(player, var16, var12, offset + ch * var5);

                if (var17 != var12) {
                    size = 0;
                    samples = 0;
                    var1 = 0;
                    player->unknown_110_5_ = 1;
                    if (player->format == 2) {
                        UnlockMutex(&data_021103c8);
                    }
                    break;
                }

                if (player->format == 2) {
                    Struct_020bf79c* state = &player->unknown_f8_[ch];
                    unsigned char* var19 = data_021103b0.unknown_8_;
                    short* destp = (short*)dest;
                    unsigned int i;
                    unsigned int end;

                    if (var7 == 0) {
                        *state = *((Struct_020bf79c*)var19)++;
                    }

                    end = var7 + samples;

                    i = var7;
                    if (i & 0x01) {
                        *destp++ = inline_020bf79c((*var19 >> 4) & 0x0f, state);
                        i++;
                        var19++;
                    }
                    while (i < (end & ~0x01)) {
                        *destp++ = inline_020bf79c(*var19 & 0x0f, state);
                        i++;
                        *destp++ = inline_020bf79c((*var19 >> 4) & 0x0f, state);
                        i++;
                        var19++;
                    }
                    if (i < end) {
                        *destp++ = inline_020bf79c(*var19 & 0x0f, state);
                        i++;
                    }
                    UnlockMutex(&data_021103c8);
                }
            } else {
                if (player->unknown_110_6_) {
                    VectorizedMemset(dest, 0, size);
                } else {
                    VectorizedInvertedMemcpy((unsigned char*)(command->buffer[0]) + var2, dest, size);
                }
            }
        }

        if (player->unknown_110_4_) {
            player->unknown_110_4_ = 0;
            continue;
        }

        if (var1) {
            player->unknown_160_ = player->unknown_c8_;
        } else {
            player->unknown_160_ += samples;
        }

        var2 += size;

        var3 -= size;

        if (player->unknown_110_5_ && player->unknown_13c_) {
            func_020bf658((struct Struct_020bf658_2*)player);
        }
    }

    if (player->unknown_134_ != NULL) {
        player->unknown_134_(command->status, command->unknown_10_, command->buffer, command->unknown_2c_,
                             player->format == 0 ? Enum_020bf79c_0 : Enum_020bf79c_1,
                             player->unknown_138_);
    }

    for (ch = 0; ch < command->unknown_10_; ch++) {
        CleanInvalidateCacheRange(command->buffer[ch], command->unknown_2c_);
    }

    if (command->status == 0) {
        player->unknown_118_ = 1;
    }
}
