#include <globaldefs.h>

#if defined(jpn)
enum { Enum_020444bc_120 = 0x44, Enum_020444bc_2464 = 0x870 };
#else
enum { Enum_020444bc_120 = 0x78, Enum_020444bc_2464 = 0x9a0 };
#endif

struct Struct_020444bc {
    char pad0[Enum_020444bc_120];
    int unknown_78_;
    char unknown_7c_[Enum_020444bc_2464 - Enum_020444bc_120 - 4];
    int unknown_9a0_;
};

// USA: func_020444bc
extern "C" ARM void func_020444bc(struct Struct_020444bc* s) {
    s->unknown_9a0_ = 5;
    s->unknown_78_ = s->unknown_78_ + 1;
}
