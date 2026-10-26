#include <globaldefs.h>

struct Struct_ov031_0222d2bc_3 { void* object; unsigned int field4; unsigned char text[32]; };
struct Struct_ov031_0222d2bc {
    unsigned short x, y, width, height;
};
struct Struct_ov031_0222d2bc_2 { unsigned short glyph, terminator; };
extern Struct_ov031_0222d2bc_3* data_ov031_02290c94;
extern unsigned char data_ov031_02248ed0[16];
extern "C" void func_ov031_0223ca40(void*, int);
extern "C" void func_ov031_0223c980(void*, unsigned short, unsigned short, unsigned short, unsigned short, int, int, Struct_ov031_0222d2bc_2*);
extern "C" void func_ov031_0223caec(void*);

// USA: func_ov031_0222d2bc
extern "C" ARM void func_ov031_0222d2bc() {
    Struct_ov031_0222d2bc var0 = {0, 0, 0, 0};
    var0.y = 0x20;
    var0.width = 0xe;
    var0.height = 0x10;
    func_ov031_0223ca40(data_ov031_02290c94->object, 0);
    Struct_ov031_0222d2bc_2 glyph;
    int column;
    int index = 0;
    column = 0;
    glyph.terminator = 0;
    do {
        if (index == 16) {
            column = 0;
            var0.y = 0x31;
        }
        unsigned char character = data_ov031_02290c94->text[index];
        if (character == 0x20) glyph.glyph = 0xe01d;
        else glyph.glyph = character;
        var0.x = data_ov031_02248ed0[column];
        func_ov031_0223c980(data_ov031_02290c94->object, var0.x,
            var0.y, var0.width, var0.height, 2, 0x480, &glyph);
        ++index;
        ++column;
    } while (index < 32);
    func_ov031_0223caec(data_ov031_02290c94->object);
}
