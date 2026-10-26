#include "globaldefs.h"

#if defined(jpn)
enum { WindowOffset = 0xe20, Enum_ov002_0215be00_7096 = 0x1a80, Enum_ov002_0215be00_21 = 22, Enum_ov002_0215be00_13 = 14, Enum_ov002_0215be00_11 = 12, Enum_ov002_0215be00_17 = 14, Enum_ov002_0215be00_38 = 41 };
#define data_ov002_0216cb48 data_ov002_0216d150
#else
enum { WindowOffset = 0xec8, Enum_ov002_0215be00_7096 = 0x1bb8, Enum_ov002_0215be00_21 = 21, Enum_ov002_0215be00_13 = 13, Enum_ov002_0215be00_11 = 11, Enum_ov002_0215be00_17 = 17, Enum_ov002_0215be00_38 = 38 };
#endif

struct Struct_ov002_0216cb48 {
    unsigned char id, width, height;
    signed char x, y;
    unsigned char unknown_5_, unknown_6_;
};
struct Struct_ov002_0215be00 {
    unsigned char unknown_0_[0xa0];
    short x, y, unknown_a4_, unknown_a6_;
    short width, height, unknown_ac_, unknown_ae_;
    unsigned char unknown_b0_, preset, unknown_b2_[3], active, unknownB6, frames;
    inline void inline_ov002_0215be00(short a, short b) { width = a; height = b; }
    inline void inline_ov002_0215be00_2(short a, short b) { x = a; y = b; }
    inline void inline_ov002_0215be00_3(short a, short b) { unknown_ac_ = a; unknown_ae_ = b; }
};
struct Struct_ov002_0215be00_2 {
    unsigned char unknown_0_[WindowOffset];
    Struct_ov002_0215be00 parameters;
    unsigned char unknown_f80_[Enum_ov002_0215be00_7096 - WindowOffset - sizeof(Struct_ov002_0215be00)];
    int mode;
};
extern "C" const Struct_ov002_0216cb48 data_ov002_0216cb48[];
extern "C" void func_ov002_02156080(void*, short*, short*);

// USA: func_ov002_0215be00
// JPN: func_ov002_0215cf30
extern "C" ARM void func_ov002_0215be00(Struct_ov002_0215be00_2* state, int id, short arg2, short arg3) {
    for (int i = 0; data_ov002_0216cb48[i].id != 255; ++i) {
        const Struct_ov002_0216cb48* preset = &data_ov002_0216cb48[i];
        if (preset->id != id) continue;
        Struct_ov002_0215be00* parameters = &state->parameters;
        parameters->preset = preset->id;
        parameters->unknown_a4_ = arg2;
        parameters->unknown_a6_ = arg3;
        parameters->inline_ov002_0215be00(preset->width, preset->height);
        parameters->inline_ov002_0215be00_2(preset->x, preset->y);
        parameters->inline_ov002_0215be00_3(preset->unknown_5_, preset->unknown_6_);
        parameters->active = 1;
        if (preset->id == Enum_ov002_0215be00_21) {
            short entries[9], height;
            short displacement = 0;
            func_ov002_02156080(state, entries, &height);
            if (height < 8) {
                displacement = (8 - height) * 2;
            } else {
                parameters->inline_ov002_0215be00(preset->width, preset->height + 1);
            }
            if (displacement < 0) displacement = 0;
            parameters->inline_ov002_0215be00_2(preset->x, preset->y - displacement);
        }
        if (preset->id == Enum_ov002_0215be00_13 && state->mode == Enum_ov002_0215be00_11) {
            parameters->x = Enum_ov002_0215be00_17;
            parameters->y = 16;
        }
        int frames = 10;
        if (id == Enum_ov002_0215be00_38) frames = 12;
        parameters->frames = frames;
        break;
    }
}

#if defined(jpn)
#undef data_ov002_0216cb48
#endif
