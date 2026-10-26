#include <globaldefs.h>

extern "C" int WindowPane_IsOpen(unsigned char* window);
struct Struct_0204aa28;
extern "C" unsigned int func_0204aa28(Struct_0204aa28* layout);

struct Struct_02081e18 {
    char unknown0[0x1c];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
};

struct Struct_02081e18_2 {
    char unknown0[4];
    Struct_02081e18* layout;
    char unknown8[0xa0 - 8];
    unsigned int unknown_a0_;
    unsigned int unknown_a4_;
    char unknown_a8_[0xe0 - 0xa8];
};

struct Struct_020813ec {
#if defined(jpn)
    char unknown0[0x20];
#else
    char unknown0[0x2c];
#endif
    int unknown_2c_;
    Struct_02081e18_2* windows;
    char unknown34[5];
    unsigned char unknown_39_;
};

extern "C" ARM unsigned int func_02081e18(Struct_020813ec* menu, int arg1) {
    if (menu->unknown_2c_ == 0 || menu->windows == 0) return 0;
    Struct_02081e18_2* window;
    int i;
    for (i = (int)menu->unknown_39_ - 1; i >= 0; i--) {
        window = &menu->windows[i];
        if (WindowPane_IsOpen(reinterpret_cast<unsigned char*>(window)) && window->layout) {
            Struct_02081e18* layout = window->layout;
            if (arg1 == layout->unknown_1c_4_) {
                return window->unknown_a0_ + window->unknown_a4_;
            }
        }
    }
    return func_0204aa28(reinterpret_cast<Struct_0204aa28*>(menu->windows->layout));
}
