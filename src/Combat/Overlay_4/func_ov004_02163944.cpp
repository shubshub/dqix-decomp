#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Grotto/Main/TreasureMapDataStructs.h"
#include "Resource/GameResources.h"
#include "std_library_functions.h"
#include "Resource/Brightness.h"

struct Struct_ov004_021636b0 { TreasureMapMetadata unknown_0_[99]; DetailedTreasureMapData details[8]; unsigned char count; char unknown_18f5_[9]; unsigned char busy; char name[17]; int state; };
struct Struct_ov004_02171010_2 { Struct_ov004_021636b0* buffer; void* scratch; void* file; };
struct Struct_ov004_02163944 { unsigned char count; unsigned char padding; TreasureMapMetadata unknown_2_[99]; };
struct Struct_ov004_02163944_2 { char pad[0x14]; int state; };
struct MapZone { char pad[0x26]; char name[17]; };
struct MapController {
#if defined(jpn)
    char pad[0x1790]; unsigned char active; char alignment[3];
#else
    char pad[0x1962]; unsigned char active; char alignment;
#endif
    int first[9]; int second[3];
};
struct Struct_ov004_02162dd8 { int field0; SafeAllocator allocator; };
extern Struct_ov004_02171010_2 data_ov004_02171010;
extern char data_ov004_0217055c[];
extern char data_ov004_02170572[];
#if defined(jpn)
#define func_ov004_0216342c func_ov004_02163a20
extern "C" {
void func_ov004_02163a20(void*);
}
#endif
extern "C" Struct_ov004_02162dd8* func_ov011_021845f8(void*, int);
extern "C" int func_020a3844(SafeAllocator*);
extern "C" void func_ov004_0216342c(void*);
extern "C" bool func_020ac760(void*);
extern "C" void VectorizedInvertedMemcpy(const void*, void*, unsigned int);
extern "C" void func_ov004_02163530(void*);
extern "C" void func_ov004_02163c40(void*);
extern "C" bool func_ov004_021635d0(int*, int*);
extern "C" void func_020e526c(void*);
extern "C" void func_020e5604(void*, SafeAllocator*, void*, unsigned int);
extern "C" MapZone* Zone3D_GetInstance();
extern "C" void func_02026420(unsigned char*, unsigned char);
extern "C" void func_020263dc(unsigned char*, void*);
extern "C" void func_020dc3b8();
void SetSubBrightness(GameResources*, int, int);
extern "C" void func_ov004_021636b0(void*, const char*);
extern "C" char* MessageSystem_GetInstance();
extern "C" void MessageSystem_Reset(char*);
extern "C" void func_020e2d24(int*, int, int);

// JPN: 0x02163efc; USA/EUR: 0x02163944.
extern "C" ARM int func_ov004_02163944(void* obj) {
    Struct_ov004_02162dd8* heap = func_ov011_021845f8(obj, 0);
    if (!heap) return 0;
    SafeAllocator* allocator = &heap->allocator;
    if (!allocator) return 0;
    func_020a3844(allocator);
    data_ov004_02171010.buffer = (Struct_ov004_021636b0*)allocator->Allocate(sizeof(Struct_ov004_021636b0));
    if (!data_ov004_02171010.buffer) return 0;
    func_ov004_0216342c(data_ov004_02171010.buffer);
    data_ov004_02171010.buffer->busy = 1;
#if !defined(jpn)
    data_ov004_02171010.scratch = func_ov011_021845f8(obj, 4)->allocator.Allocate(0x333);
    memset(data_ov004_02171010.scratch, 0, 0x333);
#endif
    Struct_ov004_02163944 saved;
    if (func_020ac760(&saved)) {
        data_ov004_02171010.buffer->count = saved.count;
        for (int i = 0; i < 99; i++) VectorizedInvertedMemcpy(&saved.unknown_2_[i], &data_ov004_02171010.buffer->unknown_0_[i], 0x1c);
    }
    func_ov004_02163530(obj);
    func_ov004_02163c40(obj);
    int page = 0;
    int selection = 0;
    if (!func_ov004_021635d0(&page, &selection)) { page = 0; selection = 0; }
    for (int i = 0; i < 8; i++) {
        ExportDetailedTreasureMapData(&data_ov004_02171010.buffer->unknown_0_[i + page * 8], &data_ov004_02171010.buffer->details[i], true, 0);
    }
#if !defined(jpn)
    Struct_ov004_02162dd8* var7 = func_ov011_021845f8(obj, 3);
    if (!var7) return 0;
    data_ov004_02171010.file = var7->allocator.Allocate(12);
    func_020e526c(data_ov004_02171010.file);
    BackgroundLoader::AddLockGlobal();
    unsigned int length = 0;
    void* file = ExtractFileFromGP2(data_ov004_0217055c, data_ov004_02170572, &length);
    func_020e5604(data_ov004_02171010.file, &var7->allocator, file, length);
    BackgroundLoader::RemoveLockGlobal();
#endif
    MapZone* zone = Zone3D_GetInstance();
    Struct_ov004_02163944_2* panel = (Struct_ov004_02163944_2*)GetGameResources()->unknown_ptr_36d0;
    data_ov004_02171010.buffer->state = panel->state;
    strcpy(data_ov004_02171010.buffer->name, zone->name);
    func_02026420((unsigned char*)panel, 1);
    func_020263dc((unsigned char*)panel, allocator);
    func_020dc3b8();
    GameResources* resources = GetGameResources();
    if (IsScreenNotFullyFaded((GameResources*)resources, true)) SetSubBrightness(resources, -16, 0);
    func_ov004_021636b0(obj, data_ov004_02171010.buffer->details[selection].mapImageName_);
    MapController* controller = (MapController*)MessageSystem_GetInstance();
    MessageSystem_Reset((char*)controller);
    controller->active = 1;
    func_020e2d24(controller->first, 9, 1);
    func_020e2d24(controller->second, 25, 1);
    data_ov004_02171010.buffer->busy = 0;
    return 0;
}
