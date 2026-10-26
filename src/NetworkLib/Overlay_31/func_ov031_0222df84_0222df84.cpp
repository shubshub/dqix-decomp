#include <globaldefs.h>

struct Struct_ov031_0222336c;
struct Struct_ov031_0222df84 { Struct_ov031_0222336c* object; int field4; unsigned char text[12]; };
struct Struct_ov031_02248ee0_2 { unsigned char unknown_0_[0xe]; unsigned short x, y; };
extern Struct_ov031_0222df84* data_ov031_02290c98;
extern Struct_ov031_02248ee0_2 data_ov031_02248ee0;
extern const unsigned char data_ov031_02248f20[12];
extern "C" void func_ov031_0223ca40(void*, int);
extern "C" void func_ov031_0223c980(Struct_ov031_0222336c*, int, int, int, int, int, int, const unsigned short*);
extern "C" void func_ov031_0223caec(void*);

// USA: func_ov031_0222df84
extern "C" ARM void func_ov031_0222df84() {
    unsigned short var0[4] __attribute__((aligned(4)));
    var0[0] = data_ov031_02248ee0.x;
    var0[1] = data_ov031_02248ee0.y;
    var0[2] = 11;
    var0[3] = 16;
    func_ov031_0223ca40(data_ov031_02290c98->object, 0);
    unsigned short text[2];
    text[1] = 0;
    const unsigned char* columns = data_ov031_02248f20;
    int i = 0;
    do {
        Struct_ov031_0222df84* row = data_ov031_02290c98;
        text[0] = row->text[i];
        unsigned short x = *columns++;
        var0[0] = x;
        func_ov031_0223c980(row->object, x, var0[1], var0[2], var0[3], 2, 0x480, text);
    } while (++i < 12);
    func_ov031_0223caec(data_ov031_02290c98->object);
}
