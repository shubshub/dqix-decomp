#include <globaldefs.h>

extern "C" void GX_SetGraphicsMode(int mode, int flagsA, int valB);

struct Struct_ov016_0219d0c0_5 {
#if defined(jpn)
 char pad[0x34];
#else
 char pad[0x18];
#endif
 int flag; };
extern Struct_ov016_0219d0c0_5 data_ov016_0219d0c0;

// USA: func_ov016_0218be7c
extern "C" ARM void func_ov016_0218be7c(void) {
    if (data_ov016_0219d0c0.flag == 0) {
        GX_SetGraphicsMode(6, 0, 0);
    } else {
        GX_SetGraphicsMode(2, 0, 0);
    }
    data_ov016_0219d0c0.flag ^= 1;
}
