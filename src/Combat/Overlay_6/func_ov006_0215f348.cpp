#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov006_0215f348_20 = 0xc };
#else
enum { Enum_ov006_0215f348_20 = 0x14 };
#endif

extern "C" void func_0208103c(void* obj, int id, int value);
extern "C" void func_020813ec(void*, int);

struct Struct_ov006_0215b7e8_2 {
    char pad0[Enum_ov006_0215f348_20];
    void* f14;
    char pad1[0x360 - Enum_ov006_0215f348_20 - 4];
    short unknown_360_;
};

// USA: func_ov006_0215f348
extern "C" ARM void func_ov006_0215f348(struct Struct_ov006_0215b7e8_2* o) {
    short v2 = -1;
    switch (o->unknown_360_) {
    case 2:
        v2 = 4;
        break;
    case 3:
        v2 = 7;
        break;
    case 4:
        break;
    }
    short v1 = 5;
    for (unsigned char i = 0; i < 3; i++) {
        func_0208103c(o->f14, v1, v2);
        v1 = (short)(v1 + 1);
        if (v2 >= 0) {
            v2 = (short)(v2 + 1);
        }
    }
    func_020813ec(o->f14, 3);
}
