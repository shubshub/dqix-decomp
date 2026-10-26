#include <globaldefs.h>

extern "C" int func_ov031_0223fb48(const char* s);
extern "C" void func_ov031_0223fb74(void* dst, const void* src, unsigned int length);

struct Struct_ov031_02290da0 { unsigned char pad[0xc]; void* (*unknown_c_)(unsigned int, unsigned int); };
extern Struct_ov031_02290da0 data_ov031_02290da0;

// USA: func_ov031_0223e674
extern "C" ARM void* func_ov031_0223e674(const char* a0) {
    int len = func_ov031_0223fb48(a0);
    void* p = data_ov031_02290da0.unknown_c_(len + 1, 4);
    if (p != 0) {
        func_ov031_0223fb74(p, a0, len);
        ((char*)p)[len] = 0;
    }
    return p;
}
