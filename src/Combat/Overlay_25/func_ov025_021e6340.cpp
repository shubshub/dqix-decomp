#include <globaldefs.h>

struct Struct_ov000_02175808 {
    char unknown0[8];
    unsigned short argument;
};
struct Struct_ov025_021e6340 {
#if defined(jpn)
    char unknown0[0x70f4];
#else
    char unknown0[0x6f04];
#endif
    unsigned short unknown_6f04_;
};
extern int g_sePlayer;
extern "C" Struct_ov025_021e6340* func_ov000_02160130();
extern "C" void SePlayer_PlayExtra(void*, int, int);

// USA: func_ov025_021e6340
extern "C" ARM int func_ov025_021e6340(Struct_ov000_02175808* command) {
    Struct_ov025_021e6340* work = func_ov000_02160130();
    work->unknown_6f04_ = command->argument;
    SePlayer_PlayExtra(&g_sePlayer, command->argument, 0);
    return 1;
}
