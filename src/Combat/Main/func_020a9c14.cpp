#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/GrottoStruct.h"
#include "Grotto/Main/TreasureMapDataStructs.h"
#include "std_library_functions.h"

struct Struct_0201165c {
    int entranceX;
    int unknown_4_;
    int unknown_8_;
    unsigned char environment;
    char pad1[3];
    unsigned char unknown_10_;
};
extern "C" void func_0201165c(char*, const void*, int, Struct_0201165c);
extern "C" void func_020a3720();
extern "C" void func_020a395c();
struct Struct_020a9c14 {
    unsigned char unknown_0_;
    unsigned char flags;
    TreasureMapMetadata unknown_2_[99];
};
struct Struct_020a9c14_2 {
#if defined(jpn)
    unsigned char prefix[0x6000];
#else
    unsigned char prefix[0x6400];
#endif
    Struct_020a9c14 mapList;
};
struct Struct_020a9c14_3 {
#if defined(jpn)
    unsigned char prefix[0x2b4];
#else
    unsigned char prefix[0xf4];
#endif
    Struct_020a9c14_2 bank;
};
struct Struct_020a9c14_4 { int x; int y; int z; };
typedef void (*Type_020a9c14)(char*, const void*, int, Struct_020a9c14_4, unsigned int, unsigned int);

// USA: func_020a9c14
extern "C" ARM int func_020a9c14(const void* saved) {
    GameState* state = GameState::GetInstance();
    Struct_020a9c14* list = &((Struct_020a9c14_3*)state)->bank.mapList;
    memcpy(list, saved, 0xad6);
    TreasureMapMetadata* map = list->unknown_2_;
    int index = 0;
    while (index < 99) {
        if (map->GetInitialByteUnknownBit()) break;
        if (index == 98) return 1;
        index++;
        map++;
    }
    func_020a3720();
    DetailedTreasureMapData detail;
    ExportDetailedTreasureMapData(map, &detail, false, 0);
    func_020a395c();
    if (detail.mapType_ == 1) {
        reinterpret_cast<Type_020a9c14>(func_0201165c)((char*)state, map, detail.entranceZoneID_, *reinterpret_cast<Struct_020a9c14_4*>(&detail.entranceX_), detail.regular_.environ_, detail.regular_.startingMonsterRank_);
    } else if (detail.mapType_ == 2) {
        reinterpret_cast<Type_020a9c14>(func_0201165c)((char*)state, map, detail.entranceZoneID_, *reinterpret_cast<Struct_020a9c14_4*>(&detail.entranceX_), 0, 0);
    }
    GrottoStruct* grotto = state->GetGrottoStruct();
    strcpy(grotto->activeMapImageName, detail.mapImageName_);
    if (detail.mapType_ == 1) {
        sprintf(grotto->activeMapNameNoLevel, detail.regular_.nameNoLevel_);
        grotto->activeMapLevel = detail.regular_.level_;
    } else if (detail.mapType_ == 2) {
        sprintf(grotto->activeMapNameNoLevel, detail.legacy_.mapNameNoLevel_);
        grotto->activeMapLevel = detail.legacy_.level_;
    }
    return 1;
}
