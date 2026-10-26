#include <globaldefs.h>

extern "C" void InvalidateDataCacheRange(const void* addr, unsigned int len);
extern "C" int memcmp(const void* a, const void* b, unsigned int len);

typedef void (*Type_ov031_022378e4)(int);

struct Struct_ov031_022378e4 {
    char name[6];
    unsigned char inUse;
};

struct Struct_ov031_022378e4_2 {
    unsigned char unknown_0_[0xf00];
    unsigned char unknown_f00_[0x400];
    Struct_ov031_022378e4 slots[16];
    Type_ov031_022378e4 callback;
    unsigned char unknown_1374_[0x821];
    unsigned char pending;
};

struct Struct_ov031_022378e4_3 {
    unsigned char unknown_0_[4];
    char name[6];
    unsigned char unknown_a_[2];
    unsigned char signature[8];
    unsigned char unknown_14_[1];
    unsigned char flags;
};

struct Struct_ov031_022378e4_4 {
    unsigned char unknown_0_[0xe];
    unsigned short count;
    Struct_ov031_022378e4_3* unknown_10_[1];
};

extern Struct_ov031_022378e4_2* data_ov031_02290d0c;
extern char data_ov031_02249288[];

// USA: func_ov031_022378e4
extern "C" ARM void func_ov031_022378e4(Struct_ov031_022378e4_4* list) {
    Struct_ov031_022378e4_2* state = data_ov031_02290d0c;
    unsigned char pending = state->pending;
    int count;
    Struct_ov031_022378e4_3* peer;
    int i;
    int j;
    Struct_ov031_022378e4* slot;
    Struct_ov031_022378e4_2* var7;

    if (pending != 0) {
        Type_ov031_022378e4 notify = state->callback;
        if (notify != 0) {
            notify(pending);
        }
        return;
    }
    InvalidateDataCacheRange(state->unknown_f00_, 0x400);

    count = list->count;
    i = 0;
    if (count <= 0) {
        return;
    }
    var7 = data_ov031_02290d0c;
    do {
        peer = list->unknown_10_[i];
        if (memcmp(peer->signature, data_ov031_02249288, 8) == 0 && (peer->flags & 1) != 0) {
            slot = var7->slots;
            j = 0;
            do {
                if (memcmp(peer->name, slot->name, 6) == 0) {
                    Type_ov031_022378e4 notify;
                    if (var7->slots[j].inUse != 0) {
                        break;
                    }
                    notify = var7->callback;
                    if (notify == 0) {
                        var7->pending = 1;
                        return;
                    }
                    notify(1);
                    return;
                }
                j++;
                slot++;
            } while (j < 16);
        }
        i++;
    } while (i < count);
}
