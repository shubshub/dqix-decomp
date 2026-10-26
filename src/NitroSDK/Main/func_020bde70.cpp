#include <globaldefs.h>
extern "C" int func_020be1a8(unsigned int, int, int);
extern "C" int* func_020bd4b8(int);

extern "C" int func_020bd8ac(unsigned int);

// USA: func_020bde70
extern "C" ARM int func_020bde70(int id, int flags, int b, int c, int* out) {
    int* entry = func_020bd4b8((int)(id));
    if (entry == NULL) return 3;
    int val = *entry;
    int result;
    if (flags & 8) {
        result = func_020be1a8((unsigned int)(val), (int)(b), (int)(c));
        if (result == 0) return 7;
    } else {
        result = func_020bd8ac(val);
    }
    if (out != NULL) *out = result;
    return 0;
}
