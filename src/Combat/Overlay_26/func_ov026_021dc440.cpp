#include <globaldefs.h>
#include <GameState/GameState.h>
#include "GameState/Field3b0.h"
#include <Filesystem/BackgroundLoader.h>
extern unsigned char g_fileLoadBuffer[0x30000] __attribute__((aligned(4)));
void* LoadFileIntoMemory(const char* path, void* buffer, unsigned int* outLength);
#include <Filesystem/GPC.h>
#include <Memory/SafeAllocator.h>
#include <NitroSDK/Matrix.h>
#include <World/Object3D.h>
#include <std_library_functions.h>
#include "Resource/GameResources.h"

#if defined(jpn)
struct Struct_ov000_02160da0 { char unknown_0_[0x7902]; signed char unknown_7712_; };
#else
struct Struct_ov000_02160da0 { char unknown_0_[0x7712]; signed char unknown_7712_; };
#endif

void ZeroInitGPCPointer(GPCFile**);
void ZeroDestroyGPCPointer(GPCFile**);
struct Struct_203dafc;
void ClearEightWords_0203dafc(struct Struct_203dafc* obj);
struct Obj0204a120;
void InitState0204a120(struct Obj0204a120* obj);
struct Owner0204a3f0;
struct Holder0204a3f0;
void SetHolderAndMarkNode0204a3f0(struct Owner0204a3f0* owner, struct Holder0204a3f0* h);
void SetName0204a440(char* obj, const char* src);
void SetStringField0234_0204a464(char* obj, const char* src);
void GameState_SetCamera(GameState*, int);
void RegisterCombatantSlot_0200fd38(GameState*, int, GameObject*);
int TestBitAt0x34_020a35e0(unsigned char*, unsigned char);
int CountSetBitsAt0x34_020a35f8(unsigned char*);
void FormatEffectStats02072c9c(int, char*);
struct Fields020407b4;
void SetFields0x44(struct Fields020407b4*, int, int, int);
struct GameResources;
void SetBrightness(struct GameResources*, int, int);
void SetMainBrightness(struct GameResources*, int, int);
extern "C" {
void func_ov000_021626a0(BattleWork*, int, int);
void func_ov000_021637fc(BattleWork*, int);
void _Z38RunFlaglearAndSetMode02167e6c_02167e6cPh(BattleWork*);
int RandomIntBelow(int);
}

#if defined(jpn)
#define data_ov026_021dee5c data_ov026_021df50a
#define data_ov026_021dee77 data_ov026_021df525
#define data_ov026_021dee84 data_ov026_021df532
#define data_ov026_021dee88 data_ov026_021df536
#define data_ov026_021de6e8 data_ov026_021ded04
#define data_ov026_021dee8f data_ov026_021df53d
#define data_ov026_021dee9c data_ov026_021df54a
#define data_ov026_021deeb5 data_ov026_021df563
#endif
extern const char data_ov026_021dee5c[];
extern const char data_ov026_021dee77[];
extern const char data_ov026_021dee84[];
extern const char data_ov026_021dee88[];
#if defined(jpn)
struct Struct_ov026_021de6a0_3 { unsigned char unknown_0_[2]; unsigned char unknown_4_; unsigned char unknown_5_; };
#else
struct Struct_ov026_021de6a0_3 { unsigned char unknown_0_[4]; unsigned char unknown_4_; unsigned char unknown_5_; };
#endif
extern const Struct_ov026_021de6a0_3 data_ov026_021de6a0;
struct Struct_ov026_021de6e8 { int unknown_0_[4]; };
struct Struct_ov026_021dc440 { signed char unknown_0_[2]; };
extern const Struct_ov026_021de6e8 data_ov026_021de6e8;
extern const char data_ov026_021dee8f[];
struct Struct_ov026_021d8ba0_3 {
    char unknown_0_[8][3];
    int unknown_18_;
    const char* unknown_1c_[8];
};
#if defined(jpn)
struct Struct_ov026_021dedac { const char* unknown_1c_[8]; };
#define _ZZ23inline_ov026_021d8ba0_2vE1s data_ov026_021dedac
extern "C" Struct_ov026_021dedac _ZZ23inline_ov026_021d8ba0_2vE1s;
#else
extern "C" Struct_ov026_021d8ba0_3 _ZZ23inline_ov026_021d8ba0_2vE1s;
#endif
extern const char data_ov026_021dee9c[];
extern const char data_ov026_021deeb5[];

// USA: func_ov026_021dc440
extern "C" ARM void func_ov026_021dc440(SafeAllocator* arg0, Struct_ov000_02160da0* arg1, void* arg2, unsigned char* arg3, const char* arg4) {
    GPCReadPair var0;
    unsigned int var1;
    char var2[0x50];
    GameState* var3 = GameState::GetInstance();
    GameResources* var4 = GetGameResources();
    int var5 = arg1->unknown_7712_;
    func_ov000_021626a0(arg1, 0x26, 1);
    func_ov000_021626a0(arg1, 0x27, 0);
    func_ov000_02167e6c(arg1);
    if (var5 != 5) arg0->Reset();
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();

    GPCReadPair* rp = &pair;
    unsigned char* buffer = g_fileLoadBuffer;
    unsigned int room = 0x30000;
    ZeroInitGPCPointer(&rp->pGPCFile);
    rp->ZeroInitializeMachine();
    if (LoadAndDecompressGPCHeaderAndInnerFileInfo(&pair.pGPCFile, pair.machine, data_ov026_021dee5c, buffer, size, room, false, 0)) {
        buffer += size;
        room -= size;
        if (DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, buffer, size, room, data_ov026_021dee77)) {
            Object3D* obj = (Object3D*)allocator->Allocate(0xac);
            if (obj) {
                obj->Initialize();
                ObjectArchiveLoadInfo info;
                ClearEightWords_0203dafc((Struct_203dafc*)&info);
                info.fileSize = size;
                info.unk_10 = 1;
                info.allocator = allocator;
                info.fileData = buffer;
                obj->LoadFromCHRArchive(&info);
                char* holder = (char*)allocator->Allocate(0x268);
                if (holder) {
                    InitState0204a120((Obj0204a120*)holder);
                    SetHolderAndMarkNode0204a3f0((Owner0204a3f0*)holder, (Holder0204a3f0*)obj);
                    SetName0204a440(holder, data_ov026_021dee84);
                    SetStringField0234_0204a464(holder, data_ov026_021dee88);
                    GameState_SetCamera(game, (int)holder);
                    AnimLabels labels;
                    labels.letters[0] = data_ov026_021de6a0.b0;
                    labels.letters[1] = data_ov026_021de6a0.b1;
                    if (!animName) {
                        labels.letters[0] += RandomIntBelow(3);
                        animName = (const char*)labels.letters;
                    }
                    obj->SetAnimationByName(animName, 1);
                    Table4 table = data_ov026_021de6e8;
                    int k = 0x10a;
                    int s = table.v[CountSetBitsAt0x34_020a35f8(party) - 1];
                    int a = FIX32_MULTIPLY(k, s);
                    obj->SetScale(a, k, a);
                    int b = FIX32_MULTIPLY(s, s);
                    int c = FIX32_MULTIPLY(b, s);
                    SetFields0x44((Fields020407b4*)obj, 0, 0xcc, -c);
                }
            }
        }
        if (DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, buffer, size, room, data_ov026_021dee8f)) {
            Object3D* obj = (Object3D*)allocator->Allocate(0xac);
            if (obj) {
                obj->Initialize();
                ObjectArchiveLoadInfo info;
                ClearEightWords_0203dafc((Struct_203dafc*)&info);
                info.fileSize = size;
                info.unk_10 = 1;
                info.allocator = allocator;
                info.fileData = buffer;
                obj->LoadFromCHRArchive(&info);
                SetFields0x44((Fields020407b4*)obj, 0, 0xcc, 0);
                obj->SetScale(0x10a, 0x10a, 0x10a);
                Model3D* model = obj->pModel_;
                Object3D::TrackedBoneMatrix* bones = (Object3D::TrackedBoneMatrix*)allocator->Allocate(0x1c0);
                if (bones && model) {
                    for (int i = 0; i < 8; ++i) {
                        int index = model->GetBoneIndex(_ZZ12GetRowLabelsvE1s.order[i]);
                        bones[i].boneIndex = index;
                        obj->TrackBone(&bones[i]);
                    }
                }
                var19->EnableBoneTracking();
                func_0200fd38(var3, 0xcf, (GameObject*)var19);
            }
        }
        for (int var25 = 0; var25 < 4; ++var25) {
            if (func_020a35e0(arg3, var25)) {
                GameObject* var26 = func_0200ff1c(var3, var25);
                if (var26) {
                    char var27[0x14];
                    func_02072c9c(var25, var27);
#if defined(jpn)
                    enum { Enum_ov026_021dc440_452 = 0x1b8 };
#else
                    enum { Enum_ov026_021dc440_452 = 0x1c4 };
#endif
                    if (*(int*)((char*)member + regionalOffset)) {
                        sprintf(name, data_ov026_021dee9c);
                        LoadFileIntoMemory(name, g_fileLoadBuffer, &size);
                        buffer = g_fileLoadBuffer;
                    } else {
                        sprintf(var2, data_ov026_021deeb5, var27);
                        DecompressFileFromGPCByName(var0.pGPCFile, var0.machine, var7, var1, var8, var2);
                    }
                    if (size) {
                        ObjectArchiveLoadInfo info;
                        ClearEightWords_0203dafc((Struct_203dafc*)&info);
                        info.unk_10 = 1;
                        info.packageID = 3;
                        info.fileSize = size;
                        info.allocator = allocator;
                        info.fileData = buffer;
                        member->obj3D_.LoadFromCCHROrCMOTArchive(&info, 0);
                        func_ov000_021637fc(self, i);
                    }
                }
            }
        }
        var0.Reset();
    }
    BackgroundLoader::RemoveLockGlobal();
    if (var5 == 5) SetBrightness(var4, 0, 0xf);
    else SetMainBrightness(var4, 0, 0xf);
    var0.Reset();
    ZeroDestroyGPCPointer(&var0.pGPCFile);
}
