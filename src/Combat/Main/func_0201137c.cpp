#include <globaldefs.h>

struct Struct_0201137c { int a; unsigned int b; };
extern "C" struct Struct_0201137c* func_0209a594(void* p, int id);

// USA: func_0201137c
extern "C" ARM int func_0201137c(char* base, int id) {
    struct Struct_0201137c* e;
    unsigned int result = 0;
#if defined(jpn)
    e = func_0209a594(base + 0x54cc, id);
#else
    e = func_0209a594(base + 0x572c, id);
#endif
    if (e != NULL) {
#if defined(jpn)
        result = e->b >> 24;
#else
        result = (e->b << 12) >> 24;
#endif
    }
    return result;
}
