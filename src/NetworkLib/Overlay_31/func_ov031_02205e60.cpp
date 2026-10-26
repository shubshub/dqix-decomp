#include <globaldefs.h>

struct Struct_ov031_02205a38;
struct Struct_ov031_0220527c;
struct Struct_ov031_02205eac;
extern "C" void* func_ov031_02205134(void*, void*, int);
extern "C" int func_ov031_0220527c(Struct_ov031_0220527c*, void*);
extern "C" int func_ov031_02205eac(Struct_ov031_02205eac*);

// USA: func_ov031_02205e60
extern "C" ARM int func_ov031_02205e60(Struct_ov031_02205a38* obj) {
    char* state = *(char**)((char*)obj + 0x64);
    if (*(int*)(state + 0xf8) < *(unsigned short*)(state + 0xfc)) return 0;
    void* record = func_ov031_02205134((void*)func_ov031_02205eac, obj, 0);
    if (record == NULL) return -33;
    return func_ov031_0220527c((Struct_ov031_0220527c*)obj, record);
}
