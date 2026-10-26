#include <globaldefs.h>

struct Struct_020f1f2c {
    unsigned int start;
    unsigned int end;
    int active;
    int flag;
    unsigned short pair;
    unsigned short field12;
    unsigned int base;
};
#if defined(jpn)
#define data_020f1f44 data_020f20b0
#define data_020f1ef8 data_020f2064
#define data_020f1f00 data_020f206c
#endif
extern Struct_020f1f2c data_020f1f44;
extern Struct_020f1f2c data_020f1f2c;
extern Struct_020f1f2c* data_020f1ef8[2];
extern Struct_020f1f2c* data_020f1f00[5];
static inline unsigned int inline_020bb588(const Struct_020f1f2c* slot) {
    return slot->end - slot->start;
}

// Main, originally func_020bb588 (USA 0x020bb588, EUR 0x020bb598, JPN 0x020bd054)
extern "C" ARM unsigned int NNS_GfdAllocFrmTexVram(unsigned int size, unsigned int fromFront) {
    unsigned int address;
    unsigned int aligned;
    int allocated;
    if (size == 0) aligned = 16;
    else aligned = (size + 15) & ~15;
    if (aligned >= 0x7fff0) return 0;
    if (fromFront != 0) {
        Struct_020f1f2c* pair;
        Struct_020f1f2c* slot;
        int i;
        i = 0;
        do {
            slot = data_020f1ef8[i];
            if (!slot->active || inline_020bb588(slot) < aligned) goto nextFront;
            switch (slot->pair) {
            case 0: pair = &data_020f1f2c; break;
            case 3: pair = &data_020f1f44; break;
            default: pair = 0; break;
            }
            if (!pair->active || inline_020bb588(pair) < (aligned >> 1)) goto nextFront;
            unsigned int start = slot->start;
            slot->start += aligned;
            pair->start += aligned >> 1;
            address = start + slot->base;
            allocated = 1;
            goto complete;
nextFront:
            i++;
        } while (i < 2);
        allocated = 0;
    } else {
        int i = 0;
        do {
            Struct_020f1f2c* slot = data_020f1f00[i];
            if (!slot->active || inline_020bb588(slot) < aligned) goto nextBack;
            slot->end -= aligned;
            address = slot->end + slot->base;
            allocated = 1;
            goto complete;
nextBack:
            i++;
        } while (i < 5);
        allocated = 0;
    }
complete:
    if (!allocated) return 0;
    unsigned short offset = address >> 3;
    return ((aligned >> 4) << 16) | offset | (fromFront << 31);
}
