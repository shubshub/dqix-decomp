#include <globaldefs.h>

extern "C" void* func_ov025_021e8cf0(char* base, int idx);
extern void* data_ov025_021ef994;

// USA: func_ov000_02181990
extern "C" ARM int func_ov000_02181990(int idx, int* out) {
    void* slot = func_ov025_021e8cf0((char*)data_ov025_021ef994, idx);
    if (!slot) {
        return 0;
    }
    *out = *(int*)slot;
    return 1;
}
