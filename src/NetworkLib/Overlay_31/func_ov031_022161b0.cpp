#include <globaldefs.h>
#include "NitroSDK/Memory.h"

extern void* data_ov031_0224e5d8;

// USA: func_ov031_022161b0
extern "C" ARM int func_ov031_022161b0(int index, void* out) {
    void* ptr = data_ov031_0224e5d8;
    if (*(int*)((char*)ptr + 0x1a90) != 2) return -1;
    if (index < 0 || index >= *(int*)((char*)ptr + 0x1a88)) return -1;

    VectorizedMemset(out, 0, 0x78);
    *(int*)out = 1;
    unsigned short v = *(unsigned short*)((char*)data_ov031_0224e5d8 + 0x1a48 + index * 2);
    *(short*)((char*)out + 4) = v;
    char* src = (char*)data_ov031_0224e5d8 + 0x1348 + index * 0x70;
    VectorizedInvertedMemcpy(src, (char*)out + 6, 0x70);
    return 0;
}
