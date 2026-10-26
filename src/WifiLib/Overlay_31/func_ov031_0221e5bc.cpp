#include <globaldefs.h>

struct Struct_ov031_02207204;
extern "C" int func_ov031_02207204(void* obj, struct Struct_ov031_02207204* arg1);

// USA: func_ov031_0221e5bc
extern "C" THUMB int func_ov031_0221e5bc(void* obj, struct Struct_ov031_02207204* arg1, unsigned char val) {
    *(unsigned char*)arg1 = val;
    return func_ov031_02207204(obj, arg1);
}
