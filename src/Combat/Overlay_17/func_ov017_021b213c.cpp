#include <globaldefs.h>

struct Struct_ov004_021589e8 {
    unsigned int low : 12;
    unsigned int f12 : 4;
    unsigned int unknown_2_0_ : 5;
    unsigned int unknown_2_5_ : 5;
    unsigned int top : 6;
};

extern "C" int func_ov017_021b2090(Struct_ov004_021589e8 a, Struct_ov004_021589e8 b);

// USA: func_ov017_021b213c
extern "C" ARM int func_ov017_021b213c(Struct_ov004_021589e8 a, Struct_ov004_021589e8 b) {
	return func_ov017_021b2090(b, a);
}
