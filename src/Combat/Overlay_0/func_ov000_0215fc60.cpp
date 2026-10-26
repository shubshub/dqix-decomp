#include <globaldefs.h>

struct Struct_ov000_0215fc60 { char pad[0xfe]; unsigned short val; };

// USA: func_ov000_0215fc60
extern "C" ARM int func_ov000_0215fc60(char* base) {
    unsigned short v = ((struct Struct_ov000_0215fc60*)(base + 0x8100))->val;
    if (v == 0x320) return 1;
    if (v == 0x321) return 2;
    return 0;
}
