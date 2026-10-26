#include <globaldefs.h>

struct DebugMenu
{
    char unk_0[0x5c];
    short unknown_5c_;
    short unknown_5e_;
    short cursor_;
    char unknown_62_[0x80 - 0x62];
};

// USA: func_ov015_02191284
extern "C" ARM int func_ov015_02191284(DebugMenu* menu) {
    return menu->cursor_ - menu->unknown_5c_;
}
