#include <globaldefs.h>

struct Struct_ov031_02237ecc_2 {
    unsigned short flags;
    unsigned short unk2;
    unsigned short value;
};
extern "C" ARM void ColorEffect_ChangeBrightness(struct Struct_ov031_02237ecc_2* dst, int value);

struct Struct_ov031_02238588 { unsigned char pad[0x1a]; signed char unknown_1a_; };
extern Struct_ov031_02238588* data_ov031_02290d10;

struct Struct_ov031_02238588_2 { unsigned char pad[8]; int field8; };
extern "C" void func_ov031_0223e2b8(struct Struct_ov031_02238588_2* obj, int v);

extern "C" void func_ov031_022385e4(void);

// USA: func_ov031_02238588
extern "C" ARM void func_ov031_02238588(void* param0) {
    data_ov031_02290d10->unknown_1a_++;
    ColorEffect_ChangeBrightness((Struct_ov031_02237ecc_2*)0x4000050, data_ov031_02290d10->unknown_1a_);
    if (data_ov031_02290d10->unknown_1a_ < 0) {
        return;
    }
    func_ov031_0223e2b8((struct Struct_ov031_02238588_2*)param0, (int)func_ov031_022385e4);
}
