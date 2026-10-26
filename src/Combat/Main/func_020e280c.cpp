#include <globaldefs.h>

#if defined(jpn)
#define func_020e1cdc func_020e38d4
#endif

extern "C" void func_020e25cc(signed char* p);
extern "C" void func_020e1cdc(void* a, void* b);
struct Struct_020e2604;
extern "C" void func_020e2604(struct Struct_020e2604* self);

struct Struct_020e280c {
    unsigned char pad0[0x10];
    void* unknown_10_;   // 0x10
};

// USA: func_020e280c
extern "C" ARM void func_020e280c(struct Struct_020e280c* self, void* b) {
    func_020e25cc((signed char*)self);
    func_020e1cdc(self->unknown_10_, b);
    func_020e2604((struct Struct_020e2604*)self);
}
