#include <globaldefs.h>

struct Struct_ov027_021dd940_4 {
    unsigned char pad[0x24];
    unsigned char state;
};

extern "C" {
    int func_ov027_021daecc();
    void func_ov027_021daf6c();
    void func_ov027_021dafc0(int, int, int);
    void func_ov027_021db124();
    void func_ov027_021db154(int, int, int);
}

extern Struct_ov027_021dd940_4 data_ov027_021dd940;

// USA: func_ov027_021dae40
extern "C" ARM void func_ov027_021dae40(int a, int b, int c) {
    for (;;) {
        switch (data_ov027_021dd940.state) {
            case 0:
            case 1:
                if (func_ov027_021daecc() == 0)
                    return;
                break;
            case 2:
                func_ov027_021daf6c();
                break;
            case 3:
                func_ov027_021dafc0(a, b, c);
                return;
            case 4:
                func_ov027_021db124();
                break;
            case 5:
                func_ov027_021db154(a, b, c);
                return;
            case 6:
            default:
                break;
        }
    }
}
