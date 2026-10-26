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

extern "C" void* __clear(void* dst, int count);
extern "C" int func_ov005_02158b3c(void* object, void* buffer);
#if defined(jpn)
extern "C" void Window_OpenPane(void* renderer, void* buffer, int a, int b, bool c, bool d, void* styles);
#else
extern "C" void Window_OpenPane(void* renderer, void* buffer, int a, int b, bool c, bool d, void* styles, bool e);
#endif

struct Struct_ov005_021589f4 {
    unsigned char unknown0[0xa0];
    short unknown_a0_, unknown_a2_, tileX, tileY;
    short unknown_a8_, unknown_aa_, unknown_ac_, unknown_ae_;
    unsigned char unknown_b0_, unknown_b1_, unknown_b2_, unknown_b3_, unknown_b4_, unknown_b5_, unknown_b6_, unknown_b7_;
};

struct Struct_ov005_021589f4_2 {
    char unknown0[0xe10];
    char* textBuffer;
    char unknown_e14_[EQUIPMENT_PANEL_OFFSET - 0xe14];
    Struct_ov005_021589f4 panel;
    char unknown_f9c_[EQUIPMENT_MESSAGE_OFFSET - EQUIPMENT_PANEL_OFFSET - sizeof(Struct_ov005_021589f4)];
    unsigned char message;
};

#if defined(jpn)
// USA: func_ov005_021589f4
extern "C" ARM void func_ov005_021589f4(Struct_ov005_021589f4_2* object) {
    unsigned int selector = object->message;
    int mode = 1;
    Struct_ov005_021589f4* panel = &object->panel;
    if (selector >= 8 && selector <= 14) {
        object->panel.unknown_a0_ = 32;
        object->panel.unknown_a2_ = 9;
        mode = 0;
        object->panel.tileX = 0;
        object->panel.tileY = 15;
        object->panel.unknown_ac_ = 12;
        object->panel.unknown_ae_ = 20;
        object->panel.unknown_b7_ = 12;
        object->panel.unknown_a8_ = 12;
        object->panel.unknown_aa_ = 11;
    } else {
        object->panel.unknown_a0_ = 24;
        object->panel.unknown_a2_ = 4;

        object->panel.tileX = 4;
        object->panel.tileY = 10;
        object->panel.unknown_ac_ = 10;
        object->panel.unknown_ae_ = 14;
        object->panel.unknown_b7_ = 10;
        object->panel.unknown_a8_ = 6;
        object->panel.unknown_aa_ = 9;
    }
    object->panel.unknown_b1_ = 0;
    object->panel.unknown_b5_ = 0;
    object->panel.unknown_b6_ = 0;
    memset(object->textBuffer, 0, Enum_ov005_021589f4_2048);
    int result = func_ov005_02158b3c(object, object->textBuffer);
    unsigned char styles[4];
    bool special = false;
    __clear(styles, 4);
    if (result != 0) {
        special = true;
        for (int i = 1; i < 4; i++) styles[i] = 2;
    }
    Window_OpenPane(panel, object->textBuffer, 0, mode, false, special, styles);

}
#else
// USA: func_ov005_021589f4
extern "C" ARM void func_ov005_021589f4(Struct_ov005_021589f4_2* object) {
    unsigned int selector = object->message;
    int mode = 1;
    Struct_ov005_021589f4* panel = &object->panel;
    if (selector >= 8 && selector <= 14) {
        panel->unknown_a0_ = 32;
        panel->unknown_a2_ = 9;
        mode = 0;
        panel->tileX = 0;
        panel->tileY = 15;
        panel->unknown_ac_ = 12;
        panel->unknown_ae_ = 20;
        panel->unknown_b7_ = 12;
        panel->unknown_a8_ = 12;
        panel->unknown_aa_ = 11;
    } else {
        panel->unknown_a0_ = 24;
        panel->unknown_a2_ = 5;

        panel->tileX = 4;
        panel->tileY = 10;
        panel->unknown_ac_ = 10;
        panel->unknown_ae_ = 14;
        panel->unknown_b7_ = 10;
        panel->unknown_a8_ = 6;
        panel->unknown_aa_ = 9;
    }
    panel->unknown_b1_ = 0;
    panel->unknown_b5_ = 0;
    panel->unknown_b6_ = 0;
    memset(object->textBuffer, 0, Enum_ov005_021589f4_2400);
    int result = func_ov005_02158b3c(object, object->textBuffer);
    unsigned char styles[4];
    bool special = false;
    __clear(styles, 4);
    if (result != 0) {
        special = true;
        for (int i = 1; i < 4; i++) styles[i] = 2;
    }
    Window_OpenPane(panel, object->textBuffer, 0, mode, false, special, styles, false);

}
#endif
