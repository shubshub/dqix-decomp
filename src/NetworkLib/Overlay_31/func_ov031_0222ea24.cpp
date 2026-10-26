#include <globaldefs.h>

struct Struct_ov031_0222ea24_3 {
    unsigned char unknown_0_[0xe7];
    unsigned char kind;
    unsigned char unknown_e8_[0xc];
    unsigned char unknown_f4_;
    unsigned char unknown_f5_;
    unsigned char unknown_f6_;
};
struct Struct_ov031_0222ea24 {
    unsigned int field_0;
    unsigned short flags;
};
struct Struct_ov031_0222ea24_2 {
    void* field_0;
    unsigned char unknown_4_[0x10];
    void* display;
    Struct_ov031_0222ea24* sprites[7];
    Struct_ov031_0222ea24* selected;
    void* unknown_38_;
    void* unknown_3c_;
    unsigned char unknown_40_[2];
    unsigned char unknown_42_;
    unsigned char unknown_43_;
    unsigned char unknown_44_;
    unsigned char unknown_45_[3];
};
struct Struct_ov031_02290ca0 {
    unsigned char field_0;
    unsigned char unknown_1_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    Struct_ov031_0222ea24_2* manager;
};
extern Struct_ov031_02290ca0 data_ov031_02290ca0;
extern signed char data_ov031_02249034[];
extern "C" Struct_ov031_0222ea24_3* func_ov031_02235c70();
extern "C" Struct_ov031_0222ea24_2* func_ov031_0223cf4c(int, int);
extern "C" void func_ov031_0222ee34();
extern "C" void func_ov031_0222ec20();
extern "C" int func_ov031_02227548();
extern "C" void func_ov031_0222336c(int, int, int);
extern "C" void func_ov031_02223518(int);
extern "C" void func_ov031_02223a0c();
extern "C" void func_ov031_022350bc(int, int, int, int, int);
extern "C" void* func_ov031_0223c560(int, int);
extern "C" Struct_ov031_0222ea24* func_ov031_0223be44(int, int);
extern "C" void* func_ov031_0223e218(void*, void*, void*, int);
extern "C" void func_ov031_02230778();
extern "C" void func_ov031_02230cd8();
extern "C" void func_ov031_0222f9ec();
extern "C" void func_ov031_022307fc();
extern "C" void func_ov031_0222ee70();
extern "C" void func_ov031_022274c0(int);

// USA: func_ov031_0222ea24
extern "C" ARM void func_ov031_0222ea24() {
    Struct_ov031_0222ea24_3* block = func_ov031_02235c70();
    data_ov031_02290ca0.manager = func_ov031_0223cf4c(0x48, 4);
    data_ov031_02290ca0.manager->unknown_43_ = block->unknown_f6_;
    data_ov031_02290ca0.manager->unknown_42_ = 12;
    func_ov031_0222ee34();
    func_ov031_0222ec20();
    if (data_ov031_02290ca0.unknown_1_ == 0) {
        func_ov031_0222336c(0x30, data_ov031_02249034[func_ov031_02227548()], block->unknown_f4_ + 1);
    } else {
        func_ov031_0222336c(0x45, -1, 0);
    }
    func_ov031_02223518(1);
    func_ov031_02223a0c();
    int var1 = data_ov031_02290ca0.unknown_4_ * 55;
    int var2 = var1 / 145;
    func_ov031_022350bc(2, 0x55, 0xf1, 0x41, var2);
    data_ov031_02290ca0.manager->display = func_ov031_0223c560(0, 1);
    int i = 0;
    do {
        data_ov031_02290ca0.manager->sprites[i] = func_ov031_0223be44(0, 0x29);
    } while (++i < 7);
    switch (block->kind) {
    case 1:
        data_ov031_02290ca0.manager->selected = func_ov031_0223be44(0, 0x50);
        data_ov031_02290ca0.manager->selected->flags = (data_ov031_02290ca0.manager->selected->flags & ~0xc00) | 0xc00;
        break;
    case 2:
        data_ov031_02290ca0.manager->selected = func_ov031_0223be44(0, 0x51);
        data_ov031_02290ca0.manager->selected->flags = (data_ov031_02290ca0.manager->selected->flags & ~0xc00) | 0xc00;
        break;
    }
    data_ov031_02290ca0.manager->unknown_3c_ = func_ov031_0223e218((void*)1, (void*)func_ov031_02230778, 0, 0x6e);
    data_ov031_02290ca0.manager->field_0 = func_ov031_0223e218(0, (void*)func_ov031_02230cd8, 0, 0x78);
    func_ov031_0222f9ec();
    func_ov031_022307fc();
    func_ov031_022274c0((int)func_ov031_0222ee70);
}
