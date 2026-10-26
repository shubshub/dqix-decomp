#include <globaldefs.h>

#if defined(jpn)
enum { Enum_020dbc5c_15304 = 0x39a8, Enum_020dbc5c_14084 = 0x34f4 };
#else
enum { Enum_020dbc5c_15304 = 0x3bc8, Enum_020dbc5c_14084 = 0x3704 };
#endif

struct Struct_020dbc5c;
extern "C" void func_020dbc9c(struct Struct_020dbc5c* p);
struct TailList020469b4;
struct TailNode020469b4;
extern "C" void func_020469b4(struct TailList020469b4* list, struct TailNode020469b4* node);

struct Struct_020dbc5c_2 {
    char pad[8];
    signed char byte8;
    char pad2[11];
};

// USA: func_020dbc5c
extern "C" ARM void func_020dbc5c(char* obj, int id) {
    struct Struct_020dbc5c_2* e = (struct Struct_020dbc5c_2*)(obj + Enum_020dbc5c_15304 + (id - 1) * 0x14);
    func_020dbc9c((struct Struct_020dbc5c*)e);
    e->byte8 = (signed char)id;
    func_020469b4(*(struct TailList020469b4**)(obj + Enum_020dbc5c_14084), (struct TailNode020469b4*)e);
}
