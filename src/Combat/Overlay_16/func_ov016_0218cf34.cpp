#include <globaldefs.h>

struct Struct_ov016_0219d144_3 {
#if defined(jpn)
 unsigned char pad[0x30];
#else
 unsigned char pad[0x44];
#endif
 unsigned long long counter; };
extern struct Struct_ov016_0219d144_3 data_ov016_0219d144;

// USA: func_ov016_0218cf34
extern "C" ARM void func_ov016_0218cf34(void) {
    data_ov016_0219d144.counter++;
}
