#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/Filesystem/NarcHandle.h"
#include "Filesystem/FileIO.h"
#include "NitroSDK/Filesystem/FileAccessor.h"
#include "NitroSDK/Filesystem/LowNitroHandle.h"
#include "Grotto/Main/ActiveGrottoClass.h"
#include "World/ZoneFeatures.h"
#include "World/Zone3D.h"
#include "std_library_functions.h"
#include "World/GrottoTileGraph.h"

extern "C" Zone3D* Zone3D_GetInstance(void);
extern "C" void func_020a0cc4(unsigned int size);
extern "C" void ROMFilesystem_InitFileTables(void);
extern "C" int ZoneId_IsMainGrottoFloor(int id);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);

extern AllocatorUnion g_mainAllocator;
#if defined(jpn)
#define data_ov017_021d7b53 data_ov017_021d8293
#define data_ov017_021d7b57 data_ov017_021d8297
#endif
extern const char data_ov017_021d7b53[];
extern const char data_ov017_021d7b57[];
extern const char data_ov017_021d7b3a[];

struct Struct_ov017_021b4a88 {
    unsigned char pad0[8];
    Struct_0201a300_4* target;
    int taskId;
    unsigned char state;
};

// USA: func_ov017_021b4a88
extern "C" ARM void func_ov017_021b4a88(Struct_ov017_021b4a88* request) {
    GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    Zone3D* zone = Zone3D_GetInstance();
    ActiveGrottoClass* grotto = &zone->grotto_;
    ZoneFeatures features;
    features.Reset();

    if (loader->GetTaskStatus(request->taskId)) {
        if (loader->GetDetailedTaskStatus(request->taskId) == BackgroundLoader::TaskStatus_Complete) {
            unsigned int size;
            void* data;
            loader->GetLoadedFileByID(request->taskId, &data, &size);
            func_020a0cc4(0x2800);

            SafeAllocator scriptAllocator;
            scriptAllocator.ResetAllocatorPointer();
            scriptAllocator.CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x800), 0x800);
            scriptAllocator.Reset();

            NarcHandle archive;
            if (archive.Initialize(data_ov017_021d7b53, (const unsigned char*)data)) {
                NitroVM vm;
                NitroVM_Initialize(&vm);
                char path[0x50];
                unsigned int index = 0;
                while (PrepareReadFileInNARCByID(&vm, &archive, index)) {
                    NitroVM_WriteOutFilePath(&vm, path, 0x50);
                    char* extension = strrchr(path, '.');
                    if (extension == 0) {
                        NitroVM_FinishRead(&vm);
                        index++;
                        continue;
                    }
                    NitroVM_FinishRead(&vm);
                    const void* file = archive.GetFileByIndex(index);
                    if (strcmp(data_ov017_021d7b57, extension) == 0) {
                        unsigned int scriptSize;
                        void* script = DecompressLZ77FileIntoScratchSpace(scriptAllocator, file, scriptSize);
                        features.Reset();
                        features.LoadFromScript(&scriptAllocator, script, scriptSize);
                    }
                    index++;
                }
                archive.Destroy();
            }

            int id = request->target->zoneId;
            request->target->loaded = 1;
            int floor = id % 20;
            SafeAllocator floorAllocator;
            floorAllocator.ResetAllocatorPointer();
            floorAllocator.CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x600), 0x600);
            floorAllocator.Reset();
            if (ZoneId_IsMainGrottoFloor(id)) {
                int width = grotto->CalculateAndStoreFloorWidth(floor);
                int height = grotto->CalculateAndStoreFloorHeight(floor);
                ActiveGrottoClass* current = &zone->grotto_;
                current->ClearGenerator(true);
                current->AllocateGenerator(&floorAllocator, true);
                FloorMap map;
                map.Clear();
                map.Clear();
                map.AllocateBuffers(&floorAllocator);
                TileFeaturePlacementData* buffer = (TileFeaturePlacementData*)AllocatorUnion_AllocateRounded(&g_mainAllocator, sizeof(TileFeaturePlacementData) * 256);
                current->CalculateFloorMap(floor, width, height, &map);
                func_02019728(zone, floor, &features, buffer, &map);
                func_0201a300(zone, floor, request->target, buffer, &map);
                AllocatorUnion_Free(&g_mainAllocator, buffer);
                map.Clear2();
            }
            void* scriptHeap = scriptAllocator.GetSignedAllocator();
            scriptAllocator.Destroy();
            AllocatorUnion_Free(&g_mainAllocator, scriptHeap);
            void* floorHeap = floorAllocator.GetSignedAllocator();
            floorAllocator.Destroy();
            AllocatorUnion_Free(&g_mainAllocator, floorHeap);
            ROMFilesystem_InitFileTables();
        }
        loader->RemoveTask(request->taskId);
        request->taskId = -1;
        request->taskId = loader->QueueLoadFile(data_ov017_021d7b3a, 0);
        request->state = 3;
    }
    features.Reset();
}
