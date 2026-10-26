#include <globaldefs.h>

extern int data_020e91c8;
struct Struct_020b1d48_2;
extern "C" void func_020b1d48(struct Struct_020b1d48_2*, int, int, int, int, int, int);

// USA: func_020b1e94
extern "C" ARM void func_020b1e94(struct Struct_020b1d48_2* s, int a, int b, int c, int d) {
    func_020b1d48(s, a, b, c, d, (int)&data_020e91c8, b);
}
