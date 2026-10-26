#include <globaldefs.h>

#if defined(jpn)
enum { Enum_0205420c_336 = 0x144 };
#else
enum { Enum_0205420c_336 = 0x150 };
#endif

extern "C" void func_02083c48(void*);

struct Struct_0205420c {
    char pad[Enum_0205420c_336];
    void* field150;
};

// USA: func_0205420c
extern "C" ARM void func_0205420c(struct Struct_0205420c* obj, int, int) {
    void* p = obj->field150;
    if (p != NULL) func_02083c48(p);
}
