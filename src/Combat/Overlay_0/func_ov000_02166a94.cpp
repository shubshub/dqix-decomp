#include <globaldefs.h>
#include <Filesystem/FileIO.h>
#include <Filesystem/BackgroundLoader.h>
#include <Resource/GameResources.h>
#include <World/Object3D.h>

#if defined(jpn)
#define func_020c9be0 func_020cb6ac
#endif

struct Struct_ov000_02166a94_2 { int unknown_0_; char unknown_4_[0x84]; };
struct Struct_ov000_02166a94_3 {
    char unknown_0_[4];
    SafeAllocator* unknown_4_;
#if defined(jpn)
    char unknown_8_[0xe20 - 8];
    void* unknown_ea4_;
    char unknown_e24_[0x57f0 - 0xe24];
    Struct_ov000_02166a94_2 unknown_5600_[2];
    char unknown_5900_[0x5ca0 - 0x5900];
    Object3D unknown_5ab0_[2];
    char unknown_5df8_[0x71ec - 0x5df8];
#else
    char unknown1_8_[0xea4 - 8];
    void* unknown_ea4_;
    char unknown_ea8_[0x5600 - 0xea8];
    Struct_ov000_02166a94_2 unknown_5600_[2];
    char unknown_5710_[0x5ab0 - 0x5710];
    Object3D unknown_5ab0_[2];
    char unknown_5c08_[0x6ffc - 0x5c08];
#endif
    char unknown_6ffc_[4];
};
struct Struct_ov000_02166a94_4 {
    char unknown_0_[0x230];
    char unknown_230_[4];
};
struct Struct_02057de0_2;
struct Struct_0203d028_11 { int unknown_0_[8]; };
union Struct_ov000_02166a94 { Struct_0203d028_11 unknown_0_; ObjectArchiveLoadInfo unknown1_0_; };
struct Struct_020d6d18_2;
struct Struct_020d6d90_3;
struct Struct_020d76fc;
struct Struct_020d6ec8;
extern "C" Struct_02057de0_2* func_02057924();
extern "C" void func_020c9be0();
void VramState_Restore(char*);
void VramState_Save(char*);
void CreateAndRegisterNode02057de0(NodeList02057de0*, int, SafeAllocator*, int, int);
void ClearEightWords_0203dafc(Struct_203dafc*);
void Forward02047b30(void*, int, int, int);
void ResetArrayAndEntry02182114(char*);
extern "C" void func_ov000_0218214c(void*, SafeAllocator*, const void*);
extern "C" char* func_02039e70();
extern "C" void func_02039e7c(void*);
extern "C" void func_02039f04(char*, int, const void*);
extern "C" void func_020d6d18(Struct_020d6d18_2*);
extern "C" void func_020d6d90(Struct_020d6d90_3*, const void*, SafeAllocator*, char*);
extern "C" void func_020d76fc(Struct_020d76fc*);
extern "C" void func_020d771c(unsigned char*);
extern "C" void func_020d6ec8(Struct_020d6ec8*, SafeAllocator*);
extern "C" void func_ov000_02160fa8(void*, int);
extern const char data_ov000_02183a5a[], data_ov000_02183a6f[], data_ov000_02183a7a[], data_ov000_02183a85[], data_ov000_02183a93[];
extern const char data_ov000_02183910[][16];
struct Struct_ov000_02183028 {
    int unknown_0_[3];
    int inline_ov000_02166a94(int arg0) const { return unknown_0_[arg0]; }
};
extern int data_ov000_021838fc[];
extern Struct_ov000_02183028 data_ov000_02183028;

// USA: func_ov000_02166a94
extern "C" ARM void func_ov000_02166a94(Struct_ov000_02166a94_3* arg0) {
    SafeAllocator* var0;
    Struct_ov000_02166a94_4* var1;
    Struct_02057de0_2* var2;
    SafeAllocator* var3;
    GameResources* var4 = GetGameResources();
    var2 = func_02057924();
    var0 = &var4->allocator_array_38[0];
    var3 = &var4->allocator_array_38[5];
    var1 = (Struct_ov000_02166a94_4*)var4->unknown_2cc_;
    unsigned int var5;
    const void* var6;
    BackgroundLoader::AddLockGlobal();
    if (!LoadFileIntoMemory(data_ov000_02183a5a, data_0211e33c, &size)) func_020c9be0();
    VramState_Restore(pairTables->tables);
    if (GetFileInNarc(data_0211e33c, data_ov000_02183a6f, &data, &size, 0)) {
        void* buffer = sourceAllocator->Allocate(size);
        if (buffer) {
            memcpy(buffer, data, size);
            CreateAndRegisterNode02057de0(nodes, 2, sourceAllocator, (int)buffer, size);
        }
    }
    SafeAllocator* var8[4] = {var0, arg0->unknown_4_, arg0->unknown_4_, arg0->unknown_4_};
    SafeAllocator* var9[4] = {var3, var3, arg0->unknown_4_, arg0->unknown_4_};
    long var10;
    SafeAllocator** var11;
    SafeAllocator** var12;
    var10 = 0;
    var11 = var8;
    var12 = var9;
    for (; data_ov000_021838fc[var10] >= 0; ++var10, ++var11, ++var12) {
        if (GetFileInNarc(data_0211e33c, data_ov000_02183910[var10], &var6, &var5, 0)) {
            void* var13 = (*var11)->Allocate(var5);
            if (var13) {
                memcpy(var13, var6, var5);
                func_02057de0(var2, data_ov000_021838fc[var10], *var12, (int)var13, var5);
            }
        }
    }
    Object3D* var14[3] = {};
    var14[0] = &arg0->unknown_5ab0_[0];
    var14[1] = &arg0->unknown_5ab0_[1];
    char var15[80];
    Struct_ov000_02166a94 var16;
    Object3D* const* var17;
    Struct_ov000_02183028* var18;
    long var19;
    Object3D* var20;
    for (var19 = 0; data_ov000_02183028.unknown_0_[var19] > 0; ++var19) {
        var18 = &data_ov000_02183028;
        sprintf(var15, data_ov000_02183a7a, var18->inline_ov000_02166a94(var19));
        GetFileInNarc(data_0211e33c, var15, &var6, &var5, 0);
        if (var6) {
            var17 = var14;
            var20 = var17[var19];
            func_0203dafc(&var16.unknown_0_);
            const void* var21;
            int var22;
            var22 = var5;
            var21 = var6;
            var16.unknown1_0_.unk_10 = 1;
            var16.unknown1_0_.fileData = var21;
            var16.unknown1_0_.allocator = var3;
            var16.unknown1_0_.unk_8 = var22;
            var20->Initialize();
            var20->LoadFromCHRArchive(&var16.unknown1_0_);
            var20->SetScale(0x10a, 0x10a, 0x10a);
        }
    }
    if (GetFileInNarc(data_0211e33c, data_ov000_02183a85, &var6, &var5, 0)) {
        func_02047b30(&arg0->unknown_5600_[0], (int)var6, var5, (int)var3);
        arg0->unknown_5600_[0].unknown_0_ = 0x3e;
    }
    if (GetFileInNarc(data_0211e33c, data_ov000_02183a93, &var6, &var5, 0)) {
        func_02047b30(&arg0->unknown_5600_[1], (int)var6, var5, (int)var3);
        arg0->unknown_5600_[1].unknown_0_ = 0x3e;
    }
    char* battleResources = self->battleResources;
    ResetArrayAndEntry02182114(battleResources);
    func_ov000_0218214c(battleResources, destinationAllocator, data_0211e33c);
    char* objectResources = GetData02104b6c_02039e70();
    ResetBattleArrays02039e7c(objectResources);
    LoadObjectResourceFiles02039f04(objectResources, (int)destinationAllocator, data_0211e33c);
    VramState_Save(pairTables->tables);
    self->entryManager = destinationAllocator->Allocate(0xa48);
    ConstructEntryManager020d6d18((Container020d6d18*)self->entryManager);
    LoadFilesAndBuildNodeList020d6d90((Obj020d6d90*)self->entryManager, data_0211e33c, destinationAllocator, pairTables->tables);
    MergeLowNibbleField((MergeLowNibbleField020d76fc*)self->entryManager);
    OrMaskedField24IntoField26_020d771c((unsigned char*)self->entryManager);
    InitEntryManagerAllocator020d6ec8((Container020d6f44*)self->entryManager, self->allocator);
    VramState_Restore(pairTables->tables);
    VramState_Save(pairTables->tables);
    SetCombatWorkFlags0x55f4_ov000_02160fa8(self, 0x40);
    BackgroundLoader::RemoveLockGlobal();
}
