#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory.h"
#include <globaldefs.h>

struct State0xbb1c;
struct Obj0203bb3c;

extern "C" void BgImage_Clear(State0xbb1c *state);
extern "C" void BgImage_Load(Obj0203bb3c *state, char *source, SafeAllocator *allocator, int category,
                                          unsigned short flags);

// One piece of the map (MapDisplay::names): a name the map script gives, whose "<name>.obg" BG tile image is
// loaded into image; MapDisplay_DrawFreeScrollMap places the pieces by index (MapDisplay::forwarding)
struct Entry02021578 {
    int field0;
    char *name;
    char image[0x1c];
};

// The MapDisplay fields MapDisplay_LoadMapPieces uses (header: names, nameCount, mapPalette, forwardingFill)
struct MapDisplayPieces_020210f8 {
    char unknown0[0x20];
    Entry02021578 *pieces;
    int pieceCount;
    char unknown28[0x48];
    int mapFirstTile;
    int blankTile;        // MapDisplay_LoadBackgroundPattern: the blank tile uploaded after the background pattern
};

struct Stream0200fd14 {
    char *ptr;
};
extern "C" void ByteStream_Read(Stream0200fd14 *stream, void *dst, unsigned int length);
extern "C" void *__clear(void *dst, int count);

// One entry of the MapDisplay's zone list (header field754, built by the map script): the zones this map covers.
// A type other than 0 puts the zones at (x, y) on this map (MapDisplay_PlaceMembers).
struct Node020211b0 {
    unsigned char type;
    unsigned char id;
    unsigned char zoneCount;
    unsigned char pad3;
    short *zoneIds;
    int x;
    int y;
    Node020211b0 *next;
};

// One record of shipMPos.bin (in minimap.gp2): where the ship is drawn on this map when it is saved at (zoneId, nodeId)
// (MapDisplay_FindShipPosition looks it up by Zone3D::savedActor_)
struct ShipPosition_020211b0 {
    unsigned short zoneId;
    unsigned char nodeId;
    unsigned char pad3;
    short x;
    short z;
};

struct MapDisplayShipPositions_020211b0 {
#if defined(jpn)
    char pad0[0x9d4];
#else
    char pad0[0xaa0];
#endif
    unsigned short count;
    ShipPosition_020211b0 entries[32];
};

// The shipMPos.bin records are kept for the zones 20000-29999 the zone list names
enum {
    kFirstShipPositionZoneId = 20000,
    kLastShipPositionZoneId = 29999,
};

// Main, originally func_020210f8 (USA 0x020210f8, EUR 0x02021108, JPN 0x02020cf4)
extern "C" ARM void MapDisplay_LoadMapPieces(char *receiver, int *pieceTasks, SafeAllocator *allocator) {
    if (pieceTasks == NULL) return;

    MapDisplayPieces_020210f8 *state = reinterpret_cast<MapDisplayPieces_020210f8 *>(receiver);
    BackgroundLoader *loader               = BackgroundLoader::GetInstance();
    void *fileData                         = NULL;
    unsigned int fileLength                = 0;
    state->mapFirstTile                 = state->blankTile + 1;

    for (int index = 0; index < state->pieceCount; index++) {
        loader->GetLoadedFileByID(pieceTasks[index], &fileData, &fileLength);
        BgImage_Clear(reinterpret_cast<State0xbb1c *>(state->pieces[index].image));
        BgImage_Load(reinterpret_cast<Obj0203bb3c *>(state->pieces[index].image),
                                             static_cast<char *>(fileData), allocator, 1, 0);
        BackgroundLoader::GetInstance()->RemoveTask(pieceTasks[index]);
        pieceTasks[index] = -1;
    }
}

// USA: MapDisplay_LoadShipPositions
#if defined(jpn)
typedef int CompletedLoadTask;
#else
typedef int *CompletedLoadTask;
#endif
// Main, originally func_020211b0 (USA 0x020211b0, EUR 0x020211c0, JPN 0x02020dac)
extern "C" ARM void MapDisplay_LoadShipPositions(char *receiver, CompletedLoadTask shipPositionsTask) {
    BackgroundLoader *loader = BackgroundLoader::GetInstance();
    Stream0200fd14 stream;
    stream.ptr              = 0;
    unsigned int fileLength = 0;
#if defined(jpn)
    loader->GetLoadedFileByID(shipPositionsTask, (void **) &stream.ptr, &fileLength);
#else
    loader->GetLoadedFileByID(*shipPositionsTask, (void **) &stream.ptr, &fileLength);
#endif

    unsigned short positionZoneIds[16];
    unsigned char positionZoneCount = 0;
    __clear(positionZoneIds, sizeof(positionZoneIds));
#if defined(jpn)
    enum { kZoneListOffset = 0x6a8 };
#else
    enum { kZoneListOffset = 0x754 };
#endif
    for (Node020211b0 *node = *(Node020211b0 **) (receiver + kZoneListOffset); node; node = node->next) {
        for (int i = 0; i < node->zoneCount; i++) {
            unsigned short zoneId = node->zoneIds[i];
            if (zoneId >= kFirstShipPositionZoneId && zoneId <= kLastShipPositionZoneId) {
                positionZoneIds[positionZoneCount++] = zoneId;
            }
        }
    }

    if (stream.ptr) {
        ((MapDisplayShipPositions_020211b0 *) receiver)->count = 0;
        VectorizedMemset(((MapDisplayShipPositions_020211b0 *) receiver)->entries, 0, 0x100);
        unsigned short recordCount = 0;
        ByteStream_Read(&stream, &recordCount, 2);
        for (int i = 0; i < recordCount; i++) {
            unsigned short zoneId;
            unsigned char nodeId;
            short x;
            short z;
            ByteStream_Read(&stream, &zoneId, 2);
            ByteStream_Read(&stream, &nodeId, 1);
            ByteStream_Read(&stream, &x, 2);
            ByteStream_Read(&stream, &z, 2);
            int found = 0;
            for (int j = 0; j < positionZoneCount && !found; j++) {
                if (zoneId == positionZoneIds[j]) found = 1;
            }
            if (found) {
                ShipPosition_020211b0 *entry = &((MapDisplayShipPositions_020211b0 *) receiver)->entries[((MapDisplayShipPositions_020211b0 *) receiver)->count++];
                entry->zoneId        = zoneId;
                entry->nodeId        = nodeId;
                entry->x             = x;
                entry->z             = z;
            }
        }
    }

#if defined(jpn)
    BackgroundLoader::GetInstance()->RemoveTask(shipPositionsTask);
#else
    BackgroundLoader::GetInstance()->RemoveTask(*shipPositionsTask);
    *shipPositionsTask = -1;
#endif
}
