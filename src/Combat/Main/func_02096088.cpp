#include <globaldefs.h>

extern "C" int func_02096100(int unused, unsigned char* arr, int idx);

// USA: func_02096088
extern "C" ARM int func_02096088(void* obj, int idx) {
    return func_02096100((int)obj, (unsigned char*)obj + 0x84, idx);
}
