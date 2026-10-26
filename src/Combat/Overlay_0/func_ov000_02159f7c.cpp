#include <globaldefs.h>

extern "C" int func_ov000_0215fd90(void* obj, int flag);

struct Struct_ov000_02159f7c {
    unsigned long long value;
};

#define TEST_BIT_CONST(bits, n) (((bits)->value & (1ULL << (n))) != 0)

// USA: func_ov000_02159f7c
extern "C" ARM int func_ov000_02159f7c(void* unused, struct Struct_ov000_02159f7c* bits) {
    if (TEST_BIT_CONST(bits, 5)) goto ret1;
    if (TEST_BIT_CONST(bits, 6)) goto ret1;
    if (TEST_BIT_CONST(bits, 9)) goto ret1;
    if (TEST_BIT_CONST(bits, 10)) goto ret1;
    if (TEST_BIT_CONST(bits, 12)) goto ret1;
    if (func_ov000_0215fd90(bits, 0x26) == 0) goto ret0;
ret1:
    return 1;
ret0:
    return 0;
}
