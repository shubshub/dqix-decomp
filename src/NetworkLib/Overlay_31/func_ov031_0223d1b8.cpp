#include <globaldefs.h>
#include "NitroSDK/TouchScreen.h"

typedef struct Struct_ov031_0223d1b8 Struct_ov031_0223d1b8;
struct Struct_ov031_0223d1b8 {
    unsigned short v[2];
};

typedef struct Struct_ov031_0223d1b8_2 Struct_ov031_0223d1b8_2;
struct Struct_ov031_0223d1b8_2 {
    TouchScreenSample samples[5];
    Struct_ov031_0223d1b8 cur;
    Struct_ov031_0223d1b8 prev;
    unsigned short mask;
    unsigned short pressed;
    unsigned short unknown_34_;
    unsigned short unknown_36_;
    unsigned char touch : 1;
    unsigned char unknown_38_1_ : 1;
    unsigned char unknown_38_2_ : 1;
    unsigned char unknown_38_3_ : 1;
    unsigned char unknown_38_4_ : 4;
};

typedef struct Struct_ov031_02290d40_2 Struct_ov031_02290d40_2;
struct Struct_ov031_02290d40_2 {
    unsigned char enabled;
    unsigned char unknown_1_;
    unsigned char pad[2];
    Struct_ov031_0223d1b8_2* inner;
};

extern Struct_ov031_02290d40_2 data_ov031_02290d40;

extern "C" void func_ov031_0223cb10(unsigned short a, unsigned short b, Struct_ov031_0223d1b8* out);
extern "C" int FastIntModulus(int a, int b);

// USA: func_ov031_0223d1b8
extern "C" ARM void func_ov031_0223d1b8(void) {
    int i;
    unsigned char found;
    int prev;
    int idx;
    TouchScreenSample var4;

    prev = data_ov031_02290d40.inner->touch ? 1 : 0;
    found = 0;
    idx = GetCurrentTouchScreenSampleIndex();
    data_ov031_02290d40.inner->prev = data_ov031_02290d40.inner->cur;
    i = 0;
    do {
        TouchScreenSample* s = &data_ov031_02290d40.inner->samples[idx];
        if (s->isHeld == 1 && s->missingCoordFlags == 0) {
            found = 1;
            ConvertTouchScreenSampleToPixels(&var4, s);
            func_ov031_0223cb10(var4.x, var4.y, &data_ov031_02290d40.inner->cur);
            break;
        }
        i++;
        idx = FastIntModulus(idx + 4, 5);
    } while (i < 4);

    data_ov031_02290d40.inner->unknown_38_1_ = found & (found ^ prev);
    data_ov031_02290d40.inner->unknown_38_3_ = prev & (found ^ prev);
    data_ov031_02290d40.inner->touch = found;
    data_ov031_02290d40.inner->unknown_38_2_ = data_ov031_02290d40.inner->unknown_38_1_;

    if (!found) {
        data_ov031_02290d40.unknown_1_ = 0;
        return;
    }
    if (++data_ov031_02290d40.unknown_1_ == 0x28) {
        data_ov031_02290d40.inner->unknown_38_2_ = 1;
    } else if (data_ov031_02290d40.unknown_1_ == 0x2f) {
        data_ov031_02290d40.inner->unknown_38_2_ = 1;
        data_ov031_02290d40.unknown_1_ = 0x28;
    }
}
