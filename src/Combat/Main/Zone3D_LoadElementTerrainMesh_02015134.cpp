#include "World/ZoneResourceInitialization.h"
#include "Filesystem/FileIO.h"
#include <globaldefs.h>

void Zone3D_FormatElementFilePath(int id, char* ext, char* outBuf);
void* GetFileFromNARCInMemory(const char* path);
void TerrainMesh_Clear(void* p);
struct RenderParams0204bf44;
struct RenderSource0204bf44;
void TerrainMesh_Init(RenderParams0204bf44*, void*, RenderSource0204bf44*, unsigned int);

extern char data_020ef1ee;  // "col2"

// The terrain mesh a .col2 file is read into (TerrainMesh_CollectPolygons' TerrainMesh: 0x4c bytes)
enum { kTerrainMeshSize = 0x4c };

// Main, originally func_02015134 (USA 0x02015134, EUR 0x02015144, JPN 0x02014f00)
extern "C" ARM int Zone3D_LoadElementTerrainMesh(Zone3D* zone, Struct02012ff0* tracker, Src02015134* source) {
    Out02015134* resource = (Out02015134*)tracker;
    SafeAllocator* allocator = zone->pAllocator_68_;
    char filename[0x50];
    unsigned int fileLength;
    Zone3D_FormatElementFilePath(source->id, &data_020ef1ee, filename);
    void* file = GetFileFromNARCInMemory(filename);
    if (file) {
        resource->field4 = allocator->Allocate(kTerrainMeshSize);
        if (resource->field4 == 0) return 0;
        void* decompressed = DecompressLZ77FileIntoAllocatedSpace(*allocator, file, fileLength);
        if (decompressed == 0) return 0;
        TerrainMesh_Clear(resource->field4);
        TerrainMesh_Init((RenderParams0204bf44*)resource->field4, allocator, (RenderSource0204bf44*)decompressed, fileLength);
    }
    resource->flag = 1;
    return 1;
}
