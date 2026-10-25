#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov025_021e5e1c_2481 = 0x7e1, Enum_ov025_021e5e1c_2482 = 0x7e2, Enum_ov025_021e5e1c_2456 = 0x868 };
#else
enum { Enum_ov025_021e5e1c_2481 = 0x9b1, Enum_ov025_021e5e1c_2482 = 0x9b2, Enum_ov025_021e5e1c_2456 = 0x998 };
#endif

#if defined(jpn)
#define func_02042b98 func_02043270
#endif

int MessageSystem_GetInstance();
#if defined(jpn)
extern "C" void func_0204500c(void* arg0, void* arg1, int arg2);
#else
extern "C" void func_0204500c(void* arg0, void* arg1, int arg2, int arg3);
#endif
extern "C" void func_02042b98(void* arg0, int arg1, int arg2, int arg3, int arg4);

struct Struct_ov025_021e5e1c { char unknown_0_[8]; void* unknown_8_; };

// USA: func_ov025_021e5e1c  (semantic: InitGlobalFieldsAndFlags_021e5e1c)
extern "C" ARM void func_ov025_021e5e1c(struct Param021e5e1c* p) {
    int base = MessageSystem_GetInstance();
    void* field8 = p->field8;
#if defined(jpn)
    func_0204500c((void*)var0, var1, 0);
#else
    func_0204500c((void*)var0, var1, 0, 0xe3);
#endif
    *(unsigned char*)(var0 + 0x1000 + Enum_ov025_021e5e1c_2481) = 0;
#if defined(jpn)
    *(int*)(var0 + 0x1730) = 0xc;
    *(int*)(var0 + 0x1734) = 0x10;
    func_02042b98((void*)var0, *(int*)(var0 + 0x1730), 0x90, 0x100, 0x30);
#else
    func_02042b98((void*)var0, 2, 0x92, 0xfc, 0x4a);
#endif
    *(unsigned char*)(var0 + 0x1000 + Enum_ov025_021e5e1c_2482) = 0;
    *(int*)(var0 + Enum_ov025_021e5e1c_2456) = 1;
}
