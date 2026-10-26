#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov000_0217f62c_7538 = 0x1faa };
#else
enum { Enum_ov000_0217f62c_7538 = 0x1d72 };
#endif

extern "C" int func_ov000_0217f6bc(void* obj);
extern "C" void* func_ov000_02161318(void* obj, int id);
struct Struct_ov000_02170fd0;
extern "C" void func_ov000_02170fd0(struct Struct_ov000_02170fd0* obj, int b);
extern "C" void func_ov000_02175258(void* obj);
extern "C" void func_ov000_0217a8f4(void* obj);

// USA: func_ov000_0217f62c
extern "C" ARM int func_ov000_0217f62c(void* objRaw) {
    char* obj = (char*)objRaw;
    int n = func_ov000_0217f6bc(obj);
    int var2 = (n >= 0 && n <= 3) ? 1 : 0;
    if (var2) {
        struct Struct_ov000_02170fd0* entry = (struct Struct_ov000_02170fd0*)func_ov000_02161318(obj, n);
        if (entry != 0) {
            *(int*)(obj + 0x17c) = *(int*)((char*)entry + 0x4c);
            func_ov000_02170fd0(entry, 0);
            *(int*)(obj + 0x910) = 0;
            *(int*)(obj + 0x914) = 0;
            *(int*)(obj + 0x918) = 0;
            *(int*)(obj + 0x91c) = 0;
            unsigned short var4 = *(unsigned short*)(obj + Enum_ov000_0217f62c_7538);
            var4 = var4 & ~0x38;
            *(unsigned short*)(obj + Enum_ov000_0217f62c_7538) = var4;
            func_ov000_02175258(obj);
            func_ov000_0217a8f4(obj);
            return 0;
        }
    }
    return 1;
}
