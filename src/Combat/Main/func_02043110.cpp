#include <globaldefs.h>

#if defined(jpn)
#define func_02043110 func_02043884
#endif

struct Struct_02043110 {
    char pad[0x8];
    int field8;
};

struct Struct_020430b0 {
    char pad[0x440];
    struct Struct_02043110* unknown_440_;
};

// USA: func_02043110
extern "C" ARM void func_02043110(struct Struct_020430b0* s) {
    struct Struct_02043110* t = s->unknown_440_;
    if (t != 0) {
        t->field8 = 0;
    }
}
