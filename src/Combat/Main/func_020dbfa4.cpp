#include <globaldefs.h>
extern "C" void* func_02057924(void);

extern "C" void func_02057fb4(void* list, int id, void* config);

struct Struct_020dbfa4 {
    char pad0[8];
    int unknown_8_;
    char unknown_c_[4];
    int unknown_10_;
    unsigned char unknown_14_;
};

// USA: func_020dbfa4
extern "C" ARM void func_020dbfa4(struct Struct_020dbfa4* o, int arg1) {
    if (o->unknown_10_ == 2 && o->unknown_14_ == 0) {
        func_02057fb4(func_02057924(), o->unknown_8_, (void*)arg1);
        o->unknown_14_ = 1;
    }
}
