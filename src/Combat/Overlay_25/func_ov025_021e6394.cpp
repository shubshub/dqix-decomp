#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov025_021e6394_12 = 0x4 };
#else
enum { Enum_ov025_021e6394_12 = 0xc };
#endif

struct Struct_ov025_021ef988_22 { char pad[Enum_ov025_021e6394_12]; void* target; };
extern struct Struct_ov025_021ef988_22 data_ov025_021ef988;

struct Struct_ov025_021e6394 { char pad[8]; int value; };

// USA: func_ov025_021e6394
extern "C" ARM int func_ov025_021e6394(struct Struct_ov025_021e6394* p) {
    *(int*)((char*)data_ov025_021ef988.target + 0x560) = p->value;
    return 1;
}
