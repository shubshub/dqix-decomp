#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Grotto/Main/TreasureMapDataStructs.h"
#include "Resource/GameResources.h"
#include "std_library_functions.h"
#include "Resource/Brightness.h"

struct Struct_ov004_021636b0 { TreasureMapMetadata unknown_0_[99]; DetailedTreasureMapData unknown_ad4_[8]; unsigned char unknown_18f4_; char unknown_18f5_[9]; unsigned char unknown_18fe_; char unknown_18ff_[17]; int unknown_1910_; };
struct Struct_ov004_02171010_2 { Struct_ov004_021636b0* unknown_0_; void* unknown_4_; void* unknown_8_; };
struct Struct_ov004_02163944 { unsigned char unknown_0_; unsigned char unknown_1_; TreasureMapMetadata unknown_2_[99]; };
struct Struct_ov004_02163944_2 { char unknown_0_[0x14]; int unknown_14_; };
struct Struct_ov004_02163944_3 { char unknown_0_[0x26]; char unknown_26_[17]; };
struct Struct_ov004_02163944_4 {
#if defined(jpn)
    char unknown_0_[0x1790]; unsigned char unknown_1962_; char unknown_1791_[3];
#else
    char unknown1_0_[0x1962]; unsigned char unknown_1962_; char unknown_1963_;
#endif
    int unknown_1964_[9]; int unknown_1988_[3];
};
struct Struct_ov004_02162dd8 { int unknown_0_; SafeAllocator unknown_4_; };
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
void SetByteFieldAt0x765_02026420(unsigned char*, unsigned char);
void SetFieldAt0x76c_020263dc(unsigned char*, void*);
void Notify02022d78WithCode2_020dc3b8();
void SetSubBrightness(GameResources*, int, int);
extern "C" void func_ov004_021636b0(void*, const char*);
char* MessageSystem_GetInstance();
void MessageSystem_Reset(char*);
void SetFieldsAt0x4And0x8_020e2d24(int*, int, int);

// JPN: 0x02163efc; USA/EUR: 0x02163944.
extern "C" ARM int func_ov004_02163944(void* arg0) {
    Struct_ov004_02162dd8* var0 = func_ov011_021845f8(arg0, 0);
    if (!var0) return 0;
    SafeAllocator* var1 = &var0->unknown_4_;
    if (!var1) return 0;
    func_020a3844(var1);
    data_ov004_02171010.unknown_0_ = (Struct_ov004_021636b0*)var1->Allocate(sizeof(Struct_ov004_021636b0));
    if (!data_ov004_02171010.unknown_0_) return 0;
    func_ov004_0216342c(data_ov004_02171010.unknown_0_);
    data_ov004_02171010.unknown_0_->unknown_18fe_ = 1;
#if !defined(jpn)
    data_ov004_02171010.unknown_4_ = func_ov011_021845f8(arg0, 4)->unknown_4_.Allocate(0x333);
    memset(data_ov004_02171010.unknown_4_, 0, 0x333);
#endif
    Struct_ov004_02163944 var2;
    if (func_020ac760(&var2)) {
        data_ov004_02171010.unknown_0_->unknown_18f4_ = var2.unknown_0_;
        for (int var3 = 0; var3 < 99; var3++) VectorizedInvertedMemcpy(&var2.unknown_2_[var3], &data_ov004_02171010.unknown_0_->unknown_0_[var3], 0x1c);
    }
    func_ov004_02163530(arg0);
    func_ov004_02163c40(arg0);
    int var4 = 0;
    int var5 = 0;
    if (!func_ov004_021635d0(&var4, &var5)) { var4 = 0; var5 = 0; }
    for (int var6 = 0; var6 < 8; var6++) {
        ExportDetailedTreasureMapData(&data_ov004_02171010.unknown_0_->unknown_0_[var6 + var4 * 8], &data_ov004_02171010.unknown_0_->unknown_ad4_[var6], true, 0);
    }
#if !defined(jpn)
    Struct_ov004_02162dd8* var7 = func_ov011_021845f8(arg0, 3);
    if (!var7) return 0;
    data_ov004_02171010.unknown_8_ = var7->unknown_4_.Allocate(12);
    func_020e526c(data_ov004_02171010.unknown_8_);
    BackgroundLoader::AddLockGlobal();
    unsigned int var8 = 0;
    void* var9 = ExtractFileFromGP2(data_ov004_0217055c, data_ov004_02170572, &var8);
    func_020e5604(data_ov004_02171010.unknown_8_, &var7->unknown_4_, var9, var8);
    BackgroundLoader::RemoveLockGlobal();
#endif
    MapZone* zone = Zone3D_GetInstance();
    ResourcePanel* panel = (ResourcePanel*)GetGameResources()->unknown_ptr_36d0;
    data_ov004_02171010.buffer->state = panel->state;
    strcpy(data_ov004_02171010.buffer->name, zone->name);
    SetByteFieldAt0x765_02026420((unsigned char*)panel, 1);
    SetFieldAt0x76c_020263dc((unsigned char*)panel, allocator);
    Notify02022d78WithCode2_020dc3b8();
    GameResources* resources = GetGameResources();
    if (IsBrightnessWithinValidRange((GameResources*)resources, true)) SetSubBrightness(resources, -16, 0);
    func_ov004_021636b0(obj, data_ov004_02171010.buffer->details[selection].mapImageName_);
    MapController* controller = (MapController*)MessageSystem_GetInstance();
    MessageSystem_Reset((char*)controller);
    controller->active = 1;
    SetFieldsAt0x4And0x8_020e2d24(controller->first, 9, 1);
    SetFieldsAt0x4And0x8_020e2d24(controller->second, 25, 1);
    data_ov004_02171010.buffer->busy = 0;
    return 0;
}
