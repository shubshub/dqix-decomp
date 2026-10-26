#include <globaldefs.h>
#include "NitroSDK/LoadToVRAM.h"

struct Struct_ov031_02248e43 { char text[25]; };
struct Struct_ov031_02248e2d { char text[22]; };
extern const Struct_ov031_02248e43 data_ov031_02248e43;
extern const Struct_ov031_02248e2d data_ov031_02248e2d;
extern char data_ov031_0224b9f4[];
extern "C" void func_ov031_022234d8(void*, void (*)(const void*, unsigned int, unsigned int));
extern "C" void* func_ov031_02223478(const char*);
extern "C" void* func_ov031_0223b61c(void*, int, int);
extern "C" void func_ov031_02234ea8(void*);
extern "C" void func_ov031_02234f34();

struct Struct_ov031_0222b71c {
    int unknown_0_;
    void* first;
    void* second;
};
struct Struct_ov031_02290c8c_2 {
    int unknown_0_;
    Struct_ov031_0222b71c* resources;
};
extern Struct_ov031_02290c8c_2 data_ov031_02290c8c;

struct Struct_ov031_0222b71c_2 {
    unsigned short priority : 2;
    unsigned short remaining : 14;
};
struct Struct_ov031_0222b71c_3 { Struct_ov031_0222b71c_2 controls[4]; };
#define MAIN_BG_0222b71c (*(volatile Struct_ov031_0222b71c_3*)0x04000008)
#define SUB_BG_0222b71c (*(volatile Struct_ov031_0222b71c_3*)0x04001008)

// USA: func_ov031_0222b71c
extern "C" ARM void func_ov031_0222b71c() {
    Struct_ov031_02248e43 var0 = data_ov031_02248e43;
    Struct_ov031_02248e2d var1 = data_ov031_02248e2d;
    func_ov031_022234d8(data_ov031_0224b9f4, LoadToMainBG3ScreenData);
    data_ov031_02290c8c.resources->first = func_ov031_0223b61c(func_ov031_02223478(var0.text), 0, 4);
    func_ov031_02234ea8(data_ov031_02290c8c.resources->first);
    func_ov031_02234f34();
    data_ov031_02290c8c.resources->second = func_ov031_0223b61c(func_ov031_02223478(var1.text), 0, 4);
    SUB_BG_0222b71c.controls[0].priority = 3;
    SUB_BG_0222b71c.controls[1].priority = 3;
    MAIN_BG_0222b71c.controls[0].priority = 3;
    MAIN_BG_0222b71c.controls[1].priority = 2;
    MAIN_BG_0222b71c.controls[2].priority = 3;
    MAIN_BG_0222b71c.controls[3].priority = 2;
}
