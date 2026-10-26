#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_02154fd0_504 = 0x1f4 };
enum { Enum_ov003_02154fd0_516 = 0x200 };
#else
enum { Enum_ov003_02154fd0_504 = 0x1f8 };
enum { Enum_ov003_02154fd0_516 = 0x204 };
#endif

extern "C" void func_ov023_021eb4f4(char* obj);

struct Struct_0207fd88;
extern "C" void func_0207fd88(struct Struct_0207fd88* obj);

struct Struct_020e2834;
extern "C" void func_020e2834(struct Struct_020e2834* self);

// USA: func_ov003_02154fd0
extern "C" ARM void func_ov003_02154fd0(char* obj) {
    if (*(unsigned char*)(obj + Enum_ov003_02154fd0_504) == 0) return;
    char* var0 = *(char**)(obj + Enum_ov003_02154fd0_516);
    if (var0 != 0) {
        func_ov023_021eb4f4(var0);
    } else {
        struct Struct_0207fd88* var1 = *(struct Struct_0207fd88**)(obj + 0x18);
        if (var1 != 0) {
            func_0207fd88(var1);
        }
    }
    struct Struct_020e2834* var2 = *(struct Struct_020e2834**)(obj + 0x1c);
    if (var2 != 0) {
        func_020e2834(var2);
    }
}
