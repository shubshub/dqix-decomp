#include <globaldefs.h>

#if defined(jpn)
#define func_020c51a4 func_020c6c70
#endif

struct Struct_0202e5d8 { unsigned int unknown_0_[12]; };
struct Struct_0202e5d8 RotationMatrixY(int angle);
extern "C" void func_020c51a4(int arg0);

// Main, originally func_02031234 (USA 0x02031234, EUR 0x02031244, JPN 0x02030d6c)
extern "C" ARM void G3_RotateY(int angle) {
    struct Mtx43_02030d84 mtx;

    if (arg0 == 0) {
        return;
    }

    var0 = RotationMatrixY(arg0);
    func_020c51a4((int)&var0);
}
