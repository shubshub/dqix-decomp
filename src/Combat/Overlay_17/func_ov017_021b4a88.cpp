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
extern "C" void func_020a0c0c(void);
int IsInRange0201b5b0(int id);
void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);

extern AllocatorUnion g_mainAllocator;
#if defined(jpn)
#define data_ov017_021d7b53 data_ov017_021d8293
#define data_ov017_021d7b57 data_ov017_021d8297
#endif
extern const char data_ov017_021d7b53[];
extern const char data_ov017_021d7b57[];
extern const char data_ov017_021d7b3a[];

struct Struct_ov017_021b4a88 {
    unsigned char unknown_0_[8];
    Struct_0201a300_4* unknown_8_;
    int unknown_c_;
    unsigned char unknown_10_;
};

// USA: func_ov017_021b4a88
extern "C" ARM void func_ov017_021b4a88(Struct_ov017_021b4a88* arg0) {
    GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    Zone3D* zone = Zone3D_GetInstance();
    ActiveGrottoClass* grotto = &zone->grotto_;
    ZoneFeatures features;
    features.Reset_0201e248();

    if (var0->GetTaskStatus(arg0->unknown_c_)) {
        if (var0->GetDetailedTaskStatus(arg0->unknown_c_) == BackgroundLoader::TaskStatus_Complete) {
            unsigned int var4;
            void* var5;
            var0->GetLoadedFileByID(arg0->unknown_c_, &var5, &var4);
            func_020a0cc4(0x2800);

            SafeAllocator scriptAllocator;
            scriptAllocator.ResetAllocatorPointer();
            scriptAllocator.CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x800), 0x800);
            scriptAllocator.Reset();

            NarcHandle var7;
            if (var7.Initialize(data_ov017_021d7b53, (const unsigned char*)var5)) {
                NitroVM var8;
                NitroVM_Initialize(&var8);
                char var9[0x50];
                unsigned int var10 = 0;
                while (PrepareReadFileInNARCByID(&var8, &var7, var10)) {
                    NitroVM_WriteOutFilePath(&var8, var9, 0x50);
                    char* var11 = strrchr(var9, '.');
                    if (var11 == 0) {
                        NitroVM_FinishRead(&var8);
                        var10++;
                        continue;
                    }
                    NitroVM_FinishRead(&var8);
                    const void* var12 = var7.GetFileByIndex(var10);
                    if (strcmp(data_ov017_021d7b57, var11) == 0) {
                        unsigned int var13;
                        void* var14 = DecompressLZ77FileIntoScratchSpace(var6, var12, var13);
                        var3.func_0201e248();
                        var3.func_0201e2b4(&var6, var14, var13);
                    }
                    var10++;
                }
                var7.Destroy();
            }

            int id = request->target->zoneId;
            request->target->loaded = 1;
            int floor = id % 20;
            SafeAllocator floorAllocator;
            floorAllocator.ResetAllocatorPointer();
            floorAllocator.CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x600), 0x600);
            floorAllocator.Reset();
            if (IsInRange0201b5b0(id)) {
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
            func_020a0c0c();
        }
        var0->RemoveTask(arg0->unknown_c_);
        arg0->unknown_c_ = -1;
        arg0->unknown_c_ = var0->QueueLoadFile(data_ov017_021d7b3a, 0);
        arg0->unknown_10_ = 3;
    }
    var3.func_0201e248();
}
