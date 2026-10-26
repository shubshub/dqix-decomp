#include <globaldefs.h>

extern "C" void* func_ov023_021db4e4(void*);
extern "C" void* func_ov023_021e2450(void* obj, int val);

// USA: func_ov023_021e2418
extern "C" ARM void* func_ov023_021e2418(void* obj) {
    void* p = func_ov023_021db4e4(obj);
    if (p != 0) {
        unsigned short f2 = *(unsigned short*)((char*)p + 0x2);
        if (f2 != 0) {
            void* q = *(void**)((char*)p + 0x4);
            if (q != 0) {
                short key = *(short*)q;
                return func_ov023_021e2450(obj, key);
            }
        }
    }
    return 0;
}
