#include <globaldefs.h>
#include "Combat/SearchEntry.h"

#if defined(jpn)
enum {
    Enum_ov017_021941fc_371 = 0x16f,
    Enum_ov017_021941fc_1788 = 0x4ec,
    Enum_ov017_021941fc_1844 = 0x524,
    Enum_ov017_021941fc_17408 = 0x4100,
    Enum_ov017_021941fc_172 = 0xfc,
    Enum_ov017_021941fc_739 = 0xc3,
    Enum_ov017_021941fc_207 = 0xcb,
    Enum_ov017_021941fc_738 = 0xc2,
    Enum_ov017_021941fc_969 = 0x139,
    Enum_ov017_021941fc_737 = 0xc1,
    Enum_ov017_021941fc_1052 = 0x16c,
    Enum_ov017_021941fc_741 = 0xc5,
    Enum_ov017_021941fc_752 = 0xd0,
    Enum_ov017_021941fc_798 = 0xfe,
    Enum_ov017_021941fc_2816 = 0x8e0,
    Enum_ov017_021941fc_2864 = 0x910,
    Enum_ov017_021941fc_348 = 0x150,
    Enum_ov017_021941fc_352 = 0x154,
    Enum_ov017_021941fc_364 = 0x160,
    Enum_ov017_021941fc_2860 = 0x90c,
    Enum_ov017_021941fc_1816 = 0x508,
    Enum_ov017_021941fc_2908 = 0x93c,
    Enum_ov017_021941fc_2812 = 0x8dc,
    Enum_ov017_021941fc_2828 = 0x8ec,
    Enum_ov017_021941fc_2832 = 0x8f0,
    Enum_ov017_021941fc_2852 = 0x904,
    Enum_ov017_021941fc_2856 = 0x908,
    Enum_ov017_021941fc_2952 = 0x968,
    Enum_ov017_021941fc_3004 = 0x99c,
    Enum_ov017_021941fc_1804 = 0x4fc,
    Enum_ov017_021941fc_85 = 0x35,
    Enum_ov017_021941fc_17152 = 0x4100,
    Enum_ov017_021941fc_178 = 0xa6,
    Enum_ov017_021941fc_853 = 0x135,
};
#else
enum {
    Enum_ov017_021941fc_371 = 0x173,
    Enum_ov017_021941fc_1788 = 0x6fc,
    Enum_ov017_021941fc_1844 = 0x734,
    Enum_ov017_021941fc_17408 = 0x4400,
    Enum_ov017_021941fc_172 = 0xac,
    Enum_ov017_021941fc_739 = 0x2e3,
    Enum_ov017_021941fc_207 = 0xcf,
    Enum_ov017_021941fc_738 = 0x2e2,
    Enum_ov017_021941fc_969 = 0x3c9,
    Enum_ov017_021941fc_737 = 0x2e1,
    Enum_ov017_021941fc_1052 = 0x41c,
    Enum_ov017_021941fc_741 = 0x2e5,
    Enum_ov017_021941fc_752 = 0x2f0,
    Enum_ov017_021941fc_798 = 0x31e,
    Enum_ov017_021941fc_2816 = 0xb00,
    Enum_ov017_021941fc_2864 = 0xb30,
    Enum_ov017_021941fc_348 = 0x15c,
    Enum_ov017_021941fc_352 = 0x160,
    Enum_ov017_021941fc_364 = 0x16c,
    Enum_ov017_021941fc_2860 = 0xb2c,
    Enum_ov017_021941fc_1816 = 0x718,
    Enum_ov017_021941fc_2908 = 0xb5c,
    Enum_ov017_021941fc_2812 = 0xafc,
    Enum_ov017_021941fc_2828 = 0xb0c,
    Enum_ov017_021941fc_2832 = 0xb10,
    Enum_ov017_021941fc_2852 = 0xb24,
    Enum_ov017_021941fc_2856 = 0xb28,
    Enum_ov017_021941fc_2952 = 0xb88,
    Enum_ov017_021941fc_3004 = 0xbbc,
    Enum_ov017_021941fc_1804 = 0x70c,
    Enum_ov017_021941fc_85 = 0x55,
    Enum_ov017_021941fc_17152 = 0x4300,
    Enum_ov017_021941fc_178 = 0xb2,
    Enum_ov017_021941fc_853 = 0x355,
};
#endif
#include "Combat/NameEntryQueue.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"
#include "Input/Input.h"


struct Struct_0202b2f0;
struct Struct_0202c1a4;
struct Struct_0209494c {
    char unknown_0_[Enum_ov017_021941fc_969];
    unsigned char unknown_3c9_0_ : 1;
    unsigned char unknown_3c9_1_ : 7;
    unsigned char unknown_3ca_;
    signed char unknown_3cb_;
};
struct Struct_02012de8;
struct Struct_02038598_4;
struct Struct_020469f8;
struct Struct_020469f8_2;
struct Struct_02015438;
struct Struct_02038598_5;
struct Struct_0203402c;
struct Struct_02039df4;
struct Struct_ov017_0218e674;
struct Struct_02033834_2;
struct Struct_02033834;
struct Struct_02033b68;
struct Struct_02028460_3 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
};

struct Struct_02061c04_10 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    short unknown_6_;
    unsigned char unknown_8_;
    unsigned short unknown_a_;
    signed char unknown_c_;
    unsigned char unknown_d_;
    float unknown_10_;
};

struct Struct_ov017_021941fc_2 {
    unsigned short unknown_0_0_ : 8;
    unsigned short unknown_1_0_ : 8;
    unsigned short unknown_2_0_ : 1;
    unsigned short unknown_2_1_ : 4;
    unsigned short unknown_2_5_ : 6;
    unsigned short unknown_3_3_ : 1;
    unsigned short unknown_3_4_ : 1;
    unsigned short unknown_3_5_ : 1;
    unsigned short unknown_3_6_ : 1;
    unsigned short unknown_3_7_ : 1;
    unsigned short unknown_4_0_ : 16;
    unsigned short unknown_6_0_ : 16;
    short unknown_8_;
    short unknown_a_;
    short unknown_c_;
    short unknown_e_;
};
struct Struct_ov017_021941fc_3 {
    unsigned char unknown_0_0_ : 2;
    unsigned char unknown_0_2_ : 6;
};
extern "C" struct SearchStruct* LinkSession_GetInstance(void);
extern "C" void* Scenario_GetInstance(void);
void* GlobalFlags_GetInstance(void);
int* GetGlobal02109030_020936f8(void);
void* GetData02153634_020e3580(void);
int FieldTaskQueue_IsEmpty(void** obj);
void EnqueueEventTag142_021cd6d8(struct Src021cd6d8* src);
extern "C" void func_ov017_0219577c(int a, int b, int c);
void RegisterNodeAndNotify_0219593c(void);
void ResetAndSetFlag0x3c9Bit0_020939dc(void* obj);
int GameState_GetProtagonistIndex(GameState* battleStruct);
void SetCombatModeFromCase020dc2d0(int mode);
void ResetEightRegionsAndFlags_02093a14(char* obj);
extern "C" void func_02094030(int* a, int b, int c, signed char d);
int CheckFlag0x3c9Bit0OrByteNonPositive_0209494c(struct StateFlags3c9* obj);
int LinkSession_IsActive(int* obj);
unsigned int FlagWord_TestBits(struct FlagWord02046708* obj, unsigned int mask);
void ClearFlag0x3c9Bit0AndCleanup_020939fc(unsigned char* obj);
extern "C" void func_ov017_021c37a4(void);
extern "C" int LinkSession_IsHostOrSolo(struct SearchStruct* obj);
int LinkSession_IsSlotLost(struct SearchStruct* obj, int value);
int TestSearchFlagBit0202c758(struct SearchStruct* obj, int value);
void EnqueueEventTag173_021d1810(int, int, signed char);
void EnqueueEventTag49_021cea34(int a0);
void SetSearchFlagBit0202c6dc(struct SearchStruct* obj, int value);
extern "C" int func_ov017_02195658(unsigned char* self);
extern "C" int LinkSession_IsGuest(struct SearchStruct* obj);
void SetFlagAndCleanup_02195618(unsigned char* obj);
void UpdateGlobalAndCombatantFlagBytes_020e35a0(unsigned char* p);
void FlagWord_ClearBits(struct FlagWord020466f4* obj, unsigned int mask);
int PopFrontAndCompactEntries_0219531c(void* obj, void* outEntry);
int GameState_GetOwnPartyOrder(char* obj, void* dst);
int Scenario_TestFlag(int unused, unsigned char* arr, int index);
extern "C" void func_ov017_02195250(void* d, void* buf);
int LinkSession_IsSlotConnected(struct SearchStruct* obj, int value);
void FlagWord_SetBits(unsigned int* obj, unsigned int mask);
void EnqueueEventTag44_021cc198(unsigned char a, int b);
extern "C" void func_ov017_021d0b30(int a, int b, void* c);
void ClearSearchFlagBit0202c69c(struct SearchStruct* obj, int value);
void ClearSearchFlagBit0202c718(struct SearchStruct* obj, int value);
void SetSearchFlagBit0202c660(struct SearchStruct* obj, int value);
int LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
GameObject* GetCombatantWithFlag0x200_0200fee0(GameState* battleStruct, int combatantId);
void CallIndexedHandler_02195494(void* obj, int index, int val);
extern "C" int func_0202bd68(struct SearchStruct* self, int bitIndex);
void SetField4b0_02167240(void* obj);
extern "C" int abs(int x);
extern "C" void func_ov017_021af59c(void* obj);
void PrependNodeToHead(struct HeadList020469f8* list, struct HeadNode020469f8* node);
int LinkSession_IsSlotMember(struct SearchStruct* obj, int value);
extern "C" void func_ov017_021905b8(unsigned char* ov, int combatantId, int mode);
int ListContainsId(struct ListHead02046b60* list, int id);
void* LinkSession_GetOwnRecord(void* base);
int GetField0x158_02053ed0(void* obj);
int GameObject_IsSinking(struct BitField0203402c* p);
extern "C" int fix32_Divide(int a, int b);
int FieldTaskQueue_GetCurrentKind(struct HeadNode02046b24** obj);
unsigned short LinkSession_GetConnectedAids(struct SearchStruct* obj);
int HasFlag3orFlag2And9a_021bd3a4(struct Obj_021bd3a4* obj);
int GameObject_GetLineLeader(void* obj);
struct Vector3i;
void GameObject_SetFacing(struct Obj02033834* obj, int value);
void GameObject_SnapFacing(struct Obj02033874* obj, int value);
int GameObject_IsGesturing(signed char* p);
extern "C" void func_020531f0(void* obj);
GameObject* FindCombatantByField0x16a_0200ffe0(GameState* battleStruct, int id);
void TrySetMode02076ccc(void* obj, int mode);
extern "C" void func_ov017_021917f0(int id, int flag);
void GameObject_SetMotionState(struct Obj02033b68* obj, int value);
extern "C" void func_ov017_021bd4d0(void* obj, unsigned char id, int a, int b);
extern "C" void func_ov017_021d48f0(void);
extern "C" void* func_0207d78c(void);
extern "C" void func_0207dba8(void* arg0);
extern int data_ov017_021d63f0;
extern int data_ov017_021d63d8;
extern int data_ov017_021d63e4;
extern int data_ov017_021d63fc;
// USA: func_ov017_021941fc
extern "C" ARM void func_ov017_021941fc(unsigned char* arg0, unsigned char* arg1, void** arg2) {
    struct Struct_02061c04_10 var0;
    unsigned char var1[15];
    int var2[3];
    int var3[3];
    struct Struct_02028460_3 var4;
    unsigned char var5[4];

    GameState* battle;
    struct SearchStruct* search;
    GameObject* actor;
    void* flags;
    int ctx;
    void* loader;
    void* owner;
    int* g;
    unsigned char* status;
    battle = GameState::GetInstance();
    ctx = ((int)GetGameResources());
    search = LinkSession_GetInstance();
    actor = battle->GetLeader();
    loader = (void*)(int)BackgroundLoader::GetInstance();
    list = *(void***)(ov + 0x3000 + kRegionOffset6fc);
    owner = Scenario_GetInstance();
    flags = GlobalFlags_GetInstance();
    g = GetGlobal02109030_020936f8();
    mode = *(unsigned char**)(ov + 0x3000 + kRegionOffset734);
    status = (unsigned char*)GetData02153634_020e3580();
    if (FieldTaskQueue_IsEmpty(list) != 0 && *(unsigned short*)(ov + kRegionOffset4400 + kRegionOffsetac) != 0) {
        params.f0 = 0;
        params.f2 = 0;
        params.f4 = 0;
        params.f6 = 0;
        params.f8 = 0;
        params.fa = 0;
        params.f10 = 0.0f;
        params.fc = -1;
        params.f2 = *(unsigned short*)(ov + kRegionOffset4400 + kRegionOffsetac);
        EnqueueEventTag142_021cd6d8(&params);
        *(unsigned short*)(ov + kRegionOffset4400 + kRegionOffsetac) = 0;
    }
    if (IsBrightnessZero((GameResources*)arg0, false) != 0) {
        int var15 = 0;
        if (*(unsigned char*)(arg0 + 0x4000 + Enum_ov017_021941fc_739) != 0) {
            unsigned char* var16 = *(unsigned char**)((unsigned char*)var10 + 0x3000 + Enum_ov017_021941fc_1844);
            if (var16[3] != 0 && *(unsigned short*)(var16 + 8) == 0 && var16[Enum_ov017_021941fc_207] == 2) {
                func_ov017_0219577c(0, 0, 0);
            } else {
                func_ov017_0219593c();
                func_020939dc(func_020936f8());
            }
            restart = 1;
        } else if (FieldTaskQueue_IsEmpty(list) != 0 && *(unsigned char*)(ov + 0x4000 + kRegionOffset2e2) != 0) {
            if (GameState_GetProtagonistIndex(battle) != 0) {
                func_ov017_0219577c(0, 1, 1);
            }
            var15 = 1;
        }
        if (var15 != 0) {
            func_020dc2d0(0);
            func_02093a14((char*)var13);
            func_02094030(var13, 4, -1, 0);
            *(unsigned char*)(arg0 + 0x4000 + Enum_ov017_021941fc_738) = 0;
            *(unsigned char*)(arg0 + 0x4000 + Enum_ov017_021941fc_739) = 0;
        }
    }
    if (((struct StateFlags3c9*)g)->bit0 &&
        CheckFlag0x3c9Bit0OrByteNonPositive_0209494c((struct StateFlags3c9*)g) != 0 &&
        LinkSession_IsActive((int*)search) == 0 &&
        FlagWord_TestBits((struct FlagWord02046708*)flags, 0x1000) == 0) {
        ClearFlag0x3c9Bit0AndCleanup_020939fc((unsigned char*)g);
    }
    if (TestFlags00((GameResources*)ov, 2) != 0) return;
    if (LinkSession_IsActive((int*)search) == 0) return;
    if (*(unsigned char*)(ov + 0x4000 + kRegionOffset2e1) != 0 &&
        ((BackgroundLoader*)loader)->GetNumQueuedTasks() == 0) {
        func_ov017_021c37a4();
        *(unsigned char*)(arg0 + 0x4000 + Enum_ov017_021941fc_737) = 0;
    }
    if (LinkSession_IsHostOrSolo(search) != 0) {
        int noTarget = -1;
        for (int i = 1; i < 4; i++) {
            if (LinkSession_IsSlotLost(search, i) == 0) continue;
            if (TestSearchFlagBit0202c758(search, i) != 0) continue;
            func_02094030(GetGlobal02109030_020936f8(), 3, noTarget, i);
            EnqueueEventTag173_021d1810(3, noTarget, i);
            EnqueueEventTag49_021cea34(i);
            SetSearchFlagBit0202c6dc(search, i);
        }
    }
    if (FlagWord_TestBits((struct FlagWord02046708*)flags, 0x40000) == 0) {
        func_ov017_02195658(ov);
    }
    if (LinkSession_IsGuest(search) != 0) {
        if (LinkSession_IsSlotLost(search, 0) != 0) {
            SetFlagAndCleanup_02195618(ov);
        }
    } else {
        for (int i = 1; i < 4; i++) {
            if (LinkSession_IsSlotLost(search, i) == 0) continue;
            if (TestSearchFlagBit0202c758(search, i) != 0) continue;
            EnqueueEventTag49_021cea34(i);
            SetSearchFlagBit0202c6dc(search, i);
        }
    }
    UpdateGlobalAndCombatantFlagBytes_020e35a0(status);
    if ((*(unsigned char**)(ov + 0x4000 + kRegionOffset41c))[0] == 0) {
        if (LinkSession_IsHostOrSolo(search) != 0) {
            if (status[1] != 0) goto dispatched;
            FlagWord_ClearBits((struct FlagWord020466f4*)flags, 0x800);
            if (PopFrontAndCompactEntries_0219531c(ov, entry) == 0) goto dispatched;
            int accept = 1;
            int used = GameState_GetOwnPartyOrder((char*)battle, region);
            if (used + entry[1] > 4) accept = 0;
            if (Scenario_TestFlag((int)owner, (unsigned char*)owner + 0x8c, 3) != 0) {
                func_ov017_02195250(ov, entry);
                accept = 0;
            }
            if (LinkSession_IsSlotConnected(search, entry[0]) == 0) accept = 0;
            if (entry[0xe] != 0) accept = 0;
            if (accept != 0) {
                FlagWord_SetBits((unsigned int*)flags, 0x800);
                EnqueueEventTag44_021cc198(entry[0], 1);
                func_ov017_021d0b30(0, entry[0], entry + 2);
                ClearSearchFlagBit0202c69c(search, entry[0]);
                ClearSearchFlagBit0202c718(search, entry[0]);
                (*(unsigned char**)(ov + 0x4000 + kRegionOffset41c))[0] = 1;
                (*(unsigned char**)(ov + 0x4000 + kRegionOffset41c))[1] = 0;
                func_ov017_02195214((Entry15_02195214 *) (*(unsigned char**)(ov + 0x4000 + kRegionOffset41c) + 2),
                    (Entry15_02195214 *) entry);
                *(unsigned char*)(ov + 0x4000 + kRegionOffset2e5) = 1;
            } else {
                EnqueueEventTag44_021cc198(entry[0], 0);
                SetSearchFlagBit0202c660(search, entry[0]);
                if (*(unsigned char*)(ov + 0x4000 + kRegionOffset2f0) == 0) {
                    FlagWord_ClearBits((struct FlagWord020466f4*)flags, 0x800);
                }
            }
        } else if (*(unsigned char*)(ov + 0x4000 + kRegionOffset31e) != 0 &&
                   LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)search) > 0) {
            int slot = 0;
            for (int i = 1; i < 4; i++) {
                if ((*(unsigned char*)(ov + 0x4000 + kRegionOffset31e) & (1 << i)) != 0) {
                    *(unsigned char*)(ov + 0x4000 + kRegionOffset31e) &= ~(1 << i);
                    slot = i;
                    break;
                }
            }
            int side;
            if (GetCombatantWithFlag0x200_0200fee0(battle,
                    LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)search)) != NULL) {
                side = 1;
            } else {
                var24 = 2;
            }
            (*(unsigned char**)(arg0 + 0x4000 + Enum_ov017_021941fc_1052))[0] = 1;
            (*(unsigned char**)(arg0 + 0x4000 + Enum_ov017_021941fc_1052))[1] = (unsigned char)var24;
            func_ov017_02195494(arg0, var22,
                (int)(*(unsigned char**)(arg0 + 0x4000 + Enum_ov017_021941fc_1052) + 2));
            (*(unsigned char**)(arg0 + 0x4000 + Enum_ov017_021941fc_1052))[2] = (unsigned char)var22;
            (*(unsigned char**)(arg0 + 0x4000 + Enum_ov017_021941fc_1052))[3] = 1;
            if (var24 == 1) *(unsigned char*)(arg0 + 0x4000 + Enum_ov017_021941fc_741) = 1;
        }
    } else if ((*(unsigned char**)(arg0 + 0x4000 + Enum_ov017_021941fc_1052))[0] == 1) {
        if (func_0202bd68(var7, (*(unsigned char**)(arg0 + 0x4000 + Enum_ov017_021941fc_1052))[2]) != 0) {
            if ((*(unsigned char**)(arg0 + 0x4000 + Enum_ov017_021941fc_1052))[1] == 2) {
                void* var25 = *(void**)(*(unsigned char**)(arg0 + 0x3000 + Enum_ov017_021941fc_2816) + 0x24);
                if (var25 != NULL) func_ov003_02167240(var25);
                (*(unsigned char**)(arg0 + 0x4000 + Enum_ov017_021941fc_1052))[0] = 2;
            } else {
                if (LinkSession_IsHostOrSolo(search) != 0 && *(int*)((char*)search + 0xfc0) == 0) {
                    if (LinkSession_IsSlotConnected(search,
                            (*(unsigned char**)(ov + 0x4000 + kRegionOffset41c))[2]) == 0) {
                        unsigned char* st = *(unsigned char**)(ov + 0x4000 + kRegionOffset41c);
                        st[0] = 0;
                        st[1] = 0;
                    }
                }
                int ok = 1;
                if (FieldTaskQueue_IsEmpty(list) == 0) ok = 0;
                if (mode[3] != 0 && mode[kRegionOffsetcf] == 2) ok = 1;
                int dx = abs(GetBrightness((GameResources*)ov, false));
                if (dx + abs(GetBrightness((GameResources*)ov, true)) > 0) ok = 0;
                if (*(short*)((char*)actor + 0xac) != 0) ok = 0;
                if (FlagWord_TestBits((struct FlagWord02046708*)flags, 0x200) != 0) ok = 1;
                if (FlagWord_TestBits((struct FlagWord02046708*)flags, 0x400) != 0) ok = 0;
                if (((BackgroundLoader*)loader)->GetNumQueuedTasks() > 0) ok = 0;
                if (ok != 0) {
                    unsigned char* node = *(unsigned char**)(ov + 0x3000 + kRegionOffsetb30);
                    func_ov017_021af59c(node);
                    node[9] = (*(unsigned char**)(ov + 0x4000 + kRegionOffset41c))[1];
                    func_ov017_02195214((Entry15_02195214 *) (node + 0xc),
                        (Entry15_02195214 *) (*(unsigned char**)(ov + 0x4000 + kRegionOffset41c) + 2));
                    PrependNodeToHead((struct HeadList020469f8*)list,
                        (struct HeadNode020469f8*)node);
                    (*(unsigned char**)(ov + 0x4000 + kRegionOffset41c))[0] = 2;
                } else if (*(unsigned char*)(ov + 0x4000 + kRegionOffset2e5) != 0) {
                    func_02094030(g, 5, -1, 0);
                    *(unsigned char*)(ov + 0x4000 + kRegionOffset2e5) = 0;
                }
            }
        } else if (LinkSession_IsSlotMember(search,
                       (*(unsigned char**)(ov + 0x4000 + kRegionOffset41c))[2]) != 0) {
            if (FlagWord_TestBits((struct FlagWord02046708*)flags, 0x40000) == 0) {
                func_ov017_021905b8(ov,
                    (*(unsigned char**)(ov + 0x4000 + kRegionOffset41c))[2], 0);
            }
        } else if ((*(unsigned char**)(arg0 + 0x4000 + Enum_ov017_021941fc_1052))[1] != 2) {
            (*(unsigned char**)(arg0 + 0x4000 + Enum_ov017_021941fc_1052))[0] = 2;
        }
    } else if ((*(unsigned char**)(ov + 0x4000 + kRegionOffset41c))[0] == 2) {
        if (ListContainsId((struct ListHead02046b60*)list, 0x26) != 0) goto dispatched;
        if (*(unsigned char*)(ov + 0x4000 + kRegionOffset2f0) == 0) {
            FlagWord_ClearBits((struct FlagWord020466f4*)flags, 0x800);
        }
        (*(unsigned char**)(arg0 + 0x4000 + Enum_ov017_021941fc_1052))[0] = 0;
    }
dispatched:
    if (TestFlags00((GameResources*)ov, 2) != 0) return;
    if (LinkSession_IsActive((int*)search) == 0) return;
    struct Slot021941fc* slot = (struct Slot021941fc*)LinkSession_GetOwnRecord(search);
    if (TestFlags00((GameResources*)ov, 0x40) == 0) {
        int kind = 0;
        unsigned char placed = 0;
        if (((Object3D*)((struct U16Field0x6_020375f8*)actor))->GetField06() == 10000 ||
            *(int*)((char*)actor + kRegionOffset15c) == 10000) {
            *(Vector3i*)posA = *(Vector3i const*)&data_ov017_021d63f0;
            *(Vector3i*)posB = *(Vector3i const*)&data_ov017_021d63d8;
            kind = 0;
        } else if (((Object3D*)((struct U16Field0x6_020375f8*)actor))->GetField06() == 10100 ||
                   *(int*)((char*)actor + kRegionOffset15c) == 10100) {
            *(Vector3i*)posA = *(Vector3i const*)&data_ov017_021d63e4;
            *(Vector3i*)posB = *(Vector3i const*)&data_ov017_021d63fc;
            kind = 0;
        } else if (GetField0x158_02053ed0(actor) == 0) {
            *(Vector3i*)posA = *(Vector3i const*)(&actor->obj3D_.position_.x);
            *(Vector3i*)posB = *(Vector3i const*)(&actor->obj3D_.rotation_.x);
            if (GameObject_IsSinking((struct BitField0203402c*)actor) != 0) {
                posA[1] = posA[1] - fix32_Divide(actor->obj3D_.GetHeight(), 0x1800);
            }
            kind = *(unsigned char*)((char*)actor + 0xbe);
            if (FieldTaskQueue_GetCurrentKind((struct HeadNode02046b24**)list) == 0x26) kind = 0;
            placed = 1;
        } else {
            *(Vector3i*)var2 = *(Vector3i const*)((int*)((char*)var8 + Enum_ov017_021941fc_352));
            *(Vector3i*)var3 = *(Vector3i const*)((int*)((char*)var8 + Enum_ov017_021941fc_364));
            if (func_02053ed0(var8) == 1) {
                var31 = 2;
            } else {
                var31 = var32;
            }
        }
        slot->x = (short)(posA[0] >> 7);
        slot->y = (short)(posA[1] >> 7);
        slot->z = (short)(posA[2] >> 7);
        slot->angle = (short)posB[1];
        slot->kind = (unsigned short)kind;
        slot->f4 = LinkSession_GetConnectedAids(search);
        slot->f6 = g_keyManager.currentKeys_;
        slot->bit12 = 1;
        slot->bit15 = placed;
        slot->members = 0;
        for (int i = 0; i < 4; i++) {
            if (battle->GetGameObjectByIndex(i) != NULL) {
                slot->members |= (1 << i);
            }
        }
        if (func_ov017_021bd3a4(
                *(struct Struct_ov017_0218e674**)(arg0 + 0x3000 + Enum_ov017_021941fc_1844)) != 0) {
            unsigned char* var34 = *(unsigned char**)(arg0 + 0x3000 + Enum_ov017_021941fc_1844);
            var34++;
            var30->unknown_2_1_ &= ~var34[Enum_ov017_021941fc_371];
        }
    } else {
        var30->unknown_1_0_ = 0;
    }
    unsigned char* actorNode = *(unsigned char**)(ov + 0x3000 + kRegionOffsetb30);
    unsigned char* partyNode = *(unsigned char**)(ov + 0x3000 + kRegionOffsetb2c);
    unsigned char* menuNode = *(unsigned char**)(ov + 0x3000 + kRegionOffset718);
    unsigned char* extraNode = *(unsigned char**)(ov + 0x3000 + kRegionOffsetb5c);
    slot->active = 0;
    slot->active |= actorNode[3];
    slot->active |= partyNode[3];
    slot->bit11 = 0;
    slot->bit11 |= menuNode[3];
    slot->bit11 |= extraNode[3];
    slot->bit13 = 1;
    if (FieldTaskQueue_IsEmpty(list) == 0) {
        slot->bit13 = 0;
        slot->bit13 |= (*(unsigned char**)(ov + 0x3000 + kRegionOffsetafc))[3];
        slot->bit13 |= (*(unsigned char**)(ov + 0x3000 + kRegionOffsetb0c))[3];
        slot->bit13 |= (*(unsigned char**)(ov + 0x3000 + kRegionOffsetb10))[3];
        slot->bit13 |= (*(unsigned char**)(ov + 0x3000 + kRegionOffsetb24))[3];
        slot->bit13 |= (*(unsigned char**)(ov + 0x3000 + kRegionOffsetb28))[3];
        slot->bit13 |= (*(unsigned char**)(ov + 0x3000 + kRegionOffsetb88))[3];
        slot->bit13 |= (*(unsigned char**)(ov + 0x3000 + kRegionOffsetbbc))[3];
    }
    var30->unknown_3_6_ = (*(unsigned char**)(arg0 + 0x3000 + Enum_ov017_021941fc_1804))[3];
    if (arg1[Enum_ov017_021941fc_207] == 2) {
        var30->unknown_2_0_ |= arg1[3];
    }
    if (TestFlags00((GameResources*)ov, 0x40) == 0) {
    unsigned char* pending = ov + kRegionOffset4300 + kRegionOffset55;
    for (int i = 0; i < 4; i++) {
        if (i == 0 && TestFlags00((GameResources*)ov, 0x200) != 0) continue;
        if (LinkSession_IsSlotMember(search, i) == 0) continue;
        if (i == LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)search)) continue;
        SearchEntry0202c178* other = LinkSession_GetReceivedRecord(search, i);
        if (other == NULL) continue;
        GameObject* c = battle->GetPartyMemberByIndex(i);
        if (c == NULL) continue;
        c = battle->GetPartyMemberByIndex(GameObject_GetLineLeader(c));
        if (c == NULL) continue;
        if ((((struct Bits0xc1*)((char*)c + 0xc1))->low & 1) == 0 && other->bit12) {
            target.x = other->x << 7;
            target.y = other->y << 7;
            target.z = other->z << 7;
            int angle = other->angle;
            *(Vector3i*)((int*)((char*)c + 0xd4)) = *(Vector3i const*)((int*)&target);
            *(unsigned char*)((char*)c + 0xe0) |= 0x10;
            GameObject_SetFacing((struct Obj02033834*)c, angle);
            struct Vec3s32_020c3030 current = *(struct Vec3s32_020c3030*)((char*)c + 0x44);
            if (Vector3fix_Distance((const Vector3fix*)&target, (const Vector3fix*)&current) > 0x1000) {
                *(Vector3i*)(&c->obj3D_.position_.x) = *(Vector3i const*)((int*)&target);
                GameObject_SnapFacing((struct Obj02033874*)c, angle);
            }
        }
        if (other->flags.kind == 2) {
            if (GameObject_IsGesturing((signed char*)c) != 0) {
                func_020531f0(c);
            }
            GameObject* var45 = func_0200ffe0(var6,
                *(unsigned short*)((char*)var42 + 0x100 + Enum_ov017_021941fc_178));
            if (var45 != NULL && *(int*)((char*)var45 + 0x130) != 9) {
                if ((**(int**)((char*)var42 + 0x130) & 1) == 0) {
                    func_02076ccc(var45, 9);
                }
            }
        }
        if ((((struct Struct_ov017_021941fc_3*)((char*)var42 + 0xc1))->unknown_0_0_ & 2) == 0) {
            int var46 = *(unsigned char*)((char*)var42 + 0xbe);
            if (var46 == 2 && var41->unknown_0_.unknown_1_0_ != 2) {
                func_ov017_021917f0(var40, 0);
            } else if (var41->unknown_0_.unknown_1_0_ == 2 && var46 != 2) {
                func_ov017_021917f0(var40, 1);
            }
            GameObject_SetMotionState((struct Obj02033b68*)c, other->flags.kind);
        }
        if ((*(unsigned char*)(arg0 + 0x4000 + Enum_ov017_021941fc_853) & (1 << var40)) == 0) continue;
        if (var41->unknown_3_7_ != 1) continue;
        func_ov017_021bd4d0(*(void**)(arg0 + 0x3000 + Enum_ov017_021941fc_1844), var40, 1, 1);
        *var39 = *var39 & ~(1 << var40);
    }
    }
    func_ov017_021d48f0();
    func_0207dba8(func_0207d78c());
}
