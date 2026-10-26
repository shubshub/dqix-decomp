#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#if defined(jpn)
#define func_ov008_0218712c func_ov008_02188008
#endif

#include "std_library_functions.h"

struct Struct_ov008_0218712c {
    unsigned char unknown_0_[0xb8];
    void* buffer;
    unsigned char unknown_bc_[0x130 - 0xbc];
    unsigned char renderer[0xa0];
    short dimensions[8];
    unsigned char unknown_1e0_;
    unsigned char pass;
    unsigned char unknown_1e2_[3];
    unsigned char enabled;
    unsigned char visible;
    unsigned char count;
};

extern "C" {
    void func_ov008_02187278(Struct_ov008_0218712c*, void*, int, void*);
#if defined(jpn)
    void Window_OpenPane(void*, void*, int, int, bool, bool, void*);
#else
    void Window_OpenPane(void*, void*, int, int, bool, bool, void*, bool);
#endif

    void func_ov008_0218712c(Struct_ov008_0218712c* menu, void* arg1) {
        menu->dimensions[0] = LOW_REGION(10, 5);
        menu->dimensions[1] = 2;
        menu->dimensions[2] = LOW_REGION(1, 7);
        menu->dimensions[3] = LOW_REGION(6, 7);
        menu->dimensions[4] = 2;
        menu->dimensions[5] = 4;
        menu->dimensions[6] = 10;
        menu->dimensions[7] = 16;
        menu->count = 10;
        menu->pass = 1;
        menu->enabled = 1;
        menu->visible = 1;
        memset(menu->buffer, 0, LOW_REGION(0x800, 0x960));
        func_ov008_02187278(menu, menu->buffer, 0, arg1);
#if defined(jpn)
        Window_OpenPane(menu->renderer, menu->buffer, 0, 0, false, false, 0);
#else
        Window_OpenPane(menu->renderer, menu->buffer, 0, 0, false, false, 0, false);
#endif

        menu->dimensions[0] = LOW_REGION(10, 5);
        menu->dimensions[1] = 2;
        menu->dimensions[2] = LOW_REGION(1, 7);
        menu->dimensions[3] = LOW_REGION(11, 12);
        menu->dimensions[4] = 2;
        menu->dimensions[5] = 4;
        menu->dimensions[6] = 10;
        menu->dimensions[7] = 16;
        menu->count = 10;
        menu->pass = 2;
        menu->enabled = 1;
        menu->visible = 1;
        memset(menu->buffer, 0, LOW_REGION(0x800, 0x960));
        func_ov008_02187278(menu, menu->buffer, 1, arg1);
#if defined(jpn)
        Window_OpenPane(menu->renderer, menu->buffer, 0, 0, false, false, 0);
#else
        Window_OpenPane(menu->renderer, menu->buffer, 0, 0, false, false, 0, false);
#endif
    }
}
