#include <globaldefs.h>

extern "C" void* func_ov000_02161318(void* obj, int idx);

// USA: func_ov000_02174fc0
extern "C" ARM void func_ov000_02174fc0(void* obj) {
    int i;
    for (i = 0; i < 4; i++) {
        signed char idx = *((char*)obj + i + 0x6c);
        void* p = func_ov000_02161318(obj, idx);
        if (p != NULL) {
            signed char off = *((char*)p + 0x18);
            int val = 0;
            int keep = *(int*)((char*)p + 0x48);
            if (*((char*)p + off + 0x10) == 0x65) val = -8;
            *(int*)((char*)p + 0x44) = val;
            *(int*)((char*)p + 0x48) = keep;
        }
    }
}
