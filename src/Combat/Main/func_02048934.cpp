#include <globaldefs.h>
#include "Util/Random.h"

extern "C" float _ffltu(unsigned int v);
extern "C" float _fmul(float a, float b);
extern "C" float _fadd(float a, float b);
extern "C" unsigned int _ffixu(float v);

struct Struct_02048934 {
    char pad0[0x5c];
    unsigned short unknown_5c_;
    unsigned short unknown_5e_;
};

struct Struct_02048934_2 {
    char pad0[0x188];
    unsigned short unknown_188_;
    unsigned short unknown_18a_;
};

// USA: func_02048934
extern "C" ARM void func_02048934(void* p, struct Struct_02048934* f, struct Random* r) {
    if (f != NULL) {
        unsigned short v = f->unknown_5c_;
        ((struct Struct_02048934_2*)p)->unknown_188_ = 0.5f + v * NextRandomFloatBetween(r, 0.8f, 1.0f);
        ((struct Struct_02048934_2*)p)->unknown_18a_ = f->unknown_5e_;
    }
}
