#include <globaldefs.h>

struct Struct_020b1d48_2 {
    int field0;
    int width;
    int height;
    unsigned char format;
    unsigned char unknown_d_[3];
    int stride;
    void* unknown_14_;
    Struct_020b1d48_2* self;
    void* layer;
    int field20;
    int field24;
    int buffer;
    void* request;
};
struct Struct_020b1d48 { unsigned char data[8]; };
struct Struct_ov031_0223c560 {
    Struct_020b1d48 layers[0x610 / 8];
    Struct_020b1d48_2 backgrounds[2];
    unsigned char unknown_670_[0xc];
    unsigned char unknown_67c_[2];
};
struct Struct_ov031_022493b0 { unsigned short value; unsigned short padding; };
extern Struct_ov031_0223c560* data_ov031_02290d38;
extern Struct_ov031_022493b0 data_ov031_022493b2[];
extern Struct_ov031_022493b0 data_ov031_022493b0[];
extern const unsigned short data_ov031_022493ac[];
extern "C" int func_ov031_0223cf4c(unsigned int, int);
extern "C" void func_020b1e94(Struct_020b1d48_2*, int, int, int, int);
extern "C" void* GetSubBG0ScreenBase();
extern "C" void* GetMainBG0ScreenBase();
extern "C" void func_020b1f48(void*, int, int, int, int, int, int, int);
extern "C" void func_ov031_0223ca40(Struct_020b1d48_2*, int);
extern "C" void func_ov031_0223c6d8();
extern "C" void* func_ov031_0223e218(void*, void*, void*, int);
#define REG_SUB_BG0CNT (*(volatile unsigned short*)0x04001008)
#define REG_MAIN_BG0CNT (*(volatile unsigned short*)0x04000008)

// USA: func_ov031_0223c560
extern "C" ARM Struct_020b1d48_2* func_ov031_0223c560(int screen, int layer) {
    unsigned short height = data_ov031_022493b2[screen].value;
    unsigned short width = data_ov031_022493b0[screen].value;
    Struct_020b1d48_2* background = &data_ov031_02290d38->backgrounds[screen];
    background->buffer = func_ov031_0223cf4c(width * height * 0x20, 0x20);
    if (screen == 1) {
        REG_SUB_BG0CNT &= ~0x40;
        REG_SUB_BG0CNT = (REG_SUB_BG0CNT & 0x43) | 0xc00;
    } else {
        REG_MAIN_BG0CNT &= ~0x40;
        REG_MAIN_BG0CNT = (REG_MAIN_BG0CNT & 0x43) | 0xc00;
    }
    func_020b1e94(background, background->buffer, width, height, 4);
    void* var3 = &data_ov031_02290d38->layers[layer];
    background->self = background;
    background->layer = var3;
    background->field20 = 1;
    background->field24 = 1;
    void* screenBase = screen == 1 ? GetSubBG0ScreenBase() : GetMainBG0ScreenBase();
    int tile = data_ov031_022493ac[screen];
    func_020b1f48(screenBase, width, height, 0, 0, 0x20, tile, 0xf);
    func_ov031_0223ca40(background, 0);
    background->request = func_ov031_0223e218((void*)1, (void*)func_ov031_0223c6d8, &data_ov031_02290d38->unknown_67c_[screen], 0xc8);
    return background;
}
