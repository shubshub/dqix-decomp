#include <globaldefs.h>

struct Struct_ov025_021ef988_22 {
#if defined(jpn)
    char pad[4];
#else
    char pad[0xc];
#endif
    void* target;
};
extern struct Struct_ov025_021ef988_22 data_ov025_021ef988;

struct Struct_ov025_021e8724 { char pad[8]; unsigned char value; };

// USA: func_ov025_021e8724
extern "C" ARM int func_ov025_021e8724(struct Struct_ov025_021e8724* p) {
    *(unsigned char*)((char*)data_ov025_021ef988.target + 0x5d0) = p->value;
    return 1;
}
