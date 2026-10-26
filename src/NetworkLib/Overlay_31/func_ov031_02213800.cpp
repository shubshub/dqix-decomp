#include <globaldefs.h>

struct Struct_ov031_02213800 {
    char pad[0xd0c];
    unsigned char field : 4;
};

extern "C" struct Struct_ov031_02213800* func_ov031_022133f8(int a0);
extern "C" ARM int func_ov031_022157c4(void *p);
extern "C" ARM int func_ov031_02215718(int a);

// USA: func_ov031_02213800
extern "C" ARM int func_ov031_02213800(char* obj) {
    Struct_ov031_02213800* h = func_ov031_022133f8(0x10);
    unsigned int v = h->field;
    if (v == 0 || v == 4) {
        unsigned int bit = (*(unsigned short*)(obj + 0x2c) >> 4) & 1;
        if (bit == 1) {
            if (func_ov031_022157c4(obj + 0xc) == 1) return 6;
        }
    }
    v = h->field;
    if (v == 0 || v == 5) {
        unsigned int bit = (*(unsigned short*)(obj + 0x2c) >> 4) & 1;
        if (bit == 1) {
            if (func_ov031_02215718((int)(obj + 0xc)) == 1) return 7;
        }
    }
    return -1;
}
