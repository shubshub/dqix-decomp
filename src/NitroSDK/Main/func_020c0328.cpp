#include <globaldefs.h>

struct Struct_020c0328 {
    unsigned int a, b, c, d;   /* 0x0,0x4,0x8,0xc */
    unsigned int unknown_10_;      /* 0x10 */
    unsigned int unknown_14_;     /* 0x14 */
};

// USA: func_020c0328
extern "C" ARM void func_020c0328(struct Struct_020c0328* state) {
    state->a = 0x67452301;
    state->b = 0xefcdab89;
    state->c = 0x98badcfe;
    state->d = 0x10325476;
    state->unknown_10_ = 0;
    state->unknown_14_ = 0;
}
