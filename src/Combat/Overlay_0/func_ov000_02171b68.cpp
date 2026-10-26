#include <globaldefs.h>

extern "C" int func_ov000_02171bc0(void*);

#if defined(jpn)
enum { Enum_ov000_02171b68_1008 = 0x430, Enum_ov000_02171b68_134 = 0xc6 };
#else
enum { Enum_ov000_02171b68_1008 = 0x3f0, Enum_ov000_02171b68_134 = 0x86 };
#endif

// USA: func_ov000_02171b68
extern "C" ARM void func_ov000_02171b68(void* obj, int idx, void* val) {
    if (idx < 0) return;
    if (idx >= 0x10) return;
    if (val == 0) return;
    *(void**)((char*)obj + idx * 4 + Enum_ov000_02171b68_1008) = val;
    *(unsigned char*)((char*)obj + Enum_ov000_02171b68_134) = (unsigned char)func_ov000_02171bc0(obj);
}
