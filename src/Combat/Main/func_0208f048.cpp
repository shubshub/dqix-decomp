#include <globaldefs.h>
#include "Combat/LootPointEvent.h"
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

#include "GameState/GameState.h"

extern "C" void* Zone3D_GetInstance(void);
extern "C" int _s32_div_f(int a, int b);

struct Struct_0208f048 {
    char pad[0x188];
    Struct_0208ec78 unknown_188_;
    Struct_0208ec78 unknown_18c_;
};

// USA: func_0208f048
extern "C" ARM void func_0208f048(unsigned char* p0) {
    void* g;
    char* var1;
    int total;
    int count1;
    int i;
    GameState* bs;
    struct Struct_0208f048* var6;

    if (*p0 != 0x62) {
        return;
    }

    g = Zone3D_GetInstance();
    var1 = (char*)((int)g + (IS_JPN ? 0x1860 : 0x1840));
    total = _s32_div_f(*(int*)(var1 + 0xb34), 100) + 4;
    if (total > 14) {
        total = 14;
    }
    count1 = total - 7;

    bs = GameState::GetInstance();
    var6 = (struct Struct_0208f048*)((char*)bs + (IS_JPN ? 0x5a7c : 0x5cdc));

    i = 0;
    while (count1 > 0) {
        unsigned int v = var6->unknown_18c_.word;
        unsigned int var8 = (v << 7) >> 24;
        var6->unknown_18c_.word = (v & 0xfe01ffff) | (((var8 | (1u << i)) << 24) >> 7);
        i++;
        count1--;
    }
    func_ov017_021d38f8(0, 0, (var6->unknown_18c_.word << 7) >> 24, 0x63, &var6->unknown_18c_);

    if (i > 0) {
        i = 0;
        total = 7;
    }
    while (total > 0) {
        unsigned int v = var6->unknown_188_.word;
        unsigned int var10 = (v << 7) >> 24;
        var6->unknown_188_.word = (v & 0xfe01ffff) | (((var10 | (1u << i)) << 24) >> 7);
        total--;
        i++;
    }
    func_ov017_021d38f8(0, 0, (var6->unknown_188_.word << 7) >> 24, 0x62, &var6->unknown_188_);
}
