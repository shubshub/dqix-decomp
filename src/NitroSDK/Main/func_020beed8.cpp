#include <globaldefs.h>

struct Struct_020beeac_2;
struct Struct_020beed8;
struct Struct_020bc180_2;
struct Struct_020bcc4c;
struct Struct_020bc9d0_2;

struct Struct_020beed8_2 {
    unsigned int unknown_0_;
    unsigned char volume;
    unsigned char unknown_5_;
    unsigned char unknown_6_;
    unsigned char flags;
};

struct Struct_020beed8_3;
typedef int (*Type_020bc180)(Struct_020beed8_3* player, unsigned int fileId);
typedef void (*Type_020bc180_2)(Struct_020beed8_3* player);

struct Struct_020beed8_3 {
    char stream[0xa8];
    char unknown_a8_[0x18];
    unsigned char format;
    unsigned char unknown_c1_;
    unsigned char unknown_c2_;
    unsigned char unknown_c3_;
    unsigned short unknown_c4_;
    unsigned short timer;
    char unknown_c8_[0xe8 - 0xc8];
    char unknown_e8_[0x10];
    char unknown_f8_[0x18];
    int unknown_110_0_ : 1;
    int unknown_110_1_ : 1;
    int unknown_110_2_ : 1;
    int unknown_110_3_ : 1;
    int unknown_110_4_ : 1;
    int unknown_110_5_ : 1;
    int unknown_110_6_ : 1;
    int unknown_114_;
    int unknown_118_;
    int unknown_11c_;
    int unknown_120_;
    unsigned char unknown_124_;
    unsigned char padding;
    unsigned char unknown_126_[6];
    void* buffer;
    unsigned int unknown_130_;
    void* unknown_134_;
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
    Type_020bc180 unknown_164_;
    Type_020bc180_2 unknown_168_;
    void* unknown_16c_;
    void* unknown_170_;
};

extern "C" void* func_020bee20(void** self, int index, int value);
extern "C" void func_020bffc4(void* obj, unsigned int id);
extern "C" void func_020beeac(struct Struct_020beeac_2* p);
extern "C" void func_020c01ec(struct Struct_020beed8* t);
extern "C" void func_020c0204(struct Struct_020bc180_2* t, int end, int duration);
extern "C" int func_020bf29c(void* obj, int a, int b);
extern "C" void func_020bf2d4(void* obj);
extern "C" void func_020bcc4c(struct Struct_020bcc4c* obj, int i, int arg);
extern "C" int func_020bc9d0(Struct_020bc9d0_2* stream, int format, void* buffer, unsigned long arg3,
                             int timer, int arg5, void* callback, void* arg);
extern "C" void func_020bf520(int status, int arg1, void* buffer[], unsigned int len, int format, void* arg);

// USA: func_020beed8
extern "C" ARM int func_020beed8(void** handle, const Struct_020beed8_2* arg1, int arg2, int arg3,
                                 int arg4, unsigned int offset, void* arg6, void* arg7,
                                 void* arg8, void* arg9) {
    Struct_020beed8_3* player;
    int format;
    int var2;
    unsigned long long var3;
    int ret;

    player = (Struct_020beed8_3*)func_020bee20(handle, arg2, arg3);
    if (player == NULL)
        return 0;

    func_020bffc4(player, arg1->unknown_0_);

    if (!player->unknown_164_(player, arg1->unknown_0_)) {
        func_020beeac((struct Struct_020beeac_2*)player);
        return 0;
    }

    var3 = player->unknown_c4_;
    var3 *= offset;
    var3 /= 1000;
    player->unknown_160_ = (unsigned int)var3;

    if (player->unknown_160_ != 0 && player->format == 2) {
        player->unknown_110_4_ = 1;
    } else {
        player->unknown_110_4_ = 0;
    }

    player->unknown_114_ = 4;
    player->unknown_110_5_ = 0;
    player->unknown_110_1_ = 0;
    player->unknown_118_ = 0;
    player->unknown_110_2_ = 0;
    player->unknown_110_3_ = 0;
    player->unknown_11c_ = 0;

    player->unknown_134_ = arg6;
    player->unknown_138_ = arg7;
    player->unknown_13c_ = arg8;
    player->unknown_140_ = arg9;

    player->unknown_144_ = arg4;

    player->volume = 0;
    player->unknown_154_ = arg1->volume;
    player->unknown_158_ = 127;

    func_020c01ec((struct Struct_020beed8*)player->unknown_e8_);
    func_020c0204((struct Struct_020bc180_2*)player->unknown_e8_, 127 << 8, 1);

    switch (player->format) {
    case 0:
        format = 0;
        break;
    case 1:
    case 2:
        format = 1;
        break;
    }

    var2 = player->unknown_c2_;
    if (arg1->flags & 1) {
        var2 = 2;
    }
    if (var2 > player->unknown_124_) {
        var2 = player->unknown_124_;
    }
    player->unknown_110_6_ = (var2 == 1) ? 1 : 0;

    ret = func_020bf29c(player, var2, (int)player->unknown_126_);
    if (!ret) {
        player->unknown_168_(player);
        func_020beeac((struct Struct_020beeac_2*)player);
        return 0;
    }

    ret = func_020bc9d0((Struct_020bc9d0_2*)player->stream, format, player->buffer,
                        player->unknown_130_ * var2 / player->unknown_124_, player->timer, 4,
                        (void*)func_020bf520, player);
    if (!ret) {
        func_020bf2d4(player);
        player->unknown_168_(player);
        func_020beeac((struct Struct_020beeac_2*)player);
        return 0;
    }

    if (var2 == 2) {
        struct Struct_020bcc4c* stream = (struct Struct_020bcc4c*)player->stream;
        func_020bcc4c(stream, 0, 0);
        func_020bcc4c(stream, 1, 127);
    }

    return 1;
}
