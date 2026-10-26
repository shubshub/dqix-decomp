#include <globaldefs.h>

extern "C" void VCountIrq_PushDisable(void);
struct Struct_020db264;
extern "C" void func_020db360(struct Struct_020db264* obj, int b);
extern "C" int func_020db9a8(struct Struct_020db264* obj);
extern "C" void VCountIrq_PopDisable(void);

// USA: func_020db264
extern "C" ARM void func_020db264(void* obj, int arg1, int arg2, int arg3, int arg4) {
    char* p = (char*)obj;
    if (*(unsigned char*)(p + 0x50) != 0 && arg1 != 0) {
        return;
    }
    VCountIrq_PushDisable();
    if (arg3 == 0) {
        *(short*)(p + 0x66) = 0;
    }
    *(unsigned char*)(p + 0x50) = (unsigned char)arg1;
    *(unsigned char*)(p + 0x52) = (unsigned char)arg2;
    int b = (arg1 == 0);
    unsigned char var2 = (unsigned char)arg4;
    *(unsigned char*)(p + 0x53) = (unsigned char)arg3;
    *(unsigned char*)(p + 0x54) = var2;
    func_020db360((struct Struct_020db264*)obj, b);
    *(unsigned char*)(p + 0x3c) = func_020db9a8((struct Struct_020db264*)obj);
    VCountIrq_PopDisable();
}
