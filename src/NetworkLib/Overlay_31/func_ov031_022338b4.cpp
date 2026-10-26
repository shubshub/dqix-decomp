#include <globaldefs.h>

struct Struct_ov031_02249198_3 { unsigned short left, right, top, bottom; };
struct Struct_ov031_02290cc8_6 { signed char field_0x0; signed char selected; unsigned char field_0x2; unsigned char unknown_3_; int unknown_4_; };
extern Struct_ov031_02249198_3 data_ov031_02249198[][4];
extern Struct_ov031_02290cc8_6 data_ov031_02290cc8;
extern signed char data_ov031_0224912e[][4][4];

extern "C" int func_ov031_02227570(unsigned int);
extern "C" void func_ov031_02236878(int);
extern "C" void func_ov031_022237dc(unsigned short, unsigned short, unsigned short, unsigned short);

// USA: func_ov031_022338b4
extern "C" ARM void func_ov031_022338b4(int dir) {
    signed char cur = data_ov031_02290cc8.selected;
    signed char next = data_ov031_0224912e[func_ov031_02227570(1)][cur][dir];
    if (next == -1) return;
    if (next == 0) {
        data_ov031_02290cc8.field_0x0 = cur;
    }
    if (next == -2) {
        data_ov031_02290cc8.selected = data_ov031_02290cc8.field_0x0;
    } else {
        data_ov031_02290cc8.selected = next;
    }
    func_ov031_02236878(8);
    func_ov031_022237dc(
        data_ov031_02249198[func_ov031_02227570(1)][data_ov031_02290cc8.selected].left,
        data_ov031_02249198[func_ov031_02227570(1)][data_ov031_02290cc8.selected].top,
        data_ov031_02249198[func_ov031_02227570(1)][data_ov031_02290cc8.selected].right,
        data_ov031_02249198[func_ov031_02227570(1)][data_ov031_02290cc8.selected].bottom);
}
