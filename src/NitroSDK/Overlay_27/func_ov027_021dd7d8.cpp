#include <globaldefs.h>
#include "NitroSDK/Memory.h"

struct Struct_ov027_021e3424_4 {
    unsigned char pad0[4];
    char* arr;
    unsigned int unknown_8_;
    int count;
};

extern Struct_ov027_021e3424_4 data_ov027_021e3424;

extern "C" int func_ov027_021dd864(int id);

// USA: func_ov027_021dd7d8
#pragma optimize_for_size off
extern "C" ARM void* func_ov027_021dd7d8(unsigned char* dst, int id) {
    if (data_ov027_021e3424.arr == 0) return 0;
    unsigned char field1 = dst[2];
    if (field1 > data_ov027_021e3424.count) return 0;
    int idx = id - 1;
    unsigned int var2 = data_ov027_021e3424.unknown_8_;
    void* slot = data_ov027_021e3424.arr + idx * 0x20 + field1 * var2;
    VectorizedInvertedMemcpy(dst + 3, slot, var2);
    int* bits = (int*)(data_ov027_021e3424.arr + 0x1e0);
    bits[idx] |= (1 << field1);
    if (!func_ov027_021dd864(id)) return 0;
    return data_ov027_021e3424.arr + idx * 0x20;
}
