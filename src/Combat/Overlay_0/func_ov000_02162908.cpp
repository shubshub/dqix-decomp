#include <globaldefs.h>

extern "C" int func_ov000_0215ffa0(void* node);

#if defined(jpn)
enum { Enum_ov000_02162908_668 = 0x218 };
#else
enum { Enum_ov000_02162908_668 = 0x29c };
#endif

static inline void* inline_ov000_02162908(void* obj, int idx) {
    void* base = *(void**)((char*)obj + Enum_ov000_02162908_668);
    return (char*)base + 0x21c + 0x8000 + idx * 0x28;
}

// USA: func_ov000_02162908
extern "C" ARM int func_ov000_02162908(void* obj, int idx, int* out) {
    void* entry = inline_ov000_02162908(obj, idx);
    void* node = *(void**)((char*)entry + 0x14);
    int count = 0;
    while (node) {
        out[count++] = func_ov000_0215ffa0(node);
        node = *(void**)((char*)node + 0x20);
    }
    return count;
}
