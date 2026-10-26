#include <globaldefs.h>

// MapDisplay's ForwardingRecord02024518
struct MapImagePlacement {
    int unknown0;
    int imageIndex;
    int x;
    int y;
};

// MapDisplay: forwarding, forwardingCount
struct MapDisplayPlacements {
    char pad[0x2c];
    MapImagePlacement* placements;
    int placementCount;
};

struct List_020278a4;
extern "C" int MapDisplay_FindPieceIndex(List_020278a4* display, int id);

// Main, originally func_02027910 (USA 0x02027910, EUR 0x02027920, JPN 0x0202717c)
extern "C" ARM void MapDisplay_AddPlacement(MapDisplayPlacements* display, int unknown0, int imageId, int x, int y) {
    display->placements[display->placementCount].unknown0 = unknown0;
    display->placements[display->placementCount].imageIndex = MapDisplay_FindPieceIndex((List_020278a4*)display, imageId);
    display->placements[display->placementCount].x = x;
    display->placements[display->placementCount].y = y;
    display->placementCount++;
}
