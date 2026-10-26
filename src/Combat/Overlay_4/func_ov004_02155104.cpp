#include <globaldefs.h>

struct Struct_ov004_02155090 { short id; char pad[4]; };
extern "C" void* func_ov004_021550c8(Struct_ov004_02155090* arr, int key);
extern char* data_ov004_021707c4;

// USA: func_ov004_02155104
extern "C" ARM int func_ov004_02155104(void) {
    Struct_ov004_02155090* arr = (Struct_ov004_02155090*)data_ov004_021707c4;
    int val = 0;
    void* entry = func_ov004_021550c8(arr, 9);
    if (entry) {
        val = val + *((unsigned char*)entry + 5);
        val = (val << 16) >> 16;
    }
    return val;
}
