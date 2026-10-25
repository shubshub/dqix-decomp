#if defined(jpn)
#define EQUIPMENT_PANEL_OFFSET 0xee0
#define EQUIPMENT_MESSAGE_OFFSET 0x3d49
enum { Enum_ov005_021589f4_2048 = 0x800 };
#else
#define EQUIPMENT_PANEL_OFFSET 0xee4
#define EQUIPMENT_MESSAGE_OFFSET 0x3dd1
enum { Enum_ov005_021589f4_2400 = 0x960 };
#endif
#include <globaldefs.h>
#include <std_library_functions.h>

extern "C" void* __clear(void* arg0, int arg1);
extern "C" int func_ov005_02158b3c(void* arg0, void* arg1);
#if defined(jpn)
extern "C" void Window_OpenPane(void* renderer, void* buffer, int a, int b, bool c, bool d, void* styles);
#else
extern "C" void Window_OpenPane(void* renderer, void* buffer, int a, int b, bool c, bool d, void* styles, bool e);
#endif

struct Struct_ov005_021589f4 {
    unsigned char unknown_0_[0xa0];
    short unknown_a0_, unknown_a2_, unknown_a4_, unknown_a6_;
    short unknown_a8_, unknown_aa_, unknown_ac_, unknown_ae_;
    unsigned char unknown_b0_, unknown_b1_, unknown_b2_, unknown_b3_, unknown_b4_, unknown_b5_, unknown_b6_, unknown_b7_;
};

struct Struct_ov005_021589f4_2 {
    char unknown_0_[0xe10];
    char* unknown_e10_;
    char unknown_e14_[EQUIPMENT_PANEL_OFFSET - 0xe14];
    Struct_ov005_021589f4 unknown_ee4_;
    char unknown_f9c_[EQUIPMENT_MESSAGE_OFFSET - EQUIPMENT_PANEL_OFFSET - sizeof(Struct_ov005_021589f4)];
    unsigned char unknown_3dd1_;
};

#if defined(jpn)
// USA: func_ov005_021589f4
extern "C" ARM void func_ov005_021589f4(Struct_ov005_021589f4_2* arg0) {
    unsigned int var0 = arg0->unknown_3dd1_;
    int var1 = 1;
    Struct_ov005_021589f4* var2 = &arg0->unknown_ee4_;
    if (var0 >= 8 && var0 <= 14) {
        arg0->unknown_ee4_.unknown_a0_ = 32;
        arg0->unknown_ee4_.unknown_a2_ = 9;
        var1 = 0;
        arg0->unknown_ee4_.unknown_a4_ = 0;
        arg0->unknown_ee4_.unknown_a6_ = 15;
        arg0->unknown_ee4_.unknown_ac_ = 12;
        arg0->unknown_ee4_.unknown_ae_ = 20;
        arg0->unknown_ee4_.unknown_b7_ = 12;
        arg0->unknown_ee4_.unknown_a8_ = 12;
        arg0->unknown_ee4_.unknown_aa_ = 11;
    } else {
        arg0->unknown_ee4_.unknown_a0_ = 24;
        arg0->unknown_ee4_.unknown_a2_ = 4;

        arg0->unknown_ee4_.unknown_a4_ = 4;
        arg0->unknown_ee4_.unknown_a6_ = 10;
        arg0->unknown_ee4_.unknown_ac_ = 10;
        arg0->unknown_ee4_.unknown_ae_ = 14;
        arg0->unknown_ee4_.unknown_b7_ = 10;
        arg0->unknown_ee4_.unknown_a8_ = 6;
        arg0->unknown_ee4_.unknown_aa_ = 9;
    }
    arg0->unknown_ee4_.unknown_b1_ = 0;
    arg0->unknown_ee4_.unknown_b5_ = 0;
    arg0->unknown_ee4_.unknown_b6_ = 0;
    memset(arg0->unknown_e10_, 0, Enum_ov005_021589f4_2048);
    int var3 = func_ov005_02158b3c(arg0, arg0->unknown_e10_);
    unsigned char var4[4];
    bool var5 = false;
    __clear(var4, 4);
    if (var3 != 0) {
        var5 = true;
        for (int var6 = 1; var6 < 4; var6++) var4[var6] = 2;
    }
    Window_OpenPane(panel, object->textBuffer, 0, mode, false, special, styles);

}
#else
// USA: func_ov005_021589f4
extern "C" ARM void func_ov005_021589f4(Struct_ov005_021589f4_2* arg0) {
    unsigned int var7 = arg0->unknown_3dd1_;
    int var8 = 1;
    Struct_ov005_021589f4* var9 = &arg0->unknown_ee4_;
    if (var7 >= 8 && var7 <= 14) {
        var9->unknown_a0_ = 32;
        var9->unknown_a2_ = 9;
        var8 = 0;
        var9->unknown_a4_ = 0;
        var9->unknown_a6_ = 15;
        var9->unknown_ac_ = 12;
        var9->unknown_ae_ = 20;
        var9->unknown_b7_ = 12;
        var9->unknown_a8_ = 12;
        var9->unknown_aa_ = 11;
    } else {
        var9->unknown_a0_ = 24;
        var9->unknown_a2_ = 5;

        var9->unknown_a4_ = 4;
        var9->unknown_a6_ = 10;
        var9->unknown_ac_ = 10;
        var9->unknown_ae_ = 14;
        var9->unknown_b7_ = 10;
        var9->unknown_a8_ = 6;
        var9->unknown_aa_ = 9;
    }
    var9->unknown_b1_ = 0;
    var9->unknown_b5_ = 0;
    var9->unknown_b6_ = 0;
    memset(arg0->unknown_e10_, 0, Enum_ov005_021589f4_2400);
    int var10 = func_ov005_02158b3c(arg0, arg0->unknown_e10_);
    unsigned char var11[4];
    bool var12 = false;
    __clear(var11, 4);
    if (var10 != 0) {
        var12 = true;
        for (int var13 = 1; var13 < 4; var13++) var11[var13] = 2;
    }
    Window_OpenPane(panel, object->textBuffer, 0, mode, false, special, styles, false);

}
#endif
