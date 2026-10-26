#include <globaldefs.h>

struct Struct_ov017_021a4368_3;
struct Struct_ov003_0217eef4;
struct Struct_ov017_021a4368_4;
struct Struct_ov003_0217f248;
struct Struct_ov017_021a4368;
struct Struct_020dae80;
extern "C" void func_ov017_021adc44(void*);
extern "C" void func_ov017_021a18a4(void*);
extern "C" void func_ov017_021b9928(char*);
extern "C" void func_ov017_021b8450(void*);
extern "C" void func_ov017_021a5954(void*);
extern "C" void func_ov017_021bae98(void*);
extern "C" void func_ov017_021babe0(void*);
extern "C" void func_ov003_0217e598(int*);
extern "C" void func_ov017_021bb8f0(char*);
extern "C" void func_ov017_021b2f2c(void*);
extern "C" void func_ov017_021b6b74(struct Struct_ov017_021a4368_3*);
extern "C" void func_ov003_0217eef4(struct Struct_ov003_0217eef4*);
extern "C" void func_ov017_021aaec8(char*);
extern "C" void func_ov017_021acd00(void*);
extern "C" void func_ov017_021afabc(struct Struct_ov017_021a4368_4*);
extern "C" void func_ov017_021c0550(void*);
extern "C" void func_ov017_021c1220(void*);
extern "C" void func_ov003_0217f248(struct Struct_ov003_0217f248*);
extern "C" void func_ov017_021b1d04(void*);
extern "C" void func_ov017_021b1f9c(void*);
extern "C" void func_ov017_021b2368(void*);
extern "C" void func_ov017_021c166c(void*);
extern "C" void func_ov017_021c19e0(void*);
extern "C" void func_ov017_021be3b4(void*);
extern "C" void func_ov017_021a9fec(void*);
extern "C" void func_ov017_021bef4c(void*);
extern "C" void func_ov017_021bf360(void*);
extern "C" void func_ov017_021c1dfc(void*);
extern "C" void func_ov017_021a925c(char*);
extern "C" void func_ov017_021a9638(void*);
extern "C" void func_ov017_021a99b0(struct Struct_ov017_021a4368*);
extern "C" void func_ov017_021a79ac(char*);
extern "C" void func_020d844c(void*);
extern "C" void func_020dae80(struct Struct_020dae80*);

struct Struct_ov017_021a4368_2 {
    signed char kind;
    unsigned char unknown_1_;
};

// USA: func_ov017_021a4368
extern "C" ARM void func_ov017_021a4368(void* unused, Struct_ov017_021a4368_2* event) {
    if (!event || event->unknown_1_) return;
    switch (event->kind) {
    case 1: func_ov017_021adc44(event); return;
    case 2: func_ov017_021a18a4(event); return;
    case 5: func_ov017_021b9928((char*)event); return;
    case 10: func_ov017_021b8450(event); return;
    case 12: func_ov017_021a5954(event); return;
    case 15: func_ov017_021bae98(event); return;
    case 16: func_ov017_021babe0(event); return;
    case 17: func_ov003_0217e598((int*)event); return;
    case 4: func_ov017_021bb8f0((char*)event); return;
    case 18: func_ov017_021b2f2c(event); return;
    case 23: func_ov017_021b6b74((Struct_ov017_021a4368_3*)event); return;
    case 24: func_ov003_0217eef4((Struct_ov003_0217eef4*)event); return;
    case 26: func_ov017_021aaec8((char*)event); return;
    case 31: func_ov017_021acd00(event); return;
    case 38: func_ov017_021afabc((Struct_ov017_021a4368_4*)event); return;
    case 40: func_ov017_021c0550(event); return;
    case 41: func_ov017_021c1220(event); return;
    case 42: func_ov003_0217f248((Struct_ov003_0217f248*)event); return;
    case 43: func_ov017_021b1d04(event); return;
    case 44: func_ov017_021b1f9c(event); return;
    case 45: func_ov017_021b2368(event); return;
    case 46: func_ov017_021c166c(event); return;
    case 47: func_ov017_021c19e0(event); return;
    case 51: func_ov017_021be3b4(event); return;
    case 59: func_ov017_021a9fec(event); return;
    case 52: func_ov017_021bef4c(event); return;
    case 53: func_ov017_021bf360(event); return;
    case 55: func_ov017_021c1dfc(event); return;
    case 56: func_ov017_021a925c((char*)event); return;
    case 57: func_ov017_021a9638(event); return;
    case 58: func_ov017_021a99b0((Struct_ov017_021a4368*)event); return;
    case 63: func_ov017_021a79ac((char*)event); return;
    case 67: func_020d844c(event); return;
    case 75: func_020dae80((Struct_020dae80*)event); return;
    }
}
