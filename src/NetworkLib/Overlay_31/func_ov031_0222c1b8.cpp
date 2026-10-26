#include <globaldefs.h>

struct Struct_ov031_0222c1b8_2 {
    unsigned char unknown_0_[0x28];
    unsigned char kind;
    unsigned char unknown_29_;
};
struct Struct_ov031_0222c1b8 {
    Struct_ov031_0222c1b8_2* entries;
    void* unknown_4_;
    void* unknown_8_;
    void* unknown_c_;
    void* first[5];
    void* second[5];
    unsigned char unknown_38_[4];
    void* unknown_3c_;
    unsigned char unknown_40_[0x12];
    unsigned char selected;
    unsigned char unknown_53_;
    unsigned char unknown_54_;
};
struct Struct_ov031_02290c8c_9 {
    unsigned char field_0;
    unsigned char unknown_1_[3];
    Struct_ov031_0222c1b8* manager;
};
struct Struct_ov031_0222c1b8_3 {
    unsigned char unknown_0_[0xf4];
    unsigned char unknown_f4_;
};
extern Struct_ov031_02290c8c_9 data_ov031_02290c8c;
extern unsigned char data_ov031_02290c90;
extern "C" int func_ov031_0223c054(int);
extern "C" int func_ov031_02222e54();
extern "C" void func_ov031_0223e2e0(int, void*);
extern "C" void func_ov031_0223da58(void*);
extern "C" void func_ov031_0223c760(void*);
extern "C" void func_ov031_02235194();
extern "C" void func_ov031_022238cc();
extern "C" void func_ov031_02223440();
extern "C" void func_ov031_02234f08();
extern "C" void func_ov031_0223b710(void*);
extern "C" void func_ov031_0223cbbc(int, int);
extern "C" void func_ov031_022357b4();
extern "C" void* func_ov031_02235c70();
extern "C" void func_ov031_02236094(int);
extern "C" void func_ov031_022274d0(int, int);
extern "C" void func_ov031_0222750c(int, int);
extern "C" void func_ov031_022274c0(int);
extern "C" void func_ov031_02235cac(void*);
extern "C" void func_ov031_02233248();
extern "C" void func_ov031_02232024();
extern "C" void func_ov031_0222cbe0();
extern "C" void func_ov031_022340c0();
extern "C" void func_ov031_0223cf70(void*);
#define REG_SCROLL (*(volatile unsigned int*)0x04000010)
#define REG_SCROLL_SUB (*(volatile unsigned int*)0x04000018)

// USA: func_ov031_0222c1b8
extern "C" ARM void func_ov031_0222c1b8() {
    if (func_ov031_0223c054(1) != 0) return;
    if (func_ov031_0223c054(0) != 0) return;
    if (func_ov031_02222e54() == 0) return;
    func_ov031_0223e2e0(1, data_ov031_02290c8c.manager->unknown_3c_);
    int i = 0;
    do {
        if (data_ov031_02290c8c.manager->first[i]) func_ov031_0223da58(data_ov031_02290c8c.manager->first[i]);
        if (data_ov031_02290c8c.manager->second[i]) func_ov031_0223da58(data_ov031_02290c8c.manager->second[i]);
    } while (++i < 5);
    func_ov031_0223c760(data_ov031_02290c8c.manager->unknown_c_);
    func_ov031_02235194();
    func_ov031_022238cc();
    func_ov031_02223440();
    func_ov031_02234f08();
    func_ov031_0223b710(data_ov031_02290c8c.manager->unknown_4_);
    func_ov031_0223b710(data_ov031_02290c8c.manager->unknown_8_);
    func_ov031_0223cbbc(1, 1);
    func_ov031_0223cbbc(0, 0x1d);
    REG_SCROLL = 0;
    REG_SCROLL_SUB = 0;
    if (data_ov031_02290c8c.manager->unknown_54_ == 0) {
        func_ov031_022357b4();
        func_ov031_02236094(((Struct_ov031_0222c1b8_3*)func_ov031_02235c70())->unknown_f4_);
        func_ov031_022274d0(2, 0);
        func_ov031_022274c0((int)func_ov031_02233248);
    } else if (data_ov031_02290c8c.field_0 == 4) {
        func_ov031_022357b4();
        func_ov031_022274d0(0, 1);
        func_ov031_022274c0((int)func_ov031_02232024);
    } else {
        func_ov031_02235cac(&data_ov031_02290c8c.manager->entries[data_ov031_02290c8c.manager->selected]);
        func_ov031_022274d0(0, 0);
        if (data_ov031_02290c8c.manager->entries[data_ov031_02290c8c.manager->selected].kind != 0) {
            func_ov031_022274d0(0, 1);
            func_ov031_0222750c(1, 1);
            func_ov031_022274c0((int)func_ov031_0222cbe0);
        } else {
            func_ov031_022274d0(0, 1);
            func_ov031_0222750c(0, 1);
            func_ov031_022274c0((int)func_ov031_022340c0);
        }
    }
    func_ov031_0223cf70(&data_ov031_02290c90);
}
