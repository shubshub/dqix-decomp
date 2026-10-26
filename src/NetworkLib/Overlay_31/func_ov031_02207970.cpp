#include <globaldefs.h>

struct Struct_ov031_0220527c;
extern "C" void* func_ov031_02205134(void*, void*, int);
extern "C" int func_ov031_0220527c(Struct_ov031_0220527c*, void*);
extern "C" void func_ov031_022079ac(void);

// USA: func_ov031_02207970
extern "C" ARM int func_ov031_02207970(void* obj, void* value) {
    void* record = func_ov031_02205134((void*)func_ov031_022079ac, obj, 1);
    if (record == NULL) return -33;
    *(void**)((char*)record + 0x10) = value;
    return func_ov031_0220527c((Struct_ov031_0220527c*)obj, record);
}
