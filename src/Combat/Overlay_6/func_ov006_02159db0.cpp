// USA: func_ov006_02159db0
#include <globaldefs.h>

struct Struct_0207fdcc_2 {
#if defined(jpn)
    unsigned char unknown[0x2a];
#else
    unsigned char unknown[0x36];
#endif
    unsigned short cursor;
};
struct Struct_02015554_2 {
    unsigned short unknown_0_;
    unsigned char phase;
};
struct Struct_02081f20_2 {
    Struct_02015554_2* input;
    unsigned short state;
    signed char initialDelay;
    signed char unknown_7_;
    signed char countdown;
};
struct Struct_ov006_02159db0_2 {
    unsigned char unknown[0x38];
    unsigned char x, y, width, height;
};
struct Struct_ov006_02159db0_3 {
    unsigned char unknown[0x28];
    int unknown_28_[3];
};
struct Struct_020e280c {
    void* entries;
    void* unknown_4_;
    void* unknown_8_;
    Struct_ov006_02159db0_2* panel;
    Struct_ov006_02159db0_3* window;
};
struct SePlayer;
extern SePlayer g_sePlayer;
extern "C" int func_020813ec(void*, int);
extern "C" void func_0208203c(Struct_02081f20_2*);
extern "C" void SePlayer_Play(SePlayer*, int, int);
extern "C" void func_02080c04(Struct_0207fdcc_2*, int);
extern "C" void func_020e280c(Struct_020e280c*, void*);
extern "C" void func_020e2d24(int*, int, int);

struct Struct_ov006_02159db0 {
#if defined(jpn)
    unsigned char unknown[0xc];
    Struct_0207fdcc_2* menu;
    Struct_020e280c* choice;
    unsigned char unknown_14_[0x3c - 0x14];
    short* unknown_44_;
    unsigned char unknown_40_[0x94 - 0x40];
    Struct_02081f20_2 repeat;
    unsigned char unknown_a0_[0x35e - 0xa0];
#else
    unsigned char unknown[0x14];
    Struct_0207fdcc_2* menu;
    Struct_020e280c* choice;
    unsigned char unknown_1c_[0x44 - 0x1c];
    short* unknown_44_;
    unsigned char unknown_48_[0x9c - 0x48];
    Struct_02081f20_2 repeat;
    unsigned char unknown_a8_[0x35e - 0xa8];
#endif
    short unknown_35e_;
    unsigned char unknown_360_[0x36c - 0x360];
    short unknown_36c_;
    short group;
};

extern "C" ARM void func_ov006_02159db0(Struct_ov006_02159db0* owner) {
    SePlayer_Play(&g_sePlayer, 5, 0);
    owner->group = 7;
    owner->unknown_35e_ = owner->unknown_36c_ = 0x22;
    owner->menu->cursor = owner->unknown_36c_;
    func_020813ec(owner->menu, owner->group);
    func_0208203c(&owner->repeat);
    owner->unknown_44_ = 0;
    if (owner->choice == 0)
        return;
    func_02080c04(owner->menu, owner->group);
    func_020e280c(owner->choice, (void*)-1);
#if defined(jpn)
    Struct_ov006_02159db0_2* panel = owner->choice->panel;
    panel->x = 0xc2;
    panel->y = 0x48;
#endif
    func_020e2d24(owner->choice->window->unknown_28_, 0x18, 1);
}
