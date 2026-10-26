#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
extern "C" void* func_020704fc(void*);
struct Struct_020708c8;
extern "C" void func_020708c8(struct Struct_020708c8*, unsigned int);

// USA: func_ov001_0215b384
extern "C" ARM int func_ov001_0215b384(void* self) {
    int v = func_ov017_021d60f4(self);
    void* handle = func_020704fc((void*)v);
    if (handle != NULL) {
        func_020708c8((struct Struct_020708c8*)handle, v);
    }
    return 1;
}
