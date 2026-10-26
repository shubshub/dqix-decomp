#include <globaldefs.h>
#include "NitroSDK/Memory.h"

struct Struct_021016e0 {
    unsigned char pad0[0x3c];
    unsigned short unknown_3c_;
    unsigned char unknown_3e_[2];
    unsigned short mode;
    unsigned char unknown_42_[2];
    unsigned int unknown_44_;
    unsigned char unknown_48_[3];
    unsigned char flags;
    unsigned char unknown_4c_[0x74];
};
struct Struct_0202cefc {
    unsigned char pad0[2];
    unsigned short error;
    unsigned char pad4[4];
    unsigned short type;
    unsigned char unknown_a_[4];
    unsigned short count;
    Struct_021016e0* entries[1];
};
struct Struct_021015a0_2 {
    unsigned char pad0[4];
    unsigned short active;
    unsigned char pad6[0xa];
    int state;
    unsigned char unknown_14_[8];
    int check;
    unsigned char pad20[0x24];
    void (*callback)(Struct_021016e0*);
};
struct Struct_02101640 {
    unsigned char pad0[8];
    unsigned int unknown_8_;
};
extern Struct_021015a0_2 data_021015a0;
extern unsigned char data_02101b80[0x400];
extern Struct_02101640 data_02101640;
extern Struct_021016e0 data_021016e0;
extern "C" void func_0202c848(int);
extern "C" int func_0202d0e0();
extern "C" void InvalidateDataCacheRange(const void*, unsigned int);
extern "C" int func_020c0290(Struct_021016e0*);
extern "C" int func_0202cddc();
static inline int inline_0202cefc(Struct_021016e0* entry) { return entry->mode == 1; }

// USA: func_0202cefc
extern "C" ARM void func_0202cefc(Struct_0202cefc* arg0) {
    if (arg0->error != 0) {
        func_0202c848(arg0->error);
        data_021015a0.state = 9;
        return;
    }
    if (data_021015a0.state != 2) {
        data_021015a0.active = 0;
        if (!func_0202d0e0()) data_021015a0.state = 9;
        return;
    }
    if (arg0->type != 4 && arg0->type == 5) {
        if (arg0->count != 0) InvalidateDataCacheRange(data_02101b80, 0x400);
        int index;
        int found = 0;
        index = 0;
        for (; index < arg0->count; index++) {
            Struct_021016e0* entry = arg0->entries[index];
            if (data_021015a0.check != 0 && func_020c0290(entry)) {
                if (data_021015a0.callback) data_021015a0.callback(entry);
            } else {
                int var3 = 0;
                if (entry->unknown_3c_ >= 0x10) var3 = inline_0202cefc(entry);
                if (var3 == 0) continue;
                if (entry->unknown_44_ != data_02101640.unknown_8_) continue;
                switch (entry->flags & 3) {
                case 1:
                    VectorizedInvertedMemcpy(entry, &data_021016e0, 0xc0);
                    found = 1;
                    goto finished;
                }
            }
        }
finished:
        if (found) {
            if (data_021015a0.callback) data_021015a0.callback(&data_021016e0);
            if (data_021015a0.active != 0) {
                if (!func_0202d0e0()) data_021015a0.state = 9;
                return;
            }
        }
    }
    if (!func_0202cddc()) data_021015a0.state = 9;
}
