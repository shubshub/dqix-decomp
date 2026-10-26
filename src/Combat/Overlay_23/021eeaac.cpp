#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "NitroSDK/OverlayId.h"

struct Struct_020727d8;
struct Struct_0202b2f0;
struct Struct_0200f3a4_8;
struct Struct_0209a470;
struct Struct_02086f24_6;
struct Struct_02013fb4;
struct Struct_ov023_021eeaac_2;

extern "C" void Overlay_Load(unsigned int id);
void ResetListHeader020727d8(List020727d8* list);
extern "C" void func_020728ac(void* a, void* b, int c, int d, int e, int f, int g);
void CopyShortTriple0x8e4a_ov000_0215fa84(void* obj, short* a, short* b, short* c);
int AreAllListedCombatantsFlagged_021ed92c();
void ItemTable_Init(void* obj);
extern "C" int ItemTable_LoadIds(void* list, void* alloc, void* data, unsigned int size, void* entries, unsigned short count);
void* ItemTable_Construct(void* obj);
void InitStruct0207cbe8(char* obj);
extern "C" int func_0207d300(void* buf, int a, int b, int c);
extern "C" int func_0207ccf0(void* buf, int a, int b, int c, int d, int e, int f);

int GameState_GetProtagonistIndex(GameState* gs);
extern "C" SearchStruct* LinkSession_GetInstance(void);
int LinkSession_IsSlotMember(SearchStruct* search, int index);
void ClearFirstTwoWords0209a338(Pair0209a338* pair);
void SetupAndRunBufferedScript0209a470(Ctx0209a470* ctx, SafeAllocator* alloc, StreamHeader* data, int length);
void ClearField00209a804(int* field);
void SetupAndRunBufferedScript0209a8b4(Ctx0209a8b4* ctx, SafeAllocator* alloc, StreamHeader* data, int length);
void ResetFields_021eefac(Reset_021eefac* s);

extern "C" int* _ZZ17GetGlobal021ffefcvE1s;
extern const char* g_itemDataArchive;
extern const char* g_itemDataFile;
extern char data_ov023_021fe1d8;
extern char data_ov023_021fe1ee;
extern char data_ov023_021fe200;
extern char data_ov023_021fe218;
#if defined(jpn)
extern char data_ov023_021fd49e[];
#endif

struct Struct_ov023_021eeaac {
    short unknown_0_;
    unsigned short unknown_2_;
    char unknown_4_;
    signed char unknown_5_;
};

static inline SafeAllocator* inline_ov000_02166804(GameResources* arg0, int arg1) {
    return &arg0->allocator_array_38[arg1];
}

// USA: func_ov023_021eeaac
extern "C" ARM int func_ov023_021eeaac(char* arg0) {
#if defined(jpn)
 enum {Enum_ov023_021eeaac_3756=0xe28, Enum_ov023_021eeaac_22788=0x5af4, Enum_ov023_021eeaac_22784=0x5af0, Enum_ov023_021eeaac_22736=0x5ac0, Enum_ov023_021eeaac_668=0x218, Enum_ov023_021eeaac_22796=0x5afc, Enum_ov023_021eeaac_22785=0x5af1};
#else
 enum {Enum_ov023_021eeaac_3756=0xeac, Enum_ov023_021eeaac_22788=0x5904, Enum_ov023_021eeaac_22784=0x5900, Enum_ov023_021eeaac_22736=0x58d0, Enum_ov023_021eeaac_668=0x29c, Enum_ov023_021eeaac_22796=0x590c, Enum_ov023_021eeaac_22785=0x5901};
#endif
    GameResources* res = GetGameResources();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int* g = _ZZ17GetGlobal021ffefcvE1s;
    SafeAllocator* alloc = GetAllocator(res, 5);
    if (g[0] == 0) {
        Overlay_Load(OVERLAY_ID(13));
#if defined(jpn)
        var2[1] = var1->QueueLoadFile(data_ov023_021fd49e, NULL);
#else
        var2[1] = var1->QueueLoadFileInGP2(&data_ov023_021fe1d8, &data_ov023_021fe1ee, NULL);
#endif

        var2[0]++;
    } else if (var2[0] == 1) {
        if (var1->GetTaskStatus(var2[1]) == 0) {
            return *(int*)(arg0 + Enum_ov023_021eeaac_3756);
        }
        unsigned int var4;
        void* var5;
        var1->GetLoadedFileByID(var2[1], &var5, &var4);
        func_020727d8((Struct_020727d8*)(arg0 + Enum_ov023_021eeaac_22788));
        func_020728ac(arg0 + Enum_ov023_021eeaac_22788, var3, (int)var5, var4, 0, 0, 0);
        var1->RemoveTask(var2[1]);
#if defined(jpn)
        g[1] = loader->QueueLoadGP1(g_itemDataArchive, NULL);
#else
        g[1] = loader->QueueLoadFileInGP2(g_itemDataArchive, g_itemDataFile, NULL);
#endif

        var2[0]++;
    } else if (var2[0] == 2) {
        int var6;
        unsigned int var7;
        void* var8;
        int var9;
        short var10[10];
        short* var11;
        unsigned short* var12;
        int var13;
        int var14;
        short var15;
        short var16;
        short var17;
        char var18[0x38];
        void* var19;
        Struct_ov023_021eeaac* var20;
        int var21;
        GameState* var22;
        char* var23;
        int var24;
        char var25[0x38];
        int var26;
        int var27;
        int var28;
        if (var1->GetTaskStatus(var2[1]) == 0) {
            return *(int*)(arg0 + Enum_ov023_021eeaac_3756);
        }
        var1->GetLoadedFileByID(var2[1], &var8, &var7);
        var9 = *(unsigned char*)(arg0 + Enum_ov023_021eeaac_22784);
        if (var9 > 8) {
            var9 = 8;
        }
        var11 = var10;
        var12 = (unsigned short*)(arg0 + Enum_ov023_021eeaac_22736);
        for (var13 = 0; var13 < var9; var13++) {
            *var11 = *var12;
            var11++;
            var12 += 3;
        }
        if (*(short*)(*(char**)(arg0 + Enum_ov023_021eeaac_668) + 0x8e4a) > 0) {
            func_ov000_0215fa84(*(void**)(arg0 + Enum_ov023_021eeaac_668), &var15, &var17, &var16);
            var10[var9] = var16;
            var9++;
            if (var15 == 0x18 && func_ov023_021ed92c()) {
                *(unsigned char*)(*(char**)(arg0 + Enum_ov023_021eeaac_668) + 0x8e97) = 1;
            }
        }
        *(void**)(self + regionalOffset5) = alloc->Allocate(0x18);
        ItemTable_Init(*(void**)(self + regionalOffset5));
        ItemTable_LoadIds(*(void**)(self + regionalOffset5), alloc, data, length, ids, count);
        loader->RemoveTask(g[1]);
        if (*(short*)(*(char**)(self + regionalOffset4) + 0x8e4a) > 0) {
            count--;
            ((SafeAllocator*)buf)->ResetAllocatorPointer();
            ItemTable_Construct(buf + 0x14);
            InitStruct0207cbe8(buf);
            InitStruct0207cbe8(buf);
            *(void**)(buf + 0x2c) = *(void**)(self + regionalOffset5);
            func_0207d300(buf, ids[count], 1, 0);
        }
        list = *(void**)(self + regionalOffset5);
        entry = (Entry021eeaac*)(self + regionalOffset3);
        present = *(signed char*)(self + regionalOffset6);
        gs = GameState::GetInstance();
        party = (char*)GameState_GetParty(gs);
        found = 0;
        for (k = 0; k < *(unsigned char*)(party + 0xf7c); k++) {
            if (present & (1 << *(unsigned char*)(party + k + 0xf78))) {
                found = 1;
                break;
            }
        }
        if (found) {
            current = GameState_GetProtagonistIndex(gs);
            for (j = 0; j < count; j++, entry++) {
                ((SafeAllocator*)obj)->ResetAllocatorPointer();
                ItemTable_Construct(obj + 0x14);
                InitStruct0207cbe8(obj);
                InitStruct0207cbe8(obj);
                *(void**)(obj + 0x2c) = list;
                slot = entry->slot;
                if (slot < 0) {
                    result = func_0207d300(obj, entry->id, 1, 1);
                } else {
                    if (current != slot && (LinkSession_IsSlotMember(LinkSession_GetInstance(), slot) != 0 || current != 0)) {
                        if (present & (1 << current)) {
                            slot = current;
                        }
                    }
                    var26 = func_0207ccf0(var25, var20->unknown_0_, 1, var6, 1, 0, 1);
                }
                var20->unknown_2_ &= ~0x8000;
                if (var26 == 2) {
                    var20->unknown_2_ |= 0x8000;
                }
            }
        }
        var2[1] = var1->QueueLoadFile(&data_ov023_021fe200, NULL);
        var2[0]++;
    } else if (var2[0] == 3) {
        if (var1->GetTaskStatus(var2[1]) == 0) {
            return *(int*)(arg0 + Enum_ov023_021eeaac_3756);
        }
        unsigned int var29;
        void* var30;
        var1->GetLoadedFileByID(var2[1], &var30, &var29);
        func_0209a338((Struct_0200f3a4_8*)(var2 + 0xe8 / 4));
        func_0209a470((Struct_0209a470*)(var2 + 0xe8 / 4), var3, (Struct_02013fb4*)var30, var29);
        var1->RemoveTask(var2[1]);
        var2[1] = var1->QueueLoadFile(&data_ov023_021fe218, NULL);
        var2[0]++;
    } else if (var2[0] == 4) {
        if (var1->GetTaskStatus(var2[1]) == 0) {
            return *(int*)(arg0 + Enum_ov023_021eeaac_3756);
        }
        unsigned int var31;
        void* var32;
        var1->GetLoadedFileByID(var2[1], &var32, &var31);
        func_0209a804(var2 + 0xf0 / 4);
        func_0209a8b4((Struct_02086f24_6*)(var2 + 0xf0 / 4), var3, (Struct_02013fb4*)var32, var31);
        var1->RemoveTask(var2[1]);
        func_ov023_021eefac((Struct_ov023_021eeaac_2*)var2);
        return 3;
    }
    return *(int*)(arg0 + Enum_ov023_021eeaac_3756);
}
