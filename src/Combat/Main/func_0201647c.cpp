#include <globaldefs.h>
#include <World/LootableContainer.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/FileIO.h>
#include <World/ZoneChest.h>

#if defined(jpn)
#define func_0205ec34 func_0205ff20
#endif

struct Struct_0201647c {
    unsigned int unknown_0_0_ : 16;
    unsigned int unknown_2_0_ : 16;
    unsigned int unknown_4_0_ : 4;
    unsigned int unknown_4_4_ : 28;
    unsigned char unknown_8_[0x64];
    Struct_0201647c* unknown_6c_;
};
struct Struct_0201647c_2 {
    unsigned int unknown_0_;
    Struct_0201647c* unknown_4_;
    unsigned int unknown_8_;
    short* unknown_c_;
};
struct Struct_020130b0;
extern "C" void* func_0205ec34();
extern "C" int* func_0202ae18();
extern "C" void* func_0208e0a8();
int IsMatchingName0208e824(void*, char*);
int TestBitInByteArray_0206dfb0(int, unsigned char*, int);
int CheckField0NonZero_0202b7d8(int*);
ListNode* FindNodeById_0201e844(void*, int, int);
void ItemTable_Init(void*);
extern "C" int ItemTable_LoadIds(void*, SafeAllocator*, void*, unsigned int, short*, unsigned short);
extern "C" void func_02013b70(Zone3D*, SafeAllocator*);
extern const char* g_itemDataArchive;
extern const char* g_itemDataFile;

#if defined(jpn)
extern "C" int func_020e0484(void*, SafeAllocator*, const char*, short*, unsigned short, bool);
#endif

// USA: func_0201647c
extern "C" ARM void func_0201647c(Zone3D* arg0) {
    SafeAllocator* var0 = arg0->pAllocator_68_;
    LootableContainerManager* var1 = LootableContainerManager::GetMainInstance();
    unsigned char* var2 = (unsigned char*)func_0205ec34();
    int* var3 = func_0202ae18();
    Struct_0201647c_2* var4 = (Struct_0201647c_2*)func_0208e0a8();
    LootableContainerManager::Container* var5 = var1->pContainerList_;
    bool var6 = false;
    if (func_0208e824(var4, arg0->pUnknownStruct_8_->mapShortName_)) var6 = true;
    int var7 = 0;
    for (; var5; var5 = var5->pNext) {
        if (var5->containerType == 0 || var5->containerType == 4) var7++;
    }
    arg0->unknown_47c_ = (Struct_020133fc*)var0->Allocate(var7 * sizeof(Struct_020133fc));
    if (!arg0->unknown_47c_) return;
    var5 = var1->pContainerList_;
    arg0->numChests_ = 0;
    for (; var5; var5 = var5->pNext) {
        if (var5->containerType == 0 || var5->containerType == 4) {
            Struct_020133fc* var8 = &arg0->unknown_47c_[arg0->numChests_];
            func_020133fc(var8);
            var8->unknown_0_ = var5->position;
            var8->unknown_c_ = var5->unk_6;
            var8->unknown_10_ = 0;
            var8->unknown_1a_ = arg0->numChests_;
            var8->unknown_1c_ = var5->uniqueID;
            var8->unknown_17_ = 0;
            if (var5->containerType == 4) var8->unknown_17_ = 1;
            if ((var5->containerType == 0 &&
                 func_0206dfb0((int)var2, var2 + 0x8c, var5->uniqueID + 0x212)) ||
                (var5->containerType == 4 &&
                 func_0206dfb0((int)var2, var2 + 0x8c, var5->uniqueID + 0x79e))) {
                var8->unknown_16_ = 8;
                var8->unknown_e_ = 0x4000;
                var5->lootType = 0;
            } else {
                var8->unknown_16_ = 1;
                var8->unknown_e_ = 0x647a;
            }
            if (func_0202b7d8(var3) && var5->containerType == 4)
                var8->unknown_18_ = 1;
            arg0->numChests_++;
        } else if (var5->containerType == 3) {
            Struct_020130b0* var9 = func_0201e844(&arg0->substruct_6c_, 5, (unsigned short)var5->unk_6);
            if (var9) *(unsigned short*)((char*)var9 + 0x30) = var5->uniqueID;
        }
    }
    short var10[100];
    int var11 = 0;
    for (var5 = var1->pContainerList_; var5; var5 = var5->pNext) {
        if (var5->lootType == 2) {
            unsigned int var12 = var5->itemIDOrRank;
            bool var13 = true;
            for (int var14 = 0; var14 < var11; var14++) {
                if (var12 == var10[var14]) {
                    var13 = false;
                    break;
                }
            }
            if (var13) var10[var11++] = var12;
        }
    }
    if (var6 && var4->unknown_4_) {
        Struct_0201647c* var15 = var4->unknown_4_;
        if (var15->unknown_4_0_ == 9) {
            short* var16 = var4->unknown_c_;
            if (var16) {
                for (int var17 = 0; var17 < 16; var11++, var16++, var17++) var10[var11] = *var16;
            }
        } else {
            while (var15) {
                var10[var11++] = var15->unknown_0_0_;
                var15 = var15->unknown_6c_;
            }
        }
    }
    ItemTable_Init(zone->unknown_struct_2754_);
    if (count > 0) {
#if defined(jpn)
        func_020e0484(zone->unknown_struct_2754_, allocator, g_itemDataArchive, ids,
            (unsigned short)count, true);
#else
        BackgroundLoader::AddLockGlobal();
        unsigned int size = 0;
        void* file = ExtractFileFromGP2(g_itemDataArchive, g_itemDataFile, &size);
        if (file) ItemTable_LoadIds(zone->unknown_struct_2754_, allocator, file, size, ids, (unsigned short)count);
        BackgroundLoader::RemoveLockGlobal();
#endif
    }
    func_02013b70(arg0, arg0->pAllocator_68_);
    if (arg0->unknown_27da_) {
        func_02013cb0(arg0, arg0->unknown_27da_);
        arg0->unknown_27da_ = 0;
    }
    if (arg0->unknown_27d8_) {
        func_02018c74(arg0, arg0->unknown_27d8_);
        arg0->unknown_27d8_ = 0;
    }
}
