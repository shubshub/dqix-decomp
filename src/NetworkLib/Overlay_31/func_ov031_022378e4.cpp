#include <globaldefs.h>

extern "C" void InvalidateDataCacheRange(const void* addr, unsigned int len);
extern "C" int memcmp(const void* a, const void* b, unsigned int len);

typedef void (*Type_ov031_022378e4)(int);

struct Struct_ov031_022378e4 {
    char unknown_0_[6];
    unsigned char unknown_6_;
};

struct Struct_ov031_022378e4_2 {
    unsigned char unknown_0_[0xf00];
    unsigned char unknown_f00_[0x400];
    Struct_ov031_022378e4 unknown_1300_[16];
    Type_ov031_022378e4 unknown_1370_;
    unsigned char unknown_1374_[0x821];
    unsigned char unknown_1b95_;
};

struct Struct_ov031_022378e4_3 {
    unsigned char unknown_0_[4];
    char unknown_4_[6];
    unsigned char unknown_a_[2];
    unsigned char unknown_c_[8];
    unsigned char unknown_14_[1];
    unsigned char unknown_15_;
};

struct Struct_ov031_022378e4_4 {
    unsigned char unknown_0_[0xe];
    unsigned short unknown_e_;
    Struct_ov031_022378e4_3* unknown_10_[1];
};

extern Struct_ov031_022378e4_2* data_ov031_02290d0c;
extern char data_ov031_02249288[];

// USA: func_ov031_022378e4
extern "C" ARM void func_ov031_022378e4(Struct_ov031_022378e4_4* arg0) {
    Struct_ov031_022378e4_2* var0 = data_ov031_02290d0c;
    unsigned char var1 = var0->unknown_1b95_;
    int var2;
    Struct_ov031_022378e4_3* var3;
    int var4;
    int var5;
    Struct_ov031_022378e4* var6;
    Struct_ov031_022378e4_2* var7;

    if (var1 != 0) {
        Type_ov031_022378e4 var8 = var0->unknown_1370_;
        if (var8 != 0) {
            var8(var1);
        }
        return;
    }
    InvalidateDataCacheRange(var0->unknown_f00_, 0x400);

    var2 = arg0->unknown_e_;
    var4 = 0;
    if (var2 <= 0) {
        return;
    }
    var7 = data_ov031_02290d0c;
    do {
        peer = list->peers[i];
        if (memcmp(peer->signature, data_ov031_02249288, 8) == 0 && (peer->flags & 1) != 0) {
            slot = sys->slots;
            j = 0;
            do {
                if (memcmp(peer->name, slot->name, 6) == 0) {
                    NotifyCallback_022378e4 notify;
                    if (sys->slots[j].inUse != 0) {
                        break;
                    }
                    var9 = var7->unknown_1370_;
                    if (var9 == 0) {
                        var7->unknown_1b95_ = 1;
                        return;
                    }
                    var9(1);
                    return;
                }
                var5++;
                var6++;
            } while (var5 < 16);
        }
        var4++;
    } while (var4 < var2);
}
