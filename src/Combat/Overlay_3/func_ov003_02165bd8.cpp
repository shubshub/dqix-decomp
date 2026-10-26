#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { Enum_ov003_02165bd8_1116 = 0x284 };
enum { Enum_ov003_02165bd8_1183 = 0x2c7 };
#else
enum { Enum_ov003_02165bd8_1116 = 0x45c };
enum { Enum_ov003_02165bd8_1183 = 0x49f };
#endif

extern "C" void func_ov003_02160c58(unsigned char* self, short* arg1, short* arg2);
extern "C" void* GameState_GetParty(GameState*);

extern "C" void func_ov003_02165c9c(unsigned char* self);

// USA: func_ov003_02165bd8
extern "C" ARM void func_ov003_02165bd8(unsigned char* self) {
    short var0, var1;
    func_ov003_02160c58(self, &var0, &var1);

    unsigned char byteF7C = *((unsigned char*)GameState_GetParty(GameState::GetInstance()) + 0xf7c);
    var1 = var1 - (byteF7C - 1);

    unsigned char* base = (unsigned char*)GameState_GetParty(GameState::GetInstance()) + 0x2000;
    int var4 = base[0xc8c];
    if (var1 != 0) {
        var4 += 1;
    }
    int limit = (var4 + 3) / 4;

    int flags = *(int*)(self + Enum_ov003_02165bd8_1116);
    if (flags & 0x10) {
        self[Enum_ov003_02165bd8_1183] = (signed char)self[Enum_ov003_02165bd8_1183] + 1;
    } else if (flags & 0x20) {
        self[Enum_ov003_02165bd8_1183] = (signed char)self[Enum_ov003_02165bd8_1183] - 1;
    }
    if (limit <= (signed char)self[Enum_ov003_02165bd8_1183]) {
        self[Enum_ov003_02165bd8_1183] = 0;
    } else if ((signed char)self[Enum_ov003_02165bd8_1183] < 0) {
        self[Enum_ov003_02165bd8_1183] = limit - 1;
    }

    func_ov003_02165c9c(self);
}
