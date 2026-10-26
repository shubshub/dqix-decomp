#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov003_02160240_1187 = 0x2cb };
enum { Enum_ov003_02160240_804 = 0x20c };
enum { Enum_ov003_02160240_792 = 0x200 };
enum { Enum_ov003_02160240_912 = 0x278 };
#else
enum { Enum_ov003_02160240_1187 = 0x4a3 };
enum { Enum_ov003_02160240_804 = 0x324 };
enum { Enum_ov003_02160240_792 = 0x318 };
enum { Enum_ov003_02160240_912 = 0x390 };
#endif

struct Struct_0207fd88;
extern "C" void func_0207fd88(struct Struct_0207fd88* obj);
extern "C" void func_ov003_0216720c(char* obj);
extern "C" void func_ov003_0216757c(char* obj);
extern "C" void func_020e2d24(int* obj, int a, int b);
struct Struct_020e28dc;
extern "C" int func_020e28dc(struct Struct_020e28dc* o);
struct Struct_020439b0;
extern "C" void func_020e2cc4(struct Struct_020439b0* obj, int enabled);
struct Struct_020e2834;
extern "C" void func_020e2834(struct Struct_020e2834* self);

// USA: func_ov003_02160240
extern "C" ARM void func_ov003_02160240(char* obj) {
    if (*(unsigned char*)(obj + Enum_ov003_02160240_1187) == 0) return;
    if (*(struct Struct_0207fd88**)(obj + Enum_ov003_02160240_804) != 0) {
        func_0207fd88(*(struct Struct_0207fd88**)(obj + Enum_ov003_02160240_804));
    }
    func_ov003_0216720c(obj);
    if (*(char**)(obj + Enum_ov003_02160240_792) != 0) {
        func_ov003_0216757c(*(char**)(obj + Enum_ov003_02160240_792));
    }
    if (*(void**)(obj + Enum_ov003_02160240_912) == 0) return;
    unsigned char* r4 = *(unsigned char**)((char*)(*(void**)(obj + Enum_ov003_02160240_912)) + 0x10);
    int flag;
    func_020e2d24((int*)(r4 + 0x28), 0x19, 1);
    flag = func_020e28dc((struct Struct_020e28dc*)*(void**)(obj + Enum_ov003_02160240_912));
    func_020e2cc4((struct Struct_020439b0*)(r4 + 0x28), flag);
    func_020e2834((struct Struct_020e2834*)*(void**)(obj + Enum_ov003_02160240_912));
}
