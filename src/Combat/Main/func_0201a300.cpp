#include <globaldefs.h>
#include "GameState/GameState.h"
#include "World/GrottoTileGraph.h"
#include "std_library_functions.h"

struct InitStruct;
struct Array020286fc;
struct Array02028754;
struct Array0202834c;
struct BoundedHalfwordPairList;
struct Container02028170;
struct List_020283c0;
struct AppendPairList;
struct TimeStamp020105a8;
void InitializeStruct020280f8(InitStruct*);
void NodeGraph_Reset(InitStruct*);
void AllocateAndClearHeaderArray020286fc(Array020286fc*, SafeAllocator*, int);
void AllocateClearArray02028754(Array02028754*, SafeAllocator*, int);
void AllocateArray0202834c(Array0202834c*, SafeAllocator*, int);
void AppendHalfwordPairCapped_02028378(BoundedHalfwordPairList*, HalfwordPair*);
int GenerateGrottoObjectPositionOrientation(void*, int, int, int*, int*, const TileFeaturePlacementData*, bool);
extern "C" void func_02028170(Struct_0201a300_10*, Struct_0201a300_3*);
extern "C" Struct_0201a300_3* func_020283c0(Struct_0201a300_11*, int);
extern "C" void func_020281d8(Struct_0201a300_12*, Struct_0201a300*);
extern "C" void func_02028214(Struct_01ff87a4*, SafeAllocator*);
extern "C" void func_020105a8(Struct_020105a8*, int*);

static inline unsigned int inline_0201a300(unsigned int arg0, unsigned int arg1) {
    SDK_ASSERT(arg0 < 16 && arg1 < 16);
    return arg0 + (arg1 << 4);
}

// USA: func_0201a300
extern "C" ARM int func_0201a300(Zone3D* arg0, int arg1, Struct_0201a300_4* arg2, const TileFeaturePlacementData* arg3, FloorMap* arg4) {
    GameState* var0 = GameState::GetInstance();
    if (!arg2) return 1;
    srand(arg2->unknown_0_ % 20);
    unsigned char var1[256];
    FloorMap* var2 = arg4 ? arg4 : &arg0->grotto_.floorMap_;
    memcpy(var1, var2->pMapData, 256);
    int var3 = 0;
    int var4 = 0;
    int var5;
    int var6;
    unsigned int var7;
    for (var5 = 1; var5 < 15; var5++) {
        for (var6 = 1; var6 < 15; var6++) {
            var7 = var5;
            var7 -= 1;
            int var8 = var1[var6 + (var5 << 4)];
            if (var8 == 1 || var8 == 3) continue;
            int var9 = var1[var6 - 1 + (var5 << 4)];
            int var10 = var1[var6 + (var7 << 4)];
            if (var9 != 1 && var9 != 3) var4++;
            var3++;
            if (var10 != 1 && var10 != 3) var4++;
        }
    }
    int remaining = 0x1020 - ((count << 4) + (neighbors << 3));
    if (remaining < 0) neighbors -= abs(remaining / 8) + 1;
    InitializeStruct020280f8((InitStruct*)&owner->lists);
    NodeGraph_Reset((InitStruct*)&owner->lists);
    AllocateAndClearHeaderArray020286fc((Array020286fc*)&owner->lists, owner->allocator, count);
    AllocateClearArray02028754((Array02028754*)&owner->lists, owner->allocator, neighbors);
    AllocateArray0202834c((Array0202834c*)&owner->lists, owner->allocator, 1);
    HalfwordPair origin;
    origin.first = 0;
    origin.second = 0;
    AppendHalfwordPairCapped_02028378((BoundedHalfwordPairList*)&owner->lists, &origin);
    for (int y = 1; y < 15; y++) {
        int previousY;
        int x = 1;
        for (; x < 15; x++) {
            previousY = y - 1;
            int value = tiles[x + (y << 4)];
            int id = x + (y << 4);
            if (value == 1 || value == 3) continue;
            AppendEntry pair;
            Elem02028170 feature;
            int tileX;
            int tileZ;
            feature.id = 0;
            feature.field_1 = 0;
            feature.field_2 = 0;
            feature.field_c = 0;
            feature.flags = 0;
            GenerateGrottoObjectPositionOrientation(zone, x, y, &tileX, &tileZ, placements, false);
            feature.field_6 = 0;
            feature.x = tileX >> 12;
            feature.z = tileZ >> 12;
            if (value == 4) feature.flags |= 2;
            feature.id = id;
            AppendCappedElement02028170((Container02028170*)&owner->lists, &feature);
            int leftId = x - 1 + (y << 4);
            int left = tiles[leftId];
            int aboveId = x + (previousY << 4);
            int above = tiles[aboveId];
            if (left != 1 && left != 3) {
                pair.second = 0;
                pair.first = 0;
                pair.first = FindListEntryById((List_020283c0*)&owner->lists, GrottoTileId0201a300(x, y));
                pair.second = FindListEntryById((List_020283c0*)&owner->lists, leftId);
                AppendPairToBoundedList_020281d8((AppendPairList*)&owner->lists, &pair);
            }
            if (var25 != 1 && var25 != 3) {
                var18.unknown_4_ = 0;
                var18.unknown_0_ = 0;
                var18.unknown_0_ = func_020283c0((Struct_0201a300_11*)&arg2->unknown_18_, var17);
                var18.unknown_4_ = func_020283c0((Struct_0201a300_11*)&arg2->unknown_18_, var24);
                func_020281d8((Struct_0201a300_12*)&arg2->unknown_18_, &var18);
            }
        }
    }
    func_02028214(&arg2->unknown_18_, arg2->unknown_10_);
    int var26;
    func_020105a8((Struct_020105a8*)var0, &var26);
    srand(var26);
    return 1;
}
