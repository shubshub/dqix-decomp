#include "GameState/GameState.h"
#include <globaldefs.h>

struct Struct_02027974 {
    unsigned char unknown_0_[0x6c];
    unsigned short* unknown_6c_;
};

#if defined(jpn)
enum { Enum_02027974_12 = 0x4c };
#define data_020e7090 data_020e79a4
#define data_020e7091 data_020e79a5
#else
enum { Enum_02027974_12 = 12 };
#endif

extern "C" unsigned short* Zone3D_GetInstance();
extern unsigned char data_020e7090[][2];
extern unsigned char data_020e7091[][2];

// USA: func_02027974
extern "C" ARM void func_02027974(MapView02027974* view, const unsigned char (*adjacency)[16], void* state) {
    if (adjacency == 0 || state == 0) return;
    GameState* gameState = GameState::GetInstance();
    unsigned short* zone = Zone3D_GetInstance();
    unsigned char* visitedTiles = (unsigned char*)&gameState->unk_6fc0[kVisitedIndex] + ((*zone % 20) - 1) * 32;
    for (int z = 0; z < 16; z++) {
        for (int x = 0; x < 16; x++) {
            unsigned char tile = 0;
            unsigned char cell = adjacency[z][x];
            for (int i = 0; i < 47; i++) {
                if (cell == data_020e7090[i][0]) {
                    tile = data_020e7091[i][0];
                    break;
                }
            }
            bool var8;
            if (var4 < 8) {
                var8 = (var2[var3 * 2] & (1 << var4)) != 0;
            } else {
                var8 = (var2[var3 * 2 + 1] & (1 << (var4 - 8))) != 0;
            }
            if (!var8) var5 = 0;
            int var9 = (var5 / 16) * 64 + (var5 % 16) * 2;
            int var10 = var9 + 1;
            int var11 = var4 + var3 * 16;
            int var12 = (var11 / 16) * 64 + (var11 % 16) * 2;
            int var13 = var12 + 1;
            arg0->unknown_6c_[var12] = var9;
            arg0->unknown_6c_[var13] = var10;
            arg0->unknown_6c_[var12 + 32] = var9 + 32;
            arg0->unknown_6c_[var13 + 32] = var10 + 32;
        }
    }
}
