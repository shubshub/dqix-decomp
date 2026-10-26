#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov025_021e8248_12 = 0x4 };
#else
enum { Enum_ov025_021e8248_12 = 0xc };
#endif

struct Struct_ov025_021ef988_34 { char pad[Enum_ov025_021e8248_12]; char* target; };
extern struct Struct_ov025_021ef988_34 data_ov025_021ef988;

// USA: func_ov025_021e8248
extern "C" ARM int func_ov025_021e8248(unsigned char* obj) {
    char* base = data_ov025_021ef988.target + 0x540;
    unsigned short f = *(unsigned short*)(base + 0x28);
    f |= 1;
    *(unsigned short*)(base + 0x28) = f;
    *(unsigned char*)(base + 0x34) = obj[0xc];
    short* dst = (short*)(base + 0x2a);
    short* src = (short*)(obj + 8);
    unsigned char i = 0;
    while (i < 2) {
        *dst = *src;
        src++;
        dst++;
        i++;
    }
    return 1;
}
