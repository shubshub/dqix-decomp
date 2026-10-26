#include <globaldefs.h>

struct Struct_02053dc0 {
#if defined(jpn)
    char pad[0x190];
#else
    char pad[0x19c];
#endif
    void* unknown_19c_;
};

// USA: func_02053dc0
extern "C" ARM void* func_02053dc0(struct Struct_02053dc0* p) {
    void* x = p->unknown_19c_;
    return x != NULL ? x : NULL;
}
