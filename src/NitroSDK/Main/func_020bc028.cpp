#include <globaldefs.h>

struct Struct_0210f3e4 {
    char pad[0x2c];
    unsigned char active;   // +0x2c
    char pad2[0x17];        // up to 0x44
};
extern Struct_0210f3e4 data_0210f3e4[16];

extern "C" void func_020bc548(Struct_0210f3e4* entry, int arg);

// USA: func_020bc028
extern "C" ARM void func_020bc028(int arg) {
    int i = 0;
    Struct_0210f3e4* e = data_0210f3e4;
    do {
        if (e->active != 0) {
            func_020bc548(e, arg);
        }
        i++;
        e++;
    } while (i < 16);
}
