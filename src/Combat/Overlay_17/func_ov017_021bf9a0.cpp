#include <globaldefs.h>
#include "Resource/TextQueue.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "World/LootableContainer.h"
#include "Resource/GameResources.h"

#if defined(jpn)
#define func_0205ec34 func_0205ff20
#endif

#if defined(jpn)
#define func_0206df6c func_0206f0c0
#endif

struct State0207dfc8 { unsigned int words[28]; };
struct StoreStruct;
struct Struct0218d618;
struct SePlayer;
struct Container020dedd0;
struct LootEventInfo { char pad0[0x30]; unsigned short containerId; };
struct LootEvent {
    char pad0[8]; unsigned short timer; short fieldA;
    LootEventInfo* info; Foo02048004* display; short taskId;
    char pad16[0x28 - 0x16]; Vector3fix position; SafeAllocator allocator;
    unsigned char special;
};
#if defined(jpn)
struct Struct_ov017_021bf9a0_3 { char unknown_0_[0x2794]; char unknown_2754_[4]; };
#else
struct Struct_ov017_021bf9a0_3 { char unknown_0_[0x2754]; char unknown_2754_[4]; };
#endif
struct Struct_ov017_021a7e14_4 {
    SafeAllocator unknown_0_; char unknown_14_[0x18]; Struct_0201099c_10* unknown_2c_;
    int unknown_30_; int unknown_34_;
};
extern "C" Struct_020465c0* func_020421a0();
extern "C" Struct_ov017_021bf9a0_3* func_02012fe4();
extern "C" unsigned char* func_0205ec34();
extern "C" int func_ov017_0218d618(Struct_ov017_0218d618_2*);
extern "C" void* func_02012d88(AllocatorUnion*, unsigned int);
extern "C" void func_02047230(Struct_02012fa4*);
extern "C" void func_0207dfc8(Struct_02015ef4_5*, Struct_02015ef4_5*);
extern "C" void func_0207df90(char*);
extern "C" void func_0207dfac(char*);
extern "C" void func_02047b30(void*, int, int, int);
extern "C" int func_0206dfb0(int, unsigned char*, int);
extern "C" void func_0206df6c(void*, unsigned char*, int, int);
extern "C" void func_ov017_021cdb00(int, int, int, int);
extern "C" void __clear(void*, int);
extern "C" void* func_020de824(void*);
extern "C" void func_0207cbe8(char*);
extern "C" int func_0207d538(void*, int, int, char*, int);
extern "C" void* func_020d7a50();
extern "C" void func_ov017_0218d644(GameResources*, Vector3fix*, int);
void SePlayer_Play(SePlayer*, int, int);
extern AllocatorUnion data_02114e20;
extern SePlayer g_sePlayer;

static inline char& inline_ov017_021bf9a0(GameResources* arg0, int arg1) {
    return arg0->unknown_2cc_[arg1];
}

// USA: func_ov017_021bf9a0
extern "C" ARM int func_ov017_021bf9a0(Struct_ov017_021bf9a0_2* arg0) {
    unsigned int var0 = GameState::GetInstance()->GetEffectiveDeltaTime();
    if (var0 < arg0->unknown_8_) { arg0->unknown_8_ -= var0; return 3; }
    arg0->unknown_8_ = 0;
    func_020421a0();
    Struct_ov017_021bf9a0* var1 = arg0->unknown_c_;
    func_02012fe4();
    BackgroundLoader* var2 = BackgroundLoader::GetInstance();
    LootableContainerManager* var3 = LootableContainerManager::GetMainInstance();
    unsigned char* var4 = func_0205ec34();
    if (!var3 || !var4) return 3;
    if (arg0->unknown_48_) {
        if (!func_ov017_0218d618((Struct_ov017_0218d618_2*)GetGameResources())) return 5;
    } else if (arg0->unknown_14_ >= 0) {
        if (var2->GetTaskStatus(arg0->unknown_14_)) {
            void* var5 = 0;
            unsigned int var6 = 0;
            var2->GetLoadedFileByID(arg0->unknown_14_, &var5, &var6);
            void* var7 = func_02012d88(&data_02114e20, 256);
            if (var5 && var7) {
                arg0->unknown_34_.CreateTypeA(var7, 256);
                func_02047230(arg0->unknown_10_);
                func_0204719c(arg0->unknown_10_);
                Struct_02015ef4_5 var8;
                func_0207dfc8((Struct_02015ef4_5*)&inline_ov017_021bf9a0(GetGameResources(), 0x230), &var8);
                func_0207df90((char*)&var8);
                func_02047b30(arg0->unknown_10_, (int)var5, var6, (int)&arg0->unknown_34_);
                func_0207dfac((char*)&var8);
            }
            var2->RemoveTask(arg0->unknown_14_);
            arg0->unknown_14_ = -1;
        } else return 3;
    }
    arg0->unknown_8_ = 300;
    unsigned short var9 = 0;
    LootableContainerManager::Container* var10 = var3->GetContainerByID(var1->unknown_30_, &var9);
    if (var10) {
        int var11 = var10->uniqueID;
        int var12 = var11 + 0x79e;
        if (!func_0206dfb0((int)var4, var4 + 0x8c, var12)) {
            func_0206df6c(var4, var4 + 0x8c, var12, 1);
            func_ov017_021cdb00(8, var11, 1, -1);
            char var13[128] = {};
            Struct_ov017_021bf9a0_3* var14 = func_02012fe4();
            Struct_ov017_021a7e14_4 var15;
            var15.unknown_0_.ResetAllocatorPointer();
            func_020de824(var15.unknown_14_);
            func_0207cbe8((char*)&var15);
            func_0207cbe8((char*)&var15);
            var15.unknown_2c_ = (Struct_0201099c_10*)var14->unknown_2754_;
            if (func_0207d538(&var15, var10->lootType, var10->itemIDOrRank, var13, 1)) {
#if defined(jpn)
                func_020d7e10(func_020d7a50(), var13, 0, 0, 1);
#else
                func_020d7e10(func_020d7a50(), var13, 0, 0, 1, 0);
#endif
                GameResources* resources = GetGameResources();
                if (self->special) func_ov017_0218d644(resources, &self->position, 0);
                else SePlayer_Play(&g_sePlayer, 14, 0);
                return 4;
            }
        }
    }
    return 5;
}
