#include <globaldefs.h>

struct Struct_0206dee8 {
    unsigned char a;
    unsigned char b;
    unsigned char c;
    char pad[0x19];
};

// USA: func_0206dee8
extern "C" ARM void func_0206dee8(Struct_0206dee8* base, unsigned char index, unsigned char* outA, unsigned char* outB, unsigned char* arg4) {
    *outA = base[index].a;
    *outB = base[index].b;
    *arg4 = base[index].c;
}
