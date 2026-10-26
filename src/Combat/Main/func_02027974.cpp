#include "GameState/GameState.h"
#include <globaldefs.h>

struct Struct_02027974 {
    unsigned char unknown0[0x6c];
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
extern "C" ARM void func_02027974(Struct_02027974* view, const unsigned char (*arg1)[16], void* state) {
    if (arg1 == 0 || state == 0) return;
    GameState* gameState = GameState::GetInstance();
    unsigned short* zone = Zone3D_GetInstance();
    unsigned char* visitedTiles = (unsigned char*)&gameState->unk_6fc0[Enum_02027974_12] + ((*zone % 20) - 1) * 32;
    for (int z = 0; z < 16; z++) {
        for (int x = 0; x < 16; x++) {
            unsigned char tile = 0;
            unsigned char cell = arg1[z][x];
            for (int i = 0; i < 47; i++) {
                if (cell == data_020e7090[i][0]) {
                    tile = data_020e7091[i][0];
                    break;
                }
            }
            bool visited;
            if (x < 8) {
                visited = (visitedTiles[z * 2] & (1 << x)) != 0;
            } else {
                visited = (visitedTiles[z * 2 + 1] & (1 << (x - 8))) != 0;
            }
            if (!visited) tile = 0;
            int base = (tile / 16) * 64 + (tile % 16) * 2;
            int base1 = base + 1;
            int pos = x + z * 16;
            int idx = (pos / 16) * 64 + (pos % 16) * 2;
            int idx1 = idx + 1;
            view->unknown_6c_[idx] = base;
            view->unknown_6c_[idx1] = base1;
            view->unknown_6c_[idx + 32] = base + 32;
            view->unknown_6c_[idx1 + 32] = base1 + 32;
        }
    }
}
