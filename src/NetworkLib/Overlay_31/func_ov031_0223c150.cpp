#include <globaldefs.h>
#include "NitroSDK/ColorEffects.h"
#include "NitroSDK/Matrix.h"

struct Struct_ov031_0223c150 {
    void* task;
    short frame;
    unsigned short duration;
    unsigned char mode;
    unsigned char active;
    unsigned char padding[2];
};
extern unsigned char data_ov031_022493a0[];
extern Struct_ov031_0223c150* data_ov031_02290d34;
extern "C" void func_ov031_0223e2c0(int, void*);

// USA: func_ov031_0223c150
extern "C" ARM void func_ov031_0223c150(void* object, Struct_ov031_0223c150* fade) {
    unsigned char flags[4] = { data_ov031_022493a0[4], data_ov031_022493a0[5], data_ov031_022493a0[6], data_ov031_022493a0[7] };
    signed char var1[4] = { data_ov031_022493a0[0], data_ov031_022493a0[1], data_ov031_022493a0[2], data_ov031_022493a0[3] };
    fade->frame++;
    int brightness = FastIntDivide(fade->frame << 4, fade->duration);
    unsigned char mode = flags[fade->mode];
    if (mode & 1) brightness = 16 - brightness;
    if (mode & 16) brightness = -brightness;
    if (fade == data_ov031_02290d34) ColorEffect_ChangeBrightness(0x04001050, brightness);
    else ColorEffect_ChangeBrightness(0x04000050, brightness);
    if (fade->frame >= fade->duration) {
        if (fade == data_ov031_02290d34) ColorEffect_ChangeBrightness(0x04001050, var1[fade->mode]);
        else ColorEffect_ChangeBrightness(0x04000050, var1[fade->mode]);
        fade->active = 0;
        func_ov031_0223e2c0(1, object);
    }
}
