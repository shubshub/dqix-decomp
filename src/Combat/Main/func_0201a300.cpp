#include <globaldefs.h>
#include "GameState/GameState.h"
#include "World/GrottoTileGraph.h"
#include "std_library_functions.h"

struct InitStruct;
struct Struct_0201a300_6;
struct Struct_0201a300_7;
struct Struct_0201a300_8;
struct Struct_0201a300_9;
struct Struct_0201a300_10;
struct Struct_0201a300_11;
struct Struct_0201a300_12;
struct Struct_020105a8;
extern "C" void func_020280f8(InitStruct*);
extern "C" void NodeGraph_Reset(InitStruct*);
extern "C" void func_020286fc(Struct_0201a300_6*, SafeAllocator*, int);
extern "C" void func_02028754(Struct_0201a300_7*, SafeAllocator*, int);
extern "C" void func_0202834c(Struct_0201a300_8*, SafeAllocator*, int);
extern "C" void func_02028378(Struct_0201a300_9*, Struct_0201a300_2*);
int GenerateGrottoObjectPositionOrientation(void*, int, int, int*, int*, const TileFeaturePlacementData*, bool);
extern "C" void func_02028170(Struct_0201a300_10*, Struct_0201a300_3*);
extern "C" Struct_0201a300_3* func_020283c0(Struct_0201a300_11*, int);
extern "C" void func_020281d8(Struct_0201a300_12*, Struct_0201a300*);
extern "C" void func_02028214(Struct_01ff87a4*, SafeAllocator*);
extern "C" void func_020105a8(Struct_020105a8*, int*);

static inline unsigned int inline_0201a300(unsigned int x, unsigned int y) {
    SDK_ASSERT(x < 16 && y < 16);
    return x + (y << 4);
}

// USA: func_0201a300
extern "C" ARM int func_0201a300(Zone3D* zone, int floor, Struct_0201a300_4* owner, const TileFeaturePlacementData* placements, FloorMap* map) {
    GameState* state = GameState::GetInstance();
    if (!owner) return 1;
    srand(owner->zoneId % 20);
    unsigned char tiles[256];
    FloorMap* var2 = map ? map : &zone->grotto_.floorMap_;
    memcpy(tiles, var2->pMapData, 256);
    int count = 0;
    int var4 = 0;
    int y;
    int x;
    unsigned int var7;
    for (y = 1; y < 15; y++) {
        for (x = 1; x < 15; x++) {
            var7 = y;
            var7 -= 1;
            int value = tiles[x + (y << 4)];
            if (value == 1 || value == 3) continue;
            int left = tiles[x - 1 + (y << 4)];
            int above = tiles[x + (var7 << 4)];
            if (left != 1 && left != 3) var4++;
            count++;
            if (above != 1 && above != 3) var4++;
        }
    }
    int remaining = 0x1020 - ((count << 4) + (var4 << 3));
    if (remaining < 0) var4 -= abs(remaining / 8) + 1;
    func_020280f8((InitStruct*)&owner->lists);
    NodeGraph_Reset((InitStruct*)&owner->lists);
    func_020286fc((Struct_0201a300_6*)&owner->lists, owner->allocator, count);
    func_02028754((Struct_0201a300_7*)&owner->lists, owner->allocator, var4);
    func_0202834c((Struct_0201a300_8*)&owner->lists, owner->allocator, 1);
    Struct_0201a300_2 origin;
    origin.first = 0;
    origin.second = 0;
    func_02028378((Struct_0201a300_9*)&owner->lists, &origin);
    for (int y = 1; y < 15; y++) {
        int var14;
        int x = 1;
        for (; x < 15; x++) {
            var14 = y - 1;
            int value = tiles[x + (y << 4)];
            int id = x + (y << 4);
            if (value == 1 || value == 3) continue;
            Struct_0201a300 pair;
            Struct_0201a300_3 feature;
            int tileX;
            int tileZ;
            feature.id = 0;
            feature.unknown_1_ = 0;
            feature.unknown_2_ = 0;
            feature.unknown_c_ = 0;
            feature.flags = 0;
            GenerateGrottoObjectPositionOrientation(zone, x, y, &tileX, &tileZ, placements, false);
            feature.unknown_6_ = 0;
            feature.x = tileX >> 12;
            feature.z = tileZ >> 12;
            if (value == 4) feature.flags |= 2;
            feature.id = id;
            func_02028170((Struct_0201a300_10*)&owner->lists, &feature);
            int var22 = x - 1 + (y << 4);
            int left = tiles[var22];
            int var24 = x + (var14 << 4);
            int above = tiles[var24];
            if (left != 1 && left != 3) {
                pair.second = 0;
                pair.first = 0;
                pair.first = func_020283c0((Struct_0201a300_11*)&owner->lists, inline_0201a300(x, y));
                pair.second = func_020283c0((Struct_0201a300_11*)&owner->lists, var22);
                func_020281d8((Struct_0201a300_12*)&owner->lists, &pair);
            }
            if (above != 1 && above != 3) {
                pair.second = 0;
                pair.first = 0;
                pair.first = func_020283c0((Struct_0201a300_11*)&owner->lists, id);
                pair.second = func_020283c0((Struct_0201a300_11*)&owner->lists, var24);
                func_020281d8((Struct_0201a300_12*)&owner->lists, &pair);
            }
        }
    }
    func_02028214(&owner->lists, owner->allocator);
    int elapsed;
    func_020105a8((Struct_020105a8*)state, &elapsed);
    srand(elapsed);
    return 1;
}
