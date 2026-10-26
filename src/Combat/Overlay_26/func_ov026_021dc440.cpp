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
struct Struct_ov000_02160da0 { char pad0[0x7902]; signed char animationState; };
#else
struct Struct_ov000_02160da0 { char pad0[0x7712]; signed char animationState; };
#endif

void ZeroInitGPCPointer(GPCFile**);
void ZeroDestroyGPCPointer(GPCFile**);
struct Struct_203dafc;
extern "C" void func_0203dafc(struct Struct_203dafc* obj);
struct Struct_0204a120;
extern "C" void func_0204a120(struct Struct_0204a120* obj);
struct Struct_0204a3f0_2;
struct Struct_0204a3f0;
extern "C" void func_0204a3f0(struct Struct_0204a3f0_2* owner, struct Struct_0204a3f0* h);
extern "C" void func_0204a440(char* obj, const char* src);
extern "C" void func_0204a464(char* obj, const char* src);
extern "C" void GameState_SetCamera(GameState*, int);
extern "C" void func_0200fd38(GameState*, int, GameObject*);
extern "C" int func_020a35e0(unsigned char*, unsigned char);
extern "C" int func_020a35f8(unsigned char*);
extern "C" void func_02072c9c(int, char*);
struct Fields020407b4;
extern "C" void func_020407b4(struct Fields020407b4*, int, int, int);
struct GameResources;
void SetBrightness(struct GameResources*, int, int);
void SetMainBrightness(struct GameResources*, int, int);
extern "C" {
void func_ov000_021626a0(Struct_ov000_02160da0*, int, int);
void func_ov000_021637fc(Struct_ov000_02160da0*, int);
extern "C" void func_ov000_02167e6c(Struct_ov000_02160da0*);
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
struct Struct_ov026_021de6a0_3 { unsigned char a[2]; unsigned char b0; unsigned char b1; };
#else
struct Struct_ov026_021de6a0_3 { unsigned char a[4]; unsigned char b0; unsigned char b1; };
#endif
extern const Struct_ov026_021de6a0_3 data_ov026_021de6a0;
struct Struct_ov026_021de6e8 { int v[4]; };
struct Struct_ov026_021dc440 { signed char letters[2]; };
extern const Struct_ov026_021de6e8 data_ov026_021de6e8;
extern const char data_ov026_021dee8f[];
struct Struct_ov026_021d8ba0_3 {
    char names[8][3];
    int loadTask;
    const char* order[8];
};
#if defined(jpn)
struct Struct_ov026_021dedac { const char* order[8]; };
#define _ZZ23inline_ov026_021d8ba0_2vE1s data_ov026_021dedac
extern "C" Struct_ov026_021dedac _ZZ23inline_ov026_021d8ba0_2vE1s;
#else
extern "C" Struct_ov026_021d8ba0_3 _ZZ23inline_ov026_021d8ba0_2vE1s;
#endif
extern const char data_ov026_021dee9c[];
extern const char data_ov026_021deeb5[];

// USA: func_ov026_021dc440
extern "C" ARM void func_ov026_021dc440(SafeAllocator* allocator, Struct_ov000_02160da0* self, void* unused, unsigned char* party, const char* animName) {
    GPCReadPair pair;
    unsigned int size;
    char name[0x50];
    GameState* game = GameState::GetInstance();
    GameResources* resources = GetGameResources();
    int mode = self->animationState;
    func_ov000_021626a0(self, 0x26, 1);
    func_ov000_021626a0(self, 0x27, 0);
    func_ov000_02167e6c(self);
    if (mode != 5) allocator->Reset();
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();

    GPCReadPair* rp = &pair;
    unsigned char* buffer = g_fileLoadBuffer;
    unsigned int var8 = 0x30000;
    ZeroInitGPCPointer(&rp->pGPCFile);
    rp->ZeroInitializeMachine();
    if (LoadAndDecompressGPCHeaderAndInnerFileInfo(&pair.pGPCFile, pair.machine, data_ov026_021dee5c, buffer, size, var8, false, 0)) {
        buffer += size;
        var8 -= size;
        if (DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, buffer, size, var8, data_ov026_021dee77)) {
            Object3D* obj = (Object3D*)allocator->Allocate(0xac);
            if (obj) {
                obj->Initialize();
                ObjectArchiveLoadInfo info;
                func_0203dafc((Struct_203dafc*)&info);
                info.fileSize = size;
                info.unk_10 = 1;
                info.allocator = allocator;
                info.fileData = buffer;
                obj->LoadFromCHRArchive(&info);
                char* holder = (char*)allocator->Allocate(0x268);
                if (holder) {
                    func_0204a120((Struct_0204a120*)holder);
                    func_0204a3f0((Struct_0204a3f0_2*)holder, (Struct_0204a3f0*)obj);
                    func_0204a440(holder, data_ov026_021dee84);
                    func_0204a464(holder, data_ov026_021dee88);
                    GameState_SetCamera(game, (int)holder);
                    Struct_ov026_021dc440 labels;
                    labels.letters[0] = data_ov026_021de6a0.b0;
                    labels.letters[1] = data_ov026_021de6a0.b1;
                    if (!animName) {
                        labels.letters[0] += RandomIntBelow(3);
                        animName = (const char*)labels.letters;
                    }
                    obj->SetAnimationByName(animName, 1);
                    Struct_ov026_021de6e8 table = data_ov026_021de6e8;
                    int k = 0x10a;
                    int s = table.v[func_020a35f8(party) - 1];
                    int a = FIX32_MULTIPLY(k, s);
                    obj->SetScale(a, k, a);
                    int b = FIX32_MULTIPLY(s, s);
                    int c = FIX32_MULTIPLY(b, s);
                    func_020407b4((Fields020407b4*)obj, 0, 0xcc, -c);
                }
            }
        }
        if (DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, buffer, size, var8, data_ov026_021dee8f)) {
            Object3D* obj = (Object3D*)allocator->Allocate(0xac);
            if (obj) {
                obj->Initialize();
                ObjectArchiveLoadInfo info;
                func_0203dafc((Struct_203dafc*)&info);
                info.fileSize = size;
                info.unk_10 = 1;
                info.allocator = allocator;
                info.fileData = buffer;
                obj->LoadFromCHRArchive(&info);
                func_020407b4((Fields020407b4*)obj, 0, 0xcc, 0);
                obj->SetScale(0x10a, 0x10a, 0x10a);
                Model3D* model = obj->pModel_;
                Object3D::TrackedBoneMatrix* var22 = (Object3D::TrackedBoneMatrix*)allocator->Allocate(0x1c0);
                if (var22 && model) {
                    for (int i = 0; i < 8; ++i) {
                        int index = model->GetBoneIndex(_ZZ23inline_ov026_021d8ba0_2vE1s.order[i]);
                        var22[i].boneIndex = index;
                        obj->TrackBone(&var22[i]);
                    }
                }
                obj->EnableBoneTracking();
                func_0200fd38(game, 0xcf, (GameObject*)obj);
            }
        }
        for (int i = 0; i < 4; ++i) {
            if (func_020a35e0(party, i)) {
                GameObject* member = func_0200ff1c(game, i);
                if (member) {
                    char tmp[0x14];
                    func_02072c9c(i, tmp);
#if defined(jpn)
                    enum { regionalOffset = 0x1b8 };
#else
                    enum { regionalOffset = 0x1c4 };
#endif
                    if (*(int*)((char*)member + regionalOffset)) {
                        sprintf(name, data_ov026_021dee9c);
                        LoadFileIntoMemory(name, g_fileLoadBuffer, &size);
                        buffer = g_fileLoadBuffer;
                    } else {
                        sprintf(name, data_ov026_021deeb5, tmp);
                        DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, buffer, size, var8, name);
                    }
                    if (size) {
                        ObjectArchiveLoadInfo info;
                        func_0203dafc((Struct_203dafc*)&info);
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
        pair.Reset();
    }
    BackgroundLoader::RemoveLockGlobal();
    if (mode == 5) SetBrightness(resources, 0, 0xf);
    else SetMainBrightness(resources, 0, 0xf);
    pair.Reset();
    ZeroDestroyGPCPointer(&pair.pGPCFile);
}
