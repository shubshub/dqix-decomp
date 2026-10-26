#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_0217480c_4171 = 0xfc7 };
enum { Enum_ov003_0217480c_4158 = 0xfba };
enum { kRegion89c = 0x818 };
enum { Enum_ov003_0217480c_4172 = 0xfc8 };
#else
enum { Enum_ov003_0217480c_4171 = 0x104b };
enum { Enum_ov003_0217480c_4158 = 0x103e };
enum { kRegion89c = 0x89c };
enum { Enum_ov003_0217480c_4172 = 0x104c };
#endif


struct Struct_0207fcb8;
extern "C" void func_0207fcb8(struct Struct_0207fcb8* obj);
struct Struct_0207fd00;
extern "C" void func_0207fd00(struct Struct_0207fd00* obj);
extern "C" void func_0207fe80(void* obj, int a, int b, int c);
struct Struct_0207fd44_2;
extern "C" void func_0207fd44(struct Struct_0207fd44_2* obj);
extern "C" void func_ov003_02175fd4(void* obj);
struct Struct_ov003_0217480c;
extern "C" void func_ov003_02176098(struct Struct_ov003_0217480c* p);
extern "C" void func_ov003_0217545c(void* obj);
extern "C" void func_ov003_02175504(void* obj);
extern "C" void func_ov003_0217577c(void* obj);

// USA: func_ov003_0217480c
extern "C" ARM void func_ov003_0217480c(void* p) {
    char* obj = (char*)p;
    if (*(unsigned char*)(obj + Enum_ov003_0217480c_4158) != 0) {
        void* sub = *(void**)(obj + kRegion89c);
        func_0207fcb8((struct Struct_0207fcb8*)sub);
        func_0207fd00((struct Struct_0207fd00*)sub);
        func_0207fe80(sub, 1, 2, 1);
        func_0207fd44((struct Struct_0207fd44_2*)sub);
        func_ov003_02175fd4(obj);
        func_ov003_02176098((struct Struct_ov003_0217480c*)obj);
        func_ov003_0217545c(obj);
        func_ov003_02175504(obj);
        func_ov003_0217577c(obj);
        *(unsigned char*)(obj + Enum_ov003_0217480c_4172) = 0;
        *(unsigned char*)(obj + Enum_ov003_0217480c_4171) = 0;
    }
}
