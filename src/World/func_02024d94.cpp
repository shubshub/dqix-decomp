#include "GameState/GameState.h"
#include "World/Zone3D.h"
#include <globaldefs.h>
#if defined(jpn)
enum { Enum_02024d94_1004 = 0xc, Enum_02024d94_8192 = 0x2400, Enum_02024d94_12 = 0x4c };
#else
enum { Enum_02024d94_1004 = 0x3ec, Enum_02024d94_8192 = 0x2000, Enum_02024d94_12 = 12 };
#endif

extern "C" void *Zone3D_GetInstance();
extern "C" void func_02027974(void *object, int adjacencyData, void *state);

static inline char *inline_02024d94(Zone3D *zone) {
    return reinterpret_cast<char *>(zone) + Enum_02024d94_1004;
}

static inline ActiveGrottoClass *inline_02024d94_2(char *zone) {
    return reinterpret_cast<ActiveGrottoClass *>(zone + Enum_02024d94_8192);
}

// USA: func_02024d94
extern "C" ARM void func_02024d94(void *object, unsigned short zoneId, Vector3i *position) {
    GameState *gameState        = GameState::GetInstance();
    Zone3D *zone                = static_cast<Zone3D *>(Zone3D_GetInstance());
    unsigned char *visitedTiles = reinterpret_cast<unsigned char *>(&gameState->unk_6fc0[Enum_02024d94_12]) + ((zoneId % 20) - 1) * 32;

    int tileX = static_cast<int>((4.0f + static_cast<float>(position->x) / 4096.0f) / 8.0f);
    int tileZ = static_cast<int>((4.0f + static_cast<float>(position->z) / 4096.0f) / 8.0f);
    if (tileX < 8) {
        visitedTiles[tileZ * 2] |= 1U << tileX;
    } else {
        visitedTiles[tileZ * 2 + 1] |= 1U << (tileX - 8);
    }

    func_02027974(object, reinterpret_cast<int>(inline_02024d94_2(inline_02024d94(zone))->floorMap_.pMapAdjacencyData),
                  *reinterpret_cast<void **>(static_cast<char *>(object) + 0x6c));
}
