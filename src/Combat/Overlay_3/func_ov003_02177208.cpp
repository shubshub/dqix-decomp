#include <globaldefs.h>
#if defined(jpn)
enum { kRegion89c = 0x818 };
enum { Enum_ov003_02177208_4156 = 0xfb8 };
#else
enum { kRegion89c = 0x89c };
enum { Enum_ov003_02177208_4156 = 0x103c };
#endif

struct Struct_0207fdcc_2;
extern "C" void func_02080c20(struct Struct_0207fdcc_2* obj, int key);
extern "C" void func_02080c68(void* obj, int id, int value);
struct Struct_02080fa8;
extern "C" void func_02080fa8(struct Struct_02080fa8* obj, int id, int value);
extern "C" int func_02080b2c(void* obj, int id);
extern "C" void func_020813ec(void* obj, int key);

// USA: func_ov003_02177208
extern "C" ARM void func_ov003_02177208(char* obj) {
    struct Struct_0207fdcc_2* var0 = *(struct Struct_0207fdcc_2**)(obj + kRegion89c);
    func_02080c20(var0, 9);
    func_02080c68(var0, 9, 0);
    func_02080fa8((struct Struct_02080fa8*)var0, 0x57, *(unsigned char*)(obj + Enum_ov003_02177208_4156));
    func_02080b2c(var0, 0x58);
    func_02080b2c(var0, 0x59);
    func_020813ec(var0, 9);
}
