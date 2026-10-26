#include <globaldefs.h>

extern int data_020f1730;
extern int data_ov032_02200180;

extern "C" int SoundPlayer_OpenArchive(void*, void*, void*, int, int);

// USA: func_0209c2b8
extern "C" ARM int func_0209c2b8(void* ctx) {
    return SoundPlayer_OpenArchive(ctx, &data_020f1730, &data_ov032_02200180, 0xa2000, 1);
}
