#include <globaldefs.h>

struct Struct_ov015_02190acc {
    char pad[0x1a4];
    int field1a4;
};

// USA: func_ov015_02190c2c
extern "C" ARM int func_ov015_02190c2c(struct Struct_ov015_02190acc* obj) {
    switch (obj->field1a4) {
        case 15: case 16: case 17: case 18: case 19: case 20: case 21:
        case 22: case 23: case 24: case 25: case 26: case 27: case 28:
        case 29: case 30: case 31: case 32:
            return 1;
        default:
            return 0;
    }
}
