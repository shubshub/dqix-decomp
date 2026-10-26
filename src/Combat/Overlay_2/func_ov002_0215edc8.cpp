#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov002_0215edc8_9284 = 0x27c + 0x2000, Enum_ov002_0215edc8_9276 = 0x274 + 0x2000 };
#else
enum { Enum_ov002_0215edc8_9284 = 0x44 + 0x2400, Enum_ov002_0215edc8_9276 = 0x3c + 0x2400 };
#endif

struct Struct_0209aa40;
extern "C" int func_0209aa40(struct Struct_0209aa40* holder);

struct Struct_0209a670;
extern "C" int func_0209a670(struct Struct_0209a670* obj);

// USA: func_ov002_0215edc8
extern "C" ARM int func_ov002_0215edc8(unsigned char* obj) {
    if (func_0209aa40((struct Struct_0209aa40*)(obj + Enum_ov002_0215edc8_9284)) <= 0) {
        goto ret0;
    }
    if (func_0209a670((struct Struct_0209a670*)(obj + Enum_ov002_0215edc8_9276)) > 0) {
        return 1;
    }
ret0:
    return 0;
}
