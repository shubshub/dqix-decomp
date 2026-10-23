#include <globaldefs.h>

extern "C" void func_0203ac40(void*, int, int, int);

struct SePlayer {
    char pad_00[0xb4];
    short field_b4;
};

// Main, originally DispatchWithShortB4_0205eaa0 (USA 0x0205eaa0, EUR 0x0205eab0, JPN 0x0205fd8c)
ARM void SePlayer_Play(struct SePlayer* obj, int a, int b) {
    func_0203ac40(obj, obj->field_b4, a, b);
}
