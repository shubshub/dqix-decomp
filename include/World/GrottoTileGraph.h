#pragma once

#include "World/Zone3D.h"

struct Struct_0201a300_3 {
    unsigned char id;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char flags;
    unsigned short x;
    unsigned short unknown_6_;
    unsigned short z;
    int unknown_c_;
};

struct Struct_0201a300 { Struct_0201a300_3* first; Struct_0201a300_3* second; };
struct Struct_0201a300_2 { unsigned short first; unsigned short second; };

struct Struct_01ff87a4 {
    unsigned char tileCapacity;
    unsigned char pairCapacity;
    unsigned char tileCount;
    unsigned char pairCount;
    Struct_0201a300_3* tiles;
    Struct_0201a300* pairs;
    int unknownC;
    int unknown10;
    int unknown14;
    int unknown18;
    int unknown_1c_;
    int unknown20;
    unsigned char originCapacity;
    unsigned char originCount;
    unsigned char unknown_26_[2];
    Struct_0201a300_2* origins;
};

// Known prefix used by the tile graph builder and its resource-load callers.
struct Struct_0201a300_4 {
    unsigned short zoneId;
    unsigned char unknown2[0xa];
    unsigned char loaded;
    unsigned char unknownD[3];
    SafeAllocator* allocator;
#if !defined(jpn)
    int unknown14;
#endif
    Struct_01ff87a4 lists;
};

#if defined(jpn)
#else
#endif

extern "C" int func_0201a300(Zone3D* zone, int floor, Struct_0201a300_4* owner,
                            const TileFeaturePlacementData* placements, FloorMap* map);
