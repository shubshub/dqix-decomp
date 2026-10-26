#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov025_021e8550_6400 = 0x1800, Enum_ov025_021e8550_218 = 0x0 };
#else
enum { Enum_ov025_021e8550_6400 = 0x1900, Enum_ov025_021e8550_218 = 0xda };
#endif

extern "C" int MessageSystem_GetInstance(void);

struct Struct_ov025_021e8550 { char pad[8]; short value; };

// USA: func_ov025_021e8550
extern "C" ARM int func_ov025_021e8550(struct Struct_ov025_021e8550* p) {
    short v = p->value;
    int base = MessageSystem_GetInstance();
    *(short*)((char*)base + Enum_ov025_021e8550_6400 + Enum_ov025_021e8550_218) = v;
    return 1;
}
