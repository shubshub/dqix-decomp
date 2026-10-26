#include <globaldefs.h>

#if defined(jpn)
enum { Enum_020466c8_56 = 0x4 };
#else
enum { Enum_020466c8_56 = 0x38 };
#endif

struct S020466c8 {
    char pad[Enum_020466c8_56];
    int field0x38;
};

// USA: func_020466c8
extern "C" ARM void func_020466c8(struct S020466c8* p, int v) {
    p->field0x38 = v;
}
