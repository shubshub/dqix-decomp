#include <globaldefs.h>

extern "C" void func_ov025_021e278c(int value, char* dst);
extern "C" void func_ov025_021e27c8(char* buf, signed char kind);

struct Struct_ov025_021e4a58 {
    unsigned char pad[8];
    signed char field8;
    unsigned char pad2[3];
    int fieldC;
};

// USA: func_ov025_021e4a58
extern "C" ARM int func_ov025_021e4a58(struct Struct_ov025_021e4a58* p) {
    char buf[0x50];
    func_ov025_021e278c(p->fieldC, buf);
    func_ov025_021e27c8(buf, p->field8);
    return 1;
}
