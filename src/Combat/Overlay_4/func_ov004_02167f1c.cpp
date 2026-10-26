#if defined(jpn)
#define R(j,u) (j)
#define func_ov004_02167b78 func_ov004_02168074
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Struct_ov004_02167f1c {
    unsigned char f4;
    short unknown_2_;
    short f8;
    short fa;
    int fc;
};

extern "C" void func_ov004_0216794c(short* a, short* b, short* c, unsigned char* d, int* e);
extern "C" void func_ov004_02167b78(void* obj, int val);
extern "C" void func_ov004_02167adc(void* obj);
extern "C" void func_ov011_021848a0(void* obj, int val);

// USA: func_ov004_02167f1c
extern "C" ARM int func_ov004_02167f1c(void* obj) {
    Struct_ov004_02167f1c buf;
    func_ov004_0216794c(&buf.fa, &buf.f8, &buf.unknown_2_, &buf.f4, &buf.fc);
    func_ov004_02167b78(obj, 0);
    func_ov004_02167adc(obj);
    if (buf.f4 != 0) {
        func_ov011_021848a0(obj, 0x28);
    } else if (buf.fc < 0) {
        func_ov011_021848a0(obj, 0x3c);
    } else {
        func_ov004_02167b78(obj, 0);
        func_ov011_021848a0(obj, 0x32);
    }
    return 0;
}
