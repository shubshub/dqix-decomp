#include <globaldefs.h>

extern "C" void VectorizedMemset(void* dst, int value, unsigned int len);
extern "C" void VectorizedInvertedMemcpy(const void* src, void* dst, unsigned int len);

struct Struct_ov027_021da314 {
    unsigned int field0;
    char* field4;
    char* field8;
    unsigned int fieldc;
};

// USA: func_ov027_021da314
extern "C" ARM void func_ov027_021da314(Struct_ov027_021da314* obj, unsigned int start, unsigned int end, int arg3) {
    if (start < 0x4000) start = 0x4000;
    if (end > 0x8000) end = 0x8000;
    if (start < obj->field0) start = obj->field0;
    unsigned int upper = obj->field0 + obj->fieldc;
    if (end > upper) end = upper;
    if (start >= end) return;
    if (arg3 != 0) {
        VectorizedMemset(obj->field8 + start, 0, end - start);
        return;
    }
    VectorizedInvertedMemcpy(obj->field4 + start, obj->field8 + start, end - start);
}
