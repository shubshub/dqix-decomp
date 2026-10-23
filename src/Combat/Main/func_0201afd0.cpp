#include <globaldefs.h>
#include "GameState/GameState.h"
#include "World/ZoneFeatures.h"
#include "World/ZoneChest.h"
#include "World/LootableContainer.h"
#include "Filesystem/FileIO.h"
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/Memory.h"
#include "std_library_functions.h"

struct Struct_0201afd0 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned short unknown_4_0_ : 2;
    unsigned short unknown_4_2_ : 2;
    unsigned short unknown_4_4_ : 3;
    short unknown_6_;
    Vector3i unknown_8_;
};

struct Struct_0201afd0_2;

struct Struct_0201afd0_3 {
    unsigned char unknown_0_;
};

struct Struct_020e6df0 {
    char unknown_0_[11];
};

struct Struct_020105a8;
struct Struct_0201afd0_4;
struct Struct_0201e690;
struct Struct_020134e0_2;
struct Struct_0201afd0_5;
struct Struct_02011430;
struct Struct_0201afd0_6;
struct Struct_0201afd0_7;
extern "C" void* func_0202ae18();
extern "C" void func_020105a8(Struct_020105a8*, int*);
int GenerateGrottoObjectPositionOrientation(void*, int, int, int*, int*, const TileFeaturePlacementData*, bool);
Entry_1e690* FindEntryById_0201e690(EntryList_1e690*, int);
void ClearThreeWords02094d00(ClearThreeWords02094d00Struct*);
void AllocateArray02094cdc(AllocDest02094cdc*, int, SafeAllocator*);
int GetBit5cd0(S_02011430*, int, int);
int CheckField0NonZero_0202b7d8(int*);
void CopyElemToIndex(Container02094d14*, Elem02094d14*, int);
void ItemTable_Init(void*);
extern "C" int ItemTable_LoadIds(void*, SafeAllocator*, void*, unsigned int, unsigned short*, unsigned short);
extern "C" void __clear(void*, int);

#if defined(jpn)
extern "C" int func_020e0484(void*, SafeAllocator*, const char*, unsigned short*, unsigned short, bool);
#define data_020e6df0 data_020e7694
#endif

extern const unsigned char data_020e6e44[15];
extern const NarcName0201afd0 data_020e6df0;
extern const char* g_itemDataArchive;
extern const char* g_itemDataFile;

static inline GrottoTilePoint inline_0201afd0(const FloorMap* arg0, unsigned char arg1) {
    return arg0->chests[arg1];
}

static inline int inline_0201afd0_2(int arg0) {
    return (int)(((long long)arg0 * arg0 + 0x800) >> 12);
}

static inline Struct_0201afd0_3 inline_0201afd0_3(const FloorMap* arg0, int arg1, int arg2) {
    Struct_0201afd0_3 var0;
    var0.unknown_0_ = arg0->GetAdjacencyBits(arg1, arg2);
    return var0;
}

static inline int inline_0201afd0_4(const ActiveGrottoClass* arg0, int arg1) {
    unsigned short var0 = arg0->GetActiveGrottoSeed();
    return var0 + arg1;
}

// USA: func_0201afd0
extern "C" ARM int func_0201afd0(Zone3D* arg0, const void* arg1, unsigned int arg2, int arg3) {
    Struct_020134e0* var0 = &arg0->substruct_6c_;
    GameState* var1 = GameState::GetInstance();
    ActiveGrottoClass* var2 = &arg0->grotto_;
    int var3;
    FloorMap* var4 = &var2->floorMap_;
    void* var5 = func_0202ae18();
    Struct_0201afd0_2* var6 = (Struct_0201afd0_2*)(arg0->unknown_struct_2724_);

    arg0->numChests_ = var4->chestCount;
    if (arg0->numChests_ == 0) {
        int var7;

        func_020105a8((Struct_020105a8*)(var1), &var7);
        srand(var7 + inline_0201afd0_4(var2, arg0->currentGrottoFloor_23ba_));
        return 0;
    }

    arg0->unknown_47c_ = (Struct_020133fc*)arg0->pAllocator_68_->Allocate(arg0->numChests_ * sizeof(Struct_020133fc));
    var0->func_0201e634(arg0->numChests_, arg0->pAllocator_68_);
    srand(inline_0201afd0_4(var2, arg0->currentGrottoFloor_23ba_));

    for (var3 = 0; var3 < arg0->numChests_; var3++) {
        Struct_020134e0::Struct_02018300 var8;
        GrottoTilePoint var9;
        Struct_0201afd0_3 var10;
        int var11;
        int var12;

        VectorizedMemset(&var8, 0, sizeof(var8));
        var8.unknown_20_ = 0;
        var8.unknown_22_ = 0;
        var8.unknown_24_ = 0;
        var8.unknown_8_.unknown1_0_.x = 0;
        var8.unknown_8_.unknown1_0_.y = 0;
        var8.unknown_8_.unknown1_0_.z = 0;
        var8.unknown_28_ = 0;
        var8.unknown_70_ = NULL;

        var8.unknown_0_ = var3;
        var8.unknown_14_.unknown1_0_.z = 0x1000;
        var8.unknown_14_.unknown1_0_.y = 0x1000;
        var8.unknown_14_.unknown1_0_.x = 0x1000;
        var8.unknown_4_ = 1;

        var9 = inline_0201afd0(var4, var3);
        var11 = GenerateGrottoObjectPositionOrientation(
            arg0, (unsigned char)(var9.x), (unsigned char)(var9.y), &var8.unknown_8_.unknown1_0_.x, &var8.unknown_8_.unknown1_0_.z, NULL, false);
        var10 = inline_0201afd0_3(var4, (unsigned char)(var9.x), (unsigned char)(var9.y));
        var12 = 0;
        if (var2->GetActiveGrottoEnviron() == 2) {
            for (int var13 = 0; var13 < 15; var13++) {
                if (var10.unknown_0_ == data_020e6e44[var13]) {
                    var12 = 1;
                    break;
                }
            }
            if (!var12) {
                var8.unknown_8_.unknown1_0_.y = -0x4cc;
            }
        }

        switch (var11) {
        case 0:
            var8.unknown_20_ = var8.unknown_22_ = 0x3244;
            break;
        case 1:
            var8.unknown_20_ = var8.unknown_22_ = 0x1922;
            break;
        case 2:
            var8.unknown_20_ = var8.unknown_22_ = 0;
            break;
        case 3:
            var8.unknown_20_ = var8.unknown_22_ = 0x4b66;
            break;
        }

        {
            fix32_t var14 = var8.unknown_14_.unknown1_0_.x / 2;
            fix32_t var15 = var8.unknown_14_.unknown1_0_.z / 2;
            fix32_t var16 = inline_0201afd0_2(var15);
            fix32_t var17 = inline_0201afd0_2(var14);

            var8.unknown_24_ = var17 + var16;
        }
        var8.unknown_70_ = NULL;
        var0->func_0201e710(var8);
    }

    {
        SafeAllocator var18;
        char var19[0x400];
        LootDistribution var20;
        Struct_020e6df0 var21;
        const void* var22;
        unsigned int var23;
        int var24[32];
        unsigned short var25[100];
        int var26;
        int var27;
        int var28;
        int var29;

        var18.ResetAllocatorPointer();
        var18.CreateTypeA(var19, sizeof(var19));
        var21 = data_020e6df0;
        if (GetFileInNarcPermissive(arg1, var21.unknown_0_, &var22, &var23)) {
            var20.Reset();
            var20.LoadFromScript(&var18, var22, var23);
        }

        func_02094d00((Struct_020134e0_2*)(var6));
        func_02094cdc((Struct_0201afd0_5*)(var6), arg0->numChests_, arg0->pAllocator_68_);
        memset(var24, 1, sizeof(var24));
        for (var28 = 0; var28 < arg0->numChests_; var28++) {
            var24[var28] = var2->RandomizeChestRank(arg0->currentGrottoFloor_23ba_);
        }

        func_020105a8((Struct_020105a8*)(var1), &var26);
        srand(var26 + inline_0201afd0_4(var2, arg0->currentGrottoFloor_23ba_));

        __clear(var25, sizeof(var25));
        var27 = 0;
        for (var29 = 0; var29 < arg0->numChests_; var29++) {
            Struct_020134e0::Struct_02018300* var30 = (Struct_020134e0::Struct_02018300*)(func_0201e690((Struct_0201afd0_4*)(var0), var29));
            const LootDistribution::Outcome* var31 = var20.Sample(var24[var29]);

            if (var31 != NULL) {
                Struct_020133fc* var32 = &arg0->unknown_47c_[var29];
                Struct_0201afd0 var33;

                func_020133fc(var32);
                var32->unknown_0_ = var30->unknown_8_.unknown1_0_;
                var32->unknown_c_ = var30->unknown_20_;
                var32->unknown_10_ = 0;
                var32->unknown_1a_ = var29;
                var32->unknown_1c_ = var29;
                var32->unknown_17_ = 2;
                if (func_02011430((Struct_02011430*)(var1), arg0->currentGrottoFloor_23ba_, var29)) {
                    var32->unknown_16_ = 8;
                    var32->unknown_e_ = 0x4000;
                } else {
                    var32->unknown_16_ = 1;
                    var32->unknown_e_ = 0x647a;
                }
                if (func_0202b7d8((int*)(var5))) {
                    var32->unknown_18_ = 1;
                }
                if (var31->lootType == 2) {
                    var25[var27++] = var31->itemID;
                }

                var33.unknown_0_ = 0;
                var33.unknown_2_ = var31->itemID;
                var33.unknown_4_0_ = 0;
                var33.unknown_4_2_ = var31->lootType;
                var33.unknown_4_4_ = 4;
                var33.unknown_8_ = var30->unknown_8_.unknown1_0_;
                func_02094d14((Struct_0201afd0_6*)(var6), (Struct_0201afd0_7*)(&var33), var32->unknown_1c_);
            }
        }

        ItemTable_Init(zone->unknown_struct_2754_);
        if (itemCount > 0) {
#if defined(jpn)
            func_020e0484(zone->unknown_struct_2754_, zone->pAllocator_68_, g_itemDataArchive, itemIDs, itemCount, true);
#else
            BackgroundLoader::AddLockGlobal();
            unsigned int size = 0;
            void* data = ExtractFileFromGP2(g_itemDataArchive, g_itemDataFile, &size);

            if (data != NULL) {
                ItemTable_LoadIds(zone->unknown_struct_2754_, zone->pAllocator_68_, data, size, itemIDs, itemCount);
            }
            BackgroundLoader::RemoveLockGlobal();
#endif
        }
        var18.Reset();
        var18.Destroy();
    }
    return 1;
}
