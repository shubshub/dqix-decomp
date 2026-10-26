#include <globaldefs.h>
#include <Resource/UiArrayEntry.h>
#include <NitroSDK/ColorEffects.h>

struct Struct_ov031_022492e2 { unsigned short l; unsigned short t; unsigned short r; unsigned short b; };
struct Struct_ov031_02222ce4;
struct Struct_ov031_02237b2c {
    Struct_ov031_02222ce4* unknown_0_;
    void* unknown_4_;
    Struct_ov031_02222ce4* sprites[2];
    void* panel;
    void* task;
    unsigned char unknown_18_[3];
    signed char selection;
    unsigned char style;
    unsigned char unknown_1d_;
    unsigned char flag;
    unsigned char unknown_1f_;
};
struct Struct_ov031_022492d8 {
    unsigned short width;
    unsigned short height;
    unsigned char priority[6];
};
struct Struct_ov031_0224931c { unsigned short width, height; };
extern const Struct_ov031_022492d8 data_ov031_022492d8;
extern Struct_ov031_022276b4* data_ov031_02290c4c;
extern Struct_ov031_02237b2c* data_ov031_02290d10;
extern const unsigned char data_ov031_0224938c[];
extern unsigned char data_ov031_02249394[];
extern const unsigned char data_ov031_022492fe[][2];
extern const Struct_ov031_0224931c data_ov031_0224931c[];
extern const Struct_ov031_022492e2 data_ov031_022492e2;
extern "C" void* func_ov031_0223cf4c(unsigned int, int);
extern "C" Struct_ov031_02222ce4* func_ov031_0223be70(int, int, int);
extern "C" void func_ov031_0223bbd8(Struct_ov031_02222ce4*, int, int, int);
extern "C" void func_ov031_0223bcc8(Struct_ov031_02222ce4*, int, int);
extern "C" void* func_ov031_0223c458(int, int, int, int, int*, int);
extern "C" void* func_ov031_0223b8c4(int, int, int);
extern "C" int func_ov031_022236d0();
extern "C" void func_ov031_0223c980(void*, int, int, int, int, int, int, void*);
extern "C" void func_ov031_0223ca54(void*, int, int, void*, int);
extern "C" void func_ov031_0223cd30(int, int, int, int);
extern "C" void func_ov031_0223cc18(int, int, const Struct_ov031_022492e2*);
extern "C" void func_ov031_022381c8(int);
extern "C" void* func_ov031_0223e218(void*, void*, void*, int);
extern "C" void func_ov031_02237ecc(void*);
extern "C" void func_ov031_02237f2c(void*);
#define REG_DISPCNT (*(volatile unsigned int*)0x04000000)

// USA: func_ov031_02237b2c
extern "C" ARM void func_ov031_02237b2c(int id, int style, unsigned char flag, int index, int value) {
    unsigned char priority[6] = {
        data_ov031_022492d8.priority[0], data_ov031_022492d8.priority[1],
        data_ov031_022492d8.priority[2], data_ov031_022492d8.priority[3],
        data_ov031_022492d8.priority[4], data_ov031_022492d8.priority[5]
    };
    int text = func_ov031_022276cc(data_ov031_02290c4c, id, index, value);
    data_ov031_02290d10 = (Struct_ov031_02237b2c*)func_ov031_0223cf4c(sizeof(Struct_ov031_02237b2c), 4);
    data_ov031_02290d10->style = style;
    data_ov031_02290d10->selection = -2;
    data_ov031_02290d10->flag = flag;
    ColorEffect_ConfigureBrightnessAdjust(0x04000050, 31, 0);
    data_ov031_02290d10->unknown_0_ = func_ov031_0223be70(0, data_ov031_0224938c[style], 0);
    func_ov031_0223bbd8(data_ov031_02290d10->unknown_0_, -1, 256, 0);
    func_ov031_0223bcc8(data_ov031_02290d10->unknown_0_, -1, 0);
    int i = 0;
    if (i < data_ov031_02249394[style]) {
        const unsigned char* sprite = data_ov031_022492fe[style];
        do {
            data_ov031_02290d10->sprites[i] = func_ov031_0223be70(0, *sprite++, 0);
            func_ov031_0223bbd8(data_ov031_02290d10->sprites[i], -1, 256, 0);
            func_ov031_0223bcc8(data_ov031_02290d10->sprites[i], -1, 0);
            i++;
        } while (i < data_ov031_02249394[style]);
    }
    int var4;
    data_ov031_02290d10->panel = func_ov031_0223c458(0, 32, 12, 1, &var4, 0);
    data_ov031_02290d10->unknown_4_ = func_ov031_0223b8c4(0, var4, 0);
    int var5 = func_ov031_022236d0();
    func_ov031_0223c980(data_ov031_02290d10->panel, 0, 0,
        data_ov031_0224931c[style].width, data_ov031_0224931c[style].height,
        2, var5, (void*)text);
    func_ov031_0223ca54(data_ov031_02290d10->panel, 256, 0, data_ov031_02290d10->unknown_4_, 0);
    func_ov031_0223cd30(0, 0, 31, 0);
    func_ov031_0223cd30(0, 1, 31, priority[data_ov031_02290d10->style]);
    func_ov031_0223cd30(0, 3, 31, 1);
    func_ov031_0223cc18(0, 1, &data_ov031_022492e2);
    func_ov031_022381c8(192);
    REG_DISPCNT = (REG_DISPCNT & ~0xe000) | 0x6000;
    if (flag) data_ov031_02290d10->task = func_ov031_0223e218((void*)1, (void*)func_ov031_02237ecc, 0, 120);
    else data_ov031_02290d10->task = func_ov031_0223e218((void*)1, (void*)func_ov031_02237f2c, 0, 120);
}
