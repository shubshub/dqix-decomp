#include <globaldefs.h>
struct CombatantRecovery;

struct Struct_02053f4c {
#if defined(jpn)
    char unk[0x19c];
#else
    char unk[0x1a8];
#endif
    int unknown_1a8_;
    int unknown_1ac_;
};

// USA: func_02053f4c
extern "C" ARM void func_02053f4c(CombatantRecovery* arg0, int val1, int val2) {
    struct Struct_02053f4c* obj = (struct Struct_02053f4c*)arg0;
    obj->unknown_1a8_ = val1;
    obj->unknown_1ac_ = val2;
}
